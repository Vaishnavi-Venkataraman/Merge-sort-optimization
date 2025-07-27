CC=gcc

# Default flags if DEBUG not set
CFLAGS=-Wall -O2
SRC_COMMON=util.c

# If DEBUG=1 is passed, override flags
ifeq ($(DEBUG),1)
	CFLAGS=-Wall -g -DDEBUG
endif

all: sort

sort: main.c $(SRC_COMMON) sort_a.c sort_i.c sort_p.c sort_c.c sort_m.c sort_f.c
	$(CC) $(CFLAGS) -o sort main.c $(SRC_COMMON) sort_a.c sort_i.c sort_p.c sort_c.c sort_m.c sort_f.c

# Individual versions
sort_a: main.c $(SRC_COMMON) sort_a.c
	$(CC) $(CFLAGS) -o sort_a main.c $(SRC_COMMON) sort_a.c

sort_i: main.c $(SRC_COMMON) sort_i.c
	$(CC) $(CFLAGS) -o sort_i main.c $(SRC_COMMON) sort_i.c

sort_p: main.c $(SRC_COMMON) sort_p.c
	$(CC) $(CFLAGS) -o sort_p main.c $(SRC_COMMON) sort_p.c

sort_c: main.c $(SRC_COMMON) sort_c.c
	$(CC) $(CFLAGS) -o sort_c main.c $(SRC_COMMON) sort_c.c

sort_m: main.c $(SRC_COMMON) sort_m.c
	$(CC) $(CFLAGS) -o sort_m main.c $(SRC_COMMON) sort_m.c

sort_f: main.c $(SRC_COMMON) sort_f.c
	$(CC) $(CFLAGS) -o sort_f main.c $(SRC_COMMON) sort_f.c

clean:
	rm -f sort sort_a sort_i sort_p sort_c sort_m sort_f *.o
