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

SUBDIRS=disable-AHRM enable-AHRM read-pwr-ad7998 read-temp-EBPL disable-AHRM read-acs-mag read-pwr-ina219 read-temp-spts

make-directories:
	mkdir -p bin

buildBin: make-directories
	set -e; for dir in ${SUBDIRS} ; do cd $$dir; make buildBin; cp bin/* ../bin/ ; cd ..; done

buildQ6: make-directories
	set -e; for dir in ${SUBDIRS} ; do cd $$dir; make buildQ6; cp bin/* ../bin/ ; cd ..; done
