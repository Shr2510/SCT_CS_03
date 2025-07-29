#include <iostream>
#include <string>
#include <cctype>

// Color escape codes
#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define CYAN        "\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"

using namespace std;

bool containsLowercase(const string& password) {
    for (char ch : password)
        if (islower(ch)) return true;
    return false;
}

bool containsUppercase(const string& password) {
    for (char ch : password)
        if (isupper(ch)) return true;
    return false;
}

bool containsDigit(const string& password) {
    for (char ch : password)
        if (isdigit(ch)) return true;
    return false;
}

bool containsSpecialChar(const string& password) {
    string specialChars = "!@#$%^&*()_+-=[]{}|;:',.<>/?`~\\\"";
    for (char ch : password)
        if (specialChars.find(ch) != string::npos) return true;
    return false;
}

int main() {
    string password;
    int strength = 0;

    cout << CYAN << "🔐 Welcome to the Password Strength Checker 🔐" << RESET << endl;
    cout << BOLDWHITE << "Enter your password: " << RESET;
    getline(cin, password);

    cout << endl;

    // Check 1: Length
    if (password.length() >= 8) {
        strength++;
    } else {
        cout << RED << "❌ Password should be at least 8 characters long." << RESET << endl;
    }

    // Check 2: Lowercase
    if (containsLowercase(password)) {
        strength++;
    } else {
        cout << RED << "❌ Add at least one lowercase letter." << RESET << endl;
    }

    // Check 3: Uppercase
    if (containsUppercase(password)) {
        strength++;
    } else {
        cout << RED << "❌ Add at least one uppercase letter." << RESET << endl;
    }

    // Check 4: Digit
    if (containsDigit(password)) {
        strength++;
    } else {
        cout << RED << "❌ Add at least one number." << RESET << endl;
    }

    // Check 5: Special character
    if (containsSpecialChar(password)) {
        strength++;
    } else {
        cout << RED << "❌ Add at least one special character." << RESET << endl;
    }

    // Final verdict
    cout << "\n" << BOLDWHITE << "Password Strength: " << RESET;

    if (strength == 5) {
        cout << GREEN << "🟢 Strong 🔥" << RESET << endl;
    } else if (strength >= 3) {
        cout << YELLOW << "🟡 Moderate 💡" << RESET << endl;
    } else {
        cout << RED << "🔴 Weak ⚠️" << RESET << endl;
    }

    return 0;
}
