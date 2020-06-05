#include <iostream>
#include <fstream>

using namespace std;

double calculatePower(int n);
double calculateOddNumber(int n);
int signValue(int n);
double kseries(int n);

int main()
{
    ifstream infile;
    infile.open("input.txt");

    int n;
    while( infile >> n)
    {
        cout << kseries(n) << endl;
    }

    return 0;
}


double calculatePower(int n)
{
    double a = 2;

    if (n == 1)
        return a;

    double temp = 1;

    for(int i = 0; i < n; i++)
    {
        temp = temp * a;
    }

    return temp;
}

double calculateOddNumber(int n)
{
    double a = 2;

    return a*n + 1;
}

int signValue(int n)
{
    if (n%2 == 0)
        return  1;
    else
        return -1;
}

double kseries(int n)
{
    if (n == 1)
        return signValue(n) * calculateOddNumber(n) / calculatePower(n);

    return (signValue(n) * calculateOddNumber(n) / calculatePower(n)) + kseries(n - 1);
}
