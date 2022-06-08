#TestModule/CmakeLists.txt

#set variables
set(modules CoreFunction)
list(APPEND modules DataModel)
list(APPEND modules Utility)
#list(APPEND modules Clock)
list(APPEND modules DataReader)
list(APPEND modules DataWriter)

set(header_paths ${CMAKE_SOURCE_DIR}/CoreFunctionModule/inc/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/DataModelModule/inc/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/UtilityModule/inc/)
#list(APPEND header_paths ${CMAKE_SOURCE_DIR}/SupportFunction/ClockModule/inc/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/SupportFunction/DataReaderModule/inc/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/SupportFunction/DataWriterModule/inc/)

list(APPEND tools_paths ${CMAKE_SOURCE_DIR}/TestModule/Tools/plog/)

#include library
include_directories(${header_paths})
include_directories(${tools_paths})

#compile target
add_executable(SCLI scli.cpp)

#link libraries
target_link_libraries(SCLI ${modules})

# ADD COMPILE TIME DEFINITIONS -----------------------------------------------------------------------------------------
if (disableLogs)
    list(APPEND compile_definitions PLOG_DISABLE_LOGGING)
endif ()

add_compile_definitions(${compile_definitions})