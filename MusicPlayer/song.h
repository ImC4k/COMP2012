#ifndef SONG_H
#define SONG_H

#include "time.h"

class Song{
  string name;
  string albumName;
  string artist;
  Time duration;

public:
  Song() = default;
  Song(string name, string albumName, string artist, Time duration);
  Song(string name, string albumName, string artist, int hh, int mm, int ss);
  Song(const Song& another);

  const Song& operator=(const Song& another);
  bool operator==(const Song& another);

  string getName();
  string getAlbumName();
  string getArtist();
  Time getDuration(); // return by reference

  void setName(string name);
  void setAlbumName(string albumName);
  void setArtist(string artist);
  void setDuration(Time duration);
  void setDuration(int hh, int mm, int ss);

};

#endif
