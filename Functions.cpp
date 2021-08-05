//Andrew Valdez avaldez125@unm.edu
//Functions.cpp

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> //for formatting later

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;


void Header()
{
	cout << "Andrew Valdez Program 7 Part 1\navaldez125@cnm.edu\nThis is a program that loads a specific CSV file into memory for easy reference\n";
	return;
}

void dataRead(vector <int> &iAge, vector <int> &initialPop, vector <int> &popBase,vector <int> &est2010, 
			  vector <int> &est2011, vector <int> &est2012, vector <int> &est2013, vector <int> &est2014)
{
	ifstream dataFile;
	string skip, value;
	dataFile.open("PopulationEstimates.csv");

	getline(dataFile, skip); //trashing the first line, as it is just for index

	Header(); //display course header

	do
	{	
		//due to some strange quirks of getline, specifically getline skipping the first value in a line,
		//these appear out of order. They work as intended, however
		getline(dataFile, value, ',');
		est2014.push_back(stoi(value)); 
		getline(dataFile, value, ',');
		iAge.push_back(stoi(value));
		getline(dataFile, value, ','); 
		initialPop.push_back(stoi(value));
		getline(dataFile, value, ',');
		popBase.push_back(stoi(value)); 
		getline(dataFile, value, ',');
		est2010.push_back(stoi(value)); //population estimate in 2010
		getline(dataFile, value, ',');
		est2011.push_back(stoi(value)); //population estimate in 2011 
		getline(dataFile, value, ',');
		est2012.push_back(stoi(value)); //etc
		getline(dataFile, value, ',');
		est2013.push_back(stoi(value));

	}while (!dataFile.eof() && dataFile.good()); //loop stops at the end of file or if there is a problem with the file

	dataFile.close(); //close file when function is done

	return;
}

double formulaFind(int &est1, int &est2, int &est2014,
				   int &est2013, int est2012, int &est2011)
{
	//this function is left intentionally vague instead of including a while or for loop so it can be used to see
	//the average growth rate of all years for any given value called by driver.cpp
	//this function returns the growth rate as a double r in the form of Population = Pe^rt (r is rate of change)
	double rateofchange;
	//typecasting ints est1 and est2 to doubles for accuracy
	double estdouble1 = (double) est1 / (double) est2;
	double estdouble2 = (double) est2012 / (double) est2011;
	double estdouble3 = (double) est2013 / (double) est2014;
	rateofchange = ((estdouble1 + estdouble2 + estdouble3) / 3.0) / 10000; //dividing combined gender and age population, as this gives us all possible ages and genders

	return rateofchange;
}
int maxPopulationGrowth(vector <int> &est2011, vector <int> &est2012, vector <int> &est2013, vector <int> &est2014)
{
	//returns the average population growth per year
	int change1112, change1213, change1314;
	change1112 = est2012[0] - est2011[0];
	change1213 = est2013[0] - est2012[0];
	change1314 = est2014[1] - est2013[0];

	if (change1112 > change1213 && change1112 > change1314)
	{
		return change1112;
	}
	
	else if (change1213 > change1112 && change1213 > change1314)
	{
		return change1213;
	}

	else
	{
		return change1314;
	}

}

bool verifyAcc(double &rateofchange, int &pop1, int &pop2)
{
	int change = &pop1 - &pop2;
	//testing to see if the rate of change gives us a number within 10000 of the actual number
	if (change - (pop1 * exp(rateofchange)) < 10000) 
	{
		return true;
	}

	else
	{
		return false;
	}

}

string formulaSolver(double &rateofchange, int &startpop)
{
	stringstream ss;
	string data = "test";
	double pop2020;
	pop2020 = startpop * (exp(rateofchange * 10)); //10 here is the number of years from 2010 to the year selected

	ss << "\nGiven the variables and a population growth rate of " << rateofchange << "\nWe can predict the population in the United States in the year 2020 "
		<< "\nwill be: " << fixed <<  (int) ceil(pop2020) << " people total according to our data. ";
	data = ss.str();

	return data;
}


void dataDisplay(string &solvedData, double &malechange, double &femalechange, int &newpop, int &startpop)
{
	ofstream userFile;
	userFile.open("CalcData.txt");
	if (userFile.good())
	{
		//writing data to file
		userFile << solvedData << "The male population will increase by \n" << fixed << (int)(startpop * (exp(malechange * 10))) 
			<< " and the female population will increase by " << fixed << (int)(startpop * (exp(femalechange * 10))) << 
			" in that time.\nWe can also gather the population increases by about " 
			<< newpop << " every year. ";
	}
	else
	{
		cout << "\nThere was an error opening the file. Please try again.\n";
	}

	return;
}

#endif