CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/tp.o  $(OBJ)/message.o $(OBJ)/player.o $(OBJ)/cell.o
HDRS = $(INC)/cell.h $(INC)/message.h $(INC)/player.h 
CFLAGS = -Wall -c -I$(INC)
INP = input

EXE = $(BIN)/tp.exe
all: $(EXE)
		$(EXE) < entrada.txt > $(SRC)/saida.txt;
$(BIN)/tp.exe: $(OBJS)
	$(CC) -pg -o $(BIN)/tp.exe $(OBJS) $(LIBS)
$(OBJ)/tp.o: $(HDRS) $(SRC)/tp.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tp.o $(SRC)/tp.cpp
$(OBJ)/cell.o: $(HDRS) $(SRC)/cell.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/cell.o $(SRC)/cell.cpp
$(OBJ)/message.o: $(HDRS) $(SRC)/message.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/message.o $(SRC)/message.cpp
$(OBJ)/player.o: $(HDRS) $(SRC)/player.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/player.o $(SRC)/player.cpp
compare:
	for number in 1 2 3 4; do \
	$(EXE) < input/entrada_$$number.txt > $(SRC)/saida.txt; \
	diff --color $(SRC)/saida.txt output/saida_$$number.txt; \
	done