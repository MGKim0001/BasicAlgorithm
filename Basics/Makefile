text : main.o
	g++ -g main.o -o test

main.o : queue.hpp stack.hpp object.hpp
	g++ -c -g main.cpp

clean:
	rm main.o test
