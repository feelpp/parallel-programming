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
add_subdirectory(MPI/MPI_1)
add_subdirectory(MPI/MPI_2)
add_subdirectory(MPI/MPI_3)
#END:MPI

#BEGIN:OpenMP
add_subdirectory(OpenMP)
#END:OpenMP

#BEGIN:OpenStar
add_subdirectory(OpenStar/OpenMP_MPI)
#END:OpenStar

#BEGIN:CUDA PART
add_subdirectory(CUDA/Array_Addition)
add_subdirectory(CUDA/Array_Reduction)
add_subdirectory(CUDA/Matrix_Summation)
add_subdirectory(CUDA/Matrix_Summation)
add_subdirectory(CUDA/Task_Parallelism)
add_subdirectory(CUDA/Vector)
#END:CUDA PART

#BEGIN:HIP
add_subdirectory(HIP/Array_Addition)
add_subdirectory(HIP/Matrix_Summation)
add_subdirectory(HIP/Practice)
#END:HIP

#BEGIN:GayaPerformance
add_subdirectory(GayaPerformance/HPC_Explorer)
add_subdirectory(GayaPerformance/HPC_Process)
#END:GayaPerformance

#BEGIN:Quicksort
add_subdirectory(Quicksort)
#END:Quicksort

#BEGIN:Specx
add_subdirectory(Specx)
#END:Specx


#BEGIN:Heat_Equation_ParallelPrograming_Comparison
add_subdirectory(Heat_Equation_ParallelPrograming_Comparison/Cuda)
add_subdirectory(Heat_Equation_ParallelPrograming_Comparison/Hip)
add_subdirectory(Heat_Equation_ParallelPrograming_Comparison/MPI)
add_subdirectory(Heat_Equation_ParallelPrograming_Comparison/MPI_OpenMP)
#END:Heat_Equation_ParallelPrograming_Comparison


