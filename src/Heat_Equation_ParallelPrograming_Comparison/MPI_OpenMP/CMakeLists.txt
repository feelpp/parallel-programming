
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


if(TRUE)
    find_package(OpenMP REQUIRED)
endif()



file(GLOB SOURCES
    "*.h"
    "*.cpp"
)

add_executable(HeatOpenMP ${SOURCES})
include_directories(SYSTEM ${MPI_INCLUDES_PATH})
target_include_directories(HeatOpenMP PUBLIC ${MPI_CXX_INCLUDE_DIRS} PUBLIC OpenMP::OpenMP_CXX)
target_link_libraries(HeatOpenMP PUBLIC ${MPI_CXX_LIBRARIES} PUBLIC OpenMP::OpenMP_CXX PRIVATE PNGwriter::PNGwriter )


########### end ####################################  
