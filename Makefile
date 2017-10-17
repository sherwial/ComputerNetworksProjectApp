CC=g++

BINARY=netweb

INCLUDES=
INCLUDES+=./utils

CXXFLAGS=
CXXFLAGS+=-std=c++11
CXXFLAGS+=-Wall
CXXFLAGS+=-pedantic

CXXFLAGS+=$(foreach i, $(INCLUDES), -I$i)

SOURCE=
SOURCE+=./main.cpp
SOURCE+=./utils/TcpServer.cpp

all: $(BINARY)

$(BINARY):
	$(CC) $(CXXFLAGS) $(SOURCE) -o $(BINARY)

clean:
	rm -rf *.o *.a $(BINARY)
