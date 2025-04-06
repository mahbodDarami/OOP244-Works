// Milestone 5: Final Application
// Student Name and ID: Mahbod Darami - 117135244
// Date: 2025-04-06
// Author: Mahbod Darami
// all codes are done by myself, Mahbod Darami

#include <iostream>
#include "Menu.h"
#include "Ordering.h"

using namespace std;
using namespace seneca;

int main() {
    Ordering dineOrder("drinks.csv", "foods.csv");
    if (!dineOrder) {
        cout << "Failed to open data files or the data files are corrupted!" << endl;
        return 1;
    }
    bool finished = false;
    while (!finished) {
        Menu seneca("Seneca Restaurant ", "End Program", 0);
        seneca << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";
        size_t mainChoice = seneca.select();

        if (mainChoice == 1) {
            bool back = false;
            while (!back) {
                Menu orderMenu("Order Menu", "Back to main menu", 1);
                orderMenu << "Food" << "Drink";

                size_t orderChoice = orderMenu.select();

                if (orderChoice == 1) {
                    dineOrder.orderFood();
                }
                else if (orderChoice == 2) {
                    dineOrder.orderDrink();
                }
                else {
                    back = true;
                }
            }
        }
        else if (mainChoice == 2) {
            dineOrder.printBill(cout);
        }
        else if (mainChoice == 3) {
            dineOrder.resetBill();
        }
        else if (mainChoice == 4) {
            dineOrder.listFoods();
        }
        else if (mainChoice == 5) {
            dineOrder.listDrinks();
        }
        else if (mainChoice == 0) {
            if (dineOrder.hasUnsavedBill()) {
                Menu confirmExit("You have bills that are not saved, are you sue you want to exit?", "No");
                confirmExit << "Yes";
                size_t exitConfirm = confirmExit.select();
                if (exitConfirm == 1) {
                    finished = true;
                }
            }
            else {
                finished = true;
            }
        }
    }

    return 0;
}
