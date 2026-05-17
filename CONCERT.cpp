#include <iostream>
#include <string>
using namespace std;

const int maximum_merch = 10;
const int concert_count = 5;

void tickets(int index);
void purchasing(int index);
void receipt(const string& customer, const string& seat, int price, int quantity,
             const string merchNames[maximum_merch], const int merchPrices[maximum_merch],
             const int merchQuantities[maximum_merch], int merchCount,
             const string& concertName);

int availability [concert_count][9] = {

    {0, 3125, 3125, 3125, 3125, 3125, 3125, 3125, 3125}, 
    {0, 3125, 3125, 3125, 3125, 3125, 3125, 3125, 3125},
    {0, 3125, 3125, 3125, 3125, 3125, 3125, 3125, 3125}, 
    {0, 3125, 3125, 3125, 3125, 3125, 3125, 3125, 3125}, 
    {0, 3125, 3125, 3125, 3125, 3125, 3125, 3125, 3125} 
};

string concerts[concert_count] = {

    "2025 LE SSERAFIM TOUR EASY CRAZY HOT IN MANILA - August 2, 2025 (MALL OF ASIA ARENA)",
    "KOSTCON KOREAN OST CONCERT CELEBRATE AND SHARE THE LOVE FOR K-DRAMA - August 6, 2025 (MALL OF ASIA ARENA)",
    "G-FORCE PROJECT 2025 - June 11, 2025 (MALL OF ASIA ARENA)",
    "PLANETSHAKERS - July 23 - 27, 2025 (MALL OF ASIA ARENA)",
    "HILLSONG (CXMMXNS MIGHTY TO SAVE TOUR) - June 7 - 8, 2025 (MALL OF ASIA ARENA)"
};

string merchandises [] = { "Lightstick", "Shirt", "Poster", "Photocard Set", "Bible Verse Sticker" };
int merch_prices [] = { 1500, 1000, 500, 750, 300 };

bool merchCategories [concert_count][5] = {

    {true, true, true, true, false},   
    {true, true, true, true, false},  
    {true, true, true, true, false},
    {false, false, true, false, true},   
    {false, false, true, false, true} 

};


int main() {
    
    int choices_artists;

    while (true) {

        cout << "========================================================================\n";
        cout << "*                                                                      *\n";
        cout << "*                 WELCOME TO ONLINE SM TICKET BUYING                   *\n";
        cout << "*                                                                      *\n";
        cout << "========================================================================\n";
        cout << "\n\n";
        cout << "Upcoming Events & Concerts:\n";

        for (int i = 0; i < concert_count; i++) {
            cout << i + 1 << ". " << concerts[i] << "\n";
        }

        cout << "6. Exit\n";
        cout << "Select a concert by number: ";
        cin >> choices_artists;
        cin.ignore();

        if (choices_artists == 6) {
            cout << "Thank you for visiting! Have a great day!\n";
            break;
        }
        else if (choices_artists < 1 || choices_artists > concert_count) {
            cout << "Invalid choice, please try again.\n";
            continue;
        }

        purchasing(choices_artists - 1);
    }

    return 0;
}

void tickets(int index) {

    string seatNames[] = {
        "Unused",
        "Floor Standing", "LBA Premium", "LBA Regular", "LBB Premium",
        "LBB Regular", "UBA", "Lower UBB", "Upper UBB"
    };

    int seatPrices[] = {
        0, 13750, 12000, 11150, 10500,
        9500, 7500, 5750, 3750
    };

    cout << "\nTicket Prices and Seat Availability for:\n" << concerts[index] << "\n";
    cout << "-----------------------------------------------------\n";
    for (int i = 1; i <= 8; ++i) {
        cout << i << ". " << seatNames[i] << " - " << seatPrices[i] << " PHP"
             << " (Available: " << availability [index][i] << ")\n";
    }
}

void purchasing(int index) {
    int ticketChoice, ticketQuantity;
    string seat, customer;
    string boughtMerch[maximum_merch];
    int merchCosts[maximum_merch];
    int merchQuantities[maximum_merch];
    int merchCount = 0;

    tickets(index);

    cout << "\nEnter your full name: ";
    getline(cin, customer);

    cout << "Enter the number of the ticket you want to buy: ";
    cin >> ticketChoice;
    cout << "Enter the quantity of tickets you want to buy: ";
    cin >> ticketQuantity;
    cin.ignore();

    if (ticketChoice < 1 || ticketChoice > 8) {
        cout << "Invalid ticket choice. Please try again.\n";
        return;
    }

    if (ticketQuantity > availability [index][ticketChoice]) {
        cout << "Not enough tickets available. Only " << availability [index][ticketChoice] << " left.\n";
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

    seat = seatNames[ticketChoice];
    int price = seatPrices[ticketChoice];
    availability [index][ticketChoice] -= ticketQuantity;

    cout << "\nDo you want to buy merchandise? (y/n): ";
    char merchChoice;
    cin >> merchChoice;
    cin.ignore();

    if (merchChoice == 'y' || merchChoice == 'Y') {
        bool buying = true;
        while (buying) {
            cout << "\nAvailable Merchandise:\n";
            for (int i = 0; i < 5; ++i) {
                if (merchCategories [index][i]) {
                    cout << i + 1 << ". " << merchandises [i] << " - " << merch_prices [i] << " PHP\n";
                }
            }

            int merchId, merch_quantity;
            cout << "Enter the merchandise number you want to buy: ";
            cin >> merchId;
            cin.ignore();

            if (merchId < 1 || merchId > 5 || !merchCategories [index][merchId - 1]) {
                cout << "Invalid merch option or not available for this concert.\n";
                continue;
            }

            cout << "Enter quantity: ";
            cin >> merch_quantity;
            cin.ignore();

            if (merchCount >= maximum_merch) {
                cout << "Maximum merchandise items reached.\n";
                break;
            }

            boughtMerch[merchCount] = merchandises [merchId - 1];
            merchCosts[merchCount] = merch_prices [merchId - 1];
            merchQuantities[merchCount] = merch_quantity;
            merchCount++;

            cout << "Add more merch? (y/n): ";
            char more;
            cin >> more;
            cin.ignore();
            buying = (more == 'y' || more == 'Y');
        }
    }

    receipt(customer, seat, price, ticketQuantity, boughtMerch, merchCosts, merchQuantities, merchCount, concerts[index]);
}

void receipt(const string& customer, const string& seat, int price, int quantity,
             const string merchNames[maximum_merch], const int merchPrices[maximum_merch],
             const int merchQuantities[maximum_merch], int merchCount,
             const string& concertName) {

    int totalTickets = price * quantity;
    int totalMerch = 0;

    for (int i = 0; i < merchCount; ++i) {
        totalMerch += merchPrices[i] * merchQuantities[i];
    }

    int grandTotal_price = totalTickets + totalMerch;

    cout << "\n\n===== RECEIPT =====\n";
    cout << "Customer Name: " << customer << "\n";
    cout << "Ticket Type: " << seat << "\n";
    cout << "Price per Ticket: " << price << " PHP\n";
    cout << "Quantity: " << quantity << "\n";
    cout << "Ticket Total: " << totalTickets << " PHP\n";

    if (merchCount > 0) {
        cout << "\n--- Merchandise Purchased ---\n";
        for (int i = 0; i < merchCount; ++i) {
            cout << merchNames[i] << " x" << merchQuantities[i]
                 << " = " << merchPrices[i] * merchQuantities[i] << " PHP\n";
        }
        cout << "Merchandise Total: " << totalMerch << " PHP\n";
    }

    cout << "\nGRAND TOTAL: " << grandTotal_price << " PHP\n";
    cout << "WE ARE EXCITED TO SEE YOU! GET READY TO TAKE A CHANCE WITH " << concertName << "!\n";
    cout << "===============================\n";
}
