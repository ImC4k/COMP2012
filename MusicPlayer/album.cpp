#include "album.h"

Album::Album(string albumName, string artist): albumName(albumName), artist(artist), numSongs(0), songs(nullptr){}

Album::Album(const Album& another){
  *this = another;
}

Album::~Album(){
  delete[] songs;
}

const Album& Album::operator=(const Album& another){
  if( this != &another){ // check self-assignment!
    this->albumName = another.albumName;
    this->artist = another.artist;
    this->numSongs = another.numSongs;
    delete[] this->songs; // deallocate original songs dynamic array first
    this->songs = new Song*[numSongs];
    for(int i = 0; i < numSongs; i++){
      this->songs[i] = another.songs[i];
    }
  }
  return *this;
}

Album& Album::operator+(Song* newSong){
  if(newSong == nullptr){return *this;}
  for(int i = 0; i < numSongs; i++){ // no need to add newSong if album already has this song
    if(songs[i] == newSong){
      return *this;
    }
  }
  Song** newArray = new Song*[++numSongs];
  for(int i = 0; i < numSongs - 1; i++){
    newArray[i] = songs[i];
  }
  newArray[numSongs - 1] = newSong;
  delete[] songs;
  songs = newArray;
  return *this;
}

Song* Album::operator[](int index){
  return this->getSong(index);
}

bool Album::operator==(const Album& another){
  if((this->albumName == another.albumName) && (this->artist == another.artist) && (this->numSongs == another.numSongs)){
    return true;
  }
  return false;
}

string Album::getAlbumName(){return albumName;}

string Album::getArtist(){return artist;}

int Album::getNumSongs(){return numSongs;}

Song* Album::getSong(int index){
  return songs[index];
}

Time Album::getTotalDuration(){
  int hh = 0, mm = 0, ss = 0;

  for(int i = 0; i < numSongs; i++){
    hh += songs[i]->getDuration().getHour();
    mm += songs[i]->getDuration().getMinute();
    ss += songs[i]->getDuration().getSecond();
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

void Album::setAlbumName(string albumName){
  this->albumName = albumName;
}

void Album::setArtist(string artist){
  this->artist = artist;
}

void Album::setSong(Song* song, int index){
  songs[index] = song;
}

void Album::print_album_info(){
  cout<<"Album name: "<<albumName<<endl;
  cout<<"Artist name: "<<artist<<endl;
  cout<<numSongs<<" songs in total, ";
  cout<<"duration is ";
  getTotalDuration().print_time();
  cout<<endl;
}

void Album::print_songs(){
  for(int i = 0; i < numSongs; i++){
    cout<<songs[i]->getName()<<endl;
  }
}

void Album::print(){
  print_album_info();
  cout<<endl<<"Songs include: "<<endl;
  print_songs();
}
