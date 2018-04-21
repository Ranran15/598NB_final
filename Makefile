COMPILER = g++
COMPILER_OPTS = -std=c++11

LINKER_OPTS = -c -g -Wall -std=c++11

EXE = client

OBJS = client.o

all: $(EXE)

$(EXE) : $(OBJS)
		$(COMPILER) $(OBJS) $(COMPILER_OPTS) -o $(EXE)

client.o: client.cpp
		$(COMPILER) $(LINKER_OPTS) client.cpp

clean:
	-rm -f *.o $(EXE)