#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <climits>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

////////////////////////////////////////////
//BEGIN IMPLEMENT
////////////////////////////////////////////

int setRowFormSeat(string str) {
    char* char_array = new char[str.size() + 1];
    strcpy(char_array, str.c_str());
    int row = 0;

    for (int i = 0; i < str.size(); i++) {
        row = row * 26 + (char_array[i] - 'A' + 1);
    }
    delete[] char_array;
    return row;
}

class Position {
private:
    string str_pos;
    int r;
    int c;
public:
    Position(int r = 0, int c = 0) : r(r), c(c) {        // r = 4, c = 5 => str_pos = D5;
        str_pos = char(r - 1 + 'A') + to_string(c);
    }
    Position(const string& str_pos) {                         // D5 => r = 4, c = 5;
        this->str_pos = str_pos;
        string row = "";
        string col = "";
        int s_letter = 0;
        while (isalpha(str_pos[s_letter])) {
            row += toupper(str_pos[s_letter]);
            ++s_letter;
        }
        while (str_pos[s_letter] >= '0' && str_pos[s_letter] <= '9') {
            col += str_pos[s_letter];
            ++s_letter;
        }

        r = setRowFormSeat(row);
        c = stoi(col);
    }
    int getRow() const {
        return r;
    }
    int getCol() const {
        return c;
    }
    string getStr() const {
        return str_pos;
    }
    void setStr(string& str_pos) {
        this->str_pos = str_pos;
        string row = "";
        string col = "";
        int s_letter = 0;
        while (isalpha(str_pos[s_letter])) {
            row += toupper(str_pos[s_letter]);
            ++s_letter;
        }
        while (str_pos[s_letter] >= '0' && str_pos[s_letter] <= '9') {
            col += str_pos[s_letter];
            ++s_letter;
        }
    }
    void setRow(int r) {
        this->r = r;
        str_pos = char(r - 1 + 'A') + to_string(c);
    }
    void setCol(int c) {
        this->c = c;
        str_pos = char(r - 1 + 'A') + to_string(c);
    }
    bool isEqual(Position pos) const {
        int r = pos.getRow();
        int c = pos.getCol();
        return (this->c == c && this->r == r);
    }
};

class RoomTheatre {
private:
    int num_row = 0;
    int num_col = 0;
    bool** seat = nullptr;
public:
    RoomTheatre(int num_row, int num_col) : num_row(num_row), num_col(num_col) {
        seat = new bool* [num_row];
        for (int i = 0; i < num_row; i++) {   // Indexing starts at 0
            seat[i] = new bool[num_col];
            for (int j = 0; j < num_col; j++) {   // Indexing starts at 0
                seat[i][j] = 0;
            }
        }
    }
    ~RoomTheatre() {
        for (int i = 0; i < num_row; i++) {   // Indexing starts at 0
            delete[] seat[i];
        }
        delete[] seat;
        seat = nullptr;
    }
    bool isBook(Position pos) const {
        int i = pos.getRow() - 1;   // Convert 1-based to 0-based index
        int j = pos.getCol() - 1;   // Convert 1-based to 0-based index
        return seat[i][j];
    }
    void Booking(Position pos) {
        int i = pos.getRow() - 1;   // Convert 1-based to 0-based index
        int j = pos.getCol() - 1;   // Convert 1-based to 0-based index
        seat[i][j] = 1;
    }
    void CancelBooking(Position pos) {
        int i = pos.getRow() - 1;   // Convert 1-based to 0-based index
        int j = pos.getCol() - 1;   // Convert 1-based to 0-based index
        seat[i][j] = 0;
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows in the theater: ";
    cin >> rows;
    cout << "Enter the number of columns in the theater: ";
    cin >> cols;

    RoomTheatre theatre(rows, cols);
    char option;

    do {
        cout << "\nMenu:\n";
        cout << "1. Book a seat\n";
        cout << "2. Cancel a booking\n";
        cout << "3. Check if a seat is booked\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        string seatStr;
        switch (option) {
        case '1':
            cout << "Enter the seat to book (e.g., A1): ";
            cin >> seatStr;
            {
                Position pos(seatStr);
                theatre.Booking(pos);
                cout << "Seat " << pos.getStr() << " booked successfully.\n";
            }
            break;
        case '2':
            cout << "Enter the seat to cancel booking (e.g., A1): ";
            cin >> seatStr;
            {
                Position pos(seatStr);
                theatre.CancelBooking(pos);
                cout << "Booking for seat " << pos.getStr() << " cancelled successfully.\n";
            }
            break;
        case '3':
            cout << "Enter the seat to check (e.g., A1): ";
            cin >> seatStr;
            {
                Position pos(seatStr);
                if (theatre.isBook(pos)) {
                    cout << "Seat " << pos.getStr() << " is booked.\n";
                }
                else {
                    cout << "Seat " << pos.getStr() << " is available.\n";
                }
            }
            break;
        case '4':
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    } while (option != '4');

    return 0;
}
