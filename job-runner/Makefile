CC=gcc
CXX=g++
CXX_FLAGS=-fpermissive
MICROCC=microblazeel-xilinx-linux-gnu-gcc
MICROPP=microblazeel-xilinx-linux-gnu-g++
BEAGLECC=arm-linux-gnueabi-g++
#CFLAGS=-static
MICROCFLAGS=-mcpu=v8.40.b -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare -mno-xl-soft-mul -mno-xl-soft-div -mxl-float-sqrt -mhard-float -mxl-float-convert -mlittle-endian -Wall
DEBUGFLAGS=-ggdb -g -gdwarf-2 -g3 #gdwarf-2 + g3 provides macro info to gdb

CS1_PATH = ../../

CPPUTEST_HOME = $(CS1_PATH)/CppUTest
CPPFLAGS += -Wall -I$(CPPUTEST_HOME)/include
MEM_LEAK_MACRO = -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h  -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
CPPUTEST_INCLUDES = -I$(CPPUTEST_HOME)/include/ -I$(SPACELIB_PATH)/include/

TIMER_PATH=../../space-timer-lib
SPACELIB_PATH=../../space-lib
SHAKESPEARE_PATH=$(SPACELIB_PATH)/shakespeare
UTLS_PATH=$(SPACELIB_PATH)/utls

INCPATH=-I./inc/ -I$(SPACELIB_PATH)/include -I$(TIMER_PATH)/inc -I$(SHAKESPEARE_PATH)/inc -I$(UTLS_PATH)/include
BBINCPATH=-I./inc/BB/
LIBPATH=-L./lib -L$(TIMER_PATH)/lib -L$(SHAKESPEARE_PATH)/lib -L$(UTLS_PATH)/lib
PCLIBS=-ltimer -lshakespeare -lcs1_utls -lrt
Q6LIBS=-ltimer-mbcc -lshakespeare-mbcc -lcs1_utlsQ6 -lrt
BBLIBS=-ltimer-BB -lshakespeare-BB -lcs1_utlsBB -lrt

buildBin: makedir
	$(CXX) $(CXX_FLAGS) $(INCPATH) $(PCINCPATH) $(LIBPATH) $(DEBUGFLAGS) src/jobrunner.cpp $(PCLIBS) -o bin/job-runner

buildQ6: makedir
	$(MICROPP) $(CXX_FLAGS) $(MICROCFLAGS) $(INCPATH) $(MICROINCPATH) $(LIBPATH) $(DEBUGFLAGS) src/jobrunner.cpp $(Q6LIBS) -o bin/job-runner-mbcc

buildBB:
	$(BEAGLECC) $(CXX_FLAGS) $(INCPATH) $(BBINCPATH) $(LIBPATH) $(DEBUGFLAGS) -static -c src/jobrunner.cpp -ltimer-BB -lshakespeare-BB

UNIT_TEST = tests/unit/job-runner-test.cpp
bin/AllTests: tests/unit/AllTests.cpp $(UNIT_TEST) $(OBJECTS) 
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(DEBUGFLAGS) $(CPPUTEST_INCLUDES) $(LIBPATH) -o $@ $^ $(LIBS) $(ENV)

makedir:
	mkdir -p bin

clean: 
	rm -rf bin/ lib/
