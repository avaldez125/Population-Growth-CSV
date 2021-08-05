# Population-Growth-CSV
This program reads in a formatted .csv file and calculates the population growth of said data over a period of time. This is a C++ program created in Visual Studio 
that uses various functions, libraries, references, and output formats. 

I created this program while studying at Central New Mexico Community College. Although the formatting and comments are things I wouldn't do the same way today, I 
still think my solution is solid. I initially used data gathered from www.census.gov to perform this calculation, but this program could theoretically be used to 
predict any population growth given properly formatted data. 

Compatible data should be in the following format:
| SEX | AGE | POPULATION | EST_BASE | POP_EST_YEAR1 | POP_EST_YEAR2 | POP_EST_YEAR3 | POP_EST_YEAR4 | POP_EST_YEAR5 |

Compatible values should be formatted as follows:
SEX
      Nominal
      0 for Male and Female
      1 for Male
      2 for Female

AGE: 
      Continuous
      0 - 100. Age in years

POPULATION_YEAR1: 
      Continuous
      Any positive integer
      
EST_BASE:
      Continuous
      Any positive integer
      
POP_EST_YEAR1:
      Continuous
      Any positive integer

POP_EST_YEAR2:
      Continuous
      Any positive integer
      
POP_EST_YEAR3:
      Continuous
      Any positive integer
      
POP_EST_YEAR4:
      Continuous
      Any positive integer
      
POP_EST_YEAR5:
      Continuous
      Any positive integer
