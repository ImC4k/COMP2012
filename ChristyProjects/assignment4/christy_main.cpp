#include <iostream>
#include <string>

using namespace std;

class GreetingCard
{
private:
  string Recipient;
  string Sender;
  string Message;
  string Occasion;
  int Card1;
  int Card2;

public:
  void setRecipient(string w) {
    Recipient = w;
  }
  string getRecipient() {
    return Recipient;
  }

  void setSender(string x) {
    Sender = x;
  }
  string getSender() {
    return Sender;
  }

  void setMessage(string y) {
    Message = y;
  }
  string getMessage() {
    return Message;
  }

  void setOccasion(string z) {
    Occasion = z;
  }
  string getOccasion() {
    return Occasion;
  }
  void setValue(int a) {
    Value = a;
  }
  string getValue() {
    return Value;
  }
};

void Card1::Display_Data(string w, string x, string y, string z, int a){
  cout << " Dear " << w << endl;
  cout << " From " << x << endl;
  cout << " All the best to you and your family." << y << endl;
  cout << " Happy Easter! " << z << endl;
}

void Card2::Display_Data(string w, string x, string y, string z, int a) {
  cout << " Dear " << w << endl;
  cout << " From " << x << endl;
  cout << " All the best to you and your family." << y << endl;
  cout << " Merry Christmas!" << z << endl;
}
int main()
{
  string Recipient;
  string Sender;
  string Message;
  string Occasion;
  int Value;
  cout << "Please enter the name of the recipient:";
  cin >> Recipient;
  cout << "Please enter the name of the sender:";
  cin >> Sender;
  cout << "Please enter the message:";
  cin >> Message;
  cout << "Please enter the occasion:";
  cin >> Occasion;
  return 0;
}
