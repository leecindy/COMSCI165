/***************************************************************
 Problem: Anagram
 Description: Write a function to test if a string is an anagram
 of another string.  The function must be case insensitive,
 does NOT consider numbers, punctuation, or spaces.
 Example: the following are anagrams:
 "Eleven plus two" is an anagram of "Twelve plus one"
 "A McDonald's Burger" is an anagram of "Real dog and crumbs!"
 ****************************************************************/

#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s1, string s2){
    string newS1 = "00000000000000000000000000", newS2 = "00000000000000000000000000";
    
    for(int i=0; i<s1.size() || i<s2.size(); i++){
        (i<s1.size() && isalpha(s1.at(i))) ? newS1.at(toupper(s1.at(i))-'A') += 1: 0;
        (i<s2.size() && isalpha(s2.at(i))) ? newS2.at(toupper(s2.at(i))-'A') += 1: 0;
    }
    
    return (newS1==newS2);
}

int main(){
    cout << isAnagram("Eleven plus two", "Twelve plus one") << endl;
}


