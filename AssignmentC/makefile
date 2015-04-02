main: 
	mpicxx main.cpp -o main.out

generate: generate.o
	g++ generate.o -o generate.out

generate.o: testDataGenerator.cpp
	g++ -c testDataGenerator.cpp -o generate.o

clean:
	-rm -f main.out
	-rm -f *.o
	-rm -f generate.out
