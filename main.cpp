#include <iostream>
#include <string>

using namespace std;

int main() {

    cout << "========================================\n";
    cout << "          BUY NOW OR SKIP?\n";
    cout << "========================================\n";
    cout << "     TikTok Shop Impulse Checker\n";
    cout << "----------------------------------------\n";

    string choice;

    cout << "Would you like to check the product? (Yes/No): ";
    cin >> choice;

    if (choice == "Yes" || choice == "yes") {
        cout << "Nice. Let's check if you should buy it!\n";

        //Product information
        double price;
        string needProduct;
        string lookProduct;
        string discount;

        cout << "\nEnter the product price (RM): ";
        cin >> price;

        cout << "Do you really need this product? (Yes/No): ";
        cin >> needProduct;

        cout << "Did you look for this product ? (Yes/No): ";
        cin >> lookProduct;

        cout << "Is this product currently on discount? (Yes/No): ";
        cin >> discount;

        // Display the information entered
        cout << "\n========================================\n";
        cout << "          PRODUCT INFORMATION\n";
        cout << "========================================\n";

        cout << "Price: RM " << price << endl;
        cout << "Need the product: " << needProduct << endl;
        cout << "Looked for product: " << lookProduct << endl;
        cout << "Discount: " << discount << endl;

    }
    else if (choice == "No" || choice == "no") {
        cout << "Okay then, you can skip this product.\n";
    }
    else {
        cout << "Invalid choice. Please enter Yes or No.\n";
    }

    return 0;
}