
#project(MPI_bcast)

######## A simple cmakelists.txt file for ... #############  

cmake_minimum_required(VERSION 3.17)
#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_CXX_COMPILER "/usr/local/bin/g++")
#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_COMPILER "/usr/local/bin/g++")
#set(CMAKE_C_COMPILER    "/usr/bin/clang-14")
#set(CMAKE_CXX_COMPILER  "/usr/bin/clang++-14")
#set(CMAKE_CXX_COMPILER "/usr/bin/gcc")
#set(CMAKE_CXX_COMPILER "/usr/bin/g++-11")

if(TRUE)
    find_package(PNGwriter)
        if(PNGwriter_FOUND)
            MESSAGE("{PNGwrite_LIBRARIES}")
        else (PNGwriter_FOUND)
            MESSAGE(SEND_ERROR "{PNGwrite_LIBRARIES Not Found}")
        endif(PNGwriter_FOUND)
endif()



if(FALSE)
    find_package(MPI REQUIRED)
    if (MPI_FOUND)
        MESSAGE("{MPI_CXX_LIBRARIES}")
        else (MPI_FOUND)
        MESSAGE (SEND_ERROR "This application cannot compile without MPI")
    endif(MPI_FOUND)
endif()

if(FALSE)
    find_package(OpenMP)
    if (OpenMP_CXX_FOUND)
        MESSAGE("{OpenMP_CXX_LIBRARIES}")
        else (OpenMP_CXX_FOUND)
        MESSAGE (SEND_ERROR "This application cannot compile without OpenMPI")
    endif(OpenMP_CXX_FOUND)
endif()


file(GLOB SOURCES
    "*.h"
    "*.cpp"
)

add_executable(HeatMPI ${SOURCES})
include_directories(SYSTEM ${MPI_INCLUDES_PATH})
target_include_directories(HeatMPI PUBLIC ${MPI_CXX_INCLUDE_DIRS})
target_link_libraries(HeatMPI  PUBLIC ${MPI_CXX_LIBRARIES} PRIVATE PNGwriter::PNGwriter )
#target_link_libraries(HeatMPI  PUBLIC ${MPI_CXX_LIBRARIES} PRIVATE libPNGwrite.a)







########### end ####################################  
