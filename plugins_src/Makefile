CC=gcc
CFLAGS=-std=c11 -Wall

all:makeso
	cp *.so ../plugins/

makeso:cmp
	$(CC) $(CFLAGS) -shared -o libaddfnc.so addfnc.o && \
	$(CC) $(CFLAGS) -shared -o libsubfnc.so subfnc.o && \
	$(CC) $(CFLAGS) -shared -o libmulfnc.so mulfnc.o && \
	$(CC) $(CFLAGS) -shared -o libdivfnc.so divfnc.o

cmp:
	$(CC) $(CFLAGS) -c -fPIC *.c

clean:
	rm *.o *.so && rm ../plugins/*.so

