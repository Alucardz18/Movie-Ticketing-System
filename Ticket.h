#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <random>
#include <array>
#include <fstream>


using namespace std;

// Global Variables
const int MOVIES = 5;
const int TICKET_MAX = 30;
int quantity;
const int ROW = 5;
const int COL = 6;

//Seating chart
class seatingchart {
private:
    // variables
    int ROW = 5;
    int COLOM = 6;
    char** seats;
    int comp = 30;
    string film;


public:
    // constractor
    seatingchart(int rows, int colm, int availabletic, string movnam) {
        ROW = rows;
        COLOM = colm;
        film = movnam;

        // Allocate memory for the seats array
        seats = new char* [ROW];
        for (int i = 0; i < ROW; i++) {
            seats[i] = new char[COLOM];
        }

        label(availabletic);
    }

    // Destructor to free memory
    ~seatingchart() {
        for (int i = 0; i < ROW; ++i) {
            delete[] seats[i];
        }
        delete[] seats;
    }

    // Label grid based on tickets available
    void label(int ticavail) {
        // whole grid is labeled 'X'
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                seats[i][j] = 'X';
            }
        }

        // create 'O' until the number is equal to tickets available
        for (int i = 0; i < ticavail; i++) {
            int row, col;
            // generate a random 'O' in the seating chat
            do {
                row = rand() % 5;
                col = rand() % 6;
            } while (seats[row][col] == 'O');
            // label the selected seat as 'O'
            seats[row][col] = 'O';
        }

    }

    // display chart
    void displaySeatingChart(string film) {
        // display the chart
        cout << "\n          " << setw(5) << "   " << film;
        cout << "\n               Seating Chart\n";
        cout << "|---------------------------------------|\n";
        // create the column label
        cout << "|\t  ";
        for (int k = 0; k < 6; k++) {
            // Convert to numbers 1, 2, 3, ...
            char colLabel = '1' + k;
            std::cout << setw(2) << colLabel << "   ";
        }

        cout << "|\n";
        cout << "|***************************************|\n";
        // row label & seats
        for (int i = 0; i < ROW; ++i) {
            cout << "| " << "Row " << (i + 1) << "->" << setw(3);
            for (int j = 0; j < COLOM; ++j) {
                char seat = (seats[i][j] == 'O') ? 'O' : 'X';
                cout << seat << setw(5);
            }
            cout << "|\n";
        }
        cout << "|---------------------------------------|\n";
    }



    // user selected seat
    void desiredseat(int row, int col, int numSeat) {
        // convert input into indices
        int rowInd = row - 1;
        int colInd = col - 1;

        for (int i = 0; i < numSeat; ++i) {
            // Check if the selected seat is available
            while (!(rowInd >= 0 && rowInd < ROW && colInd >= 0 && colInd < COL && seats[rowInd][colInd] == 'O')) {
                // unavailable seat
                cout << "Invalid seat selection. Please try again." << endl;

                // new input
                cout << "Re-enter a row and colum: ";
                cin >> row >> col;

                // convert user input to grid indices
                rowInd = row - 1;
                colInd = col - 1;

            }

        }
        // Mark the seat as reserved
        seats[rowInd][colInd] = 'X';
        system("cls");
        cout << "Seat reserved successfully!" << endl;
       
        // Updated chart
        displaySeatingChart(film);
    }

};


// Ticketing 
double ticket(ofstream& outputFile) {
    // Random array generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 30);
    int availableTic[5] = { dist(gen),dist(gen), dist(gen), dist(gen), dist(gen) };

    // variables
    int ticket[MOVIES]{};
    double total = 0.00;
    double cost;
    int choice;
    const int adult = 15;
    const int child = 10;
    const int senior = 7;


    // Movie names array
    string namesMovies[MOVIES] = { "The Dictator", "Grown Ups", "Oppenheimer","The Creator", "Joker" };

    // chart for each movie
    seatingchart* sit[5];
    for (int i = 0; i < MOVIES; ++i) {
        sit[i] = new seatingchart(5, 6, availableTic[i], namesMovies[i]);
    }

    // store selected seats
    string chosenseats[TICKET_MAX];
    string movieName;

    srand(time(0));

    // Greeting message
    cout << "               Welcome to AI Movie Box System Ticketing booth" << endl;
    do {
        // Display movies
        cout << "                                     Movies\n";
        cout << "                                 Select a Movie\n";
        cout << "|*************************************************************************|\n";
        cout << "|1 - " << namesMovies[0] << "..........." << setw(2) << availableTic[0] << " tickets...........Comedy...........R-rated |\n";
        cout << "|2 - " << namesMovies[1] << ".............." << setw(2) << availableTic[1] << " tickets...........Comedy............ PG-13 |\n";
        cout << "|3 - " << namesMovies[2] << "............" << setw(2) << availableTic[2] << " tickets.........Drama/History..... R-rated |\n";
        cout << "|4 - " << namesMovies[3] << "............" << setw(2) << availableTic[3] << " tickets.............Sci-fi.......... PG-13 |\n";
        cout << "|5 - " << namesMovies[4] << "............" << setw(2) << availableTic[4] << " tickets.......Drama/Crime/Thriller....... R-rated|\n";
        cout << "|0 - Exit                                                        " << setw(2) << "         |\n";
        cout << "|*************************************************************************| \n";
        cout << "|  Adult(13- 60 yrs) - $15 | Child (0-10 yrs) - $10| Senior(60+ yrs) - $7 |\n";
        cout << "|*************************************************************************|\n";


        // Selection input
        cout << "\nPlease choose a movie (0 to exit): ";
        cin >> choice;

        if (choice >= 1 && choice <= MOVIES) {
            int movieIndex = choice - 1;

            // User input for the number of people
            if (availableTic[movieIndex] > 0) {
                cout << "\nHow many adults: ";
                int adultQuan;
                cin >> adultQuan;
                cout << "How many children: ";
                int childQuan;
                cin >> childQuan;
                cout << "How many seniors: ";
                int seniorQuan;
                cin >> seniorQuan;

                // display the quantity of tickets bouqht
                quantity = adultQuan + childQuan + seniorQuan;
                cout << quantity << " tickests requested\n";

                // If quantity requested is more than tickets available               
                if (quantity > availableTic[movieIndex]) {
                    system("cls");
                    cout << "There are not enought tickets please reduce the number of people\n";
                }

                // If quantity is <= tickets available
                else {                    
                    cout << "You have successfully purchased: " << quantity << " tickets for \"" << namesMovies[movieIndex] << "\"" << endl;

                    // Cost of selections
                    cost = (adult * adultQuan) + (child * childQuan) + (senior * seniorQuan);

                    cout << "Cost is: $" << fixed << setprecision(2) << cost << endl;

                    // Update available tickets
                    availableTic[movieIndex] -= quantity;

                    // Update cost after every purchase
                    total += cost;

                    // seat selection                   
                    sit[movieIndex]->displaySeatingChart(namesMovies[movieIndex]);
                    movieName = namesMovies[movieIndex];

                    int count = 0;
                    do {
                        // user seat selection
                        int selrow, selcol;
                        cout << "VACANT('O') , OCCUPIED('X')" << endl;
                        cout << "Select desired seat row and column(eg. 1 2, 2 3): ";
                        cin >> selrow >> selcol;                       

                        // desired seat selection
                        sit[movieIndex]->desiredseat(selrow, selcol, quantity);
                        count++;

                        // display chosen seats
                        chosenseats[count - 1] = "Seat " + to_string(selrow) + to_string(selcol);
                    } while (count < quantity);
                    system("cls");

                    // display updated seating chart
                    sit[movieIndex]->displaySeatingChart(namesMovies[movieIndex]);
                    // Print selected seats
                    cout << "Selected seats for " << namesMovies[movieIndex] << ":\n";
                    for (int i = 0; i < count; ++i) {
                        cout << chosenseats[i] << endl;
                    }

                    // Open file for writing
                    outputFile.open("Reciept.txt", ofstream::app);

                    // file contents               
                    outputFile << "Selected seats for " << namesMovies[movieIndex] << ":\n";
                    outputFile << "Price: $" << fixed << setprecision(2) << cost << endl << endl;;
                    for (int i = 0; i < count; ++i) {
                        outputFile << namesMovies[movieIndex] << " \n" << chosenseats[i] << endl;
                        outputFile << "Recipt #: ";
                        int qr[10];
                        for (int i = 0; i < 10; i++) {
                            qr[i] = rand() % 10;
                            outputFile << qr[i];
                        }
                        outputFile << "\nCut here";
                        outputFile << "->>---------\n\n";
                    }

                    // Close the file in the ticket function
                    outputFile.close();
                }
            }

            // if there are no tickets available
            else {
                system("cls");
                cout << "Sorry, this movie is sold out. Please select another movie." << endl;
            }
        }

        // If user decieds to make their own options that's not available
        else if (choice != 0) {
            system("cls");
            cout << "Invalid choice. Please select a valid movie or enter 0 to exit." << endl;
        }
    } while (choice != 0);

    return total;
}