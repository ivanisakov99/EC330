.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET	=  Problem

C_SOURCES =  Problem.cpp 
C_OBJS     = Problem.o CuckooHashTable.o
MY_INCLUDES = CuckooHashTable.h
OUTPUTS = Problem.out

CCX = g++
CXXFLAGS = -g -std=c++11  -Wall

#============================================================
all: $(TARGET)

.o:.cpp	$(MY_INCLUDES)
	$(CCX)  -c  $(CXXFLAGS) $<  

Problem :   Problem.o CuckooHashTable.o
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

# Implicit rules: $@ = target name, $< = first prerequisite name, $^ = name of all prerequisites
#============================================================


clean:
	rm -f $(TARGET) $(C_OBJS) $(OUTPUTS) core *~