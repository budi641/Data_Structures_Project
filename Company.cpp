#include "Company.h"

Company::Company()
{

	GlobalTime.setTime(4, 0, 0);

	Run = true;

	cout << "please enter the name of the input file:"<<endl;

	string fileName;

	cin >> fileName;

	IO_Manager.setInputFileName(fileName);

	IO_Manager.processInput();

	stations = new Station[IO_Manager.getNumberOfStations()];

	



	
	
}

void Company::runSimulation()
{

	while(Run)
	{






	}

   
}
