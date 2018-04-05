TIME = time.o
SONG = song.o
ALBUM = album.o
ML = music_library.o

all: main.exe

main.exe:	$(TIME) $(SONG) $(ALBUM) $(ML) music_main.cpp
	g++ -std=c++11 $(TIME) $(SONG) $(ALBUM) $(ML) music_main.cpp -o main.exe

time.o:	time.cpp time.h
	g++ -c time.cpp -std=c++11

song.o: song.cpp song.h
	g++ -c song.cpp -std=c++11

album.o: album.cpp album.h
	g++ -c album.cpp -std=c++11

music_library.o: music_library.cpp music_library.h
	g++ -c music_library.cpp -std=c++11

clean:
	rm *.o *.exe
