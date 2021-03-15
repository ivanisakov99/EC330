.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET	=  Problem

C_SOURCES =  Problem.cpp
C_OBJS     = Problem.o
MY_INCLUDES = MaxProduct.h



CCX = g++
CXXFLAGS = -g -std=c++11  -Wall

#============================================================
all: $(TARGET)

.o:.cpp	$(MY_INCLUDES)
	$(CCX)  -c  $(CXXFLAGS) $<  

Problem :   MaxProduct.o
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

# Implicit rules: $@ = target name, $< = first prerequisite name, $^ = name of all prerequisites
#============================================================


clean:
	rm -f $(TARGET) $(C_OBJS) core *~