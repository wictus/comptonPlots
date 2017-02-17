project(comptonplots)

add_definitions(-std=gnu++0x)

list(APPEND CMAKE_MODULE_PATH $ENV{ROOTSYS}/etc/cmake)

find_package(ROOT REQUIRED COMPONENTS Hist Gpad Graf MathCore) 

include_directories(${ROOT_INCLUDE_DIRS})

add_library(comptonSpectrum SHARED comptonSpectrum.cpp)
target_link_libraries(comptonSpectrum ${ROOT_LIBRARIES})

add_library(energySpectrum SHARED energySpectrum.cpp)
target_link_libraries(energySpectrum  ${ROOT_LIBRARIES} comptonSpectrum)

add_executable(comptonplots main.cpp)

target_link_libraries(comptonplots comptonSpectrum energySpectrum)
