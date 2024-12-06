project(tga)
set(tga-src
	decoder.cpp
	encoder.cpp
	image_iterator.cpp
	memory.cpp
	stdio.cpp
	tga.h
)
add_library(tga-lib ${tga-src})
add_library(tga::tga ALIAS tga-lib)
target_include_directories(tga-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TARGET tga-lib PROPERTY CXX_STANDARD 20)
