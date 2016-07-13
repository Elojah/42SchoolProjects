cmake_minimum_required(VERSION 2.8)

#Project declaration
project(roolv2.0)

#set variables
set(BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_BUILD_DIRECTORY ${BIN_DIR})
set(CMAKE_BUILD_TYPE Release)
set(EXECUTABLE_OUTPUT_PATH ${BIN_DIR})
set (CMAKE_CXX_FLAGS "-MMD -Wall -Wextra -Werror -O3 -std=c++11")

#Set lib
set( CURSES_INCLUDE_PATH "/usr/include")
set( CURSES_LIBRARIES "/usr/lib/x86_64-linux-gnu/libncurses.so")
set( MENU_INCLUDE_PATH "/usr/include")
set( MENU_LIBRARIES "/usr/lib/x86_64-linux-gnu/libmenu.so.5.9")

#Set src & inc
set (
	INCLUDE_DIR
	include
)
file (
	GLOB_RECURSE
	source_files
	src/*
)

#Déclaration de l'exécutable
add_executable (
	exec
	${source_files}
)

target_link_libraries(exec ${CURSES_LIBRARIES} ${MENU_LIBRARIES})
include_directories(${INCLUDE_DIR} ${CURSES_INCLUDE_PATH} ${MENU_INCLUDE_PATH})
