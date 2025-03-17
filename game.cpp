#include <iostream>
using namespace std;

int main() {
    int size;

    // Ask the user for the size of the square
    cout << "Enter the size of the square: ";
    cin >> size;

    // Loop to print the square
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << "* ";
        }
        cout << endl; // Move to the next line after each row
    }

    return 0;
}
