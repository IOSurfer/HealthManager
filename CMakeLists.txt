cmake_minimum_required(VERSION 3.16)

project(HealthManager)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    message("CCACHE_FOUND")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

# Qt6 based on c++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS}  -O3 -Wall")

find_package(SQLite3 REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets Core Xml Gui)
qt_standard_project_setup()

include_directories(${CMAKE_SOURCE_DIR}/Source
                    ${CMAKE_SOURCE_DIR}/Include
                    ${CMAKE_SOURCE_DIR}/Ui)

set(HEALTH_MANAGER_SOURCE_FILE Source/Test/main.cpp

                               Source/Database/HmDatabase.cpp
                               Source/Database/HmBaseTable.cpp)

set(HEALTH_MANAGER_HEADER_FILE Source/Macro/HmDefineMember.h

                               Source/Database/HmDatabase.h
                               Source/Database/HmBaseTable.h)

set(HEALTH_MANAGER_RESOURCE_FILE )

qt_add_executable(${PROJECT_NAME}
                  ${HEALTH_MANAGER_SOURCE_FILE}
                  ${HEALTH_MANAGER_SOURCE_FILE}
                  ${HEALTH_MANAGER_SOURCE_FILE}
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets
                                              Qt6::Core
                                              Qt6::Gui
                                              Qt6::Xml
                                              SQLite::SQLite3)

if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE ON
    )
elseif(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE ON
    )
elseif(UNIX AND NOT APPLE)
endif()