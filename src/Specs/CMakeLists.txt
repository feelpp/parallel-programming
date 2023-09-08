project(BENCHMARK_SOLAR_SHADING_SPECX CXX)

ADD_DEFINITIONS(${SPECX_CXX_FLAGS})

message(CHECK_START "check OpenMP support")


if($ENV{VERBOSE})
    MESSAGE(STATUS "Benchmark SOLAR_SHADING -- SPECX_CXX_FLAGS   : ${BENCHMARK_CP_SPECX_CXX_FLAGS}")
endif()

find_package(BLAS)
find_package(LAPACK)




set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
#set(CMAKE_CXX_COMPILER "/usr/bin/gcc")
#set(CMAKE_CXX_COMPILER "/usr/bin/g++")


include(GNUInstallDirs)
include_directories("/usr/include/feelpp") 
include_directories("/usr/include/feelpp/eigen") 
add_definitions(-DOPENCV_DISABLE_EIGEN_TENSOR_SUPPORT)



if (POLICY CMP0077)
  cmake_policy(SET CMP0077 NEW)
  set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
endif()

find_package(MPI REQUIRED)
if (MPI_FOUND)
    MESSAGE("{MPI_CXX_LIBRARIES}")
    else (MPI_FOUND)
    MESSAGE (SEND_ERROR "This application cannot compile without MPI")
endif(MPI_FOUND)

#CRTL for solar shading if OK
if (MPI_CXX_WORKS)
    MESSAGE("{MPI_CXX_WORKS OK}")
    else (MPI_CXX_FOUND)
    MESSAGE (SEND_ERROR "MPI_CXX_WORKS not found")
endif(MPI_CXX_WORKS)

find_package(OpenMP)
if (OpenMP_CXX_FOUND)
    MESSAGE("{OpenMP_CXX_LIBRARIES}")
    else (OpenMP_CXX_FOUND)
    MESSAGE (SEND_ERROR "This application cannot compile without OpenMP")
endif(OpenMP_CXX_FOUND)

#find_package(OpenMP)
#if (OPENMP_FOUND)
#    set (CMAKE_C_FLAGS " ${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS} ")
#    set (CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} ")
#    set (CMAKE_EXE_LINKER_FLAGS " ${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS} ")
#endif()



#find_package(Feel++ COMPONENTS Toolboxes PATHS ${FEELPP_DIR}/share/feelpp/feel/cmake/modules $ENV{FEELPP_DIR}/share/feelpp/feel/cmake/modules /usr/share/feelpp/feel/cmake/modules /usr/local/share/feelpp/feel/cmake/modules )




#message("FEELPP DIR" ${FEELPP_DIR})

#if(NOT FEELPP_FOUND)
#  message(FATAL_ERROR "Feel++ was not found on your system. Make sure to install it and specify the FEELPP_DIR to reference the installation directory.")
#endif()

#if ( NOT FEELPP_TOOLBOXES_FOUND )
#  message(WARNING "Feel++ Toolboxes SDK is not found on your system. The toolbox application is now disabled.")
#endif()

#enable_testing()



#if ( NOT TARGET check )
#  add_custom_target(check)
#endif()

#include(CPack)


include_directories(SYSTEM ${MPI_INCLUDES_PATH})

if(BLAS_FOUND AND LAPACK_FOUND)
	if($ENV{VERBOSE})
	    MESSAGE(STATUS "Benchmark SOLAR_SHADING -- BLAS_LIBRARIES   : ${BLAS_LIBRARIES}")
	    MESSAGE(STATUS "Benchmark SOLAR_SHADING -- BLAS_LINKER_FLAGS   : ${BLAS_LINKER_FLAGS}")
	    MESSAGE(STATUS "Benchmark SOLAR_SHADING -- LAPACK_LIBRARIES   : ${LAPACK_LIBRARIES}")
	    MESSAGE(STATUS "Benchmark SOLAR_SHADING -- LAPACK_LINKER_FLAGS   : ${LAPACK_LINKER_FLAGS}")
	endif()

	# Find all code files
	file(	
	    GLOB_RECURSE
	    source_tests_files
	    ./*.cpp
	)


	# Adding the project sources dir as an include dir
	INCLUDE_DIRECTORIES(
	     ${SPECX_BINARY_DIR}/Src    
	     ${SPECX_SOURCE_DIR}/Src   
         ${MPI_CXX_INCLUDE_DIRS} 
		 ${OpenMP_CXX_INCLUDE_DIRS} 
	)

    LINK_DIRECTORIES(
    )


	# Add execs - 1 cpp = 1 exec
	foreach(exec ${source_tests_files}) 
    		if(${SPECX_COMPILE_WITH_MPI} OR NOT ${exec} MATCHES "-mpi\.")
		    get_filename_component(
			    execname ${exec}
			    NAME_WE
		    )

		    if($ENV{VERBOSE})
			    MESSAGE(STATUS "Benchmark -- Add ${execname}")
		    endif()

		    if(SPECX_COMPILE_WITH_CUDA)
			    set_source_files_properties(${exec} PROPERTIES LANGUAGE CUDA)
			    set(SPECX_LIBRARIES "${SPECX_LIBRARIES};cublas;cusolver")
		    endif()
		    

        

		    add_executable(${execname} ${exec})

        
		    
		    # TODO set_target_properties(${execname} PROPERTIES COMPILE_FLAGS "-llapack -lblas")

        #set_target_properties(${execname} PROPERTIES COMPILE_FLAGS "-llapack -lblas")

		    target_link_libraries(
			    ${execname}
			    specx
			    ${SPECX_LIBRARIES}
			    ${BLAS_LIBRARIES}
			    ${LAPACK_LIBRARIES}
				#Feelpp::feelpp
                ${MPI_CXX_LIBRARIES}
                ${OpenMP_CXX_LIBRARIES}
				#OpenMP::OpenMP_CXX
			)
		endif()
	endforeach(exec)
	
else(BLAS_FOUND AND LAPACK_FOUND)
    MESSAGE(STATUS "Benchmark SOLAR_SHADING -- Disable -- BLAS_FOUND : ${BLAS_FOUND}")
    MESSAGE(STATUS "Benchmark SOLAR_SHADING -- Disable -- LAPACK_FOUND : ${LAPACK_FOUND}")
endif()







