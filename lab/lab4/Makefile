all: parta.exe partb.exe partc.exe

parta.exe: main_a.cpp Employee.o Consultant.o
	g++ -std=c++11 -o parta.exe main_a.cpp Employee.o Consultant.o

partb.exe: main_b.cpp EducationalConsultant.o Employee.o Consultant.o
	g++ -std=c++11 -o partb.exe main_b.cpp EducationalConsultant.o Employee.o Consultant.o

partc.exe: main_c.cpp EducationalConsultant.o Employee.o Consultant.o
	g++ -std=c++11 -o partc.exe main_c.cpp EducationalConsultant.o Employee.o Consultant.o

EducationalConsultant.o: EducationalConsultant.h EducationalConsultant.cpp
	g++ -c EducationalConsultant.cpp -std=c++11

Employee.o: Employee.cpp Employee.h
	g++ -c Employee.cpp -std=c++11

Consultant.o: Consultant.cpp Consultant.h
	g++ -c Consultant.cpp -std=c++11

clean:
	rm -f *.o *.exe
