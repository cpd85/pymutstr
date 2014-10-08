all:
	gcc -shared -fPIC -I/usr/include/python2.7/ -lpython2.7 -o pymutstr.so pymutstr.c
   
.PHONY: clean
clean:
	rm -rf pymutstr.so
