CC	=	gcc
CFLAGS	=	-Wall -fPIC
BUILD	=	libpkg1.so libpkg2.so libpkg3.so usepkg1 usepkg2 \
		f12pkg1 f12pkg2 f12bothpkgs f12namedpkgs \
		f34namedpkgs

all:	$(BUILD)

clean:
	/bin/rm -f $(BUILD) *.o lib*so.[0-9]* core a.out

usepkg1:	usepkg1.o libpkg1.so
	$(CC) -o usepkg1 usepkg1.o -L. -lpkg1

usepkg2:	usepkg2.o libpkg2.so
	$(CC) -o usepkg2 usepkg2.o -L. -lpkg2

f12pkg1:	f12pkg1.o f12.o bindsym.o
	$(CC) -o f12pkg1 f12pkg1.o f12.o bindsym.o -ldl

f12pkg2:	f12pkg2.o f12.o bindsym.o
	$(CC) -o f12pkg2 f12pkg2.o f12.o bindsym.o -ldl

f12bothpkgs:	f12bothpkgs.o f12.o bindsym.o
	$(CC) -o f12bothpkgs f12bothpkgs.o f12.o bindsym.o -ldl

f12namedpkgs:	f12namedpkgs.o f12.o bindsym.o
	$(CC) -o f12namedpkgs f12namedpkgs.o f12.o bindsym.o -ldl

f34namedpkgs:	f34namedpkgs.o f34.o bindsym.o
	$(CC) -o f34namedpkgs f34namedpkgs.o f34.o bindsym.o -ldl

bindsym.o:	bindsym.h bigstr.h
f12.o:		f12.h bindsym.h bigstr.h
f34.o:		f34.h bindsym.h bigstr.h

libpkg1.so:	pkg1.o
	$(CC) -shared -Wl,-soname,libpkg1.so -o libpkg1.so pkg1.o

libpkg2.so:	pkg2.o
	$(CC) -shared -Wl,-soname,libpkg2.so -o libpkg2.so pkg2.o

libpkg3.so:	pkg3.o
	$(CC) -shared -Wl,-soname,libpkg3.so -o libpkg3.so pkg3.o
