# AvaTar

## Requirement

- *sudo privileges* in terminal

## Get started

After run `ramdisk.sh` to set-up ramdisk, run `avatar.sh` for mounting filesystem and testing

```
$ ./ramdisk.sh
$ ./avatar.sh
```

## Watch logs

```
$ tail -f /var/log/kern.log
```

OR

```
$ watch 'dmesg -c'
```
