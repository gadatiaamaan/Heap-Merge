merge: main.o
	g++ -std=c++11 main.o -o merge
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
clean:
	rm -f merge
	rm -f *.o
run: merge
	./merge
