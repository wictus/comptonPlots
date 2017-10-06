project(comptonplots)

add_definitions(-std=gnu++0x)

list(APPEND CMAKE_MODULE_PATH $ENV{ROOTSYS}/etc/cmake)

find_package(ROOT REQUIRED COMPONENTS Hist Gpad Graf MathCore) 

include_directories(${ROOT_INCLUDE_DIRS})

add_library(spectrum SHARED spectrum.cpp)
target_link_libraries(spectrum ${ROOT_LIBRARIES})

add_library(comptonSpectrum SHARED comptonSpectrum.cpp)
target_link_libraries(comptonSpectrum  ${ROOT_LIBRARIES} spectrum)

add_library(crystalEnergySpectrum SHARED crystalEnergySpectrum.cpp)
target_link_libraries(crystalEnergySpectrum  ${ROOT_LIBRARIES} spectrum comptonSpectrum)

add_executable(comptonplots main.cpp)

target_link_libraries(comptonplots spectrum comptonSpectrum crystalEnergySpectrum )
