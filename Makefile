CC:=gcc
CFLAGS:=-Wall -pedantic -ansi -g -O2

tresReversao: EP3.c
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o