
#include <linux/fs.h>
#include <linux/capability.h>
#include <linux/time.h>
#include <linux/compat.h>
#include <linux/mount.h>
#include <linux/file.h>

#include "ext4.h"

#ifdef EXT4KFS_AVATAR

int ext4k_split(struct file *filp, unsigned long arg) {	
	ext4k_debug("EXT4_IOC_SPLIT called");

	int retval = 0;

	unsigned int nlink = filp->f_inode->i_nlink;
	ext4k_debug("nlink of inode: %u", nlink);

	// TODO: create empty file
	handle_t *handle;
	struct inode *inode = filp->f_inode;
	struct inode *tmp_inode = NULL;
	__u32 goal;
	uid_t owner[2];

	goal = (((inode->i_ino - 1) / EXT4_INODES_PER_GROUP(inode->i_sb)) *
		EXT4_INODES_PER_GROUP(inode->i_sb)) + 1;
	ext4k_debug("goal = (%lu / %lu) * %lu + 1 = %u", inode->i_ino - 1,
		EXT4_INODES_PER_GROUP(inode->i_sb), EXT4_INODES_PER_GROUP(inode->i_sb), goal);

	owner[0] = i_uid_read(inode);
	owner[1] = i_gid_read(inode);
	ext4k_debug("owner[] = {%u, %u}", owner[0], owner[1]);

	struct inode* dinode = d_inode(inode->i_sb->s_root);

	ext4k_debug("d_inode->i_ino = %lu", dinode->i_ino);

//	tmp_inode = ext4_new_inode(handle, dinode,
//					S_IFREG, NULL, goal, owner);

	if (IS_ERR(tmp_inode)) {
		retval = PTR_ERR(tmp_inode);
		return retval;
	}

	// TODO: copy file of its from inode

	return 0;

}

int ext4k_merge(struct file *filp, unsigned long arg) {	
	ext4k_debug( "EXT4_IOC_MERGE called");

	return 0;
}

#endif

