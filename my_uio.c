#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "myheadfile.h"

#define MAP_SIZE 0x2000

volatile u_int32_t bram_data[1000] = {};

char uiod[] = "/dev/uio0";
int fd;
void *ptr;

int uio_init(void)
{

    return 1;
}

int uio_proc(void)
{   
    fd = open(uiod, O_RDWR);
    if (fd < 1)
    {
        printf("Invalid UIO device file:%s.\n", uiod);
        return -1;
    }
    // else
    //     printf("UIO Opened.\n");
    ptr = mmap(NULL, MAP_SIZE, PROT_READ, MAP_SHARED, fd, 0);
    // Read data from BRAM
    for(int i = 0; i < 250; i++)
        bram_data[i] = 0x0fff & *((u_int32_t*)ptr + i + 1);
    // Print data
    for(int i = 0; i < 250; i++)
        printf("data[%d]: %d\n", i, bram_data[i]);
    close(fd);
    return 1;
}
