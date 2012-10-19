# source files.

SRC = $(wildcard src/*.cpp)

OBJ = $(patsubst src%, ../buildtemp%.o, $(SRC))

OUT = bin/Rcom

# include directories
INCLUDES = -I. -I./include/ -I/usr/local/include

# C++ compiler flags (-g -O2 -Wall)
CCFLAGS = -g

# compiler
CCC = g++

# compile flags
LDFLAGS = -g

.SUFFIXES: .cpp

default: $(OUT)

../buildtemp/%.o: src/%
	mkdir -p ../buildtemp
	$(CCC) $(INCLUDES) $(CCFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	mkdir -p bin
	$(CCC) $(INCLUDES) $(CCFLAGS) $(OBJ) $(LIBS) -o $(OUT)

clean:
	rm -f $(OBJ) $(OUT)

test:
	echo $(SRC)
	echo $(OBJ)
