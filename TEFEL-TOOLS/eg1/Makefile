CC	=	gcc
CFLAGS	=	-Wall -fPIC
BUILD	=	f12.c f12.h pkg1.c libpkg1.so f12pkg1

all:	$(BUILD)

clean:
	/bin/rm -f $(BUILD) *.o lib*so.[0-9]* core a.out

f12pkg1:	f12pkg1.o f12.o bindsym.o
	$(CC) -o f12pkg1 f12pkg1.o f12.o bindsym.o -ldl

bindsym.o:	bindsym.h bigstr.h
f12.o:		f12.h bindsym.h bigstr.h

f12.h f12.c:	f12.interface
	../cint f12.interface

pkg1.c:	pkg1.pkg
	../cpkg pkg1.pkg

libpkg1.so:	pkg1.o
	$(CC) -shared -Wl,-soname,libpkg1.so -o libpkg1.so pkg1.o
