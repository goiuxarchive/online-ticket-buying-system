#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void tickets();
void purchasing();
void receipt(const string& customer, const string& seat, int price, int quantity,
             const vector<string>& boughtMerch, const vector<int>& merchPrices,
             const vector<int>& merchQuantities); 

int seatAvailability [9] = {0, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500};

string merchNames [] = {
    
    "Lightstick", "Shirt", "Poster", "Photocard Set"

};

int merchPrice [] = {

    1500, 500, 500, 700

};

int main() {

    int choice;
    while (true) {

        cout << "\n\n";
        cout << "****************************************************\n";
        cout << "*                                                  *\n";
        cout << "*                      NIKI                        *\n";
        cout << "*                                                  *\n";
        cout << "****************************************************\n";
        cout << "\n\n";
        cout << "NIKI: BUZZ WORLD TOUR Concert Ticket Buying System\n";
        cout << "February 11, 2025\n";
        cout << "MALL OF ASIA ARENA\n";
        cout << "=============================\n";
        cout << "Choose an option.\n";
        cout << "1. Buy\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                purchasing ();
                break;
            case 2:
                cout << "Thank you and have a great day!\n";
                return 0;
            default:
                cout << "TRY AGAIN\n";
        }
    }
}


void tickets() {

    cout << "\nTicket Prices and Seat Availability:\n";
    cout << "------------------------------------\n";
    cout << "1. Floor Standing - 13,750PHP (Available: " << seatAvailability[1] << ")\n";
    cout << "2. LBA Premium    - 12,000PHP (Available: " << seatAvailability[2] << ")\n";
    cout << "3. LBA Regular    - 11,150PHP (Available: " << seatAvailability[3] << ")\n";
    cout << "4. LBB Premium    - 10,500PHP (Available: " << seatAvailability[4] << ")\n";
    cout << "5. LBB Regular    - 9,500PHP  (Available: " << seatAvailability[5] << ")\n";
    cout << "6. UBA            - 7,500PHP  (Available: " << seatAvailability[6] << ")\n";
    cout << "7. Lower UBB      - 5,750PHP  (Available: " << seatAvailability[7] << ")\n";
    cout << "8. Upper UBB      - 3,750PHP  (Available: " << seatAvailability[8] << ")\n";

}


int seatPrices[] = {
        0, 13750, 12000, 11150, 10500,
        9500, 7500, 5750, 3750
    };

    cout << "\nTicket Prices and Seat Availability:\n";
    cout << "------------------------------------\n";
    for (int i = 1; i <= 8; ++i) {
        cout << i << ". " << seatNames[i] << " - " << seatPrices[i] << "PHP"
             << " (Available: " << seatAvailability[i] << ")\n";
    }

void purchasing() {

    int choices, quantity, price;
    string seat, customer;

    vector<string> boughtMerch;
    vector<int> merchCosts;
    vector<int> merchQuantities;

    tickets();

    cout << "\nEnter your full name: ";
    getline(cin, customer);
    cout << "Enter the number of the ticket you want to buy: ";
    cin >> choices;
    cout << "Enter the quantity of tickets you want to buy: ";
    cin >> quantity;

    if (choices < 1 || choices > 8 ) {
        cout << "Invalid ticket choice. Please try again.\n";
        return;
    }

}
