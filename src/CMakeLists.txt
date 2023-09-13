###  TEMPLATE.txt.tpl; coding: utf-8 ---

#  Author(s): Christophe Prud'homme <christophe.prudhomme@feelpp.org>
#       Date: 2020-06-03
#
#  Copyright (C) 2020 Cemosis
#
# Distributed under the GPL(GNU Public License):
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#
#


#set(PARALLELPROGRAMMING_TARGET_NAME pp)
#add_library(${PARALLELPROGRAMMING_TARGET} INTERFACE)
#target_include_directories(${PARALLELPROGRAMMING_TARGET} INTERFACE
#  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
#  $<INSTALL_INTERFACE:include>
#  )
#target_link_libraries(${PARALLELPROGRAMMING_TARGET} INTERFACE Feelpp::feelpp)


#BEGIN:MPI
if(TRUE)
    add_subdirectory(MPI/MPI_1)
    add_subdirectory(MPI/MPI_2)
    add_subdirectory(MPI/MPI_3)
endif()
#END:MPI/+++>OK

#BEGIN:OpenMP
if(TRUE)
    add_subdirectory(OpenMP)
endif()
#END:OpenMP//+++>OK

#BEGIN:OpenStar
if(TRUE)
    add_subdirectory(OpenStar/OpenMP_MPI)
endif()
#END:OpenStar//+++>OK

#BEGIN:CUDA PART
if(FALSE)
    add_subdirectory(CUDA/Array_Addition)
    add_subdirectory(CUDA/Array_Reduction)
    add_subdirectory(CUDA/Matrix_Summation)
    add_subdirectory(CUDA/Matrix_Summation)
    add_subdirectory(CUDA/Task_Parallelism)
    add_subdirectory(CUDA/Vector)
endif()
#END:CUDA PART

#BEGIN:HIP
if(FALSE)
    add_subdirectory(HIP/Array_Addition)
    add_subdirectory(HIP/Matrix_Summation)
    add_subdirectory(HIP/Practice)
endif()
#END:HIP

#BEGIN:GayaPerformance
if(TRUE)
    add_subdirectory(GayaPerformance/HPC_Explorer)
endif()
#BEGIN:GayaPerformance//+++>OK

if(FALSE)
    add_subdirectory(GayaPerformance/HPC_Process)
endif()
#END:GayaPerformance/PB /usr/include/sys/times.h' file not found

#BEGIN:Quicksort
if(TRUE)
    add_subdirectory(Quicksort)
endif()
#END:Quicksort//+++>OK

#BEGIN:Specx
if(FALSE)
    add_subdirectory(Specx)
endif()
#END:Specx


#BEGIN:Heat_Equation_ParallelPrograming_Comparison
if(FALSE)
    add_subdirectory(Heat_Equation_ParallelPrograming_Comparison/Cuda)
endif()

if(FALSE)
    add_subdirectory(Heat_Equation_ParallelPrograming_Comparison/Hip)
endif()

if(TRUE)
    add_subdirectory(Heat_Equation_ParallelPrograming_Comparison/MPI)
endif()

if(FALSE)
    add_subdirectory(Heat_Equation_ParallelPrograming_Comparison/MPI_OpenMP)
endif()
#END:Heat_Equation_ParallelPrograming_Comparison


