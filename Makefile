CC = g++
LFLAGS=
CFLAGS=-c -Wall -std=c++11 -O2
OBJS = verify_full.o create_full.o solve_brute.o MAIN.o
EXE=MAIN

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LFLAGS)

MAIN.o: MAIN.cpp verify_full.h create_full.h solve_brute.h
	$(CC) MAIN.cpp -o MAIN.o $(CFLAGS)

verify_full.o: verify_full.cpp verify_full.h
	$(CC) verify_full.cpp -o verify_full.o $(CFLAGS)

create_full.o: create_full.cpp create_full.h
	$(CC) create_full.cpp -o create_full.o $(CFLAGS)

solve_brute.o: solve_brute.cpp solve_brute.h
	$(CC) solve_brute.cpp -o solve_brute.o $(CFLAGS)




clean:
	@rm $(OBJS) $(EXE)
