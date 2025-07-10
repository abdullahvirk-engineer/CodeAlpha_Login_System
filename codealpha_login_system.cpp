#include <iostream>
#include <fstream>     // for file operations
#include <string>
using namespace std;

// Function to check if username already exists
bool userExists(const string& username) {
    ifstream file("users.txt");
    string storedUser, storedPass;
    while (file >> storedUser >> storedPass) {
        if (storedUser == username) {
            return true; // duplicate user
        }
    }
    return false;
}

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "\n--- Registration ---\n";
    cout << "Enter username: ";
    cin >> username;

    // Check if user already exists
    if (userExists(username)) {
        cout << "Username already exists! Try another one.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    // Save to file
    ofstream file("users.txt", ios::app); // append mode
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

// Function to login
void loginUser() {
    string username, password;
    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string storedUser, storedPass;
    bool found = false;

    while (file >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Login successful! Welcome, " << username << ".\n";
    }
    else {
        cout << "Invalid username or password.\n";
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n=== Welcome to Login System ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
