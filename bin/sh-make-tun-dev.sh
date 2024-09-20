#!/bin/bash
set -ex 

if [ ! -f "/dev/net" ]; then
    sudo mkdir -p /dev/net
fi

sudo mknod /dev/net/tap c 10 200
sudo chmod 0666 /dev/net/tap
