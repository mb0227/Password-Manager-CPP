#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <algorithm>
#include <regex> 
#include <cctype>

using namespace std;

#define USER_FILE_PATH "Files/Users.txt"
#define ADMIN_FILE_PATH "Files/Admins.txt"
#define COLOR_RESET "\033[0m"    // Reset to default color
#define COLOR_BLACK "\033[30m"   // Black
#define COLOR_RED "\033[31m"     // Red
#define COLOR_GREEN "\033[32m"   // Green
#define COLOR_YELLOW "\033[33m"  // Yellow
#define COLOR_BLUE "\033[34m"    // Blue
#define COLOR_MAGENTA "\033[35m" // Magenta
#define COLOR_CYAN "\033[36m"    // Cyan
#define COLOR_WHITE "\033[37m"   // White

class Person
{
private:
    string username;
    string password;
    string email;

public:
    Person()
    {
    }

    Person(string username, string password, string email)
    {
        this->username = username;
        this->password = password;
        this->email = email;
    }

    string toString()
    {
        return "Username: " + username + "\nPassword: " + password + "\nEmail: " + email;
    }

    string getUsername()
    {
        return username;
    }

    string getPassword()
    {
        return password;
    }

    string getEmail()
    {
        return email;
    }

    void setUsername(string username)
    {
        this->username = username;
    }

    void setPassword(string password)
    {
        this->password = password;
    }

    void setEmail(string email)
    {
        this->email = email;
    }
};

class Website
{
private:
    string username;
    string password;
    string websiteName;
    string websiteURL;
    time_t dateCreated;
    time_t lastUpdated;

public:
    Website(string username, string password, string websiteName, string websiteURL)
    {
        this->username = username;
        this->password = password;
        this->websiteName = websiteName;
        this->websiteURL = websiteURL;
        this->dateCreated = time(0);
        this->lastUpdated = time(0);
    }

    string toString()
    {
        return "Username: " + username + "\nPassword: " + password + "\nWebsite Name: " + websiteName + "\nWebsite URL: " + websiteURL + "\nDate Created: " + ctime(&dateCreated) + "\nLast Updated: " + ctime(&lastUpdated);
    }

    string getUsername()
    {
        return username;
    }

    string getPassword()
    {
        return password;
    }

    string getWebsiteName()
    {
        return websiteName;
    }

    string getWebsiteURL()
    {
        return websiteURL;
    }

    time_t getDateCreated()
    {
        return dateCreated;
    }

    time_t getLastUpdated()
    {
        return lastUpdated;
    }

    void setUsername(string username)
    {
        this->username = username;
    }

    void setPassword(string password)
    {
        this->password = password;
    }

    void setWebsiteName(string websiteName)
    {
        this->websiteName = websiteName;
    }

    void setWebsiteURL(string websiteURL)
    {
        this->websiteURL = websiteURL;
    }

    void setDateCreated(time_t dateCreated)
    {
        this->dateCreated = dateCreated;
    }

    void setLastUpdated(time_t lastUpdated)
    {
        this->lastUpdated = lastUpdated;
    }
};

class User : public Person
{
private:
    vector<Website> websites;

public:
    User()
    {
    }

    User(string username, string password, string email) : Person(username, password, email)
    {
    }

    void addWebsite(Website website)
    {
        websites.push_back(website);
    }

    void removeWebsite(string websiteURL)
    {
        for (int i = 0; i < websites.size(); i++)
        {
            if (websites[i].getWebsiteURL() == websiteURL)
            {
                websites.erase(websites.begin() + i);
                break;
            }
        }
    }

    string toString()
    {
        string result = "User: " + getUsername() + "\n" + "Email: " + getEmail();
        for (int i = 0; i < websites.size(); i++)
        {
            result += websites[i].toString() + "\n";
        }
        return result;
    }

    vector<Website> getWebsites()
    {
        return websites;
    }

    void setWebsites(vector<Website> websites)
    {
        this->websites = websites;
    }

    void editPassword(string newPassword, int index)
    {
        websites[index].setPassword(newPassword);
    }

    vector<Website> searchWebsite(string websiteURL)
    {
        vector<Website> result;
        for (int i = 0; i < websites.size(); i++)
        {
            if (websites[i].getWebsiteURL() == websiteURL)
            {
                result.push_back(websites[i]);
            }
        }
        return result;
    }

    void sortByDateCreated()
    {
        int n = websites.size();
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(websites, n, i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            swap(websites[0], websites[i]);
            heapify(websites, i, 0);
        }
    }

    void heapify(vector<Website> &websites, int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && websites[l].getDateCreated() > websites[largest].getDateCreated())
        {
            largest = l;
        }
        if (r < n && websites[r].getDateCreated() > websites[largest].getDateCreated())
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(websites[i], websites[largest]);
            heapify(websites, n, largest);
        }
    }

    void swap(Website &a, Website &b)
    {
        Website temp = a;
        a = b;
        b = temp;
    }
};

class Admin : public Person
{
public:
    Admin()
    {
    }

    Admin(string username, string password, string email) : Person(username, password, email)
    {
    }

    // vector<User> getAllUsers()
    // {
    //     return users;
    // }

    // void editUserPassword(string username, string newPassword)
    // {
    //     for (int i = 0; i < users.size(); i++)
    //     {
    //         if (users[i].getUsername() == username)
    //         {
    //             users[i].setPassword(newPassword);
    //             break;
    //         }
    //     }
    // }

    // void deleteUserPassword(string username)
    // {
    //     for (int i = 0; i < users.size(); i++)
    //     {
    //         if (users[i].getUsername() == username)
    //         {
    //             users.erase(users.begin() + i);
    //             break;
    //         }
    //     }
    // }
};

class Encryption
{
private:
    static const int key = 56; // Key used for shifting

public:
    // Encryption function
    static string encrypt(string text)
    {
        string result = "";
        for (int i = 0; i < text.length(); i++)
        {
            if (isalpha(text[i])) // Only process alphabetic characters
            {
                if (isupper(text[i])) // Process uppercase letters
                {
                    result += char((text[i] - 'A' + (key % 26)) % 26 + 'A');
                }
                else // Process lowercase letters
                {
                    result += char((text[i] - 'a' + (key % 26)) % 26 + 'a');
                }
            }
            else // Non-alphabetic characters remain unchanged
            {
                result += text[i];
            }
        }
        return result;
    }

    // Decryption function
    static string decrypt(string text)
    {
        string result = "";
        for (int i = 0; i < text.length(); i++)
        {
            if (isalpha(text[i])) // Only process alphabetic characters
            {
                if (isupper(text[i])) // Process uppercase letters
                {
                    result += char((text[i] - 'A' - (key % 26) + 26) % 26 + 'A');
                }
                else // Process lowercase letters
                {
                    result += char((text[i] - 'a' - (key % 26) + 26) % 26 + 'a');
                }
            }
            else // Non-alphabetic characters remain unchanged
            {
                result += text[i];
            }
        }
        return result;
    }
};

class RandomPassword
{
public:
    static string generatePassword()
    {
        string password = "";
        string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+";
        for (int i = 0; i <= 8; i++)
        {
            password += characters[rand() % characters.size()];
        }
        return password;
    }
};

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
        return username.length() >= 3 && username.length() <= 8;
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

    static vector<string> splitAndDecode(const string &line)
    {
        vector<string> tokens;
        string token;
        bool isEscaped = false;
        for (size_t i = 0; i < line.length(); ++i)
        {
            if (line[i] == '%' && (i + 1 < line.length()))
            {
                if (line.substr(i, 2) == "%(")
                {
                    token += ','; // Decode ',' from '%('
                    i += 1;       // Skip the '('
                    continue;
                }
                else if (line.substr(i, 2) == "%)")
                {
                    token += ';'; // Decode ';' from '%)'
                    i += 1;       // Skip the ')'
                    continue;
                }
            }
            else if (line[i] == ',')
            {
                tokens.push_back(token);
                token.clear();
            }
            else
            {
                token += line[i];
            }
        }

        // Add last token
        tokens.push_back(token);
        return tokens;
    }
};

// Data Layer Classes
class UserDL
{
public:
    static void addUser(User user)
    {
        ofstream file(USER_FILE_PATH, ios::app);
        file << user.getUsername() << "," << user.getPassword() << "," << user.getEmail() << endl;
        file.close();
    }

    static vector<User> getUsers()
    {
        vector<User> users;
        ifstream file(USER_FILE_PATH);
        string line;

        while (getline(file, line))
        {
            vector<string> tokens = Validations::splitAndDecode(line);

            if (tokens.size() == 3)
            {
                string username = Validations::trim(tokens[0]);
                string password = Encryption::decrypt(Validations::trim(tokens[1]));
                string email = Validations::trim(tokens[2]);
                if (username != "" && password != "" && email != "")
                {
                    users.push_back(User(username, password, email));
                }
                else
                {
                    cout << COLOR_RED << "\t\t\t\t\t\tInvalid user data found in file, skipping: " << line << COLOR_RESET << endl;
                }
            }
        }

        file.close();
        return users;
    }

    static bool userExists(string input)
    {
        vector<User> users = getUsers();
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == input || users[i].getEmail() == input)
            {
                return true;
            }
        }
        return false;
    }

    void updateUser(User user)
    {
        vector<User> users = getUsers();
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == user.getUsername())
            {
                users[i] = user;
                break;
            }
        }

        ofstream file(USER_FILE_PATH);
        for (int i = 0; i < users.size(); i++)
        {
            file << users[i].getUsername() << " " << users[i].getPassword() << " " << users[i].getEmail() << endl;
        }
        file.close();
    }

    void deleteUser(string username)
    {
        vector<User> users = getUsers();
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == username)
            {
                users.erase(users.begin() + i);
                break;
            }
        }

        ofstream file(USER_FILE_PATH);
        for (int i = 0; i < users.size(); i++)
        {
            file << users[i].getUsername() << " " << users[i].getPassword() << " " << users[i].getEmail() << endl;
        }
        file.close();
    }

    User getUser(string username)
    {
        vector<User> users = getUsers();
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == username)
            {
                return users[i];
            }
        }
        return User();
    }

    static User authenticateUser(string username, string password)
    {
        vector<User> users = getUsers();
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == username || users[i].getEmail() == username && users[i].getPassword() == password)
            {
                return users[i];
            }
        }
        return User();
    }
};

class AdminDL
{
public:
    static void addAdmin(Admin admin)
    {
        ofstream file(ADMIN_FILE_PATH, ios::app);
        file << admin.getUsername() << "," << admin.getPassword() << "," << admin.getEmail() << endl;
        file.close();
    }

    static vector<Admin> getAdmins()
    {
        vector<Admin> admins;
        ifstream file(ADMIN_FILE_PATH);
        string line;

        while (getline(file, line))
        {
            vector<string> tokens = Validations::splitAndDecode(line);

            // Each line should have exactly 3 tokens: username, password, email
            if (tokens.size() == 3)
            {
                string username = Validations::trim(tokens[0]);
                string password = Encryption::decrypt(Validations::trim(tokens[1]));
                string email = Validations::trim(tokens[2]);

                if (username != "" && password != "" && email != "")
                {
                    admins.push_back(Admin(username, password, email));
                }
                else
                {
                    cout << COLOR_RED<< "\t\t\t\t\t\tInvalid admin data found in file, skipping: " << line << COLOR_RESET<< endl;
                }
            }
        }

        file.close();
        return admins;
    }

    static bool adminExists(string input)
    {
        vector<Admin> admins = getAdmins();
        for (int i = 0; i < admins.size(); i++)
        {
            if (admins[i].getUsername() == input || admins[i].getEmail() == input)
            {
                return true;
            }
        }
        return false;
    }

    static Admin authenticateAdmin(string username, string password)
    {
        vector<Admin> admins = getAdmins();
        for (int i = 0; i < admins.size(); i++)
        {
            if (admins[i].getUsername() == username || admins[i].getEmail() == username && admins[i].getPassword() == password)
            {
                return admins[i];
            }
        }
        return Admin();
    }
};

// control functions
int movementOfArrow(int x, int y, int minOption, int maxOption);
void showCursor(bool value);
void gotoxy(int x, int y);
void clearScreen();
void pauseScreen();

// view functions
string getInputWithEscapeHandling();
string getPasswordInput();
int displayLandingPage();
int selectRole();

// user input functions
Person signUp();

int main()
{
    while (true)
    {
        int option = displayLandingPage();
        if (option == 1)
        {
            string username, password;
            showCursor(true);
            clearScreen();
            cout << COLOR_CYAN << "\t\t\t\t\t\tEnter username/email: " << COLOR_RESET;
            username = getInputWithEscapeHandling();
            username = Validations::sanitizeInput(Validations::trim(username));

            if (username.empty())
                continue;
            
            cout << COLOR_CYAN << "\t\t\t\t\t\tEnter password: " << COLOR_RESET;
            password = getPasswordInput();
            password = Validations::sanitizeInput(Validations::trim(password));

            if (password.empty())
                continue;

            if (AdminDL::authenticateAdmin(username, password).getUsername() != "")
            {
                cout << "admin login";
                pauseScreen();
            }
            else if(UserDL::authenticateUser(username, password).getUsername() != "")
            {
                cout << "user login";
                pauseScreen();
            }
            else
            {
                cout << COLOR_RED << "\t\t\t\t\t\tInvalid username/email or password!" << COLOR_RESET << endl;
                pauseScreen();
            }
        }
        else if (option == 2)
        {
            int roleOptionSelected = selectRole();
            if (roleOptionSelected == 3)
                continue;
            showCursor(true);
            Person person(signUp());
            if (roleOptionSelected == 1 && person.getUsername() != "" && person.getPassword() != "")
            {
                Admin admin(person.getUsername(), Encryption::encrypt(person.getPassword()), person.getEmail());
                AdminDL::addAdmin(admin);
                pauseScreen();
            }
            else if (roleOptionSelected == 2)
            {
                cout << "User" << endl;
            }
            clearScreen();
        }
        else if (option == 3)
        {
            showCursor(true);
            cout << "Exit" << endl;
            break;
        }
    }
    return 0;
}

void showCursor(bool value)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = value;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearScreen()
{
    system("cls");
}

void pauseScreen()
{
    cout << COLOR_BLUE << "\t\t\t\t\t\tPress any key to continue..." << COLOR_RESET;
    _getch();
}

int movementOfArrow(int x, int y, int minOption, int maxOption)
{
    int key;
    showCursor(false);
    gotoxy(x, y);
    cout << "\33[32m"
         << "o>";

    do
    {
        key = _getch();

        // Clear previous arrow
        gotoxy(x, y);
        cout << "  ";

        if (key == 72 && minOption > 1)
        {
            // Move up
            minOption--;
            y = y - 1;
        }
        else if (key == 80 && minOption < maxOption)
        {
            // Move down
            minOption++;
            y = y + 1;
        }

        // Draw new arrow
        gotoxy(x, y);
        cout << "o>";

    } while (key != 13); // 13 is the ASCII code for Enter key
    return minOption;
}

int displayLandingPage()
{
    clearScreen();
    cout << COLOR_YELLOW
         << "\t\t\t\t\t\tLogin" << endl;
    cout << "\t\t\t\t\t\tRegister" << endl;
    cout << "\t\t\t\t\t\tExit" << endl;
    cout << COLOR_RESET;
    return movementOfArrow(45, 0, 1, 3);
}

int selectRole()
{
    clearScreen();
    cout << COLOR_YELLOW
         << "\t\t\t\t\t\tAdmin" << endl;
    cout << "\t\t\t\t\t\tUser" << endl;
    cout << "\t\t\t\t\t\tGo Back" << endl;
    cout << COLOR_RESET;
    return movementOfArrow(45, 0, 1, 3);
}

string getInputWithEscapeHandling()
{
    string input;
    char ch;

    while ((ch = _getch()) != 13)
    { // 13 is ASCII for Enter
        if (ch == 27)
        { // ESC key (ASCII 27)
            cout << "\t\t\t\t\t\t\nESC key pressed. Exiting input.\n";
            return ""; // Return empty string on ESC
        }
        else if (ch == 8)
        { // Backspace (ASCII 8)
            if (!input.empty())
            {
                cout << "\b \b";  // Move back and overwrite with space
                input.pop_back(); // Remove last character from input
            }
        }
        else if (ch == 9) // continue if tab is pressed
        {
            continue;
        }
        else
        {
            input.push_back(ch); // Add character to input
            cout << ch;          // Echo the character to console
        }
    }
    cout << endl; // Move to the next line
    return input;
}

// Updated getPasswordInput
string getPasswordInput()
{
    string input;
    char ch;

    while ((ch = _getch()) != 13)
    { // 13 is ASCII for Enter
        if (ch == 27)
        { // ESC key (ASCII 27)
            cout << "\t\t\t\t\t\t\nESC key pressed. Exiting input.\n";
            return ""; // Return empty string on ESC
        }
        else if (ch == 8)
        { // Backspace (ASCII 8)
            if (!input.empty())
            {
                cout << "\b \b";  // Move back and overwrite with space
                input.pop_back(); // Remove last character from input
            }
        }
        else if (ch == 9) // continue if tab is pressed
        {
            continue;
        }
        else
        {
            input.push_back(ch); // Add character to input
            cout << '*';         // Mask input with '*'
        }
    }
    cout << endl; // Move to the next line
    return input;
}

// Updated signUp function
Person signUp()
{
    string username, password, email;

    // Get username
    while (true)
    {
        clearScreen();
        cout <<COLOR_CYAN << "\t\t\t\t\t\tEnter username: " << COLOR_RESET;
        username = getInputWithEscapeHandling();
        username = Validations::sanitizeInput(Validations::trim(username));

        if (username.empty())
            return Person(); // If ESC was pressed, stop here

        if (!Validations::validateUsername(username))
        {
            cout << COLOR_RED << "\t\t\t\t\t\tUsername must be at least 3 characters and at most 8 characters long!" << COLOR_RESET << "\n";
            pauseScreen();
            continue;
        }
        else if (AdminDL::adminExists(username) || UserDL::userExists(username))
        {
            cout << COLOR_RED << "\t\t\t\t\t\tUsername already exists!" << COLOR_RESET << "\n";
            pauseScreen();
            continue;
        }
        else
        {
            break;
        }
    }

    // Get password
    while (true)
    {
        clearScreen();
        cout << COLOR_MAGENTA << "\t\t\t\t\t\tPassword must be at least 6 characters long and include "
             << "a special \n\t\t\t\t\t\tcharacter, a capital letter, a number, and a lowercase letter." << COLOR_RESET << "\n";
        cout << COLOR_MAGENTA << "\t\t\t\t\t\tEnter \"gen\" to generate a random password!" <<endl<< COLOR_RESET;
        cout << COLOR_CYAN << "\t\t\t\t\t\tEnter password: "<< COLOR_RESET;
        password = getPasswordInput();
        password = Validations::sanitizeInput(Validations::trim(password));

        if(password == "gen")
        {
            password = RandomPassword::generatePassword();
            cout << COLOR_GREEN << "\t\t\t\t\t\tGenerated password: " << password << COLOR_RESET << endl;
            char option;
            cout << COLOR_CYAN << "\n\t\t\t\t\t\tDo you want to use this password? (Y/N): " << COLOR_RESET;
            option = getch();
            if (option == 'Y' || option == 'y')
            {
                break;
            }
            else
            {
                continue;
            }
        }

        if (password.empty())
            return Person(); // If ESC was pressed, stop here

        if (!Validations::validatePassword(password))
        {
            cout << COLOR_RED << "\t\t\t\t\t\tPassword must be at least 6 characters long and include "
                 << "a special \n\t\t\t\t\t\tcharacter, a capital letter, a number, and a lowercase letter." << COLOR_RESET << "\n";
            pauseScreen();
            return Person();
        }
        else
        {
            break;
        }
    }

    // Get email
    while (true)
    {
        clearScreen();
        cout<< COLOR_CYAN << "\t\t\t\t\t\tEnter email: " << COLOR_RESET;
        email = getInputWithEscapeHandling();
        email = Validations::sanitizeInput(Validations::trim(email));

        if (email.empty())
            return Person(); // If ESC was pressed, stop here



        if (!Validations::validateEmail(email))
        {
            cout << COLOR_RED << "\t\t\t\t\t\tInvalid email format!" << COLOR_RESET << "\n";
            pauseScreen();
            return Person();
        }
        else
        {
            break;
        }
    }

    // Success message
    cout << COLOR_GREEN << "\t\t\t\t\t\tSign up successful!" << COLOR_RESET << endl;
    return Person(username, password, email);
}