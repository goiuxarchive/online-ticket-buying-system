#include <iostream>
#include <string>

using namespace std;

const int MAX_MERCH = 10;

void tickets(int concertIndex);
void purchasing(int concertIndex);
void receipt(const string& customer, const string& seat, int price, int quantity,
             const string merchNames[MAX_MERCH], const int merchPrices[MAX_MERCH],
             const int merchQuantities[MAX_MERCH], int merchCount,
             const string& concertName);


int seatAvailability[9] = {0, 100, 100, 100, 100, 100, 100, 100, 100};

string merchNames[] = {
    "Lightstick", "Shirt", "Poster", "Photocard Set", "Bible Verse Sticker"
};
int merchPrices[] = {
    1500, 1000, 500, 750, 300
};

struct Concert {
    string name;
    string date;
    string venue;
    string merchAllowed[5];
    int merchCount;
};

Concert concerts[] = {
    {"LE SSERAFIM TOUR EASY CRAZY HOT IN MANILA", "August 2, 2025", "MALL OF ASIA ARENA", {"Lightstick", "Shirt", "Poster", "Photocard Set", "Bible Verse Sticker"}, 5},
    {"KOSTCON KOREAN OST CONCERT CELEBRATE AND SHARE THE LOVE FOR K-DRAMA", "August 6, 2025", "MALL OF ASIA ARENA", {"Lightstick", "Shirt", "Poster", "Photocard Set", "Bible Verse Sticker"}, 5},
    {"G-FORCE PROJECT 2025", "June 11, 2025", "MALL OF ASIA ARENA", {"Lightstick", "Shirt", "Poster", "Photocard Set", "Bible Verse Sticker"}, 5},
    {"PLANETSHAKERS", "July 23 - 27, 2025", "MALL OF ASIA ARENA", {"Poster", "Bible Verse Sticker"}, 2},
    {"HILLSONG (CXMMXNS MIGHTY TO SAVE TOUR)", "June 7 - 8, 2025", "MALL OF ASIA ARENA", {"Poster", "Bible Verse Sticker"}, 2}
};

int main() {
    int choice;

    while (true) {
        cout << "\n\n****************************************************\n";
        cout << "*                  CONCERTS LIST                    *\n";
        cout << "****************************************************\n";
        for (int i = 0; i < 5; ++i) {
            cout << i+1 << ". " << concerts[i].name << " - " << concerts[i].date
                 << " (" << concerts[i].venue << ")\n";
        }
        cout << "6. Exit\n";
        cout << "Choose a concert (1-6): ";
        cin >> choice;
        cin.ignore();

        if (choice >=1 && choice <=5) {
            purchasing(choice - 1);
        } else if (choice == 6) {
            cout << "Thank you and have a great day!\n";
            break;
        } else {
            cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}

void tickets() {
    string seatNames[] = {
        "Unused",
        "Floor Standing", "LBA Premium", "LBA Regular", "LBB Premium",
        "LBB Regular", "UBA", "Lower UBB", "Upper UBB"
    };

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
}

void purchasing(int concertIndex) {
    int choices, quantity, price;
    string seat, customer;

    string boughtMerch[MAX_MERCH];
    int merchCosts[MAX_MERCH];
    int merchQuantities[MAX_MERCH];
    int merchCount = 0;

    tickets();

    cout << "\nEnter your full name: ";
    getline(cin, customer);

    cout << "Enter the number of the ticket you want to buy: ";
    cin >> choices;
    cout << "Enter the quantity of tickets you want to buy: ";
    cin >> quantity;

    if (choices < 1 || choices > 8 ){
        cout << "Invalid ticket choice. Please try again.\n";
        return;
    }

    if (quantity > seatAvailability[choices]) {
        cout << "Not enough tickets available. Only " << seatAvailability[choices] << " left.\n";
        return;
    }

    string seatNames[] = {
        "Unused",
        "Floor Standing", "LBA Premium", "LBA Regular", "LBB Premium",
        "LBB Regular", "UBA", "Lower UBB", "Upper UBB"
    };

    int seatPrices[] = {
        0, 13750, 12000, 11150, 10500,
        9500, 7500, 5750, 3750
    };

    seat = seatNames[choices];
    price = seatPrices[choices];
    seatAvailability[choices] -= quantity;

    cout << "\nDo you want to buy merchandise? (y/n): ";
    char merchChoice;
    cin >> merchChoice;

    if (merchChoice == 'y' || merchChoice == 'Y') {
        bool buying = true;
        while (buying && merchCount < MAX_MERCH) {
            cout << "\nAvailable Merchandise:\n";
            for (int i = 0; i < concerts[concertIndex].merchCount; ++i) {
                int merchId = -1;
                for (int j = 0; j < 5; ++j) {
                    if (concerts[concertIndex].merchAllowed[i] == merchNames[j]) {
                        merchId = j;
                        break;
                    }
                }
                if (merchId != -1) {
                    cout << (i+1) << ". " << merchNames[merchId] << " - " << merchPrices[merchId] << "PHP\n";
                }
            }

            int merchId, merchQty;
            cout << "Enter the merchandise number you want to buy: ";
            cin >> merchId;

            if (merchId < 1 || merchId > concerts[concertIndex].merchCount) {
                cout << "Invalid merch option.\n";
                continue;
            }

            cout << "Enter quantity: ";
            cin >> merchQty;

            string selectedMerch = concerts[concertIndex].merchAllowed[merchId-1];
        
            int selectedPrice = 0;
            for (int j = 0; j < 5; ++j) {
                if (merchNames[j] == selectedMerch) {
                    selectedPrice = merchPrices[j];
                    break;
                }
            }

            boughtMerch[merchCount] = selectedMerch;
            merchCosts[merchCount] = selectedPrice;
            merchQuantities[merchCount] = merchQty;
            merchCount++;

            cout << "Add more merch? (y/n): ";
            char more;
            cin >> more;
            buying = (more == 'y' || more == 'Y');
        }
    }

    receipt(customer, seat, price, quantity, boughtMerch, merchCosts, merchQuantities, merchCount, concerts[concertIndex]);
}

void receipt(const string& customer, const string& seat, int price, int quantity,
             string boughtMerch[], int merchPrices[], int merchQuantities[], int merchCount) {
    
    int totalTickets = price * quantity;
    int totalMerch = 0;

    for (int i = 0; i < merchCount; ++i) {
        totalMerch += merchPrices[i] * merchQuantities[i];
    }

    int grandTotal = totalTickets + totalMerch;

    cout << "\n\n===== RECEIPT =====\n";
    cout << "Customer Name: " << customer << "\n";
    cout << "Ticket Type: " << seat << "\n";
    cout << "Price per Ticket: " << price << "PHP\n";
    cout << "Quantity: " << quantity << "\n";
    cout << "Ticket Total: " << totalTickets << "PHP\n";

    if (merchCount > 0) {
        cout << "\n--- Merchandise Purchased ---\n";
        for (int i = 0; i < merchCount; ++i) {
            cout << boughtMerch[i] << " x" << merchQuantities[i]
                 << " = " << merchPrices[i] * merchQuantities[i] << "PHP\n";
        }
        cout << "Merch Total: " << totalMerch << "PHP\n";
    }

    cout << "\nGRAND TOTAL: " << grandTotal << "PHP\n";
    cout << "Date: February 11, 2025\n";
    cout << "\nWE ARE EXCITED TO SEE YOU! GET READY TO TAKE A CHANCE WITH " << concertName << "!\n";
    cout << "===============================\n";
}
