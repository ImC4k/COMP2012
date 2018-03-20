// #include "stdafx.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
//function to read and store the contents of file to vector
void readFile(vector<string> *ab)
{
	string line;
	ifstream in("weblog.txt");//opening file for reading
	while (getline(in, line))//getting the one line from weblog
		(*ab).push_back(line);//push_back(line) used to store the line at the end of the vector
							  //(*ab).at(20);
	in.close();//closing file

}
//function to display last five lines
void dispLast5(vector<string> ab)
{
	for (int i = ab.size() - 5; i<ab.size(); i++)
		cout << ab.at(i) << endl;
}
//function to get the line when the line number is passed
string getLine(vector<string> ab, int n)
{
	return (ab.at(n - 1));
}
//function to reverse the weblog and write it ot a file
void reverseWrite(vector<string> ab)
{
	ofstream out("revweblog.txt");//opening the file in write mode
	for (int i = ab.size() - 1; i >= 0; i--)//looping the vector in reverse order
	{
		out << ab.at(i) << endl;//writing the line to a file
	}
	out.close();//closing the file

}
int main()
{
	vector<string> weblog;//declaring vector
	string line;
	readFile(&weblog);//calling readFile method
	dispLast5(weblog);//displaying the las five lines
	cout << getLine(weblog, 5);//displaying the 5th line
	reverseWrite(weblog);//calling function to reverse the vector and write to a file

}
