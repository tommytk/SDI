#include "UI.h"
#include <ctime>
#include <cmath>
#include <iostream>

#pragma region Main
int main()
{
	srand((unsigned)time(0));
	UserInterface myUI;
	int userInput;
	
	bool exitSelected = false;
	do
	{ 
		//TESTING CODE GOES ABOVE HERE
		
		myUI.displayMenu();
		std::cin >> userInput;
		switch (userInput)
		{
		case 1:
			{	
			myUI.addAircraft();
			break;
			}
	case 2:
			{
			myUI.deleteAircraft();
			break;
			}
		case 3:
			{
			myUI.searchByName();
			break;
			}
		case 4:
			{
			myUI.searchByID();
			break;
			}
		case 5:
			{
			myUI.printToScreen();
			break;
			}
		/*case 6:
			{
			int sig; 
			sig = (rand()%10000);
			myUI.signalComparison(sig);
			break;
			}
		case 7:
			{
			myUI.saveDatabase();
			break;
			}*/
		case 8:
			{
			myUI.loadDatabase();
			break;
			}
		/*case 9:
			{
			exitSelected = myUI.exit(exitSelected);
			break;
			}*/
		/*default:
			{
			myUI.selectionInvalid();
			break;
			}*/
		}
	} while (!exitSelected);
	return 0;
}



#pragma endregion 