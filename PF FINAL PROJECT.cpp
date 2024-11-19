#include <iostream>
using namespace std;

struct RideInfo {
    char type;
    int discountAge;
    double discountPercent;
};

double calculateDiscount(int age, const RideInfo &ride) {
    if (age < ride.discountAge) {
        return 0.0;
    } else {
        return ride.discountPercent / 100.0;
    }
}

int main() {
    const int maxfamilies = 100; 

    int totalChargesHistory[maxfamilies];
    int totalSumHistory[maxfamilies];

    int numFamilies = 0; 
    char continueinput;

    do {
        numFamilies++;

        int numPersons, hours = 0, parkingFee = 0;
        int agePerson;
        int sum = 0;
        char swing;

        cout << "\nFamily " << numFamilies << ":" << endl;
        cout << "WELCOME TO JOYLAND WEBSITE!!!!" << endl;
        cout << "DISCOUNTS ON TICKET BOOKING...." << endl;

        cout << "The rates for Discovery ride:" << endl;
        cout << "Children below 10 years are not allowed to sit on Discovery" << endl;
        cout << "Children above the age of 10 years will have a 30% discount" << endl <<endl;
             

        cout << "The rates for Top spin ride:" << endl;
        cout << "Children below 10 years are not allowed to sit on Discovery" << endl;
        cout << "Children above the age of 10 years will have a 15% discount" << endl <<endl;
          cout<<" ticket price : 500" <<endl;  

        cout << "Enter the number of family members" << endl;
        cin >> numPersons;

        RideInfo ride;

        cout << "Enter the number of hours you want to spend in Joyland" << endl;
        cin >> hours;

        parkingFee = 10 * hours;

        cout << "Enter 'd' for Discovery ride and 't' for Top_spin ride" << endl;
        cin >> swing;

        if (swing == 'd' || swing == 'D') {
            ride.type = swing;
            ride.discountAge = 10;
            ride.discountPercent = 30.0;
        } else {
            ride.type = swing;
            ride.discountAge = 10;
            ride.discountPercent = 15.0;
        }

        cout << "Enter the age of each family member:" << endl;
        for (int i = 0; i < numPersons; i++) {
            cout << "Person " << i + 1 << ": ";
            cin >> agePerson;

            double discount = calculateDiscount(agePerson, ride);
            double ticket = 500.0 - (500.0 * discount);
            sum += ticket;

            if (agePerson < ride.discountAge) {
                cout << "Sorry! Person " << i + 1 << " is not allowed to sit on " << ride.type << " ride" << endl;
            } else {
                cout << "Person " << i + 1 << " has " << ride.discountPercent << "% discount" << endl;
            }
        }

        cout << "\nFamily " << numFamilies << " total sum is: " << sum << endl;
        totalSumHistory[numFamilies - 1] = sum;

        int totalCharges = sum + parkingFee;
        cout << "Family " << numFamilies << " total charges are: " << totalCharges << endl;
        totalCharges =totalChargesHistory[numFamilies - 1] ;
        
        cout << "\nDo you want to enter details for another family? (y/n): ";
        cin >> continueinput;

    } while (continueinput == 'y' || continueinput == 'Y');

    
    char showHistory;
    cout << "\nDo you want to see the history? (y/n): ";
    cin >> showHistory;

    if (showHistory == 'y' || showHistory == 'Y') {
        cout << "\n\nhistory  of the day:" << endl;
        for (int i = 0; i < numFamilies; i++) {
            cout << "Family " << i + 1 << " - Total Charges: " << totalChargesHistory[i] << ", Total Sum: " << totalSumHistory[i] << endl;
        }
    }

    return 0;
}
