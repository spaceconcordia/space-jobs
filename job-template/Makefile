JOBNAME=job_template
CC=g++
MICROCC=microblazeel-xilinx-linux-gnu-g++
MICROCCPATH=/home/ty/XiphosDevEnv/petalinux-v12.12-mbel/bin
#MICROCC=$(MICROCCPATH)/microblazeel-xilinx-linux-gnu-g++
CFLAGS=-Wall
MICROCFLAGS=-mcpu=v8.40.b -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare -mno-xl-soft-mul -mno-xl-soft-div -mxl-float-sqrt -mhard-float -mxl-float-convert -mlittle-endian -Wall
DEBUGFLAGS=-ggdb -g -gdwarf-2 -g3 #gdwarf-2 + g3 provides macro info to gdb
INCPATH=-I ./inc/ -I../../space-lib/shakespeare/inc/ 
LIBPATH=-L./lib/ -L../../space-lib/shakespeare/lib/

buildBin:
	$(CC) $(CFLAGS) $(INCPATH) $(LIBPATH) src/*.cpp -lshakespeare -o bin/$(JOBNAME)-x86

buildQ6:
	$(MICROCC) $(MICROCFLAGS) $(INCPATH) $(LIBPATH) src/*.cpp -lshakespeare-mbcc -o bin/$(JOBNAME)
