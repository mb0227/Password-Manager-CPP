#include <string>
using namespace std;

class Utils
{
public:
    static string adminFilePath; 
    static string userFilePath; 
};

string Utils::adminFilePath = "Files//Admins.txt";
string Utils::userFilePath = "Files//Users.txt";