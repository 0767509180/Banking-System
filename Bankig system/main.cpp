

#include <iostream>
#include <string>
#include <map>

using namespace std;

// Structure to represent a user account
struct Account {
    string username;
    string password;
    double balance;
};

// Map to store user accounts with account number as key
map<int, Account> accounts;

// Function to create a new account
void createAccount() {
    int accountNumber;
    cout << "Enter account number: ";
    cin >> accountNumber;

    if (accounts.find(accountNumber) != accounts.end()) {
        cout << "Account already exists." << endl;
        return;
    }

    string username, password;
    double balance = 0.0;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    accounts[accountNumber] = {username, password, balance};
    cout << "Account created successfully." << endl;
}

// Function to login to an existing account
void login() {
    int accountNumber;
    string username, password;

    cout << "Enter account number: ";
    cin >> accountNumber;

    if (accounts.find(accountNumber) == accounts.end()) {
        cout << "Account does not exist." << endl;
        return;
    }

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (accounts[accountNumber].username != username || accounts[accountNumber].password != password) {
        cout << "Invalid username or password." << endl;
        return;
    }

    cout << "Login successful." << endl;

    // Display transaction options
    int choice;
    do {
        cout << "\nTransaction Options:" << endl;
        cout << "1. Deposit money" << endl;
        cout << "2. Withdraw money" << endl;
        cout << "3. Check account balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                accounts[accountNumber].balance += amount;
                cout << "Deposit successful. New balance: " << accounts[accountNumber].balance << endl;
                break;
            }
            case 2: {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;

                if (amount > accounts[accountNumber].balance) {
                    cout << "Insufficient funds." << endl;
                } else {
                    accounts[accountNumber].balance -= amount;
                    cout << "Withdrawal successful. New balance: " << accounts[accountNumber].balance << endl;
                }
                break;
            }
            case 3:
                cout << "Account balance: " << accounts[accountNumber].balance << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}

int main() {
    int choice;
    do {
        cout << "\Banking System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}

