/*
 * Copyright [2020] [Animesh Trivedi]
 *
 * This code is part of the Advanced Network Programming (ANP) course
 * at VU Amsterdam.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *        http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#include "icmp.h"
#include "utilities.h"
#include "subuff.h"
#include "ip.h"
#include "timer.h"
#include "anp_netdev.h"

struct icmp_retry_arg {
    struct subuff *sub;
    uint32_t daddr;
};

void *icmp_retry_handler(void *arg) {
    struct icmp_retry_arg *retry_arg = (struct icmp_retry_arg *)arg;
    
    int ret = ip_output(retry_arg->daddr, retry_arg->sub);
    
    if (ret == -EAGAIN) {
        timer_oneshot(50, icmp_retry_handler, retry_arg);
    } else if (ret > 0) {
        printf("ICMP reply successfully sent\n");
        free_sub(retry_arg->sub);
        free(retry_arg);
        return NULL;
    } else {
        printf("Error sending ICMP reply\n");
        free_sub(retry_arg->sub);
        free(retry_arg);
        return NULL;
    }

    return NULL;
}

void icmp_rx(struct subuff *sub)
{
    struct iphdr *ip_header = IP_HDR_FROM_SUB(sub);
    
    uint8_t ip_header_len = ip_header->ihl * 4;

    uint8_t *icmp_start = sub->head + ETH_HDR_LEN + ip_header_len;
    struct icmp *icmp_header = (struct icmp *)icmp_start;

    uint16_t incoming_checksum = icmp_header->checksum;
    icmp_header->checksum = 0;

    uint16_t icmp_length = IP_PAYLOAD_LEN(ip_header);
    uint16_t computed_checksum = do_csum(icmp_header, icmp_length, 0);

    if (computed_checksum != incoming_checksum) {
        free_sub(sub);
        return;
    }
    
    if (icmp_header->type == ICMP_V4_ECHO) {
        icmp_reply(sub);
    }

    free_sub(sub);
    return;
}

void icmp_reply(struct subuff *sub)
{
    // FIXME: implement your ICMP reply implementation here
    // Hints:
    // Step 1: prepare an ICMP response buffer
    // Step 2: make sure that all fields are valid, in the network byte order, and the checksum is correct
    // Step 3: send it out on ip_ouput(...)
    // See how ARP processing is implemented for processing and sending packets

    struct iphdr *ip_header = IP_HDR_FROM_SUB(sub);
    uint8_t ip_header_len = ip_header->ihl * 4;

    sub_reserve(sub, ETH_HDR_LEN + ip_header_len + IP_PAYLOAD_LEN(ip_header));
    sub_push(sub, ip_header_len + IP_PAYLOAD_LEN(ip_header));
    
    uint8_t *icmp_start = sub->head + ETH_HDR_LEN + ip_header_len;
    struct icmp *icmp_header = (struct icmp *)icmp_start;

    int icmp_length = IP_PAYLOAD_LEN(ip_header);

    icmp_header->type = ICMP_V4_REPLY;
    icmp_header->checksum = 0;

    icmp_header->checksum = do_csum(icmp_header, icmp_length, 0);

    sub->len = IP_PAYLOAD_LEN(ip_header);
    sub->data = icmp_start;
    sub->protocol = 1;
    
    int ret = ip_output(ip_header->saddr, sub);
    
    if (ret == -EAGAIN) {
        printf("ARP resolution pending, scheduling retry...\n");

        struct icmp_retry_arg *retry_arg = malloc(sizeof(struct icmp_retry_arg));
        retry_arg->sub = sub;
        retry_arg->daddr = ntohl(ip_header->saddr);

        timer_oneshot(50, icmp_retry_handler, retry_arg);
    } else if (ret > 0) {
        printf("ICMP reply successfully sent\n");
    } else {
        printf("Error sending ICMP reply\n");
    }
    return;
    //Test
}
 