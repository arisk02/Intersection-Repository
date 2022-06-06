EXECS = simulation
OBJS = simulation.o Animator.o VehicleBase.o ConfigParser.o

#### use next two lines for Mac
#CC = clang++
#CCFLAGS = -std=gnu++2a -stdlib=libc++

#### use next two lines for linux machines:
CC = g++
CCFLAGS = -std=c++17

all: $(EXECS)

simulation: $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

ConfigParser.o: ConfigParser.cpp ConfigParser.h
	$(CC) $(CCFLAGS) -c $<

VehicleBase.o: VehicleBase.cpp VehicleBase.h ConfigParser.cpp ConfigParser.h
	$(CC) $(CCFLAGS) -c $<

Animator.o: Animator.cpp Animator.h
	$(CC) $(CCFLAGS) -c $<

simulation.o: simulation.cpp ConfigParser.cpp ConfigParser.h
	$(CC) $(CCFLAGS) -c $<

clean:
	/bin/rm -f a.out $(OBJS) $(EXECS)
