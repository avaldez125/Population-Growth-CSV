//Andrew Valdez avaldez125@unm.edu
//Driver.cpp

#include "Functions.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> iAge, initialPop, popBase, 
		est2010, est2011, est2012, est2013, est2014;
	ifstream dataFile;
	string value, skip, solvedData, answer;
	double rateofchange, malechange, femalechange;
	int newPop;
	bool loop = true;

	//reading data file to vectors
	dataRead(iAge, initialPop, popBase, est2010, est2011, est2012, est2013, est2014);
	
	cout << "\nLoading complete!\nPlease wait while calculations are completed...\n";

	do
	{
		//sending the 101st value (the combined population for all ages and genders) to the formulaFind function
		rateofchange = formulaFind(popBase[101], initialPop[101], est2014[101], est2013[101], est2012[101], est2011[101]); 
		//sending the 306th value to formulaFind, as that is where all population data for women is
		femalechange = formulaFind(popBase[305], initialPop[305], est2014[306], est2013[305], est2012[305], est2011[305]); 
		//sending the 203rd value to formulaFind, where you can find all population data for men
		malechange = formulaFind(popBase[204], initialPop[204], est2014[204], est2013[203], est2012[203], est2011[203]); 
		newPop = maxPopulationGrowth(est2011, est2012, est2013, est2014);

		if (verifyAcc(rateofchange, est2011[101], est2012[101])
				&& verifyAcc(malechange, est2012[202], est2013[202])
					&& verifyAcc(femalechange, est2011[303], est2012[303]))
		{
			solvedData = formulaSolver(rateofchange, initialPop[101]);
			dataDisplay(solvedData, malechange, femalechange, newPop, initialPop[101]);
		}

		cout << "\nData analysis complete! Would you like to run this program again? (y/n) \n";
		cin >> answer;
		
		if (answer == "n" || answer == "no")
		{
			loop = false;
		}
		
	} while (loop);

	cout << "\nThank you for using my program!\n\n";

	return 0;
}