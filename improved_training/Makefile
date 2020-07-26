OPTS = -Wall -g -std=c++11
CC = g++

NNtraining: NNtraining.o 
	$(CC) $(OPTS) -o NNtraining NNtraining.o net_fun.o Neural_net.o connect4.o -lm -fopenmp

NNtraining.o: connect4.o NNtraining.cpp
	$(CC) $(OPTS) -c NNtraining.cpp -fopenmp

connect4.o: Neural_net.o connect4.cpp connect4.h
	$(CC) $(OPTS) -c connect4.cpp -fopenmp

Neural_net.o: net_fun.o Neural_net.h Neural_net.cpp
	$(CC) $(OPTS) -c Neural_net.cpp -fopenmp

net_fun.o: net_fun.h net_fun.cpp
	$(CC) $(OPTS) -c net_fun.cpp -fopenmp