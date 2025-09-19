#include <pthread.h>
#include <stdio.h>
#include "cpu.h"
#include "ram.h"
#include "disk.h"
#include "device.h"

#include <curl/curl.h>

void handler(char* URL){

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

#ifdef __APPLE__

void setup_mt(){

    pthread_t cpu;
    pthread_t ram;
    pthread_t disk;
    pthread_t device;

    pthread_create(&cpu, NULL, cpu_info , NULL);
    pthread_create(&ram, NULL, ram_info , NULL);
    pthread_create(&disk, NULL, disk_size , NULL);
    pthread_create(&device, NULL, get_device_info , NULL);

    pthread_join(cpu, NULL);
    pthread_join(ram, NULL);
    pthread_join(disk, NULL);
    pthread_join(device, NULL);

}

int main(int argc, char** argv) {

    setup_mt();

    return 0;
}

#endif

#ifdef __gnu_linux

void setup_mt(){

   pthread_t cpu;
   pthread_t ram;
   pthread_t disk;
   pthread_t device;

   pthread_create(&cpu, NULL, cpu_i, NULL);
   pthread_create(&ram, NULL, ram_i, NULL);
   pthread_create(&disk, NULL, disk_i, NULL);
   pthread_create(&device, NULL, device_i, NULL);

}

int main(int argc, char** argv) {

    setup_mt();

    return 0;
}

#endif
