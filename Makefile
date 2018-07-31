CC	=	gcc
CFLAGS	=	-Wall -fPIC
BUILD	=	libpkg1.so libpkg2.so libpkg3.so usepkg1 usepkg2 \
		usef12pkg1 usef12pkg2 usef12bothpkgs usef12threepkgs \
		usef34threepkgs

all:	$(BUILD)

clean:
	/bin/rm -f $(BUILD) *.o lib*so.[0-9]* core a.out

usepkg1:	usepkg1.o libpkg1.so
	$(CC) -o usepkg1 usepkg1.o -L. -lpkg1

usepkg2:	usepkg2.o libpkg2.so
	$(CC) -o usepkg2 usepkg2.o -L. -lpkg2

usef12pkg1:	usef12pkg1.o f12.o
	$(CC) -o usef12pkg1 usef12pkg1.o f12.o -ldl

usef12pkg2:	usef12pkg2.o f12.o
	$(CC) -o usef12pkg2 usef12pkg2.o f12.o -ldl

usef12bothpkgs:	usef12bothpkgs.o f12.o
	$(CC) -o usef12bothpkgs usef12bothpkgs.o f12.o -ldl

usef12threepkgs:	usef12threepkgs.o f12.o
	$(CC) -o usef12threepkgs usef12threepkgs.o f12.o -ldl

usef34threepkgs:	usef34threepkgs.o f34.o
	$(CC) -o usef34threepkgs usef34threepkgs.o f34.o -ldl

libpkg1.so:	pkg1.o
	$(CC) -shared -Wl,-soname,libpkg1.so.1 -o libpkg1.so.1 pkg1.o
	rm -f libpkg1.so
	ln -s libpkg1.so.1 libpkg1.so

libpkg2.so:	pkg2.o
	$(CC) -shared -Wl,-soname,libpkg2.so.1 -o libpkg2.so.1 pkg2.o
	rm -f libpkg2.so
	ln -s libpkg2.so.1 libpkg2.so

libpkg3.so:	pkg3.o
	$(CC) -shared -Wl,-soname,libpkg3.so.1 -o libpkg3.so.1 pkg3.o
	rm -f libpkg3.so
	ln -s libpkg3.so.1 libpkg3.so
