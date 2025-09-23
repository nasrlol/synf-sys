#ifdef __gnu_linux__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

typedef struct {
    unsigned long mem_size;
} ram;

unsigned long get_total(void);
unsigned long get_usage(void);


int main(int argc, char** argv) {
    printf("compiled for __gnu_linux__");
    if (argc > 1) {
        if (strcmp(argv[1], "total") == 0) {
            printf("Get the total ram usage");
            while (1) {
                sleep(1);
                printf("%lu", get_total());
            }
        } else if (strcmp(argv[1], "name") == 0) {
            printf("Get the ram usage");
            printf("%lu", get_usage());
        }
    } else
        printf("no arguments passed, try again with : frequency, temperature or name");
    return 0;
    return 0;
}

unsigned long get_total(void) {
    struct sysinfo info;

    if (sysinfo(&info) != 0) {
        perror("sysinfo");
        return 1;
    }

    long total_ram = info.totalram * info.mem_unit;
    return total_ram;
}

unsigned long get_usage(void) {
    struct sysinfo info;

    if (sysinfo(&info) != 0) {
        perror("sysinfo");
        return 1;
    }

    long total_ram = info.totalram * info.mem_unit;
    long free_ram = info.freeram * info.mem_unit;

    return total_ram - free_ram;
}

#endif
