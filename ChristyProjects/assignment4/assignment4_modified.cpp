// ConsoleApplication8.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class GreetingCard
{
private:
	int Number;
	string Recipient;
	string Occasion;
	string Message;
	string Sender;

public:
     void setNumber(int a) {
		Number = a;
	}
	int getNumber() {
		return Number;
	}
	void setRecipient(string w) {
		Recipient = w;
	}
	string getRecipient() {
		return Recipient;
	}
	void setOccasion(string y) {
		Occasion = y;
	}
	string getOccasion() {
		return Occasion;
	}

	void setMessage(string x) {
		Message = x;
	}
	string getMessage() {
		return Message;
	}
	void setSender(string z) {
		Sender = z;
	}
	string getSender() {
		return Sender;
	}

	GreetingCard() {
		// because you want to initialize object using this default constructor,
		// then it should try to initialize all its data members
		// here I added two lines of code, setting card ID to be -1, and all strings as "" (which is nothing)
		// earlier I said this Constructor can have nothing inside, that holds true
		// but when you try to access data members of an object initialized by default Constructor,
		// then you will see some strange stuff like random ID number will be assigned.
		// So, it's best that you take control of what the ID number should be, by assigning those variables yourself, instead of by the compiler

		/*
		Number = -1;
		Recipient = Occasion = Message = Sender = "";
		*/
	}
	GreetingCard(int a, string w, string x, string y, string z) {
		Number = a;
		Recipient = w;
		Occasion = x;
		Message = y;
		Sender = z;
	}


	void Display_Data() {
		cout << "Card ID: " << Number << endl;
		cout << "Dear " << Recipient << endl;
		cout << "Happy " << Occasion << endl;
		cout << "Message: " << Message << endl;
		cout << "Best, " << Sender << endl;
	}

};
int main()
{
	int Number;
    string Recipient;
	string Occasion;
	string Message;
	string Sender;
	cout << "Please enter the number of the card:";
	cin >> Number;
	cout << "Please enter the name of the recipient:";
	cin >> Recipient;
	cout << "Please enter the occasion:";
	cin >> Occasion;
	cout << "Please enter the message:";
	cin >> Message;
	cout << "Please enter the name of the sender:";
	cin >> Sender;

	GreetingCard my( Number, Recipient, Occasion, Message, Sender);
	cout << endl <<  "'my' object" << endl;
	my.Display_Data();

	my.Display_Data();
	cout << "my message: " << my.getMessage() << endl;
	GreetingCard other;
	cout << endl << "'other' object" << endl;
	other.Display_Data();
	cout << endl << "'changing other' object" << endl;
	other.setMessage("Hello");
	other.Display_Data();

	// this two lines of code should be deleted
	cin >> Occasion;
	cin >> Occasion;

    return 0;
}
