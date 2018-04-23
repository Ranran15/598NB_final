# COMPILER = g++
# COMPILER_OPTS = -DFOO -std=c++11 -lssl -lcrypto -ggdb3 -O2 -march=native -mtune=native -O2 -g -DNDEBUG -I/home/r/libsnark/. -I/home/r/libsnark/depends/libff -I/home/r/libsnark/depends/libfqfft -I/home/r/libsnark/depends/libff/libff/..
# #COMPILER_OPTS = -DFOO -std=c++11 -lssl -lcrypto -DCURVE_ALT_BN128 -DNO_PROCPS -ggdb -I/usr/local/include/libff -lsnark -lff -lgmp -lstdc++ -lprocps -lgmpxx
# #-I/install/path/include
# #-I/install/path/usr/local/include/libsnark

# LINKER_OPTS = -std=c++11  -ggdb3 -O2 -L/install/path/usr/local/lib -lsnark_adsnark
# #-lssl -lcrypto  -ggdb3 -O2 -march=native -mtune=native -O2 -g -DNDEBUG -I/home/r/libsnark/. -I/home/r/libsnark/depends/libff -I/home/r/libsnark/depends/libfqfft -I/home/r/libsnark/depends/libff/libff/..

# #-c -g -std=c++11 -lssl -lcrypto -DFOO -L/install/path/usr/local/lib -lsnark


# EXE = client

# OBJS = client.o

# all: $(EXE)

# $(EXE) : client.o
# 		$(COMPILER) client.o $(COMPILER_OPTS) -o $(EXE)

# client.o: client.cpp
# 		$(COMPILER) $(LINKER_OPTS) client.cpp

# clean:
# 	-rm -f *.o $(EXE)



OPTIONS = -std=c++11 -lssl -lcrypto -ggdb3 -O2 -march=native -mtune=native -O2 -g -DNDEBUG
INCLUDE = -I/install/path/usr/local/include -I/install/path/usr/local/include/libff -L/install/path/usr/local/lib

#INCLUDE = -I/install/path/usr/local/include -L/home/r/libsnark -libsnark -L/home/r/libff
LIBS    = -lsnark -libff -lsnark_adsnark 
#-lsnark_adsnark 
#-libff -libsnark
GCC			= g++

sha256: client.cpp
	$(GCC) $< -o $@ $(OPTIONS) $(INCLUDE) $(LIBS)