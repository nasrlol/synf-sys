#ifndef CPU_H
#define CPU_H

#ifdef __gnu_linux__

float cpu_freq(void);
char* cpu_name(void);
void cpu_temperature(void);

#endif
#ifdef __APPLE__

void* cpu_name();
void* cpu_threads();
void* cpu_info();

#endif
#endif
