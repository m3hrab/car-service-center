#include <iostream>
using namespace std;

int main()
{
    // dataType arrayName[size]
    int numbers[200];

    
    // arrayName[index}]

    for (int i=0; i<200; i++)
    {
        numbers[i] = i + 1;
    }
    // numbers[index] = value
    

    cout << numbers[199] << endl;
    return 0;


}