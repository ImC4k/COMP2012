#include <iostream>
#include <string>
#include <ifstream>

using namespace std;

/*
    #######################             #########################
    #######################             ##########################
    ######                              #######             #######
    ######                              #######              #######
    ################                    #######              ########
    ################                    #######             ########
    ######                              ###########################
    ######                              ##########################
    ######                              #######
    ######                              #######
    ######                              #######

*/

// Function prototypes, be defined at bottom

Product* promptProductDetail(string name = "", int quantity = -1);





/*
    #####################               ############################
    #####################               #############################
    #####                               ######                  #######
    #####                               ######                   #######
    #####                               ######                    #######
    #####                               ######                    #######
    #####                               ######                   #######
    #####                               ######                  #######
    #####################               #############################
    #####################               ############################

*/

// Class declaration

class Product{
  string name;
  int quantity;
  double price;

  bool isPaid;
  string specialRequest;

public:
  Product(string name, double price, int quantity, bool isPaid, string request = "");
  Product(string name, int quantity);
  Product(const Product& another);
  string getName();
  double getPrice();
  int getQuantity();
  bool status();
  string getSRequest();
  void setName(string name);
  void setPrice(double price);
  void setQuantity(int quantity);
  bool setStatus(bool status);
  string setSRequest(string specialRequest);

};

class Person{
  string name;
  int numProduct; // stores the number of purchases
  Product** purchasedItems; // dynamic array to store pointers of Product objects

public:
  Person(string name, Product* product = nullptr);
  Person(const Person& another);
  ~Person();
  string getName();
  int getnumProduct();
  double getPurchaseSum(); // needs modification (price*quantity)
  Product* getProduct(string name); // returns product pointer by searching name
  Product* getProduct(int index); // returns product pointer by index, overloaded
  void addProduct(string name, int quantity);
  void addProduct(Product* product);
  void removeProduct(sdtring name, int quantity);
};

class Clients{ // designed to collect Person objects
  Person** clients;
  int numClients;
public:
  Clients(); // default constructor, log nothing to clients[]
  Clients(Person* person);
  Clients(Clients &another);
  ~Clients();
  Clients** getClients();
  int getNumClients();
  void addClient(Person* person); // giving full detail to add is easy
  void removeClient(string name); // this function only needs the name of person, will do search
  Person* getPerson(int index); // returns person pointer by index
  int getPersonIndex(string name); // return person pointer by searching name
}



Product::Product(string name, double price, int quantity, bool isPaid, string request){
  this->name = name;
  this->price = price;
  this->quantity = quantity;
  this->isPaid = isPaid;
  this->specialRequest = request;
}
Product::Product(string name, int quantity){
  this->name = name;
  this->quantity = quantity;
  this->price = 0;
  this->isPaid = false;
  this->specialRequest = "";
}
Product::Product(const Product& another){
  this->name = another->getName();
  this->price = another->getPrice();
  this->quantity = another->getQuantity();
  this->isPaid = another->status();
  this->specialRequest = another->getSRequest();
}
string Product::getName(){return name;}
double Product::getPrice(){return price;}
int Product::getQuantity(){return quantity;}
bool Product::status(){return isPaid;}
string Product::getSRequest(){return specialRequest;}
void Product::setName(string name){this->name = name;}
void Product::setPrice(double price){this->price = price;}
void Product::setQuantity(int quantity){this->quantity = quantity;}
bool Product::setStatus(bool status){this->status = status;}
string Product::setSRequest(string specialRequest){this->specialRequest = specialRequest;}






Person::Person(string name, Product* product){
  this->name = name;
  if(product == nullptr){
    numProduct = 0;
    return; // readability
  }
  else{
    numProduct++;
    purchasedItems = new Product*[numProduct];
    purchasedItems[0] = product;
    return;
  }
}
Person::Person(const person& another){
  this->name = another->getName();
  this->numProduct = another->getnumProduct();
  purchasedItems = new Product*[numProduct];
  for(int i = 0; i < numProduct; i++){
    purchasedItems[i] = new Product(another->getProduct(i));
  }
} // TODO
Person::~Person(){
  for(int i = 0; i < numProduct; i++){
    delete purchasedItems[i];
    purchasedItems = nullptr;
  }
  delete[] purchasedItems;
  purchasedItems = nullptr;
}
string Person::getName(){return name;}
int Person::getnumProduct(){return numProduct;}
double Person::getPurchaseSum(){
  double sum = 0;
  for(int i = 0; i < numProduct; i++){
    sum += purchasedItems[i]->getPrice()*purchasedItems[i]->getQuantity();
  }
  return sum;
}
Product* Person::getProduct(string name){
  for(int i = 0; i < numProduct; i++){
    if(purchasedItems[i]->getName() == name){
      return purchasedItems[i];
    }
  }
  return nullptr;
}
Product* Person::getProduct(int index){
  if(index >= numProduct){
    return nullptr;
  }
  else return purchasedItems[index];
} // TODO
void Person::addProduct(string name, int quantity){ // if there is product with same name, add to that object
  Product* targetProduct = getProduct(name);
  if(targetProduct != nullptr){
    int originalQuantity = targetProduct->getQuantity();
    targetProduct->setQuantity(originalQuantity + quantity);
    return;
  }
  else{
    Product* newProduct = promptProductDetail(name, quantity);
    addProduct(newProduct);
  }
}
void Person::addProduct(Product* product){ // overloaded function
  Product* existProduct = getProduct(product->getName()); // get the existing product with the same name as request
  if(numProduct == 0){ // nothing has been purchased by this person
    purchasedItems = new Product*[1];
    purchasedItems[0] = product;
    return;
  }
  else if(existProduct != nullptr){ // there is such product in purchasedItems[] already
    int originalQuantity = existProduct->getQuantity();
    existProduct->setQuantity(originalQuantity + product->getQuantity());
    return;
  }
  else{ // there is no such product in purchasedItems[], and need to put it to last of array
    // NOTE: no sorting needed
    Product** newPurchasedItems = new Product*[++numProduct]; // create new array for storing all products purchased by person
    for(int i = 0; i < numProduct - 1; i++){ // copy to new array
      Product* currentProduct = purchasedItems[i];
      Product* newProduct = new Product(currentProduct->getName(), currentProduct->getPrice(), currentProduct->getQuantity(), currentProduct->status(), currentProduct->getSRequest());
      newPurchasedItems[i] = newProduct;
    }
    newPurchasedItems[numProduct-1] = product; // put the new product to last of array

    for(int i = 0; i < numProduct - 1; i++){ // delete old purchasedItems
      delete purchasedItems[i];
    }
    delete[] purchasedItems;
    purchasedItems = newPurchasedItems; // reassign purchasedItems
  }

}
void Person::removeProduct(string name, int quantity){
  Product* product = getProduct(name);
  int originalQuantity = product->getQuantity();
  if(product == nullptr || originalQuantity < quantity || quantity <= 0) return;
  else if(originalQuantity > quantity){
    product->setQuantity(originalQuantity - quantity);
  }
  else{ // originalQuantity == quantity, NOTE remove the product object from purchasedItems
    Product** newPurchasedItems = new Product*[--numProduct];
    for(int i = 0; i < numProduct; i++){
      if(purchasedItems[i]->getName() == name){ // skip one object
        i--;
        continue;
      }
      Product* currentProduct = purchasedItems[i];
      Product* newProduct = new Product(currentProduct->getName(), currentProduct->getPrice(), currentProduct->getQuantity(), currentProduct->status(), currentProduct->getSRequest());
      newPurchasedItems[i] = newProduct;
    }
    for(int i = 0; i < numProduct + 1; i++){
      delete purchasedItems[i];
    }
    delete[] purchasedItems;
    purchasedItems = newPurchasedItems;
    return;
  }
}





Clients::Clients(){
  numClients = 0;
  clients = nullptr;
}
Clients::Clients(Person* person){
  clients = new Product*[++numClients];
  clients[0] = person;
  return;
}
Clients::Clients(Clients &another){ // hard copy required
  this->numClients = another->getNumClients();
  clients = new Person*[numClients];
  for(int i = 0; i < numClients; i++){
    clients[i] = new Person(another->getPerson(i));
  }
}
Clients::~Clients(){
  for(int i = 0; i < numClients; i++){
    delete clients[i];
  }
  delete[] clients;
}
Clients** Clients::getClients(){return clients;}
int Clients::getNumClients(){return numClients;}
void Clients::addClient(Person* person){
  if(numClients == 0){
    clients = new Person*[1];
    clients[0] = person;
  }
  else{

  }
} // TODO // TODO
void Clients::removeClient(string name){
  int targetPersonIndex = getPerson(name);
  if(targetPersonIndex == -1){
    return;
  }
  else{ // the required person exists, removal required
    Person** newClients = new Person*[--numClients];
    for(int i = 0; i < numClients; i++){ // create new clients[], copy every Person except the found index of person to be removed
      if(i == targetPersonIndex){
        continue;
      }
      Person* newPerson = new Person(clients[i]);
      newClients[i] = newPerson;
    }
    for(int i = 0; i < numClients + 1; i++){ // delete clients[], reassign clients = newClients
      delete clients[i];
    }
    delete[] clients;
    clients = newClients;
    return;
  }
}
int Clients::getPersonIndex(string name){
  for(int i = 0; i < numClients; i++){
    if(clients[i]->getName() == name){
      return i;
    }
  }
  return -1;
}
Person* Clients::getPerson(int index){
  if (index >= numClients) return nullptr;
  else return clients[index];
}



Product* promptProductDetail(string name, int quantity){ // NOTE:in perfect condition only, don't temper with the rules
  if(name == ""){
    cout<<"Please enter the name of product:"<<endl;
    cin>>name;
  }

  double price;
  cout<<"Please enter the price of product:"<<endl;
  cin>>price;

  if(quantity == -1){
    cout<<"Please enter the quantity of product:"<<endl;
  }

  bool isPaid;
  char isPaid_c;
  cout<<"Has he/she paid yet? enter y or n"<<endl;
  cin>>isPaid_c;
  if(isPaid_c == 'y'){
    isPaid = true;
  }
  else isPaid = false;

  string request;
  cout<<"Please enter the special request or remark (in 1 line only):"<<endl;
  geline(cin, request);

  Product* newProduct = new Product(name, price, quantity, isPaid, request);
  return newProduct;
}

int main(){

  return 0;
}
