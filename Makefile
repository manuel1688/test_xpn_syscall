# Definitions

 MAKE         = make -s
 CC           = /home/lab/bin/mpich/bin/mpicc
 MYHEADER     = -I../../../include/ -I../../../include/base
 MYLIBPATH    = -L../../../src/base
 LIBRARIES    = -lpthread -ldl
 MYFLAGS      = -O2 -Wall -D_REENTRANT -DPOSIX_THREADS -DHAVE_CONFIG_H

# Rules
all: create_write_close open_read_close

create_write_close: create_write_close.c
	$(CC) -o create_write_close create_write_close.o $(MYLIBPATH) $(LIBRARIES)

open_read_close: open_read_close.c
	$(CC) -o open_read_close open_read_close.o $(MYLIBPATH) $(LIBRARIES)

%.o: %.c
	$(CC) $(CFLAGS) $(MYFLAGS) $(MYHEADER) -c $< -o $@

clean:
	rm -f ./*.o
	rm -f ./create_write_close ./open_read_close