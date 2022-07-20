CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/tp.o $(OBJ)/hash.o $(OBJ)/email.o $(OBJ)/node.o $(OBJ)/tree.o 
HDRS =  $(INC)/email.h $(INC)/hash.h $(INC)/node.h $(INC)/tree.h 
CFLAGS = -g -Wall -c -I$(INC)
INP = input

EXE = $(BIN)/tp.exe
all: $(EXE)
		
$(BIN)/tp.exe: $(OBJS)
	$(CC) -pg -o $(BIN)/tp.exe $(OBJS) $(LIBS)
$(OBJ)/tp.o: $(HDRS) $(SRC)/tp.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tp.o $(SRC)/tp.cpp
$(OBJ)/email.o: $(HDRS) $(SRC)/email.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/email.o $(SRC)/email.cpp
$(OBJ)/node.o: $(HDRS) $(SRC)/node.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/node.o $(SRC)/node.cpp
$(OBJ)/tree.o: $(HDRS) $(SRC)/tree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tree.o $(SRC)/tree.cpp
$(OBJ)/hash.o: $(HDRS) $(SRC)/hash.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/hash.o $(SRC)/hash.cpp
compare:
	for number in 1 2 3 4 5 6 7 8; do \
	$(EXE) < input/entrada_$$number.txt > $(SRC)/saida.txt; \
	echo "comparing $$number"; \
	diff --color $(SRC)/saida.txt output/saida_$$number.txt; \
	done