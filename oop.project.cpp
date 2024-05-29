#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Expense {
private:
    string category;
    int amount;
    string date;

public:
    Expense(){

    }
    Expense(string cat, int amt, string dt) : category(cat), amount(amt), date(dt) {}

    string getCategory(){
        return category;
    }
    int getAmount(){
        return amount;
    }
    string getDate(){
        return date;
    }

    void display(){
        cout << "Category: " << category << ", Amount: $" << amount << ", Date: " << date << endl;
    }
};

class Budget {
private:
    string category;
    int limitAmount;

public:

Budget(){

}
    Budget(string cat, int lim) : category(cat), limitAmount(lim) {}

    string getCategory(){
        return category;
    }
    double getLimit(){
        return limitAmount;
    }

    void display() const {
        cout << "Category: " << category << ", Limit: $" << limitAmount << endl;
    }
};

class User {
private:
    string name;
    string profession;

public:

    User(){

    }
    User(string userName, string prof) : name(userName), profession(prof) {}

    string getName(){
        return name;
    }

    string getProfession(){
        return profession;
    }  

};

class ExpenseTracker {
private:

    User user;
    Expense expenses[500];
    Budget budgets[500];
    int ie = 0, ib = 0;

public:

    void registerUser(){
        string n, p;
        cout << "Enter your name: ";
        cin >> n;

        cout << "Enter your Profession: ";
        cin >> p;
        User newUser(n, p);

        user = newUser;
        cout << "Account is Successfully Created" << endl;
    }
    
    ExpenseTracker(){
    }

    void addExpense(){
        int am;
        string date, category;
        cout << "Enter Amount of Expense: ";
        cin >> am;
        cout << "Enter Date of Expense: ";
        cin >> date;
        cout << "Enter Category of Expense(e.g. Grocery/Gym/Trip): ";
        cin >> category;

        Expense newExpense(category, am, date);

        expenses[ie] = newExpense;
        ie++;
        cout << "Expense is Successfully Added" << endl;
    }

    void addBudget(){
        int limitAmount;
        string category;
        cout << "Enter Limit Amount for this Budget Plan: ";
        cin >> limitAmount;
        cout << "Enter Category of Budget(e.g. Grocery/Gym/Trip): ";
        cin >> category;

        Budget newBudget(category, limitAmount);

        budgets[ib] = newBudget;
        ib++;
        cout << "Budget is Successfully Added" << endl;
    }

    void displayExpenses(){
        cout << endl << "Expenses for " << user.getName() << endl;
    
        for(int i=0; i<ie; i++){
            cout << "Category: " << expenses[i].getCategory() << " \tAmount Limit: " << expenses[i].getAmount();
            cout << " \tDate: " << expenses[i].getDate() << endl;
            cout << "-----------------------------------------------------------" << endl;
        }
    
    }

    void displayBudgets(){
        cout << endl << "Budgets Plans for " << user.getName() << endl;
        for(int i=0; i<ib; i++){
            cout << "Category" << budgets[i].getCategory() << " => Amount Limit: " << budgets[i].getLimit() << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }


};

int main() {
    ExpenseTracker tracker;
    
            cout << "\n   \t=== Expense Tracker ===\n";
            cout << "Create your account in Expense Tracker Application\n";
            tracker.registerUser();
    
    int choice;
        do {
            cout << "1. Add Expense\n";
            cout << "2. Add Budget Plan\n";
            cout << "3. Display Expenses\n";
            cout << "4. Display Budgets\n";
            cout << "0. Exit\n"; 
            cout << endl;

            cout << "Enter your choice: ";
            cin >> choice;

            try {
                switch (choice) {
                    case 1:
                        tracker.addExpense();
                        break;

                    case 2:
                        tracker.addBudget();
                        break;

                    case 3:
                        tracker.displayExpenses();
                        break;

                    case 4:
                        tracker.displayBudgets();
                        break;

                    case 0:
                        cout << "Exiting...\n";
                        break;

                    default:
                        cout << "Invalid choice. Please try again.\n";
                        break;
                }
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }

        } while (choice != 0);

    
    return 0;
}
