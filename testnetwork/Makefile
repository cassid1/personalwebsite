OPTS = -Wall -g -std=c++11
CC = g++

connect4driver: connect4driver.o 
	$(CC) $(OPTS) -o connect4driver connect4driver.o net_fun.o Neural_net.o connect4.o -lm

connect4driver.o: connect4.o connect4driver.cpp
	$(CC) $(OPTS) -c connect4driver.cpp

connect4.o: Neural_net.o connect4.cpp connect4.h
	$(CC) $(OPTS) -c connect4.cpp

Neural_net.o: net_fun.o Neural_net.h Neural_net.cpp
	$(CC) $(OPTS) -c Neural_net.cpp

net_fun.o: net_fun.h net_fun.cpp
	$(CC) $(OPTS) -c net_fun.cpp
	