//
//  NumberList.h
//  NumberList
//
//  Created by Cindy Lee on 4/11/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//

#ifndef NumberList_h
#define NumberList_h

class NumberList
{
public:
    NumberList()
    {head = nullptr;}
    
    void appendNode(double);
    void insertNode(double);
    void deleteNode(double);
    void displayList() const;
    
private:
    struct ListNode
    {
        double value;
        struct ListNode* next;
    };
    
    ListNode* head;
};

#endif /* NumberList_h */
