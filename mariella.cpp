// Team Names: Samuel Sanchez, Athena Raya, Evelyn Murillo, Regie Daquioag
// Date: November 3, 2015
// Project: Speech Signal Analysis (GITHUB)

#include <iostream> // cin, cout
#include <cstdlib> // exit(1)
#include <fstream> // ifstream, ofstream, open(), close()
#include <iomanip> // setw()
#include <cmath> // pow(), sqrt()
#include <vector> // size()
using namespace std;

//*******************************************************************************
double avgPower(vector<double> v, int n);
//Summary: Calculates average power outputted by sound waves
//Precondition: Needs a vector, number of elements, and an output file
//Postcondition: Prints out the average to the system and to a file
//*******************************************************************************
double avgMagnitude(vector<double> v, int n);
//Summary: Calculates average magnitude
//Precondition: Needs a vector, total number of elements, and an output file
//Postcondition: Prints out average to system and output file
//*******************************************************************************
double zeroCross(vector<double> v, int n);
//Summary: Calculates the number of times the sound waves have a value of zero
//Precondition:  Needs a vector, the number of elements in the vector, and an output stream
//Postcondition: Prints out the number of zero crossings to the system and to a file
//*******************************************************************************
double variances(vector<double> v, double n, double mean);
//Summary: Determines the variance of a list of numbers
//Precondition: Needs a vector along with the number of elements
//Postcondition: Prints out the variance
//****************************************************************************
double standardDevs(double vary);
//Summary: Determines the standard deviation of a list of numbers
//Precondition: Needs a vector and a the number of elements in the vector
//Postcondition: Prints out standard deviation
//****************************************************************************
double mean(vector<double> v);
// Summary: Calculates the mean of the vector indexed values and returns them to other functions
// Precondition: Needs a vector and the element count
// Postcondition: Returns the mean
//***************************************************************************
double percentage(double a, double b);
//Summary: calculates the percentage of difference.
//Precondition: comparison two data text file
//Postcondition: print out data.
//***************************************************************************

int main()
{
    ifstream fin1, fin2;
    ofstream fout1;
    vector<double> maria;
    vector<double> ransom;
    double element1 = 0, element2 = 0, iterator;
    fin1.open("two_a.txt");
    fin2.open("two_b.txt");
    fout1.open("comparison.txt");

    if(fin1.fail() || fin2.fail() || fout1.fail())
    {
        cout << "Error: File did not open correctly" << endl;
        exit(1);
    }
    
    while(fin1 >> iterator)
    {
        maria.push_back(element1);
        maria[element1] = iterator;
        element1++;
    }
    
    while(fin2 >> iterator)
    {
        ransom.push_back(element2);
        ransom[element2] = iterator;
        element2++;
    }
    
    mean(maria);
    mean(ransom);
    double meanM = mean(maria);
    double meanR = mean(ransom);
    variances(maria, element1, meanM);
    variances(ransom, element2, meanR);
    double varM = variances(maria, element1, meanM);
    double varR = variances(ransom, element2, meanR);
    
//******************************************************************    
    fout1 << "Samuel Sanchez, Athena Raya, Evelyn Murillo, Regie Daquioag\n" << endl;
    
    fout1 << setw(24) << "two_a.txt"
        << setw(15) << "two_b.txt" 
        << setw(18) << "% difference" << endl;
    fout1.setf(ios::left);
    
    fout1 << setw(15) << "Mean" << setw(15);
    fout1 << meanM << setw(15);
    fout1 << meanR << setw(15);
    fout1 << percentage(mean(maria),  mean(ransom))  << endl;
    
    
    fout1 << setw(15) << "Variance" << setw(15);
    fout1 << varM << setw(15);
    fout1 << varR << setw(15);      
    fout1  << percentage(varM, varR)  << endl;
         
    fout1 << setw(15) << "Deviation" << setw(15);
    fout1 << standardDevs(varM) << setw(15);
    fout1 << standardDevs(varR) << setw(15);      
    fout1 << percentage(standardDevs(varM), standardDevs(varR))  << endl;
     
    fout1 << setw(15) << "Power" << setw(15);
    fout1 << avgPower(maria, element1) << setw(15);
    fout1 << avgPower(ransom, element2) << setw(15);      
    fout1 << percentage(avgPower(maria, element1), avgPower(ransom, element2 ))  << endl;
         
    fout1 << setw(15) << "Magnitude" << setw(15);
    fout1 << avgMagnitude(maria, element1) << setw(15);
    fout1 << avgMagnitude(ransom, element2) << setw(15);      
    fout1 << percentage(avgMagnitude(maria, element1), avgMagnitude(ransom, element2))  << endl;
    
    fout1 << setw(15) << "Zero Crossings" << setw(15);
    fout1 << zeroCross(maria, element1) << setw(15);
    fout1 << zeroCross(ransom, element2) << setw(15);      
    fout1 << percentage(zeroCross(maria, element1), zeroCross(ransom, element2)) << endl;
    
    fout1 << " \n B. The values for each data file that match closely are: mean. " << endl
                << " C. The values for each data file that are mostly different are: " << endl
                << " D. Other statistical measures we would suggest are: sound waves " <<endl
                << " E. By examining the data from both file we have determined the percentage" << endl  << "difference is too great to concluded that voice captured is Maria Estrella "  << endl;

    fin1.close();
    fin2.close();
    return 0;
}

double avgPower(vector<double> v, int n)
{
    double avgPower = 0;
    int size = v.size();
    for(int xi = 0; xi < n; xi++)
    {
        avgPower += pow(v[xi], 2);  
    }
    
    return avgPower/size;
}

double avgMagnitude(vector<double> v, int n)
{
    double avgMagnitude = 0;
    int size = v.size();
    for(int xi = 0; xi < n; xi++)
    {
        avgMagnitude += fabs(v[xi]);  
    }
    
    return avgMagnitude/size;
}

double zeroCross(vector<double> v, int n)
{
    int numOfCrossings = 0;
    double prev, next;
    for(int xi = 0; xi < n; xi++)
    {
        prev = v[xi];
        next = v[xi + 1];
        if((prev < 0 && next > 0) || (prev > 0 && next < 0))
            numOfCrossings++;
    }
    return numOfCrossings;
}


double variances(vector<double> v, double n, double mean)
{
               double total = 0, sum = 0;
               double variance;
       
               for(int xi = 0; xi < n; xi++)
               {
               sum +=  pow((v[xi] - mean), 2);
               }
               variance = (sum/n);

               return variance;
}


double standardDevs(double vary)
{
               double standDev = sqrt(vary); // Used variance result
               
               return standDev;
}


double mean(vector<double> v)
{
    double sum = 0.0;
    double average;
    for (int ix = 0; ix < v.size();ix++)
    {
        sum+=v[ix];
    }
    average = sum / v.size();
    return average;
}


double percentage(double a, double b)
{
    return ((fabs(a-b) / ((a + b)/2)) * 100); // Initial - final / initial * 100 for percentage
}


