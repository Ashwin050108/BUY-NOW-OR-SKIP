#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

// Function to convert input text to lowercase for case-insensitive comparisons
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

    // Prompt user to start program
    cout << "Would you like to check the product? (Yes/No): ";
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

    // Product information
    double price;
    double budget;
    string needProduct;
    string lookProduct;
    string discount;
    string priority;

    // Price input with error handling
    cout << "\nEnter the final product price after any discount (RM): ";
    if (!(cin >> price) || price <= 0) {
        cout << "Invalid price. Enter a number greater than 0.\n";
        return 0;
    }

    // Budget input with error handling
    cout << "Enter your remaining shopping budget (RM): ";
    if (!(cin >> budget) || budget < 0) {
        cout << "Invalid budget. Enter 0 or a higher amount.\n";
        return 0;
    }

    // Questionnaire inputs
    cout << "Do you really need this product? (Yes/No): ";
    cin >> needProduct;
    needProduct = toLower(needProduct);

    cout << "Did you plan to look for this product? (Yes/No): ";
    cin >> lookProduct;
    lookProduct = toLower(lookProduct);

    cout << "Is this product currently on discount? (Yes/No): ";
    cin >> discount;
    discount = toLower(discount);

    // Priority selection
    cout << "\nWishlist Priority:\n";
    cout << "1. Low\n";
    cout << "2. Medium\n";
    cout << "3. High\n";
    cout << "Enter your priority (1-3): ";

    int priorityChoice;

    if (!(cin >> priorityChoice)) {
        cout << "Invalid priority. Please enter a number from 1 to 3.\n";
        return 0;
    }

    if (priorityChoice == 1) {
        priority = "low";
    }
    else if (priorityChoice == 2) {
        priority = "medium";
    }
    else if (priorityChoice == 3) {
        priority = "high";
    }
    else {
        cout << "Invalid priority. Please enter a number from 1 to 3.\n";
        return 0;
    }

    // Validate Yes/No questionnaire inputs
    if ((needProduct != "yes" && needProduct != "no") ||
        (lookProduct != "yes" && lookProduct != "no") ||
        (discount != "yes" && discount != "no")) {
        cout << "\nInvalid answer. Use Yes or No.\n";
        return 0;
    }

    // Display product information
    cout << fixed << setprecision(2);

    cout << "\n========================================\n";
    cout << "          PRODUCT INFORMATION\n";
    cout << "========================================\n";
    cout << "Final price: RM " << price << '\n';
    cout << "Remaining budget: RM " << budget << '\n';
    cout << "Need the product: " << needProduct << '\n';
    cout << "Planned to look for it: " << lookProduct << '\n';
    cout << "Currently on discount: " << discount << '\n';
    cout << "Wishlist priority: " << priority << '\n';

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