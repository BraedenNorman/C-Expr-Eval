all: stacktest

stacktest: istack.h istack.c istack-tests.c
	gcc istack.c istack-tests.c -o stacktest

clean:
	@rm -f *.o stacktest