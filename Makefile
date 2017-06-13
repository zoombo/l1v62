CC=gcc
CFLAGS=-std=c11 -Wall

all:mlib sublibs
	$(CC) $(CFLAGS) main.c -L. -lmlibdyn -ldl -o less1

mlib:flib
	$(CC) $(CFLAGS) -shared -o libmlibdyn.so helper_funcs.o

flib:
	$(CC) $(CFLAGS) -c -fPIC helper_funcs.c

sublibs:
	make -C ./plugins_src/

clean:
	rm *.o less1 libmlibdyn.so && \
	make -C ./plugins_src/ clean


