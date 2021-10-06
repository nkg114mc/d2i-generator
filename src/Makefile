# files

EXE = d2i-gen

OBJS = main.o bitwriter.o items.o complex_item.o item_const.o item_quality.o

# rules

all: $(EXE)

clean:
	$(RM) $(OBJS) .depend # keep exe

# general

CXX      = g++ # g++ if you must, but beware of NPS!
CXXFLAGS = -pthread
LDFLAGS  = -pthread

# warnings

CXXFLAGS += -ansi -pedantic -Wall -Wextra

# C++

CXXFLAGS += -std=c++11 -fno-rtti

# optimisation

#CXXFLAGS += -O2 -mpopcnt -mbmi2 -DBMI
CXXFLAGS += -O2 -mpopcnt
LDFLAGS  += -O2

#CXXFLAGS += -flto
#LDFLAGS  += -flto

CXXFLAGS += -g -DDEBUG

# dependencies

$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

.depend:
	$(CXX) $(CXXFLAGS) -MM $(OBJS:.o=.cpp) > $@

include .depend

