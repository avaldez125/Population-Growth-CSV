//Andrew Valdez avaldez125@unm.edu
//Functions.h

#include <string>
#include <vector>

using namespace std;


void Header();
void dataRead(vector <int> &iAge, vector <int> &initialPop, vector <int> &popBase,vector <int> &est2010, 
			  vector <int> &est2011, vector <int> &est2012, vector <int> &est2013, vector <int> &est2014);
double formulaFind(int &est1, int &est2, int &est2014, int &est2013, int est2012, int &est2011); 
int maxPopulationGrowth(vector <int> &est2011, vector <int> &est2012, 
								vector <int> &est2013, vector <int> &est2014); //estbase and initialpop are not included in this
																				//function as they are incomplete years
bool verifyAcc(double &rateofchange, int &pop1, int &pop2);
string formulaSolver(double &rateofchange, int &startpop);
void dataDisplay(string &solvedData, double &malechange, double &femalechange, int &newpop, int &startpop);
