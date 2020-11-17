# CMakeList.txt : CMake project for Logik, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Logik")

# Report all warnings
if (MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall)
endif()

# Main executable
add_executable (Logik "Logik.cpp" "Logik.h" "SequenceParser.h" "SequenceParser.cpp" "Main.cpp")

# Test executable
add_executable (LogikTest "test/Test.cpp" "SequenceParser.cpp" "Logik.cpp")
