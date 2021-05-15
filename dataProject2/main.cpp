#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;

int checkNumber(string number); //function that returns the number if the string does not contain letters and exits the program otherwise


int main()
{
    
    int* arr;
    int n; //number of elements
    int k; //number of arrays 
    string inputfilename;
    string outputfilename;
   
    cin >> n;
    cin >> k;
    cin >> inputfilename;
    cin >> outputfilename;

    arr = new int[n];

    if (k<=0 || n<=0)
    {
        cout << "k and n must be a positive variables" << endl;
        exit(1);
    }


    ifstream f;
    f.open(inputfilename); //opening the file

    if (!f.is_open())
    {
        cout << "file is not found" << endl;
        exit(1);
    }

    string number;
    for (int i = 0; i < n; i++)
    {
        int temp;
        f >> number;
        arr[i] = checkNumber(number);
    }
      
    //now we will sort the array
    KmergeWay(arr, n, k);
   ////////////////

    ofstream fileOut(outputfilename);//putting the output on a new file
    if (!fileOut)//checking if we can open the file
    {
        cout << "file is not found" << endl;
        exit(1);
    }
    
    //writing the sorted array to the outfile
    for (int i = 0; i < n; i++)
    {
        fileOut << arr[i];
        fileOut << "\n";
    }


    fileOut.close(); //possible bug?????????
    f.close();//closing the file
    delete[] arr;
    return 0;
}



int checkNumber(string number)
{
    int size = number.length();
    for (int i = 0; i < size; i++)
    {   
        if ((i == 0) && (number[i] == '-'))
            continue;

        if (!((number[i]>='0')&&(number[i]<='9')))
        {
            cout << "one of the numbers in the file is invalid" << endl;
            exit(1);
        }
    }
    int num;
    num = stoi(number);
    return num;
}