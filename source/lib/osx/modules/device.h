#ifndef DEVICE_H
#define DEVICE_H

#ifdef __APPLE__

typedef struct{
    char* name;
    char* model;
} device_s;

void* get_device_info();


#endif
#endif
