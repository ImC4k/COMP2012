#include <iostream>

#include "folder.h"

using namespace std;

Folder::Folder(unsigned int size)
{
	maxSize = size;
	currSize = 0;
	files = new const File*[size];
}

Folder::~Folder()
{
	delete[] files;
}

Folder::Folder(const Folder &folder)
{
	this->maxSize = folder.maxSize;
	this->files = new const File*[maxSize];

	for(int i = 0; i < folder.currSize; i++){ // is this kind of shallow copy?
		this->addFile(*folder.files[i]);
	}
}

void Folder::addFile(const File &file)
{
	if(maxSize == currSize){ // if folder is full
		cout<<"Insufficient space for folder"<<endl;
		return;
	}
	if(contains(file)){ // if folder contains the file already
		cout<<"File already exists in folder"<<endl;
		return;
	}

	files[currSize] = &file;
	currSize++;
	cout<<"added a file"<<endl; // DEBUG
}

bool Folder::contains(const File &file) const
{
	for(int i = 0; i < currSize; i++){
		if(file.equals(*files[i])){
			return true;
		}
	}
	return false;
}

void Folder::print() const
{
	for(int i = 0; i < currSize; i++){
		files[i]->print();
	}
}
