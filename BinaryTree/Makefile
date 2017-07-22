text : main.o
	g++ -g main.o -o test

main.o : binarytree.hpp node.hpp
	g++ -c -g main.cpp

clean:
	rm main.o test
