/* RLE encryption relies on the fact that in many files there are many repeated characters
 (example: AAAAAA) ..
 
 Method-i
 The algorithm replaces this will a  character+count resulting in a much smaller size.
 For example: a string in a file contains: "AAAAADDDDDDDDEEEQQQQQQQQQQAAEE" is replaced 
 with: "A5D8E3Q10A2E2"

 Write a program that asks user to input a file name, and choose the operation
 A) COMPRESS: read and compress the file into a 2nd file with the same name with added extension ".RLE"
 B) DECOMPRESS: read a compressed file and reconstruct the original file.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void compress(string fileName){
    fstream myFile;
    fstream outFile;
    string str;

    myFile.open(fileName, ios::in);
    outFile.open(fileName+".RLE", ios::out|ios::app);
    
    if(myFile && outFile){
        while(getline(myFile, str)){
            int pos = 0;
            long count;
            char letter;
            while(pos < str.size()){
                letter = str.at(pos);
                if(str.find_first_not_of(letter, pos) != string::npos){
                    count = str.find_first_not_of(letter, pos) - pos;
                }
                else{
                    count = str.size() - pos;
                }
                outFile << letter << count;
                pos += count;
            }
            outFile << endl;
        }
    }
    
    myFile.close();
    outFile.close();
}

void decompress(string fileName){
    fstream myFile;
    fstream outFile;
    string str;
    
    myFile.open(fileName, ios::in);
    outFile.open(fileName.substr(0, fileName.size()-4));
    
    if(myFile && outFile){
        while(getline(myFile, str)){
            int count, pos;
            char letter;
            while(stringstream(str) >> letter >> count){
                for(int i = 0; i < count; i++)
                    outFile << letter;
                if(str.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 1) != string::npos){
                    pos = str.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 1);
                    str = str.substr(pos);
                }
                else{
                    str.clear();
                }
            }
            outFile << endl;
        }
    }
    
    myFile.close();
    outFile.close();
    
}

int main(){
    string mystr, fileName;
    int choice;
    cout << "Enter a file name: " << endl;
    getline(cin, fileName);
    
    cout << "Please choose the operation:" << endl;
    cout << "1 - Compress" << endl;
    cout << "2 - Decompress" << endl;
    getline(cin, mystr);
    stringstream(mystr) >> choice;
    
    switch(choice){
        case 1:
            compress(fileName);
            break;
        case 2:
            decompress(fileName);
            break;
        default:
            cout << "You selected an invalid oepration.  End of program." << endl;
            break;
    }
    
    return 0;
    
}
