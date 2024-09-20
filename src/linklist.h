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

#ifndef ANPNETSTACK_LINKLIST_H
#define ANPNETSTACK_LINKLIST_H

// kernel inspited link list implementation

/* The list_head can be used to store structs in a doubly linked list.
Add the struct list_head as a variable to a struct. Example:

struct my_struct
{
    struct list_head list;
    ...
};
*/



#include <stddef.h>

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

// Create and initialize a new list with name "name"
#define LIST_HEAD(name) \
    struct list_head name = { &(name), &(name) }

// Initialize an existing list_head. Example: list_init(&my_struct.head);
static inline void list_init(struct list_head *head)
{
    head->prev = head->next = head;
}

//Add "new" to the front of "head"
static inline void list_add(struct list_head *new, struct list_head *head)
{
    head->next->prev = new;
    new->next = head->next;
    new->prev = head;
    head->next = new;
}

// Append "new" after "head"
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
    head->prev->next = new;
    new->prev = head->prev;
    new->next = head;
    head->prev = new;
}

// Remove "elem" from the list
static inline void list_del(struct list_head *elem)
{
    struct list_head *prev = elem->prev;
    struct list_head *next = elem->next;

    prev->next = next;
    next->prev = prev;
}

// Convert a struct list_head to the struct that that entry belongs to.
/* Example: 
    struct my_struct example;
    list_init(&example.list);

    ...

    From "struct my_struct*" to "struct list_head*":
    struct list_head *item = &example->list;

    From "struct list_head*" to "struct my_struct*":
    struct my_struct* my_struct = list_entry(item, struct my_struct, list);
    where:
    "item" is the struct list_head*.
    "struct my_struct" is the type of struct.
    "list" is the name of the "struct list_head" inside "struct my_struct"

*/
#define list_entry(ptr, type, member) \
    ((type *) ((char *) (ptr) - offsetof(type, member)))

// Same as list_entry, but when "ptr" is not inside a struct but only represents the head of the list.
#define list_first_entry(ptr, type, member) \
    list_entry((ptr)->next, type, member)

// For loop to iterate through the list.
// "pos" is the name of the current list entry.
// "head" is the head of the list. After it comes the first entry.
#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

// Same as list_for_each, but it still works while deleting entries.
#define list_for_each_safe(pos, p, head)    \
    for (pos = (head)->next, p = pos->next; \
         pos != (head);                     \
         pos = p, p = pos->next)

// Returns 1 if the list is empty, and 0 if the list is not empty.
static inline int list_empty(struct list_head *head)
{
    return head->next == head;
}

#endif //ANPNETSTACK_LINKLIST_H
