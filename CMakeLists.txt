project(comptonplots)

add_definitions(-std=gnu++0x)

list(APPEND CMAKE_MODULE_PATH $ENV{ROOTSYS}/etc/cmake)

find_package(ROOT REQUIRED COMPONENTS Hist Gpad Graf MathCore) 

include_directories(${ROOT_INCLUDE_DIRS})

add_library(spectrum SHARED spectrum.cpp)
target_link_libraries(spectrum ${ROOT_LIBRARIES})

add_library(energySpectrum SHARED energySpectrum.cpp)
target_link_libraries(energySpectrum  ${ROOT_LIBRARIES} spectrum)

add_library(crystalEnergySpectrum SHARED crystalEnergySpectrum.cpp)
target_link_libraries(crystalEnergySpectrum  ${ROOT_LIBRARIES} energySpectrum)

add_executable(comptonplots main.cpp)

target_link_libraries(comptonplots spectrum energySpectrum crystalEnergySpectrum )
