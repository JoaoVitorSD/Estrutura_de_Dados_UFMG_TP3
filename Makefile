CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/tp.o
HDRS = 
CFLAGS = -Wall -c -I$(INC)
INP = input

EXE = $(BIN)/tp.exe
all: $(EXE)
		$(EXE) < entrada.txt > $(SRC)/saida.txt;
$(BIN)/tp.exe: $(OBJS)
	$(CC) -pg -o $(BIN)/tp.exe $(OBJS) $(LIBS)
$(OBJ)/tp.o: $(HDRS) $(SRC)/tp.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tp.o $(SRC)/tp.cpp
compare:
	for number in 1 2 3 4; do \
	$(EXE) < input/entrada_$$number.txt > $(SRC)/saida.txt; \
	diff --color $(SRC)/saida.txt output/saida_$$number.txt; \
	done