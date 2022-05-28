#CoreFunctionModule/CmakeLists.txt

#file globbing
file(GLOB source "src/*.cpp")
file(GLOB test_files "test/*")

#include header
include_directories(inc/)
include_directories(${CMAKE_SOURCE_DIR}/UtilityModule/inc/)
include_directories(${CMAKE_SOURCE_DIR}/DataModelModule/inc/)
include_directories(${CMAKE_SOURCE_DIR}/TestModule/Tools/doctest/)
include_directories(${CMAKE_SOURCE_DIR}/TestModule/Tools/plog/)

#compile module
add_library(CoreFunction STATIC ${source})
add_library(CoreFunctionTest STATIC ${test_files})

# ADD COMPILE TIME DEFINITIONS -----------------------------------------------------------------------------------------
if (disableLogs)
    list(APPEND compile_definitions PLOG_DISABLE_LOGGING)
endif ()

add_compile_definitions(${compile_definitions})