#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#define EXT4_IOC_GETFLAGS    _IOR('f', 1, long)
#define EXT4_IOC_GETVERSION  _IOR('f', 3, long)
#define EXT4_IOC_EXT4K_READ  _IOW('f', 22, long)
#define EXT4_IOC_SPLIT 7777
#define EXT4_IOC_MERGE 7778

int main(int argc, char* argv[]) {
    int fd, error=0; 
    int buf, tmp;

    if (argc != 2) {
        perror("argv[1] = <filename>");
        exit(0);
    }

    fd = open(argv[1], O_RDWR);
    if (fd < 0) {
        perror("file open");
        exit(1);
    }

    error = ioctl(fd, EXT4_IOC_SPLIT, 2);
    error = ioctl(fd, EXT4_IOC_MERGE, 2);
    
    //error = ioctl(fd, EXT4_IOC_GETFLAGS, &buf);
    //error = ioctl(fd, EXT4_IOC_GETVERSION, &tmp);

    if(error < 0) {
        perror("ioctl");
        exit(1);
    }

    printf("buf : %d tmp : %d \n", buf, tmp);

   // error = ioctl(fd, EXT4_IOC_EXT4K_READ, &tmp);

    if(error < 0) {
        perror("ioctl::EXT4K_TEST");
        exit(1);
    }

    close(fd);

    return 0;
}
