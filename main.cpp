#include <iostream>
#include <string>

using namespace std;

int main() {

      cout << "========================================\n";
    cout << "          BUY NOW OR SKIP?\n";
    cout << "========================================\n";
    cout << "     Tiktok Shop Impulse Checker\n";
    cout << "----------------------------------------\n";

    string choice;

    cout << "Would you like to check this product? (Yes/No): ";
    cin >> choice;

     if (choice == "Yes" || choice == "Yes") {
        cout << " Nice. Let's check if you should buy it!\n";
    }
    else if (choice == "No" || choice == "No") {
        cout << "Okay then, you can skip this product.\n";
    }
    else {
        cout << "Invalid choice. Please enter Yes or No.\n";
    }

    return 0;
}