CFLAGS=-Wall -O2 -D_FILE_OFFSET_BITS=64

all: rsig rdelta rpatch
rsig: rsig.c
	gcc $(CFLAGS) -o rsig rsig.c -lrsync
rdelta: rdelta.c
	gcc $(CFLAGS) -o rdelta rdelta.c -lrsync
rpatch: rpatch.c
	gcc $(CFLAGS) -o rpatch rpatch.c -lrsync
clean:
	rm -f rsig rdelta rpatch
