# Definitions

 MAKE         = make -s
 CC           = /home/lab/bin/mpich/bin/mpicc
 MYHEADER     = -I../../../include/ -I../../../include/base
 MYLIBPATH    = -L../../../src/base
 LIBRARIES    = -lpthread -ldl
 MYFLAGS      = -O2 -Wall -D_REENTRANT -DPOSIX_THREADS -DHAVE_CONFIG_H

# Rules

all: prueba_create open_write_close

prueba_create: prueba_create.o
	$(CC) -o prueba_create prueba_create.o $(MYLIBPATH) $(LIBRARIES)

open_write_close: open_write_close.o
	$(CC) -o open_write_close open_write_close.o $(MYLIBPATH) $(LIBRARIES)

%.o: %.c
	$(CC) $(CFLAGS) $(MYFLAGS) $(MYHEADER) -c $< -o $@

clean:
	rm -f ./*.o
	rm -f ./prueba_create ./open_write_close