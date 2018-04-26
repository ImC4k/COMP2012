#ifndef FILE_H
#define FILE_H

class File
{
public:
	File(); // default constructor
	~File(); // destructor
	File(const File &file); // copy constructor
	File(const char *name); // conversion constuctor

	bool equals(const File &file) const;
	void print() const;

private:
	char *name;
};

#endif
