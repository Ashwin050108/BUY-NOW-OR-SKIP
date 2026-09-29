#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cctype>

using namespace std;

string toLower(string text) {
    for (char &letter : text) {
        letter = static_cast<char>(
            tolower(static_cast<unsigned char>(letter))
        );
    }
    return text;
}

int main() {
    cout << "========================================\n";
    cout << "          BUY NOW OR SKIP?\n";
    cout << "========================================\n";
    cout << "     TikTok Shop Impulse Checker\n";
    cout << "----------------------------------------\n";

    string choice;

    cout << "Would you like to check a product? (Yes/No): ";
    cin >> choice;
    choice = toLower(choice);

    if (choice == "no") {
        cout << "Okay, you can skip this product.\n";
        return 0;
    }

    if (choice != "yes") {
        cout << "Invalid choice. Please enter Yes or No.\n";
        return 0;
    }

    // Product information: Programmer A
    double price;
    double budget;
    string needProduct;
    string lookProduct;
    string discount;
    string priority;

    cout << "\nEnter the product price (RM): ";
    if (!(cin >> price) || price <= 0) {
        cout << "Invalid price. Enter a number greater than 0.\n";
        return 0;
    }

    cout << "Enter your remaining shopping budget (RM): ";
    if (!(cin >> budget) || budget < 0) {
        cout << "Invalid budget. Enter 0 or a higher amount.\n";
        return 0;
    }

    cout << "Do you really need this product? (Yes/No): ";
    cin >> needProduct;
    needProduct = toLower(needProduct);

    cout << "Did you plan to look for this product? (Yes/No): ";
    cin >> lookProduct;
    lookProduct = toLower(lookProduct);

    cout << "Is this product currently on discount? (Yes/No): ";
    cin >> discount;
    discount = toLower(discount);

    cout << "Wishlist priority (Low/Medium/High): ";
    cin >> priority;
    priority = toLower(priority);

    if ((needProduct != "yes" && needProduct != "no") ||
        (lookProduct != "yes" && lookProduct != "no") ||
        (discount != "yes" && discount != "no") ||
        (priority != "low" && priority != "medium" &&
         priority != "high")) {
        cout << "\nInvalid answer. Use Yes/No and Low/Medium/High.\n";
        return 0;
    }

    cout << fixed << setprecision(2);

    cout << "\n========================================\n";
    cout << "          PRODUCT INFORMATION\n";
    cout << "========================================\n";
    cout << "Price: RM " << price << '\n';
    cout << "Remaining budget: RM " << budget << '\n';
    cout << "Need the product: " << needProduct << '\n';
    cout << "Planned to look for it: " << lookProduct << '\n';
    cout << "Currently on discount: " << discount << '\n';
    cout << "Wishlist priority: " << priority << '\n';

    // Recommendation: Programmer B
    cout << "\n========================================\n";
    cout << "             RECOMMENDATION\n";
    cout << "========================================\n";

    if (price > budget) {
        cout << "SKIP: The product costs more than your remaining budget.\n";
    }
    else if (needProduct == "yes") {
        cout << "BUY: You need this product and it fits your budget.\n";
    }
    else if (priority == "high" && lookProduct == "yes") {
        cout << "BUY: This is a high-priority item you planned to buy, "
             << "and it fits your budget.\n";
    }
    else if (priority == "medium" || priority == "high") {
        cout << "WAIT: It fits your budget, but take some time to decide "
             << "whether you really want it.\n";
    }
    else {
        cout << "SKIP: This is a low-priority purchase.\n";
    }

    return 0;
}