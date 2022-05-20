#SupportFunction/DataReaderModule/CmakeLists.txt

#file globbing
file(GLOB source "src/*.cpp")

#include header
include_directories(inc/)
include_directories(${CMAKE_SOURCE_DIR}/UtilityModule/inc/)
include_directories(${CMAKE_SOURCE_DIR}/DataModelModule/inc/)
include_directories(${CMAKE_SOURCE_DIR}/TestModule/)

#compile module
add_library(DataReader STATIC ${source})