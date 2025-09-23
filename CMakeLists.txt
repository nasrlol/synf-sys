CMAKE_MINIMUM_REQUIRED(VERSION 3.12)

# Set the project name
PROJECT(synf)

# Find curl package
find_package(CURL REQUIRED)

# add the executable
ADD_EXECUTABLE(main

        # OSX Files
        source/osx/modules/cpu.c
        source/osx/modules/ram.c
        source/osx/modules/disk.c
        source/osx/modules/device.c


        # Linux Files
        source/linux/modules/cpu.c
        source/linux/modules/ram.c
        source/linux/modules/disk.c
        source/linux/modules/device.c

        # Main File
        source/main.c

)

TARGET_LINK_LIBRARIES(main PRIVATE CURL::libcurl)
TARGET_INCLUDE_DIRECTORIES(main PRIVATE source/lib/osx source/lib/linux)
