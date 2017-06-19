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

void NumberList::appendNode(double num){
    ListNode* newNode;
    ListNode* nodePtr;
    
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;
    
    if(!head){
        head = newNode;
    }
    else{
        nodePtr = head;
        
        while(nodePtr->next)
            nodePtr = nodePtr->next;
        
        nodePtr->next = newNode;
    }
}

void NumberList::displayList() const{
    ListNode* nodePtr;
    
    nodePtr = head;
    
    while(nodePtr){
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
}

void NumberList::insertNode(double num){
    ListNode* newNode;
    ListNode* nodePtr;
    ListNode* previousNode = nullptr;
    
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;
    
    if(!head){
        head = newNode;
    }
    else{
        nodePtr = head;
        
        while(nodePtr->value < num){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        if(previousNode == nullptr){
            head = newNode;
            newNode->next = nodePtr;
        }
        else{
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
    
}

void NumberList::deleteNode(double num){
    ListNode* previousNode;
    ListNode* nodePtr;
    
    if(!head)
        return;
    
    if(head->value == num){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else{
        nodePtr = head;
        while(nodePtr != nullptr && nodePtr->value != num){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr->value == num){
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
    
}
