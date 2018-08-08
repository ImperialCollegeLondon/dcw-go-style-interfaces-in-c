CC	=	gcc
CFLAGS	=	-Wall -fPIC
BUILD	=	f12.c f12.h pkg1.c pkg2.c pkg3.c \
		libpkg1.so libpkg2.so libpkg3.so f12namedpkgs \
		f34.c f34.h f34namedpkgs

all:	$(BUILD)

clean:
	/bin/rm -f $(BUILD) *.o lib*so.[0-9]* core a.out

f12namedpkgs:	f12namedpkgs.o f12.o bindsym.o
	$(CC) -o f12namedpkgs f12namedpkgs.o f12.o bindsym.o -ldl

bindsym.o:	bindsym.h bigstr.h
f12.o:		f12.h bindsym.h bigstr.h

f12.h f12.c:	f12.interface
	../cint f12.interface

f34.o:		f34.h bindsym.h bigstr.h

f34.h f34.c:	f34.interface
	../cint f34.interface

f34namedpkgs:	f34namedpkgs.o f34.o bindsym.o
	$(CC) -o f34namedpkgs f34namedpkgs.o f34.o bindsym.o -ldl

pkg1.c:	pkg1.pkg
	../cpkg pkg1.pkg

libpkg1.so:	pkg1.o
	$(CC) -shared -Wl,-soname,libpkg1.so -o libpkg1.so pkg1.o
	rm -f libpkg1.so.1

pkg2.c:	pkg2.pkg
	../cpkg pkg2.pkg

libpkg2.so:	pkg2.o
	$(CC) -shared -Wl,-soname,libpkg2.so -o libpkg2.so pkg2.o
	rm -f libpkg2.so.1

pkg3.c:	pkg3.pkg
	../cpkg pkg3.pkg

libpkg3.so:	pkg3.o
	$(CC) -shared -Wl,-soname,libpkg3.so -o libpkg3.so pkg3.o
	rm -f libpkg3.so.1
