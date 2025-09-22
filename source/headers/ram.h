#ifndef RAM_H
#define RAM_H

#ifdef __APPLE__

void* size();
void* av_size();
void* ram_info();

#endif
#ifdef __gnu_linux__

void* size();
void* av_size();
void* ram_info();

#endif
#endif
