#include <iostream>

using namespace std;

class Tickets{
	int MaxSeats;
	int GroupHolders;
	int HouseHolders;

	float calcPercentage(int a, int b){float fa = a, fb = b; return fa/fb*100;}
	int calcAvailableSeats(){return MaxSeats - GroupHolders - HouseHolders;}

public:
	Tickets(int numGroupHolder, int numHouseHolder, int maxCapacity = 1319){
		MaxSeats = maxCapacity;
		GroupHolders = numGroupHolder;
		HouseHolders = numHouseHolder;
	}

	void showCalculations(){
		cout<<"Number of available tickets for individual sales are "<<calcAvailableSeats()<<"."<<endl;
		cout<<"Percentage of individual sales is "<<calcPercentage(calcAvailableSeats(), MaxSeats)<<"%."<<endl;
		cout<<"Percentage of group ticket sales is "<<calcPercentage(GroupHolders, MaxSeats)<<"%."<<endl;
		cout<<"Percentage of reserved house ticket holder is "<<calcPercentage(HouseHolders, MaxSeats)<<"%."<<endl;

	}
};

int main(){
	cout<<"Please input the number of group ticket holders: "<<endl;
	int numGroupHolder;
	cin>>numGroupHolder;

	cout<<"Please input the number of house ticket holders: "<<endl; // num of tickets reserved for authors, producers, casts, theater owners etc.
	int numHouseHolder;
	cin>>numHouseHolder;

	Tickets Hamilton(numGroupHolder, numHouseHolder);
	Hamilton.showCalculations();
}
