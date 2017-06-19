#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

void showSeats(vector<string> rows){
    cout << setw(25) << right << "Seats" << endl;
    cout << setw(40) << right << "123456789012345678901234567890" << endl;
    for (int i=0; i < rows.size(); i++){
        cout << "Row " << setw(6) << left << i+1 << rows.at(i) << endl;
    }
    return;
}

void updateSeats(vector<string> &rows, int row, int seatNumber){
    rows.at(row-1).at(seatNumber-1) = '*';
    return;
}

bool isAvailable(vector<string> rows, int row, int seatNumber){
    if(rows.at(row-1).at(seatNumber-1) == '#')
        return true;
    return false;
}

void getPrice(vector<double> &price){
    string mystr;
    for (int i=0; i < price.size(); i++){
        cout << "Enter price for row " << i + 1 << " : " << endl;
        getline(cin, mystr);
        stringstream(mystr) >> price.at(i);
    }
    return;
}

void buyTicket(vector<string>& rows, vector<double> price, vector<int>& rowAvailableCount, int& availableCount){
    string mystr;
    int row, seatNumber;
    bool check;
    static double total = 0;
    
    cout << "Please enter the row and seat number you want to purchase: " << endl;
    getline(cin, mystr);
    stringstream(mystr) >> row >> seatNumber;
    if((row > 0 && row <= 15) && (seatNumber > 0 || seatNumber <= 10)){
        check = isAvailable(rows, row, seatNumber);
        if(check){
            updateSeats(rows, row, seatNumber);
            showSeats(rows);
            rowAvailableCount.at(row-1) -= 1;
            availableCount--;
            total += price.at(row-1);
            cout << "Total price: " << total << endl;
        }
        else{
            cout << "The seat you selected is sold out." << endl;
        }
    }
    else
        cout << "The seat you selected is not available." << endl;
    
    return;
    
}

int main(){
    const int NUM_ROWS = 15, NUM_SEATS = 30;
    vector<string> rows(NUM_ROWS, string(NUM_SEATS,'#')); //initialize seats
    vector<double> price(NUM_ROWS);
    int availableCount = NUM_ROWS * NUM_SEATS;
    vector<int> rowAvailableCount(NUM_ROWS, NUM_SEATS);
    bool again = true;
    string mystr;
    int choice;
    
    getPrice(price);
    showSeats(rows);
    
    while (again == true){
        cout << "Please select:" << endl;
        cout << "1 - Buy tickets." << endl;
        cout << "2 - How many seats are available in each row?" << endl;
        cout << "3 - How many seats are available in the entire auditorium?" << endl;
        cout << "4 - Exit program" << endl;
        getline(cin, mystr);
        stringstream(mystr) >> choice;
        switch(choice){
            case 1:
                buyTicket(rows, price, rowAvailableCount, availableCount);
                break;
            case 2:
                for(int i=0; i < NUM_ROWS; i++){
                    cout << "Seats available in Row " << i+1 << ": " << rowAvailableCount.at(i) << endl;
                }
                break;
            case 3:
                cout << "Seats available in the entire auditorium: " << availableCount << endl;
                break;
            case 4:
                again = false;
                break;
        }
    }
    return 0;
}
