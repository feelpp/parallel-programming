project(SPECX CXX)

cmake_minimum_required (VERSION 3.20 FATAL_ERROR)

set(SPECX_SOURCE_DIR ${specx_SOURCE_DIR} )
set(SPECX_BINARY_DIR ${specx_BINARY_DIR} )


include(CheckLanguage)
check_language(CUDA)

OPTION(SPECX_COMPILE_WITH_CUDA "Set to on to compile tasks with CUDA callables" ${CMAKE_CUDA_COMPILER})
OPTION(SPECX_COMPILE_WITH_HIP "Set to on to compile tasks with HIP callables" ${CMAKE_HIP_COMPILER})

if(SPECX_COMPILE_WITH_CUDA AND SPECX_COMPILE_WITH_HIP)
    message(FATAL_ERROR "Impossible to use both CUDA and HIP together")
endif()

if(SPECX_COMPILE_WITH_CUDA)
	enable_language(CUDA)
		
	if(NOT CMAKE_CUDA_ARCHITECTURES)
      set(CMAKE_CUDA_ARCHITECTURES "75" CACHE STRING
          "Set CUDA target architecture" FORCE)
    endif()
endif()

if(SPECX_COMPILE_WITH_HIP)
    # Search for rocm in common locations
    list(APPEND CMAKE_PREFIX_PATH /opt/rocm/hip /opt/rocm)
    # Find hip
    find_package(hip)
    # Set the GPU to compile for
    set(GPU_TARGETS "gfx900" CACHE STRING "GPU targets to compile for")
endif()

INCLUDE(CMakeDependentOption)
set(SPECX_LIBRARIES "")
set(SPECX_INCLUDE_DIR "")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# need pthread
list(APPEND SPECX_LIBRARIES pthread)


ADD_DEFINITIONS(${SPECX_CXX_FLAGS})




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


file(GLOB WFOPenMP_SRC
     "*.hpp"
     "*.cpp"
)


foreach (myfile ${WFOPenMP_SRC})
    get_filename_component(myname ${myfile} NAME_WLE)
    get_filename_component(dirname ${myfile} DIRECTORY)
    message("${myname}.cpp | ${dir_src}")

    add_executable(${myname} "${myname}.cpp")

	target_link_libraries(
		${myname}
		specx
		${SPECX_LIBRARIES}
		)


    #if(MPI_FOUND)
        #include_directories(SYSTEM ${MPI_INCLUDES_PATH})
        #target_include_directories(${myname}  PUBLIC ${MPI_CXX_INCLUDE_DIRS})
        #target_link_libraries(${myname}  PUBLIC ${MPI_CXX_LIBRARIES} )
    #endif()

    #if(OpenMP_CXX_FOUND)
    #    target_link_libraries(${myname} PUBLIC OpenMP::OpenMP_CXX ${OpenCV_LIBS})
    #endif()
endforeach (file ${WFOPenMP_SRC})



