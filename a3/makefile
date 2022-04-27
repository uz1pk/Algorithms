#Usman Zaheer
#CIS 3490

CC = gcc
FLAGS = -Wall -std=c11

BIN = bin/

all: $(BIN)main.o $(BIN)P11.o $(BIN)P12.o $(BIN)P21.o $(BIN)P22.o $(BIN)P23.o
	$(CC) $(FLAGS) $(BIN)main.o $(BIN)P11.o $(BIN)P12.o $(BIN)P21.o $(BIN)P22.o $(BIN)P23.o -lm -o a3

$(BIN)main.o: main.c P11.c P12.c P21.c P22.c
	$(CC) $(FLAGS) -c main.c -o $(BIN)main.o

$(BIN)P11.o: P11.c
	$(CC) $(FLAGS) -c P11.c -o $(BIN)P11.o

$(BIN)P12.o: P12.c
	$(CC) $(FLAGS) -c P12.c -o $(BIN)P12.o

$(BIN)P21.o: P21.c
	$(CC) $(FLAGS) -c P21.c -o $(BIN)P21.o

$(BIN)P22.o: P22.c
	$(CC) $(FLAGS) -c P22.c -o $(BIN)P22.o

$(BIN)P23.o: P23.c
	$(CC) $(FLAGS) -c P23.c -o $(BIN)P23.o

clean:
	rm -rf $(BIN)*.o a3