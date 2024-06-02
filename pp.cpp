#include <iostream>
#include <stdexcept>
using namespace std;

class Expense {
public:
    int salary;
    int Groseryexpense;
    int Electricitybill;
    int gassbill;
    int totalexpenses;

public:
    Expense() {
        cout << "Enter your salary amount:" << endl;
        cin >> salary;
        cout << "Enter your Grosery expense:" << endl;
        cin >> Groseryexpense;
        cout << "Enter your Electricity bill:" << endl;
        cin >> Electricitybill;
        cout << "Enter your gas bill:" << endl;
        cin >> gassbill;
    }

    void expense_detail() {
        totalexpenses = Electricitybill + Groseryexpense + gassbill;
        totalexpenses = salary - totalexpenses;
        cout << "Total remaining salary after expenses: " << totalexpenses << endl;
    }
};

class Budget {
public:
    string category;
    int limitamount;

public:
    Budget() {
        cout << "Enter category: ";
        cin >> category;
        cout << "Enter your limit amount: ";
        cin >> limitamount;
    }
};

class User {
public:
    string username;
    string profession;

public:
    User() {
        cout << "Enter your profession: ";
        cin >> profession;
        cout << "Enter your name: " << endl;
        cin >> username;
    }
};

class Tracker : public User, public Budget, public Expense {
    int totalamount;

public:
    void add() {
        totalamount = totalexpenses + limitamount;
        if (totalamount > salary) {
            throw runtime_error("OOPS! Your expenses are more than your salary.");
        } else {
            cout << "Total amount after adding limit: " << totalamount << endl;
            cout << "You can go for a gym membership." << endl;
        }
    }
};

int main() {
    try {
        Tracker object1;
        object1.expense_detail();
        object1.add();
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    cout << "Program continues after the exception handling." << endl;
    return 0;
}
