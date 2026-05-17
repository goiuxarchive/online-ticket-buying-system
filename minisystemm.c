#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void tickets();
void purchasing();
void receipt(const string& type, int price, int quantity);

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

        switch (choice) {
            case 1:
                purchasing();
                break;
            case 2:
                cout << "Thank you and have a great day!\n";
                return 0;
            default:
                cout << "TRY AGAIN\n";
        }
    }

    return 0;
}

void tickets() {
    cout << "Ticket Prices and Seats:\n";
    cout << "1. Floor Standing - 13,750PHP\n";
    cout << "2. LBA Premium - 12,000PHP\n";
    cout << "3. LBA Regular - 11,150PHP\n";
    cout << "4. LBB Premium - 10,500PHP\n";
    cout << "5. LBB Regular - 9,500PHP\n";
    cout << "6. UBA - 7,500PHP\n";
    cout << "7. Lower UBB - 5,750PHP\n";
    cout << "8. Upper UBB - 3,750PHP\n";
}

void purchasing() {
    int choices, quantity, price;
    string seat;

    tickets();

    cout << "Enter the number of the ticket you want to buy: ";
    cin >> choices;
    cout << "Enter the quantity of tickets you want to buy: ";
    cin >> quantity;

    switch (choices) {
        case 1: seat = "Floor Standing"; price = 13750; break;
        case 2: seat = "LBA Premium"; price = 12000; break;
        case 3: seat = "LBA Regular"; price = 11150; break;
        case 4: seat = "LBB Premium"; price = 10500; break;
        case 5: seat = "LBB Regular"; price = 9500; break;
        case 6: seat = "UBA"; price = 7500; break;
        case 7: seat = "Lower UBB"; price = 5750; break;
        case 8: seat = "Upper UBB"; price = 3750; break;
        default:
            cout << "Invalid ticket choice. Please try again.\n";
            return;
    }

    cout << "You have selected " << quantity << " tickets for a total price of " << price * quantity << "PHP.\n";
    receipt(seat, price, quantity);
}

void receipt(const string& seat, int price, int quantity) {
    ofstream fptr("receipt.txt");

    if (!fptr) {
        cout << "Error opening file!\n";
        return;
    }

    fptr << "NIKI: BUZZ WORLD TOUR Concert Ticket Receipt\n";
    fptr << "Ticket Type: " << seat << "\n";
    fptr << "Price per Ticket: " << price << "PHP\n";
    fptr << "Quantity: " << quantity << "\n";
    fptr << "Total Price: " << price * quantity << "PHP\n";
    fptr << "Date: February 11, 2025\n";
    fptr << "WE ARE EXCITED TO SEE YOU! GET READY TO TAKE A CHANCE WITH NIKI BUZZ WORLD TOUR!\n";
    fptr << "\n\n";
    fptr << "****************************************************\n";
    fptr << "*                                                  *\n";
    fptr << "*                      NIKI                        *\n";
    fptr << "*                                                  *\n";
    fptr << "****************************************************\n";
    fptr << "\n\n";
    fptr.close();

    cout << "Receipt generated and saved to receipt.txt\n";
}
