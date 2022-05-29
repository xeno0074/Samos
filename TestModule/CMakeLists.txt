#TestModule/CmakeLists.txt

#set variables
set(modules CoreFunction)
list(APPEND modules DataModel)
list(APPEND modules Utility)
#list(APPEND modules Clock)
list(APPEND modules DataReader)

set(test_libs CoreFunctionTest)
#list(APPEND test_lib DataModelTest)
#list(APPEND test_lib UtilityTest)

set(header_paths ${CMAKE_SOURCE_DIR}/CoreFunctionModule/inc/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/DataModelModule/inc/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/UtilityModule/inc/)
#list(APPEND header_paths ${CMAKE_SOURCE_DIR}/SupportFunction/ClockModule/inc/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/SupportFunction/DataReaderModule/inc/)

set(tools_paths ${CMAKE_SOURCE_DIR}/TestModule/Tools/doctest/)
list(APPEND tools_paths ${CMAKE_SOURCE_DIR}/TestModule/Tools/plog/)

#include library
include_directories(${header_paths})
include_directories(${tools_paths})

#compile target
add_executable(SampleTest SampleTest.cpp)
add_executable(FunctionTest FunctionTest.cpp)

#link libraries
target_link_libraries(SampleTest ${modules})
target_link_libraries(FunctionTest ${modules} ${test_libs})

# ADD COMPILE TIME DEFINITIONS -----------------------------------------------------------------------------------------
if (disableLogs)
    list(APPEND compile_definitions PLOG_DISABLE_LOGGING)
endif ()

add_compile_definitions(${compile_definitions})

# COPY TEST FILES GENERATOR SCRIPTS ------------------------------------------------------------------------------------
configure_file(${CMAKE_SOURCE_DIR}/TestModule/Scripts/conf_gen.py ${CMAKE_BINARY_DIR}/TestModule/ COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/TestModule/Scripts/entries_gen.py ${CMAKE_BINARY_DIR}/TestModule/ COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/TestModule/Scripts/utilities.py ${CMAKE_BINARY_DIR}/TestModule/ COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/TestModule/Scripts/prepare_test.py ${CMAKE_BINARY_DIR}/TestModule/ COPYONLY)