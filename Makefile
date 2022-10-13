.PHONY : build lua test clean

default :
	@echo "======================================="
	@echo "Please use 'make build' command to build it.."
	@echo "Please use 'make lua' command to build lua C API.."
	@echo "======================================="

CC = cc

LIB += -llua
git 
MICRO += -std=c99 -Wall -Wl,-rpath,./ -I. -I/usr/local/include -L. -L/usr/local/lib 

WARNING += -Wall -Wno-unused-variable -Wno-unused-function

build :

	$(CC) -o xtea.so xtea.c -O3 -fPIC --shared -std=c99 -Wall

lua :

	$(CC) -o xtea.so lua-xtea.c xtea.c -O3 -fPIC --shared $(MICRO) $(LIB)

clean :
	rm -rf xtea.so