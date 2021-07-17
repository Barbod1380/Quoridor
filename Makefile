Wall: Wall1.o Wall2.o
	g++ Wall1.o Wall2.o -o Wall 

Wall1.o: Wall1.cpp
	g++ -c Wall1.cpp

Wall2.o: Wall2.cpp
	g++ -c Wall2.cpp
	