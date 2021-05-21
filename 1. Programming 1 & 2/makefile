.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET	=  Problem1 Problem2

C_SOURCES =  Problem1.cpp Problem2.cpp
C_OBJS     = Problem1.o Problem2.o
OUTPUTS	= Problem.out

CCX = g++
CXXFLAGS = -g -std=c++11  -Wall

#============================================================
all: $(TARGET)

.o:.cpp	$(MY_INCLUDES)
	$(CCX)  -c  $(CXXFLAGS) $<  

Problem1 :   Problem1.o
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

Problem2 :   Problem2.o
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

# Implicit rules: $@ = target name, $< = first prerequisite name, $^ = name of all prerequisites
#============================================================


clean:
	rm -f $(TARGET) $(C_OBJS) $(OUTPUTS) core *~
