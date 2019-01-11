
#include <linux/fs.h>
#include <linux/capability.h>
#include <linux/time.h>
#include <linux/compat.h>
#include <linux/mount.h>
#include <linux/file.h>

#include "ext4.h"

#ifdef EXT4KFS_AVATAR

int ext4k_split(struct file *filp, unsigned long arg) {	
	ext4k_debug("EXT4_IOC_SPLIT called\n");

	return 0;

}

int ext4k_merge(struct file *filp, unsigned long arg) {	
	ext4k_debug( "EXT4_IOC_MERGE called\n");

	return 0;
}
#endif

