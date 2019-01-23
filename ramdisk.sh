#!/bin/bash
(( EUID )) && echo "Need to be root." && exit 1

function dividor {
    printf '%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -
}

set +x

HOME_DIR=`pwd`
MOUNT_DIR=/mnt/ramdisk
IMAGE=ext4.image

if [ ! -d $MOUNT_DIR ]; then
    mkdir $MOUNT_DIR
else
    umount $MOUNT_DIR
fi

mount -t ramfs ramfs $MOUNT_DIR
dd if=/dev/zero of=$MOUNT_DIR/$IMAGE bs=1M count=512
mkfs.ext4 $MOUNT_DIR/$IMAGE


