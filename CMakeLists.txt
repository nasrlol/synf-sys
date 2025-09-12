CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# set the project name
PROJECT(synf)

# add the executable
ADD_EXECUTABLE(main
    source/main.c

    source/lib/osx/cpu.c
    source/lib/osx/ram.c
    source/lib/osx/disk.c
    source/lib/osx/device.c

    source/lib/linux/cpu.c
    source/lib/linux/ram.c
    source/lib/linux/disk.c
    source/lib/linux/device.c

)

TARGET_INCLUDE_DIRECTORIES(main PRIVATE source/lib/osx source/lib/linux)
