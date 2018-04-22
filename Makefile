COMPILER = g++
COMPILER_OPTS = -std=c++11 -lssl -lcrypto

LINKER_OPTS = -c -g -std=c++11 -lssl -lcrypto

EXE = client

OBJS = client.o

all: $(EXE)

$(EXE) : $(OBJS)
		$(COMPILER) $(OBJS) $(COMPILER_OPTS) -o $(EXE)

client.o: client.cpp
		$(COMPILER) $(LINKER_OPTS) client.cpp

clean:
	-rm -f *.o $(EXE)