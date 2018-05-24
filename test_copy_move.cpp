// can copied object copy every data member?

#include <iostream>
#include <string>
using namespace std;
enum class Gender {M, F};
enum class Major {COMP, MECH, BICH, CPEG, UNDECLARED};

class Person{
private:
  string name;
  int age;
  Gender gender;

public:
  Person(string name, int age, Gender gender): name(name), age(age), gender(gender){}

  virtual void print() const{
    cout<<*this;
  }
  friend ostream& operator<<(ostream& os, const Person& p){
    os<<"Name: "<<p.name<<endl
    <<"Age: "<<p.age<<endl
    <<"Gender: "<<((p.gender == Gender::M)? "Male": "Female")<<endl;
    return os;
  }
  Person& operator=(Person&& p){
    this->name = p.name;
    this->age = p.age;
    this->gender = p.gender;
    p.name = "";
    p.age = 0;
    p.gender = Gender::M;
    return *this;
  }

  Person& operator=(const Person& p){
    if(&p != this){
      this->name = p.name;
      this->age = p.age;
      this->gender = p.gender;
    }
    return *this;
  }

  Person(Person&& p){
    *this = move(p);
  }
  Person(const Person& p){
    *this = p;
  }
};

class Student: public Person{
  int study_year;
  Major major;
  double gpa;
public:
  Student(string name, int age, Gender gender, int yr, Major maj = Major::UNDECLARED, double gpa = 0): Person(name, age, gender), study_year(yr), major(maj), gpa(gpa){}

  void print() const override{
    cout<<*this;
  }

  friend ostream& operator<<(ostream& os, const Student& s){
    s.Person::print();
    os<<"Year of study: "<<s.study_year<<endl
    <<"Major in college: ";
    switch(s.major){
      case Major::COMP: os<<"COMP"<<endl; break;
      case Major::MECH: os<<"MECH"<<endl; break;
      case Major::BICH: os<<"BICH"<<endl; break;
      case Major::CPEG: os<<"CPEG"<<endl; break;
      default: os<<"UNDECLARED"<<endl;
    }
    os<<"Current GPA: "<<s.gpa<<endl;
    return os;
  }

  Student& operator=(Student&& s){
    this->Person::operator=(move(s));
    this->study_year = s.study_year;
    this->major = s.major;
    this->gpa = s.gpa;
    s.study_year = 0;
    s.major = Major::UNDECLARED;
    s.gpa = 0;
    return *this;
  }

  Student& operator=(const Student& s){
    if(&s != this){
      this->study_year = s.study_year;
      this->major = s.major;
      this->gpa = s.gpa;
    }
    return *this;
  }

  Student(Student&& s):Person(s){
    *this = s;
  }
  Student(const Student& s):Person(s){
    *this = s;
  }
};

int main(){
  Student Calvin("Calvin", 20, Gender::M, 2, Major::COMP, 3.31);
  cout<<Calvin<<endl<<endl;

  Student haha = move(Calvin);
  cout<<haha<<endl<<endl;
  cout<<Calvin<<endl;
  return 0;
}
