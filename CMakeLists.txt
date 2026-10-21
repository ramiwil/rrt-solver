cmake_minimum_required(VERSION 3.23)

project(RRTSolver)

file(GLOB_RECURSE ALL_SOURCES
	${CMAKE_SOURCE_DIR}/src/*.cpp
	${CMAKE_SOURCE_DIR}/src/*.h
)


add_executable(RRTSolver)

target_sources(RRTSolver
	PRIVATE	${ALL_SOURCES}
)


find_program(CLANG_FORMAT clang-format)
if(CLANG_FORMAT)
	add_custom_target(
		COMMAND ${CLANG_FORMAT} -i ${ALL_SOURCES}
		COMMENT "Formatting source files."
	)
endif()
