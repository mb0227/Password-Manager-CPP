#include <iostream>  //input output stream library for
#include <windows.h> //for sleep function
#include <cstdlib>   //for exit(0) function
#include <string>    //to work well with strings
#include <conio.h>   //for getch function
#include <fstream>   //for file handling
#include <algorithm> //for some built in functions
#include <iomanip>   //for setw function
#include <cctype>    //for is alnum function

using namespace std; // to avoid using std::

// to print colrs
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// formatting functions f0r my app
// header for my app
void header();
// login and sign up pages headerc
void loginPageHeader();
// cls function
void cls();
// welcome function
void welcome();
// loading
void loadingFunction();
// user guidelines
void howToUse();
// printing builiding openening animation
void printBuilding();
// animation in the start
void openingAnimation();
void CustomerHeader();
void EmployeeHeader();
// validation
//  makes sure there is no comma in given data
bool noComma(string newUser);
bool noCommaItem(string item);
// validation for password
bool validPassword(string password);
// validation for phone number
bool validPhoneNumber(string phoneNumber);
// checks if user enters spaces
bool empty(string check);
// validation for age
bool validAge(string age);
void printS2();
void printS();
void printC();
void printSSC();

// Customer Login and Sign Up Functions
void guidelines();
void getUserInput(string usernames[], string passwords[], string ages[], string genders[],
                  string phoneNumbers[], string addresses[], int &totalUsers);

// checks if customer trying to login exists
bool isExistingUser(string usernames[], string passwords[], int totalUsers, string username, string password);
// checks is users name is unique
bool isUniqueUser(string usernames[], int totalUsers, string newUser);
void forgotPassword(string usernames[], string passwords[], string ages[], string genders[], string phoneNumbers[], string addresses[], int totalUsers);
// login successfull, customer menu
int customerMenu();
// customer functionalities
// displays all the shops
// customer option 1
string displayShops(string shops[], int totalShops);

// subfunction of display shops
// Displays shop 1 menu
void shop1(string foodMenuShop1[], int foodMenuPricesShop1[], int totalShop1Items, string orderedItems1[], int orderedItemsQuantity1[], int orderedItemsPrices1[], string userIdentity1[]); // Displays shop 2 menu
// Displays shop 2 menu
void shop2(string foodMenuShop2[], int foodMenuPricesShop2[], int totalShop2Items, string orderedItems2[], int orderedItemsQuantity2[], int orderedItemsPrices2[], string userIdentity2[]);
// Displays shop 3 menu
void shop3();
// Displays shop 4 menu
// Displays shop 5 menu
void shop5(string stationery[], int stationeryPrices[], string deodorants[], int deodrantPrices[], string facewashBrands[], int facewashPrices[], string chips[], int chipsPrices[], string perfumes[], int perfumePrices[], string biscuits[], int biscuitsPrices[], string drinks[], int drinksPrices[], int totalStationarySupplies, int totalDeodrants, int totalFacewash, int totalchips, int totalPerfumes, int totalBiscuits, int totalDrinks);
// Displays shop 6 menu
// Displays shop 7 menu
void shop7(string foodMenuShop7[], int foodMenuPricesShop7[], int totalShop7Items, string orderedItems7[], int orderedItemsQuantity7[], int orderedItemsPrices7[], string userIdentity7[]);
// Displays shop 8 menu
void shop8(string foodMenuShop8[], int foodMenuPricesShop8[], int totalShop8Items, string orderedItems8[], int orderedItemsQuantity8[], int orderedItemsPrices8[], string userIdentity8[]);
// Displays shop 9 menu
void shop9(string foodMenuShop9[], int foodMenuPricesShop9[], int totalShop9Items, string orderedItems9[], int orderedItemsQuantity9[], int orderedItemsPrices9[], string userIdentity9[]);
// Displays shop 10 menu
void shop10(string foodMenuShop10[], int foodMenuPricesShop10[], int totalShop10Items, string orderedItems10[], int orderedItemsQuantity10[], int orderedItemsPrices10[], string userIdentity10[]);
// Displays shop 11 menu
void shop11(string foodMenuShop11[], int foodMenuPricesShop11[], int totalShop11Items, string orderedItems11[], int orderedItemsQuantity11[], int orderedItemsPrices11[], string userIdentity11[]);
// Displays shop 12 menu
void shop12(string foodMenuShop12[], int foodMenuPricesShop12[], int totalShop12Items, string orderedItems12[], int orderedItemsQuantity12[], int orderedItemsPrices12[], string userIdentity12[]);
// to order more than 1 item
string orderMore();
// Is validation to make sure user enters correct quantity of food to order
bool validQuantity(string quantity);
// calculates bill if user orders single quantity
void calculateBill(string input, int foodPrices[], int totalItems);
// get discount
void getDiscount(int bill);

bool isUniqueUserCP(string usernames[], int totalUsers, string newUser);
// to order drinks
// customer option 2
void drinksOrder(string drinkItems[], int drinkPrices[], int totalDrinks, string orderedDrinks[], int orderedDrinksQuantity[], int orderedDrinksPrices[], string userIdentity9[]);
// to book a table

// customer option 3
void performTableAction(bool bookedTables[], string userInfo[]);
// subfunctions of booking a table
bool isValidTable(string tableNum);
void cancelBooking(bool bookedTables[], string tableNum);
void bookTable(bool bookedTables[], string tableNum, string userInfo[]);
bool isTableBooked(const bool bookedTables[], string tableNum);
// to give suggestion to admin

// customer option 4
void takeSuggestion(string suggestions[], int &totalSuggestions);
// to give complain to admin

// customer option 5
void takeComplaint(string complaints[], int &totalComplaints);
// to take reviews for public

// customer option 6
// sub functionalities for option 6
// takes input for review type
string reviewType();
void takeReviewsForPublic(string userReviewsForPublic[], int &totalReviewsForPublic);
// to take reviews for Chefs food
void takeReviewsForChef(string userReviewsForChef[], int &totalReviewsForChef);

// customer option 7
//  to view notifications notified by user
void viewNotifications(string notification[], int totalNotifications);

// customer option 8
// to view rules
void displayRules(string rules[], int currentRules);

// customer option 9
//  to get in contact with customer care
void messageToHelplineBoyByCustomer(string username, string messageByHelplineBoy[], string userMessages[], string HelplineLineBoyReplies[], int &totalMessages, int totalHelplineBoyMessages, int totalUsers);

// customer option 10
//  SSC about section
void aboutUs();

// customer option 11
//  change password user
void changePassword(string usernames[], string passwords[], int totalUsers, string username);

// customer option 14
// change username
void changeUsername(string usernames[], int totalUsers, string username);

// customer option 15
// to delete account
void deleteUser(string usernames[], string passwords[], string ages[], string genders[], string phoneNumbers[], int &totalUsers, string currentUser); // customer

// ADMIN functions
//  To check if admin exists
bool isExistingAdmin(string adminUsernames[], string adminPasswords[], int totalAdmins, string adminUsername, string adminPassword);

// displays admin menu
int adminMenu();

// admin option 1
// options selection for admin op1
int selectFromAdminOption1();
// managing shops op 1 subfunction 1
string shopToHandle(string shops[], int totalShops);
void manageShops(string shopList[], int &totalShops);
// to add a new shop
void addShop(string shops[], int &totalShops);
// to remove an existing shop
void removeShop(string shops[], int &totalShops);

// managing menus inside shops
// op 1 subfunction 2
void addShopMenu(string foodMenuShop[], int foodMenuPricesShop[], int &totalShopItems);
// removes an existing item
void removeShopMenu(string foodMenuShop[], int foodMenuPricesShop[], int &totalShopItems);
// for shop 1
void manageShopMenu(string foodMenuShop[], int foodMenuPricesShop[], int &totalShopItems);

// manage drinks menu
void manageDrinksMenu(string drinks[], int drinksPrices[], int &totalDrinks);
// adding or removing drinks
void addDrinksMenu(string drinks[], int drinksPrices[], int &totalDrinks);
void removeDrinksMenu(string drinks[], int drinksPrices[], int &totalDrinks);

// op 1 subfunction 4
//  employee manager
void employeeManager(string employees[], int &totalEmployees);
// adding or removing employees
void addEmployee(string employees[], int &totalEmployees);
void removeEmployee(string employees[], int &totalEmployees);

// admin option 2
// op2 subfunction 1
int selectFromAdminOption2();

// view users data
// op2 subfunction 1
void viewEmployeesData(string EmployeeUsernames[], string EmployeePasswords[], int totalEmployees, string EmployeeAges[], string EmployeeGenders[], string EmployeePhoneNumbers[]);
// op2 subfunction 7
void viewUsersData(string usernames[], string passwords[], int totalUsers, string ages[], string genders[], string phoneNumbers[], string addresses[]);

// select suboption for option 3
int selectFromAdminOption3();

// op3 subfunction1
void removeUser(string usernames[], string passwords[], string ages[], string genders[], string phoneNumbers[], int &totalUsers); // admin
void usersManager(string usernames[], string passwords[], string ages[], string genders[], string phoneNumbers[], int &totalUsers);

// op3 subfunction2
void removeEmployeeAccount(string employeeUsernames[], string employeePasswords[], string employeeAges[], string employeeGenders[], string employeePhoneNumbers[], int &totalEmployees); // admin functionality

// admin option 4
void changeAdminUsername(string adminUsernames[], int totalAdmins, string adminUserName);

// admin option 5
// adding new rules by admin
void addRules(string rules[], int &currentRules);

// admin option 6
// notify users
void notifyUsers(string notification[], int &totalNotifications);

// admin option 7
//  changing password for admin
void changePasswordAdmin(string adminUsernames[], string adminPasswords[], int totalAdmins, string adminUsername, string adminPassword);

// admin option 10
// delete admin account
void deleteAdmin(string adminUsernames[], string adminPasswords[], int &totalAdmins, string currentUser);

// admin option 11
// add admin account
void addAdmin(string adminUsernames[], string adminPasswords[], int &totalAdmins);

// chef menu
int chefMenu();

// chef option 1
//  select shop for chef
string chefSelectShop(string shops[], int totalShops);
// view orders in shop1
void viewOrdersShop1(string orderedItems1[], int orderedItemsQuantity1[]);
// view orders in shop2
void viewOrdersShop2(string orderedItems2[], int orderedItemsQuantity2[]);
// view orders in shop7
void viewOrdersShop7(string orderedItems7[], int orderedItemsQuantity7[]);
// view orders in shop8
void viewOrdersShop8(string orderedItems8[], int orderedItemsQuantity8[]);
// view orders in shop9
void viewOrdersShop9(string orderedItems9[], int orderedItemsQuantity9[]);
// view orders in shop10
void viewOrdersShop10(string orderedItems10[], int orderedItemsQuantity10[]);
// view orders in shop11
void viewOrdersShop11(string orderedItems11[], int orderedItemsQuantity11[]);
// view orders in shop12
void viewOrdersShop12(string orderedItems12[], int orderedItemsQuantity12[]);
// validation if chef enters invalid shop number
void invalidShop();

// chef option 3
// view reviews about food
void viewReviewsByChef(string userReviewsForChef[], int &totalReviewsForChef);

// chef option 7
//  chef account balance
void ChefBalance(string Chefs[], int ChefSalaries[], int index);

// employee login validations
bool isUniqueEmployee(string EmployeeUsernames[], int totalEmployees, string newEmployee);
bool isExistingEmployee(string EmployeeUsernames[], string EmployeePasswords[], int totalEmployees, string EmployeeUsername, string EmployeePassword);

// employee menu
int EmployeeMenu();

// option1
void displayShopsEmployee(string shops[], int totalShops);

// option 2
// view booked and unbooked tables
void viewAllTablesStatus(const bool bookedTables[]);

// option 3
// suggestion for customer care
void takeEmployeeSuggestion(string EmployeeSuggestions[], int &totalEmployeeSuggestions);

// option4
// change password
void changePasswordEmployee(string EmployeeUsernames[], string EmployeePasswords[], int totalEmployees, string EmployeeUsername, string EmployeePassword);
void getEmployeesInput(string usernames[], string passwords[], string ages[], string genders[],
                       string phoneNumbers[], int &totalUsers);
// option 7
// account balance
void EmployeeBalance(string Employees[], int EmployeeSalaries[], int index);

// delievery boy menu
int DeliveryBoyMenu();

// delievry boy option 1
// select shop delivery boy menu
string DeliveryBoySelectShop(string shops[], int totalShops);

// shop 1
void foodDeliveryShop1(string userIdentity1[], string orderedItems1[], int orderedItemsQuantity1[]);
// shop 2
void foodDeliveryShop2(string userIdentity2[], string orderedItems2[], int orderedItemsQuantity2[]);
// shop 7
void foodDeliveryShop7(string userIdentity7[], string orderedItems7[], int orderedItemsQuantity7[]);
// shop 8
void foodDeliveryShop8(string userIdentity8[], string orderedItems8[], int orderedItemsQuantity8[]);
// shop 9
void foodDeliveryShop9(string userIdentity9[], string orderedItems9[], int orderedItemsQuantity9[]);
// shop 10
void foodDeliveryShop10(string userIdentity10[], string orderedItems10[], int orderedItemsQuantity10[]);
// shop 11
void foodDeliveryShop11(string userIdentity11[], string orderedItems11[], int orderedItemsQuantity11[]);
// shop 12
void foodDeliveryShop12(string userIdentity12[], string orderedItems12[], int orderedItemsQuantity12[]);
// drinks
void drinksDelivery(string userIdentity9[], string orderedDrinks[], int orderedDrinksQuantity[]); // DeliveryBoy

void invalidShopDelivery();
// delievry boy option 3
void DeliveryBoyBalance(string DeliveryBoys[], int DeliveryBoySalaries[], int index);

// helpline boy menu
int HelplineBoyMenu();

// helpline boy option 1
void replyToMessageByHelplineBoy(string messageByHelplineBoy[], int &userNumberByMessage, string usernames[], string userMessages[], string HelplineLineBoyReplies[], int totalMessages, int &totalHelplineBoyMessages, int totalUsers);

// helpline option 3
// account balance
void HelplineBoyBalance(string HelplineBoys[], int HelplineBoySalaries[], int index);

// accountant menu
int AccountantMenu();

// if option 1
void paySalary(string employees[], int employeeSalaries[], int totalEmployees, string chefs[], int chefsSalaries[], int totalChefs, string DeliveryBoys[], int DeliveryBoySalaries[], int totalDeliveryBoy, string Accountants[], int AccountantsSalaries[], int totalAccountants, string helplineBoys[], int HelplineBoysSalaries[], int totalHelplineBoys, string CustomerCares[], int CustomerCareSalaries[], int totalCustomerCare);

// if option 3
int viewAccountBalance(string usernames[], string username, int totalNames);
void AccountantBalance(string Accountants[], int AccountantsSalaries[], int index);

// customer care menu
int CustomerCareMenu();

// if option 1
// checking input type
string inputType();
// subfunctions
void viewHelplineBoySuggestions(string HelplineBoySuggestions[], int totalHelplineBoySuggestions);
void viewDeliveryBoySuggestions(string DeliveryBoySuggestions[], int totalDeliveryBoySuggestions);
void viewAccountantSuggestions(string AccountantSuggestions[], int totalAccountantSuggestions);
void viewChefSuggestions(string chefSuggestions[], int totalChefSuggestions);
void viewEmployeeSuggestions(string EmployeeSuggestions[], int totalEmployeeSuggestions);
void viewSuggestions(string suggestions[], int totalSuggestions);

// option2
void viewComplaints(string complaints[], int totalComplaints);

// option 3
void CustomerCareBalance(string CustomerCare[], int CustomerCareSalaries[], int index);

/// user guidelines
void howToUse();

// File Handling
string getField(string record, int field); // to find out commas in sent data

// updating data after changes
void UpdateDataToFileForCustomerParallelArrays(const string usernames[], const string passwords[], const string phoneNumbers[], const string addresses[], const string genders[], const string ages[], const int totalUsers);

// reading data from customer file
void readDataFromCustomersFileInParallelArrays(string usernames[], string passwords[], string phoneNumbers[], string addresses[], string genders[], string ages[], int &totalUsers);

// file handling for chefs
void updateDataToEmployeesFile(const string usernames[], const string passwords[], const string phoneNumbers[], const string genders[], const string ages[], const int totalUsers, const char *filename);

// reading data from chef file
void readDataFromEmployeesFile(string usernames[], string passwords[], string phoneNumbers[], string genders[], string ages[], int &totalUsers, const char *filename);

// file handling for customer service

// it reads data from file which contains employees information
void readDataFromEmployeesInfo(string workers[], int &Items, const char *filename);
// update data to file after Updation
void UpdateDataToFileForEmployeesInfo(const string workers[], const int Items, const char *filename);

// same as above
// to store customer feedback
void readFeedbackData(string suggestion[], int &index, const char *filename);
void UpdateFeedbackData(string suggestion[], int totalSuggestions, const char *filename);

void readSuggestionsData(string suggestion[], int &totalSuggestions, const char *filename);
void UpdateSuggestionsData(const string suggestion[], const int totalSuggestions, const char *filename);

// to store chefs feedback
// to store admins notification

// to store customer complains
void UpdateDataToFileForCustomerComplaint(const string suggestion[], const int totalSuggestions);
void readDataFromCustomerComplaintFile(string suggestion[], int &totalSuggestions);

void storeShopsToFile(const string shops[], const int totalShops);
void readShopsToFile(string shops[], int &totalShops);

void readShopsMenuToFile(string shopMenu[], int shopMenuPrice[], int &totalShops, const char *filename);
void storeShopsMenuToFile(const string shopMenu[], const int shopMenuPrice[], const int totalShops, const char *filename);
// validation
bool ValidateEnterDataFor2(string option);
bool validData(string name, string hall, string phoneNumer);
bool hasTabs(string input);
bool isValidChar(char ch);

void hideCursor(bool value);
// built in functions
void gotoxy(int x, int y);

// to get local time
string getCurrentTimestamp();

int movementOfArrow(int x, int y, int minOption, int maxOption);
// some global constants

// global variables for Users
const int maxUsers = 1000;
const int maxAdmins = 2;
const int maxChefs = 12;
const int maxEmployees = 20;
const int maxDeliveryBoys = 25;
const int maxHelplineBoys = 5;
const int maxAccountants = 5;
const int maxCustomerCare = 10;

// global variables for max shops
const int maxShops = 20;

// global variables for max shops items
const int maxShop1Items = 25;
const int maxShop2Items = 10;
const int maxShop7Items = 25;
const int maxShop8Items = 25;
const int maxShop9Items = 10;
const int maxShop10Items = 20;
const int maxShop11Items = 10;
const int maxShop12Items = 10;

// global variables for shop 5 and 6
const int maxStationerySupplies = 20;
const int maxdeodrants = 20;
const int maxFacewash = 20;
const int maxChips = 20;
const int maxPerfumes = 20;
const int maxBiscuits = 20;

// global variables for max drinks
const int maxDrinks = 32;

// global variables for max feedbacks
const int maxComplaints = 100;
const int maxSuggestions = 100;
const int maxChefSuggestions = 100;
const int maxEmployeeSuggestions = 100;
const int maxDeliveryBoySuggestions = 100;
const int maxHelplineBoySuggestions = 100;
const int maxCustomerCareSuggestions = 100;
const int maxAccountantSuggestions = 100;

int orderNum = 0;
int totalPrice = 0;
// max messages limit
const int maxMessages = 300;

// max rules limit
const int maxRules = 20;

const int maxReviewsForPublic = 300;
const int maxReviewsForChef = 300;

const int maxNotifications = 50;
const int maxOrderedItems = 5;
const int maxIdentityItems = 3;

int main()
{

    hideCursor(0);
    system("cls");
    printSSC();
    Sleep(30);
    system("cls");
    printBuilding();
    openingAnimation();
    //   some local variables for current number of items
    //   registered users
    int totalUsers = 0;
    int totalAdmins = 1;
    int totalEmployees = 0;
    int totalDeliveryBoys = 0;
    int totalAccountants = 0;
    int totalCustomerCare = 0;
    int totalHelplineBoys = 0;
    int totalChefs = 0;

    // employees added to the app by admin
    int totalEmployeesData = 0;
    int totalDeliveryBoysData = 0;
    int totalAccountantsData = 0;
    int totalCustomerCareData = 0;
    int totalHelplineBoysData = 0;
    int totalChefsData = 0;

    // shops
    int totalShops = 0;

    // current shop items number
    int totalShop1Items = 0;
    int totalShop2Items = 0;
    int totalShop7Items = 0;
    int totalShop8Items = 0;
    int totalShop9Items = 0;
    int totalShop10Items = 0;
    int totalShop11Items = 0;
    int totalShop12Items = 0;

    // supplies num
    int totalStationarySupplies = 10;
    int totalDeodrants = 10;
    int totalFacewash = 10;
    int totalchips = 15;
    int totalPerfumes = 10;
    int totalBiscuits = 10;

    // total drinks
    int totalDrinks = 0;

    // current feed back
    int totalSuggestions = 0;
    int totalComplaints = 0;
    int totalChefSuggestions = 0;
    int totalEmployeeSuggestions = 0;
    int totalDeliveryBoySuggestions = 0;
    int totalAccountantSuggestions = 0;
    int totalCustomerCareSuggestions = 0;
    int totalHelplineBoySuggestions = 0;

    // current data
    int currentRules = 10;
    int totalMessages = 0;
    int totalHelplineBoyMessages = 0;
    int totalReviewsForPublic = 0;
    int totalReviewsForChef = 0;
    int totalNotifications = 0;
    int userNumberByMessage = 0;

    // users arrays
    //  user parallel arrays
    // file 1
    string usernames[maxUsers];
    string passwords[maxUsers];
    string ages[maxUsers];
    string genders[maxUsers];
    string phoneNumbers[maxUsers];
    string addresses[maxUsers];

    // admin data parallel arrays
    // file 2
    string adminUsernames[maxAdmins];
    string adminPasswords[maxAdmins];
    string adminAges[maxAdmins];
    string adminGenders[maxAdmins];
    string adminPhoneNumbers[maxAdmins];

    // pre defeined user for backdoor entry
    adminUsernames[0] = {"a"};
    adminPasswords[0] = {"a"};

    // chef data parallel arrays
    // file 3
    string chefUsernames[maxChefs];
    string chefPasswords[maxChefs];
    string chefAges[maxChefs];
    string chefGenders[maxChefs];
    string chefPhoneNumbers[maxChefs];

    // employee data parallel arrays
    // file 4
    string employeeUsernames[maxEmployees];
    string employeePasswords[maxEmployees];
    string employeeAges[maxEmployees];
    string employeeGenders[maxEmployees];
    string employeePhoneNumbers[maxEmployees];

    // user data parallel arrays
    // file 5
    string DeliveryBoyUsernames[maxDeliveryBoys];
    string DeliveryBoyPasswords[maxDeliveryBoys];
    string DeliveryBoyAges[maxDeliveryBoys];
    string DeliveryBoyGenders[maxDeliveryBoys];
    string DeliveryBoyPhoneNumbers[maxDeliveryBoys];

    // user data parallel arrays
    // file 6
    string HelplineBoyUsernames[maxHelplineBoys];
    string HelplineBoyPasswords[maxHelplineBoys];
    string HelplineBoyAges[maxHelplineBoys];
    string HelplineBoyGenders[maxHelplineBoys];
    string HelplineBoyPhoneNumbers[maxHelplineBoys];

    // user data parallel arrays
    // file 7
    string AccountantUsernames[maxAccountants];
    string AccountantPasswords[maxAccountants];
    string AccountantAges[maxAccountants];
    string AccountantGenders[maxAccountants];
    string AccountantPhoneNumbers[maxAccountants];

    // user data parallel arrays
    // file 8
    string CustomerCareUsernames[maxCustomerCare];
    string CustomerCarePasswords[maxCustomerCare];
    string CustomerCareAges[maxCustomerCare];
    string CustomerCareGenders[maxCustomerCare];
    string CustomerCarePhoneNumbers[maxCustomerCare];

    // after order getting user info
    string userIdentity1[maxIdentityItems];
    string userIdentity2[maxIdentityItems];
    string userIdentity7[maxIdentityItems];
    string userIdentity8[maxIdentityItems];
    string userIdentity9[maxIdentityItems];
    string userIdentity10[maxIdentityItems];
    string userIdentity11[maxIdentityItems];
    string userIdentity12[maxIdentityItems];

    // for ordering user food and storing data
    string orderedItems1[maxOrderedItems];
    int orderedItemsPrices1[maxOrderedItems];
    int orderedItemsQuantity1[maxOrderedItems];

    string orderedItems2[maxOrderedItems];
    int orderedItemsPrices2[maxOrderedItems];
    int orderedItemsQuantity2[maxOrderedItems];

    string orderedItems7[maxOrderedItems];
    int orderedItemsPrices7[maxOrderedItems];
    int orderedItemsQuantity7[maxOrderedItems];

    string orderedItems8[maxOrderedItems];
    int orderedItemsPrices8[maxOrderedItems];
    int orderedItemsQuantity8[maxOrderedItems];

    string orderedItems9[maxOrderedItems];
    int orderedItemsPrices9[maxOrderedItems];
    int orderedItemsQuantity9[maxOrderedItems];

    string orderedItems10[maxOrderedItems];
    int orderedItemsPrices10[maxOrderedItems];
    int orderedItemsQuantity10[maxOrderedItems];

    string orderedItems11[maxOrderedItems];
    int orderedItemsPrices11[maxOrderedItems];
    int orderedItemsQuantity11[maxOrderedItems];

    string orderedItems12[maxOrderedItems];
    int orderedItemsPrices12[maxOrderedItems];
    int orderedItemsQuantity12[maxOrderedItems];

    string orderedDrinks[maxOrderedItems];
    int orderedDrinksPrices[maxOrderedItems];
    int orderedDrinksQuantity[maxOrderedItems];

    // Shop Names
    string shops[maxShops];

    string foodMenuShop1[maxShop1Items];

    int foodMenuPricesShop1[maxShop1Items];

    // Menu and Prices for Shop2
    string foodMenuShop2[maxShop2Items];

    int foodMenuPricesShop2[maxShop2Items];

    // Menu and Prices for Shop7
    string foodMenuShop7[maxShop7Items];

    int foodMenuPricesShop7[maxShop7Items];

    // Menu and Prices for Shop8
    string foodMenuShop8[maxShop8Items];

    int foodMenuPricesShop8[maxShop8Items];

    // Menu and Prices for Shop9
    string foodMenuShop9[maxShop9Items];
    int foodMenuPricesShop9[maxShop9Items];

    // Menu and Prices for Shop10
    string foodMenuShop10[maxShop10Items];

    int foodMenuPricesShop10[maxShop10Items];

    // Menu and Prices for Shop11
    string foodMenuShop11[maxShop11Items];

    int foodMenuPricesShop11[maxShop11Items];

    // Menu and Prices for Shop12
    string foodMenuShop12[maxShop12Items];

    int foodMenuPricesShop12[maxShop12Items];

    // Define and modify other arrays similarly

    // Menu and Prices for Shop6 and 6
    string stationery[maxStationerySupplies] = {
        "Pen", "Pencil", "Marker", "Notebooks", "Notepads",
        "Sticky notes", "Envelopes", "Stationery paper", "Printer paper", "Ink cartridges"};
    int stationeryPrices[maxStationerySupplies] = {25, 10, 30, 200, 200, 100, 20, 50, 20, 100};

    string deodorants[maxdeodrants] = {
        "Dove", "Degree", "Old Spice", "Axe",
        "Nivea", "Secret", "Speed Stick", "Gillette",
        "Sure", "Mitchum"};
    int deodrantPrices[maxdeodrants] = {250, 190, 300, 200, 200, 190, 200, 500, 200, 200};

    string facewashBrands[maxFacewash] = {
        "Ponds", "Neutrogena", "Clean & Clear", "Aveeno",
        "Olay", "Garnier", "The Body Shop", "Burts Bees",
        "Clinique", "Himalaya Herbals"};
    int facewashPrices[maxFacewash] = {250, 190, 300, 200, 200, 190, 200, 500, 200, 200};

    string chips[maxChips] = {
        "Lays Classic", "Lays Salted", "Lays Masala", "Lays French Cheese", "Lays Tomato Tango",
        "Kurkure Masala Munch", "Kurkure Green Chutney", "Kurkure Red Masala", "Pringles", "Snackers",
        "Potato Chips", "Cheetos", "Pringles Original", "Pringles Sour", "Slanty Vegetable"};
    int chipsPrices[maxChips] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};

    // Define and modify other arrays in a similar way as above

    // drinks

    string perfumes[maxPerfumes] = {
        "J. Fragrances", "Junaid Jamshed", "Ajmal Perfumes", "Al Haramain Perfumes", "Rasasi Perfumes",
        "Gul Ahmed", "MTJ", "Fragrance Station", "The Body Shop", "Engage Perfumes"};
    int perfumePrices[maxPerfumes] = {2500, 1900, 3000, 2000, 2000, 1900, 2000, 5000, 2000, 2000};

    string biscuits[maxBiscuits] = {
        "LU ", "Peek Freans", "Bake Parlor", "Prince", "Rio",
        "Dawn", "Gala", "Marie", "Party", "Peanut Pik"};
    int biscuitsPrices[maxBiscuits] = {40, 40, 40, 40, 40, 40, 40, 40, 40, 40};

    // Menu and Prices for Drinks
    string drinkItems[maxDrinks];

    int drinkPrices[maxDrinks];

    // admin defined employees
    string employees[maxEmployees];
    int employeeSalaries[maxEmployees];

    // admin defined chefs
    string chefs[maxChefs];
    int chefsSalaries[maxChefs];

    // admin defined deliveryboys
    string DeliveryBoys[maxDeliveryBoys];
    int DeliveryBoysSalaries[maxDeliveryBoys];

    // admin defined accountants
    string Accountants[maxAccountants];
    int AccountantsSalaries[maxAccountants];

    // admin defined customer care emp
    string CustomerCares[maxCustomerCare];
    int CustomerCareSalaries[maxCustomerCare];

    // admin defined helpine boy
    string HelplineBoys[maxHelplineBoys];
    int HelplineBoysSalaries[maxHelplineBoys];

    // store notfications
    string notification[totalNotifications];
    // Rules fOR SSC
    string rules[maxRules] = {
        "\t\t\t\t\t\tRespectful Behavior:\n \t\t\t\t\t\t              Maintain respectful and courteous behavior towards staff and other customers at all times.\n",
        "\t\t\t\t\t\tHalal Consumption:\n \t\t\t\t\t\t       Understand and respect the establishments commitment to serving only Halal food if it aligns with \n\t\t\t\t\t\tyour dietary preferences.\n",
        "\t\t\t\t\t\tCleanliness:\n \t\t\t\t\t\t        Dispose of waste properly in designated bins. Keep the dining area clean by clearing tables after use..\n",
        "\t\t\t\t\t\tCultural Sensitivity:\n \t\t\t\t\t\t       Respect cultural norms and customs observed in the cafeteria. Be mindful of others dietary preferences\n\t\t\t\t\t\tand religious practices..\n",
        "\t\t\t\t\t\tPatience and Cooperation:\n \t\t\t\t\t\t        Be patient during busy hours and cooperate with staff requests. Understand that waiting times \n\t\t\t\t\t\tmay vary based on demand..\n",
        "\t\t\t\t\t\tMobile Phone Etiquette:\n \t\t\t\t\t\t          Keep phone conversations brief and avoid loud or disruptive behavior while using mobile devices..\n",
        "\t\t\t\t\t\tPaying Bills:\n \t\t\t\t\t\t        Pay bills promptly and avoid delaying the payment process. Check bills for accuracy and report any discrepancies\n\t\t\t\t\t\t politely to the staff..\n",
        "\t\t\t\t\t\tFeedback:\n \t\t\t\t\t\t      Provide constructive feedback through available channels if there are any concerns or suggestions for improvement..\n",
        "\t\t\t\t\t\tSmoking Regulations:\n \t\t\t\t\t\t           Adhere to designated smoking areas and follow local laws regarding smoking on the premises.\n",
        "\t\t\t\t\t\tOccupancy Duration:\n \t\t\t\t\t\t        Be mindful of the time spent occupying a table during peak hours. If the cafeteria is crowded, try to\n\t\t\t\t\t\t limit your stay to accommodate other customers."};

    // to get feedback by all types of employees
    string ChefSuggestions[maxChefSuggestions];
    string EmployeeSuggestions[maxEmployeeSuggestions];
    string DeliveryBoySuggestions[maxDeliveryBoySuggestions];
    string HelplineBoySuggestions[maxHelplineBoySuggestions];
    string AccountantSuggestions[maxAccountantSuggestions];

    // to get user feedback
    string userComplaints[maxComplaints];
    string userSuggestions[maxSuggestions];
    // to get feeedback for public and chefs

    string userReviewsForPublic[maxReviewsForPublic];
    string userReviewsForChef[maxReviewsForChef];

    // To message Helpline and get a reply
    string userMessages[maxMessages];
    string HelplineLineBoyReplies[maxMessages];
    string messageByHelplineBoy[totalUsers];

    string userInfo[3];
    int totalOrderedItems;

    bool bookedTables[100] = {false}; // Initialize all tables as unbooked

    bool isTrue = true;
    bool loginSuccessfull = false;

    // file handling
    // loading files for all users
    readDataFromCustomersFileInParallelArrays(usernames, passwords, phoneNumbers, addresses, genders, ages, totalUsers);
    readDataFromEmployeesFile(chefUsernames, chefPasswords, chefPhoneNumbers, chefGenders, chefAges, totalChefs, "ChefsSignupData.txt");
    readDataFromEmployeesFile(employeeUsernames, employeePasswords, employeePhoneNumbers, employeeGenders, employeeAges, totalEmployees, "EmployeesSignupData.txt");
    readDataFromEmployeesFile(DeliveryBoyUsernames, DeliveryBoyPasswords, DeliveryBoyPhoneNumbers, DeliveryBoyGenders, DeliveryBoyAges, totalDeliveryBoys, "DeliveryBoysSignupData.txt");
    readDataFromEmployeesFile(HelplineBoyUsernames, HelplineBoyPasswords, HelplineBoyPhoneNumbers, HelplineBoyGenders, HelplineBoyAges, totalHelplineBoys, "HelplineBoysSignupData.txt");
    readDataFromEmployeesFile(AccountantUsernames, AccountantPasswords, AccountantPhoneNumbers, AccountantGenders, AccountantAges, totalAccountants, "AccountantsSignupData.txt");
    readDataFromEmployeesFile(CustomerCareUsernames, CustomerCarePasswords, CustomerCarePhoneNumbers, CustomerCareGenders, CustomerCareAges, totalCustomerCare, "CustomerCaresSignupData.txt");

    // loading all files related to data admin entered
    readDataFromEmployeesInfo(employees, totalEmployeesData, "EmployeesInfo.txt");
    readDataFromEmployeesInfo(chefs, totalChefsData, "ChefsInfo.txt");
    readDataFromEmployeesInfo(Accountants, totalAccountantsData, "AccountantsInfo.txt");
    readDataFromEmployeesInfo(HelplineBoys, totalHelplineBoysData, "HelplineBoysInfo.txt");
    readDataFromEmployeesInfo(DeliveryBoys, totalDeliveryBoysData, "DeliveryBoysInfo.txt");
    readDataFromEmployeesInfo(CustomerCares, totalCustomerCareData, "CustomerCaresInfo.txt");

    readFeedbackData(userReviewsForChef, totalReviewsForChef, "CustomerReviewForChef.txt");
    readFeedbackData(userReviewsForPublic, totalReviewsForPublic, "CustomerReview.txt");

    // loads feedback related files
    readSuggestionsData(DeliveryBoySuggestions, totalDeliveryBoySuggestions, "DeliveryBoySuggestions.txt");
    readSuggestionsData(HelplineBoySuggestions, totalHelplineBoySuggestions, "HelplineBoySuggestions.txt");
    readSuggestionsData(userSuggestions, totalSuggestions, "CustomerSuggestions.txt");
    readSuggestionsData(AccountantSuggestions, totalAccountantSuggestions, "AccountantSuggestions.txt");
    readSuggestionsData(ChefSuggestions, totalChefSuggestions, "ChefSuggestions.txt");
    readSuggestionsData(EmployeeSuggestions, totalEmployeeSuggestions, "EmployeeSuggestions.txt");

    readShopsToFile(shops, totalShops);
    readShopsMenuToFile(foodMenuShop1, foodMenuPricesShop1, totalShop1Items, "Shop1Menu.txt");
    readShopsMenuToFile(foodMenuShop2, foodMenuPricesShop2, totalShop2Items, "Shop2Menu.txt");
    readShopsMenuToFile(foodMenuShop7, foodMenuPricesShop7, totalShop7Items, "Shop7Menu.txt");
    readShopsMenuToFile(foodMenuShop8, foodMenuPricesShop8, totalShop8Items, "Shop8Menu.txt");
    readShopsMenuToFile(foodMenuShop9, foodMenuPricesShop9, totalShop9Items, "Shop9Menu.txt");
    readShopsMenuToFile(foodMenuShop10, foodMenuPricesShop10, totalShop10Items, "Shop10Menu.txt");
    readShopsMenuToFile(foodMenuShop11, foodMenuPricesShop11, totalShop11Items, "Shop11Menu.txt");
    readShopsMenuToFile(foodMenuShop12, foodMenuPricesShop12, totalShop12Items, "Shop12Menu.txt");
    readShopsMenuToFile(drinkItems, drinkPrices, totalDrinks, "Drinks.txt");

    // loads customer complaitns
    readDataFromCustomerComplaintFile(userComplaints, totalComplaints);

    string option;
    while (isTrue) // main while loop
    {
        // first display header and clear screen
        system("cls");
        loginPageHeader();
        bool LogOut = false;
        // role inquire
        hideCursor(0);
        cout << "\33[36m"
             << "\t\t\t\t\t\tProceed as"
             << "\33[0m"
             << "\33[32m"
             << "\n\t\t\t\t\t\t1. Customer \n\t\t\t\t\t\t2. Admin\n\t\t\t\t\t\t3. Chef\n\t\t\t\t\t\t4. Employee \n\t\t\t\t\t\t5. Delivery Boy \n\t\t\t\t\t\t6. Helpline Boy \n\t\t\t\t\t\t7. Accountant\n\t\t\t\t\t\t8. Customer Care\n\t\t\t\t\t\t9. Read Guidlines \n\t\t\t\t\t\t10. Exit";
        int opt = movementOfArrow(45, 17, 1, 10);
        hideCursor(1);

        if (opt == 1)
        {
            system("cls");
            loginPageHeader();
            // Customer Page
            while (isTrue)
            {
                // while loop for 2nd user
                string username, password;
                hideCursor(1);
                cout << "\33[35m"
                     << "\t\t\t\t\t\tDo you want to Sign in or Sign up (Press 1 to Sign in and 2 for Sign up): ";
                getline(cin, option);
                hideCursor(0);
                if (option == "BB") // throughout this program I will use which means Going Back to last page
                {
                    break; // It will break current while loop and go back to previous page
                }
                if (option == "1") // if option is 1
                {
                    system("cls");
                    loginPageHeader();

                    // user sign in page
                    int wrongPassCount = 0;
                again1:
                    hideCursor(1);
                    cout << "\33[36m"
                         << "\t\t\t\t\t\tEnter username: ";

                    getline(cin, username);
                    if (username == "BB") // go back
                    {
                        break;
                    }
                    if (username.length() < 6 || username.length() > 10 || hasTabs(username)) // making sure no comma is present
                    {
                        cout << "\33[31m"
                             << "\t\t\t\t\t\tInvalid Username. \n";
                        cls();
                        loginPageHeader();
                        goto again1;
                    }
                    if (!noComma(username))
                    {
                        cls();
                        loginPageHeader();
                        goto again1;
                    }
                    if (empty(username))
                    {
                        continue;
                    }

                    cout << "\33[36m"
                         << "\t\t\t\t\t\tEnter password: ";
                    getline(cin, password);
                    hideCursor(0);
                    if (isExistingUser(usernames, passwords, totalUsers, username, password)) // checks for existing user
                    {
                        cout << "\33[33m"
                             << "\t\t\t\t\t\tLogin successful! Welcome, " << username << "!" << endl; // condition is true login succeeded
                        loadingFunction();
                        loginSuccessfull = true;
                    }
                    else
                    {
                        wrongPassCount++;
                        if (wrongPassCount == 5)
                        {
                            wrongPassCount = 0;
                            forgotPassword(usernames, passwords, ages, genders, phoneNumbers, addresses, totalUsers);
                            goto again1;
                        }
                        cout << "\33[31m"
                             << "\t\t\t\t\t\tInvalid username or password. Please try again." << endl; // Invalid user

                        cls();
                        loginPageHeader();
                        goto again1;
                    }

                    if (loginSuccessfull) // if login is succesfull i display menu
                    {
                        loadingFunction();
                        while (true)
                        {
                            system("cls");
                            header();
                            int choice = customerMenu(); // receive an option from customer and store in choice variable to navigate pages
                            if (choice == 1)
                            {
                                system("cls");
                                header();
                                string input = displayShops(shops, totalShops); // receive an input from customer and store in input variable to navigate pages
                                if (input == "BB")                              // go back
                                {
                                    continue;
                                }
                                else if (input == "1") // displays shop 1 menu where user can order food, after ordering or coming back user goes back to menu
                                {
                                    system("cls");
                                    header();
                                    orderNum = 0;
                                    totalPrice = 0;
                                    shop1(foodMenuShop1, foodMenuPricesShop1, totalShop1Items, orderedItems1, orderedItemsQuantity1, orderedItemsPrices1, userIdentity1);
                                }
                                else if (input == "2") // displays shop 2 menu where user can order food
                                {
                                    system("cls");
                                    header();
                                    orderNum = 0;
                                    totalPrice = 0;
                                    shop2(foodMenuShop2, foodMenuPricesShop2, totalShop2Items, orderedItems2, orderedItemsQuantity2, orderedItemsPrices2, userIdentity2);
                                }
                                else if (input == "3" || input == "4") // displays shop 3 or 4 menu where user cant order food
                                {
                                    system("cls");
                                    header();
                                    shop3(); // it is a minor shop and doesnt offer much services
                                }
                                else if (input == "5" || input == "6") // displays shop 5 menu where user can order food
                                {
                                    system("cls");
                                    header();
                                    shop5(stationery, stationeryPrices, deodorants, deodrantPrices, facewashBrands, facewashPrices, chips, chipsPrices, perfumes, perfumePrices, biscuits, biscuitsPrices, drinkItems, drinkPrices, totalStationarySupplies, totalDeodrants, totalFacewash, totalchips, totalPerfumes, totalBiscuits, totalDrinks);
                                    // this shop doesnt provide ordering services
                                }
                                else if (input == "7") // displays shop 7 menu where user can order food
                                {
                                    system("cls");
                                    header();
                                    orderNum = 0;
                                    totalPrice = 0;
                                    shop7(foodMenuShop7, foodMenuPricesShop7, totalShop7Items, orderedItems7, orderedItemsQuantity7, orderedItemsPrices7, userIdentity7);
                                }
                                else if (input == "8") // displays shop 8 menu where user can order food
                                {
                                    system("cls");
                                    header();
                                    orderNum = 0;
                                    totalPrice = 0;
                                    shop8(foodMenuShop8, foodMenuPricesShop8, totalShop8Items, orderedItems8, orderedItemsQuantity8, orderedItemsPrices8, userIdentity8);
                                }
                                else if (input == "9") // displays shop 9 menu where user can order food
                                {
                                    system("cls");
                                    header();
                                    orderNum = 0;
                                    totalPrice = 0;
                                    shop9(foodMenuShop9, foodMenuPricesShop9, totalShop9Items, orderedItems9, orderedItemsQuantity9, orderedItemsPrices9, userIdentity9);
                                }
                                else if (input == "10") // displays shop 10 menu where user can order food
                                {
                                    system("cls");
                                    header();
                                    orderNum = 0;
                                    totalPrice = 0;
                                    shop10(foodMenuShop10, foodMenuPricesShop10, totalShop10Items, orderedItems10, orderedItemsQuantity10, orderedItemsPrices10, userIdentity10);
                                }
                                else if (input == "11") // displays shop 11 menu where user can order food
                                {
                                    system("cls");
                                    header();
                                    orderNum = 0;
                                    totalPrice = 0;
                                    shop11(foodMenuShop11, foodMenuPricesShop11, totalShop11Items, orderedItems11, orderedItemsQuantity11, orderedItemsPrices11, userIdentity11);
                                }
                                else if (input == "12") // displays shop 12 menu where user can order food
                                {
                                    system("cls");
                                    header();
                                    orderNum = 0;
                                    totalPrice = 0;
                                    shop12(foodMenuShop12, foodMenuPricesShop12, totalShop12Items, orderedItems12, orderedItemsQuantity12, orderedItemsPrices12, userIdentity12);
                                }
                            }

                            else if (choice == 2) // displays drinks menu where user can order drinks
                            {
                                system("cls");
                                header();
                                orderNum = 0;
                                totalPrice = 0;
                                drinksOrder(drinkItems, drinkPrices, totalDrinks, orderedDrinks, orderedDrinksQuantity, orderedDrinksPrices, userIdentity9);
                            }
                            else if (choice == 3) // booking table function
                            {
                                system("cls");
                                header();
                                performTableAction(bookedTables, userInfo);
                            }
                            else if (choice == 4) // take suggestion from userr
                            {
                                system("cls");
                                header();
                                takeSuggestion(userSuggestions, totalSuggestions);
                                UpdateSuggestionsData(userSuggestions, totalSuggestions, "CustomerSuggestions.txt");
                            }
                            else if (choice == 5) // take complaints from user
                            {
                                system("cls");
                                header();
                                takeComplaint(userComplaints, totalComplaints);
                                UpdateDataToFileForCustomerComplaint(userComplaints, totalComplaints);
                            }
                            else if (choice == 6) // user can give reviews about food and overall ssc here
                            {
                                system("cls");
                                header();
                                string receive = reviewType();
                                if (receive == "1")
                                {
                                    system("cls");
                                    header();
                                    takeReviewsForChef(userReviewsForChef, totalReviewsForChef);
                                    UpdateFeedbackData(userReviewsForChef, totalReviewsForChef, "CustomerReviewForChef.txt");
                                }
                                else if (receive == "2")
                                {
                                    system("cls");
                                    header();
                                    takeReviewsForPublic(userReviewsForPublic, totalReviewsForPublic);
                                    UpdateFeedbackData(userReviewsForPublic, totalReviewsForPublic, "CustomerReview.txt");
                                }
                                else if (receive == "BB") // if he enters bb we return
                                {
                                    continue;
                                }
                            }
                            else if (choice == 7) // shows notifications sent by admin
                            {
                                system("cls");
                                header();
                                viewNotifications(notification, totalNotifications);
                            }
                            else if (choice == 8) // shows rules added by admin
                            {
                                system("cls");
                                header();
                                displayRules(rules, currentRules);
                            }
                            else if (choice == 9) // message helpline by admin
                            {
                                system("cls");
                                header();
                                messageToHelplineBoyByCustomer(username, messageByHelplineBoy, userMessages, HelplineLineBoyReplies, totalMessages, totalHelplineBoyMessages, totalUsers);
                            }
                            else if (choice == 10) // ssc about section
                            {
                                system("cls");
                                header();
                                aboutUs();
                            }
                            else if (choice == 11) // changing password of user
                            {
                                changePassword(usernames, passwords, totalUsers, username);
                                UpdateDataToFileForCustomerParallelArrays(usernames, passwords, phoneNumbers, addresses, genders, ages, totalUsers);
                            }
                            else if (choice == 14) // log out
                            {
                                string in;
                                system("cls");
                                header();
                                hideCursor(1);
                                cout << "\33[0m";
                                cout << "\33[31m"
                                     << "\t\t\t\t\t\tAre you sure you want to Log Out(Yes or No)? "
                                     << "\33[0m";
                                getline(cin, in);
                                hideCursor(0);
                                if (in == "Yes" || in == "yes" || in == "YES")
                                {
                                    LogOut = true;
                                    break;
                                }
                                else
                                {
                                    continue;
                                }
                            }
                            else if (choice == 15) // exits the program
                            {
                                loadingFunction();
                                exit(0);
                            }
                            else if (choice == 13) // delete account by user
                            {
                                system("cls");
                                header();
                                string in;
                                hideCursor(1);
                                SetConsoleTextAttribute(hConsole, 4);
                                cout
                                    << "\t\t\t\t\t\tAre you sure you want to delete account (Yes/No)? ";
                                getline(cin, in);
                                hideCursor(0);
                                if (in == "Yes" || in == "yes" || in == "YES")
                                {
                                    deleteUser(usernames, passwords, ages, genders, phoneNumbers, totalUsers, username);
                                    UpdateDataToFileForCustomerParallelArrays(usernames, passwords, phoneNumbers, addresses, genders, ages, totalUsers); // if user deletes account then data is saved in this file
                                    break;
                                }
                                else
                                {
                                    continue;
                                }
                            }
                            else if (choice == 12)
                            {
                                changeUsername(usernames, totalUsers, username);                                                                     // change username
                                UpdateDataToFileForCustomerParallelArrays(usernames, passwords, phoneNumbers, addresses, genders, ages, totalUsers); // update in file
                            }
                        }
                        if (LogOut)
                        {
                            break;
                        }
                    }
                }
                else if (option == "2") // customer login
                {
                    if (totalUsers < maxUsers)
                    {
                        getUserInput(usernames, passwords, ages, genders,
                                     phoneNumbers, addresses, totalUsers);
                        UpdateDataToFileForCustomerParallelArrays(usernames, passwords, phoneNumbers, addresses, genders, ages, totalUsers);
                    }
                    else
                    {
                        cout << "\33[31m"
                             << "\t\t\t\t\t\tMaximum number of users reached. Cannot register more users." << endl;
                        cls();
                        loginPageHeader();
                    }
                }
                else
                {
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tWrong input. Enter 1 to Sign in and 2 for Sign up." << endl;
                    cls();
                    loginPageHeader();
                }
            }
        }
        else if (opt == 2)
        {
            system("cls");
            loginPageHeader();
            string adminUsername, adminPassword;
            hideCursor(1);
            cout << "\33[36m"
                 << "\t\t\t\t\t\tEnter username: ";
            getline(cin, adminUsername);
            hideCursor(0);
            if (adminUsername == "BB") // go back
            {
                continue;
            }

            if (empty(adminUsername) || hasTabs(adminUsername) || !noComma(adminUsername)) // empty username
            {
                continue;
            }
            hideCursor(1);
            cout << "\33[36m"
                 << "\t\t\t\t\t\tEnter password: ";

            char ch;
            while (true)
            {
                ch = _getch();

                if (ch == 13)
                {
                    break;
                }
                else if (ch == 8)
                {
                    if (!adminPassword.empty())
                    {
                        cout << "\b \b";
                        adminPassword.pop_back();
                    }
                }
                else
                {
                    if (isValidChar(ch))
                    {
                        cout << '*';
                        adminPassword += ch;
                    }
                }
            }
            hideCursor(0);
            cout << "\n";
            // checking if admin exists
            if (isExistingAdmin(adminUsernames, adminPasswords, totalAdmins, adminUsername, adminPassword))
            {
                int inTake;
                system("cls");
                loginPageHeader();
                cout << "\33[33m"
                     << "\t\t\t\t\t\tAdmin Login successful! Welcome, " << adminUsername << "!" << endl;
                loadingFunction();
                while (true)
                {
                    system("cls");
                    header();
                    int input = adminMenu();
                    if (input == 1)
                    {
                        system("cls");
                        header();
                        int inTake = selectFromAdminOption1(); // menu option 1 sub options
                        // managerial roles of admin
                        if (inTake == 1)
                        {
                            system("cls");
                            header();
                            manageShops(shops, totalShops);
                        }
                        else if (inTake == 2)
                        {
                            system("cls");
                            header();
                            string shopNumber = shopToHandle(shops, totalShops);
                            // selecting shop menu to edit
                            if (shopNumber == "1")
                            {
                                system("cls");
                                header();
                                manageShopMenu(foodMenuShop1, foodMenuPricesShop1, totalShop1Items);
                                storeShopsMenuToFile(foodMenuShop1, foodMenuPricesShop1, totalShop1Items, "Shop1Menu.txt");
                            }

                            else if (shopNumber == "2")
                            {
                                system("cls");
                                header();
                                manageShopMenu(foodMenuShop2, foodMenuPricesShop2, totalShop2Items);
                                storeShopsMenuToFile(foodMenuShop2, foodMenuPricesShop2, totalShop2Items, "Shop2Menu.txt");
                            }
                            else if (shopNumber == "7")
                            {
                                system("cls");
                                header();
                                manageShopMenu(foodMenuShop7, foodMenuPricesShop7, totalShop7Items);
                                storeShopsMenuToFile(foodMenuShop7, foodMenuPricesShop7, totalShop7Items, "Shop7Menu.txt");
                            }
                            else if (shopNumber == "8")
                            {
                                system("cls");
                                header();
                                manageShopMenu(foodMenuShop8, foodMenuPricesShop8, totalShop8Items);
                                storeShopsMenuToFile(foodMenuShop8, foodMenuPricesShop8, totalShop8Items, "Shop8Menu.txt");
                            }
                            else if (shopNumber == "9")
                            {
                                system("cls");
                                header();
                                manageShopMenu(foodMenuShop9, foodMenuPricesShop9, totalShop9Items);
                                storeShopsMenuToFile(foodMenuShop9, foodMenuPricesShop9, totalShop9Items, "Shop9Menu.txt");
                            }
                            else if (shopNumber == "10")
                            {
                                system("cls");
                                header();
                                manageShopMenu(foodMenuShop10, foodMenuPricesShop10, totalShop10Items);
                                storeShopsMenuToFile(foodMenuShop10, foodMenuPricesShop10, totalShop10Items, "Shop10Menu.txt");
                            }
                            else if (shopNumber == "11")
                            {
                                system("cls");
                                header();
                                manageShopMenu(foodMenuShop11, foodMenuPricesShop11, totalShop11Items);
                                storeShopsMenuToFile(foodMenuShop11, foodMenuPricesShop11, totalShop11Items, "Shop11Menu.txt");
                            }
                            else if (shopNumber == "12")
                            {
                                system("cls");
                                header();
                                manageShopMenu(foodMenuShop12, foodMenuPricesShop12, totalShop12Items);
                                storeShopsMenuToFile(foodMenuShop12, foodMenuPricesShop12, totalShop12Items, "Shop12Menu.txt");
                            }
                            else if (shopNumber == "BB")
                            {
                                continue;
                            }
                        }
                        // manage drinks menu
                        else if (inTake == 3)
                        {
                            system("cls");
                            header();
                            manageDrinksMenu(drinkItems, drinkPrices, totalDrinks);
                            storeShopsMenuToFile(drinkItems, drinkPrices, totalDrinks, "Drinks.txt");
                        }
                        // manage employee
                        else if (inTake == 4)
                        {
                            system("cls");
                            header();
                            employeeManager(employees, totalEmployeesData);
                            UpdateDataToFileForEmployeesInfo(employees, totalEmployeesData, "EmployeesInfo.txt");
                        }
                        // manage chefs
                        else if (inTake == 5)
                        {
                            system("cls");
                            header();
                            employeeManager(chefs, totalChefsData);
                            UpdateDataToFileForEmployeesInfo(chefs, totalChefsData, "ChefsInfo.txt");
                        }
                        // manage delivery boys
                        else if (inTake == 6)
                        {
                            system("cls");
                            header();
                            employeeManager(DeliveryBoys, totalDeliveryBoysData);
                            UpdateDataToFileForEmployeesInfo(DeliveryBoys, totalDeliveryBoysData, "DeliveryBoysInfo.txt");
                        }
                        // manage helpline boy
                        else if (inTake == 7)
                        {
                            system("cls");
                            header();
                            employeeManager(HelplineBoys, totalHelplineBoysData);
                            UpdateDataToFileForEmployeesInfo(HelplineBoys, totalHelplineBoysData, "HelplineBoysInfo.txt");
                        }
                        // manage customer service
                        else if (inTake == 8)
                        {
                            system("cls");
                            header();
                            employeeManager(CustomerCares, totalCustomerCareData);
                            UpdateDataToFileForEmployeesInfo(CustomerCares, totalCustomerCareData, "CustomerCaresInfo.txt");
                        }
                        // manage accountants
                        else if (inTake == 9)
                        {
                            system("cls");
                            header();
                            employeeManager(Accountants, totalAccountantsData);
                            UpdateDataToFileForEmployeesInfo(Accountants, totalAccountantsData, "AccountantsInfo.txt");
                        }
                        else if (inTake == 10)
                        {
                            continue;
                        }
                    }

                    // views registered users data
                    else if (input == 2)
                    {
                        system("cls");
                        header();
                        inTake = selectFromAdminOption2(); // option 2 sub menu
                        // view employees data
                        if (inTake == 1)
                        {
                            system("cls");
                            header();
                            viewEmployeesData(employeeUsernames, employeePasswords, totalEmployees, employeeAges, employeeGenders, employeePhoneNumbers);
                        }
                        else if (inTake == 2)
                        {
                            system("cls");
                            header();
                            viewEmployeesData(chefUsernames, chefPasswords, totalChefs, chefAges, chefGenders, chefPhoneNumbers);
                        }
                        else if (inTake == 3)
                        {
                            system("cls");
                            header();
                            viewEmployeesData(DeliveryBoyUsernames, DeliveryBoyPasswords, totalDeliveryBoys, DeliveryBoyAges, DeliveryBoyGenders, DeliveryBoyPhoneNumbers);
                        }
                        else if (inTake == 4)
                        {
                            system("cls");
                            header();
                            viewEmployeesData(HelplineBoyUsernames, HelplineBoyPasswords, totalHelplineBoys, HelplineBoyAges, HelplineBoyGenders, HelplineBoyPhoneNumbers);
                        }
                        else if (inTake == 5)
                        {
                            system("cls");
                            header();
                            viewEmployeesData(CustomerCareUsernames, CustomerCarePasswords, totalCustomerCare, CustomerCareAges, CustomerCareGenders, CustomerCarePhoneNumbers);
                        }
                        else if (inTake == 6)
                        {
                            system("cls");
                            header();
                            viewEmployeesData(AccountantUsernames, AccountantPasswords, totalAccountants, AccountantAges, AccountantGenders, AccountantPhoneNumbers);
                        }
                        else if (inTake == 7)
                        {
                            system("cls");
                            header();
                            viewUsersData(usernames, passwords, totalUsers, ages, genders, phoneNumbers, addresses);
                        }
                        else if (inTake == 8)
                        {
                            continue;
                        }
                    }

                    // removing or updating data of users
                    else if (input == 3)
                    {
                        system("cls");
                        header();
                        inTake = selectFromAdminOption3();
                        if (inTake == 1)
                        {
                            system("cls");
                            header();
                            removeEmployeeAccount(employeeUsernames, employeePasswords, employeeAges, employeeGenders, employeePhoneNumbers, totalEmployees);
                            updateDataToEmployeesFile(employeeUsernames, employeePasswords, employeePhoneNumbers, employeeGenders, employeeAges, totalEmployees, "EmployeesSignUpData.txt");
                        }
                        else if (inTake == 2)
                        {
                            system("cls");
                            header();
                            removeEmployeeAccount(chefUsernames, chefPasswords, chefAges, chefGenders, chefPhoneNumbers, totalChefs);
                            updateDataToEmployeesFile(chefUsernames, chefPasswords, chefAges, chefGenders, chefPhoneNumbers, totalChefs, "ChefsSignUpData.txt");
                        }
                        else if (inTake == 3)
                        {
                            system("cls");
                            header();
                            removeEmployeeAccount(DeliveryBoyUsernames, DeliveryBoyPasswords, DeliveryBoyAges, DeliveryBoyGenders, DeliveryBoyPhoneNumbers, totalDeliveryBoys);
                            updateDataToEmployeesFile(DeliveryBoyUsernames, DeliveryBoyPasswords, DeliveryBoyAges, DeliveryBoyGenders, DeliveryBoyPhoneNumbers, totalDeliveryBoys, "DeliveryBoysSignUpData.txt");
                        }
                        else if (inTake == 4)
                        {
                            system("cls");
                            header();
                            removeEmployeeAccount(HelplineBoyUsernames, HelplineBoyPasswords, HelplineBoyAges, HelplineBoyGenders, HelplineBoyPhoneNumbers, totalHelplineBoys);
                            updateDataToEmployeesFile(HelplineBoyUsernames, HelplineBoyPasswords, HelplineBoyAges, HelplineBoyGenders, HelplineBoyPhoneNumbers, totalHelplineBoys, "HelplineBoysSignUpData.txt");
                        }
                        else if (inTake == 5)
                        {
                            system("cls");
                            header();
                            removeEmployeeAccount(CustomerCareUsernames, CustomerCarePasswords, CustomerCareAges, CustomerCareGenders, CustomerCarePhoneNumbers, totalCustomerCare);
                            updateDataToEmployeesFile(CustomerCareUsernames, CustomerCarePasswords, CustomerCareAges, CustomerCareGenders, CustomerCarePhoneNumbers, totalCustomerCare, "CustomerCaresSignUpData.txt");
                        }
                        else if (inTake == 6)
                        {
                            system("cls");
                            header();
                            removeEmployeeAccount(AccountantUsernames, AccountantPasswords, AccountantAges, AccountantGenders, AccountantPhoneNumbers, totalAccountants);
                            updateDataToEmployeesFile(AccountantUsernames, AccountantPasswords, AccountantPhoneNumbers, AccountantGenders, AccountantAges, totalAccountants, "AccountantsSignupData.txt");
                        }
                        else if (inTake == 7)
                        {
                            system("cls");
                            header();
                            removeUser(usernames, passwords, ages, genders, phoneNumbers, totalUsers);
                            UpdateDataToFileForCustomerParallelArrays(usernames, passwords, phoneNumbers, addresses, genders, ages, totalUsers);
                        }
                        else if (inTake == 8)
                        {
                            continue;
                        }
                    }
                    // change admin username
                    else if (input == 7)
                    {
                        changeAdminUsername(adminUsernames, totalAdmins, adminUsername);
                    }
                    // add rules
                    else if (input == 5)
                    {
                        system("cls");
                        header();
                        addRules(rules, currentRules);
                    }
                    // send notification
                    else if (input == 6)
                    {
                        system("cls");
                        header();
                        notifyUsers(notification, totalNotifications);
                    }
                    // change password
                    else if (input == 8)
                    {
                        system("cls");
                        header();
                        changePasswordAdmin(adminUsernames, adminPasswords, totalAdmins, adminUsername, adminPassword);
                    }
                    // log out
                    else if (input == 10)
                    {
                        system("cls");
                        header();
                        string out;
                        SetConsoleTextAttribute(hConsole, 4);
                        hideCursor(1);
                        cout
                            << "\t\t\t\t\t\tAre you sure you want to Log Out(Yes or No)? ";
                        getline(cin, out);
                        hideCursor(0);
                        if (out == "Yes" || out == "yes" || out == "YES")
                        {
                            // storeShopData(shops, totalShops, "Shops.txt");
                            LogOut = true;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    // exit
                    else if (input == 11)
                    {
                        // storeShopData(shops, totalShops, "Shops.txt");
                        loadingFunction();
                        exit(0);
                    }
                    // delete account
                    else if (input == 9)
                    {
                        string confirm;
                        system("cls");
                        header();
                        SetConsoleTextAttribute(hConsole, 4);
                        hideCursor(1);
                        cout
                            << "\t\t\t\t\t\tAre you sure you want to Delete account (1 to delete and any other key to Continue)? ";
                        getline(cin, confirm);
                        hideCursor(0);
                        if (confirm == "1")
                        {
                            deleteAdmin(adminUsernames, adminPasswords, totalAdmins, adminUsername);
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    // add admin
                    else if (input == 4)
                    {
                        system("cls");
                        header();
                        addAdmin(adminUsernames, adminPasswords, totalAdmins);
                    }
                }
            }
            else
            {
                // invalid data
                cout << "\33[31m"
                     << "\t\t\t\t\t\tInvalid username or password. Please try again." << endl;
                cls();
            }
        }
        // same logic as above users have
        else if (opt == 3)
        {
            system("cls");
            loginPageHeader();
            string key;
            hideCursor(1);
            cout << "\33[32m"
                 << "\t\t\t\t\t\tEnter key: ";
            // asking for key to continue
            getline(cin, key);
            hideCursor(0);
            if (key != "123")
            {
                continue;
            }
            if (key == "BB")
            {
                continue;
            }
            hideCursor(1);
            cout << "\33[35m"
                 << "\t\t\t\t\t\tDo you want to Sign in or Sign up (Press 1 to Sign in and 2 for Sign up): ";
            getline(cin, option);
            hideCursor(0);
            if (option == "BB")
            {
                continue;
            }
            if (option == "1")
            {
                system("cls");
                loginPageHeader();
                string chefUsername, chefPassword;
            again2:
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter username: ";
                getline(cin, chefUsername);
                hideCursor(0);
                if (chefUsername == "BB")
                {
                    continue;
                }
                if (empty(chefUsername) || hasTabs(chefUsername) || chefUsername.length() < 6 || chefUsername.length() > 10 || !noComma(chefUsername))
                {
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tInvalid Username \n";
                    cls();
                    loginPageHeader();
                    goto again2;
                }
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter password: ";
                getline(cin, chefPassword);
                hideCursor(0);

                if (isExistingEmployee(chefUsernames, chefPasswords, totalChefs, chefUsername, chefPassword))
                {
                    system("cls");
                    loginPageHeader();
                    cout << "\33[33m"
                         << "\t\t\t\t\t\tChef Login successful! Welcome, " << chefUsername << "!" << endl;
                    loadingFunction();
                    while (true)
                    {
                        system("cls");
                        header();
                        int selectMenu = chefMenu();
                        if (selectMenu == 1)
                        {
                            system("cls");
                            header();
                            string selectChefShop = chefSelectShop(shops, totalShops);
                            if (selectChefShop == "1")
                            {
                                system("cls");
                                header();
                                viewOrdersShop1(orderedItems1, orderedItemsQuantity1);
                                cls();
                            }
                            else if (selectChefShop == "2")
                            {
                                system("cls");
                                header();
                                viewOrdersShop2(orderedItems2, orderedItemsQuantity2);
                                cls();
                            }
                            else if (selectChefShop == "3")
                            {
                                system("cls");
                                header();
                                invalidShop();
                                cls();
                            }
                            else if (selectChefShop == "4")
                            {
                                system("cls");
                                header();
                                invalidShop();
                                cls();
                            }
                            else if (selectChefShop == "5")
                            {
                                system("cls");
                                header();
                                invalidShop();
                                cls();
                            }
                            else if (selectChefShop == "6")
                            {
                                system("cls");
                                header();
                                invalidShop();
                                cls();
                            }
                            else if (selectChefShop == "7")
                            {
                                system("cls");
                                header();
                                viewOrdersShop7(orderedItems7, orderedItemsQuantity7);
                                cls();
                            }
                            else if (selectChefShop == "8")
                            {
                                system("cls");
                                header();
                                viewOrdersShop8(orderedItems8, orderedItemsQuantity8);
                                cls();
                            }
                            else if (selectChefShop == "9")
                            {
                                system("cls");
                                header();
                                viewOrdersShop9(orderedItems9, orderedItemsQuantity9);
                                cls();
                            }
                            else if (selectChefShop == "10")
                            {
                                system("cls");
                                header();
                                viewOrdersShop10(orderedItems10, orderedItemsQuantity10);
                                cls();
                            }
                            else if (selectChefShop == "11")
                            {
                                system("cls");
                                header();
                                viewOrdersShop11(orderedItems11, orderedItemsQuantity11);
                                cls();
                            }
                            else if (selectChefShop == "12")
                            {
                                system("cls");
                                header();
                                viewOrdersShop12(orderedItems12, orderedItemsQuantity12);
                                cls();
                            }
                            else if (selectChefShop == "BB")
                            {
                                continue;
                            }
                        }
                        else if (selectMenu == 2)
                        {
                            system("cls");
                            header();
                            takeEmployeeSuggestion(ChefSuggestions, totalChefSuggestions);
                        }
                        else if (selectMenu == 3)
                        {
                            system("cls");
                            header();
                            viewReviewsByChef(userReviewsForChef, totalReviewsForChef);
                        }
                        else if (selectMenu == 5)
                        {
                            system("cls");
                            header();
                            changePasswordEmployee(chefUsernames, chefPasswords, totalChefs, chefUsername, chefPassword);
                            updateDataToEmployeesFile(chefUsernames, chefPasswords, chefPhoneNumbers, chefGenders, chefAges, totalChefs, "ChefsSignUpData.txt");
                        }
                        else if (selectMenu == 6)
                        {
                            system("cls");
                            header();
                            string ou;
                            hideCursor(1);
                            cout << "\33[31m"
                                 << "\t\t\t\t\t\tAre you sure you want to Log Out(Yes or No)? ";
                            getline(cin, ou);
                            hideCursor(0);
                            if (ou == "Yes" || ou == "yes" || ou == "YES")
                            {
                                LogOut = true;
                                UpdateSuggestionsData(ChefSuggestions, totalChefSuggestions, "ChefSuggestions.txt");
                                break;
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (selectMenu == 7)
                        {
                            loadingFunction();
                            UpdateSuggestionsData(ChefSuggestions, totalChefSuggestions, "ChefSuggestions.txt");
                            exit(0);
                        }
                        else if (selectMenu == 4)
                        {
                            system("cls");
                            header();
                            int x = 20;
                            x = viewAccountBalance(chefs, chefUsername, totalChefsData);
                            if (x != 234)
                            {
                                system("cls");
                                header();
                                ChefBalance(chefs, chefsSalaries, x);
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
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tInvalid username or password. Please try again." << endl;
                    cls();
                    loginPageHeader();
                    goto again2;
                }
            }
            else if (option == "2")
            {
                if (totalChefs < maxChefs)
                {
                    getEmployeesInput(chefUsernames, chefPasswords, chefAges, chefGenders,
                                      chefPhoneNumbers, totalChefs);
                    updateDataToEmployeesFile(chefUsernames, chefPasswords, chefPhoneNumbers, chefGenders, chefAges, totalChefs, "ChefsSignUpData.txt");
                }
                else
                {
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tMaximum number of chefs reached. Cannot register more chefs." << endl;
                    cls();
                    loginPageHeader();
                }
            }
        }
        else if (opt == 4)
        {
            system("cls");
            loginPageHeader();
            string key;
            hideCursor(1);
            cout << "\33[32m"
                 << "\t\t\t\t\t\tEnter key: ";
            getline(cin, key);
            hideCursor(0);
            if (key != "123")
            {
                continue;
            }
            if (key == "BB")
            {
                continue;
            }
            hideCursor(1);
            cout << "\33[35m"
                 << "\t\t\t\t\t\tDo you want to Sign in or Sign up (Press 1 to Sign in and 2 for Sign up): ";
            getline(cin, option);
            hideCursor(0);
            if (option == "BB")
            {
                continue;
            }
            if (option == "1")
            {
                system("cls");
                loginPageHeader();
                string employeeUsername, employeePassword;
            again3:
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter username: ";
                getline(cin, employeeUsername);
                hideCursor(0);
                if (employeeUsername == "BB")
                {
                    continue;
                }
                if (empty(employeeUsername) || employeeUsername.length() < 6 || employeeUsername.length() > 10 || hasTabs(employeeUsername) || !noComma(employeeUsername))
                {
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tInvalid Username\n ";
                    cls();
                    loginPageHeader();
                    goto again3;
                }
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter password: ";
                getline(cin, employeePassword);
                hideCursor(0);

                if (isExistingEmployee(employeeUsernames, employeePasswords, totalEmployees, employeeUsername, employeePassword))
                {
                    system("cls");
                    loginPageHeader();
                    cout << "\33[33m"
                         << "\t\t\t\t\t\tEmployee Login successful! Welcome, " << employeeUsername << "!" << endl;
                    loadingFunction();
                    while (true)
                    {
                        system("cls");
                        header();
                        int selectMenu = EmployeeMenu();
                        if (selectMenu == 1)
                        {
                            system("cls");
                            header();
                            displayShopsEmployee(shops, totalShops);
                        }
                        else if (selectMenu == 2)
                        {
                            system("cls");
                            header();
                            viewAllTablesStatus(bookedTables);
                        }
                        else if (selectMenu == 3)
                        {
                            system("cls");
                            header();
                            takeEmployeeSuggestion(EmployeeSuggestions, totalEmployeeSuggestions);
                        }
                        else if (selectMenu == 4)
                        {
                            system("cls");
                            header();
                            changePasswordEmployee(employeeUsernames, employeePasswords, totalEmployees, employeeUsername, employeePassword);
                            updateDataToEmployeesFile(employeeUsernames, employeePasswords, employeePhoneNumbers, employeeGenders, employeeAges, totalEmployees, "EmployeesSignUpData.txt");
                        }
                        else if (selectMenu == 6)
                        {
                            system("cls");
                            header();
                            string ou;
                            hideCursor(1);
                            cout << "\33[31m"
                                 << "\t\t\t\t\t\tAre you sure you want to Log Out(Yes or No)? ";
                            getline(cin, ou);
                            hideCursor(0);
                            if (ou == "Yes" || ou == "yes" || ou == "YES")
                            {
                                LogOut = true;
                                UpdateSuggestionsData(EmployeeSuggestions, totalEmployeeSuggestions, "EmployeeSuggestions.txt");
                                break;
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (selectMenu == 7)
                        {
                            loadingFunction();
                            UpdateSuggestionsData(EmployeeSuggestions, totalEmployeeSuggestions, "EmployeeSuggestions.txt");
                            exit(0);
                        }
                        else if (selectMenu == 5)
                        {
                            system("cls");
                            header();
                            int x = 2500;
                            x = viewAccountBalance(employees, employeeUsername, totalEmployeesData);
                            if (x != 234)
                            {
                                system("cls");
                                header();
                                EmployeeBalance(employees, employeeSalaries, x);
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
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tInvalid username or password. Please try again." << endl;
                    cls();
                    loginPageHeader();
                    goto again3;
                }
            }
            else if (option == "2")
            {
                if (totalEmployees < maxEmployees)
                {
                    getEmployeesInput(employeeUsernames, employeePasswords, employeeAges, employeeGenders,
                                      employeePhoneNumbers, totalEmployees);
                    updateDataToEmployeesFile(employeeUsernames, employeePasswords, employeePhoneNumbers, employeeGenders, employeeAges, totalEmployees, "EmployeesSignUpData.txt");
                }
                else
                {

                    cout << "\33[31m"
                         << "\t\t\t\t\t\tMaximum number of Employees reached. Cannot register more Employees." << endl;
                    cls();
                    loginPageHeader();
                }
            }
        }
        else if (opt == 5)
        {
            system("cls");
            loginPageHeader();
            string key;
            hideCursor(1);
            cout << "\33[32m"
                 << "\t\t\t\t\t\tEnter key: ";
            getline(cin, key);
            hideCursor(0);
            if (key != "123")
            {
                continue;
            }
            if (key == "BB")
            {
                continue;
            }
            hideCursor(1);
            cout << "\33[35m"
                 << "\t\t\t\t\t\tDo you want to Sign in or Sign up (Press 1 to Sign in and 2 for Sign up): ";
            getline(cin, option);
            hideCursor(0);
            if (option == "BB")
            {
                continue;
            }
            if (option == "1")
            {
                system("cls");
                loginPageHeader();
                string DeliveryBoyUsername, DeliveryBoyPassword;
            again4:
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter username: ";
                getline(cin, DeliveryBoyUsername);
                hideCursor(0);
                if (DeliveryBoyUsername == "BB")
                {
                    continue;
                }
                if (empty(DeliveryBoyUsername) || hasTabs(DeliveryBoyUsername) || DeliveryBoyUsername.length() < 6 || DeliveryBoyUsername.length() > 10 || !noComma(DeliveryBoyUsername))
                {
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tUsername Invalid" << endl;
                    cls();
                    loginPageHeader();
                    goto again4;
                }
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter password: ";
                getline(cin, DeliveryBoyPassword);
                hideCursor(0);
                if (isExistingEmployee(DeliveryBoyUsernames, DeliveryBoyPasswords, totalDeliveryBoys, DeliveryBoyUsername, DeliveryBoyPassword))
                {
                    system("cls");
                    loginPageHeader();
                    cout << "\33[33m"
                         << "\t\t\t\t\t\tDelivery Boy Login successful! Welcome, " << DeliveryBoyUsername << "!" << endl;
                    loadingFunction();
                    while (true)
                    {
                        system("cls");
                        header();
                        int selectMenu = DeliveryBoyMenu();
                        if (selectMenu == 1)
                        {
                            system("cls");
                            header();
                            string selectDBShop = DeliveryBoySelectShop(shops, totalShops);
                            if (selectDBShop == "1")
                            {
                                system("cls");
                                header();
                                foodDeliveryShop1(userIdentity1, orderedItems1, orderedItemsQuantity1);
                                cls();
                            }
                            else if (selectDBShop == "2")
                            {
                                system("cls");
                                header();
                                foodDeliveryShop2(userIdentity2, orderedItems2, orderedItemsQuantity2);
                                cls();
                            }
                            else if (selectDBShop == "3")
                            {
                                system("cls");
                                header();
                                invalidShopDelivery();
                                cls();
                            }
                            else if (selectDBShop == "4")
                            {
                                system("cls");
                                header();
                                invalidShopDelivery();
                                cls();
                            }
                            else if (selectDBShop == "5")
                            {
                                system("cls");
                                header();
                                invalidShopDelivery();
                                cls();
                            }
                            else if (selectDBShop == "6")
                            {
                                system("cls");
                                header();
                                invalidShopDelivery();
                                cls();
                            }
                            else if (selectDBShop == "7")
                            {
                                system("cls");
                                header();
                                foodDeliveryShop7(userIdentity7, orderedItems7, orderedItemsQuantity7);
                                cls();
                            }
                            else if (selectDBShop == "8")
                            {
                                system("cls");
                                header();
                                foodDeliveryShop8(userIdentity8, orderedItems8, orderedItemsQuantity8);
                                cls();
                            }
                            else if (selectDBShop == "9")
                            {
                                system("cls");
                                header();
                                foodDeliveryShop9(userIdentity9, orderedItems9, orderedItemsQuantity9);
                                cls();
                            }
                            else if (selectDBShop == "10")
                            {
                                system("cls");
                                header();
                                foodDeliveryShop10(userIdentity10, orderedItems10, orderedItemsQuantity10);
                                cls();
                            }
                            else if (selectDBShop == "11")
                            {
                                system("cls");
                                header();
                                foodDeliveryShop11(userIdentity11, orderedItems11, orderedItemsQuantity11);
                                cls();
                            }
                            else if (selectDBShop == "12")
                            {
                                system("cls");
                                header();
                                foodDeliveryShop12(userIdentity12, orderedItems12, orderedItemsQuantity12);
                                cls();
                            }
                            else if (selectDBShop == "13")
                            {
                                system("cls");
                                header();
                                drinksDelivery(userIdentity9, orderedDrinks, orderedDrinksQuantity);
                                cls();
                            }
                            else if (selectDBShop == "BB")
                            {
                                continue;
                            } // DeliveryBoy
                        }
                        else if (selectMenu == 2)
                        {
                            system("cls");
                            header();
                            takeEmployeeSuggestion(DeliveryBoySuggestions, totalDeliveryBoySuggestions);
                        }
                        else if (selectMenu == 3)
                        {
                            int e = 2500;
                            system("cls");
                            header();
                            e = viewAccountBalance(DeliveryBoys, DeliveryBoyUsername, totalDeliveryBoysData);
                            if (e != 234)
                            {
                                system("cls");
                                header();
                                DeliveryBoyBalance(DeliveryBoys, DeliveryBoysSalaries, e);
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (selectMenu == 4)
                        {
                            system("cls");
                            header();
                            changePasswordEmployee(DeliveryBoyUsernames, DeliveryBoyPasswords, totalDeliveryBoys, DeliveryBoyUsername, DeliveryBoyPassword);
                            updateDataToEmployeesFile(DeliveryBoyUsernames, DeliveryBoyPasswords, DeliveryBoyPhoneNumbers, DeliveryBoyGenders, DeliveryBoyAges, totalDeliveryBoys, "DeliveryBoysSignUpData.txt");
                        }
                        else if (selectMenu == 5)
                        {
                            system("cls");
                            header();
                            string ou;
                            hideCursor(1);
                            cout << "\33[31m"
                                 << "\t\t\t\t\t\tAre you sure you want to Log Out(Yes or No)? ";
                            getline(cin, ou);
                            hideCursor(0);
                            if (ou == "Yes" || ou == "yes" || ou == "YES")
                            {
                                LogOut = true;
                                UpdateSuggestionsData(DeliveryBoySuggestions, totalDeliveryBoySuggestions, "DeliveryBoySuggestions.txt");
                                break;
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (selectMenu == 6)
                        {
                            loadingFunction();
                            UpdateSuggestionsData(DeliveryBoySuggestions, totalDeliveryBoySuggestions, "DeliveryBoySuggestions.txt");
                            exit(0);
                        }
                    }
                }
                else
                {
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tInvalid username or password. Please try again." << endl;
                    cls();
                    loginPageHeader();
                    goto again4;
                }
            }
            else if (option == "2")
            {
                if (totalDeliveryBoys < maxDeliveryBoys)
                {
                    getEmployeesInput(DeliveryBoyUsernames, DeliveryBoyPasswords, DeliveryBoyAges, DeliveryBoyGenders,
                                      DeliveryBoyPhoneNumbers, totalDeliveryBoys);
                    updateDataToEmployeesFile(DeliveryBoyUsernames, DeliveryBoyPasswords, DeliveryBoyPhoneNumbers, DeliveryBoyGenders, DeliveryBoyAges, totalDeliveryBoys, "DeliveryBoysSignUpData.txt");
                }
                else
                {

                    cout << "\33[31m"
                         << "\t\t\t\t\t\tMaximum number of Delivery Boys reached. Cannot register more Delivery Boys." << endl;
                    cls();
                    loginPageHeader();
                }
            }
        }
        else if (opt == 6)
        {
            system("cls");
            loginPageHeader();
            string key;
            hideCursor(1);
            cout << "\33[32m"
                 << "\t\t\t\t\t\tEnter key: ";
            getline(cin, key);
            hideCursor(0);
            if (key != "123")
            {
                continue;
            }
            if (key == "BB")
            {
                continue;
            }
            hideCursor(1);
            cout << "\33[35m"
                 << "\t\t\t\t\t\tDo you want to Sign in or Sign up (Press 1 to Sign in and 2 for Sign up): ";
            getline(cin, option);
            hideCursor(0);
            if (option == "BB")
            {
                continue;
            }
            if (option == "1")
            {
                system("cls");
                loginPageHeader();
                string HelplineBoyUsername, HelplineBoyPassword;
            again5:
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter username: ";
                getline(cin, HelplineBoyUsername);
                hideCursor(0);
                if (HelplineBoyUsername == "BB")
                {
                    continue;
                }
                if (empty(HelplineBoyUsername) || hasTabs(HelplineBoyUsername) || HelplineBoyUsername.length() < 6 || HelplineBoyUsername.length() > 10 || !noComma(HelplineBoyUsername))
                {
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tInvalid username \n";
                    cls();
                    loginPageHeader();
                    goto again5;
                }
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter password: ";
                getline(cin, HelplineBoyPassword);
                hideCursor(0);
                if (isExistingEmployee(HelplineBoyUsernames, HelplineBoyPasswords, totalHelplineBoys, HelplineBoyUsername, HelplineBoyPassword))
                {
                    system("cls");
                    loginPageHeader();
                    cout << "\33[33m"
                         << "\t\t\t\t\t\tHelpline Boy Login successful! Welcome, " << HelplineBoyUsername << "!" << endl;
                    loadingFunction();
                    while (true)
                    {
                        system("cls");
                        header();
                        int selectMenu = HelplineBoyMenu();
                        if (selectMenu == 1)
                        {
                            system("cls");
                            header();
                            replyToMessageByHelplineBoy(messageByHelplineBoy, userNumberByMessage, usernames, userMessages, HelplineLineBoyReplies, totalMessages, totalHelplineBoyMessages, totalUsers);
                        }
                        else if (selectMenu == 2)
                        {
                            system("cls");
                            header();
                            takeEmployeeSuggestion(HelplineBoySuggestions, totalHelplineBoySuggestions);
                        }
                        else if (selectMenu == 3)
                        {
                            system("cls");
                            header();
                            int j = 2500;
                            j = viewAccountBalance(HelplineBoys, HelplineBoyUsername, totalHelplineBoysData);
                            if (j != 234)
                            {
                                system("cls");
                                header();
                                HelplineBoyBalance(HelplineBoys, HelplineBoysSalaries, j);
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (selectMenu == 4)
                        {
                            system("cls");
                            header();
                            changePasswordEmployee(HelplineBoyUsernames, HelplineBoyPasswords, totalHelplineBoys, HelplineBoyUsername, HelplineBoyPassword);
                            updateDataToEmployeesFile(HelplineBoyUsernames, HelplineBoyPasswords, HelplineBoyPhoneNumbers, HelplineBoyGenders, HelplineBoyAges, totalHelplineBoys, "HelplineBoysSignUpData.txt");
                        }
                        else if (selectMenu == 5)
                        {
                            system("cls");
                            header();
                            string ou;
                            hideCursor(1);
                            cout << "\33[31m"
                                 << "\t\t\t\t\t\tAre you sure you want to Log Out(Yes or No)? ";
                            getline(cin, ou);
                            hideCursor(0);
                            if (ou == "Yes" || ou == "yes" || ou == "YES")
                            {
                                LogOut = true;
                                UpdateSuggestionsData(HelplineBoySuggestions, totalHelplineBoySuggestions, "HelplineBoySuggestions.txt");
                                break;
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (selectMenu == 6)
                        {
                            loadingFunction();
                            UpdateSuggestionsData(HelplineBoySuggestions, totalHelplineBoySuggestions, "HelplineBoySuggestions.txt");
                            exit(0);
                        }
                    }
                }
                else
                {
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tInvalid username or password. Please try again." << endl;
                    cls();
                    loginPageHeader();
                    goto again5;
                }
            }
            else if (option == "2")
            {
                if (totalHelplineBoys < maxHelplineBoys)
                {
                    getEmployeesInput(HelplineBoyUsernames, HelplineBoyPasswords, HelplineBoyAges, HelplineBoyGenders,
                                      HelplineBoyPhoneNumbers, totalHelplineBoys);
                    updateDataToEmployeesFile(HelplineBoyUsernames, HelplineBoyPasswords, HelplineBoyPhoneNumbers, HelplineBoyGenders, HelplineBoyAges, totalHelplineBoys, "HelplineBoysSignUpData.txt");
                }
                else
                {

                    cout << "\33[31m"
                         << "\t\t\t\t\t\tMaximum number of Delivery Boys reached. Cannot register more Delivery Boys." << endl;
                    cls();
                    loginPageHeader();
                }
            }
        }
        else if (opt == 7)
        {
            system("cls");
            loginPageHeader();
            string key, option;
            hideCursor(1);
            cout << "\33[32m"
                 << "\t\t\t\t\t\tEnter key: ";
            getline(cin, key);
            hideCursor(0);
            if (key != "123")
            {
                continue;
            }
            if (key == "BB")
            {
                continue;
            }
            hideCursor(1);
            cout << "\33[35m"
                 << "\t\t\t\t\t\tDo you want to Sign in or Sign up (Press 1 to Sign in and 2 for Sign up): ";
            getline(cin, option);
            hideCursor(0);
            if (option == "BB")
            {
                continue;
            }
            if (option == "1")
            {
                system("cls");
                loginPageHeader();
                string AccountantUsername, AccountantPassword;
            again6:
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter username: ";
                getline(cin, AccountantUsername);
                hideCursor(0);
                if (AccountantUsername == "BB")
                {
                    continue;
                }
                if (empty(AccountantUsername) || !noComma(AccountantUsername) || AccountantUsername.length() < 6 || AccountantUsername.length() > 10 || hasTabs(AccountantUsername))
                {
                    cout << "\33[36m"
                         << "\t\t\t\t\t\tInvalid username \n";
                    cls();
                    loginPageHeader();
                    goto again6;
                }
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter password: ";
                getline(cin, AccountantPassword);
                hideCursor(0);
                if (isExistingEmployee(AccountantUsernames, AccountantPasswords, totalAccountants, AccountantUsername, AccountantPassword))
                {
                    system("cls");
                    loginPageHeader();
                    cout << "\33[33m"
                         << "\t\t\t\t\t\tAccountant Login successful! Welcome, " << AccountantUsername << "!" << endl;
                    loadingFunction();
                    while (true)
                    {
                        system("cls");
                        header();
                        int selectMenu = AccountantMenu();
                        if (selectMenu == 1)
                        {
                            system("cls");
                            header();
                            paySalary(employees, employeeSalaries, totalEmployeesData, chefs, chefsSalaries, totalChefsData, DeliveryBoys, DeliveryBoysSalaries, totalDeliveryBoysData, Accountants, AccountantsSalaries, totalAccountantsData, HelplineBoys, HelplineBoysSalaries, totalHelplineBoysData, CustomerCares, CustomerCareSalaries, totalCustomerCareData);
                        }
                        else if (selectMenu == 2)
                        {
                            system("cls");
                            header();
                            takeEmployeeSuggestion(AccountantSuggestions, totalAccountantSuggestions);
                        }
                        else if (selectMenu == 3)
                        {
                            system("cls");
                            header();
                            int j = 2500;
                            j = viewAccountBalance(Accountants, AccountantUsername, totalAccountantsData);
                            if (j != 234)
                            {
                                system("cls");
                                header();
                                AccountantBalance(Accountants, AccountantsSalaries, j);
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (selectMenu == 4)
                        {
                            system("cls");
                            header();
                            changePasswordEmployee(AccountantUsernames, AccountantPasswords, totalAccountants, AccountantUsername, AccountantPassword);
                            updateDataToEmployeesFile(AccountantUsernames, AccountantPasswords, AccountantPhoneNumbers, AccountantGenders, AccountantAges, totalAccountants, "AccountantsSignupData.txt");
                        }
                        else if (selectMenu == 5)
                        {
                            system("cls");
                            header();
                            string ou;
                            hideCursor(1);
                            cout << "\33[31m"
                                 << "\t\t\t\t\t\tAre you sure you want to Log Out(Yes or No)? ";
                            getline(cin, ou);
                            hideCursor(0);
                            if (ou == "Yes" || ou == "yes" || ou == "YES")
                            {
                                LogOut = true;
                                UpdateSuggestionsData(AccountantSuggestions, totalAccountantSuggestions, "AccountantSuggestions.txt");
                                break;
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (selectMenu == 6)
                        {
                            loadingFunction();
                            UpdateSuggestionsData(AccountantSuggestions, totalAccountantSuggestions, "AccountantSuggestions.txt");
                            exit(0);
                        }
                    }
                }
                else
                {
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tInvalid username or password. Please try again." << endl;
                    cls();
                    loginPageHeader();
                    goto again6;
                }
            }
            else if (option == "2")
            {
                if (totalAccountants < maxAccountants)
                {
                    getEmployeesInput(AccountantUsernames, AccountantPasswords, AccountantAges, AccountantGenders,
                                      AccountantPhoneNumbers, totalAccountants);
                    updateDataToEmployeesFile(AccountantUsernames, AccountantPasswords, AccountantPhoneNumbers, AccountantGenders, AccountantAges, totalAccountants, "AccountantsSignupData.txt");
                }
                else
                {

                    cout << "\33[31m"
                         << "\t\t\t\t\t\tMaximum number of Delivery Boys reached. Cannot register more Delivery Boys." << endl;
                    cls();
                    loginPageHeader();
                }
            }
        }
        else if (opt == 8)
        {
            system("cls");
            loginPageHeader();
            string key, option;
            hideCursor(1);
            cout << "\33[32m"
                 << "\t\t\t\t\t\tEnter key: ";
            getline(cin, key);
            hideCursor(0);
            if (key != "123")
            {
                continue;
            }
            if (key == "BB")
            {
                continue;
            }
            hideCursor(1);
            cout << "\33[36m"
                 << "\t\t\t\t\t\tDo you want to Sign in or Sign up (Press 1 to Sign in and 2 for Sign up): ";
            getline(cin, option);
            hideCursor(0);
            if (option == "BB")
            {
                continue;
            }
            if (option == "1")
            {
                system("cls");
                loginPageHeader();
                string CustomerCareUsername, CustomerCarePassword;
            again7:
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter username: ";
                getline(cin, CustomerCareUsername);
                hideCursor(0);
                if (empty(CustomerCareUsername) || hasTabs(CustomerCareUsername) || CustomerCareUsername.length() < 6 || CustomerCareUsername.length() > 10 || !noComma(CustomerCareUsername))
                {
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tInvalid username \n";
                    cls();
                    loginPageHeader();
                    goto again7;
                }
                if (CustomerCareUsername == "BB")
                {
                    continue;
                }
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter password: ";
                getline(cin, CustomerCarePassword);
                hideCursor(0);
                if (isExistingEmployee(CustomerCareUsernames, CustomerCarePasswords, totalCustomerCare, CustomerCareUsername, CustomerCarePassword))
                {
                    system("cls");
                    loginPageHeader();
                    cout << "\33[33m"
                         << "\t\t\t\t\t\tCustomer Care Employee Login successful! Welcome, " << CustomerCareUsername << "!" << endl;
                    loadingFunction();
                    while (true)
                    {
                        system("cls");
                        header();
                        int selectMenu = CustomerCareMenu();
                        if (selectMenu == 1)
                        {
                            system("cls");
                            header();
                            string ox = inputType();
                            if (ox == "C")
                            {
                                system("cls");
                                header();
                                viewSuggestions(userSuggestions, totalSuggestions);
                            }
                            else if (ox == "D")
                            {
                                system("cls");
                                header();
                                viewDeliveryBoySuggestions(DeliveryBoySuggestions, totalDeliveryBoySuggestions);
                            }
                            else if (ox == "CH")
                            {
                                system("cls");
                                header();
                                viewChefSuggestions(ChefSuggestions, totalChefSuggestions);
                            }
                            else if (ox == "A")
                            {
                                system("cls");
                                header();
                                viewAccountantSuggestions(AccountantSuggestions, totalAccountantSuggestions);
                            }
                            else if (ox == "H")
                            {
                                system("cls");
                                header();
                                viewHelplineBoySuggestions(HelplineBoySuggestions, totalHelplineBoySuggestions);
                            }
                            else if (ox == "E")
                            {
                                system("cls");
                                header();
                                viewEmployeeSuggestions(EmployeeSuggestions, totalEmployeeSuggestions);
                            }
                            else if (ox == "BB")
                            {
                                continue;
                            }
                        }
                        else if (selectMenu == 2)
                        {
                            system("cls");
                            header();
                            viewComplaints(userComplaints, totalComplaints);
                        }
                        else if (selectMenu == 3)
                        {
                            system("cls");
                            header();
                            int k = 2000;
                            k = viewAccountBalance(CustomerCares, CustomerCareUsername, totalCustomerCareData);
                            if (k != 234)
                            {
                                system("cls");
                                header();
                                CustomerCareBalance(CustomerCares, CustomerCareSalaries, k);
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (selectMenu == 4)
                        {
                            system("cls");
                            header();
                            changePasswordEmployee(CustomerCareUsernames, CustomerCarePasswords, totalCustomerCare, CustomerCareUsername, CustomerCarePassword);
                            updateDataToEmployeesFile(CustomerCareUsernames, CustomerCarePasswords, CustomerCarePhoneNumbers, CustomerCareGenders, CustomerCareAges, totalCustomerCare, "CustomerCaresSignUpData.txt");
                        }
                        else if (selectMenu == 5)
                        {
                            system("cls");
                            header();
                            string ou;
                            hideCursor(1);
                            cout << "\33[31m"
                                 << "\t\t\t\t\t\tAre you sure you want to Log Out(Yes or No)? ";
                            getline(cin, ou);
                            hideCursor(0);
                            if (ou == "Yes" || ou == "yes" || ou == "YES")
                            {
                                LogOut = true;
                                break;
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (selectMenu == 6)
                        {
                            loadingFunction();
                            exit(0);
                        }
                    }
                }
                else
                {
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tInvalid username or password. Please try again." << endl;
                    cls();
                    loginPageHeader();
                    goto again7;
                }
            }
            else if (option == "2")
            {
                if (totalCustomerCare < maxCustomerCare)
                {
                    getEmployeesInput(CustomerCareUsernames, CustomerCarePasswords, CustomerCareAges, CustomerCareGenders,
                                      CustomerCarePhoneNumbers, totalCustomerCare);
                    updateDataToEmployeesFile(CustomerCareUsernames, CustomerCarePasswords, CustomerCarePhoneNumbers, CustomerCareGenders, CustomerCareAges, totalCustomerCare, "CustomerCaresSignUpData.txt");

                    // Repeat until a valid password is entered
                }
                else
                {

                    cout << "\33[31m"
                         << "\t\t\t\t\t\tMaximum number of Delivery Boys reached. Cannot register more Delivery Boys." << endl;
                    cls();
                    loginPageHeader();
                }
            }
        }
        else if (opt == 9)
        {
            system("cls");
            loginPageHeader();
            system("cls");
            howToUse();
            cls();
        }
        else if (opt == 10)
        {
            exit(0);
        }
    }
}

// header for my business app
void header()
{
    cout << "\33[31;1m"
         << "\t\t\t\t\t\t\t ____    _                 _                  _       " << endl;
    cout << "\33[31;1m"
         << "\t\t\t\t\t\t\t/ ___|  | |_   _   _    __| |   ___   _ __   | |_ " << endl;
    cout << "\33[31;1m"
         << "\t\t\t\t\t\t\t\\___ \\  | __| | | | |  / _` |  / _ \\ | '_ \\  | __|" << endl;
    cout << "\33[31;1m"
         << "\t\t\t\t\t\t\t ___) | | |_  | |_| | | (_| | |  __/ | | | | | |_ " << endl;
    cout << "\33[31;1m"
         << "\t\t\t\t\t\t\t|____/   \\__|  \\__,_|  \\__,_|  \\___| |_| |_|  \\__|" << endl;
    cout << "\33[32;1m"
         << "\t\t\t\t\t\t\t ____                          _                  " << endl;
    cout << "\33[32;1m"
         << "\t\t\t\t\t\t\t/ ___|    ___   _ __  __   __ (_)   ___    ___    " << endl;
    cout << "\33[32;1m"
         << "\t\t\t\t\t\t\t\\___ \\   / _ \\ | '__| \\ \\ / / | |  / __|  / _ \\   " << endl;
    cout << "\33[32;1m"
         << "\t\t\t\t\t\t\t ___) | |  __/ | |     \\ V /  | | | (__  |  __/   " << endl;
    cout << "\33[32;1m"
         << "\t\t\t\t\t\t\t|____/   \\___| |_|      \\_/   |_|  \\___|  \\___|   " << endl;
    cout << "\33[34;1m"
         << "\t\t\t\t\t\t\t  ____                  _                         " << endl;
    cout << "\33[34;1m"
         << "\t\t\t\t\t\t\t / ___|   ___   _ __   | |_    ___   _ __         " << endl;
    cout << "\33[34;1m"
         << "\t\t\t\t\t\t\t| |      / _ \\ | '_ \\  | __|  / _ \\ | '__|        " << endl;
    cout << "\33[34;1m"
         << "\t\t\t\t\t\t\t| |___  |  __/ | | | | | |_  |  __/ | |           " << endl;
    cout << "\33[34;1m"
         << "\t\t\t\t\t\t\t \\____|  \\___| |_| |_|  \\__|  \\___| |_|           \33[0m" << endl
         << endl
         << endl;
}

// Here is my Header for my Login Page
void loginPageHeader()
{
    cout << endl
         << endl;
    cout << "\33[31m"
         << "\t\t\t\t\t\t ____    _                     ___          "
         << "\33[33m"
         << "    __"
         << "\33[32m"
         << "    ____    _                     _   _         \n";
    cout << "\33[31m"
         << "\t\t\t\t\t\t/ ___|  (_)   __ _   _ __     |_ _|  _ __     "
         << "\33[33m"
         << " / /"
         << "\33[32m"
         << "   / ___|  (_)   __ _   _ __     | | | |  _ __  \n";
    cout << "\33[31m"
         << "\t\t\t\t\t\t\\___ \\  | |  / _` | | '_ \\     | |  | '_ \\ "
         << "\33[33m"
         << "   / /"
         << "\33[32m"
         << "    \\___ \\  | |  / _` | | '_ \\    | | | | | '_ \\ \n";
    cout << "\33[31m"
         << "\t\t\t\t\t\t ___) | | | | (_| | | | | |    | |  | | | |  "
         << "\33[33m"
         << "/ /"
         << "\33[32m"
         << "      ___) | | | | (_| | | | | |   | |_| | | |_) |\n";
    cout << "\33[31m"
         << "\t\t\t\t\t\t|____/  |_|  \\__, | |_| |_|   |___| |_| |_| "
         << "\33[33m"
         << "/_/"
         << "\33[32m"
         << "      |____/  |_|  \\__, | |_| |_|    \\___/  | .__/ \n";
    cout << "\33[31m"
         << "\t\t\t\t\t\t             |___/                            "
         << "\33[33m"
         << "   "
         << "\33[32m"
         << "                 |___/                    |_|    \n";
    cout << "\33[34m"
         << "\t\t\t\t\t\t                                 ____                                                           \n";
    cout << "\33[34m"
         << "\t\t\t\t\t\t                                |  _ \\    __ _    __ _    ___                                   \n";
    cout << "\33[34m"
         << "\t\t\t\t\t\t                                | |_) |  / _` |  / _` |  / _ \\                                  \n";
    cout << "\33[34m"
         << "\t\t\t\t\t\t                                |  __/  | (_| | | (_| | |  __/                                  \n";
    cout << "\33[34m"
         << "\t\t\t\t\t\t                                |_|      \\__,_|  \\__, |  \\___|                                  \n";
    cout << "\33[34m"
         << "\t\t\t\t\t\t                                                 |___/                                          \n\n\n";
}

// cls functions
void cls()
{
    cout << "\33[31m"
         << "\t\t\t\t\t\tPress any key to continue."
         << "\33[0m" << endl;
    getch();
    system("cls");
}

// welcome
void welcome()
{
    SetConsoleTextAttribute(hConsole, 5);
    cout << endl
         << endl;

    cout << "\t\t\t\t\t\t\t__            _____   _        ____    ___    __  __   _____     _____    ___  \n";
    cout << "\t\t\t\t\t\t\t\\ \\      / / | ____| | |      / ___|  / _ \\  |  \\/  | | ____|   |_   _|  / _ \\ \n";
    cout << "\t\t\t\t\t\t\t \\ \\ /\\ / /  |  _|   | |     | |     | | | | | |\\/| | |  _|       | |   | | | |\n";
    cout << "\t\t\t\t\t\t\t  \\ V  V /   | |___  | |___  | |___  | |_| | | |  | | | |___      | |   | |_| |\n";
    cout << "\t\t\t\t\t\t\t   \\_/\\_/    |_____| |_____|  \\____|  \\___/  |_|  |_| |_____|     |_|    \\___/ \n";
    cout << "\t\t\t\t\t\t                                                                               \n";
    cout << "\t\t\t\t\t\t                                   ____     ____      ____                             \n";
    cout << "\t\t\t\t\t\t                                  / ___|   / ___|    / ___|                            \n";
    cout << "\t\t\t\t\t\t                                  \\___ \\   \\___  \\  | |                                \n";
    cout << "\t\t\t\t\t\t                                   ___) |   ___) | |  |___                             \n";
    cout << "\t\t\t\t\t\t                                  |____/   |____/    \\____|                            \n";
    cout << "\t\t\t\t\t\t                                                                               \n\n\n";
}

void loadingFunction()
{
    int x = 40, y = 3;
    char box = 219; // ASCII code for a box

    gotoxy(x + 32, y + 32);
    cout << "Loading...";

    gotoxy(x, y + 34);
    cout << box;

    for (int i = 0; i < 70; i++)
    {
        Sleep(20);
        x++;
        gotoxy(x, y + 34);
        cout << box;
    }
}

void printBuilding()
{
    SetConsoleTextAttribute(hConsole, 6);
    cout << "\t\t\t\t\t\t                                      /\\                                  \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t                                      /\\                                  \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t                                      /\\                                  \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t                                      /\\                                  \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t                                    _`=='_                                 \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t                                 _-~......~-_                              \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t                             _--~............~--_                          \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t                       __--~~....................~~--__                    \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t           .___..---~~~................................~~~---..___,        \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t            `=.______________________SSC________________________,='        \n";
    cout << "\t\t\t\t\t\t               @^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@            \n";
    Sleep(60);
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\t\t\t\t\t\t                        |  |  I   I   II   I   I  |  |                     \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t                        |  |_I_I_II_I_I_|  |                               \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t                        | /__I  I   II   I  I__\\ |                        \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t                        |'_     ~~~~~~~~~~~~~~     _`|                     \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t                    __-~...~~~~~--------------~~~~~...~-__                 \n";
    Sleep(60);
    SetConsoleTextAttribute(hConsole, 11);
    cout << "\t\t\t\t\t\t            ___---~~......................................~~---___         \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t.___..---~~~......................................................~~~---.._\n";
    Sleep(60);
    cout << "\t\t\t\t\t\t`=.______________________________________________________________________,=\n";
    Sleep(60);
    cout << "\t\t\t\t\t\t    @^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@ \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t              |   |    | |    |  |    ||    |  |    | |    |   |           \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t              |   |____| |____|  |    ||    |  |____| |____|   |           \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t              |__________________|____||____|__________________|           \n";
    Sleep(60);
    cout << "\t\t\t\t\t\t            -|_____|_____|_____|__|------|__|_____|_____|_____|-  _____    \n";
    Sleep(100);
}

void openingAnimation()
{
    int x = 49, y = 3;
    // ascii code for box
    char box = 219;

    gotoxy(x + 33, y + 29);
    cout << "\33[35m"
         << "Proceeding...";

    hideCursor(0);
    for (int i = 0; i < 75; i++)
    {
        Sleep(20);
        x++;
        gotoxy(x, y + 30);
        cout << box;
    }
    hideCursor(1);
    cout << "\33[0m";
}

// empty
bool empty(string check)
{
    if (check == "" || check == " " || check == "  " || check == "   " || check == "    " || check == "     " || check == "      " ||
        check == "       " || check == "        " || check == "         " || check == "          " || check == "          " || check == "          " || check == "          " || check == "           " || check == "            " || check == "             " || check == "                   ")
    {
        return 1;
    }
    return 0;
}

// How to use
void howToUse()
{
    welcome();
    cout << "\33[34m"
         << "\n\t\t\t\t\t\tHello and Welcome to SSC";
    cout << "\33[34m"
         << "\n\n\n\t\t\t\t\t\tHere is some basic Know How for beginners on this app";
    cout << "\33[34m"
         << "\n\t\t\t\t\t\t1. If you are new, you have to sign up first and then login later.";
    cout << "\33[34m"
         << "\n\t\t\t\t\t\t2. For Customers, they should chose 1 on opening interface and then continue with 2 and sign up and come to login";
    cout << "\33[34m"
         << "\n\t\t\t\t\t\t3. Your Username must be between 6 and 10 characters and it must not contain a comma";
    cout << "\33[34m"
         << "\n\t\t\t\t\t\t4. Your Password must be between 8 and 12 characters and it must not contain a comma";
    cout << "\33[34m"
         << "\n\t\t\t\t\t\t5. Password must have a number, Special Character and a capital alphabet";
    cout << "\33[34m"
         << "\n\t\t\t\t\t\t6. After this you are all set to go";
    cout << "\33[34m"
         << "\n\t\t\t\t\t\t7. If you want to go back to previous page press\"BB\". This should be done on first prompt of new Interface";
    cout << "\33[34m"
         << "\n\t\t\t\t\t\t8 To go forwad you will be given choice So, please read carefully\n";
}

// this function checks all the usernames in the array to see if the user who is trying to log in exists
bool isExistingUser(string usernames[], string passwords[], int totalUsers, string username, string password)
{
    for (int i = 0; i < totalUsers; ++i)
    {
        if (usernames[i] == username && passwords[i] == password) // checls all the users and checks for current users, if it matches return true
        {
            return true;
        }
    }
    return false;
}

// this function makes sure no two users have same name
bool isUniqueUser(string usernames[], int totalUsers, string newUser)
{
    bool isUnique = true;
    for (int i = 0; i < totalUsers; ++i)
    {
        if (usernames[i] == newUser)
        {
            cout << "\33[31m"
                 << "\t\t\t\t\t\tUsername already exists. Please try a different username." << endl; // if username is same return false
            isUnique = false;
            if (!isUnique)
            {
                return false;
            }
        }
    }
    return true;
}

// this is a validation to make sure there is no comma in Users entered name
// It fetches ascii of each char and checks if it is equal to commas ascii which is 44
bool noComma(string newUser)
{
    bool commaFound = false;
    bool spaceFound = false;
    int spaceCount = 0;

    for (int i = 0; i < newUser.length(); i++)
    {
        int asciiCode = newUser[i];
        if (asciiCode == 44)
        {
            commaFound = true;
            break;
        }
        if (newUser[i] == ' ')
        {
            spaceCount++;
            if (spaceCount > 1)
            {
                spaceFound = true;
                break;
            }
        }
    }
    if (commaFound || spaceFound || spaceCount > 1)
    {
        return false;
    }
    return true;
}

// It fetches ascii of each char and checks if it is equal to commas ascii which is 44
bool noCommaItem(string item)
{
    bool commaFound = false;
    bool spaceFound = false;
    int spaceCount = 0;

    for (int i = 0; i < item.length(); i++)
    {
        int asciiCode = item[i];
        if (asciiCode == 44)
        {
            commaFound = true;
            break;
        }
    }
    if (commaFound)
    {
        return false;
    }
    return true;
}

// this validation checks if entered password by customer is Valid or not
bool validPassword(string password)
{
    int characters = 0, capitalCharacters = 0, specialCharacters = 0, numbers = 0, spaceCount = 0, commaCount = 0;
    bool isTrue = false;
    for (int i = 0; i < password.length(); i++)
    {
        int asciiCode = password[i];

        if (asciiCode >= 48 && asciiCode <= 57)
        {
            numbers++;
        }
        // checks for nums
        else if (asciiCode >= 65 && asciiCode <= 90)
        {
            capitalCharacters++;
        }
        else if (asciiCode >= 97 && asciiCode <= 122)
        {
            characters++;
        }
        // checks for small chars
        else if ((asciiCode > 32 && asciiCode <= 43) || (asciiCode >= 45 && asciiCode <= 57) || (asciiCode >= 58 && asciiCode <= 64) || (asciiCode >= 91 && asciiCode <= 96) || (asciiCode >= 123 && asciiCode <= 126))
        {
            specialCharacters++;
        }
        // checks for capital chars
        else if (asciiCode == 32)
        {
            spaceCount++;
        }
        // checks for space
        else if (asciiCode == 44)
        {
            commaCount++;
        }
        // checks for comma
    }

    if (characters >= 0 && numbers >= 1 && specialCharacters >= 1 && capitalCharacters >= 1 && spaceCount == 0 && commaCount == 0 && (password.length() >= 8 && password.length() <= 12))
    {
        isTrue = true;
    }
    return isTrue;
}

// validation for age
bool validAge(string age)
{
    bool valid = true;
    if (age.length() == 0)
    {
        return false;
    }
    for (int i = 0; i < age.length(); i++)
    {
        int asciiCode = age[i];
        if (asciiCode >= 48 && asciiCode <= 57)
        {
            continue;
        }
        else
        {
            valid = false;
            break;
        }
    }
    if (!valid)
    {
        return false;
    }
    return true;
}

// validation for phone number
bool validPhoneNumber(string phoneNumber)
{
    bool valid = true;
    if (phoneNumber.length() == 12)
    {
        for (int i = 0; i < phoneNumber.length(); i++)
        {
            int asciiCode = phoneNumber[i];
            if (asciiCode >= 48 && asciiCode <= 57)
            {
                continue;
            }
            else
            {
                valid = false;
                break;
            }
        }
        if (!valid)
        {
            return false;
        }
        return true;
    }
    return false;
}

// customer opening interface
int customerMenu()
{
    cout << "\33[33m"
         << "\t\t\t\t\t\t\tCustomer Menu\n"
         << "\33[0m";
    cout << "\33[32m"
         << "\t\t\t\t\t\t1. View Shops (To Order Food)" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t2. Do you want to Order Drinks?" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t3. Do you want to Book Table?" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t4. Give a Suggestion" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t5. Submit a Complaint" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t6. Give Reviews about SSC" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t7. View Notifications" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t8. View rules and code of conduct" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t9. Need Help? Contact here." << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t10. About Us" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t11. Change Password" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t12. Change Username" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t13. Delete account" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t14. Log Out" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t15. Exit App" << endl;
    int input = movementOfArrow(45, 18, 1, 15);
    return input;
}

// displays all shops to user
string displayShops(string shops[], int totalShops)
{
    string input;
    bool isSuccesfull = false;
    for (int i = 0; i < totalShops; i++) // displays all shops
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << shops[i] << endl;
    }
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter a shop you want to order from (1 to " << totalShops << "): ";
    hideCursor(1);
    getline(cin, input);
    hideCursor(0);
    if (input == "BB")
    {
        return input;
    }
    bool isValid = false;
    for (int i = 1; i <= totalShops; i++)
    {
        if (input == to_string(i))
        {
            isValid = true;
            break;
        }
    }

    if (isValid)
    {
        return input;
    }
    else
    {
        cls();
        header();
        return displayShops(shops, totalShops);
    }
}

// shop1 order for customer
void shop1(string foodMenuShop1[], int foodMenuPricesShop1[], int totalShop1Items, string orderedItems1[], int orderedItemsQuantity1[], int orderedItemsPrices1[], string userIdentity1[])
{
    string input, n, h, p, quantity;
    bool isSuccesfull = false, maxOrder = false, orderDone = false, isValid = false;
    // displaying all the items
    cout << "\33[32m"
         << "\t\t\t\t\t\t     Food                        Price in Rupees\n";
    for (int i = 0; i < totalShop1Items; i++)
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << foodMenuShop1[i] << " | " << setw(5) << right << foodMenuPricesShop1[i] << " Rupees" << endl;
    }

    // taking user input
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter a food you want to order: (1 to " << totalShop1Items << "): ";
    hideCursor(1);
    getline(cin, input);
    hideCursor(0);
    // BB to return to previous page
    if (input == "BB")
    {
        return;
    }

    for (int i = 1; i <= totalShop1Items; i++)
    {
        if (input == to_string(i))
        {
            isValid = true;
            break; // break if input is found
        }
    }

    // if input is valid
    if (isValid)
    {
        // enter quantity maximum is 30
        cout << "\33[33m"
             << "\t\t\t\t\t\tEnter quantity of " << foodMenuShop1[stoi(input) - 1] << " Max=30: ";
        hideCursor(1);
        getline(cin, quantity);
        hideCursor(0);
        // if enetered quantity is greater than 30
        if (validQuantity(quantity))
        {
            string option = orderMore();
            if (option == "1")
            {
                if (orderNum <= 5)
                {
                    system("cls");
                    header();
                    // store input in an array so chef and deleivery boy can access it
                    orderedItems1[orderNum] = foodMenuShop1[stoi(input) - 1];
                    orderedItemsPrices1[orderNum] = foodMenuPricesShop1[stoi(input) - 1];
                    orderedItemsQuantity1[orderNum] = stoi(quantity);
                    orderNum++;
                    if (orderNum == 5)
                    {
                        maxOrder = true;
                    }
                    else
                    {
                        // recursive call
                        return shop1(foodMenuShop1, foodMenuPricesShop1, totalShop1Items, orderedItems1, orderedItemsQuantity1, orderedItemsPrices1, userIdentity1);
                    }
                }
            }
            else
            {
                system("cls");
                header();
                if (orderNum == 0)
                {
                    // if order is only one item
                    orderedItems1[orderNum] = foodMenuShop1[stoi(input) - 1];
                    orderedItemsPrices1[orderNum] = foodMenuPricesShop1[stoi(input) - 1];
                    orderedItemsQuantity1[orderNum] = stoi(quantity);
                    calculateBill(input, foodMenuPricesShop1, totalShop1Items);
                    orderDone = true;
                    cls();
                }
                else
                {
                    // if more than one item
                    orderedItems1[orderNum] = foodMenuShop1[stoi(input) - 1];
                    orderedItemsPrices1[orderNum] = foodMenuPricesShop1[stoi(input) - 1];
                    orderedItemsQuantity1[orderNum] = stoi(quantity);
                    orderNum++;
                    cout << "\33[32m"
                         << "\t\t\t\t\t\tDisplaying your Items and Bill in a moment.\n";
                    cls();
                    header();
                    // displaying order
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        cout << "\33[32m"
                             << "\t\t\t\t\t\t" << orderedItemsQuantity1[index] << " of " << orderedItems1[index] << endl;
                    }
                    cout << "\33[32m" << endl;
                    // total Price calulation
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        totalPrice = totalPrice + orderedItemsPrices1[index] * orderedItemsQuantity1[index];
                    }
                    // calculate bil
                    cout << "\33[36m"
                         << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
                    cls();
                    orderDone = true;
                }
            }
        }
        else
        {
            cls();
            header();
            return shop1(foodMenuShop1, foodMenuPricesShop1, totalShop1Items, orderedItems1, orderedItemsQuantity1, orderedItemsPrices1, userIdentity1);
        }
        if (maxOrder)
        {
            // if order is 5 items
            cout << "\33[32m"
                 << "\t\t\t\t\t\tYou have ordered max Items. Displaying your bill in a moment\n";
            loadingFunction();
            system("cls");
            header();
            cout << "\33[32m"
                 << "\t\t\t\t\t\tYou have ordered: \n";
            // same as above
            for (int index = 0; index < 5; index++)
            {
                cout << "\33[32m"
                     << "\t\t\t\t\t\t" << orderedItemsQuantity1[index] << " of " << orderedItems1[index] << endl;
            }
            cout << "\33[32m" << endl;
            for (int index = 0; index < 5; index++)
            {
                totalPrice = totalPrice + orderedItemsPrices1[index] * orderedItemsQuantity1[index];
            }
            cout << "\33[36m"
                 << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
            cls();
            header();
            getDiscount(totalPrice);
            orderDone = true;
        }
    }
    if (orderDone)
    {
        while (true)
        {
            system("cls");
            header();
            // user Identity so that delievry boy can check order and user info
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your name: ";
            hideCursor(1);
            getline(cin, n);

            if (n == "BB")
            {
                return;
            }
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Hall: ";

            getline(cin, h);

            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Phone Number: ";
            getline(cin, p);
            hideCursor(0);
            if (validData(n, h, p))
            {
                userIdentity1[0] = n;
                userIdentity1[1] = h;
                userIdentity1[2] = p;
                cout << "\33[33m"
                     << "\n\t\t\t\t\t\tOrder Placed. \n";
                ////storeOrderedItemsWithID(userIdentity1, orderedItems1, orderedItemsQuantity1, orderedItemsPrices1, orderNum);
                ////storeUserIdentityWithID(userIdentity1);
                cls();
                return;
            }
            else
            {
                cout << "\33[31m"
                     << "\n\t\t\t\t\t\tInvalid Data. Dont use commas and write phone number in (923331234567) Format\n"
                     << "\33[0m";
                cls();
                continue;
            }
        }
    }
    else
    {
        // recursive call
        cls();
        header();
        return shop1(foodMenuShop1, foodMenuPricesShop1, totalShop1Items, orderedItems1, orderedItemsQuantity1, orderedItemsPrices1, userIdentity1);
    }
}

// same method as above shops but to maintain clarity made onther functions
//  shop2 order for customer
void shop2(string foodMenuShop2[], int foodMenuPricesShop2[], int totalShop2Items, string orderedItems2[], int orderedItemsQuantity2[], int orderedItemsPrices2[], string userIdentity2[])
{
    string n, h, p, input, quantity;
    bool isSuccesfull = false, maxOrder = false, orderDone = false, isValid = false;
    cout << "\33[32m"
         << "\t\t\t\t\t\t     Food                        Price in Rupees\n";
    for (int i = 0; i < totalShop2Items; i++)
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << foodMenuShop2[i] << " | " << setw(5) << right << foodMenuPricesShop2[i] << " Rupees" << endl;
    }
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter a food you want to order: (1 to " << totalShop2Items << "): ";
    hideCursor(1);
    getline(cin, input);
    hideCursor(0);
    if (input == "BB")
    {
        return;
    }
    for (int i = 1; i <= totalShop2Items; i++)
    {
        if (input == to_string(i))
        {
            isValid = true;
            break; // break if input is found
        }
    }
    if (isValid)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\tEnter quantity of " << foodMenuShop2[stoi(input) - 1] << " Max=30: ";
        getline(cin, quantity);
        if (validQuantity(quantity))
        {
            string option = orderMore();
            if (option == "1")
            {
                if (orderNum <= 5)
                {
                    system("cls");
                    header();
                    orderedItems2[orderNum] = foodMenuShop2[stoi(input) - 1];
                    orderedItemsPrices2[orderNum] = foodMenuPricesShop2[stoi(input) - 1];
                    orderedItemsQuantity2[orderNum] = stoi(quantity);
                    orderNum++;
                    if (orderNum == 5)
                    {
                        maxOrder = true;
                    }
                    else
                    {
                        return shop2(foodMenuShop2, foodMenuPricesShop2, totalShop2Items, orderedItems2, orderedItemsQuantity2, orderedItemsPrices2, userIdentity2);
                    }
                }
            }
            else
            {
                system("cls");
                header();
                if (orderNum == 0)
                {
                    orderedItems2[orderNum] = foodMenuShop2[stoi(input) - 1];
                    orderedItemsPrices2[orderNum] = foodMenuPricesShop2[stoi(input) - 1];
                    orderedItemsQuantity2[orderNum] = stoi(quantity);
                    calculateBill(input, foodMenuPricesShop2, totalShop2Items);
                    orderDone = true;
                    cls();
                }
                else
                {
                    orderedItems2[orderNum] = foodMenuShop2[stoi(input) - 1];
                    orderedItemsPrices2[orderNum] = foodMenuPricesShop2[stoi(input) - 1];
                    orderedItemsQuantity2[orderNum] = stoi(quantity);
                    orderNum++;

                    cout << "\33[32m"
                         << "\t\t\t\t\t\tDisplaying your Items and Bill in a moment.\n";
                    cls();
                    header();
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        cout << "\33[32m"
                             << "\t\t\t\t\t\t" << orderedItemsQuantity2[index] << " of " << orderedItems2[index] << endl;
                    }
                    cout << "\33[32m" << endl;
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        totalPrice = totalPrice + orderedItemsPrices2[index] * orderedItemsQuantity2[index];
                    }
                    cout << "\33[36m"
                         << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
                    cls();
                    orderDone = true;
                }
            }
        }
        else
        {
            cls();
            header();
            return shop2(foodMenuShop2, foodMenuPricesShop2, totalShop2Items, orderedItems2, orderedItemsQuantity2, orderedItemsPrices2, userIdentity2);
        }
        if (maxOrder)
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\tYou have ordered max Items. Displaying your bill in a moment\n";
            loadingFunction();
            system("cls");
            header();
            for (int index = 0; index < 5; index++)
            {
                cout << "\33[32m"
                     << "\t\t\t\t\t\t" << orderedItemsQuantity2[index] << " of " << orderedItems2[index] << endl;
            }
            cout << "\33[32m" << endl;
            for (int index = 0; index < 5; index++)
            {
                totalPrice = totalPrice + orderedItemsPrices2[index] * orderedItemsQuantity2[index];
            }
            cout << "\33[36m"
                 << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
            cls();
            header();
            getDiscount(totalPrice);
            orderDone = true;
        }
    }
    if (orderDone)
    {
        while (true)
        {
            system("cls");
            header();
            // user Identity so that delievry boy can check order and user info
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your name: ";
            hideCursor(1);
            getline(cin, n);
            if (n == "BB")
            {
                return;
            }
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Hall: ";
            getline(cin, h);
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Phone Number: ";
            getline(cin, p);
            hideCursor(0);
            if (validData(n, h, p))
            {
                userIdentity2[0] = n;
                userIdentity2[1] = h;
                userIdentity2[2] = p;
                cout << "\33[33m"
                     << "\n\t\t\t\t\t\tOrder Placed. \n";
                // storeOrderedItemsWithID(userIdentity2, orderedItems2, orderedItemsQuantity2, orderedItemsPrices2, orderNum);
                // storeUserIdentityWithID(userIdentity2);
                cls();
                return;
            }
            else
            {
                cout << "\33[31m"
                     << "\n\t\t\t\t\t\tInvalid Data. Dont use commas and write phone number in (923331234567) Format\n"
                     << "\33[0m";
                cls();
                continue;
            }
        }
    }
    else
    {
        cls();
        header();
        return shop2(foodMenuShop2, foodMenuPricesShop2, totalShop2Items, orderedItems2, orderedItemsQuantity2, orderedItemsPrices2, userIdentity2);
    }
}

// shop3 order for customer
void shop3()
{
    string option1, option2, address, ok;
    bool isDone = false;
    cout << "\33[32m"
         << "\t\t\t\t\t\tDo you want to get documents photocopied (Type 1 if you want to, any\n\t\t\t\t\t\tother key to go main menu)? ";
    hideCursor(1);
    getline(cin, option1);
    hideCursor(0);
    if (option1 == "BB")
    {
        return;
    }
    if (option1 == "1")
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\tPlease send documents on WhatsApp number 92 333 2242342" << endl;
        cout << "\33[33m"
             << "\t\t\t\t\t\tPress any key to continue..." << endl;
        getch();
        cout << "\33[32m"
             << "\t\t\t\t\t\tDo you want to get them Delivered (Type 1 if you want to, 2 if\n\t\t\t\t\t\tyou can pick up, any other key to go to main menu): ";
        getline(cin, option2);
        if (ValidateEnterDataFor2(option1))
        {
            if (option2 == "1")
            {
                cout << "\33[32m"
                     << "\t\t\t\t\t\tEnter your address: ";
                hideCursor(1);
                getline(cin, address);
                hideCursor(0);
                cout << "\33[32m"
                     << "\t\t\t\t\t\tWe'll be there as soon as possible." << endl;
                isDone = true;
            }
            else if (option2 == "2")
            {
                cout << "\33[32m"
                     << "\t\t\t\t\t\tYou can pick them up at any time." << endl;
                isDone = true;
            }
        }
        else
        {
            cls();
        }
    }
    if (isDone)
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\tPress 1 to exit and any other key to go to main menu: ";
        getline(cin, ok);
        if (ok == "1")
        {
            loadingFunction();

            exit(0);
        }
        else
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\tGoing back to main menu.\n";
            cls();
        }
    }
}

// shop5 order for customer
void shop5(string stationery[], int stationeryPrices[], string deodorants[], int deodrantPrices[], string facewashBrands[], int facewashPrices[], string chips[], int chipsPrices[], string perfumes[], int perfumePrices[], string biscuits[], int biscuitsPrices[], string drinks[], int drinksPrices[], int totalStationarySupplies, int totalDeodrants, int totalFacewash, int totalchips, int totalPerfumes, int totalBiscuits, int totalDrinks)
{
    string input;
    cout << "\33[32m"
         << "\t\t\t\t\t\tWelcome to General Store and Stationary" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t1. Stationery and Office Supplies" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t2. Deodrants" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t3. Facewash " << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t4. Snacks" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t5. Drinks" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t6. Perfume" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\t7. Biscuits" << endl;
    cout << "\33[31m"
         << "\t\t\t\t\t\tNote that items displayed here are only available on shop not\n\t\t\t\t\t\tfor Delivery! ";
    hideCursor(1);
    getline(cin, input);
    hideCursor(0);
    if (input == "BB")
    {
        return;
    }
    else if (input == "1")
    {
        system("cls");
        header();
        cout << "\33[32m"
             << "\n\t\t\t\t\t\t          Stationery Supplies                      Price" << endl;
        for (int i = 0; i < totalStationarySupplies; i++)
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << stationery[i] << " | " << setw(5) << right << stationeryPrices[i] << " Rupees" << endl;
        }
        cls();
    }

    else if (input == "2")
    {
        system("cls");
        header();
        cout << "\33[32m"
             << "\n\t\t\t\t\t\t          Deodorants                              Price" << endl;
        for (int i = 0; i < totalDeodrants; i++)
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << deodorants[i] << " | " << setw(5) << right << deodrantPrices[i] << " Rupees" << endl;
        }
        cls();
    }

    else if (input == "3")
    {
        system("cls");
        header();
        cout << "\33[32m"
             << "\n\t\t\t\t\t\t         Facewash Brands                          Price" << endl;
        for (int i = 0; i < totalFacewash; i++)
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << facewashBrands[i] << " | " << setw(5) << right << facewashPrices[i] << " Rupees" << endl;
        }
        cls();
    }

    else if (input == "4")
    {
        system("cls");
        header();
        cout << "\33[32m"
             << "\n\t\t\t\t\t\t         Chips                                    Price" << endl;
        for (int i = 0; i < totalchips; i++)
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << chips[i] << " | " << setw(5) << right << chipsPrices[i] << " Rupees" << endl;
        }
        cls();
    }

    else if (input == "5")
    {
        system("cls");
        header();
        cout << "\33[32m"
             << "\n\t\t\t\t\t\t        Drinks                                    Price" << endl;
        for (int i = 0; i < totalDrinks; i++)
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << drinks[i] << " | " << setw(5) << right << drinksPrices[i] << " Rupees" << endl;
        }
        cls();
    }

    else if (input == "6")
    {
        system("cls");
        header();
        cout << "\33[32m"
             << "\n\t\t\t\t\t\t      Perfumes                                    Price" << endl;
        for (int i = 0; i < totalPerfumes; i++)
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << perfumes[i] << " | " << setw(5) << right << perfumePrices[i] << " Rupees" << endl;
        }
        cls();
    }

    else if (input == "7")
    {
        system("cls");
        header();
        cout << "\33[32m"
             << "\n\t\t\t\t\t\t       Biscuits                                     Price" << endl;
        for (int i = 0; i < totalBiscuits; i++)
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << biscuits[i] << " | " << setw(5) << right << biscuitsPrices[i] << " Rupees" << endl;
        }
        cls();
    }

    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid Option\n";
        cls();
        header();
        return shop5(stationery, stationeryPrices, deodorants, deodrantPrices, facewashBrands, facewashPrices, chips, chipsPrices, perfumes, perfumePrices, biscuits, biscuitsPrices, drinks, drinksPrices, totalStationarySupplies, totalDeodrants, totalFacewash, totalchips, totalPerfumes, totalBiscuits, totalDrinks);
    }
}

// shop7 order for customer
void shop7(string foodMenuShop7[], int foodMenuPricesShop7[], int totalShop7Items, string orderedItems7[], int orderedItemsQuantity7[], int orderedItemsPrices7[], string userIdentity7[])
{
    string input, n, h, p;
    string quantity;
    bool isSuccesfull = false, maxOrder = false, orderDone = false;
    int maxOrderedItems = 5;
    cout << "\33[32m"
         << "\t\t\t\t\t\t     Item                        Price in Rupees\n";
    for (int i = 0; i < totalShop7Items; i++)
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << foodMenuShop7[i] << " | " << setw(5) << right << foodMenuPricesShop7[i] << " Rupees" << endl;
    }
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter a item you want to order: (1 to " << totalShop7Items << "): ";
    hideCursor(1);
    getline(cin, input);
    hideCursor(0);
    if (input == "BB")
    {
        return;
    }
    bool isValid = false;
    for (int i = 1; i <= totalShop7Items; i++)
    {
        if (input == to_string(i))
        {
            isValid = true;
            break;
        }
    }
    if (isValid)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\tEnter quantity of " << foodMenuShop7[stoi(input) - 1] << " Max=30: ";
        hideCursor(1);
        getline(cin, quantity);
        hideCursor(0);
        if (validQuantity(quantity))
        {
            string option = orderMore();
            if (option == "1")
            {
                if (orderNum <= 5)
                {
                    system("cls");
                    header();
                    orderedItems7[orderNum] = foodMenuShop7[stoi(input) - 1];
                    orderedItemsPrices7[orderNum] = foodMenuPricesShop7[stoi(input) - 1];
                    orderedItemsQuantity7[orderNum] = stoi(quantity);
                    orderNum++;
                    if (orderNum == 5)
                    {
                        maxOrder = true;
                    }
                    else
                    {
                        return shop7(foodMenuShop7, foodMenuPricesShop7, totalShop7Items, orderedItems7, orderedItemsQuantity7, orderedItemsPrices7, userIdentity7);
                    }
                }
            }
            else
            {
                system("cls");
                header();
                if (orderNum == 0)
                {
                    orderedItems7[orderNum] = foodMenuShop7[stoi(input) - 1];
                    orderedItemsPrices7[orderNum] = foodMenuPricesShop7[stoi(input) - 1];
                    orderedItemsQuantity7[orderNum] = stoi(quantity);
                    calculateBill(input, foodMenuPricesShop7, totalShop7Items);
                    cls();
                    orderDone = true;
                }
                else
                {
                    orderedItems7[orderNum] = foodMenuShop7[stoi(input) - 1];
                    orderedItemsPrices7[orderNum] = foodMenuPricesShop7[stoi(input) - 1];
                    orderedItemsQuantity7[orderNum] = stoi(quantity);
                    orderNum++;

                    cout << "\33[32m"
                         << "\t\t\t\t\t\tDisplaying your Items and Bill in a moment.\n";
                    cls();
                    header();
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        cout << "\33[32m"
                             << "\t\t\t\t\t\t" << orderedItemsQuantity7[index] << " of " << orderedItems7[index] << endl;
                    }
                    cout << "\33[32m" << endl;
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        totalPrice = totalPrice + orderedItemsPrices7[index] * orderedItemsQuantity7[index];
                    }
                    cout << "\33[36m"
                         << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;

                    cls();
                    orderDone = true;
                }
            }
        }
        else
        {
            cls();
            header();
            return shop7(foodMenuShop7, foodMenuPricesShop7, totalShop7Items, orderedItems7, orderedItemsQuantity7, orderedItemsPrices7, userIdentity7);
        }
        if (maxOrder)
        {
            cout << "\33[33m"
                 << "\t\t\t\t\t\tYou have ordered max Items. Displaying your bill in a moment\n";
            loadingFunction();
            system("cls");
            header();
            for (int index = 0; index < 5; index++)
            {
                cout << "\33[32m"
                     << "\t\t\t\t\t\t" << orderedItemsQuantity7[index] << " of " << orderedItems7[index] << endl;
            }
            cout << "\33[32m" << endl;
            for (int index = 0; index < 5; index++)
            {
                totalPrice = totalPrice + orderedItemsPrices7[index] * orderedItemsQuantity7[index];
            }
            cout << "\33[36m"
                 << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
            cls();
            header();
            getDiscount(totalPrice);
            orderDone = true;
        }
    }
    if (orderDone)
    {
        while (true)
        {
            system("cls");
            header();
            // user Identity so that delievry boy can check order and user info
            hideCursor(1);
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your name: ";
            getline(cin, n);
            if (n == "BB")
            {
                return;
            }
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Hall: ";
            getline(cin, h);
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Phone Number: ";
            getline(cin, p);
            hideCursor(0);
            if (validData(n, h, p))
            {
                userIdentity7[0] = n;
                userIdentity7[1] = h;
                userIdentity7[2] = p;
                cout << "\33[33m"
                     << "\n\t\t\t\t\t\tOrder Placed. \n";
                cls();
                // storeOrderedItemsWithID(userIdentity7, orderedItems7, orderedItemsQuantity7, orderedItemsPrices7, orderNum);
                // storeUserIdentityWithID(userIdentity7);
                return;
            }
            else
            {
                cout << "\33[31m"
                     << "\n\t\t\t\t\t\tInvalid Data. Dont use commas and write phone number in (923331234567) Format\n"
                     << "\33[0m";
                cls();
                continue;
            }
        }
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid Quantity.\n";
        cls();
        header();
        return shop7(foodMenuShop7, foodMenuPricesShop7, totalShop7Items, orderedItems7, orderedItemsQuantity7, orderedItemsPrices7, userIdentity7);
    }
}

// shop8 order for customer
void shop8(string foodMenuShop8[], int foodMenuPricesShop8[], int totalShop8Items, string orderedItems8[], int orderedItemsQuantity8[], int orderedItemsPrices8[], string userIdentity8[])
{
    string input, n, h, p;
    string quantity;
    bool isSuccesfull = false, maxOrder = false, orderDone = false;
    int maxOrderedItems = 5;
    cout << "\33[32m"
         << "\t\t\t\t\t\t     Item                        Price in Rupees\n";
    for (int i = 0; i < totalShop8Items; i++)
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << foodMenuShop8[i] << " | " << setw(5) << right << foodMenuPricesShop8[i] << " Rupees" << endl;
    }
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter a item you want to order: (1 to " << totalShop8Items << "): ";
    hideCursor(1);
    getline(cin, input);
    hideCursor(0);
    if (input == "BB")
    {
        return;
    }
    bool isValid = false;
    for (int i = 1; i <= totalShop8Items; i++)
    {
        if (input == to_string(i))
        {
            isValid = true;
            break;
        }
    }
    if (isValid)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\tEnter quantity of " << foodMenuShop8[stoi(input) - 1] << " Max=30: ";
        hideCursor(1);
        getline(cin, quantity);
        hideCursor(0);
        if (validQuantity(quantity))
        {
            string option = orderMore();
            if (option == "1")
            {
                if (orderNum <= 5)
                {
                    system("cls");
                    header();
                    orderedItems8[orderNum] = foodMenuShop8[stoi(input) - 1];
                    orderedItemsPrices8[orderNum] = foodMenuPricesShop8[stoi(input) - 1];
                    orderedItemsQuantity8[orderNum] = stoi(quantity);
                    orderNum++;
                    if (orderNum == 5)
                    {
                        maxOrder = true;
                    }
                    else
                    {
                        return shop8(foodMenuShop8, foodMenuPricesShop8, totalShop8Items, orderedItems8, orderedItemsQuantity8, orderedItemsPrices8, userIdentity8);
                    }
                }
            }
            else
            {
                system("cls");
                header();
                if (orderNum == 0)
                {
                    orderedItems8[orderNum] = foodMenuShop8[stoi(input) - 1];
                    orderedItemsPrices8[orderNum] = foodMenuPricesShop8[stoi(input) - 1];
                    orderedItemsQuantity8[orderNum] = stoi(quantity);
                    calculateBill(input, foodMenuPricesShop8, totalShop8Items);
                    cls();
                    orderDone = true;
                }
                else
                {
                    orderedItems8[orderNum] = foodMenuShop8[stoi(input) - 1];
                    orderedItemsPrices8[orderNum] = foodMenuPricesShop8[stoi(input) - 1];
                    orderedItemsQuantity8[orderNum] = stoi(quantity);
                    orderNum++;

                    cout << "\33[32m"
                         << "\t\t\t\t\t\tDisplaying your Items and Bill in a moment.\n";
                    cls();
                    header();
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        cout << "\33[32m"
                             << "\t\t\t\t\t\t" << orderedItemsQuantity8[index] << " of " << orderedItems8[index] << endl;
                    }
                    cout << "\33[32m" << endl;
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        totalPrice = totalPrice + orderedItemsPrices8[index] * orderedItemsQuantity8[index];
                    }
                    cout << "\33[32m"
                         << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
                    orderDone = true;
                    cls();
                }
            }
        }
        else
        {
            cls();
            header();
            return shop8(foodMenuShop8, foodMenuPricesShop8, totalShop8Items, orderedItems8, orderedItemsQuantity8, orderedItemsPrices8, userIdentity8);
        }
        if (maxOrder)
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\tYou have ordered max Items. Displaying your bill in a moment\n";
            loadingFunction();
            system("cls");
            header();
            for (int index = 0; index < 5; index++)
            {
                cout << "\33[32m"
                     << "\t\t\t\t\t\t" << orderedItemsQuantity8[index] << " of " << orderedItems8[index] << endl;
            }
            cout << "\33[32m" << endl;
            for (int index = 0; index < 5; index++)
            {
                totalPrice = totalPrice + orderedItemsPrices8[index] * orderedItemsQuantity8[index];
            }
            cout << "\33[32m"
                 << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
            cls();
            header();
            getDiscount(totalPrice);
            orderDone = true;
        }
    }
    if (orderDone)
    {
        while (true)
        {
            system("cls");
            header();
            // user Identity so that delievry boy can check order and user info
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your name: ";
            hideCursor(1);
            getline(cin, n);
            if (n == "BB")
            {
                return;
            }
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Hall: ";
            getline(cin, h);
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Phone Number: ";
            getline(cin, p);
            hideCursor(0);
            if (validData(n, h, p))
            {
                userIdentity8[0] = n;
                userIdentity8[1] = h;
                userIdentity8[2] = p;
                cout << "\33[33m"
                     << "\n\t\t\t\t\t\tOrder Placed. \n";
                // storeOrderedItemsWithID(userIdentity8, orderedItems8, orderedItemsQuantity8, orderedItemsPrices8, orderNum);
                // storeUserIdentityWithID(userIdentity8);
                cls();
                return;
            }
            else
            {
                cout << "\33[31m"
                     << "\n\t\t\t\t\t\tInvalid Data. Dont use commas and write phone number in (923331234567) Format\n"
                     << "\33[0m";
                cls();
                continue;
            }
        }
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid Quantity.\n";
        cls();
        header();
        return shop8(foodMenuShop8, foodMenuPricesShop8, totalShop8Items, orderedItems8, orderedItemsQuantity8, orderedItemsPrices8, userIdentity8);
    }
}

// shop9 order for customer
void shop9(string foodMenuShop9[], int foodMenuPricesShop9[], int totalShop9Items, string orderedItems9[], int orderedItemsQuantity9[], int orderedItemsPrices9[], string userIdentity9[])
{
    string input, n, h, p;
    string quantity;
    bool isSuccesfull = false, maxOrder = false, orderDone = false;
    int maxOrderedItems = 5;
    cout << "\33[32m"
         << "\t\t\t\t\t\t     Item                        Price in Rupees\n";
    for (int i = 0; i < totalShop9Items; i++)
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << foodMenuShop9[i] << " | " << setw(5) << right << foodMenuPricesShop9[i] << " Rupees" << endl;
    }
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter a item you want to order: (1 to " << totalShop9Items << "): ";
    hideCursor(1);
    getline(cin, input);
    hideCursor(0);
    if (input == "BB")
    {
        return;
    }
    bool isValid = false;
    for (int i = 1; i <= totalShop9Items; i++)
    {
        if (input == to_string(i))
        {
            isValid = true;
            break;
        }
    }
    if (isValid)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\tEnter quantity of " << foodMenuShop9[stoi(input) - 1] << " Max=30: ";
        hideCursor(1);
        getline(cin, quantity);
        hideCursor(0);
        if (validQuantity(quantity))
        {
            string option = orderMore();
            if (option == "1")
            {
                if (orderNum <= 5)
                {
                    system("cls");
                    header();
                    orderedItems9[orderNum] = foodMenuShop9[stoi(input) - 1];
                    orderedItemsPrices9[orderNum] = foodMenuPricesShop9[stoi(input) - 1];
                    orderedItemsQuantity9[orderNum] = stoi(quantity);
                    orderNum++;
                    if (orderNum == 5)
                    {
                        maxOrder = true;
                    }
                    else
                    {
                        return shop9(foodMenuShop9, foodMenuPricesShop9, totalShop9Items, orderedItems9, orderedItemsQuantity9, orderedItemsPrices9, userIdentity9);
                    }
                }
            }
            else
            {
                system("cls");
                header();
                if (orderNum == 0)
                {
                    orderedItems9[orderNum] = foodMenuShop9[stoi(input) - 1];
                    orderedItemsPrices9[orderNum] = foodMenuPricesShop9[stoi(input) - 1];
                    orderedItemsQuantity9[orderNum] = stoi(quantity);
                    calculateBill(input, foodMenuPricesShop9, totalShop9Items);
                    cls();
                    orderDone = true;
                }
                else
                {
                    orderedItems9[orderNum] = foodMenuShop9[stoi(input) - 1];
                    orderedItemsPrices9[orderNum] = foodMenuPricesShop9[stoi(input) - 1];
                    orderedItemsQuantity9[orderNum] = stoi(quantity);
                    orderNum++;

                    cout << "\33[32m"
                         << "\t\t\t\t\t\tDisplaying your Items and Bill in a moment.\n";
                    cls();
                    header();
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        cout << "\33[32m"
                             << "\t\t\t\t\t\t" << orderedItemsQuantity9[index] << " of " << orderedItems9[index] << endl;
                    }
                    cout << "\33[32m" << endl;
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        totalPrice = totalPrice + orderedItemsPrices9[index] * orderedItemsQuantity9[index];
                    }
                    cout << "\33[36m"
                         << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
                    orderDone = true;
                    cls();
                }
            }
        }
        else
        {
            cls();
            header();
            return shop9(foodMenuShop9, foodMenuPricesShop9, totalShop9Items, orderedItems9, orderedItemsQuantity9, orderedItemsPrices9, userIdentity9);
        }
        if (maxOrder)
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\tYou have ordered max Items. Displaying your bill in a moment\n";
            loadingFunction();
            system("cls");
            header();
            for (int index = 0; index < 5; index++)
            {
                cout << "\33[32m"
                     << "\t\t\t\t\t\t" << orderedItemsQuantity9[index] << " of " << orderedItems9[index] << endl;
            }
            cout << "\33[32m" << endl;
            for (int index = 0; index < 5; index++)
            {
                totalPrice = totalPrice + orderedItemsPrices9[index] * orderedItemsQuantity9[index];
            }
            cout << "\33[36m"
                 << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
            cls();
            header();
            getDiscount(totalPrice);
            orderDone = true;
        }
    }
    if (orderDone)
    {
        while (true)
        {
            system("cls");
            header();
            // user Identity so that delievry boy can check order and user info
            hideCursor(1);
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your name: ";
            getline(cin, n);
            if (n == "BB")
            {
                return;
            }
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Hall: ";
            getline(cin, h);
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Phone Number: ";
            getline(cin, p);
            hideCursor(0);
            if (validData(n, h, p))
            {
                userIdentity9[0] = n;
                userIdentity9[1] = h;
                userIdentity9[2] = p;
                cout << "\33[33m"
                     << "\n\t\t\t\t\t\tOrder Placed. \n";
                // storeOrderedItemsWithID(userIdentity9, orderedItems9, orderedItemsQuantity9, orderedItemsPrices9, orderNum);
                // storeUserIdentityWithID(userIdentity9);
                cls();
                return;
            }
            else
            {
                cout << "\33[31m"
                     << "\n\t\t\t\t\t\tInvalid Data. Dont use commas and write phone number in (923331234567) Format\n"
                     << "\33[0m";
                cls();
                continue;
            }
        }
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid Quantity.\n";
        cls();
        header();
        return shop9(foodMenuShop9, foodMenuPricesShop9, totalShop9Items, orderedItems9, orderedItemsQuantity9, orderedItemsPrices9, userIdentity9);
    }
}

// shop10 order for customer
void shop10(string foodMenuShop10[], int foodMenuPricesShop10[], int totalShop10Items, string orderedItems10[], int orderedItemsQuantity10[], int orderedItemsPrices10[], string userIdentity10[])
{
    string input, n, h, p;
    string quantity;
    bool isSuccesfull = false, maxOrder = false, orderDone = false;
    int maxOrderedItems = 5;
    cout << "\33[32m"
         << "\t\t\t\t\t\t     Item                        Price in Rupees\n";
    for (int i = 0; i < totalShop10Items; i++)
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << foodMenuShop10[i] << " | " << setw(5) << right << foodMenuPricesShop10[i] << " Rupees" << endl;
    }
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter a item you want to order: (1 to " << totalShop10Items << "): ";
    hideCursor(1);
    getline(cin, input);
    hideCursor(0);
    if (input == "BB")
    {
        return;
    }
    bool isValid = false;
    for (int i = 1; i <= totalShop10Items; i++)
    {
        if (input == to_string(i))
        {
            isValid = true;
            break;
        }
    }
    if (isValid)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\tEnter quantity of " << foodMenuShop10[stoi(input) - 1] << " Max=30: ";
        hideCursor(1);
        getline(cin, quantity);
        hideCursor(0);
        if (validQuantity(quantity))
        {
            string option = orderMore();
            if (option == "1")
            {
                if (orderNum <= 5)
                {
                    system("cls");
                    header();
                    orderedItems10[orderNum] = foodMenuShop10[stoi(input) - 1];
                    orderedItemsPrices10[orderNum] = foodMenuPricesShop10[stoi(input) - 1];
                    orderedItemsQuantity10[orderNum] = stoi(quantity);
                    orderNum++;
                    if (orderNum == 5)
                    {
                        maxOrder = true;
                    }
                    else
                    {
                        return shop10(foodMenuShop10, foodMenuPricesShop10, totalShop10Items, orderedItems10, orderedItemsQuantity10, orderedItemsPrices10, userIdentity10);
                    }
                }
            }
            else
            {
                system("cls");
                header();
                if (orderNum == 0)
                {
                    orderedItems10[orderNum] = foodMenuShop10[stoi(input) - 1];
                    orderedItemsPrices10[orderNum] = foodMenuPricesShop10[stoi(input) - 1];
                    orderedItemsQuantity10[orderNum] = stoi(quantity);
                    calculateBill(input, foodMenuPricesShop10, totalShop10Items);
                    cls();
                    orderDone = true;
                }
                else
                {
                    orderedItems10[orderNum] = foodMenuShop10[stoi(input) - 1];
                    orderedItemsPrices10[orderNum] = foodMenuPricesShop10[stoi(input) - 1];
                    orderedItemsQuantity10[orderNum] = stoi(quantity);
                    orderNum++;

                    cout << "\33[32m"
                         << "\t\t\t\t\t\tDisplaying your Items and Bill in a moment.\n";
                    cls();
                    header();
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        cout << "\33[32m"
                             << "\t\t\t\t\t\t" << orderedItemsQuantity10[index] << " of " << orderedItems10[index] << endl;
                    }
                    cout << "\33[32m" << endl;
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        totalPrice = totalPrice + orderedItemsPrices10[index] * orderedItemsQuantity10[index];
                    }
                    cout << "\33[36m"
                         << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
                    orderDone = true;
                    cls();
                }
            }
        }
        else
        {
            cls();
            header();
            return shop10(foodMenuShop10, foodMenuPricesShop10, totalShop10Items, orderedItems10, orderedItemsQuantity10, orderedItemsPrices10, userIdentity10);
        }
        if (maxOrder)
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\tYou have ordered max Items. Displaying your bill in a moment\n";
            loadingFunction();
            system("cls");
            header();
            for (int index = 0; index < 5; index++)
            {
                cout << "\33[32m"
                     << "\t\t\t\t\t\t" << orderedItemsQuantity10[index] << " of " << orderedItems10[index] << endl;
            }
            cout << "\33[32m" << endl;
            for (int index = 0; index < 5; index++)
            {
                totalPrice = totalPrice + orderedItemsPrices10[index] * orderedItemsQuantity10[index];
            }
            cout << "\33[36m"
                 << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
            cls();
            header();
            getDiscount(totalPrice);
            orderDone = true;
        }
    }
    if (orderDone)
    {
        while (true)
        {
            system("cls");
            header();
            // user Identity so that delievry boy can check order and user info
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your name: ";
            hideCursor(1);
            getline(cin, n);
            if (n == "BB")
            {
                return;
            }
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Hall: ";
            getline(cin, h);
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Phone Number: ";
            getline(cin, p);
            hideCursor(0);
            if (validData(n, h, p))
            {
                userIdentity10[0] = n;
                userIdentity10[1] = h;
                userIdentity10[2] = p;
                cout << "\33[33m"
                     << "\n\t\t\t\t\t\tOrder Placed. \n";
                // storeOrderedItemsWithID(userIdentity10, orderedItems10, orderedItemsQuantity10, orderedItemsPrices10, orderNum);
                // storeUserIdentityWithID(userIdentity10);
                cls();
                return;
            }
            else
            {
                cout << "\33[31m"
                     << "\n\t\t\t\t\t\tInvalid Data. Dont use commas and write phone number in (923331234567) Format\n"
                     << "\33[0m";
                cls();
                continue;
            }
        }
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid Quantity.\n";
        cls();
        header();
        return shop10(foodMenuShop10, foodMenuPricesShop10, totalShop10Items, orderedItems10, orderedItemsQuantity10, orderedItemsPrices10, userIdentity10);
    }
}

// shop11 order for customer
void shop11(string foodMenuShop11[], int foodMenuPricesShop11[], int totalShop11Items, string orderedItems11[], int orderedItemsQuantity11[], int orderedItemsPrices11[], string userIdentity11[])
{
    string input, n, h, p;
    string quantity;
    bool isSuccesfull = false, maxOrder = false, orderDone;
    int maxOrderedItems = 5;
    cout << "\33[32m"
         << "\t\t\t\t\t\t     Item                        Price in Rupees\n";
    for (int i = 0; i < totalShop11Items; i++)
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << foodMenuShop11[i] << " | " << setw(5) << right << foodMenuPricesShop11[i] << " Rupees" << endl;
    }
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter a item you want to order: (1 to " << totalShop11Items << "): ";
    hideCursor(1);
    getline(cin, input);
    hideCursor(0);
    if (input == "BB")
    {
        return;
    }
    bool isValid = false;
    for (int i = 1; i <= totalShop11Items; i++)
    {
        if (input == to_string(i))
        {
            isValid = true;
            break;
        }
    }
    if (isValid)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\tEnter quantity of " << foodMenuShop11[stoi(input) - 1] << " Max=30: ";
        hideCursor(1);
        getline(cin, quantity);
        hideCursor(0);
        if (validQuantity(quantity))
        {
            string option = orderMore();
            if (option == "1")
            {
                if (orderNum <= 5)
                {
                    system("cls");
                    header();
                    orderedItems11[orderNum] = foodMenuShop11[stoi(input) - 1];
                    orderedItemsPrices11[orderNum] = foodMenuPricesShop11[stoi(input) - 1];
                    orderedItemsQuantity11[orderNum] = stoi(quantity);
                    orderNum++;
                    if (orderNum == 5)
                    {
                        maxOrder = true;
                    }
                    else
                    {
                        return shop11(foodMenuShop11, foodMenuPricesShop11, totalShop11Items, orderedItems11, orderedItemsQuantity11, orderedItemsPrices11, userIdentity11);
                    }
                }
            }
            else
            {
                system("cls");
                header();
                if (orderNum == 0)
                {
                    orderedItems11[orderNum] = foodMenuShop11[stoi(input) - 1];
                    orderedItemsPrices11[orderNum] = foodMenuPricesShop11[stoi(input) - 1];
                    orderedItemsQuantity11[orderNum] = stoi(quantity);
                    calculateBill(input, foodMenuPricesShop11, totalShop11Items);
                    cls();
                    orderDone = true;
                }
                else
                {
                    orderedItems11[orderNum] = foodMenuShop11[stoi(input) - 1];
                    orderedItemsPrices11[orderNum] = foodMenuPricesShop11[stoi(input) - 1];
                    orderedItemsQuantity11[orderNum] = stoi(quantity);
                    orderNum++;

                    cout << "\33[32m"
                         << "\t\t\t\t\t\tDisplaying your Items and Bill in a moment.\n";
                    cls();
                    header();
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        cout << "\33[32m"
                             << "\t\t\t\t\t\t" << orderedItemsQuantity11[index] << " of " << orderedItems11[index] << endl;
                    }
                    cout << "\33[32m" << endl;
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        totalPrice = totalPrice + orderedItemsPrices11[index] * orderedItemsQuantity11[index];
                    }
                    cout << "\33[36m"
                         << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
                    orderDone = true;
                    cls();
                }
            }
        }
        else
        {
            cls();
            header();
            return shop11(foodMenuShop11, foodMenuPricesShop11, totalShop11Items, orderedItems11, orderedItemsQuantity11, orderedItemsPrices11, userIdentity11);
        }
        if (maxOrder)
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\tYou have ordered max Items. Displaying your bill in a moment\n";
            loadingFunction();
            system("cls");
            header();
            for (int index = 0; index < 5; index++)
            {
                cout << "\33[32m"
                     << "\t\t\t\t\t\t" << orderedItemsQuantity11[index] << " of " << orderedItems11[index] << endl;
            }
            cout << "\33[32m" << endl;
            for (int index = 0; index < 5; index++)
            {
                totalPrice = totalPrice + orderedItemsPrices11[index] * orderedItemsQuantity11[index];
            }
            cout << "\33[36m"
                 << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
            cls();
            header();
            getDiscount(totalPrice);
            orderDone = true;
        }
    }
    if (orderDone)
    {
        while (true)
        {
            system("cls");
            header();
            // user Identity so that delievry boy can check order and user info
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your name: ";
            hideCursor(1);
            getline(cin, n);
            if (n == "BB")
            {
                return;
            }
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Hall: ";
            getline(cin, h);
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Phone Number: ";
            getline(cin, p);
            hideCursor(0);
            if (validData(n, h, p))
            {
                userIdentity11[0] = n;
                userIdentity11[1] = h;
                userIdentity11[2] = p;
                cout << "\33[33m"
                     << "\n\t\t\t\t\t\tOrder Placed. \n";
                // storeOrderedItemsWithID(userIdentity11, orderedItems11, orderedItemsQuantity11, orderedItemsPrices11, orderNum);
                // storeUserIdentityWithID(userIdentity11);
                cls();
                return;
            }
            else
            {
                cout << "\33[31m"
                     << "\n\t\t\t\t\t\tInvalid Data. Dont use commas and write phone number in (923331234567) Format\n"
                     << "\33[0m";
                cls();
                continue;
            }
        }
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid Quantity.\n";
        cls();
        header();
        return shop11(foodMenuShop11, foodMenuPricesShop11, totalShop11Items, orderedItems11, orderedItemsQuantity11, orderedItemsPrices11, userIdentity11);
    }
}

// shop11 order for customer
void shop12(string foodMenuShop12[], int foodMenuPricesShop12[], int totalShop12Items, string orderedItems12[], int orderedItemsQuantity12[], int orderedItemsPrices12[], string userIdentity12[])
{
    string input, n, h, p;
    string quantity;
    bool isSuccesfull = false, maxOrder = false, orderDone = false;
    int maxOrderedItems = 5;
    cout << "\33[32m"
         << "\t\t\t\t\t\t     Item                        Price in Rupees\n";
    for (int i = 0; i < totalShop12Items; i++)
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << foodMenuShop12[i] << " | " << setw(5) << right << foodMenuPricesShop12[i] << " Rupees" << endl;
    }
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter a item you want to order: (1 to " << totalShop12Items << "): ";
    hideCursor(1);
    getline(cin, input);
    hideCursor(0);
    if (input == "BB")
    {
        return;
    }
    bool isValid = false;
    for (int i = 1; i <= totalShop12Items; i++)
    {
        if (input == to_string(i))
        {
            isValid = true;
            break;
        }
    }
    if (isValid)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\tEnter quantity of " << foodMenuShop12[stoi(input) - 1] << " Max=30: ";
        hideCursor(1);
        getline(cin, quantity);
        hideCursor(0);
        if (validQuantity(quantity))
        {
            string option = orderMore();
            if (option == "1")
            {
                if (orderNum <= 5)
                {
                    system("cls");
                    header();
                    orderedItems12[orderNum] = foodMenuShop12[stoi(input) - 1];
                    orderedItemsPrices12[orderNum] = foodMenuPricesShop12[stoi(input) - 1];
                    orderedItemsQuantity12[orderNum] = stoi(quantity);
                    orderNum++;
                    if (orderNum == 5)
                    {
                        maxOrder = true;
                    }
                    else
                    {
                        return shop12(foodMenuShop12, foodMenuPricesShop12, totalShop12Items, orderedItems12, orderedItemsQuantity12, orderedItemsPrices12, userIdentity12);
                    }
                }
            }
            else
            {
                system("cls");
                header();
                if (orderNum == 0)
                {
                    orderedItems12[orderNum] = foodMenuShop12[stoi(input) - 1];
                    orderedItemsPrices12[orderNum] = foodMenuPricesShop12[stoi(input) - 1];
                    orderedItemsQuantity12[orderNum] = stoi(quantity);
                    calculateBill(input, foodMenuPricesShop12, totalShop12Items);
                    cls();
                    orderDone = true;
                }
                else
                {
                    orderedItems12[orderNum] = foodMenuShop12[stoi(input) - 1];
                    orderedItemsPrices12[orderNum] = foodMenuPricesShop12[stoi(input) - 1];
                    orderedItemsQuantity12[orderNum] = stoi(quantity);
                    orderNum++;

                    cout << "\33[32m"
                         << "\t\t\t\t\t\tDisplaying your Items and Bill in a moment.\n";
                    cls();
                    header();
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        cout << "\33[32m"
                             << "\t\t\t\t\t\t" << orderedItemsQuantity12[index] << " of " << orderedItems12[index] << endl;
                    }
                    cout << "\33[32m" << endl;
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        totalPrice = totalPrice + orderedItemsPrices12[index] * orderedItemsQuantity12[index];
                    }
                    cout << "\33[36m"
                         << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;

                    orderDone = true;
                    cls();
                }
            }
        }
        else
        {
            cls();
            header();
            return shop12(foodMenuShop12, foodMenuPricesShop12, totalShop12Items, orderedItems12, orderedItemsQuantity12, orderedItemsPrices12, userIdentity12);
        }
        if (maxOrder)
        {
            cout << "\33[33m"
                 << "\t\t\t\t\t\tYou have ordered max Items. Displaying your bill in a moment\n";
            loadingFunction();
            system("cls");
            header();
            for (int index = 0; index < 5; index++)
            {
                cout << "\33[32m"
                     << "\t\t\t\t\t\t" << orderedItemsQuantity12[index] << " of " << orderedItems12[index] << endl;
            }
            cout << "\33[32m" << endl;
            for (int index = 0; index < 5; index++)
            {
                totalPrice = totalPrice + orderedItemsPrices12[index] * orderedItemsQuantity12[index];
            }
            cout << "\33[36m"
                 << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
            cls();
            header();
            getDiscount(totalPrice);
            orderDone = true;
        }
    }
    if (orderDone)
    {
        while (true)
        {
            system("cls");
            header();
            // user Identity so that delievry boy can check order and user info
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your name: ";
            hideCursor(1);
            getline(cin, n);
            if (n == "BB")
            {
                return;
            }
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Hall: ";
            getline(cin, h);
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Phone Number: ";
            getline(cin, p);
            hideCursor(0);
            if (validData(n, h, p))
            {
                userIdentity12[0] = n;
                userIdentity12[1] = h;
                userIdentity12[2] = p;
                cout << "\33[33m"
                     << "\n\t\t\t\t\t\tOrder Placed. \n";
                // storeOrderedItemsWithID(userIdentity12, orderedItems12, orderedItemsQuantity12, orderedItemsPrices12, orderNum);
                // storeUserIdentityWithID(userIdentity12);
                cls();
                return;
            }
            else
            {
                cout << "\33[31m"
                     << "\n\t\t\t\t\t\tInvalid Data. Dont use commas and write phone number in (923331234567) Format\n"
                     << "\33[0m";
                cls();
                continue;
            }
        }
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid Quantity.\n";
        cls();
        header();
        return shop12(foodMenuShop12, foodMenuPricesShop12, totalShop12Items, orderedItems12, orderedItemsQuantity12, orderedItemsPrices12, userIdentity12);
    }
}

// checks for input qunatity if it is valid
bool validQuantity(string quantity)
{
    bool isValid = false;
    for (int i = 1; i <= 30; i++)
    {
        if (quantity == to_string(i))
        {
            isValid = true;
            break;
        }
    }

    if (isValid)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// calculates bill for single item
void calculateBill(string input, int foodPrices[], int totalItems)
{
    string quantity;
    int bill;
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter Quantity again (Min=1 and Max=30): ";
    hideCursor(1);
    getline(cin, quantity);
    hideCursor(0);
    if (quantity == "BB")
    {
        return;
    }
    bool isValid = false;
    for (int i = 1; i <= 30; i++)
    {
        if (quantity == to_string(i))
        {
            isValid = true;
            break;
        }
    }

    if (isValid)
    {
        int Quantity = stoi(quantity);
        int Price = stoi(input);
        bill = Quantity * foodPrices[Price - 1];
        cout << "\33[36m"
             << "\t\t\t\t\t\tYour Bill is " << bill << " Rupees\n";
    }
    else
    {
        cls();
        header();
        return calculateBill(input, foodPrices, totalItems);
    }
}

// to order more than one input
string orderMore()
{
    string option;
    cout << "\33[34m"
         << "\t\t\t\t\t\tDo you want to order something else? (1 for Yes and any other key to continue): ";
    hideCursor(1);
    getline(cin, option);
    hideCursor(0);
    return option;
}

// user gets discount for ordering 5 items
void getDiscount(int bill) // user Functionality
{
    int discount = 0;
    string option;
    cout << "\33[33m"
         << "\t\t\t\t\t\tDo you want to get a 10 %/ discount on this purchase (1 for Yes and 2 for No): ";
    hideCursor(1);
    getline(cin, option);
    hideCursor(0);
    if (option == "1")
    {
        discount = bill - (bill * 0.1);
        cout << "\33[36m"
             << "\t\t\t\t\t\tYour Bill after discount is " << discount << endl;
    }
    else
    {
        return;
    }
}

// to order drinks
void drinksOrder(string drinkItems[], int drinkPrices[], int totalDrinks, string orderedDrinks[], int orderedDrinksQuantity[], int orderedDrinksPrices[], string userIdentity9[])
{
    string input;
    string quantity, n, h, p;
    bool isSuccesfull = false, maxOrder = false, orderDone = false;
    int maxOrderedItems = 5;
    cout << "\33[32m"
         << "\t\t\t\t\t\t     Drinks                       Price in Rupees\n";
    for (int i = 0; i < totalDrinks; i++)
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << drinkItems[i] << " | " << setw(5) << right << drinkPrices[i] << " Rupees" << endl;
    }
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter a drinks you want to order: (1 to " << totalDrinks << "): ";
    hideCursor(1);
    getline(cin, input);
    hideCursor(0);
    if (input == "BB")
    {
        return;
    }
    bool isValid = false;
    for (int i = 1; i <= totalDrinks; i++)
    {
        if (input == to_string(i))
        {
            isValid = true;
            break;
        }
    }
    if (isValid)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\tEnter quantity of " << drinkItems[stoi(input) - 1] << " Max=30: ";
        hideCursor(1);
        getline(cin, quantity);
        hideCursor(0);
        if (validQuantity(quantity))
        {
            string option = orderMore();
            if (option == "1")
            {
                if (orderNum <= 5)
                {
                    system("cls");
                    header();
                    orderedDrinks[orderNum] = drinkItems[stoi(input) - 1];
                    orderedDrinksPrices[orderNum] = drinkPrices[stoi(input) - 1];
                    orderedDrinksQuantity[orderNum] = stoi(quantity);
                    orderNum++;
                    if (orderNum == 5)
                    {
                        maxOrder = true;
                    }
                    else
                    {
                        return drinksOrder(drinkItems, drinkPrices, totalDrinks, orderedDrinks, orderedDrinksQuantity, orderedDrinksPrices, userIdentity9);
                    }
                }
            }
            else
            {
                system("cls");
                header();
                if (orderNum == 0)
                {
                    orderedDrinks[orderNum] = drinkItems[stoi(input) - 1];
                    orderedDrinksPrices[orderNum] = drinkPrices[stoi(input) - 1];
                    orderedDrinksQuantity[orderNum] = stoi(quantity);
                    calculateBill(input, drinkPrices, totalDrinks);
                    cls();
                    orderDone = true;
                }
                else
                {
                    orderedDrinks[orderNum] = drinkItems[stoi(input) - 1];
                    orderedDrinksPrices[orderNum] = drinkPrices[stoi(input) - 1];
                    orderedDrinksQuantity[orderNum] = stoi(quantity);
                    orderNum++;

                    cout << "\33[32m"
                         << "\t\t\t\t\t\tDisplaying your Items and Bill in a moment.\n";
                    cls();
                    header();
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        cout << "\33[32m"
                             << "\t\t\t\t\t\t" << orderedDrinksQuantity[index] << " " << orderedDrinks[index] << endl;
                    }
                    cout << "\33[32m" << endl;
                    for (int index = 0; index < orderNum + 1; index++)
                    {
                        totalPrice = totalPrice + orderedDrinksPrices[index] * orderedDrinksQuantity[index];
                    }
                    cout << "\33[36m"
                         << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
                    orderDone = true;
                    cls();
                }
            }
        }
        else
        {
            cls();
            header();
            return drinksOrder(drinkItems, drinkPrices, totalDrinks, orderedDrinks, orderedDrinksQuantity, orderedDrinksPrices, userIdentity9);
        }
        if (maxOrder)
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\tYou have ordered max Items. Displaying your bill in a moment\n";
            loadingFunction();
            system("cls");
            header();
            for (int index = 0; index < 5; index++)
            {
                cout << "\33[32m"
                     << "\t\t\t\t\t\t" << orderedDrinksQuantity[index] << " " << orderedDrinks[index] << endl;
            }
            cout << "\33[32m" << endl;
            for (int index = 0; index < 5; index++)
            {
                totalPrice = totalPrice + orderedDrinksPrices[index] * orderedDrinksQuantity[index];
            }
            cout << "\33[36m"
                 << "\n\t\t\t\t\t\tYour total is: " << totalPrice << endl;
            cls();
            header();
            getDiscount(totalPrice);
            orderDone = true;
        }
    }
    if (orderDone)
    {
        while (true)
        {
            system("cls");
            header();
            // user Identity so that delievry boy can check order and user info
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your name: ";
            hideCursor(1);
            getline(cin, n);
            if (n == "BB")
            {
                return;
            }
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Hall: ";
            getline(cin, h);
            cout << "\33[33m"
                 << "\n\t\t\t\t\t\tEnter Your Phone Number: ";
            getline(cin, p);
            hideCursor(0);
            if (validData(n, h, p))
            {
                userIdentity9[0] = n;
                userIdentity9[1] = h;
                userIdentity9[2] = p;
                cout << "\33[33m"
                     << "\n\t\t\t\t\t\tOrder Placed. \n";
                cls();
                return;
            }
            else
            {
                cout << "\33[31m"
                     << "\n\t\t\t\t\t\tInvalid Data. Dont use commas and write phone number in (923331234567) Format\n"
                     << "\33[0m";
                cls();
                continue;
            }
        }
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid Input.\n";
        cls();
        header();
        return drinksOrder(drinkItems, drinkPrices, totalDrinks, orderedDrinks, orderedDrinksQuantity, orderedDrinksPrices, userIdentity9);
    }
}

// booking table functionalities
void performTableAction(bool bookedTables[], string userInfo[])
{
    string option, tableNum, tableToCheck;
    // book table
    cout << "\33[32m"
         << "\t\t\t\t\t\t1. Book a Table\n";
    // cancel booking
    cout << "\33[32m"
         << "\t\t\t\t\t\t2. Cancel Booking\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter your choice: ";
    hideCursor(1);
    getline(cin, option);
    hideCursor(0);
    if (option == "BB")
    {
        return;
    }
    if (option == "1" || option == "2")
    {
        if (option == "1")
        {
            // checks table availablity
            cout << "\33[33m"
                 << "\t\t\t\t\t\tEnter Table Number to check its availability (1 to 30): ";
            hideCursor(1);
            getline(cin, tableToCheck);
            hideCursor(0);
            if (isValidTable(tableToCheck))
            {
                // Valid table number input
                cout << "\33[33m"
                     << "\t\t\t\t\t\tEnter Table Number to book (1 to 30): ";
                hideCursor(1);
                getline(cin, tableNum);
                hideCursor(0);
                if (tableNum == "BB")
                {
                    return;
                }
                // checks validity of table and if it is previously booked
                if (isValidTable(tableNum) && !isTableBooked(bookedTables, tableNum))
                {
                    bookTable(bookedTables, tableNum, userInfo);
                    cls();
                }
                else
                {
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tInvalid table number entered or table is already booked. Try again." << endl;
                    cls();
                    header();
                    return performTableAction(bookedTables, userInfo);
                }
            }
            else
            {
                cout << "\33[31m"
                     << "\t\t\t\t\t\tInvalid table number entered. Please enter a number between 1 and 30." << endl;
                cls();
                header();
                return performTableAction(bookedTables, userInfo);
            }
        }
        else if (option == "2")
        {

            cout << "\33[33m"
                 << "\t\t\t\t\t\tEnter Table Number to cancel booking (1 to 30): ";
            hideCursor(1);
            getline(cin, tableNum);
            hideCursor(0);
            if (tableNum == "BB")
            {
                return;
            }
            // checks validity of entered table
            if (isValidTable(tableNum))
            {
                if (isTableBooked(bookedTables, tableNum))
                {
                    // cancel booking if table is valid
                    cancelBooking(bookedTables, tableNum);
                    cls();
                }
                else
                {
                    // cancelling booking
                    cout << "\33[32m"
                         << "\t\t\t\t\t\tTable " << tableNum << " is not booked. No booking to cancel." << endl;
                    cls();
                    header();
                }
            }
            else
            {
                cout << "\33[31m"
                     << "\t\t\t\t\t\tInvalid option entered. Please enter 1 or 30." << endl;
                cls();
                header();
                return performTableAction(bookedTables, userInfo);
            }
        }
        else
        {
            cout << "\33[31m"
                 << "\t\t\t\t\t\tInvalid option entered. Please enter 1 or 2." << endl;
            cls();
            header();
            return performTableAction(bookedTables, userInfo);
        }
    }
}

// check validity of tables
bool isValidTable(string tableNum)
{
    if (tableNum == "1" || tableNum == "2" || tableNum == "3" || tableNum == "4" || tableNum == "5" || tableNum == "6" || tableNum == "7" || tableNum == "8" || tableNum == "9" || tableNum == "10" || tableNum == "11" || tableNum == "12" || tableNum == "13" || tableNum == "14" || tableNum == "15" || tableNum == "16" || tableNum == "17" || tableNum == "18" || tableNum == "19" || tableNum == "20" || tableNum == "21" || tableNum == "22" || tableNum == "23" || tableNum == "24" || tableNum == "25" || tableNum == "26" || tableNum == "27" || tableNum == "28" || tableNum == "29" || tableNum == "30")
    {
        return true;
    }
    return false;
}

// booking a table
void bookTable(bool bookedTables[], string tableNum, string userInfo[])
{
    string n, t, p;
    if (isValidTable(tableNum))
    {
        if (bookedTables[stoi(tableNum) - 1])
        {
            // returns info that table is already booked
            cout << "\33[36m"
                 << "\t\t\t\t\t\tTable " << tableNum << " is already booked. Please choose another table." << endl;
        }
        else
        {
            // booking successfull
            bookedTables[stoi(tableNum) - 1] = true;
            cout << "\33[32m"
                 << "\t\t\t\t\t\tTable " << tableNum << " has been successfully booked.\n";
            while (true)
            {
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter your name: ";
                hideCursor(1);
                getline(cin, n);
                if (n == "BB")
                {
                    return;
                }
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter your Phone Number: ";
                getline(cin, p);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter your Arrival Time: ";
                getline(cin, t);
                hideCursor(0);
                if (validData(n, t, p))
                {
                    userInfo[0] = n;
                    userInfo[1] = p;
                    userInfo[2] = t;
                    return;
                }
                else
                {
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tInvalid Data\n";
                    cls();
                    header();
                    continue;
                }
            }
        }
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid table number entered. Please enter a number between 1 and 30." << endl;
        cls();
        header();
        return;
    }
}

// cancelling a booking
void cancelBooking(bool bookedTables[], string tableNum)
{
    if (isValidTable(tableNum))
    {
        if (bookedTables[stoi(tableNum) - 1])
        {
            // cancelling booking
            bookedTables[stoi(tableNum) - 1] = false;
            cout << "\33[32m"
                 << "\t\t\t\t\t\tBooking for Table " << tableNum << " has been canceled." << endl;
        }
        else
        {
            // not booked already
            cout << "\33[32m"
                 << "\t\t\t\t\t\tTable " << tableNum << " is not booked." << endl;
        }
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid table number entered. Please enter a number between 1 and 30." << endl;
        cls();
        header();
        return;
    }
}

// checks if table is already booked
bool isTableBooked(const bool bookedTables[], string tableNum)
{
    if (isValidTable(tableNum))
    {
        // table is already booked
        if (bookedTables[stoi(tableNum) - 1])
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\tAlready Booked\n";
            // cls();
            return true;
        }
        else
        {
            // not booked already
            cout << "\33[32m"
                 << "\t\t\t\t\t\tNot Booked\n";
            // cls();
            return false;
        }
    }
    else
    {
        return false;
    }
}

// take suggestion from user
void takeSuggestion(string suggestions[], int &totalSuggestions)
{
    string userInput;
    // enter a suggestion
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter a suggestion: ";
    hideCursor(1);
    getline(cin, userInput);
    if (empty(userInput) || hasTabs(userInput))
    {
        return;
    }
    hideCursor(0);
    if (userInput == "BB")
    {
        return;
    }
    if (totalSuggestions < maxSuggestions)
    {
        // adding a suggestion to an array and storing it
        suggestions[totalSuggestions++] = userInput;
        cout << "\33[32m"
             << "\t\t\t\t\t\tThank you for your suggestion! We will do our best to accommodate this suggestion." << endl;
        cls();
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tMaximum limit reached for suggestions. Unable to submit more. " << endl;
        cls();
        return;
    }
}

// take complaints
void takeComplaint(string complaints[], int &totalComplaints)
{
    string userInput;
    cout << "\33[33m"
         << "\t\t\t\t\t\tSubmit a complaint: ";
    hideCursor(1);
    getline(cin, userInput);
    hideCursor(0);
    if (empty(userInput) || hasTabs(userInput))
    {
        return;
    }

    if (userInput == "BB")
    {
        return;
    }
    if (totalComplaints < maxComplaints)
    {
        // increment complaints in array
        complaints[totalComplaints++] = userInput;
        cout << "\33[32m"
             << "\t\t\t\t\t\tThank you for your response! We will look deeply into this matter." << endl;
        cls();
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tMaximum limit reached for complaints. Unable to submit more." << endl;
        cls();
        return;
    }
}

// review types functipn
string reviewType()
{
    string option;
    cout << "\33[32m"
         << "\t\t\t\t\t\tDo you want to give a feedback about the Food(1) or SSC(2)? ";
    hideCursor(1);
    getline(cin, option);
    hideCursor(0);
    if (option == "1" || option == "2" || option == "BB")
    {
        return option;
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid Option.\n";
        cls();
        header();
        return reviewType();
    }
}

// rating systems for users
void takeReviewsForPublic(string userReviewsForPublic[], int &totalReviewsForPublic) // user functionality
{
    string userInput, option;
    cout << "\33[32m"
         << "\t\t\t\t\t\tDo you want to leave a feedback or watch other customers feedbacks (1 for first, 2 for second)? ";
    hideCursor(1);
    getline(cin, option);
    hideCursor(0);
    if (option == "BB")
    {
        return;
    }
    else if (option == "1")
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\tEnter a feedback: ";
        hideCursor(1);
        getline(cin, userInput);
        hideCursor(0);
        if (empty(userInput) || hasTabs(userInput))
        {
            return;
        }

        if (totalReviewsForPublic < maxReviewsForPublic)
        {
            userReviewsForPublic[totalReviewsForPublic++] = userInput;
            cout << "\33[32m"
                 << "\t\t\t\t\t\tThank you for your feedback! We will do our best to accommodate this suggestion." << endl;
            cls();
        }
        else
        {
            cout << "\33[31m"
                 << "\t\t\t\t\t\tMaximum limit reached for feedbacks. Unable to submit more." << endl;
            cls();
            header();
        }
    }
    else if (option == "2")
    {

        cout << "\33[32m"
             << "\t\t\t\t\t\tFeedbacks:" << endl;
        for (int i = 0; i < totalReviewsForPublic; ++i)
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\t" << i + 1 << ". " << userReviewsForPublic[i] << endl;
        }
        cls();
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid Option." << endl;
        cls();
        header();
        return;
    }
}

// take reviews for chef
void takeReviewsForChef(string userReviewsForChef[], int &totalReviewsForChef) // user functionality
{
    string userInput, option;
    cout << "\33[32m"
         << "\t\t\t\t\t\tDo you want to leave a feedback or go back (1 for first, 2 for going back)? ";
    hideCursor(1);
    getline(cin, option);
    hideCursor(0);
    if (option == "1")
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\tEnter a feedback: ";
        hideCursor(1);
        getline(cin, userInput);
        hideCursor(0);
        if (empty(userInput) || hasTabs(userInput))
        {
            return;
        }
        if (totalReviewsForChef < maxReviewsForChef)
        {
            userReviewsForChef[totalReviewsForChef++] = userInput;

            cout << "\33[32m"
                 << "\t\t\t\t\t\tThank you for your feedback! We will do our best to accommodate this suggestion." << endl;
            cls();
        }
        else
        {
            cout << "\33[31m"
                 << "\t\t\t\t\t\tMaximum limit reached for feedbacks. Unable to submit more." << endl;
            cls();
            header();
        }
    }
    else
    {
        return;
    }
}

// view notifications by admin
void viewNotifications(string notification[], int totalNotifications) // customer functionality tba
{
    cout << "\33[32m"
         << "\t\t\t\t\t\tNotifications:" << endl;
    for (int i = 0; i < totalNotifications; ++i)
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << notification[i] << endl;
    }
    cls();
}

// view rules by user
void displayRules(string rules[], int currentRules) // customer functionality tba
{
    for (int i = 0; i < currentRules; ++i)
    {
        cout << "\33[32m" << rules[i] << endl;
    }
    cls();
}

// messaging helpline boy by customer to resolve any issu
void messageToHelplineBoyByCustomer(string username, string messageByHelplineBoy[], string userMessages[], string HelplineLineBoyReplies[], int &totalMessages, int totalHelplineBoyMessages, int totalUsers) // change to helpline
{
    string option, message;
    bool hasMsg = false;
    cout << "\33[32m"
         << "\t\t\t\t\t\tDo you want to send a new message or go to Inbox (1 for New Message and 2 for Inbox): ";
    hideCursor(1);
    getline(cin, option);
    hideCursor(0);
    if (option == "BB")
    {
        return;
    }
    else if (option == "1")
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\tEnter a message(Please Write Your Username in end): ";
        hideCursor(1);
        getline(cin, message);
        hideCursor(0);
        getCurrentTimestamp();
        if (totalMessages < maxMessages)
        {
            userMessages[totalMessages++] = message;
        }
        else
        {
            cout << "\33[31m"
                 << "\t\t\t\t\t\tMaximum limit reached for messages." << endl;
            cls();
            header();
        }
    }
    else if (option == "2")
    {
        for (int i = 0; i < totalUsers; ++i)
        {
            if (username == messageByHelplineBoy[i])
            {
                hasMsg = true;
                break;
            }
        }
        if (hasMsg)
        {
            if (totalMessages == 0 && totalHelplineBoyMessages == 0)
            {
                cout << "\33[31m"
                     << "\t\t\t\t\t\tInbox is Empty\n";
                cls();
            }
            if (totalHelplineBoyMessages > 0)
            {
                cout << "\33[32m"
                     << "\t\t\t\t\t\tMessages \n"
                     << endl;
                for (int i = 0; i < totalHelplineBoyMessages; ++i)
                {
                    cout << "\33[32m"
                         << "\t\t\t\t\t\t" << i + 1 << ". Customer Care: " << HelplineLineBoyReplies[i] << endl;
                }
                cls();
            }
            if (totalMessages > 0)
            {
                cout << "\33[32m"
                     << "\n\t\t\t\t\t\tUser Messages \n"
                     << endl;
                for (int i = 0; i < totalMessages; ++i)
                {
                    cout << "\33[32m"
                         << "\t\t\t\t\t\t" << i + 1 << ". User: " << userMessages[i] << endl;
                }
            }
            cls();
        }
        else
        {
            cout << "\33[31m"
                 << "\t\t\t\t\t\tInbox is Empty\n";
        }
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid Input." << endl;
        cls();
        header();
        return messageToHelplineBoyByCustomer(username, messageByHelplineBoy, userMessages, HelplineLineBoyReplies, totalMessages, totalHelplineBoyMessages, totalUsers);
    }
}

// about ssc
void aboutUs()
{
    cout << "\33[32m"
         << "\t\t\t\t\t\tWelcome to the Students' Services Center (SSC) at UET Lahore!" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tAt SSC, we take pride in providing a vibrant and welcoming environment\n\t\t\t\t\t\tthat caters to the diverse needs of our esteemed students. Whether you are\n\t\t\t\t\t\ta hostel resident or a day scholar, our center is designed \n\t\t\t\t\t\tto ensure your comfort, convenience, and overall well-being throughout \n\t\t\t\t\t\tyour academic journey." << endl
         << endl;

    cout << "\33[32m"
         << "\t\t\t\t\t\tExceptional Facilities:" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tStep into SSC, where exceptional facilities await you. From spacious study areas equipped with the \n\t\t\t\t\t\tlatest technology to recreational spaces fostering camaraderie \n\t\t\t\t\t\tamong students, we offer a diverse range of amenities. Our state-of-the-art \n\t\t\t\t\t\tfacilities aim to create a conducive environment for both \n\t\t\t\t\t\tlearning and relaxation." << endl
         << endl;

    cout << "\33[32m"
         << "\t\t\t\t\t\tDedicated and Friendly Staff:" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tOur dedicated team at SSC is committed to providing unparalleled support and assistance. From addressing\n\t\t\t\t\t\tyour queries to offering guidance on various aspects of student life, \n\t\t\t\t\t\tyour friendly staff is always available to lend a helping hand. Approachable, \n\t\t\t\t\t\tknowledgeable, and supportive – they are here to ensure your experience \n\t\t\t\t\t\tat SSC is enriching and fulfilling." << endl
         << endl;

    cout << "\33[32m"
         << "\t\t\t\t\t\tCulinary Deliveryghts and Dining Experience:" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tSSC takes pride in its delectable range of culinary offerings. Our dining options boast \n\t\t\t\t\t\ta wide array of flavorful cuisines that cater to various tastes and dietary \n\t\t\t\t\t\tpreferences. Our chefs craft Deliverycious meals using fresh ingredients, ensuring \n\t\t\t\t\t\ta Deliveryghtful dining experience for all. Whether you're craving \n\t\t\t\t\t\ta quick snack between classes or a hearty meal after a long day, \n\t\t\t\t\t\tSSC's food choices have you covered." << endl
         << endl;

    cout << "\33[32m"
         << "\t\t\t\t\t\tComprehensive Services for Student Needs:" << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tUnderstanding the diverse needs of our student community, SSC endeavors\n\t\t\t\t\t\tto provide comprehensive services. supplies and resources, we aim to \n\t\t\t\t\t\tmake daily life convenient for hostel residents. All the \n\t\t\t\t\t\tbasic needs of students are fulfilled here" << endl
         << endl;

    cout << "\33[32m"
         << "\t\t\t\t\t\tAt SSC, we believe in fostering a supportive community where students \n\t\t\t\t\t\tfeel at home. We strive to create an environment that not only meets but \n\t\t\t\t\t\texceeds the expectations of our students, ensuring \n\t\t\t\t\t\ttheir university experience is memorable and fulfilling." << endl
         << endl;

    cout << "\33[32m"
         << "\t\t\t\t\t\tWe welcome you to explore the array of services and \n\t\t\t\t\t\tfacilities at Students' Services Center, your home away from home at UET Lahore." << endl;
    cls();
}

// change password
void changePassword(string usernames[], string passwords[], int totalUsers, string username)
{
    system("cls");
    loginPageHeader();
    string newPassword, checkNewPassword;
    // enter new pass
    cout << "\33[32m"
         << "\t\t\t\t\t\tEnter a new password: ";
    hideCursor(1);
    getline(cin, newPassword);
    hideCursor(0);
    // if option bb go back
    if (newPassword == "BB")
    {
        return;
    }
    // if pass is not valid
    if (!validPassword(newPassword))
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tPassword is invalid. Please try again." << endl;
        cls();
        return changePassword(usernames, passwords, totalUsers, username);
    }

    cout << "\33[32m"
         << "\t\t\t\t\t\tEnter the new password again: ";
    hideCursor(1);
    getline(cin, checkNewPassword);
    hideCursor(0);
    // if passwords are not equal recusive call
    if (newPassword != checkNewPassword)
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tPasswords do not match. Please try again." << endl;
        cls();
        return changePassword(usernames, passwords, totalUsers, username);
    }

    // if all is true password is changed
    for (int i = 0; i < totalUsers; ++i)
    {
        if (usernames[i] == username)
        {
            passwords[i] = newPassword;
            cout << "\33[32m"
                 << "\t\t\t\t\t\tPassword changed successfully for user: " << username << endl;
            cls();
        }
    }
}

// change username for customer
// same logic as Chnage password
void changeUsername(string usernames[], int totalUsers, string username)
// cust new
{
    system("cls");
    loginPageHeader();
    string newUsername, checkNewUsername;
    cout << "\33[32m"
         << "\t\t\t\t\t\tEnter a new Username: ";
    hideCursor(1);
    getline(cin, newUsername);
    hideCursor(0);
    if (newUsername == "BB")
    {
        return;
    }
    if (empty(newUsername) || hasTabs(newUsername) || newUsername.length() < 6 || newUsername.length() > 10 || !noComma(newUsername))
    {
        gotoxy(4, 23);
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid Username. " << endl;
        cls();
        loginPageHeader();
        return changeUsername(usernames, totalUsers, username);
    }
    if ((isUniqueUser(usernames, totalUsers, newUsername) && (newUsername.length() >= 6 && newUsername.length() <= 10)))
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\tEnter the new Username again: ";
        hideCursor(1);
        getline(cin, checkNewUsername);
        hideCursor(0);
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tUsername is invalid. Please try again." << endl;
        cls();
        return changeUsername(usernames, totalUsers, username);
    }

    if (newUsername != checkNewUsername)
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tUsernames do not match. Please try again." << endl;
        cls();
        return changeUsername(usernames, totalUsers, username);
    }

    for (int i = 0; i < totalUsers; ++i)
    {
        if (usernames[i] == username)
        {
            usernames[i] = newUsername;
            cout << "\33[32m"
                 << "\t\t\t\t\t\tUsername changed successfully for user from " << username << " to " << newUsername << endl;
            cls();
        }
    }
}

// delete users account
void deleteUser(string usernames[], string passwords[], string ages[], string genders[], string phoneNumbers[], int &totalUsers, string currentUser) // customer functionality
{
    // intitialize as -1
    int index = -1;
    for (int i = 0; i < totalUsers; ++i)
    {
        // finding index
        if (usernames[i] == currentUser)
        {
            index = i;
            break;
        }
    }

    // to del user
    if (index != -1)
    {
        // delete all info related to user
        for (int i = index; i < totalUsers - 1; ++i)
        {
            usernames[i] = usernames[i + 1];
            passwords[i] = passwords[i + 1];
            ages[i] = ages[i + 1];
            phoneNumbers[i] = phoneNumbers[i + 1];
            genders[i] = genders[i + 1];
        }
        totalUsers--;
        cout << "\33[31"
             << "\t\t\t\t\t\tUser " << currentUser << " removed successfully!" << endl;
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tUser not found or unable to delete account." << endl;
        cls();
    }
}

// to see if admin trying to login exists or not
bool isExistingAdmin(string adminUsernames[], string adminPasswords[], int totalAdmins, string adminUsername, string adminPassword)
{
    for (int i = 0; i < totalAdmins; ++i)
    {
        // returns true if admin exists
        if (adminUsernames[i] == adminUsername && adminPasswords[i] == adminPassword)
        {
            return true;
        }
    }
    return false;
}

// admin menu
int adminMenu()
{
    cout << "\33[32m"
         << "\t\t\t\t\t\tAdmin Menu\n"
         << "\33[0m";
    cout << "\33[33m"
         << "\t\t\t\t\t\t1. Add/Remove Shops, Menu, Drinks, Employees, Chefs, Delivery Boys, Helpline Boys, Customer Service, Accountants" << endl;
    cout << "\33[33m"
         << "\t\t\t\t\t\t2. View Customers, Employees , Chefs, Delivery Boys, Helpine boys, Customer Service Boys, Accountants Data\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t3. Delete Customers, Employees, Chefs, Delivery Boys, Helpine boys, Customer Service Account Data\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t4. Add new Admin\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t5. Add Rules\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t6. Send Notification\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t7. Edit Admin Username\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t8. Change Password\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t9. Delete Account\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t10. Log Out\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t11. Exit\n";
    int input = movementOfArrow(45, 18, 1, 11);
    return input;
}

// ADD GO BACK HERE
// select admin option1 suboptions
int selectFromAdminOption1()
{
    cout << "\33[32m"
         << "\t\t\t\t\t\tAdd/Remove"
         << "\33[0m" << endl;
    cout << "\33[33m"
         << "\t\t\t\t\t\t1. For Shops\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t2. For Menu\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t3. For Drinks\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t4. For Employee\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t5. For Chefs\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t6. For Delivery boys\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t7. For Helpline boys\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t8. For Customer Service\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t9. For Accountants\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t10. Go Back\n";
    int input = movementOfArrow(45, 18, 1, 10);
    return input;
}

// managing shops by admin
void manageShops(string shopList[], int &totalShops)
{
    bool isUpdated = false;
    cout << "\33[33m"
         << "\t\t\t\t\t\tSHOP LIST " << endl;
    // listing shops
    for (int i = 0; i < totalShops; i++)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << shopList[i] << endl;
    }
    // adding or removing a shop
    string action;
    hideCursor(1);
    cout << "\33[32m"
         << "\t\t\t\t\t\tDo you want to add (a) or remove (r) a shop? ";
    getline(cin, action);
    hideCursor(0);
    if (action == "BB") // go back if bb
    {
        return;
    }
    else if (action == "a") // add if a
    {
        addShop(shopList, totalShops);
        isUpdated = true;
    }
    else if (action == "r") // remove if r
    {
        removeShop(shopList, totalShops);
        isUpdated = true;
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid action. Enter either a or r." << endl; // invalid input
        cls();
        header();
        return manageShops(shopList, totalShops); // Recursive call for invalid input
    }

    if (isUpdated)
    {
        system("cls");
        header();
        storeShopsToFile(shopList, totalShops);
        cout << "\33[33m"
             << "\t\t\t\t\t\tUpdated Shop List: " << endl; // list after Update
        for (int i = 0; i < totalShops; i++)
        {
            cout << "\33[33m"
                 << "\t\t\t\t\t\t" << i + 1 << ". " << shopList[i] << endl;
        }
        cls();
    }
}

// add new shop
void addShop(string shops[], int &totalShops)
{
    system("cls");
    header();
    if (totalShops < maxShops)
    {
        string newShop;
        cout << "\33[33m"
             << "\t\t\t\t\t\t SHOP LIST " << endl; // list
        for (int i = 0; i < totalShops; i++)
        {
            cout << "\33[33m"
                 << "\t\t\t\t\t\t" << i + 1 << ". " << shops[i] << endl; // lsit shops
        }
        hideCursor(1);
        cout << "\33[32m"
             << "\t\t\t\t\t\tEnter the name of the shop to add: "; // add new shops
        getline(cin, newShop);
        hideCursor(0);
        if (empty(newShop) || hasTabs(newShop) || !noCommaItem(newShop))
        {
            return;
        }
        if (newShop == "BB")
        {
            return;
        }
        shops[totalShops] = newShop;
        totalShops++; // increment total shops
        cout << "\33[33m"
             << "\t\t\t\t\t\tShop added successfully!" << endl;
        cls();
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tShop limit reached. Cannot add more shops." << endl;
        cls();
        return addShop(shops, totalShops);
    }
}

// remove a shop
void removeShop(string shops[], int &totalShops)
{
    system("cls");
    header();
    cout << "\33[33m"
         << "\t\t\t\t\t\t SHOP LIST " << endl;
    for (int i = 0; i < totalShops; i++)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << shops[i] << endl;
    }
    string index;
    hideCursor(1);
    cout << "\33[32m"
         << "\t\t\t\t\t\tEnter the number of the shop to remove: ";
    getline(cin, index);
    hideCursor(0);
    if (index == "BB")
    {
        return;
    }

    bool isValid = false;
    // validation
    for (int i = 1; i <= totalShops; i++)
    {
        if (index == to_string(i))
        {
            isValid = true;
            break;
        }
    }

    if (isValid)
    {
        for (int i = stoi(index) - 1; i < totalShops - 1; i++)
        {
            shops[i] = shops[i + 1];
        }
        totalShops--;
        cout << "\33[31m"
             << "\t\t\t\t\t\tItem removed successfully!" << endl;
        cls();
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid shop number. No shop removed." << endl;
        cls();
        return removeShop(shops, totalShops);
    }
}

// add menu in shop
void addShopMenu(string foodMenuShop[], int foodMenuPricesShop[], int &totalShopItems)
{
    system("cls");
    header();
    if (totalShopItems < maxShop1Items)
    {
        string newItem;
        string newItemPrice;
        bool validPrice = false;
        for (int i = 0; i < totalShopItems; i++)
        {
            cout << "\33[32m"
                 << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << foodMenuShop[i] << " | " << setw(5) << right << foodMenuPricesShop[i] << " Rupees" << endl;
        }
        hideCursor(1);
        cout << "\33[32m"
             << "\t\t\t\t\t\tEnter the name of the new item to add: ";
        getline(cin, newItem);
        if (newItem == "BB")
        {
            return;
        }
        if (empty(newItem) || hasTabs(newItem) || !noCommaItem(newItem))
        {
            return addShopMenu(foodMenuShop, foodMenuPricesShop, totalShopItems);
        }
        cout << "\33[32m"
             << "\t\t\t\t\t\tEnter the price of the new item to add: ";
        getline(cin, newItemPrice);
        hideCursor(0);
        for (int i = 0; i <= 2000; i++)
        {
            if (newItemPrice == to_string(i))
            {
                validPrice = true;
                break;
            }
        }
        if (!validPrice)
        {
            return addShopMenu(foodMenuShop, foodMenuPricesShop, totalShopItems);
        }
        foodMenuShop[totalShopItems] = newItem;
        foodMenuPricesShop[totalShopItems] = stoi(newItemPrice);
        totalShopItems++;
        cout << "\33[33m"
             << "\t\t\t\t\t\tItem added successfully!" << endl;
        cls();
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tMaximum items limit reached. Cannot add more items." << endl;
        return addShopMenu(foodMenuShop, foodMenuPricesShop, totalShopItems);
    }
}

// remove menu in shop
void removeShopMenu(string foodMenuShop[], int foodMenuPricesShop[], int &totalShopItems)
{
    system("cls");
    header();
    string index;
    for (int i = 0; i < totalShopItems; i++)
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\t" << setw(3) << i + 1 << "). " << setw(23) << left << foodMenuShop[i] << " | " << setw(5) << right << foodMenuPricesShop[i] << " Rupees" << endl;
    }
    hideCursor(1);
    cout << "\33[32m"
         << "\t\t\t\t\t\tEnter the number of the item to remove: ";
    getline(cin, index);
    hideCursor(0);
    if (index == "BB")
    {
        return;
    }
    bool isValid = false;
    // validation
    for (int i = 1; i <= totalShopItems; i++)
    {
        if (index == to_string(i))
        {
            isValid = true;
            break;
        }
    }

    if (isValid)
    {
        for (int i = stoi(index) - 1; i < totalShopItems - 1; i++)
        {
            foodMenuShop[i] = foodMenuShop[i + 1];
            foodMenuPricesShop[i] = foodMenuPricesShop[i + 1];
        }
        totalShopItems--;
        cout << "\33[33m"
             << "\t\t\t\t\t\tItem removed successfully!" << endl;
        cls();
        //  return input;
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid item number. No item removed.\n";
        cls();
        return removeShopMenu(foodMenuShop, foodMenuPricesShop, totalShopItems);
    }
}

// enter shop to handle
string shopToHandle(string shops[], int totalShops)
{
    string input;
    for (int i = 0; i < totalShops; i++)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << shops[i] << endl;
    }
    hideCursor(1);
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter a shop whose menu you want to change (1 to " << totalShops << ") Except 3 to 6: ";
    getline(cin, input);
    hideCursor(0);
    if (input == "BB")
    {
        return input;
    }
    bool isValid = false;
    if (input == "1" || input == "2" || input == "7" || input == "8" || input == "9" || input == "10" || input == "11" || input == "12")
    {
        return input;
    }

    else
    {
        cls();
        header();
        return shopToHandle(shops, totalShops);
    }
}

// manageshop1 menu
void manageShopMenu(string foodMenuShop[], int foodMenuPricesShop[], int &totalShopItems)
{
    bool isUpdated = false;
    cout << "\33[33m"
         << "\t\t\t\t\t\tMENU LIST " << endl;
    for (int i = 0; i < totalShopItems; i++)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << foodMenuShop[i] << endl;
    }
    string action;
    hideCursor(1);
    cout << "\33[32m"
         << "\t\t\t\t\t\tDo you want to add (a) or remove (r) a item? ";
    getline(cin, action);
    hideCursor(0);
    if (action == "BB")
    {
        return;
    }
    else if (action == "a")
    {
        addShopMenu(foodMenuShop, foodMenuPricesShop, totalShopItems);
        isUpdated = true;
    }
    else if (action == "r")
    {
        removeShopMenu(foodMenuShop, foodMenuPricesShop, totalShopItems);
        isUpdated = true;
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid action. Enter either a or r." << endl;
        cls();
        header();
        return manageShopMenu(foodMenuShop, foodMenuPricesShop, totalShopItems); // Recursive call for invalid input
    }

    if (isUpdated)
    {
        system("cls");
        header();
        cout << "\33[33m"
             << "\t\t\t\t\t\tUpdated Shop List: " << endl;
        for (int i = 0; i < totalShopItems; i++)
        {
            cout << "\33[33m"
                 << "\t\t\t\t\t\t" << i + 1 << ". " << foodMenuShop[i] << endl;
        }
        cls();
    }
}

// manage drinks menu
void manageDrinksMenu(string drinks[], int drinksPrices[], int &totalDrinks)
{
    bool isUpdated = false;
    cout << "\33[33m"
         << "\t\t\t\t\t\t Drinks List " << endl;
    for (int i = 0; i < totalDrinks; i++)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << drinks[i] << endl;
    }
    string action;
    hideCursor(1);
    cout << "\33[32m"
         << "\t\t\t\t\t\tDo you want to add (a) or remove (r) a drink? ";
    getline(cin, action);
    hideCursor(0);
    if (action == "BB")
    {
        return;
    }
    else if (action == "a")
    {
        addDrinksMenu(drinks, drinksPrices, totalDrinks);
        isUpdated = true;
    }
    else if (action == "r")
    {
        removeDrinksMenu(drinks, drinksPrices, totalDrinks);
        isUpdated = true;
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid action. Enter either a or r." << endl;
        cls();
        header();
        return manageDrinksMenu(drinks, drinksPrices, totalDrinks); // Recursive call for invalid input
    }

    if (isUpdated)
    {
        system("cls");
        header();
        cout << "\33[33m"
             << "\t\t\t\t\t\tUpdated Drink List: " << endl;
        for (int i = 0; i < totalDrinks; i++)
        {
            cout << "\33[33m"
                 << "\t\t\t\t\t\t" << i + 1 << ". " << drinks[i] << endl;
        }
        cls();
    }
}

// add new drinks
void addDrinksMenu(string drinks[], int drinksPrices[], int &totalDrinks)
{
    system("cls");
    header();
    if (totalDrinks < maxDrinks)
    {
        for (int i = 0; i < totalDrinks; i++)
        {
            cout << "\33[33m"
                 << "\t\t\t\t\t\t" << i + 1 << ". " << drinks[i] << endl;
        }
        string newItem;
        string newItemPrice;
        bool validPrice = false;
        hideCursor(1);
        cout << "\33[32m"
             << "\t\t\t\t\t\tEnter the name of the new drink to add: ";
        getline(cin, newItem);
        if (empty(newItem) || hasTabs(newItem) || !noCommaItem(newItem))
        {
            return addDrinksMenu(drinks, drinksPrices, totalDrinks);
        }
        cout << "\33[32m"
             << "\t\t\t\t\t\tEnter the price of the new drink to add: ";
        getline(cin, newItemPrice);
        hideCursor(0);
        for (int i = 0; i <= 2000; i++)
        {
            if (newItemPrice == to_string(i))
            {
                validPrice = true;
                break;
            }
        }
        if (!validPrice)
        {
            return addDrinksMenu(drinks, drinksPrices, totalDrinks);
        }
        drinks[totalDrinks] = newItem;
        drinksPrices[totalDrinks] = stoi(newItemPrice);
        totalDrinks++;
        cout << "\33[33m"
             << "\t\t\t\t\t\tDrink added successfully!" << endl;
        cls();
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tMaximum drinks limit reached. Cannot add more drinks." << endl;
        cls();
        return;
    }
}

// removing drinks
void removeDrinksMenu(string drinks[], int drinksPrices[], int &totalDrinks)
{
    system("cls");
    header();
    string index;
    for (int i = 0; i < totalDrinks; i++)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << drinks[i] << endl;
    }
    cout << "\33[32m"
         << "\t\t\t\t\t\tEnter the number of the drink to remove: ";
    getline(cin, index);
    if (index == "BB")
    {
        return;
    }
    bool isValid = false;
    // validation
    for (int i = 1; i <= totalDrinks; i++)
    {
        if (index == to_string(i))
        {
            isValid = true;
            break;
        }
    }

    if (isValid)
    {
        for (int i = stoi(index) - 1; i < totalDrinks - 1; i++)
        {
            drinks[i] = drinks[i + 1];
            drinksPrices[i] = drinksPrices[i + 1];
        }
        totalDrinks--;
        cout << "\33[33m"
             << "\t\t\t\t\t\tDrink removed successfully!" << endl;
        cls();
        //  return input;
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid item number. No item removed.\n";
        cls();
        return;
    }
}

// managing employees
void employeeManager(string employees[], int &totalEmployees)
{
    bool isUpdated = false;
    cout << "\33[33m"
         << "\t\t\t\t\t\tEMPLOYEE LIST" << endl;
    for (int i = 0; i < totalEmployees; ++i)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << employees[i] << endl;
    }

    string action;
    hideCursor(1);
    cout << "\33[32m"
         << "\t\t\t\t\t\tDo you want to add (a) or remove (r) an employee? ";
    getline(cin, action);
    hideCursor(0);
    if (action == "BB")
    {
        return;
    }
    else if (action == "a")
    {
        addEmployee(employees, totalEmployees);
        isUpdated = true;
    }
    else if (action == "r")
    {
        removeEmployee(employees, totalEmployees);
        isUpdated = true;
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid action. Enter either a or r." << endl;
        cls();
        header();
        return employeeManager(employees, totalEmployees);
    }

    if (isUpdated)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\tUpdated Employee List: " << endl;
        system("cls");
        header();
        for (int i = 0; i < totalEmployees; i++)
        {
            cout << "\33[33m"
                 << "\t\t\t\t\t\t" << i + 1 << ". " << employees[i] << endl;
        }
        cls();
    }
}

// adding new employee
void addEmployee(string employees[], int &totalEmployees)
{
    system("cls");
    header();
    if (totalEmployees < maxEmployees)
    {
        string newEmployee;
        cout << "\33[33m"
             << "\t\t\t\t\t\tEMPLOYEE LIST" << endl;
        for (int i = 0; i < totalEmployees; ++i)
        {
            cout << "\33[33m"
                 << "\t\t\t\t\t\t" << i + 1 << ". " << employees[i] << endl;
        }
        hideCursor(1);
        cout << "\33[32m"
             << "\t\t\t\t\t\tEnter the name of the employee to add: ";
        getline(cin, newEmployee);
        if (empty(newEmployee) || hasTabs(newEmployee) || !noCommaItem(newEmployee))
        {
            return addEmployee(employees, totalEmployees);
        }
        hideCursor(0);
        employees[totalEmployees] = newEmployee;
        totalEmployees++;
        cout << "\33[33m"
             << "\t\t\t\t\t\tEmployee added successfully!" << endl;
        cls();
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tEmployee limit reached. Cannot add more employees." << endl;
        cls();
        return;
    }
}

// rewmoving employee
void removeEmployee(string employees[], int &totalEmployees)
{
    system("cls");
    header();
    string index;
    cout << "\33[33m"
         << "\t\t\t\t\t\tEMPLOYEE LIST" << endl;
    for (int i = 0; i < totalEmployees; ++i)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << employees[i] << endl;
    }
    hideCursor(1);
    cout << "\33[32m"
         << "\t\t\t\t\t\tEnter the number of the employee to remove: ";
    getline(cin, index);
    hideCursor(0);
    bool isValid = false;
    for (int i = 1; i <= totalEmployees; i++)
    {
        if (index == to_string(i))
        {
            isValid = true;
            break;
        }
    }
    if (isValid)
    {
        for (int i = stoi(index) - 1; i < totalEmployees - 1; i++)
        {
            employees[i] = employees[i + 1];
        }
        totalEmployees--;
        cout << "\33[33m"
             << "\t\t\t\t\t\tEmployee removed successfully!" << endl;
        cls();
        //  return input;
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid employee number. No employee removed.\n";
        cls();
        return removeEmployee(employees, totalEmployees);
    }
}

// selecting sub option for admin opt 2
int selectFromAdminOption2()
{
    string in;
    cout << "\33[32m"
         << "\t\t\t\t\t\tView Data\n"
         << "\33[0m";
    cout << "\33[33m"
         << "\t\t\t\t\t\t1. For Employee\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t2. For Chefs\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t3. For Delivery boys\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t4. For Helpline boys\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t5. For Customer Service\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t6. For Accountants\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t7. For Customers\n";
    cout << "\33[32m"
         << "\t\t\t\t\t\t8. Go Back";
    int input = movementOfArrow(45, 18, 1, 8);
    return input;
}

// view users data by admin
void viewUsersData(string usernames[], string passwords[], int totalUsers, string ages[], string genders[], string phoneNumbers[], string addresses[])
{
    cout << "\33[33m"
         << "\t\t\t\t\t\tUsers Data:" << endl;
    for (int i = 0; i < totalUsers; i++)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\t" << i + 1 << ". Username: " << usernames[i] << "\n\t\t\t\t\t\t   Password: " << passwords[i] << "\n\t\t\t\t\t\t   Address: " << addresses[i] << "\n\t\t\t\t\t\t   Phone Number: " << phoneNumbers[i] << "\n\t\t\t\t\t\t   Gender: " << genders[i] << "\n\t\t\t\t\t\t   Age: " << ages[i] << endl;
    }
    cls();
}

// view emp data by admin
void viewEmployeesData(string EmployeeUsernames[], string EmployeePasswords[], int totalEmployees, string EmployeeAges[], string EmployeeGenders[], string EmployeePhoneNumbers[])
{
    cout << "\33[33m"
         << "\t\t\t\t\t\tUsernames & Passwords:" << endl;
    for (int i = 0; i < totalEmployees; i++)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\t" << i + 1 << ". Username: " << EmployeeUsernames[i] << "\n\t\t\t\t\t\t   Password: " << EmployeePasswords[i] << "\n\t\t\t\t\t\t   Phone Number: " << EmployeePhoneNumbers[i] << "\n\t\t\t\t\t\t   Gender: " << EmployeeGenders[i] << "\n\t\t\t\t\t\t   Age: " << EmployeeAges[i] << endl;
    }

    cls();
}

// select admin opt 3 sub options
int selectFromAdminOption3()
{
    cout << "\33[33m"
         << "\t\t\t\t\t\tDelete Data\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t1. For Employee\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t2. For Chefs\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t3. For Delivery boys\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t4. For Helpline boys\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t5. For Customer Service\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t6. For Accountants\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t7. For Customers\n";
    cout << "\33[33m"
         << "\t\t\t\t\t\t8. Go Back ";
    int input = movementOfArrow(45, 18, 1, 8);
    return input;
}

// remove user
void removeUser(string usernames[], string passwords[], string ages[], string genders[], string phoneNumbers[], int &totalUsers) // admin functionality
{
    string index;
    cout << "\33[33m"
         << "\t\t\t\t\t\tUSER LIST" << endl;
    for (int i = 0; i < totalUsers; ++i)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << usernames[i] << endl;
    }
    cout << "\33[32m"
         << "\t\t\t\t\t\tEnter the number of the user to remove: ";
    hideCursor(1);
    getline(cin, index);
    hideCursor(0);
    if (index == "BB")
    {
        return;
    }
    bool isValid = false;
    for (int i = 1; i <= totalUsers; i++)
    {
        if (index == to_string(i))
        {
            isValid = true;
            break;
        }
    }
    if (isValid)
    {
        for (int i = stoi(index) - 1; i < totalUsers - 1; i++)
        {
            usernames[i] = usernames[i + 1];
            passwords[i] = passwords[i + 1];
            ages[i] = ages[i + 1];
            phoneNumbers[i] = phoneNumbers[i + 1];
            genders[i] = genders[i + 1];
        }
        totalUsers--;
        cout << "\33[33m"
             << "\t\t\t\t\t\tUser removed successfully!" << endl;
        cls();
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid User number. No user removed.\n";
        cls();
        header();
        return removeUser(usernames, passwords, ages, genders, phoneNumbers, totalUsers);
    }
}

// managaing users accounts
void usersManager(string usernames[], string passwords[], string ages[], string genders[], string phoneNumbers[], int &totalUsers) // admin Functionality to del user login info
{
    bool isUpdated = false;
    cout << "\33[33m"
         << "\t\t\t\t\t\tEMPLOYEE LIST" << endl;
    for (int i = 0; i < totalUsers; ++i)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << usernames[i] << endl;
    }
    cls();
    header();
    removeUser(usernames, passwords, ages, genders, phoneNumbers, totalUsers);
    cout << "\33[33m"
         << "\t\t\t\t\t\tUpdated Users List: " << endl;
    system("cls");
    header();
    for (int i = 0; i < totalUsers; i++)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << usernames[i] << endl;
    }
    cls();
}

// removing ssc workers employees
void removeEmployeeAccount(string employeeUsernames[], string employeePasswords[], string employeeAges[], string employeeGenders[], string employeePhoneNumbers[], int &totalEmployees) // admin functionality
{
    string index;
    cout << "\33[33m"
         << "\t\t\t\t\t\tEmployee LIST" << endl;
    for (int i = 0; i < totalEmployees; ++i)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << employeeUsernames[i] << endl;
    }
    cout << "\33[32m"
         << "\t\t\t\t\t\tEnter the number of the employee whose account you want to delete: ";
    hideCursor(1);
    getline(cin, index);
    hideCursor(0);
    if (index == "BB")
    {
        return;
    }
    bool isValid = false;
    for (int i = 1; i <= totalEmployees; i++)
    {
        if (index == to_string(i))
        {
            isValid = true;
            break;
        }
    }
    if (isValid)
    {
        for (int i = stoi(index) - 1; i < totalEmployees - 1; i++)
        {
            employeeUsernames[i] = employeeUsernames[i + 1];
            employeePasswords[i] = employeePasswords[i + 1];
            employeeAges[i] = employeeAges[i + 1];
            employeePhoneNumbers[i] = employeePhoneNumbers[i + 1];
            employeeGenders[i] = employeeGenders[i + 1];
        }
        totalEmployees--;
        cout << "\33[33m"
             << "\t\t\t\t\t\tEmployee removed successfully!" << endl;
        cls();
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid Employee number. No Employees account removed.\n";
        cls();
        header();
        return removeEmployeeAccount(employeeUsernames, employeePasswords, employeeAges, employeeGenders, employeePhoneNumbers, totalEmployees);
    }
}

// change admin username
void changeAdminUsername(string adminUsernames[], int totalAdmins, string adminUserName) //  new
{
    system("cls");
    loginPageHeader();
    string newUsername, checkNewUsername;
    cout << "\33[32m"
         << "\t\t\t\t\t\tEnter a new Username: ";
    hideCursor(1);
    getline(cin, newUsername);
    hideCursor(0);
    if (newUsername == "BB")
    {
        return;
    }
    if (empty(newUsername) || !noComma(newUsername) || hasTabs(newUsername))
    {
        cls();
        return changeAdminUsername(adminUsernames, totalAdmins, adminUserName);
    }
    if ((newUsername.length() >= 6) && (newUsername.length() <= 10))
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\tEnter the new Username again: ";
        hideCursor(1);
        getline(cin, checkNewUsername);
        hideCursor(0);
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tUsername is invalid. Please try again." << endl;
        cls();
        return changeAdminUsername(adminUsernames, totalAdmins, adminUserName);
    }

    if (newUsername != checkNewUsername)
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tUsernames do not match. Please try again." << endl;
        cls();
        return changeAdminUsername(adminUsernames, totalAdmins, adminUserName);
    }

    for (int i = 0; i < totalAdmins; ++i)
    {
        if (adminUsernames[i] == adminUserName)
        {
            adminUsernames[i] = newUsername;
            cout << "\33[33m"
                 << "\t\t\t\t\t\tUsername changed successfully for user from " << adminUserName << " to " << newUsername << endl;
            cls();
        }
    }
}

// notify users
void notifyUsers(string notification[], int &totalNotifications) // admin functionality tba
{
    string message;
    cout << "\33[33m"
         << "\t\t\t\t\t\tWrite a notification: ";
    hideCursor(1);
    getline(cin, message);
    hideCursor(0);
    if (message == "BB" || empty(message) || hasTabs(message))
    {
        return;
    }
    if (totalNotifications < maxNotifications)
    {
        notification[totalNotifications++] = message;
        cls();
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tMaximum limit reached for suggestions. Unable to submit more." << endl;
        cls();
        header();
    }
}

// adding new rules
void addRules(string rules[], int &currentRules) // admin functionality
{
    string addMore;
    string newRule;
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter the new rule: ";
    hideCursor(1);
    getline(cin, newRule);
    hideCursor(0);
    if (newRule == "BB")
    {
        return;
    }
    if (currentRules < maxRules)
    {
        rules[currentRules] = newRule;
        currentRules++;
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tMaximum number of rules reached." << endl;
    }

    cout << "\33[33m"
         << "\n\t\t\t\t\t\tUpdated Rules:\n";
    displayRules(rules, currentRules);
}

// change password for admin
void changePasswordAdmin(string adminUsernames[], string adminPasswords[], int totalAdmins, string adminUsername, string adminPassword)
{
    string adminNewPassword, adminCheckNewPassword;
    system("cls");
    loginPageHeader();
    cout << "\33[32m"
         << "\t\t\t\t\t\tEnter a new password: ";
    hideCursor(1);
    getline(cin, adminNewPassword);
    hideCursor(0);
    if (adminNewPassword == "BB")
    {
        return;
    }
    if (empty(adminNewPassword) || !noComma(adminNewPassword) || hasTabs(adminNewPassword))
    {
        cls();
        return changePasswordAdmin(adminUsernames, adminPasswords, totalAdmins, adminUsername, adminPassword);
    }
    if (!validPassword(adminNewPassword))
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tPassword is invalid. Please try again." << endl;
        cls();
        return changePasswordAdmin(adminUsernames, adminPasswords, totalAdmins, adminUsername, adminPassword);
    }

    cout << "\33[32m"
         << "\t\t\t\t\t\tEnter the new password again: ";
    hideCursor(1);
    getline(cin, adminCheckNewPassword);
    hideCursor(0);

    if (adminNewPassword != adminCheckNewPassword)
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tPasswords do not match. Please try again." << endl;
        cls();
        return changePasswordAdmin(adminUsernames, adminPasswords, totalAdmins, adminUsername, adminPassword);
    }

    for (int i = 0; i < totalAdmins; ++i)
    {
        if (adminUsernames[i] == adminUsername)
        {
            adminPasswords[i] = adminNewPassword;
            cout << "\33[33m"
                 << "\t\t\t\t\t\tPassword changed successfully for user: " << adminUsername << endl;
            cls();
        }
    }
}

// delete admin
void deleteAdmin(string adminUsernames[], string adminPasswords[], int &totalAdmins, string currentUser) // admin functionality
{
    int index = -1;
    for (int i = 0; i < totalAdmins; ++i)
    {
        if (adminUsernames[i] == currentUser)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < totalAdmins - 1; ++i)
        {
            adminUsernames[i] = adminUsernames[i + 1];
            adminPasswords[i] = adminPasswords[i + 1];
        }
        totalAdmins--;
        cout << "\33[33m"
             << "\t\t\t\t\t\tAdmnin " << currentUser << " removed successfully!" << endl;
        cls();
    }
    else
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\tAdmin not found or unable to delete account." << endl;
        cls();
        header();
    }
}

// adding new admin
void addAdmin(string adminUsernames[], string adminPasswords[], int &totalAdmins)
{
    string newUsername, newPassword;
    if (totalAdmins <= maxAdmins)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\tEnter new Admins Username: ";
        hideCursor(1);
        getline(cin, newUsername);
        hideCursor(0);
        if (newUsername == "BB")
        {
            return;
        }
        if (newUsername.length() < 6 && newUsername.length() > 10 || empty(newUsername) || hasTabs(newUsername) || !noCommaItem(newUsername))
        {
            cout << "\33[31m"
                 << "\t\t\t\t\t\tInvalid username" << endl;
            cls();
            return;
        }
        hideCursor(1);
        cout << "\33[33m"
             << "\t\t\t\t\t\tEnter new Admins Password: ";
        getline(cin, newPassword);
        hideCursor(0);
        if (newPassword.length() <= 8 && newPassword.length() > 12 || empty(newUsername) || hasTabs(newUsername) || !noCommaItem(newUsername))
        {
            cout << "\33[31m"
                 << "\t\t\t\t\t\tInvalid username" << endl;
            cls();
            return;
        }
        adminUsernames[totalAdmins] = newUsername;
        adminPasswords[totalAdmins] = newPassword;
        totalAdmins++;
        cout << "\33[33m"
             << "\t\t\t\t\t\tAdmin " << newUsername << " added successfully!" << endl;
        cls();
        header();
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tMaximum admin capacity reached. Unable to add new admin." << endl;
        cls();
        header();
    }
}

// chef menu
int chefMenu()
{
    cout << "\33[36m"
         << "\t\t\t\t\t\t1. View Shops\n"
         << "\t\t\t\t\t\t2. Leave a Suggestion for Customer Care\n"
         << "\t\t\t\t\t\t3. View Customer reviews about food\n"
         << "\t\t\t\t\t\t4. View Account Balance\n"
         << "\t\t\t\t\t\t5. Change Password\n"
         << "\t\t\t\t\t\t6. Log Out\n"
         << "\t\t\t\t\t\t7. Exit\n";
    int input = movementOfArrow(45, 17, 1, 7);
    return input;
}

// chf selects shop
string chefSelectShop(string shops[], int totalShops)
{
    string input;
    bool isSuccessful = false;

    for (int i = 0; i < totalShops; i++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << shops[i] << endl;
    }

    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter a shop of which you are employed of (1,2 and 7 to " << totalShops << "): ";
    hideCursor(1);
    getline(cin, input);
    hideCursor(0);
    if (input == "BB")
    {
        return input;
    }

    bool isValid = false;
    for (int i = 1; i <= totalShops; i++)
    {
        if (input == to_string(i))
        {
            isValid = true;
            break;
        }
    }

    if (isValid)
    {
        return input;
    }
    else
    {
        cout << "\33[31m";
        cout << "\t\t\t\t\t\tInvalid shop selection. Please choose a valid shop.\n";
        cout << "\33[0m";
        cls();
        header();
        return chefSelectShop(shops, totalShops);
    }
}

// making multiple functions so different chefs can access differents orders at same times
// view orders of shop1
void viewOrdersShop1(string orderedItems1[], int orderedItemsQuantity1[])
{
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity1[index] << " of " << orderedItems1[index] << endl;
    }
}

// view orders of shop2
void viewOrdersShop2(string orderedItems2[], int orderedItemsQuantity2[])
{
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity2[index] << " of " << orderedItems2[index] << endl;
    }
}

// view orders of shop7
void viewOrdersShop7(string orderedItems7[], int orderedItemsQuantity7[])
{
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity7[index] << " of " << orderedItems7[index] << endl;
    }
}

// view orders of shop8
void viewOrdersShop8(string orderedItems8[], int orderedItemsQuantity8[])
{
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity8[index] << " of " << orderedItems8[index] << endl;
    }
}

// view orders of shop9
void viewOrdersShop9(string orderedItems9[], int orderedItemsQuantity9[])
{
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity9[index] << " of " << orderedItems9[index] << endl;
    }
}

// view orders of shop10
void viewOrdersShop10(string orderedItems10[], int orderedItemsQuantity10[])
{
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity10[index] << " of " << orderedItems10[index] << endl;
    }
}

// view orders of shop11
void viewOrdersShop11(string orderedItems11[], int orderedItemsQuantity11[])
{
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity11[index] << " of " << orderedItems11[index] << endl;
    }
}

// view orders of shop12
void viewOrdersShop12(string orderedItems12[], int orderedItemsQuantity12[])
{
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity12[index] << " of " << orderedItems12[index] << endl;
    }
}

// invalid shop here means that enetered shop doesnt support this format
void invalidShop()
{
    cout << "\33[31m"
         << "\t\t\t\t\t\tThis shop does not require Chefs. Choose your own valid shop.\n";
}

void invalidShopDelivery()
{
    cout << "\33[31m"
         << "\t\t\t\t\t\tThis shop does not require Delivery Boys. Choose your own valid shop.\n";
}

// view reviews by chef submitted by customer
void viewReviewsByChef(string userReviewsForChef[], int &totalReviewsForChef)
{
    cout << "\33[36m"
         << "\t\t\t\t\t\tFeedbacks:" << endl;
    for (int i = 0; i < totalReviewsForChef; ++i)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << userReviewsForChef[i] << endl;
    }
    cls();
}

// view chef balance
void ChefBalance(string Chefs[], int ChefSalaries[], int index)
{
    // Within ChefBalance function
    cout << "Index: " << index << endl;
    cout << "\33[36m"
         << "\t\t\t\t\t\t" << Chefs[index] << " Balance is " << ChefSalaries[index] << endl;
    cls();
}

// validation for unique employee
bool isUniqueEmployee(string EmployeeUsernames[], int totalEmployees, string newEmployee)
{
    bool isUnique = true;
    for (int i = 0; i < totalEmployees; ++i)
    {
        if (EmployeeUsernames[i] == newEmployee)
        {
            cout << "\33[31m"
                 << "\t\t\t\t\t\tUsername already exists. Please try a different username." << endl;
            isUnique = false;
            if (!isUnique)
            {
                return false;
            }
        }
    }
    return true;
}

// validation for existing employee
bool isExistingEmployee(string EmployeeUsernames[], string EmployeePasswords[], int totalEmployees, string EmployeeUsername, string EmployeePassword)
{
    for (int i = 0; i < totalEmployees; ++i)
    {
        if (EmployeeUsernames[i] == EmployeeUsername && EmployeePasswords[i] == EmployeePassword)
        {
            return true;
        }
    }
    return false;
}

// validation for existing menu
int EmployeeMenu()
{
    cout << "\33[35m"
         << "\t\t\t\t\t\t1. View Shops\n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t2. View Booked Tables\n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t3. Leave a Suggestion for Customer Care\n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t4. Change Password\n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t5. View account balance\n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t6. Log Out\n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t7. Exit\n";
    int input = movementOfArrow(45, 17, 1, 7);
    return input;
}

void displayShopsEmployee(string shops[], int totalShops)
{
    string input;
    bool isSuccesfull = false;
    for (int i = 0; i < totalShops; i++) // displays all shops
    {
        cout << "\33[35m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << shops[i] << endl;
    }
    cls();
}

// view booked and unbooked tables
void viewAllTablesStatus(const bool bookedTables[])
{
    cout << "\33[35m"
         << "\t\t\t\t\t\tTable Status:" << endl;
    for (int i = 0; i < 30; ++i)
    {
        cout << "\33[35m"
             << "\t\t\t\t\t\tTable " << i + 1 << ": " << (bookedTables[i] ? "Booked" : "Not Booked") << endl;
    }
    cls();
}

// take suggestion for employee
void takeEmployeeSuggestion(string EmployeeSuggestions[], int &totalEmployeeSuggestions)
{
    string EmployeeInput;
    cout << "\33[35m"
         << "\t\t\t\t\t\tEnter a suggestion: ";
    hideCursor(1);
    getline(cin, EmployeeInput);
    hideCursor(0);
    if (empty(EmployeeInput) || hasTabs(EmployeeInput))
    {
        return;
    }
    if (EmployeeInput == "BB")
    {
        return;
    }
    if (totalEmployeeSuggestions < maxEmployeeSuggestions)
    {
        EmployeeSuggestions[totalEmployeeSuggestions++] = EmployeeInput;
        cls();
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tMaximum limit reached for suggestions. Unable to submit more." << endl;
        cls();
        header();
    }
}

// change password
void changePasswordEmployee(string EmployeeUsernames[], string EmployeePasswords[], int totalEmployees, string EmployeeUsername, string EmployeePassword)
{
    string EmployeeNewPassword, EmployeeCheckNewPassword;
    cout << "\33[32m"
         << "\t\t\t\t\t\tEnter a new password: ";
    hideCursor(1);
    getline(cin, EmployeeNewPassword);
    hideCursor(0);
    if (EmployeeNewPassword == "BB")
    {
        return;
    }
    if (!validPassword(EmployeeNewPassword))
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tPassword is invalid. Please try again." << endl;
        cls();
        loginPageHeader();
        return changePasswordEmployee(EmployeeUsernames, EmployeePasswords, totalEmployees, EmployeeUsername, EmployeePassword);
    }

    cout << "\33[32m"
         << "\t\t\t\t\t\tEnter the new password again: ";
    hideCursor(1);
    getline(cin, EmployeeCheckNewPassword);
    hideCursor(0);

    if (EmployeeNewPassword != EmployeeCheckNewPassword)
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tPasswords do not match. Please try again." << endl;
        cls();
        loginPageHeader();
        return changePasswordEmployee(EmployeeUsernames, EmployeePasswords, totalEmployees, EmployeeUsername, EmployeePassword);
    }

    for (int i = 0; i < totalEmployees; ++i)
    {
        if (EmployeeUsernames[i] == EmployeeUsername)
        {
            EmployeePasswords[i] = EmployeeNewPassword;
            cout << "\33[35m"
                 << "\t\t\t\t\t\tPassword changed successfully for user: " << EmployeeUsername << endl;
            cls();
        }
    }
}

// emplyee checking his balance
void EmployeeBalance(string Employees[], int EmployeeSalaries[], int index)
{
    cout << "\33[35m"
         << "\t\t\t\t\t\t" << Employees[index] << " Balance is " << EmployeeSalaries[index] << endl;
    cls();
}

// delievry boy menu
int DeliveryBoyMenu()
{
    cout << "\33[32m"
         << "\t\t\t\t\t\t1. View Orders\n";
    cout << "\33[32m"
         << "\t\t\t\t\t\t2. Leave a Suggestion for Customer Care\n";
    cout << "\33[32m"
         << "\t\t\t\t\t\t3. View Accounts Balance\n";
    cout << "\33[32m"
         << "\t\t\t\t\t\t4. Change Password\n";
    cout << "\33[32m"
         << "\t\t\t\t\t\t5. Log Out\n";
    cout << "\33[32m"
         << "\t\t\t\t\t\t6. Exit\n";
    int input = movementOfArrow(45, 17, 1, 6);
    return input;
}

// selling shop for db
string DeliveryBoySelectShop(string shops[], int totalShops)
{
    string input;
    bool isSuccesfull = false;
    for (int i = 0; i < totalShops; i++)
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << shops[i] << endl;
    }
    cout << "\33[32m"
         << "\t\t\t\t\t\t" << totalShops + 1 << ". Drinks order: \n";
    cout << "\33[36m"
         << "\t\t\t\t\t\tEnter a shop of which you are employed of (1,2 and 7 to " << totalShops + 1 << "): ";
    hideCursor(1);
    getline(cin, input);
    hideCursor(0);
    if (input == "BB")
    {
        return input;
    }
    bool isValid = false;
    for (int i = 1; i <= totalShops + 1; i++)
    {
        if (input == to_string(i))
        {
            isValid = true;
            break;
        }
    }

    if (isValid)
    {
        return input;
    }
    else
    {
        cls();
        header();
        return DeliveryBoySelectShop(shops, totalShops);
    }
}

// view orders shop 1
void foodDeliveryShop1(string userIdentity1[], string orderedItems1[], int orderedItemsQuantity1[]) // DeliveryBoy
{
    cout << "\33[32m"
         << "\t\t\t\t\t\tDeleiver Food to: " << userIdentity1[0] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tPhone Number: " << userIdentity1[1] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tAddress: " << userIdentity1[2] << endl;
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity1[index] << " of " << orderedItems1[index] << endl;
    }
}

// view orders shop 2
void foodDeliveryShop2(string userIdentity2[], string orderedItems2[], int orderedItemsQuantity2[]) // DeliveryBoy
{
    cout << "\33[32m"
         << "\t\t\t\t\t\tDeleiver Food to: " << userIdentity2[0] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tPhone Number: " << userIdentity2[1] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tAddress: " << userIdentity2[2] << endl;
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity2[index] << " of " << orderedItems2[index] << endl;
    }
}

// view orders shop 7
void foodDeliveryShop7(string userIdentity7[], string orderedItems7[], int orderedItemsQuantity7[]) // DeliveryBoy
{
    cout << "\33[32m"
         << "\t\t\t\t\t\tDeleiver Food to: " << userIdentity7[0] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tPhone Number: " << userIdentity7[1] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tAddress: " << userIdentity7[2] << endl;
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity7[index] << " of " << orderedItems7[index] << endl;
    }
}

// view orders shop 8
void foodDeliveryShop8(string userIdentity8[], string orderedItems8[], int orderedItemsQuantity8[]) // DeliveryBoy
{
    cout << "\33[32m"
         << "\t\t\t\t\t\tDeleiver Food to: " << userIdentity8[0] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tPhone Number: " << userIdentity8[1] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tAddress: " << userIdentity8[2] << endl;
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity8[index] << " of " << orderedItems8[index] << endl;
    }
}

// view orders shop 9
void foodDeliveryShop9(string userIdentity9[], string orderedItems9[], int orderedItemsQuantity9[]) // DeliveryBoy
{
    cout << "\33[32m"
         << "\t\t\t\t\t\tDeleiver Food to: " << userIdentity9[0] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tPhone Number: " << userIdentity9[1] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tAddress: " << userIdentity9[2] << endl;
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity9[index] << " of " << orderedItems9[index] << endl;
    }
}

// view drinks order
void drinksDelivery(string userIdentity9[], string orderedDrinks[], int orderedDrinksQuantity[]) // DeliveryBoy
{
    cout << "\33[32m"
         << "\t\t\t\t\t\tDeleiver Food to: " << userIdentity9[0] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tPhone Number: " << userIdentity9[1] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tAddress: " << userIdentity9[2] << endl;
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedDrinksQuantity[index] << " of " << orderedDrinks[index] << endl;
    }
}

// view orders shop 10
void foodDeliveryShop10(string userIdentity10[], string orderedItems10[], int orderedItemsQuantity10[]) // DeliveryBoy
{
    cout << "\33[32m"
         << "\t\t\t\t\t\tDeleiver Food to: " << userIdentity10[0] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tPhone Number: " << userIdentity10[1] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tAddress: " << userIdentity10[2] << endl;
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity10[index] << " of " << orderedItems10[index] << endl;
    }
}

// view orders shop 11
void foodDeliveryShop11(string userIdentity11[], string orderedItems11[], int orderedItemsQuantity11[]) // DeliveryBoy
{
    cout << "\33[32m"
         << "\t\t\t\t\t\tDeleiver Food to: " << userIdentity11[0] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tPhone Number: " << userIdentity11[1] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tAddress: " << userIdentity11[2] << endl;
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity11[index] << " of " << orderedItems11[index] << endl;
    }
}

// view orders shop 12
void foodDeliveryShop12(string userIdentity12[], string orderedItems12[], int orderedItemsQuantity12[]) // DeliveryBoy
{
    cout << "\33[32m"
         << "\t\t\t\t\t\tDeleiver Food to: " << userIdentity12[0] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tPhone Number: " << userIdentity12[1] << endl;
    cout << "\33[32m"
         << "\t\t\t\t\t\tAddress: " << userIdentity12[2] << endl;
    for (int index = 0; index < orderNum + 1; index++)
    {
        cout << "\33[36m"
             << "\t\t\t\t\t\t" << orderedItemsQuantity12[index] << " of " << orderedItems12[index] << endl;
    }
}

// delivery boy balance
void DeliveryBoyBalance(string DeliveryBoys[], int DeliveryBoySalaries[], int index)
{
    cout << "\33[32m"
         << "\t\t\t\t\t\t" << DeliveryBoys[index] << " Balance is " << DeliveryBoySalaries[index] << endl;
    cls();
}

// accountant menu
int AccountantMenu()
{
    cout << "\33[32m"
         << "\t\t\t\t\t\t1. Pay Salary\n";
    cout << "\33[32m"
         << "\t\t\t\t\t\t2. Leave a Suggestion for Customer Care\n";
    cout << "\33[32m"
         << "\t\t\t\t\t\t3. View Account Balance\n";
    cout << "\33[32m"
         << "\t\t\t\t\t\t4. Change Password\n";
    cout << "\33[32m"
         << "\t\t\t\t\t\t5. Log Out\n";
    cout << "\33[32m"
         << "\t\t\t\t\t\t6. Exit\n";
    int input = movementOfArrow(45, 17, 1, 6);
    return input;
}

// pay salary
void paySalary(string employees[], int employeeSalaries[], int totalEmployees, string chefs[], int chefsSalaries[], int totalChefs, string DeliveryBoys[], int DeliveryBoySalaries[], int totalDeliveryBoy, string Accountants[], int AccountantsSalaries[], int totalAccountants, string helplineBoys[], int HelplineBoysSalaries[], int totalHelplineBoys, string CustomerCares[], int CustomerCareSalaries[], int totalCustomerCare)
{
    string accountNumber, input, userType, pay;
    bool isUpdated = false, isValid = false, isTrue = false;

    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter the type of user (Employee/Chef/DeliveryBoy/Accountant/HelplineBoy/CustomerCare): ";
    hideCursor(1);
    getline(cin, userType);
    hideCursor(0);
    if (userType == "BB")
    {
        return;
    }
    else if (userType == "Employee")
    {
        totalEmployees = totalEmployees;
        employees = employees;
        employeeSalaries = employeeSalaries;
    }
    else if (userType == "Chef")
    {
        totalEmployees = totalChefs;
        employees = chefs;
        employeeSalaries = chefsSalaries;
    }
    else if (userType == "DeliveryBoy")
    {
        totalEmployees = totalDeliveryBoy;
        employees = DeliveryBoys;
        employeeSalaries = DeliveryBoySalaries;
    }
    else if (userType == "Accountant")
    {
        totalEmployees = totalAccountants;
        employees = Accountants;
        employeeSalaries = AccountantsSalaries;
    }
    else if (userType == "HelplineBoy")
    {
        totalEmployees = totalHelplineBoys;
        employees = helplineBoys;
        employeeSalaries = HelplineBoysSalaries;
    }
    else if (userType == "CustomerCare")
    {
        totalEmployees = totalCustomerCare;
        employees = CustomerCares;
        employeeSalaries = CustomerCareSalaries;
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid user type entered!" << endl;
        return;
    }

    for (int i = 0; i < totalEmployees; i++)
    {
        cout << "\t\t\t\t\t\t" << i + 1 << ". " << employees[i] << "\n";
    }
    cout << "\33[33m"
         << "\t\t\t\t\t\tEnter the number of the user you want to pay: ";
    hideCursor(1);
    getline(cin, input);
    hideCursor(0);

    for (int i = 1; i <= totalEmployees; i++)
    {
        if (input == to_string(i))
        {
            isValid = true;
            break;
        }
    }

    if (isValid)
    {
        cout << "\33[33m"
             << "\t\t\t\t\t\tEnter the new salary for " << employees[stoi(input) - 1] << ": ";
        hideCursor(1);
        getline(cin, pay);
        hideCursor(0);
        for (int i = 1; i <= 3000; i++)
        {
            if (pay == to_string(i))
            {
                isTrue = true;
                break;
            }
        }
        // Validate the input and update the salary
        if (isTrue)
        {
            int newSalary = stoi(pay);

            employeeSalaries[stoi(input) - 1] = newSalary;
            cout << "\33[32m"
                 << "\t\t\t\t\t\tYou have successfully updated the salary of " << employees[stoi(input) - 1] << endl;
        }
        else
        {
            cout << "\33[31m"
                 << "\t\t\t\t\t\tInvalid salary. Please enter a valid positive number between 1 and 3000." << endl;
        }

        cls();
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid user number. Enter a number between 1 and " << totalEmployees << "." << endl;
        cls();
        header();
    }
}

// view account balance for all employees
int viewAccountBalance(string usernames[], string username, int totalNames)
{
    string checkName;
    bool found = false;
    int index = 0;
    cout << "\33[36m"
         << "\t\t\t\t\t\tEnter your registered name: ";
    hideCursor(1);
    getline(cin, checkName);
    hideCursor(0);
    for (int i = 0; i < totalNames; i++)
    {
        if (usernames[i] == checkName)
        {
            found = true;
            index = i;
            break;
        }
    }
    if (found)
    {
        return index;
    }
    else
    {
        return 234;
        cls();
    }
}

// ACCOUNTANT balance
void AccountantBalance(string Accountants[], int AccountantsSalaries[], int index)
{
    cout << "\33[32m"
         << "\t\t\t\t\t\t" << Accountants[index] << " Balance is " << AccountantsSalaries[index] << endl;
    cls();
}

// helpline boy menu
int HelplineBoyMenu()
{
    cout << "\33[35m"
         << "\t\t\t\t\t\t1. View Inbox \n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t2. Make a Suggestion\n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t3. View Account Balance\n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t4. Change Password\n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t5. Log Out\n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t6. Exit\n";
    int input = movementOfArrow(45, 17, 1, 6);
    return input;
}

// reply to msg that is sent by user
void replyToMessageByHelplineBoy(string messageByHelplineBoy[], int &userNumberByMessage, string usernames[], string userMessages[], string HelplineLineBoyReplies[], int totalMessages, int &totalHelplineBoyMessages, int totalUsers) // change to helpline
{
    string name, option, message;
    bool doesExist = false;
    cout << "\33[32m"
         << "\t\t\t\t\t\tDo you want to send a new message or go to Inbox (1 for New Message and 2 for Inbox): ";
    hideCursor(1);
    getline(cin, option);
    hideCursor(0);
    if (option == "BB")
    {
        return;
    }
    else if (option == "1")
    {
        cout << "\33[32m"
             << "\t\t\t\t\t\tEnter a User's name who you want to message: ";
        hideCursor(1);
        getline(cin, name);
        hideCursor(0);
        for (int i = 0; i < totalUsers; ++i)
        {
            if (usernames[i] == name)
            {
                doesExist = true;
                break;
            }
        }
        if (doesExist)
        {
            cout << "\33[35m"
                 << "\t\t\t\t\t\tWrite a new message to " << name << ": ";
            hideCursor(1);
            getline(cin, message);
            hideCursor(0);
            getCurrentTimestamp();
            if (totalHelplineBoyMessages < maxMessages)
            {
                HelplineLineBoyReplies[totalHelplineBoyMessages++] = message;
                messageByHelplineBoy[userNumberByMessage++] = name;
                cls();
            }
            else
            {
                cout << "\33[31m"
                     << "\t\t\t\t\t\tMaximum limit reached for messages." << endl;
                cls();
                header();
            }
        }
        else
        {
            cout << "\33[31m"
                 << "\t\t\t\t\t\tInvalid Username. Try again." << endl;
            cls();
            header();
            return replyToMessageByHelplineBoy(messageByHelplineBoy, userNumberByMessage, usernames, userMessages, HelplineLineBoyReplies, totalMessages, totalHelplineBoyMessages, totalUsers);
        }
    }
    else if (option == "2")
    {
        if (totalMessages == 0 && totalHelplineBoyMessages == 0)
        {
            cout << "\33[35m"
                 << "\t\t\t\t\t\tInbox is Empty\n";
        }
        if (totalHelplineBoyMessages > 0)
        {
            cout << "\33[35m"
                 << "\t\t\t\t\t\tYour Last message: ";
            cout << "\33[35m"
                 << "\t\t\t\t\t\t" << HelplineLineBoyReplies[totalHelplineBoyMessages - 1];
        }
        for (int i = 0; i < totalMessages; i++)
        {
            cout << "\33[35m"
                 << "\t\t\t\t\t\t" << i + 1 << ". " << userMessages[i] << endl;
        }
        cls();
    }
    else
    {
        cout << "\33[31m"
             << "\t\t\t\t\t\tInvalid Input." << endl;
        cls();
        header();
        return replyToMessageByHelplineBoy(messageByHelplineBoy, userNumberByMessage, usernames, userMessages, HelplineLineBoyReplies, totalMessages, totalHelplineBoyMessages, totalUsers);
    }
}

// helpline boy balance
void HelplineBoyBalance(string HelplineBoys[], int HelplineBoySalaries[], int index)
{
    cout << "\33[35m"
         << "\t\t\t\t\t\t" << HelplineBoys[index] << " Balance is " << HelplineBoySalaries[index] << endl;
    cls();
}

// customer menu
int CustomerCareMenu()
{
    cout << "\33[35m"
         << "\t\t\t\t\t\t1. View Suggestion Box\n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t2. View Complaints of users\n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t3. View Account Balance\n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t4. Change Password\n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t5. Log Out\n";
    cout << "\33[35m"
         << "\t\t\t\t\t\t6. Exit\n";
    int input = movementOfArrow(45, 17, 1, 6);
    return input;
}

// input type
string inputType()
{
    string in;
    cout << "\33[32m"
         << "\t\t\t\t\t\tView Suggestions of (C for Customer,A for Accountant, E for Employees, D for Delivery Boys, H for Helpline Boys, \n\t\t\t\t\t\tCH for Chef): ";
    hideCursor(1);
    getline(cin, in);
    hideCursor(0);
    if (in == "BB")
    {
        return in;
    }
    if (in == "C" || in == "E" || in == "D" || in == "H" || in == "CH" || in == "A")
    {
        return in;
    }
    else
    {
        cls();
        header();
        return inputType();
    }
}

// view helpline boy suggestions by cs
void viewHelplineBoySuggestions(string HelplineBoySuggestions[], int totalHelplineBoySuggestions)
{
    cout << "\33[35m"
         << "\t\t\t\t\t\tHelpline Boy Suggestions:" << endl;
    for (int i = 0; i < totalHelplineBoySuggestions; ++i)
    {
        cout << "\33[35m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << HelplineBoySuggestions[i] << endl;
    }
    cls();
}

// view accountant suggestions by cs
void viewAccountantSuggestions(string AccountantSuggestions[], int totalAccountantSuggestions)
{
    cout << "\33[35m"
         << "\t\t\t\t\t\tAccountant Suggestions:" << endl;
    for (int i = 0; i < totalAccountantSuggestions; ++i)
    {
        cout << "\33[35m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << AccountantSuggestions[i] << endl;
    }
    cls();
}

// view chef suggestions cs
void viewChefSuggestions(string chefSuggestions[], int totalChefSuggestions)
{
    cout << "\33[35m"
         << "\t\t\t\t\t\tChef Suggestions:" << endl;
    for (int i = 0; i < totalChefSuggestions; ++i)
    {
        cout << "\33[35m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << chefSuggestions[i] << endl;
    }
    cls();
}

// view delivery boy suggestions by cs
void viewDeliveryBoySuggestions(string DeliveryBoySuggestions[], int totalDeliveryBoySuggestions)
{
    cout << "\33[35m"
         << "\t\t\t\t\t\tDeliveryBoy Suggestions:" << endl;
    for (int i = 0; i < totalDeliveryBoySuggestions; ++i)
    {
        cout << "\33[35m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << DeliveryBoySuggestions[i] << endl;
    }
    cls();
}

// view user suggestions by cs
void viewSuggestions(string suggestions[], int totalSuggestions)
{
    cout << "\33[35m"
         << "\t\t\t\t\t\tSuggestions:" << endl;
    for (int i = 0; i < totalSuggestions; ++i)
    {
        cout << "\33[35m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << suggestions[i] << endl;
    }
    cls();
}

// view employee suggestions by cs
void viewEmployeeSuggestions(string EmployeeSuggestions[], int totalEmployeeSuggestions)
{
    cout << "\33[35m"
         << "\t\t\t\t\t\tEmployee Suggestions:" << endl;
    for (int i = 0; i < totalEmployeeSuggestions; ++i)
    {
        cout << "\33[35m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << EmployeeSuggestions[i] << endl;
    }
    cls();
}

// view user complaints by cs
void viewComplaints(string complaints[], int totalComplaints)
{
    cout << "\33[35m"
         << "\t\t\t\t\t\tComplaints:" << endl;
    for (int i = 0; i < totalComplaints; ++i)
    {
        cout << "\33[35m"
             << "\t\t\t\t\t\t" << i + 1 << ". " << complaints[i] << endl;
    }
    cls();
}

// view cs balance
void CustomerCareBalance(string CustomerCare[], int CustomerCareSalaries[], int index)
{
    cout << "\33[35m"
         << "\t\t\t\t\t\t" << CustomerCare[index] << " Balance is " << CustomerCareSalaries[index] << endl;
    cls();
}

// validation for 2 options
bool ValidateEnterDataFor2(string option)
{
    bool flag = false;
    if (option == "1" || option == "2")
    {
        flag = true;
    }
    return flag;
}

// file handling
//  Function for reading data from file in parallel arrays
void readDataFromCustomersFileInParallelArrays(string usernames[], string passwords[], string phoneNumbers[], string addresses[], string genders[], string ages[], int &totalUsers)
{
    string record;
    fstream data;
    data.open("Customers.txt", ios::in);

    while (getline(data, record))
    {
        if (count(record.begin(), record.end(), ',') != 5)
        {
            // Skip the line if it doesn't have exactly 5 commas
            continue;
        }
        // assgin the data according to their respective arrays
        usernames[totalUsers] = getField(record, 1);
        passwords[totalUsers] = getField(record, 2);
        phoneNumbers[totalUsers] = getField(record, 3);
        addresses[totalUsers] = getField(record, 4);
        genders[totalUsers] = getField(record, 5);
        ages[totalUsers] = getField(record, 6);
        totalUsers++;
    }
    data.close();
}

string getField(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}

// Function for updating data in file from parallel arrays
void UpdateDataToFileForCustomerParallelArrays(const string usernames[], const string passwords[], const string phoneNumbers[], const string addresses[], const string genders[], const string ages[], const int totalUsers)
{
    fstream data;
    data.open("Customers.txt", ios::out);

    if (!data)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for (int i = 0; i < totalUsers; ++i)
    {
        data << usernames[i] << "," << passwords[i] << "," << phoneNumbers[i] << "," << addresses[i] << "," << genders[i] << ","
             << ages[i] << "\n";
    }
    data.close();
}

// Function for reading data from file in parallel arrays
void readDataFromEmployeesFile(string usernames[], string passwords[], string phoneNumbers[], string genders[], string ages[], int &totalUsers, const char *filename)
{
    string record;
    fstream data;
    data.open(filename, ios::in);

    while (getline(data, record))
    {
        if (count(record.begin(), record.end(), ',') != 4)
        {
            // Skip the line if it doesn't have exactly 5 commas
            continue;
        }
        // assgin the data according to their respective arrays
        usernames[totalUsers] = getField(record, 1);
        passwords[totalUsers] = getField(record, 2);
        phoneNumbers[totalUsers] = getField(record, 3);
        genders[totalUsers] = getField(record, 4);
        ages[totalUsers] = getField(record, 5);
        totalUsers++;
    }
    data.close();
}

// Function for updating data in file from parallel arrays
void updateDataToEmployeesFile(const string usernames[], const string passwords[], const string phoneNumbers[], const string genders[], const string ages[], const int totalUsers, const char *filename)
{
    fstream data;
    data.open(filename, ios::out);

    if (!data)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for (int i = 0; i < totalUsers; ++i)
    {
        data << usernames[i] << "," << passwords[i] << "," << phoneNumbers[i] << "," << genders[i] << ","
             << ages[i]
             << "\n";
    }
    data.close();
}

// function for reading data from emp files
void readDataFromEmployeesInfo(string workers[], int &Items, const char *filename)
{
    string record;
    fstream data;
    data.open(filename, ios::in);

    while (getline(data, record))
    {
        if (count(record.begin(), record.end(), ',') != 0)
        {
            // Skip the line if it doesn't have exactly 1 commas
            continue;
        }
        // assgin the data according to their respective arrays
        workers[Items] = getField(record, 1);
        Items++;
    }
    data.close();
}

// Function for updating data in file from parallel arrays
void UpdateDataToFileForEmployeesInfo(const string workers[], const int Items, const char *filename)
{
    fstream data;
    data.open(filename, ios::out);

    if (!data)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for (int i = 0; i < Items; ++i)
    {
        data << workers[i] << "\n";
    }
    data.close();
}

// function for reading data from cs feedback
// Function for reading data from file in string arrays
void readFeedbackData(string suggestion[], int &index, const char *filename)
{
    fstream file;
    file.open(filename, ios::in);
    string line;
    while (getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }
        // Convert the string to an integer and store it in the array
        suggestion[index] = line;
        index++;
    }
    file.close();
}

// Function for updating data from file in parallel arrays
void UpdateFeedbackData(string suggestion[], int size, const char *filename)
{
    fstream file;
    file.open(filename, ios::out);
    for (int i = 0; i < size; i++)
    {
        file << suggestion[i];
        file << "\n";
    }
    file.close();
}

void readSuggestionsData(string suggestion[], int &totalSuggestions, const char *filename)
{
    string record;
    fstream data;
    data.open(filename, ios::in);

    while (getline(data, record))
    {
        if (count(record.begin(), record.end(), ',') != 0)
        {
            // Skip the line if it doesn't have exactly 1 commas
            continue;
        }
        // assgin the data according to their respective arrays
        suggestion[totalSuggestions] = getField(record, 1);
        totalSuggestions++;
    }
    data.close();
}

// Function for updating data in file from parallel arrays
void UpdateSuggestionsData(const string suggestion[], const int totalSuggestions, const char *filename)
{
    fstream data;
    data.open(filename, ios::out);
    if (!data)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for (int i = 0; i < totalSuggestions; ++i)
    {
        data << suggestion[i] << "\n";
    }
    data.close();
}

void readDataFromCustomerComplaintFile(string suggestion[], int &totalSuggestions)
{
    string record;
    fstream data;
    data.open("CustomerComplaint.txt", ios::in);

    while (getline(data, record))
    {
        if (count(record.begin(), record.end(), ',') != 0)
        {
            // Skip the line if it doesn't have exactly 1 commas
            continue;
        }
        // assgin the data according to their respective arrays
        suggestion[totalSuggestions] = getField(record, 1);
        totalSuggestions++;
    }
    data.close();
}

// Function for updating data in file from parallel arrays
void UpdateDataToFileForCustomerComplaint(const string suggestion[], const int totalSuggestions)
{
    fstream data;
    data.open("CustomerComplaint.txt", ios::out);
    if (!data)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for (int i = 0; i < totalSuggestions; ++i)
    {
        data << suggestion[i] << "\n";
    }
    data.close();
}

string getCurrentTimestamp()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Format: "at HH:MM:SS on DD/MM/YYYY"
    char timestamp[30];
    strftime(timestamp, sizeof(timestamp), "at %H:%M:%S on %d/%m/%Y", ltm);

    return string(timestamp);
}

// builtin functions
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

bool validData(string name, string hall, string phoneNumber)
{
    // Check if any field contains a comma or if any field's length is less than 5
    if (!noCommaItem(name) || !noCommaItem(hall) || !noCommaItem(phoneNumber) || name.length() < 5 || hall.length() < 3 || !validPhoneNumber(phoneNumber))
    {
        return false;
    }
    return true;
}

bool containsComma(const string &str)
{
    // Check if the string contains a comma
    return str.find(',') != string::npos;
}
bool hasTabs(string input)
{
    // Check if the input string contains tabs ('\t')
    if (input.find('\t') != string::npos) // npos means not found
    {
        return true; // Found a tab
    }
    return false; // No tabs found
}

void hideCursor(bool value)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = value;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void getUserInput(string usernames[], string passwords[], string ages[], string genders[],
                  string phoneNumbers[], string addresses[], int &totalUsers)
{
    string newUser, age, gender, phoneNumber, address, password, checkPassword;
    system("cls");
    loginPageHeader();
    guidelines();
    CustomerHeader();
    // Validation loops
    while (true)
    {
        gotoxy(4, 22);
        hideCursor(1);
        cout << "\33[36m"
             << "\t\t\t\t\t\tEnter Username: ";
        getline(cin, newUser);

        hideCursor(0);
        if (newUser == "BB")
        {
            return;
        }
        if (empty(newUser) || hasTabs(newUser) || newUser.length() < 6 || newUser.length() > 10 || !noComma(newUser))
        {
            gotoxy(4, 23);
            cout << "\33[31m"
                 << "\t\t\t\t\t\tInvalid Username. Please Read Guidelines" << endl;
            cls();
            loginPageHeader();
            guidelines();
            CustomerHeader();
            continue;
        }

        if ((isUniqueUser(usernames, totalUsers, newUser))) // checking is username is unique and has no commas
        {
            // Age input and validation
            while (true)
            {
                gotoxy(4, 23);
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter Age: ";
                getline(cin, age);
                hideCursor(0);
                // Age input and validation logic
                if (age == "BB")
                {
                    system("cls");
                    loginPageHeader();
                    return;
                }
                if ((age.length() > 3) || (!validAge(age)))
                {
                    gotoxy(4, 24);
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tAge is invalid" << endl;
                    cls();
                    loginPageHeader();
                    guidelines();
                    CustomerHeader();
                    continue;
                }
                break;
            }

            // Gender input and validation
            while (true)
            {
                gotoxy(4, 24);
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter Gender('M'/'F'): "; // checking if gender is valid
                getline(cin, gender);
                hideCursor(0);
                // Gender input and validation logic
                if (gender == "BB")
                {
                    system("cls");
                    loginPageHeader();
                    return;
                }
                if ((gender != "M" && gender != "m" && gender != "F" && gender != "f"))
                {
                    gotoxy(4, 25);
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tGender is invalid" << endl;
                    cls();
                    loginPageHeader();
                    guidelines();
                    CustomerHeader();
                    continue;
                }
                break;
            }

            // Phone number input and validation
            while (true)
            {
                gotoxy(4, 25);
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter Phone number(e.g. 923331234567): ";
                getline(cin, phoneNumber);
                hideCursor(0);
                // Phone number input and validation logic
                // ...
                if (phoneNumber == "BB")
                {
                    system("cls");
                    loginPageHeader();
                    return;
                }
                if (!validPhoneNumber(phoneNumber))
                {
                    gotoxy(4, 26);
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tPhone Number is invalid" << endl;
                    cls();
                    loginPageHeader();
                    guidelines();
                    CustomerHeader();
                    continue;
                }
                break;
            }

            // Address input and validation
            while (true)
            {
                hideCursor(1);
                gotoxy(4, 26);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter Address (Max Length=20): ";
                getline(cin, address);
                hideCursor(0);
                // Address input and validation logic
                if (address == "BB")
                {
                    system("cls");
                    loginPageHeader();
                    return;
                }
                if (address.length() > 20 || empty(address) || !noCommaItem(address))
                {
                    gotoxy(4, 27);
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tAddress is invalid" << endl;
                    cls();
                    loginPageHeader();
                    guidelines();
                    CustomerHeader();
                    continue;
                }
                break;
            }

            // Password input and validation
            while (true)
            {
                gotoxy(4, 27);
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter Password: ";
                getline(cin, password);
                hideCursor(0);
                // Password input and validation logic
                if (password == "BB")
                {
                    system("cls");
                    loginPageHeader();
                    return;
                }
                if (!validPassword(password))
                {
                    gotoxy(4, 28);
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tInvalid Password. Please read the instructions. \n";
                    cls();
                    loginPageHeader();
                    guidelines();
                    CustomerHeader();
                    continue;
                }
                break;
            }

            // Password match validation
            while (true)
            {
                gotoxy(4, 28);
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter password again: ";
                getline(cin, checkPassword);
                hideCursor(0);
                if (checkPassword == "BB")
                {
                    system("cls");
                    loginPageHeader();
                    return;
                }
                if (password != checkPassword)
                {
                    gotoxy(4, 29);
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tPasswords. Please read the instructions. \n";
                    cls();
                    loginPageHeader();
                    guidelines();
                    CustomerHeader();
                    continue;
                }
                break;
            }

            // Assign validated user data
            usernames[totalUsers] = newUser;
            passwords[totalUsers] = password;
            ages[totalUsers] = age;
            genders[totalUsers] = gender;
            phoneNumbers[totalUsers] = phoneNumber;
            addresses[totalUsers] = address;
            totalUsers++;
            gotoxy(4, 29);
            cout << "\33[32m"
                 << "\t\t\t\t\t\tAccount created successfully. \n";
            cls();
            loginPageHeader();
            break;
        }
        else
        {
            cls();
            loginPageHeader();
            guidelines();
            CustomerHeader();
            continue;
        }
        cls();
        loginPageHeader();
    }
}

void getEmployeesInput(string usernames[], string passwords[], string ages[], string genders[],
                       string phoneNumbers[], int &totalUsers)
{
    string newUser, age, gender, phoneNumber, address, password, checkPassword;
    system("cls");
    loginPageHeader();
    guidelines();
    EmployeeHeader();
    // Validation loops
    while (true)
    {
        gotoxy(4, 22);
        hideCursor(1);
        cout << "\33[36m"
             << "\t\t\t\t\t\tEnter Username: ";
        getline(cin, newUser);
        hideCursor(0);

        if (newUser == "BB")
        {
            return;
        }
        if (empty(newUser) || hasTabs(newUser) || newUser.length() < 6 || newUser.length() > 10 || !noComma(newUser))
        {
            gotoxy(4, 23);
            cout << "\33[31m"
                 << "\t\t\t\t\t\tInvalid Username. Read Guidelines" << endl;
            cls();
            loginPageHeader();
            guidelines();
            EmployeeHeader();
            continue;
        }

        if ((isUniqueEmployee(usernames, totalUsers, newUser))) // checking is username is unique and has no commas
        {
            // Age input and validation
            while (true)
            {
                gotoxy(4, 23);
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter Age: ";
                getline(cin, age);
                hideCursor(0);
                // Age input and validation logic
                if (age == "BB")
                {
                    system("cls");
                    loginPageHeader();
                    return;
                }
                if ((age.length() > 3) || (!validAge(age)))
                {
                    gotoxy(4, 24);
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tAge is invalid" << endl;
                    cls();
                    loginPageHeader();
                    guidelines();
                    EmployeeHeader();
                    continue;
                }
                break;
            }

            // Gender input and validation
            while (true)
            {
                gotoxy(4, 24);
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter Gender('M'/'F'): "; // checking if gender is valid
                getline(cin, gender);
                hideCursor(0);
                // Gender input and validation logic
                if (gender == "BB")
                {
                    system("cls");
                    loginPageHeader();
                    return;
                }
                if ((gender != "M" && gender != "m" && gender != "F" && gender != "f"))
                {
                    gotoxy(4, 25);
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tGender is invalid" << endl;
                    cls();
                    loginPageHeader();
                    guidelines();
                    EmployeeHeader();
                    continue;
                }
                break;
            }

            // Phone number input and validation
            while (true)
            {
                gotoxy(4, 25);
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter Phone number(e.g. 923331234567): ";
                getline(cin, phoneNumber);
                hideCursor(0);
                // Phone number input and validation logic
                // ...
                if (phoneNumber == "BB")
                {
                    system("cls");
                    loginPageHeader();
                    return;
                }
                if (!validPhoneNumber(phoneNumber))
                {
                    gotoxy(4, 26);
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tPhone Number is invalid" << endl;
                    cls();
                    loginPageHeader();
                    guidelines();
                    EmployeeHeader();
                    continue;
                }
                break;
            }

            // Password input and validation
            while (true)
            {
                gotoxy(4, 26);
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter Password: ";
                getline(cin, password);
                hideCursor(0);
                // Password input and validation logic
                if (password == "BB")
                {
                    system("cls");
                    loginPageHeader();
                    return;
                }
                if (!validPassword(password))
                {
                    gotoxy(4, 27);
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tInvalid Password. Please read the instructions. \n";
                    cls();
                    loginPageHeader();
                    guidelines();
                    EmployeeHeader();
                    continue;
                }
                break;
            }

            // Password match validation
            while (true)
            {
                gotoxy(4, 27);
                hideCursor(1);
                cout << "\33[36m"
                     << "\t\t\t\t\t\tEnter password again: ";
                getline(cin, checkPassword);
                hideCursor(0);
                if (checkPassword == "BB")
                {
                    system("cls");
                    loginPageHeader();
                    return;
                }
                if (password != checkPassword)
                {
                    gotoxy(4, 28);
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tPasswords do not match. \n";
                    cls();
                    loginPageHeader();
                    guidelines();
                    EmployeeHeader();
                    continue;
                }
                break;
            }

            // Assign validated user data
            usernames[totalUsers] = newUser;
            passwords[totalUsers] = password;
            ages[totalUsers] = age;
            genders[totalUsers] = gender;
            phoneNumbers[totalUsers] = phoneNumber;
            totalUsers++;
            gotoxy(4, 28);
            cout << "\33[32m"
                 << "\t\t\t\t\t\tAccount created successfully. \n";
            cls();
            loginPageHeader();
            break;
        }
        else
        {
            cls();
            loginPageHeader();
            guidelines();
            EmployeeHeader();
            continue;
        }
        cls();
        loginPageHeader();
    }
}

void guidelines()
{
    cout << "\33[31m"
         << "\t\t\t\t\t\t***Username Must Contain at Least 6 Letters and Max 10 Letters, no Comma and Max 1 Space***" << endl;
    cout << "\33[31m"
         << "\t\t\t\t\t\t***Password Must Contain at Least 8 Letters and Max 12 Letters, 1 Capital Letter, 1 Special Charater, 1 Number, no Space \n\t\t\t\t\t\tand No Comma***" << endl;
    cout << "\33[31m"
         << "\t\t\t\t\t\t***Other fields must also be filled as instructed to proceed Smoothly**" << endl
         << endl;
}

void CustomerHeader()
{
    SetConsoleTextAttribute(hConsole, 11);
    gotoxy(2, 2);
    cout << "  ____ ";
    gotoxy(2, 3);
    cout << " / ___|";
    gotoxy(2, 4);
    cout << "| |    ";
    gotoxy(2, 5);
    cout << "| |___ ";
    gotoxy(2, 6);
    cout << " \\____|";
    gotoxy(2, 7);
    cout << "       ";
    gotoxy(2, 8);
    cout << "| | | |";
    gotoxy(2, 9);
    cout << "| | | |";
    gotoxy(2, 10);
    cout << "| |_| |";
    gotoxy(2, 11);
    cout << " \\___/ ";
    gotoxy(2, 12);
    cout << " ____  ";
    gotoxy(2, 13);
    cout << "/ ___| ";
    gotoxy(2, 14);
    cout << "\\___ \\ ";
    gotoxy(2, 15);
    cout << " ___) |";
    gotoxy(2, 16);
    cout << "|____/ ";
    gotoxy(2, 17);
    cout << " _____ ";
    gotoxy(2, 18);
    cout << "|_   _|";
    gotoxy(2, 19);
    cout << "  | |  ";
    gotoxy(2, 20);
    cout << "  | |  ";
    gotoxy(2, 21);
    cout << "  |_|  ";
    gotoxy(2, 22);
    cout << "  ___  ";
    gotoxy(2, 23);
    cout << " / _ \\ ";
    gotoxy(2, 24);
    cout << "| | | |";
    gotoxy(2, 25);
    cout << "| |_| |";
    gotoxy(2, 26);
    cout << " \\___/ ";
    gotoxy(2, 27);
    cout << " __  __";
    gotoxy(2, 28);
    cout << "|  \\/  |";
    gotoxy(2, 29);
    cout << "| |\\/| |";
    gotoxy(2, 30);
    cout << "| |  | |";
    gotoxy(2, 31);
    cout << "|_|  |_|";
    gotoxy(2, 32);
    cout << " _____ ";
    gotoxy(2, 33);
    cout << "| ____|";
    gotoxy(2, 34);
    cout << "|  _|  ";
    gotoxy(2, 35);
    cout << "| |___ ";
    gotoxy(2, 36);
    cout << "|_____|";
    gotoxy(2, 37);
    cout << " ____  ";
    gotoxy(2, 38);
    cout << "|  _ \\ ";
    gotoxy(2, 39);
    cout << "| |_) |";
    gotoxy(2, 40);
    cout << "|  _ < ";
    gotoxy(2, 41);
    cout << "|_| \\_\\ ";
}

void EmployeeHeader()
{
    SetConsoleTextAttribute(hConsole, 6);
    gotoxy(2, 2);
    cout << " _____  ";
    gotoxy(2, 3);
    cout << "| ____| ";
    gotoxy(2, 4);
    cout << "|  _|   ";
    gotoxy(2, 5);
    cout << "| |___  ";
    gotoxy(2, 6);
    cout << "|_____| ";
    gotoxy(2, 7);
    cout << " __  __ ";
    gotoxy(2, 8);
    cout << "|  \\/  | ";
    gotoxy(2, 9);
    cout << "| |\\/| | ";
    gotoxy(2, 10);
    cout << "| |  | | ";
    gotoxy(2, 11);
    cout << "|_|  |_| ";
    gotoxy(2, 12);
    cout << " ____   ";
    gotoxy(2, 13);
    cout << "|  _ \\  ";
    gotoxy(2, 14);
    cout << "| |_) | ";
    gotoxy(2, 15);
    cout << "|  __/  ";
    gotoxy(2, 16);
    cout << "|_|     ";
    gotoxy(2, 17);
    cout << " _      ";
    gotoxy(2, 18);
    cout << "| |     ";
    gotoxy(2, 19);
    cout << "| |     ";
    gotoxy(2, 20);
    cout << "| |___  ";
    gotoxy(2, 21);
    cout << "|_____| ";
    gotoxy(2, 22);
    cout << "  ___   ";
    gotoxy(2, 23);
    cout << " / _ \\  ";
    gotoxy(2, 24);
    cout << "| | | | ";
    gotoxy(2, 25);
    cout << "| |_| | ";
    gotoxy(2, 26);
    cout << " \\___/  ";
    gotoxy(2, 27);
    cout << "        ";
    gotoxy(2, 28);
    cout << "__   __ ";
    gotoxy(2, 29);
    cout << "\\ \\ / / ";
    gotoxy(2, 30);
    cout << " \\ V /  ";
    gotoxy(2, 31);
    cout << "  | |   ";
    gotoxy(2, 32);
    cout << "  |_|   ";
    gotoxy(2, 33);
    cout << "        ";
    gotoxy(2, 34);
    cout << " _____  ";
    gotoxy(2, 35);
    cout << "| ____| ";
    gotoxy(2, 36);
    cout << "|  _|   ";
    gotoxy(2, 37);
    cout << "| |___  ";
    gotoxy(2, 38);
    cout << "|_____| ";
    gotoxy(2, 39);
    cout << "        ";
    gotoxy(2, 40);
    cout << " _____  ";
    gotoxy(2, 41);
    cout << "| ____| ";
    gotoxy(2, 42);
    cout << "|  _|   ";
    gotoxy(2, 43);
    cout << "| |___  ";
    gotoxy(2, 44);
    cout << "|_____| ";
}

bool isValidChar(char ch)
{
    // Check if the character is an alphanumeric key
    if (isalnum(ch))
    {
        return true;
    }
    return false;
}

int movementOfArrow(int x, int y, int minOption, int maxOption)
{
    int key;
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

void storeShopsToFile(const string shops[], const int totalShops)
{
    fstream data;
    data.open("Shops.txt", ios::out);

    if (!data)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for (int i = 0; i < totalShops; ++i)
    {
        data << shops[i] << endl;
    }
    data.close();
}

void readShopsToFile(string shops[], int &totalShops)
{
    string record;
    fstream data;
    data.open("Shops.txt", ios::in);
    totalShops = 0;
    while (getline(data, record))
    {
        shops[totalShops] = record;
        totalShops++;
    }
    data.close();
}

void storeShopsMenuToFile(const string shopMenu[], const int shopMenuPrice[], const int totalShops, const char *filename)
{
    fstream data;
    data.open(filename, ios::out);

    if (!data)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for (int i = 0; i < totalShops; ++i)
    {
        data << shopMenu[i] << "," << shopMenuPrice[i] << endl;
    }
    data.close();
}
void readShopsMenuToFile(string shopMenu[], int shopMenuPrice[], int &totalShops, const char *filename)
{
    string record;
    fstream data;
    data.open(filename, ios::in);
    totalShops = 0;
    while (getline(data, record))
    {
        shopMenu[totalShops] = getField(record, 1);
        shopMenuPrice[totalShops] = stoi(getField(record, 2));
        totalShops++;
    }
    data.close();
}

void forgotPassword(string usernames[], string passwords[], string ages[], string genders[], string phoneNumbers[], string addresses[], int totalUsers)
{
    system("cls");
    loginPageHeader();
    string username, age, gender, phoneNumber, newPassword, yes;
    cout << "\33[31m"
         << "\t\t\t\t\t\tForgot your password? Type Yes if you want to change: "
         << "\33[0m";
    getline(cin, yes);
    hideCursor(1);
    if (yes == "Yes" || yes == "yes" || yes == "YES")
    {
        while (true)
        {
            system("cls");
            loginPageHeader();
            CustomerHeader();
            gotoxy(4, 22);
            hideCursor(1);
            cout << "\33[36m"
                 << "\t\t\t\t\t\tEnter Username: ";
            getline(cin, username);
            hideCursor(0);
            if (username == "BB")
            {
                system("cls");
                loginPageHeader();
                return;
            }
            if (empty(username) || hasTabs(username) || username.length() < 6 || username.length() > 10 || !noComma(username))
            {
                gotoxy(4, 23);
                cout << "\33[31m"
                     << "\t\t\t\t\t\tInvalid Username. Please Read Guidelines" << endl;
                cls();
                continue;
            }

            if ((!isUniqueUserCP(usernames, totalUsers, username))) // checking is username is unique and has no commas
            {
                // Age input and validation
                while (true)
                {
                    gotoxy(4, 23);
                    hideCursor(1);
                    cout << "\33[36m"
                         << "\t\t\t\t\t\tEnter Age: ";
                    getline(cin, age);
                    hideCursor(0);
                    // Age input and validation logic
                    if (age == "BB")
                    {
                        system("cls");
                        loginPageHeader();
                        return;
                    }
                    if ((age.length() > 3) || (!validAge(age)))
                    {
                        gotoxy(4, 24);
                        cout << "\33[31m"
                             << "\t\t\t\t\t\tAge is invalid" << endl;
                        cls();
                        loginPageHeader();
                        CustomerHeader();
                        continue;
                    }
                    break;
                }

                // Gender input and validation
                while (true)
                {
                    gotoxy(4, 24);
                    hideCursor(1);
                    cout << "\33[36m"
                         << "\t\t\t\t\t\tEnter Gender('M'/'F'): "; // checking if gender is valid
                    getline(cin, gender);
                    hideCursor(0);
                    // Gender input and validation logic
                    if (gender == "BB")
                    {
                        system("cls");
                        loginPageHeader();
                        return;
                    }
                    if ((gender != "M" && gender != "m" && gender != "F" && gender != "f"))
                    {
                        gotoxy(4, 25);
                        cout << "\33[31m"
                             << "\t\t\t\t\t\tGender is invalid" << endl;
                        cls();
                        loginPageHeader();
                        CustomerHeader();
                        continue;
                    }
                    break;
                }

                // Phone number input and validation
                while (true)
                {
                    gotoxy(4, 25);
                    hideCursor(1);
                    cout << "\33[36m"
                         << "\t\t\t\t\t\tEnter Phone number(e.g. 923331234567): ";
                    getline(cin, phoneNumber);
                    hideCursor(0);
                    // Phone number input and validation logic
                    // ...
                    if (phoneNumber == "BB")
                    {
                        system("cls");
                        loginPageHeader();
                        return;
                    }
                    if (!validPhoneNumber(phoneNumber))
                    {
                        gotoxy(4, 26);
                        cout << "\33[31m"
                             << "\t\t\t\t\t\tPhone Number is invalid" << endl;
                        cls();
                        loginPageHeader();
                        CustomerHeader();
                        continue;
                    }
                    break;
                }
            }
            else
            {
                cout << "\t\t\t\t\t\tUsername is not registered. Try Again!\n";
                cls();
                continue;
            }
            break;
        }

        // Check if provided information matches user data
        bool userFound = false;
        for (int i = 0; i < totalUsers; ++i)
        {
            if (usernames[i] == username && ages[i] == age && genders[i] == gender && phoneNumbers[i] == phoneNumber)
            {
                userFound = true;
                // Enter a new password
                cout << "\33[32m"
                     << "\t\t\t\t\t\tEnter a new password: ";
                hideCursor(1);
                getline(cin, newPassword);
                hideCursor(0);

                // Validate the new password
                if (!validPassword(newPassword))
                {
                    cout << "\33[31m"
                         << "\t\t\t\t\t\tPassword is invalid. Please try again." << endl;
                    cls();
                    loginPageHeader();
                    return;
                }

                // Change the password
                passwords[i] = newPassword;
                cout << "\33[32m"
                     << "\t\t\t\t\t\tPassword changed successfully for user: " << username << endl;
                UpdateDataToFileForCustomerParallelArrays(usernames, passwords, phoneNumbers, addresses, genders, ages, totalUsers);
                cls();
                loginPageHeader();
                return;
            }
        }

        if (!userFound)
        {
            cout << "\33[31m"
                 << "\t\t\t\t\t\tVerification failed. Please check your information and try again." << endl;
            cls();
            loginPageHeader();
        }
    }
    else
    {
        system("cls");
        loginPageHeader();
        return;
    }
}

bool isUniqueUserCP(string usernames[], int totalUsers, string newUser)
{
    bool isUnique = true;
    for (int i = 0; i < totalUsers; ++i)
    {
        if (usernames[i] == newUser)
        {
            isUnique = false;
            if (!isUnique)
            {
                return false;
            }
        }
    }
    return true;
}

void printS()
{
    cout << "\33[31m";
    gotoxy(65, 15);
    cout << " ____  ";
    gotoxy(65, 16);
    Sleep(50);
    cout << "/ ___| ";
    gotoxy(65, 17);
    Sleep(50);
    cout << "\\___ \\ ";
    gotoxy(65, 18);
    Sleep(50);
    cout << " ___) |";
    gotoxy(65, 19);
    Sleep(50);
    cout << "|____/ ";
    cout << "\33[0m";
}

void printS2()
{
    cout << "\33[32m";
    gotoxy(76, 15);
    cout << " ____  ";
    gotoxy(76, 16);
    Sleep(50);
    cout << "/ ___| ";
    gotoxy(76, 17);
    Sleep(50);
    cout << "\\___ \\ ";
    gotoxy(76, 18);
    Sleep(50);
    cout << " ___) |";
    gotoxy(76, 19);
    Sleep(50);
    cout << "|____/ ";
    cout << "\33[0m";
}

void printC()
{
    cout << "\33[34m";
    gotoxy(87, 15);
    cout << "  ____ ";
    gotoxy(87, 16);
    Sleep(50);
    cout << " / ___|";
    gotoxy(87, 17);
    Sleep(50);
    cout << "| |    ";
    gotoxy(87, 18);
    Sleep(50);
    cout << "| |___ ";
    gotoxy(87, 19);
    Sleep(50);
    cout << " \\____|";
    cout << "\33[0m";
}

void printSSC()
{
    Sleep(100);
    printS();
    Sleep(100);
    printS2();
    Sleep(100);
    printC();
    Sleep(250);
}