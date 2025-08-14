#ifdef __APPLE__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>

#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>

void* size();
void* av_size();

/*
    hw.memsize: 8589934592
    hw.memsize_usable: 7989493760
 */

typedef struct {

    long double total;
    long double available;
} ram;

ram data;

#define D 1073741824
 
void* size(){

    int64_t size;
    size_t len = sizeof(size);
    if (sysctlbyname("hw.memsize", &size, &len, NULL, 0) < 0)
        perror("error in retrieving the memory size");

    data.total = size / D; 
    return NULL;
}

void* av_size(){

    int64_t size ;
    size_t len = sizeof(size);
    if (sysctlbyname("hw.memsize_usable", &size, &len, NULL, 0) < 0)
        perror("error in retrieving the available memory size");

    data.available = size / D;
    return NULL;
}

void* ram_info(){
    size();
    av_size();

    printf("available ram: %LF\n", data.available );
    printf("total ram: %LF\n", data.total );

    return NULL;
}

#endif
