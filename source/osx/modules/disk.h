#ifndef DISK_H
#define DISK_H

#ifdef __APPLE__

void* disk_size();

<<<<<<<< HEAD:source/headers/disk.h
#endif

#ifdef __gnu_linux__
========
typedef struct {
    long long size;
    short name;
} disk_s;

>>>>>>>> refs/remotes/origin/main:source/osx/modules/disk.h

#endif
#endif
