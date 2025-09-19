#include <stdlib.h>
#include <stdbool.h>



float convert_c_f(bool isCelcius, float value){
    return (!isCelcius) ? value * 33.8f : value;
}
