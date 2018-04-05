#ifndef ALBUM_H
#define ALBUM_H

#include "song.h"

// This class is Album, storing a number of songs
// Will also have data members called albumName and artist also
// also a Time data member storing total during of the album

class Album{
  string albumName;
  string artist;
  int numSongs;
  Song** songs; // dynamic array pointing to number of songs in the album

public:
  Album(string albumName = "", string artist = "");
  Album(const Album& another);
  ~Album();

  const Album& operator=(const Album& another); // returned item should not be changed
  Album& operator+(Song* newSong); // always add song to the last of songs array
  Song* operator[](int index); // returned item should not be changed
  bool operator==(const Album& another); // equality operator only checks equality of attributes, won't check song by song

  string getAlbumName();
  string getArtist();
  int getNumSongs();
  Song* getSong(int index); // returned item should not be changed
  Time getTotalDuration();

  void setAlbumName(string albumName);
  void setArtist(string artist);
  void setSong(Song* song, int index);

  void print_album_info();
  void print_songs();
  void print();

};

#endif
