/*
* EducationalConsultant.cpp
*/

#include "EducationalConsultant.h"

EducationalConsultant::EducationalConsultant(int id, string name, double base, double wage, int hour): Consultant(id, name, base), wagePerHour(wage), workingHours(hour){}

double EducationalConsultant::getWage() const{
  return wagePerHour;
}

int EducationalConsultant::getHours() const{
  return workingHours;
}

void EducationalConsultant::setWage(double wage){
  wagePerHour = wage;
}

void EducationalConsultant::setHours(int hours){
  workingHours = hours;
}

double EducationalConsultant::performanceSalary() const{
  return wagePerHour*workingHours;
}

double EducationalConsultant::netSalary() const{
  return Consultant::netSalary(Consultant::getBaseSalary() + performanceSalary());
}

void EducationalConsultant::check(Item item) const {
	switch(item) {
	case Item::id:
		cout << "ID: " << Employee::getID() <<endl;
		break;
	case Item::name:
		cout << "Name: " << Employee::getName() <<endl ;
		break;
	case Item::base_salary:
		cout<<"Base Salary: "<<Consultant::getBaseSalary()<<endl;
		break;
	case Item::net_salary:
		cout<<"Net Salary: "<<netSalary()<<endl;
		break;
  case Item::performance_salary:
    cout<<"Performance Salary: "<<performanceSalary()<<endl;
    break;
  default:
		cout << "Invalid item." <<endl;
	}

}
