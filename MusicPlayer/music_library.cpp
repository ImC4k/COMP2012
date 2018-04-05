#include "music_library.h"

MusicLibrary::MusicLibrary(string applicationName, int userID): applicationName(applicationName), userID(userID){}

MusicLibrary::MusicLibrary(const MusicLibrary& another){
  *this = another;
}

MusicLibrary::~MusicLibrary(){
  for(int i = 0; i < numAlbums; i++){
    delete albums[i];
  }
  delete[] albums;
}

const MusicLibrary& MusicLibrary::operator=(const MusicLibrary& another){
  if(this != &another){
    this->applicationName = another.applicationName;
    this->userID = another.userID;
    this->numAlbums = another.numAlbums;
    delete[] this->albums;
    this->albums = new Album*[numAlbums];
    for(int i = 0; i < numAlbums; i++){
      this->albums[i] = another.albums[i];
    }
  }
  return *this;
}

const Album* MusicLibrary::operator[](int index){
  return this->getAlbum(index);
}

MusicLibrary& MusicLibrary::operator+(Song* song){
  if(song == nullptr){return *this;}
  string albumName = song->getAlbumName();
  for(int i = 0; i < numAlbums; i++){
    if(albums[i]->getAlbumName() == albumName){
      Album* album = albums[i];
      for(int j = 0; j < albums[i]->getNumSongs(); j++){
        if(album->getSong(j)->getName() == song->getName()){
          return *this;
        }
      }
      *albums[i]+song;
    }
  }
  // XXX will this cause memory leak?
  Album* newAlbum = new Album(song->getAlbumName(), song->getArtist());
  *newAlbum+song;
  *this+newAlbum;
  return *this;
}

MusicLibrary& MusicLibrary::operator+(Album* album){
  if(album == nullptr){return *this;}
  for(int i = 0; i < numAlbums; i++){
    if(*albums[i] == *album || albums[i] == album){
      return *this;
    }
  }
  Album** newArray = new Album*[++numAlbums];
  for(int i = 0; i < numAlbums - 1; i++){
    newArray[i] = albums[i];
  }
  newArray[numAlbums - 1] = album;
  return *this;
}

string MusicLibrary::getApplicationName(){return applicationName;}

int MusicLibrary::getUserID(){return userID;}

int MusicLibrary::getNumAlbums(){return numAlbums;}

int MusicLibrary::getNumSongs(){
  int totalSongs = 0;
  for(int i = 0; i < numAlbums; i++){
    totalSongs += albums[i]->getNumSongs();
  }
  return totalSongs;
}

Time MusicLibrary::getTotalDuration(){
  int hh = 0, mm = 0, ss = 0;

  for(int i = 0; i < numAlbums; i++){
    hh += albums[i]->getTotalDuration().getHour();
    mm += albums[i]->getTotalDuration().getMinute();
    ss += albums[i]->getTotalDuration().getSecond();
    if(ss >= 60){
      mm += 1;
      ss -= 60;
    }
    if(mm >= 60){
      hh += 1;
      mm -= 60;
    }
  }
  return Time(hh, mm, ss);
}

Album* MusicLibrary::getAlbum(int index){
  return albums[index];
}

void MusicLibrary::setApplicationName(string applicationName){
  this->applicationName = applicationName;
}

void MusicLibrary::setUserID(int userID){
  this->userID = userID;
}
