#include <iostream>
#include <vector>
#include <string>
using namespace std;


template<typename T>
class Queue
{
public:
    void enqueue(T);
    T dequeue();
    
private:
    vector<T> elements;
    vector<T> tempElements;
};


template<typename T>
void Queue<T>::enqueue(T value) {
    elements.push_back(value);
}

template<typename T>
T Queue<T>::dequeue() {
    T value;
    
    if(tempElements.empty()){
        while(!elements.empty()) {
            tempElements.push_back(elements.back());
            elements.pop_back();
        }
    }
    value = tempElements.back();
    tempElements.pop_back();
    return value;

}

int main() {
    Queue<int> intQueue;
    int name1 = 1;
    int name2 = 2;
    int name3 = 3;
    int name4 = 4;
    intQueue.enqueue(name1);
    intQueue.enqueue(name2);
    intQueue.enqueue(name3);
    cout << intQueue.dequeue() << endl;
    intQueue.enqueue(name4);
    cout << intQueue.dequeue() << endl;
    cout << intQueue.dequeue() << endl;
    cout << intQueue.dequeue() << endl;



    
}

