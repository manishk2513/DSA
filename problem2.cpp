#include <iostream>
#include <string>
#include <limits>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    long accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string name, long accNum, double initialBalance = 0.0) {
        accountHolderName = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount " << amount << " deposited successfully." << endl;
        } else {
            cout << "Invalid amount for deposit!" << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount " << amount << " withdrawn successfully." << endl;
        } else if (amount <= 0) {
            cout << "Invalid amount for withdrawal!" << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    // Function to display account details
    void displayDetails() {
        cout << "\n----- Account Details -----" << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    string name;
    long accountNum;
    double initialBalance;
    
    // Get account details from user
    cout << "Enter Account Holder Name: ";
    getline(cin, name);
    
    while(true) {
        cout << "Enter Account Number: ";
        if(cin >> accountNum) {
            if(accountNum > 0) break;
            cout << "Account number must be positive!" << endl;
        } else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    while(true) {
        cout << "Enter Initial Balance: $";
        if(cin >> initialBalance) {
            if(initialBalance >= 0) break;
            cout << "Initial balance cannot be negative!" << endl;
        } else {
            cout << "Invalid input! Please enter a valid amount." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    // Create account with user input
    BankAccount account(name, accountNum, initialBalance);
    
    // Display initial account details
    cout << "\nAccount created successfully!" << endl;
    account.displayDetails();
    
    int choice;
    double amount;
    
    do {
        cout << "\n=== Banking Operations ===" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Display Account Details" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        
        // Input validation for choice
        if(!(cin >> choice)) {
            cout << "Invalid input! Please enter a number between 1 and 4." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        if(choice < 1 || choice > 4) {
            cout << "\nInvalid choice! Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch(choice) {
            case 1:
                while(true) {
                    cout << "Enter amount to deposit: $";
                    if(cin >> amount) {
                        if(amount > 0) {
                            account.deposit(amount);
                            break;
                        }
                        cout << "Amount must be positive!" << endl;
                    } else {
                        cout << "Invalid input! Please enter a valid amount." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                break;
                
            case 2:
                while(true) {
                    cout << "Enter amount to withdraw: $";
                    if(cin >> amount) {
                        if(amount > 0) {
                            account.withdraw(amount);
                            break;
                        }
                        cout << "Amount must be positive!" << endl;
                    } else {
                        cout << "Invalid input! Please enter a valid amount." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                break;
                
            case 3:
                account.displayDetails();
                break;
                
            case 4:
                cout << "\nThank you for using our banking system!" << endl;
                break;
        }
    } while(choice != 4);

    return 0;
}
