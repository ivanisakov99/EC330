.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET	=  Problem1 Problem2

C_SOURCES =  Problem1.cpp
C_OBJS     = Problem1.o
MY_INCLUDES = 



CCX = g++
CXXFLAGS = -g -std=c++11  -Wall

#============================================================
all: $(TARGET)

.o:.cpp	$(MY_INCLUDES)
	$(CCX)  -c  $(CXXFLAGS) $<  

Problem4 :   Problem1.o
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

Problem5 :   Problem2.o
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

# Implicit rules: $@ = target name, $< = first prerequisite name, $^ = name of all prerequisites
#============================================================


clean:
	rm -f $(TARGET) $(C_OBJS) core *~