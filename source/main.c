#include <pthread.h>
#include <stdio.h>
#include "cpu.h"
#include "ram.h"
#include "disk.h"
#include "device.h"

#include <curl/curl.h>

void handler(void){


    CURL *curl;
    CURLcode res;

    /* In Windows, this inits the Winsock stuff */
    curl_global_init(CURL_GLOBAL_ALL);
    /* get a curl handle */
    curl = curl_easy_init();
    if (curl) {
        /* First set the URL that is about to receive our POST. This URL can
       just as well be an https:// URL if that is what should receive the
       data. */
        curl_easy_setopt(curl, CURLOPT_URL, "http://postit.example.com/moo.cgi");
        /* Now specify the POST data */
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");

        /* Perform the request, res gets the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

}



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
