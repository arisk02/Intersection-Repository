# Intersection-Repository

This is an intersection simulation that takes an input file with 18 parameters like the probability
of a car being spawned, probability of it turning left or right, it being a car, an SUV or a truck
and etc. It also provides the length of each of the traffic lights as well as the maximum time of
the simulation. The simulation at its present state does not have left turns implemented, but right
turns are. After running the simulation, in order to progress it you just have to hit return, and it
will go up by 1 unit of time (tick). 

Compiling:
make simulation

Running the simulation:
./simulation <filePath> <seed>
where seed is a three digit integer used. Every integer will make for a unique simulation.
