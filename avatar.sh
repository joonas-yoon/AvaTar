#!/bin/bash
(( EUID )) && echo "Need to be root." && exit 1

function dividor {
    printf '%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -
}

set -ex

HOME_DIR=`pwd`
MOD_NAME=ext4k
MOD_DIR=$HOME_DIR/$MOD_NAME
MOUNT_FS=/mnt/ramdisk/ext4.image
MOUNT_DIR=$HOME_DIR/fs

cd $MOD_DIR
make clean
make -j 32

set +x
if [ ! -d $MOUNT_DIR ]; then
    mkdir $MOUNT_DIR
    touch $MOUNT_DIR/if-see-this-then-not-mounted
else
    set +e
    # unmount previous module
    umount $MOUNT_DIR
fi
dividor

# before mount, list up directory under not mounted
echo "ls $MOUNT_DIR"
ls -al $MOUNT_DIR
dividor

# see what it used by on our module
echo "lsmod $MOD_NAME"
lsmod | grep $MOD_NAME
dividor

# remove and list again
echo "rmmod $MOD_NAME && lsmod $MOD_NAME"
echo `rmmod $MOD_NAME`
lsmod | grep $MOD_NAME
dividor

# add new module
echo "insmod $MOD_DIR/$MOD_NAME.ko && lsmod $MOD_NAME"
insmod $MOD_DIR/$MOD_NAME.ko
lsmod | grep $MOD_NAME
dividor

# mount with new module
echo "mount -t $MOD_NAME $MOUNT_FS $MOUNT_DIR"
mount -t $MOD_NAME -o loop $MOUNT_FS $MOUNT_DIR

# after mount, see in directory
echo "ls $MOUNT_DIR"
ls -al $MOUNT_DIR
dividor

cd $HOME_DIR
echo "end."
exit
