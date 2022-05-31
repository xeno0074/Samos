#TestModule/CmakeLists.txt

#set variables
set(modules CoreFunction)
list(APPEND modules DataModel)
list(APPEND modules Utility)
#list(APPEND modules Clock)
list(APPEND modules DataReader)
list(APPEND modules DataWriter)

#set(test_libs CoreFunctionTest)
#list(APPEND test_lib DataModelTest)
#list(APPEND test_lib UtilityTest)

set(header_paths ${CMAKE_SOURCE_DIR}/CoreFunctionModule/inc/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/DataModelModule/inc/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/CoreFunctionModule/test/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/UtilityModule/inc/)
#list(APPEND header_paths ${CMAKE_SOURCE_DIR}/SupportFunction/ClockModule/inc/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/SupportFunction/DataReaderModule/inc/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/TestModule/TestHelper/inc/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/SupportFunction/DataWriterModule/inc/)

set(tools_paths ${CMAKE_SOURCE_DIR}/TestModule/Tools/doctest/)
list(APPEND tools_paths ${CMAKE_SOURCE_DIR}/TestModule/Tools/plog/)

#include library
include_directories(${header_paths})
include_directories(${tools_paths})

file(GLOB test_src ${CMAKE_CURRENT_SOURCE_DIR}/TestHelper/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Tools/doctest/*.cpp)

#compile target
add_executable(SampleTest SampleTest.cpp ${test_src})
add_executable(FunctionTest FunctionTest.cpp ${test_src})

#link libraries
target_link_libraries(SampleTest ${modules})
target_link_libraries(FunctionTest ${modules})

# ADD COMPILE TIME DEFINITIONS -----------------------------------------------------------------------------------------
if (disableLogs)
    list(APPEND compile_definitions PLOG_DISABLE_LOGGING)
endif ()

add_compile_definitions(${compile_definitions})

# COPY TEST FILES GENERATOR SCRIPTS ------------------------------------------------------------------------------------
configure_file(${CMAKE_SOURCE_DIR}/TestModule/Scripts/conf_gen.py ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/TestModule/Scripts/entries_gen.py ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/TestModule/Scripts/utilities.py ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/TestModule/Scripts/prepare_test.py ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)

# EXECUTE SCRIPTS
#if (UNIX)
#    execute_process(
#            COMMAND python3 "${CMAKE_CURRENT_BINARY_DIR}/entries_gen.py"
#            ECHO_OUTPUT_VARIABLE
#    )
#endif ()
#
#if (WIN32)
#    execute_process(
#            COMMAND py "${CMAKE_CURRENT_BINARY_DIR}/entries_gen.py"
#            ECHO_OUTPUT_VARIABLE
#endif ()