CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# set the project name
PROJECT(synf)

# add the executable
ADD_EXECUTABLE(main

        source/lib/osx/modules/cpu.c
        source/lib/osx/modules/ram.c
        source/lib/osx/modules/disk.c
        source/lib/osx/modules/device.c

        source/lib/linux/modules/cpu.c
        source/lib/linux/modules/ram.c
        source/lib/linux/modules/disk.c
        source/lib/linux/modules/device.c
        source/main.c

)


FIND_PACKAGE(CURL REQUIRED)

TARGET_LINK_LIBRARIES(main PRIVATE CURL::libcurl)
TARGET_INCLUDE_DIRECTORIES(main PRIVATE source/lib/osx source/lib/linux)
