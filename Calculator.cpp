#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

//perform calculation
double calculate(string operation) {
    double x = 0, y = 0, result = 0;
    char sign;
    
    if(operation.find("sqrt") != string::npos){
        string sqrtOperation;
        sqrtOperation = operation.substr(operation.find("(") + 1);
        stringstream(sqrtOperation) >> x;
        sign = 's';
    }
    else{
        stringstream(operation) >> x >> sign >> y;
    }
    
    switch(sign){
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        case '^':
            result = pow(x, y);
            break;
        case 's':
            result = sqrt(x);
            break;
    }
    
    return result;
}

//decimal to binary
int binary(int decimal){
    int remainder = 0, bin = 0, multiple = 1;
    while(decimal > 0){
        remainder = decimal % 2;
        bin += remainder * multiple;
        multiple *= 10;
        decimal /= 2;
    }
    return bin;
}

//print result
void printResult(ostream &out, string operation, double result){
    int width = operation.size();
    out << fixed << setprecision(3) << "Result: " << operation << " = " << left << setw(20-width);
    out << result << "\tHex: " << hex << static_cast<int>(result);
    out << "\tOct: " << oct << static_cast<int>(result);
    out << dec << "\tBin: " << binary(static_cast<int>(result)) << endl;
    return;
}

//print bye
void printBye(ostream& out){
    out << "Good Bye!" << endl;
    return;
}

//print output
void display(string operation, fstream& outputFile){
    if (operation == "exit") {
        printBye(cout);
        printBye(outputFile);
        exit(0);
    }
    else {
        printResult(cout, operation, calculate(operation));
        printResult(outputFile, operation, calculate(operation));
    }
    return;
}

//file input method
void fileInput() {
    string fileName, operation;
    fstream inputFile, outputFile;
    cout << "Please enter the input file name" << endl;
    getline(cin, fileName);
    inputFile.open(fileName, ios::in);
    outputFile.open(fileName.substr(0,fileName.find(".")) + "-Calculated.txt", ios::out | ios::app);
    
    if (inputFile && outputFile) {
        while (getline(inputFile, operation)) {
            cout << "Please Input Operation: " << operation << endl;  // just to look the same as direct input
            display(operation, outputFile);
        }
    }
    
    inputFile.close();
    outputFile.close();
    
    return;
}

//direct input method
void directInput() {
    string operation;
    bool next = true;
    fstream outputFile;
    outputFile.open("Calc.txt", ios::out | ios::app);
    
    while(next){
        cout << "Please Input Operation: ";
        getline(cin, operation);
        if(outputFile){
            display(operation, outputFile);
        }
    }
    outputFile.close();
    return;
}

int main() {
    string myStr;
    int choice;
    cout << "Welcome to Calculator\n" << endl;
    cout << "Please choose an input method" << endl;
    cout << "1 - File Input" << endl;
    cout << "2 - Direct Input" << endl;
    getline(cin, myStr);
    stringstream(myStr) >> choice;
    switch(choice){
        case 1:
            fileInput();
            break;
        case 2:
            directInput();
            break;
    }
    return 0;
}
