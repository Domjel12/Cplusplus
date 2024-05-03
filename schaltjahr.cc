
#include <iostream>

bool Schaltjahr(int y){
	
	return (y % 4 == 0 && y % 100 !=0 || y % 400 == 0);
}

int main(int argc, char **argv)
{
	int year;
	
	std::cout << "Bitte Jahr eingeben: " << std::endl;
	 
	std::cin >> year;
	 
	if(Schaltjahr(year))
		std::cout << year << " ist Schaltjahr!" << std::endl;
	else
		std::cout << year << " ist kein Schaltjahr!" << std::endl;
		
	return 0;
}

