merge: main.o
	g++ main.o -o merge
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -f merge
	rm -f *.o
run: merge
	./merge
