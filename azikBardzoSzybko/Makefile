APP=sterowanie-lazikiem
GXX := g++
GXX_FLAGS 	:= -std=c++17 -W -Wall -pedantic -g3


SRC := $(wildcard src/*.cpp)
INCLUDE := inc/


all: $(SRC)
	$(GXX) $^ $(GXX_FLAGS) -I$(INCLUDE) -o $(APP)
