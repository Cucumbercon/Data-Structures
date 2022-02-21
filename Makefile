CC = g++
LFLAGS = -Wall -pedantic-errors
CCFLAGS = $(LFLAGS) -c


compile: main.o Instructor.o Student.o
	$(CC) $(LFLAGS) -o main main.o Instructor.o Student.o

main.o: main.cpp Student.h
	$(CC) $(CCFLAGS) main.cpp

Student.o: Student.cpp Student.h
		$(CC) $(CCFLAGS) Student.cpp

Instructor.o: Instructor.cpp Student.h Instructor.h
		$(CC) $(CCFLAGS) Instructor.cpp
run: compile
		./main instructors.txt students.txt

clean:
	rm -f main
	rm -f *.o
