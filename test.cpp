#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

const string userFilePath = "Files/Users.txt";

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

// class Admin : public Person
// {
// public:
//     vector<User> getAllUsers()
//     {
//         return users;
//     }

//     void editUserPassword(string username, string newPassword)
//     {
//         for (int i = 0; i < users.size(); i++)
//         {
//             if (users[i].getUsername() == username)
//             {
//                 users[i].setPassword(newPassword);
//                 break;
//             }
//         }
//     }

//     void deleteUserPassword(string username)
//     {
//         for (int i = 0; i < users.size(); i++)
//         {
//             if (users[i].getUsername() == username)
//             {
//                 users.erase(users.begin() + i);
//                 break;
//             }
//         }
//     }
// };

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

class UserDL
{
public:
    static void addUser(User user)
    {
        ofstream file(userFilePath, ios::app);
        file << user.getUsername() <<","<< user.getPassword() << "," << user.getEmail() << endl;
        file.close();
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

        ofstream file(userFilePath);
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

        ofstream file(userFilePath);
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

    vector<User> getUsers()
    {
        vector<User> users;
        ifstream file(userFilePath);
        string username, password, email;
        while (file >> username >> password >> email)
        {
            User user(username, password, email);
            users.push_back(user);
        }
        file.close();
        return users;
    }
};

int displayLandingPage();
void showCursor(bool value);
void gotoxy(int x, int y);
int movementOfArrow(int x, int y, int minOption, int maxOption);
void clearScreen();

int main()
{
    while(true)
    {
        int option = displayLandingPage();
        if(option == 1)
        {
            cout << "Login" << endl;
        }
        else if(option == 2)
        {
            showCursor(true);
            
            cout << "Register" << endl;
        }
        else if(option == 3)
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
    cout << "\33[32m"
         << "\t\t\t\t\t\tLogin" << endl;
    cout << "\t\t\t\t\t\tRegister" << endl;
    cout << "\t\t\t\t\t\tExit" << endl;
    cout << "\33[0m";
    return movementOfArrow(45, 0, 1, 3);
}