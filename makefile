client: Common.o client.o
	g++ Common.o client.o -o client

Common.o: Common.cpp
	g++ -c Common.cpp

client.o: client.cpp
	g++ -c client.cpp
	