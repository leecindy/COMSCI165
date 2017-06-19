//
//  main.cpp
//  NumberList
//
//  Created by Cindy Lee on 4/11/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//

#include <iostream>
#include "NumberList.h"
using namespace std;

int main(){
    NumberList list;
    
    list.appendNode(2.5);
    list.appendNode(7.9);
    list.appendNode(12.6);
    list.insertNode(2.1);
    list.deleteNode(7.9);
    list.displayList();
    cout << "hi" << endl;
    return 0;
}
