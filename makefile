all: client server

server: server.o
	g++ -std=c++14 -o server server.cpp -lpthread

client: client.o
	g++ -std=c++14 -o client client.cpp -lpthread

server.o: server.cpp
	g++ -c server.cpp


client.o: client.cpp
	g++ -c client.cpp

