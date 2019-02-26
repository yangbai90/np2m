cmake_minimum_required(VERSION 3.10)

project(np2m)

set(CMAKE_CXX_STANDARD 14)


#####################################
### For debug mode
#####################################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra")


#####################################
### For release mode
#####################################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -O3 -march=native")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")


set(SRC src/main.cpp)

################################
### For string utils 
###############################
set(INC include/StringUtils.h)
set(SRC ${SRC} src/StringUtils/LowerAndUpperCaseConvert.cpp)
set(SRC ${SRC} src/StringUtils/RemoveSpace.cpp)
set(SRC ${SRC} src/StringUtils/SplitNumVecFromString.cpp)
set(SRC ${SRC} src/StringUtils/SplitStringVecBySymbol.cpp)

####################################
### For GeoReader 
####################################
set(INC ${INC} include/GeoReader.h)
set(SRC ${SRC} src/GeoReader/GeoReader.cpp)
set(SRC ${SRC} src/GeoReader/ReadGeoFile.cpp)
set(SRC ${SRC} src/GeoReader/ModifyForCirlce.cpp src/GeoReader/ModifyForSphere.cpp)
set(SRC ${SRC} src/GeoReader/PrintInfo.cpp)


add_executable(np2m ${SRC} ${INC})



