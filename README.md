# AvaTar

## Requirement

- *sudo privileges* in terminal

## Get started

After run `ramdisk.sh` to set-up ramdisk, run `avatar.sh` for mounting filesystem and testing

```
$ ./ramdisk.sh
$ ./avatar.sh
```

## How to test

In mounted filesystem, using library with ioctl as following:
```
$ gcc test.c -o test           # compile
$ fallocate -l 32k fs/duumy    # make a dummy file with 32kb
$ test fs/dummy                # run
```

If you wonder how it works, read `test.c` and `ext4k/avatar.c` for details.

## Watch logs

```
$ tail -f /var/log/kern.log
```

OR

```
$ dmesg -c
```
