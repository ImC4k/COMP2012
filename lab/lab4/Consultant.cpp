/*
 * Consultant.cpp
 */

#include "Consultant.h"

Consultant::Consultant(int cid, string cname, double base): Employee(cid, cname), cid(cid), cname(cname), baseSalary(base) {
}

double Consultant::getBaseSalary() const {
	return baseSalary;
}

void Consultant::setBaseSalary(double base) {
	baseSalary = base;
}

double Consultant::netSalary(double salary) const {
	double temp = salary; // temp is for subtracting 40000s
	double taxToPay = 0;
	if(salary < 40000){
		return salary;
	}
	if(salary == 40000){
		return salary - salary*0.02;
	}
	taxToPay += 40000*0.02;
	temp -= 40000;
	if(temp <= 40000){
		return salary - taxToPay - temp*0.07;
	}
	taxToPay += 40000*0.07;
	temp -= 40000;
	if(temp <= 40000){
		return salary - taxToPay - temp*0.12;
	}
	taxToPay += 40000*0.12;
	temp -= 40000;
	taxToPay += temp*0.17;
	return salary - taxToPay;
}

void Consultant::check(Item item) const {
	switch(item) {
	case Item::id:
		cout << "ID: " << cid <<endl;
		break;
	case Item::name:
		cout << "Name: " << cname <<endl ;
		break;
	case Item::base_salary:
		cout<<"Base Salary: "<<baseSalary<<endl;
		break;
	case Item::net_salary:
		cout<<"Net Salary: "<<netSalary(baseSalary)<<endl;
		break;
	default:
		cout << "Invalid item." <<endl;
	}

}
