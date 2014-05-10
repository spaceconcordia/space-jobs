CC=g++
MICROCC=microblazeel-xilinx-linux-gnu-g++
CFLAGS=-Wall
MICROCFLAGS=-mcpu=v8.40.b -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare -mno-xl-soft-mul -mno-xl-soft-div -mxl-float-sqrt -mhard-float -mxl-float-convert -mlittle-endian -Wall
DEBUGFLAGS=-ggdb -g -gdwarf-2 -g3 #gdwarf-2 + g3 provides macro info to gdb
INCPATH=-I./include/ #-I/home/ty/XiphosDevEnv/petalinux-v12.12-mbel/microblazeel-xilinx-linux-gnu/sys-root/usr/include/
INCTESTPATH=-I./tests/unit/stubs/ -I./tests/helpers/include/
LIBPATH=-L./lib/
#LIBS=-lCppUTest -lCppUTestExt
#The test builds have their own main provided by CppUTest so we need to exclude commander.cpp
#DEBUG_SRC_FILES =`find src/ ! -name 'main.cpp' -name '*.cpp'`

buildBin:
	$(CC) $(CFLAGS) $(INCPATH) $(LIBPATH) src/*.cpp -lshakespeare -o bin/enable-AHRM-x86

buildQ6:
	$(MICROCC) $(MICROCFLAGS) $(INCPATH) $(LIBPATH) src/*.cpp -lshakespeare-mbcc -o bin/enable-AHRM
