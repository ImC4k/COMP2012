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
  int cardNum;

public:

  GreetingCard(string Recipient = "---Unknown---", string Sender = "---Unknown---", string Message = "---Unknown---", string Occasion = "---Unknown---", int num = -1): Recipient(Recipient), Sender(Sender), Message(Message), Occasion(Occasion), cardNum(num){}

  void setRecipient(string w) {
    Recipient = w;
  }

  string getRecipient() const{
    return Recipient;
  }

  void setSender(string x) {
    Sender = x;
  }

  string getSender() const{
    return Sender;
  }

  void setMessage(string y) {
    Message = y;
  }

  string getMessage() const{
    return Message;
  }

  void setOccasion(string z) {
    Occasion = z;
  }

  string getOccasion() const{
    return Occasion;
  }

  void setCardNum(int a) {
    cardNum = a;
  }

  int getCardNum() const{
    return cardNum;
  }

  void displayData(){
    cout<<"Card ID: "<<cardNum<<endl<<endl;
    cout<<"--- A Card for "<<Occasion<<" ---"<<endl<<endl;
    cout<<"Dear "<<Recipient<<", "<<endl;
    cout<<Message<<endl<<endl;
    cout<<"From "<<Sender<<endl;
  }
};



GreetingCard prompt_input(){
  string Recipient;
  string Sender;
  string Message;
  string Occasion;
  int num;
  cout << "Please enter the name of the recipient: ";
  getline(cin, Recipient);
  cout << "Please enter the name of the sender: ";
  getline(cin, Sender);
  cout << "Please enter the message: ";
  getline(cin, Message);
  cout << "Please enter the occasion: ";
  getline(cin, Occasion);
  cout<<"Please enter the card ID: ";
  cin>>num;
  return GreetingCard(Recipient, Sender, Message, Occasion, num);
}
int main()
{
  GreetingCard Card1 = prompt_input();
  Card1.displayData();

  GreetingCard Default;
  Default.displayData();

  return 0;
}
