CC=g++
MICROCC=microblazeel-xilinx-linux-gnu-g++
CFLAGS=-Wall
MICROCFLAGS=-mcpu=v8.40.b -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare -mno-xl-soft-mul -mno-xl-soft-div -mxl-float-sqrt -mhard-float -mxl-float-convert -mlittle-endian -Wall
DEBUGFLAGS=-ggdb -g -gdwarf-2 -g3 #gdwarf-2 + g3 provides macro info to gdb

PROJECT_DIR=../../..
SPACE_LIB=$(PROJECT_DIR)/space-lib
SHAKESPEARE_PATH=$(SPACE_LIB)/shakespeare
UTLS_PATH=$(SPACE_LIB)/utls

INCPATH=-I./include/ -I$(SHAKESPEARE_PATH)/inc -I$(SPACE_LIB)/include
INCTESTPATH=-I./tests/unit/stubs/ -I./tests/helpers/include/
LIBPATH=-L./lib/ -L$(SHAKESPEARE_PATH)/lib -L$(UTLS_PATH)/lib
PC_LIBS=-lshakespeare -lcs1_utls
Q6_LIBS=-lshakespeare-mbcc -lcs1_utlsQ6

JOB_NAME=disable-AHRM

buildBin: make-directories
	$(CC) $(CFLAGS) $(INCPATH) $(LIBPATH) src/*.cpp -o bin/$(JOB_NAME)-x86 $(PC_LIBS)

buildQ6: make-directories
	$(MICROCC) $(MICROCFLAGS) $(INCPATH) $(LIBPATH) src/*.cpp -o bin/$(JOB_NAME) $(Q6_LIBS)

make-directories: 
	mkdir -p bin
