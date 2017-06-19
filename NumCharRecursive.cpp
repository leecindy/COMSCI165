//
//  main.cpp
//  NumCharRecursive
//
//  Created by Cindy Lee on 4/21/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int numChar(char letter, string myStr, int index){
    if(index >= myStr.size())
        return 0;
    else{
        if(myStr.at(index) == letter)
            return 1+numChar(letter, myStr, index+1);
        else
            return numChar(letter, myStr, index+1);
    }
}

int main(){
    string myStr = "aabbcdddeef";
    cout << numChar('d', myStr, 0) << endl;
    return 0;
}
