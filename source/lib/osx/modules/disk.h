#ifndef DISK_H
#define DISK_H

#ifdef __APPLE__

void* disk_size();

typedef struct {
    long long size;
    short name;
} disk_s;


#endif
#endif
