#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <random>
#include <array>
#include <fstream>
using namespace std;

// Global variables
const double SALES_TAX_RATE = 0.07;
double runningTotal = 0.0;
int extra;
double total;
double price = 0.00;


// Concession 
double candytyp() {
    // Clear screen
    system("cls");

    // Select candy
    cout << "                   Candy\n";
    cout << "         Select a candy of choice\n";
    cout << "|*****************************************|\n";
    cout << "|1 - M&M's ....................... $ 5.99 |\n";
    cout << "|2 - Twizzlers ................... $ 6.99 |\n";
    cout << "|3 - Skinny Dipped Almonds ....... $ 6.00 |\n";
    cout << "|4 - Tru Fru ..................... $ 6.79 |\n";
    cout << "|_________________________________________|\n\n";

    // User selection
    cout << "Enter your selection: ";
    cin >> extra;

    if (extra == 1) {
        cout << "M&M's: ";
        price = 5.99;
        cout << "$" << price << endl;

    }
    else if (extra == 2) {
        cout << "Twizzlers: ";
        price = 6.99;
        cout << "$" << price << endl;

    }
    else if (extra == 3) {
        cout << "Skinny Dipped Almonds: ";
        price = 6.00;
        cout << "$" << price << endl;

    }
    else if (extra == 4) {
        cout << "Tru Fru: ";
        price = 6.79;
        cout << "$" << price << endl;

    }
    else {
        // If user inputs unkown selection
        cout << "Invalid\n";
        price = 0.00;
    }
    return price;
}

double popsub() {
    // Clear screen
    system("cls");
    // Select topping
    cout << "                Popcorn\n";
    cout << "           Select a flavor\n";
    cout << "|*************************************|\n";
    cout << "|1 - Cinnamon Sugar .......... $ 0.95 |\n";
    cout << "|2 - Buffalo ................. $ 0.99 |\n";
    cout << "|3 - Seafood Seasoning ....... $ 0.95 |\n";
    cout << "|4 - Chocolate ............... $ 0.50 |\n";
    cout << "|5 - Original ................ $ 0.00 |\n";
    cout << "|_____________________________________|\n\n";
    // Popcorn's original price
    double foodPrice = 10.95;

    // User selection
    cout << "Enter your selection: ";
    cin >> extra;

    if (extra == 1) {
        cout << "Cinnamon Sugar: ";
        price = 0.95;
        // Add & display topping price to popcorn
        total = foodPrice + price;
        cout << "$" << total << endl;
    }
    else if (extra == 2) {
        cout << "Buffalo: ";
        price = 0.99;
        // Add & display topping price to popcorn
        total = foodPrice + price;
        cout << "$" << total << endl;
    }
    else if (extra == 3) {
        cout << "Seafood Seasoning: ";
        price = 0.95;
        // Add & display topping price to popcorn
        total = foodPrice + price;
        cout << "$" << total << endl;
    }
    else if (extra == 4) {
        cout << "Chocolate: ";
        price = 0.50;
        // Add & display topping price to popcorn
        total = foodPrice + price;
        cout << "$" << total << endl;
    }
    else if (extra == 5) {
        cout << "Original: ";
        price = 0.00;
        // Add & display topping price to popcorn
        total = foodPrice + price;
        cout << "$" << total << endl;
    }
    else {
        // If user inputs unkown selection
        cout << "Invalid\n";
        price = 0.00;
    }
    return total;
}

double drinkop() {
    // Clear screen
    system("cls");
    // Select topping
    cout << "                 Drinks\n";
    cout << "             Select a Drink            \n";
    cout << "|**************************************|\n";
    cout << "|1 - Coca Cola (2L) ........... $ 3.95 |\n";
    cout << "|2 - Lemonade (2L) ............ $ 2.99 |\n";
    cout << "|3 - Dr. Pepper (2L) .......... $ 2.95 |\n";
    cout << "|4 - Water .....................$ 2.90 |\n";
    cout << "|______________________________________|\n\n";

    // User selection input
    cout << "Enter a selection: ";
    cin >> extra;

    if (extra == 1) {
        cout << "Coca Cola (2L): ";
        price = 3.95;
        cout << "$" << price << endl;
    }
    else if (extra == 2) {
        cout << "Lemonade: ";
        price = 2.99;
        cout << "$" << price << endl;
    }
    else if (extra == 3) {
        cout << "Dr. Pepper: ";
        price = 2.95;
        cout << "$" << price << endl;
    }
    else if (extra == 4) {
        cout << "Water: ";
        price = 2.90;
        cout << "$" << price << endl;
    }
    else {
        // If user inputs unkown selection
        cout << "Invalid\n";
        price = 0.00;
    }
    return price;
}

double hotDsub() {
    // Clear screen
    system("cls");
    // Select condiment
    cout << "                 Hot Dogs\n";
    cout << "             Select a condiment\n";
    cout << "|******************************************|\n";
    cout << "|1 - Chilli ....................... $ 2.95 |\n";
    cout << "|2 - Ketchup ...................... $ 1.99 |\n";
    cout << "|3 - BBQ Sauce .................... $ 2.00 |\n";
    cout << "|4 - Thousand Island Dressing ..... $ 2.50 |\n";
    cout << "|5 - Sriracha-Mayo ................ $ 2.00 |\n";
    cout << "|__________________________________________|\n\n";
    // Hot Dogs original price
    double foodPrice = 10.99;

    // User selection
    cout << "Enter your selection: ";
    cin >> extra;

    if (extra == 1) {
        cout << "Chilli: ";
        price = 2.95;
        // Add & display condiment
        total = foodPrice + price;
        cout << "$" << total << endl;
    }
    else if (extra == 2) {
        cout << "Ketchup: ";
        price = 1.99;
        // Add & display condiment
        total = foodPrice + price;
        cout << "$" << total << endl;
    }
    else if (extra == 3) {
        cout << "BBQ Sauce: ";
        price = 2.00;
        // Add & display condiment
        total = foodPrice + price;
        cout << "$" << total << endl;
    }
    else if (extra == 4) {
        cout << "Thousand Island Dressing: ";
        price = 2.50;
        // Add & display condiment
        total = foodPrice + price;
        cout << "$" << total << endl;
    }
    else if (extra == 5) {
        cout << "Sriracha-Mayo: ";
        price = 2.00;
        // Add & display condiment
        total = foodPrice + price;
        cout << "$" << total << endl;
    }
    else {
        // If user inputs unkown selection
        cout << "Invalid\n";
        price = 0.00;
    }
    return total;
}

double concession(ofstream& outputFile) {
    // Variables
    bool end = true;
    string selectedItems = "";

    do {
        // Clear screen
        system("cls");
        // Greetings
        cout << "Welcome to AI Movie Box System Concessions" << endl;
        // Display concession choices
        cout << "      Select an option of choice\n";
        cout << "|************************************|\n";
        cout << "|1 - Popcorn ................ $10.95 |\n";
        cout << "|2 - Candy .................. Varies |\n";
        cout << "|3 - Drinks ................. Varies |\n";
        cout << "|4 - Hot Dogs ............... $10.99 |\n";
        cout << "|5 - Chocolate Cookies ...... $12.00 |\n";
        cout << "|____________________________________|\n\n";

        // Prompt user to input a choice.
        int choice;
        cout << "Enter selection: ";
        cin >> choice;

        // Variables        
        double itemPrice = 0.00;
        string itemName;

        switch (choice) {
        case 1:
            itemName = "Popcorn";
            itemPrice = popsub();
            break;
        case 2:
            itemName = "Candy";
            itemPrice = candytyp();
            break;
        case 3:
            itemName = "Drink";
            itemPrice = drinkop();
            break;
        case 4:
            itemName = "Hot Dogs";
            itemPrice = hotDsub();
            break;
        case 5:
            itemName = "Cookies";
            itemPrice = 10.90;
            system("cls");
            cout << itemName << ": ";
            cout << "$" << itemPrice << endl;
            break;

            // User input is wrong
        default:
            cout << "Invalid choice. Please select a valid item." << endl;
            // Restart the loop for an invalid choice
            continue;
        }

        if (itemPrice != 0.00) {
            // Getting the amount selected from the user
            int quantity;
            cout << "Enter the quantity: ";
            cin >> quantity;
            // Adding the current selection + the quantity
            double subtotal = itemPrice * quantity;
            runningTotal += subtotal;


            cout << itemName << " x" << quantity << ": $" << fixed << setprecision(2) << subtotal << endl;
            cout << subtotal;
            selectedItems += itemName + " x" + to_string(quantity) + ": $" + to_string(subtotal) + "\n";
        }

        cout.precision(2);
        // Display selected items and balance
        cout << "\nSelected Items:\n" << fixed << selectedItems;
        cout << "**********************************\n";
        cout << "Balance: $" << fixed << setprecision(2) << runningTotal << endl;

        // Ask if the user wants to continue
        char answ;
        cout << "\nDo you want to proceed to checkout?\n";
        cout << "Enter y(yes) to checkout and n(no) to keep selecting: ";
        cin >> answ;

        // Ending the selection to checkout
        if (answ == 'y') {
            end = false;
        }
    } while (end);

    // Clear screen 
    system("cls");
    // Calculating the total amount and the tax amount
    double taxAmount = runningTotal * SALES_TAX_RATE;
    double totalAmount = runningTotal + taxAmount;

    // Diplay selected items
    cout << "Selected Items:\n" << selectedItems << endl;
    cout << "******************************\n";

    // Display the result to the user
    cout << "Subtotal: $" << fixed << setprecision(2) << runningTotal << endl;
    cout << "Sales Tax (" << SALES_TAX_RATE * 100 << "%): $" << fixed << setprecision(2) << taxAmount << endl;
    cout << "Total: $" << fixed << setprecision(2) << totalAmount << endl;

    cout << "\nThank you for your order!" << endl;

    // Open file for writing
    outputFile.open("Reciept.txt", ofstream::app);

    // file contents 
    outputFile << "*****************\n";
    outputFile << "Selected Items:\n" << selectedItems << endl;

    // Close the file in the ticket function
    outputFile.close();

    return totalAmount;
}