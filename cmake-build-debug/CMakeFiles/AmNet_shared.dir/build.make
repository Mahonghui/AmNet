# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mahonghui/CLionProjects/AmNet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mahonghui/CLionProjects/AmNet/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AmNet_shared.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AmNet_shared.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AmNet_shared.dir/flags.make

CMakeFiles/AmNet_shared.dir/src/base/util.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/base/util.cpp.o: ../src/base/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AmNet_shared.dir/src/base/util.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/base/util.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/base/util.cpp

CMakeFiles/AmNet_shared.dir/src/base/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/base/util.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/base/util.cpp > CMakeFiles/AmNet_shared.dir/src/base/util.cpp.i

CMakeFiles/AmNet_shared.dir/src/base/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/base/util.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/base/util.cpp -o CMakeFiles/AmNet_shared.dir/src/base/util.cpp.s

CMakeFiles/AmNet_shared.dir/src/http/filehandler.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/http/filehandler.cpp.o: ../src/http/filehandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AmNet_shared.dir/src/http/filehandler.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/http/filehandler.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/http/filehandler.cpp

CMakeFiles/AmNet_shared.dir/src/http/filehandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/http/filehandler.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/http/filehandler.cpp > CMakeFiles/AmNet_shared.dir/src/http/filehandler.cpp.i

CMakeFiles/AmNet_shared.dir/src/http/filehandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/http/filehandler.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/http/filehandler.cpp -o CMakeFiles/AmNet_shared.dir/src/http/filehandler.cpp.s

CMakeFiles/AmNet_shared.dir/src/http/filestat.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/http/filestat.cpp.o: ../src/http/filestat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AmNet_shared.dir/src/http/filestat.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/http/filestat.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/http/filestat.cpp

CMakeFiles/AmNet_shared.dir/src/http/filestat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/http/filestat.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/http/filestat.cpp > CMakeFiles/AmNet_shared.dir/src/http/filestat.cpp.i

CMakeFiles/AmNet_shared.dir/src/http/filestat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/http/filestat.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/http/filestat.cpp -o CMakeFiles/AmNet_shared.dir/src/http/filestat.cpp.s

CMakeFiles/AmNet_shared.dir/src/http/httpparser.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/http/httpparser.cpp.o: ../src/http/httpparser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AmNet_shared.dir/src/http/httpparser.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/http/httpparser.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/http/httpparser.cpp

CMakeFiles/AmNet_shared.dir/src/http/httpparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/http/httpparser.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/http/httpparser.cpp > CMakeFiles/AmNet_shared.dir/src/http/httpparser.cpp.i

CMakeFiles/AmNet_shared.dir/src/http/httpparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/http/httpparser.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/http/httpparser.cpp -o CMakeFiles/AmNet_shared.dir/src/http/httpparser.cpp.s

CMakeFiles/AmNet_shared.dir/src/http/httpresponse.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/http/httpresponse.cpp.o: ../src/http/httpresponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AmNet_shared.dir/src/http/httpresponse.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/http/httpresponse.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/http/httpresponse.cpp

CMakeFiles/AmNet_shared.dir/src/http/httpresponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/http/httpresponse.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/http/httpresponse.cpp > CMakeFiles/AmNet_shared.dir/src/http/httpresponse.cpp.i

CMakeFiles/AmNet_shared.dir/src/http/httpresponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/http/httpresponse.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/http/httpresponse.cpp -o CMakeFiles/AmNet_shared.dir/src/http/httpresponse.cpp.s

CMakeFiles/AmNet_shared.dir/src/http/httpserver.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/http/httpserver.cpp.o: ../src/http/httpserver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/AmNet_shared.dir/src/http/httpserver.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/http/httpserver.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/http/httpserver.cpp

CMakeFiles/AmNet_shared.dir/src/http/httpserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/http/httpserver.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/http/httpserver.cpp > CMakeFiles/AmNet_shared.dir/src/http/httpserver.cpp.i

CMakeFiles/AmNet_shared.dir/src/http/httpserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/http/httpserver.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/http/httpserver.cpp -o CMakeFiles/AmNet_shared.dir/src/http/httpserver.cpp.s

CMakeFiles/AmNet_shared.dir/src/http/matcher.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/http/matcher.cpp.o: ../src/http/matcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/AmNet_shared.dir/src/http/matcher.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/http/matcher.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/http/matcher.cpp

CMakeFiles/AmNet_shared.dir/src/http/matcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/http/matcher.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/http/matcher.cpp > CMakeFiles/AmNet_shared.dir/src/http/matcher.cpp.i

CMakeFiles/AmNet_shared.dir/src/http/matcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/http/matcher.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/http/matcher.cpp -o CMakeFiles/AmNet_shared.dir/src/http/matcher.cpp.s

CMakeFiles/AmNet_shared.dir/src/http/route.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/http/route.cpp.o: ../src/http/route.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/AmNet_shared.dir/src/http/route.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/http/route.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/http/route.cpp

CMakeFiles/AmNet_shared.dir/src/http/route.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/http/route.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/http/route.cpp > CMakeFiles/AmNet_shared.dir/src/http/route.cpp.i

CMakeFiles/AmNet_shared.dir/src/http/route.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/http/route.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/http/route.cpp -o CMakeFiles/AmNet_shared.dir/src/http/route.cpp.s

CMakeFiles/AmNet_shared.dir/src/http/router.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/http/router.cpp.o: ../src/http/router.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/AmNet_shared.dir/src/http/router.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/http/router.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/http/router.cpp

CMakeFiles/AmNet_shared.dir/src/http/router.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/http/router.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/http/router.cpp > CMakeFiles/AmNet_shared.dir/src/http/router.cpp.i

CMakeFiles/AmNet_shared.dir/src/http/router.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/http/router.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/http/router.cpp -o CMakeFiles/AmNet_shared.dir/src/http/router.cpp.s

CMakeFiles/AmNet_shared.dir/src/log/asynclogger.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/log/asynclogger.cpp.o: ../src/log/asynclogger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/AmNet_shared.dir/src/log/asynclogger.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/log/asynclogger.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/log/asynclogger.cpp

CMakeFiles/AmNet_shared.dir/src/log/asynclogger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/log/asynclogger.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/log/asynclogger.cpp > CMakeFiles/AmNet_shared.dir/src/log/asynclogger.cpp.i

CMakeFiles/AmNet_shared.dir/src/log/asynclogger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/log/asynclogger.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/log/asynclogger.cpp -o CMakeFiles/AmNet_shared.dir/src/log/asynclogger.cpp.s

CMakeFiles/AmNet_shared.dir/src/log/logbuf.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/log/logbuf.cpp.o: ../src/log/logbuf.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/AmNet_shared.dir/src/log/logbuf.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/log/logbuf.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/log/logbuf.cpp

CMakeFiles/AmNet_shared.dir/src/log/logbuf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/log/logbuf.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/log/logbuf.cpp > CMakeFiles/AmNet_shared.dir/src/log/logbuf.cpp.i

CMakeFiles/AmNet_shared.dir/src/log/logbuf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/log/logbuf.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/log/logbuf.cpp -o CMakeFiles/AmNet_shared.dir/src/log/logbuf.cpp.s

CMakeFiles/AmNet_shared.dir/src/log/logfile.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/log/logfile.cpp.o: ../src/log/logfile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/AmNet_shared.dir/src/log/logfile.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/log/logfile.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/log/logfile.cpp

CMakeFiles/AmNet_shared.dir/src/log/logfile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/log/logfile.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/log/logfile.cpp > CMakeFiles/AmNet_shared.dir/src/log/logfile.cpp.i

CMakeFiles/AmNet_shared.dir/src/log/logfile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/log/logfile.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/log/logfile.cpp -o CMakeFiles/AmNet_shared.dir/src/log/logfile.cpp.s

CMakeFiles/AmNet_shared.dir/src/log/logger.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/log/logger.cpp.o: ../src/log/logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/AmNet_shared.dir/src/log/logger.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/log/logger.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/log/logger.cpp

CMakeFiles/AmNet_shared.dir/src/log/logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/log/logger.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/log/logger.cpp > CMakeFiles/AmNet_shared.dir/src/log/logger.cpp.i

CMakeFiles/AmNet_shared.dir/src/log/logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/log/logger.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/log/logger.cpp -o CMakeFiles/AmNet_shared.dir/src/log/logger.cpp.s

CMakeFiles/AmNet_shared.dir/src/log/util.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/log/util.cpp.o: ../src/log/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/AmNet_shared.dir/src/log/util.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/log/util.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/log/util.cpp

CMakeFiles/AmNet_shared.dir/src/log/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/log/util.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/log/util.cpp > CMakeFiles/AmNet_shared.dir/src/log/util.cpp.i

CMakeFiles/AmNet_shared.dir/src/log/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/log/util.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/log/util.cpp -o CMakeFiles/AmNet_shared.dir/src/log/util.cpp.s

CMakeFiles/AmNet_shared.dir/src/net/connection.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/net/connection.cpp.o: ../src/net/connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/AmNet_shared.dir/src/net/connection.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/net/connection.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/net/connection.cpp

CMakeFiles/AmNet_shared.dir/src/net/connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/net/connection.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/net/connection.cpp > CMakeFiles/AmNet_shared.dir/src/net/connection.cpp.i

CMakeFiles/AmNet_shared.dir/src/net/connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/net/connection.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/net/connection.cpp -o CMakeFiles/AmNet_shared.dir/src/net/connection.cpp.s

CMakeFiles/AmNet_shared.dir/src/net/epollor.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/net/epollor.cpp.o: ../src/net/epollor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/AmNet_shared.dir/src/net/epollor.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/net/epollor.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/net/epollor.cpp

CMakeFiles/AmNet_shared.dir/src/net/epollor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/net/epollor.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/net/epollor.cpp > CMakeFiles/AmNet_shared.dir/src/net/epollor.cpp.i

CMakeFiles/AmNet_shared.dir/src/net/epollor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/net/epollor.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/net/epollor.cpp -o CMakeFiles/AmNet_shared.dir/src/net/epollor.cpp.s

CMakeFiles/AmNet_shared.dir/src/net/eventbase.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/net/eventbase.cpp.o: ../src/net/eventbase.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/AmNet_shared.dir/src/net/eventbase.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/net/eventbase.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/net/eventbase.cpp

CMakeFiles/AmNet_shared.dir/src/net/eventbase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/net/eventbase.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/net/eventbase.cpp > CMakeFiles/AmNet_shared.dir/src/net/eventbase.cpp.i

CMakeFiles/AmNet_shared.dir/src/net/eventbase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/net/eventbase.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/net/eventbase.cpp -o CMakeFiles/AmNet_shared.dir/src/net/eventbase.cpp.s

CMakeFiles/AmNet_shared.dir/src/net/iobuffer.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/net/iobuffer.cpp.o: ../src/net/iobuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/AmNet_shared.dir/src/net/iobuffer.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/net/iobuffer.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/net/iobuffer.cpp

CMakeFiles/AmNet_shared.dir/src/net/iobuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/net/iobuffer.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/net/iobuffer.cpp > CMakeFiles/AmNet_shared.dir/src/net/iobuffer.cpp.i

CMakeFiles/AmNet_shared.dir/src/net/iobuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/net/iobuffer.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/net/iobuffer.cpp -o CMakeFiles/AmNet_shared.dir/src/net/iobuffer.cpp.s

CMakeFiles/AmNet_shared.dir/src/net/loop.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/net/loop.cpp.o: ../src/net/loop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/AmNet_shared.dir/src/net/loop.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/net/loop.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/net/loop.cpp

CMakeFiles/AmNet_shared.dir/src/net/loop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/net/loop.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/net/loop.cpp > CMakeFiles/AmNet_shared.dir/src/net/loop.cpp.i

CMakeFiles/AmNet_shared.dir/src/net/loop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/net/loop.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/net/loop.cpp -o CMakeFiles/AmNet_shared.dir/src/net/loop.cpp.s

CMakeFiles/AmNet_shared.dir/src/net/loopthread.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/net/loopthread.cpp.o: ../src/net/loopthread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/AmNet_shared.dir/src/net/loopthread.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/net/loopthread.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/net/loopthread.cpp

CMakeFiles/AmNet_shared.dir/src/net/loopthread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/net/loopthread.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/net/loopthread.cpp > CMakeFiles/AmNet_shared.dir/src/net/loopthread.cpp.i

CMakeFiles/AmNet_shared.dir/src/net/loopthread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/net/loopthread.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/net/loopthread.cpp -o CMakeFiles/AmNet_shared.dir/src/net/loopthread.cpp.s

CMakeFiles/AmNet_shared.dir/src/net/server.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/net/server.cpp.o: ../src/net/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building CXX object CMakeFiles/AmNet_shared.dir/src/net/server.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/net/server.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/net/server.cpp

CMakeFiles/AmNet_shared.dir/src/net/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/net/server.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/net/server.cpp > CMakeFiles/AmNet_shared.dir/src/net/server.cpp.i

CMakeFiles/AmNet_shared.dir/src/net/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/net/server.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/net/server.cpp -o CMakeFiles/AmNet_shared.dir/src/net/server.cpp.s

CMakeFiles/AmNet_shared.dir/src/net/threadpool.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/net/threadpool.cpp.o: ../src/net/threadpool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Building CXX object CMakeFiles/AmNet_shared.dir/src/net/threadpool.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/net/threadpool.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/net/threadpool.cpp

CMakeFiles/AmNet_shared.dir/src/net/threadpool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/net/threadpool.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/net/threadpool.cpp > CMakeFiles/AmNet_shared.dir/src/net/threadpool.cpp.i

CMakeFiles/AmNet_shared.dir/src/net/threadpool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/net/threadpool.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/net/threadpool.cpp -o CMakeFiles/AmNet_shared.dir/src/net/threadpool.cpp.s

CMakeFiles/AmNet_shared.dir/src/net/timerqueue.cpp.o: CMakeFiles/AmNet_shared.dir/flags.make
CMakeFiles/AmNet_shared.dir/src/net/timerqueue.cpp.o: ../src/net/timerqueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_23) "Building CXX object CMakeFiles/AmNet_shared.dir/src/net/timerqueue.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmNet_shared.dir/src/net/timerqueue.cpp.o -c /Users/mahonghui/CLionProjects/AmNet/src/net/timerqueue.cpp

CMakeFiles/AmNet_shared.dir/src/net/timerqueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmNet_shared.dir/src/net/timerqueue.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahonghui/CLionProjects/AmNet/src/net/timerqueue.cpp > CMakeFiles/AmNet_shared.dir/src/net/timerqueue.cpp.i

CMakeFiles/AmNet_shared.dir/src/net/timerqueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmNet_shared.dir/src/net/timerqueue.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahonghui/CLionProjects/AmNet/src/net/timerqueue.cpp -o CMakeFiles/AmNet_shared.dir/src/net/timerqueue.cpp.s

# Object files for target AmNet_shared
AmNet_shared_OBJECTS = \
"CMakeFiles/AmNet_shared.dir/src/base/util.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/http/filehandler.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/http/filestat.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/http/httpparser.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/http/httpresponse.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/http/httpserver.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/http/matcher.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/http/route.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/http/router.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/log/asynclogger.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/log/logbuf.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/log/logfile.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/log/logger.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/log/util.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/net/connection.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/net/epollor.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/net/eventbase.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/net/iobuffer.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/net/loop.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/net/loopthread.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/net/server.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/net/threadpool.cpp.o" \
"CMakeFiles/AmNet_shared.dir/src/net/timerqueue.cpp.o"

# External object files for target AmNet_shared
AmNet_shared_EXTERNAL_OBJECTS =

lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/base/util.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/http/filehandler.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/http/filestat.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/http/httpparser.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/http/httpresponse.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/http/httpserver.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/http/matcher.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/http/route.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/http/router.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/log/asynclogger.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/log/logbuf.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/log/logfile.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/log/logger.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/log/util.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/net/connection.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/net/epollor.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/net/eventbase.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/net/iobuffer.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/net/loop.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/net/loopthread.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/net/server.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/net/threadpool.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/src/net/timerqueue.cpp.o
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/build.make
lib/libAmNet.dylib: CMakeFiles/AmNet_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_24) "Linking CXX shared library lib/libAmNet.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AmNet_shared.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AmNet_shared.dir/build: lib/libAmNet.dylib

.PHONY : CMakeFiles/AmNet_shared.dir/build

CMakeFiles/AmNet_shared.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AmNet_shared.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AmNet_shared.dir/clean

CMakeFiles/AmNet_shared.dir/depend:
	cd /Users/mahonghui/CLionProjects/AmNet/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mahonghui/CLionProjects/AmNet /Users/mahonghui/CLionProjects/AmNet /Users/mahonghui/CLionProjects/AmNet/cmake-build-debug /Users/mahonghui/CLionProjects/AmNet/cmake-build-debug /Users/mahonghui/CLionProjects/AmNet/cmake-build-debug/CMakeFiles/AmNet_shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AmNet_shared.dir/depend

