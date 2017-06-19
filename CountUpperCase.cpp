/***************************************************************
 Problem: Loops Lab - Count Uppercase Letters
 Description: This program will ask the user to input a string,
 and it will display the number of uppercase letters.
 Name: Pui Lee (Cindy)
 ID: 1147451
 Date: 2/9/2017
 Status: complete
 ****************************************************************/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    
    string myString;
    int upperCount = 0;
    
    cout << "Enter a string: ";
    getline(cin, myString);
    
    for (int i = 0; i < myString.size(); i++){
        if(isupper(myString.at(i)))
           upperCount++;
    }
    
    cout << "The number of uppercase letters is " << upperCount << endl;
    
    return 0;
    
}
