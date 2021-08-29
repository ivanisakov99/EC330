CCX = g++
CXXFLAGS = -g -std=c++11 -Wall
# shell := /bin/zsh
# Build the parser .o file
# test.o: myshell_parser.c myshell_parser.h
Problems.o: Problems.cpp Problems.hpp

# Automatically discover all test files
test_cpp_files=$(shell find . -type f -name 'test*.cpp')
test_o_files=$(test_cpp_files:.cpp=.o)
test_files=$(test_cpp_files:.cpp=)


# The intermediate test .o files shouldn't be auto-deleted in test runs; they
# may be useful for incremental builds while fixing fs.c bugs.
.SECONDARY: $(test_o_files)

.PHONY: clean check checkprogs

# Rules to build each individual test
./%: ./%.o Problems.o
	$(CCX) $(CXXFLAGS) $^ $(LIBDIRS) -o $@

# Build all of the test programs
checkprogs: $(test_files)

# Run the test programs
check: checkprogs
	./run_tests.sh $(test_files)

clean:
	rm -f *.o $(test_files) $(test_o_files)

# .SUFFIXES:
# .SUFFIXES: .o .cpp
# #============================================================
# TARGET	=  Problem1 Problem2

# C_SOURCES =  Problem1.cpp Problem2.cpp
# C_OBJS     = Problem1.o Problem2.o
# OUTPUTS	= Problem.out

# CCX = g++
# CXXFLAGS = -g -std=c++11  -Wall

# #============================================================
# all: $(TARGET)

# .o:.cpp	$(MY_INCLUDES)
# 	$(CCX)  -c  $(CXXFLAGS) $<  

# Problem1 :   Problem1.o
# 	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

# Problem2 :   Problem2.o
# 	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

# # Implicit rules: $@ = target name, $< = first prerequisite name, $^ = name of all prerequisites
# #============================================================


# clean:
# 	rm -f $(TARGET) $(C_OBJS) $(OUTPUTS) core *~
