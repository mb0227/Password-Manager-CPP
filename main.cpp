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
#define WEBSITE_FILE_PATH "Files/Websites.txt"

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
protected:
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
    int id;
    string username;
    string password;
    string websiteName;
    string websiteURL;
    time_t dateCreated;
    time_t lastUpdated;

public:
    Website()
    {
    }

    Website(string username, string password, string websiteName, string websiteURL)
    {
        this->id = assignID();
        this->username = username;
        this->password = password;
        this->websiteName = websiteName;
        this->websiteURL = websiteURL;
        this->dateCreated = time(0);
        this->lastUpdated = time(0);
    }

    Website(int id, string username, string password, string websiteName, string websiteURL, time_t dateCreated, time_t dateUpdated)
    {
        this->id = id;
        this->username = username;
        this->password = password;
        this->websiteName = websiteName;
        this->websiteURL = websiteURL;
        this->dateCreated = dateCreated;
        this->lastUpdated = dateUpdated;
    }

    int assignID();

    string toString(bool maskPassword)
    {
        string dateCreatedStr = ctime(&dateCreated);
        string lastUpdatedStr = ctime(&lastUpdated);
        string maskedPassword = "";
        // Remove the newline character at the end of the ctime string
        if (!dateCreatedStr.empty() && dateCreatedStr.back() == '\n')
        {
            dateCreatedStr.pop_back(); // Removes the last character if it's a newline
        }
        if (!lastUpdatedStr.empty() && lastUpdatedStr.back() == '\n')
        {
            lastUpdatedStr.pop_back(); // Removes the last character if it's a newline
        }

        if (maskPassword)
        {
            for (int i = 0; i < password.size(); i++)
            {
                maskedPassword += '*';
            }
        }

        string displayPassword = maskPassword ? maskedPassword : password;

        return std::string(COLOR_CYAN) + "\tWebsite URL: " + std::string(COLOR_RESET) + std::string(COLOR_YELLOW) + websiteURL + std::string(COLOR_RESET) + " " +
               std::string(COLOR_MAGENTA) + "\t\tPassword: " + std::string(COLOR_RESET) + std::string(COLOR_YELLOW) + displayPassword + std::string(COLOR_RESET) + "\n" +
               std::string(COLOR_CYAN) + "\tDate Created: " + std::string(COLOR_RESET) + std::string(COLOR_YELLOW) + dateCreatedStr + std::string(COLOR_RESET) + " " +
               std::string(COLOR_MAGENTA) + "\tLast Updated: " + std::string(COLOR_RESET) + std::string(COLOR_YELLOW) + lastUpdatedStr + std::string(COLOR_RESET);
    }

    int getID()
    {
        return id;
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
public:
    vector<Website> websites;

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

    void removeWebsite(int websiteID)
    {
        for (int i = 0; i < websites.size(); i++)
        {
            if (websites[i].getID() == websiteID)
            {
                websites.erase(websites.begin() + i);
                break;
            }
        }
    }

    vector<Website> searchWebsites(string &input)
    {
        vector<Website> websites = getWebsites();
        vector<Website> result;
        for (auto &website : websites)
        {
            if (website.getWebsiteName().find(input) != std::string::npos ||
                website.getWebsiteURL().find(input) != std::string::npos)
            {
                result.push_back(website);
            }
        }
        return result;
    }

    string toString()
    {
        string result = "User: " + getUsername() + "\n" + "Email: " + getEmail();
        for (int i = 0; i < websites.size(); i++)
        {
            result += websites[i].toString(true) + "\n";
        }
        return result;
    }

    vector<Website> getWebsites();

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

    void sortByDateUpdated()
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
        if (l < n && websites[l].getLastUpdated() > websites[largest].getLastUpdated())
        {
            largest = l;
        }
        if (r < n && websites[r].getLastUpdated() > websites[largest].getLastUpdated())
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
        string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-={}[]|.<>?";

        srand(time(0));

        // Generate an 8-character password
        for (int i = 0; i < 8; i++)
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

    static vector<string> split(const string &str, char delimiter)
    {
        vector<string> tokens;
        string token;
        stringstream ss(str);

        // Use getline to split based on the delimiter
        while (getline(ss, token, delimiter))
        {
            tokens.push_back(token);
        }

        return tokens;
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
        file << user.getUsername() << "," << Encryption::encrypt(user.getPassword()) << "," << user.getEmail() << "," << endl;
        file.close();
    }

    static void deleteUsersWebsites(User user, string username, int websiteID)
    {
        ifstream file(USER_FILE_PATH);
        vector<string> fileData;
        string line;
        bool userFound = false;

        while (getline(file, line))
        {
            vector<string> tokens = Validations::splitAndDecode(line);

            if (tokens.size() == 4)
            {
                string usernameInFile = Validations::trim(tokens[0]);
                if (usernameInFile == username)
                {
                    userFound = true;
                    vector<string> websiteIDs = Validations::split(tokens[3], ';');
                    for (int i = 0; i < websiteIDs.size(); i++)
                    {
                        if (stoi(websiteIDs[i]) == websiteID)
                        {
                            websiteIDs.erase(websiteIDs.begin() + i);
                            break;
                        }
                    }

                    string updatedWebsites;
                    for (int i = 0; i < websiteIDs.size(); i++)
                    {
                        updatedWebsites += websiteIDs[i];
                        if (i != websiteIDs.size() - 1)
                        {
                            updatedWebsites += ";";
                        }
                    }

                    line = tokens[0] + "," + tokens[1] + "," + tokens[2] + "," + updatedWebsites;
                }
            }

            fileData.push_back(line);
        }
        file.close();

        if (userFound)
        {
            ofstream outFile(USER_FILE_PATH, ios::trunc);
            for (const string &updatedLine : fileData)
            {
                outFile << updatedLine << endl;
            }
            outFile.close();
        }
        user.removeWebsite(websiteID);
    }

    static void addWebsiteForUserInFile(string username, int websiteId)
    {
        ifstream file(USER_FILE_PATH);
        vector<string> fileData;
        string line;
        bool userFound = false;

        while (getline(file, line))
        {
            vector<string> tokens = Validations::splitAndDecode(line);

            if (tokens.size() == 4)
            {
                string usernameInFile = Validations::trim(tokens[0]);
                if (usernameInFile == username)
                {
                    userFound = true;
                    if (!tokens[3].empty())
                    {
                        tokens[3] += ";";
                    }
                    tokens[3] += to_string(websiteId);

                    line = tokens[0] + "," + tokens[1] + "," + tokens[2] + "," + tokens[3];
                }
            }

            fileData.push_back(line);
        }
        file.close();

        if (userFound)
        {
            ofstream outFile(USER_FILE_PATH, ios::trunc);
            for (const string &updatedLine : fileData)
            {
                outFile << updatedLine << endl;
            }
            outFile.close();
        }
    }

    static vector<User> getUsers();

    static User getUserByUsername(string username)
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

    static void updateUser(User user)
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
            file << users[i].getUsername() << "," << Encryption::encrypt(users[i].getPassword()) << "," << users[i].getEmail() << ",";
            for (int j = 0; j < users[i].getWebsites().size(); j++)
            {
                file << users[i].getWebsites()[j].getID();
                if (j != users[i].getWebsites().size() - 1)
                {
                    file << ";";
                }
            }
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
            file << users[i].getUsername() << "," << Encryption::encrypt(users[i].getPassword()) << "," << users[i].getEmail() << ",";
            for (int j = 0; j < users[i].getWebsites().size(); j++)
            {
                file << users[i].getWebsites()[j].getID();
                if (j != users[i].getWebsites().size() - 1)
                {
                    file << ";";
                }
            }
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
            if ((users[i].getUsername() == username || users[i].getEmail() == username) && users[i].getPassword() == password)
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
        file << admin.getUsername() << "," << Encryption::encrypt(admin.getPassword()) << "," << admin.getEmail() << endl;
        file.close();
    }

    static Admin getAdminByUsername(string username)
    {
        vector<Admin> users = getAdmins();
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == username)
            {
                return users[i];
            }
        }
        return Admin();
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
                    cout << COLOR_RED << "\t\t\t\t\t\tInvalid admin data found in file, skipping: " << line << COLOR_RESET << endl;
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
            if ((admins[i].getUsername() == username || admins[i].getEmail() == username) && admins[i].getPassword() == password)
            {
                return admins[i];
            }
        }
        return Admin();
    }
};

class WebsiteDL
{
public:
    static void addWebsite(Website website)
    {
        ofstream file(WEBSITE_FILE_PATH, ios::app);
        file << website.getID() << "," << website.getUsername() << "," << Encryption::encrypt(website.getPassword()) << "," << website.getWebsiteName() << "," << website.getWebsiteURL() << "," << website.getDateCreated() << "," << website.getLastUpdated() << endl;
        file.close();
    }

    static int getIdForNewWebsite()
    {
        vector<Website> websites = getWebsites();
        if (websites.size() == 0)
        {
            return 1; // First website
        }
        return websites[websites.size() - 1].getID() + 1; // Increment last ID
    }

    static vector<Website> getWebsites()
    {
        vector<Website> websites;
        ifstream file(WEBSITE_FILE_PATH);
        string line;

        while (getline(file, line))
        {
            vector<string> tokens = Validations::splitAndDecode(line);

            if (tokens.size() == 7)
            {
                int id = stoi(tokens[0]);
                string username = Validations::trim(tokens[1]);
                string password = Encryption::decrypt(Validations::trim(tokens[2]));
                string websiteName = Validations::trim(tokens[3]);
                string websiteURL = Validations::trim(tokens[4]);
                time_t dateCreated = stoi(Validations::trim(tokens[5]));
                time_t lastUpdated = stoi(Validations::trim(tokens[6]));

                if (username != "" && password != "" && websiteName != "" && websiteURL != "")
                {
                    websites.push_back(Website(id, username, password, websiteName, websiteURL, dateCreated, lastUpdated));
                }
                else
                {
                    cout << COLOR_RED << "\t\t\t\t\t\tInvalid website data found in file, skipping: " << line << COLOR_RESET << endl;
                }
            }
        }

        file.close();
        return websites;
    }

    static Website findWebsiteByID(int id)
    {
        vector<Website> websites = getWebsites();
        for (int i = 0; i < websites.size(); i++)
        {
            if (websites[i].getID() == id)
            {
                return websites[i];
            }
        }
        return Website();
    }

    static bool websiteExists(string givenString)
    {
        vector<Website> websites = getWebsites();
        for (int i = 0; i < websites.size(); i++)
        {
            if (websites[i].getWebsiteURL() == givenString || websites[i].getWebsiteName() == givenString) // checks for both url and website name
            {
                return true;
            }
        }
        return false;
    }

    static void editWebsite(Website website)
    {
        vector<Website> websites = getWebsites();
        for (int i = 0; i < websites.size(); i++)
        {
            if (websites[i].getID() == website.getID())
            {
                websites[i] = website;
                break;
            }
        }

        ofstream file(WEBSITE_FILE_PATH);
        for (int i = 0; i < websites.size(); i++)
        {
            file << websites[i].getID() << "," << websites[i].getUsername() << "," << Encryption::encrypt(websites[i].getPassword()) << "," << websites[i].getWebsiteName() << "," << websites[i].getWebsiteURL() << "," << websites[i].getDateCreated() << "," << websites[i].getLastUpdated() << endl;
        }
        file.close();
    }

    static void deleteWebsite(int id)
    {
        vector<Website> websites = getWebsites();
        for (int i = 0; i < websites.size(); i++)
        {
            if (websites[i].getID() == id)
            {
                websites.erase(websites.begin() + i);
                break;
            }
        }

        ofstream file(WEBSITE_FILE_PATH);
        for (int i = 0; i < websites.size(); i++)
        {
            file << websites[i].getID() << "," << websites[i].getUsername() << "," << Encryption::encrypt(websites[i].getPassword()) << "," << websites[i].getWebsiteName() << "," << websites[i].getWebsiteURL() << "," << websites[i].getDateCreated() << "," << websites[i].getLastUpdated() << endl;
        }
        file.close();
    }
};

int Website::assignID()
{
    return WebsiteDL::getIdForNewWebsite();
}

vector<User> UserDL::getUsers()
{
    vector<User> users;
    ifstream file(USER_FILE_PATH);
    string line;

    while (getline(file, line))
    {
        vector<string> tokens = Validations::splitAndDecode(line);

        if (tokens.size() == 4)
        {
            string username = Validations::trim(tokens[0]);
            string password = Encryption::decrypt(Validations::trim(tokens[1]));
            string email = Validations::trim(tokens[2]);
            string websites = Validations::trim(tokens[3]);
            if (username != "" && password != "" && email != "")
            {
                User user = User(username, password, email);

                vector<string> websiteIDs = Validations::split(websites, ';');

                for (int i = 0; i < websiteIDs.size(); i++)
                {
                    Website website = WebsiteDL::findWebsiteByID(stoi(websiteIDs[i]));
                    user.addWebsite(website);
                }

                users.push_back(user);
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

vector<Website> User::getWebsites()
{
    websites.clear();
    ifstream file(USER_FILE_PATH);
    string line;
    while (getline(file, line))
    {
        vector<string> tokens = Validations::splitAndDecode(line);

        if (tokens.size() == 4 && tokens[0] == username)
        {
            string websitesString = Validations::trim(tokens[3]);
            vector<string> websiteIDs = Validations::split(websitesString, ';');

            for (int i = 0; i < websiteIDs.size(); i++)
            {
                Website website = WebsiteDL::findWebsiteByID(stoi(websiteIDs[i]));
                websites.push_back(website);
            }
        }
    }
    return websites;
}

// control functions
int movementOfArrow(int x, int y, int minOption, int maxOption, int lineJump);
void showCursor(bool value);
void gotoxy(int x, int y);
bool showPasswords();
void clearScreen();
void pauseScreen();

// view functions
int displayUserWebsites(User userx, vector<Website> websites);
void displaySortedWebsites(vector<Website> websites);
int optionSelectedForDisplayedWebsites(int totalWebsites);
void displayWebsite(Website &website, bool mask);
User displayUsersNames(string operation);
string getInputWithEscapeHandling();
Website takeNewWebsiteInput();
int displayAdminLandingPage();
int displayUserLandingPage();
string getPasswordInput();
int displayLandingPage();
void displayUsersData();
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

            if (AdminDL::authenticateAdmin(username, password).getUsername() != "") // admin sign in
            {
                AdminDL::getAdminByUsername(username);
                while (true)
                {
                    clearScreen();
                    int option = displayAdminLandingPage();
                    if (option == 1) // display data
                    {
                        clearScreen();
                        displayUsersData();
                    }
                    else if (option == 2) // display passwords
                    {
                        clearScreen();
                        User user = displayUsersNames("view");
                        if (user.getUsername() != "")
                        {
                            clearScreen();
                            cout << COLOR_BLUE << "\tPasswords for user \"" << user.getUsername() << "\" are: " << COLOR_RESET << endl;
                            vector<Website> websites = user.getWebsites();
                            for (int i = 0; i < websites.size(); i++)
                            {
                                cout << websites[i].toString(false) << endl;
                            }
                            pauseScreen();
                        }
                        else
                        {
                            cout << COLOR_RED << "\tNo user found with name such name!" << COLOR_RESET << endl;
                            pauseScreen();
                        }
                    }
                    else if (option == 3) // edit passwords
                    {
                        clearScreen();
                        User user = displayUsersNames("edit");
                        if (user.getUsername() != "")
                        {
                            clearScreen();
                            cout << COLOR_BLUE << "\tPasswords for user \"" << user.getUsername() << "\" are: " << COLOR_RESET << endl;
                            vector<Website> websites = user.getWebsites();
                            for (int i = 0; i < websites.size(); i++)
                            {
                                if (i > 8)
                                    cout << "  ";
                                else
                                    cout << "   ";
                                cout << COLOR_BLUE << i + 1 << "). " << COLOR_RESET << COLOR_CYAN << websites[i].toString(false) << COLOR_RESET << endl;
                            }
                            int totalWebsites = websites.size();
                            if (totalWebsites > 0)
                            {
                                int selectedWebsite = optionSelectedForDisplayedWebsites(totalWebsites);
                                if (selectedWebsite == totalWebsites + 1 || selectedWebsite == 0)
                                {
                                    continue;
                                }
                                clearScreen();
                                displayWebsite(user.getWebsites()[selectedWebsite - 1], false);
                            }
                            else
                            {
                                cout << COLOR_RED << "\tNo websites found for this user!" << COLOR_RESET << endl;
                                pauseScreen();
                            }
                        }
                        else
                        {
                            cout << COLOR_RED << "\tNo user found with such name!" << COLOR_RESET << endl;
                            pauseScreen();
                        }
                    }
                    else if (option == 4) // delete passwords
                    {
                        clearScreen();
                        User user = displayUsersNames("delete");
                        if (user.getUsername() != "")
                        {
                            clearScreen();
                            cout << COLOR_BLUE << "\tPasswords for user \"" << user.getUsername() << "\" are: " << COLOR_RESET << endl;
                            vector<Website> websites = user.getWebsites();
                            for (int i = 0; i < websites.size(); i++)
                            {
                                if (i > 8)
                                    cout << "  ";
                                else
                                    cout << "   ";
                                cout << COLOR_BLUE << i + 1 << "). " << COLOR_RESET << COLOR_CYAN << websites[i].toString(false) << COLOR_RESET << endl;
                            }
                            int totalWebsites = websites.size();
                            if (totalWebsites > 0)
                            {
                                int selectedWebsite = optionSelectedForDisplayedWebsites(totalWebsites);
                                if (selectedWebsite == totalWebsites + 1 || selectedWebsite == 0)
                                {
                                    continue;
                                }
                                clearScreen();
                                cout << COLOR_RED << "\n\t\t\t\t\t\tAre you sure you want to delete this website? (Y/N): " << COLOR_RESET;
                                char option = getch();
                                if (option == 'Y' || option == 'y')
                                {
                                    int websiteIdToDelete = user.getWebsites()[selectedWebsite - 1].getID();
                                    UserDL::deleteUsersWebsites(user, user.getUsername(), websiteIdToDelete);
                                    WebsiteDL::deleteWebsite(websiteIdToDelete);
                                    cout << COLOR_GREEN << "\t\t\t\t\t\tWebsite deleted successfully!" << COLOR_RESET << endl;
                                }
                            }
                            else
                            {
                                cout << COLOR_RED << "\tNo websites dound for this user!" << COLOR_RESET << endl;
                                pauseScreen();
                            }
                        }
                        else
                        {
                            cout << COLOR_RED << "\tNo user found with name such name!" << COLOR_RESET << endl;
                            pauseScreen();
                        }
                    }
                    else if (option == 5) // log out
                    {
                        char option;
                        cout << COLOR_RED << "\n\t\t\t\t\t\tDo you want to log out? (Y/N): " << COLOR_RESET;
                        showCursor(true);
                        option = getch();
                        if (option == 'Y' || option == 'y')
                        {
                            showCursor(false);
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
            else if (UserDL::authenticateUser(username, password).getUsername() != "")
            {
                User user = UserDL::getUserByUsername(username);
                while (true)
                {
                    clearScreen();
                    int option = displayUserLandingPage();
                    int totalWebsites = user.getWebsites().size();
                    if (option == 1) // display websites
                    {
                    displayWebsites:
                        clearScreen();
                        if (totalWebsites > 0)
                        {
                            int selectedWebsite = displayUserWebsites(user, user.getWebsites());
                            if (selectedWebsite == totalWebsites + 1)
                            {
                                continue;
                            }
                            else if (selectedWebsite == 0)
                            {
                                clearScreen();
                                cout << COLOR_GREEN << "\t\t\t\t\tSorted by last updated date: " << COLOR_RESET << endl;
                                user.sortByDateUpdated();
                                displaySortedWebsites(user.websites);
                                goto displayWebsites;
                            }
                            else
                            {
                                clearScreen();
                                cout << user.getWebsites()[selectedWebsite - 1].toString(false) << endl;
                                pauseScreen();
                                goto displayWebsites;
                            }
                        }
                        else
                        {
                            cout << COLOR_RED << "\tNo websites dound for this user!" << COLOR_RESET << endl;
                            pauseScreen();
                        }
                    }
                    else if (option == 2) // add website
                    {
                        showCursor(true);
                        Website website(takeNewWebsiteInput());
                        if (website.getWebsiteName() != "" && website.getWebsiteURL() != "")
                        {
                            WebsiteDL::addWebsite(website);
                            UserDL::addWebsiteForUserInFile(user.getUsername(), website.getID());
                            user.addWebsite(website);
                            cout << COLOR_GREEN << "\t\t\t\t\t\tWebsite added successful!" << COLOR_RESET << endl;
                            pauseScreen();
                        }
                    }
                    else if (option == 3) // edit website
                    {
                        int totalWebsites = user.getWebsites().size();
                        if (totalWebsites > 0)
                        {
                        displayWebs:
                            clearScreen();
                            int selectedWebsite = displayUserWebsites(user, user.getWebsites());
                            if (selectedWebsite == totalWebsites + 1)
                            {
                                continue;
                            }
                            else if (selectedWebsite == 0)
                            {
                                clearScreen();
                                cout << COLOR_GREEN << "\t\t\t\t\tSorted by last updated date: " << COLOR_RESET << endl;
                                user.sortByDateUpdated();
                                displaySortedWebsites(user.websites);
                                goto displayWebs;
                            }
                            clearScreen();
                            displayWebsite(user.getWebsites()[selectedWebsite - 1], true);
                        }
                        else
                        {
                            cout << COLOR_RED << "\tNo websites dound for this user!" << COLOR_RESET << endl;
                            pauseScreen();
                        }
                    }
                    else if (option == 4) // delete website
                    {
                        clearScreen();
                        int totalWebsites = user.getWebsites().size();
                        if (totalWebsites > 0)
                        {
                            int selectedWebsite = displayUserWebsites(user, user.getWebsites());
                            if (selectedWebsite == totalWebsites + 1)
                            {
                                continue;
                            }
                            else if (selectedWebsite == 0)
                            {
                                clearScreen();
                                cout << COLOR_GREEN << "\t\t\t\t\tSorted by last updated date: " << COLOR_RESET << endl;
                                user.sortByDateUpdated();
                                displaySortedWebsites(user.websites);
                            }
                            clearScreen();
                            cout << COLOR_RED << "\n\t\t\t\t\t\tAre you sure you want to delete this website? (Y/N): " << COLOR_RESET;
                            char option = getch();
                            if (option == 'Y' || option == 'y')
                            {
                                int websiteIdToDelete = user.getWebsites()[selectedWebsite - 1].getID();
                                UserDL::deleteUsersWebsites(user, user.getUsername(), websiteIdToDelete);
                                WebsiteDL::deleteWebsite(websiteIdToDelete);
                                cout << COLOR_GREEN << "\n\t\t\t\t\t\tWebsite deleted successfully!" << COLOR_RESET << endl;
                                pauseScreen();
                            }
                        }
                        else
                        {
                            cout << COLOR_RED << "\tNo websites dound for this user!" << COLOR_RESET << endl;
                            pauseScreen();
                        }
                    }
                    else if (option == 5) // search website
                    {
                        clearScreen();
                        showCursor(true);
                        cout << COLOR_CYAN << "\t\t\t\t\t\tEnter the Website's Name/URL you want to search : " << COLOR_RESET;
                        string input = getInputWithEscapeHandling();
                        if (input.empty())
                            continue;
                        vector<Website> result = user.searchWebsites(input);
                        if (result.size() == 0)
                        {
                            cout << COLOR_RED << "\t\t\t\t\t\tNo website found!" << COLOR_RESET << endl;
                        }
                        else
                        {
                            for (auto &website : result)
                            {
                                bool showPassword = showPasswords();
                                cout << "\n";
                                cout << website.toString(showPassword) << endl;
                                pauseScreen();
                            }
                        }
                    }
                    else if (option == 6) // change password
                    {
                        clearScreen();
                        showCursor(true);
                        cout << COLOR_CYAN << "\t\t\t\t\t\tEnter new password: " << COLOR_RESET;
                        string newPassword = getPasswordInput();
                        if (newPassword.empty())
                            continue;
                        if (!Validations::validatePassword(newPassword))
                        {
                            cout << COLOR_RED << "\t\t\t\t\t\tPassword must be at least 6 characters long and include "
                                 << "a special \n\t\t\t\t\t\tcharacter, a capital letter, a number, and a lowercase letter." << COLOR_RESET << "\n";
                            pauseScreen();
                            continue;
                        }
                        user.setPassword(Encryption::encrypt(newPassword));
                        UserDL::updateUser(user);
                        cout << COLOR_GREEN << "\t\t\t\t\t\tPassword changed successfully!" << COLOR_RESET << endl;
                        pauseScreen();
                    }
                    else if (option == 7) // log out
                    {
                        char option;
                        cout << COLOR_RED << "\n\t\t\t\t\t\tDo you want to log out? (Y/N): " << COLOR_RESET;
                        showCursor(true);
                        option = getch();
                        if (option == 'Y' || option == 'y')
                        {
                            showCursor(false);
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
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
                Admin admin(person.getUsername(), person.getPassword(), person.getEmail());
                AdminDL::addAdmin(admin);
            }
            else if (roleOptionSelected == 2 && person.getUsername() != "" && person.getPassword() != "")
            {
                User user(person.getUsername(), person.getPassword(), person.getEmail());
                UserDL::addUser(user);
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

int displayLandingPage()
{
    clearScreen();
    cout << COLOR_YELLOW
         << "\t\t\t\t\t\tLogin" << endl;
    cout << "\t\t\t\t\t\tRegister" << endl;
    cout << "\t\t\t\t\t\tExit" << endl;
    cout << COLOR_RESET;
    return movementOfArrow(45, 0, 1, 3, 1);
}

int selectRole()
{
    clearScreen();
    cout << COLOR_YELLOW
         << "\t\t\t\t\t\tAdmin" << endl;
    cout << "\t\t\t\t\t\tUser" << endl;
    cout << "\t\t\t\t\t\tGo Back" << endl;
    cout << COLOR_RESET;
    return movementOfArrow(45, 0, 1, 3, 1);
}

int displayUserLandingPage()
{
    clearScreen();
    cout << COLOR_YELLOW
         << "\t\t\t\t\t\tView Websites" << endl;
    cout << "\t\t\t\t\t\tAdd Website" << endl;
    cout << "\t\t\t\t\t\tEdit Website" << endl;
    cout << "\t\t\t\t\t\tDelete Website" << endl;
    cout << "\t\t\t\t\t\tSearch Website" << endl;
    cout << "\t\t\t\t\t\tChange Password" << endl;
    cout << "\t\t\t\t\t\tLogout" << endl;
    cout << COLOR_RESET;
    return movementOfArrow(45, 0, 1, 7, 1);
}

int displayAdminLandingPage()
{
    clearScreen();
    cout << COLOR_YELLOW
         << "\t\t\t\t\t\tView Users" << endl;
    cout << "\t\t\t\t\t\tView Users stored passwords" << endl;
    cout << "\t\t\t\t\t\tEdit Users stored passwords" << endl;
    cout << "\t\t\t\t\t\tDelete Users stored passwords" << endl;
    cout << "\t\t\t\t\t\tLogout" << endl;
    cout << COLOR_RESET;
    return movementOfArrow(45, 0, 1, 5, 1);
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

Person signUp()
{
    string username, password, email;

    while (true)
    {
        clearScreen();
        cout << COLOR_CYAN << "\t\t\t\t\t\tEnter username: " << COLOR_RESET;
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
        cout << COLOR_MAGENTA << "\t\t\t\t\t\tEnter \"gen\" to generate a random password!" << endl
             << COLOR_RESET;
        cout << COLOR_CYAN << "\t\t\t\t\t\tEnter password: " << COLOR_RESET;
        password = getPasswordInput();
        password = Validations::sanitizeInput(Validations::trim(password));

        if (password == "gen")
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
        cout << COLOR_CYAN << "\t\t\t\t\t\tEnter email: " << COLOR_RESET;
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
        else if (AdminDL::adminExists(email) || UserDL::userExists(email))
        {
            cout << COLOR_RED << "\t\t\t\t\t\tEmail already exists!" << COLOR_RESET << "\n";
            pauseScreen();
            continue;
        }
        else
        {
            break;
        }
    }

    // Success message
    cout << COLOR_GREEN << "\t\t\t\t\t\tSign up successful!" << COLOR_RESET << endl;
    pauseScreen();
    return Person(username, password, email);
}

// int displayUserWebsites(User user, vector<Website> websites)
// {
//     vector<Website> websites = user.getWebsites();
//     if (websites.size() > 0)
//     {
//         gotoxy(93, 0);
//         cout << COLOR_GREEN << "Sort by Last Updated(S)" << COLOR_RESET << endl;
//     }

//     // Display websites
//     int i = 0;
//     for (i; i < websites.size(); i++)
//     {
//         if (i > 8)
//             cout << "  ";
//         else
//             cout << "   ";
//         cout << COLOR_BLUE << i + 1 << "). " << COLOR_RESET << COLOR_CYAN << websites[i].toString(true) << COLOR_RESET << endl;
//     }

//     if (i > 8)
//         cout << "  ";
//     else
//         cout << "   ";
//     cout << COLOR_BLUE << websites.size() + 1 << ").  " << COLOR_RESET << COLOR_CYAN << "Go back" << COLOR_RESET << endl;

//     return movementOfArrow(0, 1, 1, websites.size() + 1, 2);
// }

int displayUserWebsites(User user, vector<Website> websites)
{
    if (websites.size() > 0)
    {
        gotoxy(93, 0);
        cout << COLOR_GREEN << "Sort by Last Updated(S)" << COLOR_RESET << endl;
        gotoxy(93, 1);
        cout << COLOR_GREEN << "Go Back to previous page(B)" << COLOR_RESET << endl;
    }

    // Display websites
    int i = 0;
    for (i; i < websites.size(); i++)
    {
        if (i > 8)
            cout << "  ";
        else
            cout << "   ";
        cout << COLOR_BLUE << i + 1 << "). " << COLOR_RESET << COLOR_CYAN << websites[i].toString(true) << COLOR_RESET << endl;
    }

    if (i > 8)
        cout << "  ";
    else
        cout << "   ";
    cout << COLOR_BLUE << websites.size() + 1 << ").  " << COLOR_RESET << COLOR_CYAN << "Go back" << COLOR_RESET << endl;

    int totalWebsites = websites.size();
    return optionSelectedForDisplayedWebsites(totalWebsites);
}

int movementOfArrow(int x, int y, int currentOption, int maxOption, int lineJump)
{
    int key;
    showCursor(false);

    // Set cursor position at the start (Go back)
    gotoxy(x, y);
    cout << "\33[32m" << "o>";

    do
    {
        key = _getch();

        // Clear previous arrow
        gotoxy(x, y);
        cout << "  ";

        if (key == 72) // Up arrow key
        {
            if (currentOption > 1)
            {
                currentOption--;
                y -= lineJump; // Move up 7 lines
            }
        }
        else if (key == 80) // Down arrow key
        {
            if (currentOption < maxOption)
            {
                currentOption++;
                y += lineJump; // Move down 7 lines
            }
        }
        else if (key == 'S' || key == 's') // Sort option key
        {
            return 0; // Return 0 for "Sort by Last Updated"
        }

        // Draw new arrow at updated position
        gotoxy(x, y);
        cout << "o>";

    } while (key != 13); // Enter key to select an option

    return currentOption;
}

Website takeNewWebsiteInput()
{
    string websiteName, websiteURL, username, password;
    while (true)
    {
        clearScreen();
        cout << COLOR_CYAN << "\t\t\t\t\t\tEnter username for website: " << COLOR_RESET;
        username = getInputWithEscapeHandling();
        username = Validations::sanitizeInput(Validations::trim(username));

        if (username.empty())
            return Website(); // If ESC was pressed, stop here

        if (!Validations::validateUsername(username))
        {
            cout << COLOR_RED << "\t\t\t\t\t\tUsername must be at least 3 characters and at most 8 characters long!" << COLOR_RESET << "\n";
            pauseScreen();
            continue;
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        clearScreen();
        cout << COLOR_MAGENTA << "\t\t\t\t\t\tPassword must be at least 6 characters long and include "
             << "a special \n\t\t\t\t\t\tcharacter, a capital letter, a number, and a lowercase letter." << COLOR_RESET << "\n";
        cout << COLOR_MAGENTA << "\t\t\t\t\t\tEnter \"gen\" to generate a random password!" << endl
             << COLOR_RESET;
        cout << COLOR_CYAN << "\t\t\t\t\t\tEnter password: " << COLOR_RESET;
        password = getPasswordInput();
        password = Validations::sanitizeInput(Validations::trim(password));

        if (password == "gen")
        {
            password = RandomPassword::generatePassword();
            cout << COLOR_GREEN << "\t\t\t\t\t\tGenerated password: " << password << COLOR_RESET << endl;
            char option;
            cout << COLOR_CYAN << "\t\t\t\t\t\tDo you want to use this password? (Y/N): " << COLOR_RESET;
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
            return Website(); // If ESC was pressed, stop here

        if (!Validations::validatePassword(password))
        {
            cout << COLOR_RED << "\t\t\t\t\t\tPassword must be at least 6 characters long and include "
                 << "a special \n\t\t\t\t\t\tcharacter, a capital letter, a number, and a lowercase letter." << COLOR_RESET << "\n";
            pauseScreen();
            return Website();
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        clearScreen();
        cout << COLOR_CYAN << "\t\t\t\t\t\tEnter website name: " << COLOR_RESET;
        websiteName = getInputWithEscapeHandling();
        websiteName = Validations::sanitizeInput(Validations::trim(websiteName));

        if (websiteName.empty())
            return Website(); // If ESC was pressed, stop here

        // if (WebsiteDL::websiteExists(websiteName))
        // {
        //     cout << COLOR_RED << "\t\t\t\t\t\tWebsite name already exists!" << COLOR_RESET << "\n";
        //     pauseScreen();
        //     continue;
        // }
        else
        {
            break;
        }
    }

    while (true)
    {
        clearScreen();
        cout << COLOR_CYAN << "\t\t\t\t\t\tEnter website URL: " << COLOR_RESET;
        websiteURL = getInputWithEscapeHandling();
        websiteURL = Validations::sanitizeInput(Validations::trim(websiteURL));

        if (websiteURL.empty())
            return Website(); // If ESC was pressed, stop here

        // if (WebsiteDL::websiteExists(websiteURL))
        // {
        //     cout << COLOR_RED << "\t\t\t\t\t\tWebsite URL already exists!" << COLOR_RESET << "\n";
        //     pauseScreen();
        //     continue;
        // }
        else
        {
            break;
        }
    }

    return Website(username, password, websiteName, websiteURL);
}

void displayWebsite(Website &website, bool mask)
{
    string maskedPassword = "", input;

    while (true) // Loop to re-display the website after each update
    {
        clearScreen();
        maskedPassword = "";
        for (int i = 0; i < website.getPassword().size(); i++)
        {
            maskedPassword += '*';
        }

        time_t dateCreated = website.getDateCreated();
        time_t lastUpdated = website.getLastUpdated();
        string dateCreatedStr = ctime(&dateCreated);
        string lastUpdatedStr = ctime(&lastUpdated);
        string displayPassword = mask ? maskedPassword : website.getPassword();

        cout << std::string(COLOR_CYAN) + "\tUsername: " + std::string(COLOR_RESET) + std::string(COLOR_YELLOW) + website.getUsername() + std::string(COLOR_RESET) + "\n" +
                    std::string(COLOR_CYAN) + "\tPassword: " + std::string(COLOR_RESET) + std::string(COLOR_YELLOW) + displayPassword + std::string(COLOR_RESET) + "\n" +
                    std::string(COLOR_CYAN) + "\tWebsite Name: " + std::string(COLOR_RESET) + std::string(COLOR_YELLOW) + website.getWebsiteName() + std::string(COLOR_RESET) + "\n" +
                    std::string(COLOR_CYAN) + "\tWebsite URL: " + std::string(COLOR_RESET) + std::string(COLOR_YELLOW) + website.getWebsiteURL() + std::string(COLOR_RESET) + "\n" +
                    std::string(COLOR_CYAN) + "\tDate Created: " + std::string(COLOR_RESET) + std::string(COLOR_YELLOW) + dateCreatedStr + std::string(COLOR_RESET) +
                    std::string(COLOR_CYAN) + "\tLast Updated: " + std::string(COLOR_RESET) + std::string(COLOR_YELLOW) + lastUpdatedStr + std::string(COLOR_RESET) +
                    std::string(COLOR_CYAN) + "\tGo Back" + std::string(COLOR_RESET) + "\n";

        int option = movementOfArrow(5, 0, 1, 7, 1);
        clearScreen();
        showCursor(true);

        if (option == 1)
        {
            cout << COLOR_CYAN << "\t\t\t\t\t\tEnter new username: " << COLOR_RESET;
            input = getInputWithEscapeHandling();
            input = Validations::sanitizeInput(Validations::trim(input));
            if (input.empty())
                continue; // Skip to next iteration if no input is provided
            website.setUsername(input);
        }
        else if (option == 2)
        {
            cout << COLOR_CYAN << "\t\t\t\t\t\tEnter new password: " << COLOR_RESET;
            input = getPasswordInput();
            input = Validations::sanitizeInput(Validations::trim(input));
            if (input.empty())
                continue;

            if (!Validations::validatePassword(input))
            {
                cout << COLOR_RED << "\t\t\t\t\t\tPassword must be at least 6 characters long and include "
                     << "a special \n\t\t\t\t\t\tcharacter, a capital letter, a number, and a lowercase letter." << COLOR_RESET << "\n";
                pauseScreen();
                continue;
            }
            website.setPassword(input);
        }
        else if (option == 3)
        {
            cout << COLOR_CYAN << "\t\t\t\t\t\tEnter new website name: " << COLOR_RESET;
            input = getInputWithEscapeHandling();
            input = Validations::sanitizeInput(Validations::trim(input));
            if (input.empty())
                continue;
            website.setWebsiteName(input);
        }
        else if (option == 4)
        {
            cout << COLOR_CYAN << "\t\t\t\t\t\tEnter new website URL: " << COLOR_RESET;
            input = getInputWithEscapeHandling();
            input = Validations::sanitizeInput(Validations::trim(input));
            if (input.empty())
                continue;
            website.setWebsiteURL(input);
        }
        else if (option == 5 || option == 6)
        {
            cout << COLOR_RED << "\t\t\t\t\t\tDate created/updated field is manually uneditable\n";
            pauseScreen();
            continue;
        }
        else if (option == 7)
        {
            return; // Exit when user selects "Go Back"
        }

        website.setLastUpdated(time(0));
        WebsiteDL::editWebsite(website);
    }
}

bool showPasswords()
{
    char option;
    cout << COLOR_RED << "\n\t\t\t\t\t\tDo you want to hide passwords? (Y/N): " << COLOR_RESET;
    option = getch();
    if (option == 'Y' || option == 'y')
        return true;
    return false;
}

void displayUsersData()
{
    vector<User> users = UserDL::getUsers();
    for (int i = 0; i < users.size(); i++)
    {
        cout << "\t" << COLOR_CYAN << "Username: " << COLOR_RESET << COLOR_YELLOW << users[i].getUsername() << COLOR_RESET << COLOR_CYAN << " Email: " << COLOR_RESET << COLOR_YELLOW << users[i].getEmail() << COLOR_RESET << COLOR_CYAN << " Password: " << COLOR_RESET << COLOR_YELLOW << users[i].getPassword() << COLOR_RESET << endl;
    }
    pauseScreen();
}

User displayUsersNames(string operation)
{
    vector<User> users = UserDL::getUsers();
    for (int i = 0; i < users.size(); i++)
    {
        cout << "\t" << COLOR_CYAN << "Username: " << COLOR_RESET << COLOR_YELLOW << users[i].getUsername() << endl;
    }
    showCursor(true);
    cout << COLOR_CYAN << "\tEnter the username of the user you want to " << operation << " the passwords of: " << COLOR_RESET;
    string username = getInputWithEscapeHandling();
    username = Validations::sanitizeInput(Validations::trim(username));
    if (username.empty())
        return User();
    return UserDL::getUserByUsername(username);
}

int optionSelectedForDisplayedWebsites(int totalWebsites)
{
    showCursor(true);
    while (true) // Loop to handle invalid inputs
    {
        string input = ""; // To store the multi-digit input
        cout << COLOR_CYAN << "\n\tEnter the website number to view details: " << COLOR_RESET;
        char key;
        while (true)
        {
            key = getch();
            int option = key - '0'; // Convert char digit to int
            // If 'Enter' is pressed, break to process the input
            if (key == '\r') // '\r' is the carriage return (Enter) on Windows
            {
                break;
            }
            // If it's a number, append it to the input string

            // Handle non-numeric special commands first
            if (key == 'S' || key == 's')
            {
                return 0; // Indicates sorting option
            }
            else if (key == 'B' || key == 'b' || option == totalWebsites + 1)
            {
                return totalWebsites + 1; // Return Go Back index
            }
            else if (isdigit(key) && key != '0')
            {
                input += key;
                cout << key; // Display the typed digit
            }
        }

        if (!input.empty())
        {
            int option = stoi(input); // Convert string to integer

            // Check if the option is a valid website index
            if (option >= 1 && option <= totalWebsites)
            {
                return option; // Return the selected website index
            }
        }
    }
}

void displaySortedWebsites(vector<Website> websites)
{
    int num = 1;
    for (auto website : websites)
    {
        cout << COLOR_CYAN << num++ << "). " << COLOR_RESET << website.toString(false) << endl;
    }
    pauseScreen();
}