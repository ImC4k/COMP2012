// OiLamWong_CSAssignment3.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void readFile(vector <string> *ab, string fileName /* add one more parameter to receive file name for input*/)
{
	string line;
	ifstream in ("weblog.txt" /* change "weblog.txt" to "fileName" to allow flexibility*/);
	while (getline (in, line));
		(*ab).push_back(line);
	in.close();
}

void displayLast5(vector <string> ab)
{
	for (int i = ab.size() - 5; i < ab.size(); i++)
		cout << ab.at(i) << endl;
}

string getLine(vector <string> ab, int n)
{
	return (ab.at(n - 1));
}

void reverseWrite(vector <string> ab, string fileName /* add one more parameter to receive file name for output*/)
{
	ofstream out("reverseweblog.txt" /* change "reverseweblog.txt" to "fileName" to allow flexibility*/);
	for (int i = ab.size() - 1; i >= 0; i--)
	{
		out << ab.at(i) << endl;
	}
	out.close();
}

int main()
{
	vector <string> weblog;
	// add some code to recieve text file name
	/*
		cout<<"Please enter the name of text file: "<<endl;
		string fileName;
		cin>>filename;
	*/

	readFile(&weblog, filename/* add one more parameter to receive file name*/);
	displayLast5(weblog);
	cout << getLine(weblog, 5);

	// add some code to recieve text file namespace
	/*
		cout<<"Please input the file name that you want to output to: "<<endl;
		string outFileName;
		cin>>outFileName;
	*/
	reverseWrite(weblog, outFileName/* add one more parameter to receive file name*/);
}
