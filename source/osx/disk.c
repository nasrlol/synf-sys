#ifdef __APPLE__

#include <stdio.h>
#include <sys/param.h>
#include <sys/mount.h>

typedef struct {
    long long size;
    ushort name;
} disk_s;


void* disk_size();

disk_s disk__s;

void* disk_size(){

    struct statfs disk;
    
    statfs("/", &disk);

    disk__s.size = disk.f_bfree;
    return NULL; 
}

void* get_disk_info(){

    printf("free disk space: %llu\n", disk__s.size);

    return NULL;
}

#endif

