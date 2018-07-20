#author: K

CC = g++
TARGET = chain
OBJS = Block.o Blockchain.o sha256.o main.o

$(TARGET):$(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lcrypto
Block.o:Block.cpp
	$(CC) -std=c++11 -c Block.cpp -o Block.o
Blockchain.o:Blockchain.cpp
	$(CC) -std=c++11 -c Blockchain.cpp -o Blockchain.o
sha256.o:sha256.cpp
	$(CC) -std=c++11 -c sha256.cpp -o sha256.o -lcrypto
main.o:main.cpp
	$(CC) -std=c++11 -c main.cpp -o main.o
   
.PHONY: clean
clean:
	-rm -f $(TARGET) $(OBJS)
