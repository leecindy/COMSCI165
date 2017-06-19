/***************************************************************
 Problem: Functions Lab - Binary to Decimal
 Description: Write a function that returns a decimal number 
 from a binary string.  Write a test program that prompts the 
 user to enter a binary number as a string and displays its 
 decimal equivalent value.
 Name: Pui Lee (Cindy)
 ID: 1147451
 Date: 2/16/2017
 Status: complete
 ****************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

// Return the decimal value of a binary string
int bin2Dec(const string &binaryString){
    int remainder = 0, count = 0;
    int binary = 0, decimal = 0;
    stringstream(binaryString) >> binary;
    
    while(binary > 0){
        remainder = binary % 10;
        decimal += remainder * pow(2, count);
        count ++;
        binary /= 10;
    }
    return decimal;
}

// Function to print output
void print(ostream& out, int decimal){
    out << "Decimal equivalent value is " << decimal << endl;
    return ;
}

int main(){
    string myStr;
    ofstream outFile("Bin2Dec.txt");
    cout << "Enter a binary number" << endl;
    getline(cin, myStr);
    
    if(outFile){
        print(cout, bin2Dec(myStr)); //print to screen
        print(outFile, bin2Dec(myStr)); //print to file
    }
    
    outFile.close();
    return 0;
}
