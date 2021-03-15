.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET	=  Problem4 Problem5

C_SOURCES =  Problem4.cpp
C_OBJS     = Problem4.o
MY_INCLUDES = 



CCX = g++
CXXFLAGS = -g -std=c++11  -Wall

#============================================================
all: $(TARGET)

.o:.cpp	$(MY_INCLUDES)
	$(CCX)  -c  $(CXXFLAGS) $<  

Problem4 :   Problem4.o
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

Problem5 :   Problem5.o
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

# Implicit rules: $@ = target name, $< = first prerequisite name, $^ = name of all prerequisites
#============================================================


clean:
	rm -f $(TARGET) $(C_OBJS) core *~