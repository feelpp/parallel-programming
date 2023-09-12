
project(MPI_bcast)

######## A simple cmakelists.txt file for ... #############  

cmake_minimum_required(VERSION 3.17)
#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_CXX_COMPILER "/usr/local/bin/g++")


add_executable(MPI_bcast MPI_bcast.cpp)

find_package(MPI REQUIRED)
if (MPI_FOUND)
    MESSAGE("{MPI_CXX_LIBRARIES}")
    else (MPI_FOUND)
    MESSAGE (SEND_ERROR "This application cannot compile without MPI")
endif(MPI_FOUND)


find_package(OpenMP)
if (OpenMP_CXX_FOUND)
    MESSAGE("{OpenMP_CXX_LIBRARIES}")
    else (OpenMP_CXX_FOUND)
    MESSAGE (SEND_ERROR "This application cannot compile without OpenMPI")
endif(OpenMP_CXX_FOUND)



include_directories(SYSTEM ${MPI_INCLUDES_PATH})
target_include_directories(MPI_bcast PUBLIC ${MPI_CXX_INCLUDE_DIRS})
target_link_libraries(MPI_bcast PUBLIC ${MPI_CXX_LIBRARIES} )

# traget_link_libraries(A PUBLIC OpenMP::OpenMP_CXX)

########### end ####################################  
