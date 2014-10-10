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

buildBin:
	$(CC) $(CFLAGS) $(INCPATH) $(LIBPATH) src/*.cpp -o bin/read-acs-mag-x86 $(PC_LIBS)

buildQ6:
	$(MICROPP) $(MICROCFLAGS) $(INCPATH) $(LIBPATH) src/*.cpp o bin/read-acs-mag $(Q6_LIBS)

clean:
	rm -f bin/* lib/* 

#buildAllTests: buildUnitTests
#buildUnitTests:
#        $(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCPATH) $(INCTESTPATH) $(LIBPATH) src/*.cpp tests/unit/*.cpp -o bin/AllUnitTests $(LIBS)


#%.o: %.cpp
#        $(CC) $(CFLAGS) $(INCPATH) $(LIBPATH) -DPC -c $^ -o $@

#%.a: %.o
#        ar -cvq $@ $^

#staticlibs.tar: src/NamedPipe.a src/Net2Com.a
#        mv $^ ./
#        tar -cf $@ include/NamedPipe.h include/Net2Com.h NamedPipe.a Net2Com.a
#        rm *.a

#src/NamedPipeQ6.o: src/NamedPipe.cpp
#        $(MICROCC) $(MICROCFLAGS) $(INCPATH) -c $^ -o $@

#src/Net2ComQ6.o : src/Net2Com.cpp
#        $(MICROCC) $(MICROCFLAGS) $(INCPATH) -c $^ -o $@

#src/NamedPipe-mbcc.a: src/NamedPipeQ6.o
#        ar -cvq $@ $^

#src/Net2Com-mbcc.a: src/Net2ComQ6.o
#        ar -cvq $@ $^

#staticlibsQ6.tar: src/NamedPipe-mbcc.a src/Net2Com-mbcc.a
#        mv $^ ./
#        tar -cf $@ include/NamedPipe.h include/Net2Com.h NamedPipe-mbcc.a Net2Com-mbcc.a
