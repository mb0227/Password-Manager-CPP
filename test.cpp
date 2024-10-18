#include <iostream>
#include <conio.h> // for getch()
#include <regex>   // for email validation
#include <cctype>  // for character checks
#include <string>
#include <algorithm> // for std::replace

using namespace std;

class Validations
{
public:
    // Static function to trim leading and trailing whitespace
    static string trim(const string &str)
    {
        size_t first = str.find_first_not_of(' ');
        if (first == string::npos)
            return ""; // All spaces
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, last - first + 1);
    }

    // Static function to validate username length (must be >= 3)
    static bool validateUsername(const string &username)
    {
        return username.length() >= 3;
    }

    // Static function to validate password
    // Must have: 6+ chars, 1 special char, 1 number, 1 capital letter, 1 lowercase
    static bool validatePassword(const string &password)
    {
        if (password.length() < 6)
            return false;

        bool hasSpecial = false, hasDigit = false, hasUpper = false, hasLower = false;

        for (char c : password)
        {
            if (isdigit(c))
                hasDigit = true;
            else if (isupper(c))
                hasUpper = true;
            else if (islower(c))
                hasLower = true;
            else if (ispunct(c))
                hasSpecial = true;
        }

        return hasSpecial && hasDigit && hasUpper && hasLower;
    }

    // Static function to replace certain characters
    // ',' -> '%('  and ';' -> '%)'
    static string sanitizeInput(string input)
    {
        string sanitizedInput;
        for (char c : input)
        {
            if (c == ',')
            {
                sanitizedInput += "%(";
            }
            else if (c == ';')
            {
                sanitizedInput += "%)";
            }
            else
            {
                sanitizedInput += c;
            }
        }
        return sanitizedInput;
    }

    // Static function to validate email format (simple regex check)
    static bool validateEmail(const string &email)
    {
        regex emailPattern(R"((\w+)(\.?)(\w*)@(\w+)\.(\w+))");
        return regex_match(email, emailPattern);
    }
};

// Function to get input from user using getch() and handle ESC
string getInputWithEscapeHandling() {
    string input;
    char ch;

    while ((ch = _getch()) != 13) {  // 13 is ASCII for Enter
        if (ch == 27) {  // ESC key (ASCII 27)
            cout << "\nESC key pressed. Exiting input.\n";
            return "";  // Return empty string on ESC
        } else if (ch == 8) {  // Backspace (ASCII 8)
            if (!input.empty()) {  // Only process backspace if input is not empty
                cout << "\b \b";  // Move back and overwrite with space
                input.pop_back();  // Remove last character from input
            }
        } else {
            input.push_back(ch);  // Add character to input
            cout << ch;  // Echo the character to console
        }
    }
    cout << endl;  // Move to the next line
    return input;
}

string getPasswordInput() {
    string input;
    char ch;

    while ((ch = _getch()) != 13) {  // 13 is ASCII for Enter
        if (ch == 27) {  // ESC key (ASCII 27)
            cout << "\nESC key pressed. Exiting input.\n";
            return "";  // Return empty string on ESC
        } else if (ch == 8) {  // Backspace (ASCII 8)
            if (!input.empty()) {  // Only process backspace if input is not empty
                cout << "\b \b";  // Move back and overwrite with space
                input.pop_back();  // Remove last character from input
            }
        } else {
            input.push_back(ch);  // Add character to input
            cout << '*';  // Mask input with '*'
        }
    }
    cout << endl;  // Move to the next line
    return input;
}

// Function to handle sign-up logic
void signUp()
{
    string username, password, email;

    // Get username
    cout << "Enter username: ";
    username = getInputWithEscapeHandling();
    username = Validations::sanitizeInput(Validations::trim(username));
    if (username.empty())
        return; // If ESC was pressed, stop here

    if (!Validations::validateUsername(username))
    {
        cout << "Username must be at least 3 characters long!\n";
        return;
    }

    // Get password
    cout << "Enter password: ";
    password = getPasswordInput();
    password = Validations::sanitizeInput(Validations::trim(password));
    if (password.empty())
        return; // If ESC was pressed, stop here

    if (!Validations::validatePassword(password))
    {
        cout << "Password must be at least 6 characters long and include "
             << "a special character, a capital letter, a number, and a lowercase letter.\n";
        return;
    }

    // Get email
    cout << "Enter email: ";
    email = getInputWithEscapeHandling();
    email = Validations::sanitizeInput(Validations::trim(email));
    if (!Validations::validateEmail(email))
    {
        cout << "Invalid email format!\n";
        return;
    }

    // Success message
    cout << "Sign up successful!" << endl;
}

int main()
{
    signUp();
    return 0;
}
