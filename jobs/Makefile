CC=g++
MICROCC=microblazeel-xilinx-linux-gnu-g++
CFLAGS=-Wall
MICROCFLAGS=-mcpu=v8.40.b -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare -mno-xl-soft-mul -mno-xl-soft-div -mxl-float-sqrt -mhard-float -mxl-float-convert -mlittle-endian -Wall
DEBUGFLAGS=-ggdb -g -gdwarf-2 -g3 #gdwarf-2 + g3 provides macro info to gdb

PROJECT_DIR=../../
SHAKESPEARE_PATH=$(PROJECT_DIR)/space-lib/shakespeare
UTLS_PATH=$(PROJECT_DIR)/space-lib/utls

INCPATH=-I./include/ -I$(SHAKESPEARE_PATH)/inc
INCTESTPATH=-I./tests/unit/stubs/ -I./tests/helpers/include/
LIBPATH=-L./lib/ -L$(SHAKESPEARE_PATH)/lib -L$(UTLS_PATH)/lib
PC_LIBS=-lshakespeare -lcs1_utls
Q6_LIBS=-lshakespeare-mbcc -lcs1_utlsQ6
#LIBS=-lCppUTest -lCppUTestExt
#The test builds have their own main provided by CppUTest so we need to exclude commander.cpp
#DEBUG_SRC_FILES =`find src/ ! -name 'main.cpp' -name '*.cpp'`

make-directories:
	mkdir -p bin

% %/src/%.cpp:
	$(CC) $(CFLAGS) $(INCPATH) $(LIBPATH) $< -o $@ $(PC_LIBS

buildBin:
	$(CC) $(CFLAGS) $(INCPATH) $(LIBPATH) src/*.cpp -o bin/read-pwr-ad7998-x86 $(PC_LIBS)

buildQ6:
	$(MICROCC) $(MICROCFLAGS) $(INCPATH) $(LIBPATH) src/*.cpp -o bin/read-pwr-ad7998 $(Q6_LIBS)

bin/read-pwr-ad7998:
	$(CC) $(CFLAGS) $(INCPATH) $(LIBPATH) src/*.cpp -o $^ $(PC_LIBS)

read-pwr-ina219:

read-temp-EBPL:

read-temp-spts:

disable-AHRM: 

enable-AHRM:


