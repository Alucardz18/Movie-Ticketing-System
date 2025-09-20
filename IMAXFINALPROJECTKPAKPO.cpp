#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <random>
#include <array>
#include <fstream>
#include "Ticket.h"
#include "Consession.h"

using namespace std;

int main() {

    // Variables
    char answ;
    bool bansw = true;
    const double SALES_TAX_RATE = 0.07;

    // Open the file
    ofstream outputFile;
    
    // Call ticketing function
    string chosenMovie;
    string chosenSeats[30];
    double ticTotal = ticket(outputFile);
    double conTot = concession(outputFile);

    // Calculate the sales tax of ticket bought
    double taxAmount = ticTotal + (ticTotal * SALES_TAX_RATE);

    // Complete loop if customer bought a ticket
    do {
        if (taxAmount > 0) {

            cout << "\n**************************";
            cout << "\nTicket total is $" << fixed << setprecision(2) << ticTotal << endl;
            cout << "Ticket taxed total is $" << taxAmount << endl;
            cout << "\nComplete total is : $" << fixed << setprecision(2) << (taxAmount + conTot) << endl;
        }
        // Give the customer a chance to re-select or not
        else {
            cout << "Snacks can only be purchased after tickets are bought\n";
            cout << "Would you like to buy a ticket? (Y/N): ";
            cin >> answ;
            if (answ == 'y') {
                answ = true;
            }
            system("cls");
        }
    } while (!bansw);

    // Open the file for appending
    outputFile.open("Reciept.txt", std::ofstream::app);

    // file content   
    outputFile << "\n**************************";
    outputFile << "\nTicket total is $" << fixed << setprecision(2) << ticTotal << endl;
    outputFile << "Concession total is: $" << conTot << endl;
    outputFile << "Complete total is : $" << fixed << setprecision(2) << (taxAmount + conTot) << endl;
    outputFile << "\nThank you. Enjoy your time. :)\n" << endl;

    // Close the file
    outputFile.close();
    cout << "Done\n\n";

    return 0;
}


