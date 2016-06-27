SRC_DIR=src/
FLAGS=-Wall -O2
CPP=g++
all:
	$(CPP) $(SRC_DIR)*.cpp -o ServiceCenterSimulator $(FLAGS)

clean:
	rm ServiceCenterSimulator
