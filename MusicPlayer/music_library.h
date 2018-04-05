#ifndef MUSIC_LIBRARY_H
#define MUSIC_LIBRARY_H

#include "album.h"

class MusicLibrary{
  string applicationName;
  int userID;
  int numAlbums;
  Album** albums; // stores albums using dynamic array

public:
  MusicLibrary(string applicationName = "", int userID = 0);
  MusicLibrary(const MusicLibrary& another);
  ~MusicLibrary();

  const MusicLibrary& operator=(const MusicLibrary& another);
  const Album* operator[](int index);
  MusicLibrary& operator+(Song* song); // add to an album if album name is defined, don't add the song if song already existed
  MusicLibrary& operator+(Album* album); // add the album to music library, don't add the album if album already existed

  string getApplicationName();
  int getUserID();
  int getNumAlbums();
  int getNumSongs();
  Time getTotalDuration(); // return total duration of entire music library
  Album* getAlbum(int index);

  void setApplicationName(string applicationName);
  void setUserID(int userID);
};

#endif
