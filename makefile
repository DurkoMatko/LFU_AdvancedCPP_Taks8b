CC = g++
OBJECT_FILES = main.o LinkedList.o
CPPFLAGS = -std=c++11

default : all
all : Finds

Finds: $(OBJECT_FILES)
	g++ -o $@ main.o 


%.o: %.cpp
	$(CC) -c $(CPPFLAGS) $<


clean:
	rm Finds $(OBJECT_FILES)
