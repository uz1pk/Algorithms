#Usman Zaheer
#CIS 3490

CC = gcc
FLAGS = -Wall -std=c11

BIN = bin/
INC = include/
SRC = src/

all: p11 p12 p2

p11: $(BIN)p11.o $(BIN)helper.o
	$(CC) $(FLAGS) -Wall $(BIN)p11.o $(BIN)helper.o -o p11

p12: $(BIN)p12.o $(BIN)helper.o
	$(CC) $(FLAGS) -Wall $(BIN)p12.o $(BIN)helper.o -o p12

p2: $(BIN)p2.o $(BIN)helper.o
	$(CC) $(FLAGS) -Wall $(BIN)p2.o $(BIN)helper.o -o p2

$(BIN)p11.o: $(SRC)p11.c $(INC)a4.h
	$(CC) $(FLAGS) -I$(INC) -c -fpic $< -o $@

$(BIN)p12.o: $(SRC)p12.c $(SRC)helper.c $(INC)a4.h
	$(CC) $(FLAGS) -I$(INC) -c -fpic $< -o $@

$(BIN)p2.o: $(SRC)p2.c $(SRC)helper.c $(INC)a4.h
	$(CC) $(FLAGS) -I$(INC) -c -fpic $< -o $@

$(BIN)helper.o: $(SRC)helper.c $(INC)a4.h
	$(CC) $(FLAGS) -I$(INC) -c -fpic $< -o $@

clean: 
	rm $(BIN)*.o p11 p12 p2
