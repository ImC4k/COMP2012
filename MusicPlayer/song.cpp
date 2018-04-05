#include "song.h"

Song::Song(string name, string albumName, string artist, Time duration): name(name), albumName(albumName), artist(artist), duration(duration){}

Song::Song(string name, string albumName, string artist, int hh, int mm, int ss): name(name), albumName(albumName), artist(artist), duration(Time(hh, mm, ss)){}

Song::Song(const Song& another){
  *this = another;
}

const Song& Song::operator=(const Song& another){
  if(this != &another){
    this->name = another.name;
    this->albumName = another.albumName;
    this->artist = another.artist;
    this->duration = another.duration;
  }
  return *this;
}

bool Song::operator==(const Song& another){
  if((this->name == another.name) && (this->albumName == another.albumName) && (this->artist == another.artist)){
    return true;
  }
  return false;
}

string Song::getName(){return name;}

string Song::getAlbumName(){return albumName;}

string Song::getArtist(){return artist;}

Time Song::getDuration(){return duration;}

void Song::setName(string name){
  this->name = name;
}

void Song::setAlbumName(string albumName){
  this->albumName = albumName;
}

void Song::setArtist(string artist){
  this->artist = artist;
}

void Song::setDuration(Time duration){
  this->duration = duration;
}

void Song::setDuration(int hh, int mm, int ss){
  this->duration = Time(hh, mm, ss);
}
