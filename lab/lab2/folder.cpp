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

Folder::Folder(const Folder &folder) // BUG
{
	this->maxSize = folder.maxSize;
	this->files = new const File*[maxSize];
	// for(int i = 0; i < currSize; i++){
	// 	File newFile(*folder.files[i]);
	// 	files[i] = &newFile;
	// }
	for(int i = 0; i < folder.currSize; i++){
		this->addFile(*folder.files[i]);
	}
}

void Folder::addFile(const File &file) // cout<<"Insufficient space for folder"<<endl; if cannot add file
{
	if(maxSize == currSize){ // if folder is full
		cout<<"Insufficient space for folder"<<endl;
		return;
	}
	if(contains(file)){
		cout<<"File already exists in folder"<<endl;
		return;
	}

	files[currSize] = &file;
	currSize++;
}

bool Folder::contains(const File &file) const
{
	for(int i = 0; i < currSize; i++){
		if(file.equals(*files[i])){
			return true;
		}
	}
	return false; // Dummy statement. You need to update it with your own code.
}

void Folder::print() const
{
	for(int i = 0; i < currSize; i++){
		files[i]->print();
	}
}
