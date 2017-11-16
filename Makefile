CC = gcc
CFLAGS = -g --std=c99
PROG = ErrorTrace
SRC = src

.PHONY : all clean cleanall tests

#================== Make program =====================
all : $(PROG)

$(PROG) : main.o #$(SRC)/defines.h
	$(CC) $(CFLAGS) -o $(PROG) main.o

main.o : $(SRC)/main.c
	$(CC) $(CFLAGS) -c $(SRC)/main.c

#============= Clean and tests =========================
clean :
	-rm -f *.o
# -f prevents the displaying of "file not found" error

cleanall : clean
	-rm -f $(PROG)

tests :
	echo "Tests not yet implemented"
