#include <iostream>

using namespace std;

class Tickets{

private:
	//Define your variables here
	//there should be 3 variables, storing
	// max capacity, 
	// number of group holders and 
	// number of house holders resp.
	
	// this function accepts two integer values,
	// and return a float value by a/b*100 (a percentage)
	// NOTE: division of 2 integers will only return an integer value
	float calcPercentage(int a, int b);

	// this function will calculate number of available seats for individual sales
	int calcAvailableSeats();

public:
	// this is a constructor with default value: maximum capacity 1319
	// you can change the names 'a' and 'b' for higher readibility
	// this function should initialize all your variables' values 
	Tickets(int a, int b, int maxCapacity = 1319);

	// this function will print out the calculations required
	void showCalculations();
};

int main(){
	// here, you should prompt the user for number of group ticket holders.
	// store the value in a variable called numGroupHolder
	

	// here, you should prompt the user for number of house ticket holders.
	// store the value in a variable called numHouseHolder
	
	Tickets Hamilton(numGroupHolder, numHouseHolder);
	Hamilton.showCalculations();

	return 0;
}
