#include <pthread.h>
#include <stdio.h>
#include "cpu.h"
#include "ram.h"
#include "disk.h"
#include "device.h"

int main(int argc, char** argv) {
    pthread_t cpu_t;
    pthread_t ram_t;
    pthread_t disk_t;
    pthread_t device_t;

    // cpu threads
    pthread_create(&cpu_t, NULL, cpu_info , NULL);

    // ram threads
    pthread_create(&ram_t, NULL, ram_info , NULL);

    // disk threads
    pthread_create(&disk_t, NULL, disk_size , NULL);

    // device thread
    pthread_create(&device_t, NULL, get_device_info , NULL);

    pthread_join(cpu_t, NULL);
    pthread_join(ram_t, NULL);
    pthread_join(disk_t, NULL);
    pthread_join(device_t, NULL);

    return 0;
}
