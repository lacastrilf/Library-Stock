#include <iostream>
#include <string>
#include <cctype> // Use std::isdigit
using namespace std;

// Include of class
#include "Datas.h"
#include "Book.h"

bool isNumber(const string &str)
{
    for (char c : str)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

class UserMenu
{
public:
    void showMenu()
    {
        string userOption;
        do
        {
            cout << "--User Menu--" << endl;
            cout << "1. Sell a book" << endl;
            cout << "2. Buy books" << endl;
            cout << "3. Watch list of books" << endl;
            cout << "4. Filter books by title letter" << endl;
            cout << "5. Search book by a Key" << endl;
            cout << "6. Exit" << endl;
            cout << "Select an option please: ";
            cin >> userOption;

            if (isNumber(userOption))
            {
                if (userOption == "1")
                {
                    cout << "Sell Book selected..." << endl;
                    sellBook();
                }
                else if (userOption == "2")
                {
                    cout << "Buy Book selected..." << endl;
                    buyBook();
                }
                else if (userOption == "3")
                {
                    cout << "View list of books selected..." << endl;
                }
                else if (userOption == "4")
                {
                    cout << "Filter by title letter option selected..." << endl;
                }
                else if (userOption == "5")
                {
                    cout << "Search book by Key selected..." << endl;
                }
                else if (userOption == "6")
                {
                    cout << "Exiting..." << endl;
                }
                else
                {
                    cout << "Invalid option. Please try again." << endl;
                }
            }
            else
            {
                cout << "Invalid option. Please enter a number." << endl;
            }

        } while (userOption != "6");
    }

private:
    string sellerName; //update

    void sellBook()
    {
        string title, author;
        int year;
        double price;
        cout << "Enter book details please: " << endl;

        cout << "Enter your name please: ";   
        getline(cin,sellerName);

        cout << "Title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Author: ";
        getline(cin, author);

        cout << "Year: ";
        cin >> year;

        do
        {
            cout << "Price: $";
            cin >> price;

            if (price <= 0)
            {
                cout << "Error: Price must be greater than 0. Please try again. :)" << endl;
            }
        } while (price <= 0);
        cout << "Book titled '" << title << "' by " << author << " added for sale at $" << price << "." << endl;
    }

    void buyBook()
    {
        string title, option;
        int year;
        double price;

        cout << "Where do you want to buy the book?" << endl;
        cout << "1. From the library" << endl;
        cout << "2. From " << sellerName << endl; 
        cin >> option;

        if (isNumber(option))
        {
            cout << "Enter the title of the book you want to buy: ";
            cin.ignore();
            getline(cin, title);

            if (option == "1")
            {
                cout << "Searching for '" << title << "' in the library..." << endl;
            }
            else if (option == "2")
            {
                cout << "Searching for '" << title << "' from UserX..." << endl;
            }
            else
            {
                cout << "Invalid option, sorry :(.Returning to main menu." << endl;
            }
        }
        else
        {
            cout << "Invalid option. Please enter a number." << endl;
        }
    }
};

// Method to check if number is greather than 0
bool isGreather(const int number)
{
    return number > 0;
}

int indexRow(string key)
{
}

int indexColumns(string key)
{
}

struct Stock
{
    string typeString;
    int typeInt;
    double typeDouble;
};
//--------------------------------------------------------------------------------------------
int main()
{
    string option, username, password;
    Datas dataBook("./txtFiles/books.txt");     // Create objet of type "Datas" to manage the Books.txt files
    Datas data("./txtFiles/administrator.txt"); // Create objet of type "Datas" to manage the administrator.txt files

    Stock stock[10][10];

    ifstream file("./txtFiles/books.txt");
    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    else
    {
        string vector[7]{};
        string line;
        int rows = 0, columns = 0, index = 0;

        while (getline(file, line))
        {
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            rows = indexRow(token);
            columns = indexColumns(token);

            while (getline(ss, token, ',') && index)
            {
                vector[index] = token;
                index++;
            }
            Book newBook(vector[0], vector[1], vector[2], 2, 3, 1, vector[6]);
            stock[rows][columns].typeString = token;
        }
    }

    cout << "Welcome to the library!" << endl;
    cout << "1. User" << endl
         << "2. Administrator" << endl
         << "Select an option: ";
    cin >> option;

    if (isNumber(option))
    {
        if (option == "1")
        {
            UserMenu menu;
            menu.showMenu();
        }
        else if (option == "2")
        {

            cout << "Enter your username" << endl;
            cin >> username;
            cout << "Enter your password" << endl;
            cin >> password;

            if (data.getAdministrator(username, password))
            {

                cout << "Administrator authenticated successfully!" << endl;
                cout << "Administrator Menu" << endl;
                cout << "1. Define the number of books in stock." << endl;
                cout << "2. Add a new book to the stock." << endl;
                cout << "3. Search for a book by its key." << endl;
                cout << "Exit the program" << endl;
                cout << "Enter a option: ";
                cin >> option;

                if (isNumber(option))
                {
                    int optionSwitch = stoi(option); // Convert to integer option
                    string title;
                    string author;
                    int year;
                    int price;
                    int quantityStock;
                    string seller;

                    // Creat an object to type "Data" to manage the books file

                    switch (optionSwitch)
                    {
                    case 1:
                        // Define the number of books in stock

                        break;
                    case 2:
                    {
                        // Add a new book to the stock
                        cout << "Add a new book" << endl;
                        cout << "Enter the title of the book: ";
                        cin >> title;
                        cout << "Enter the author of the book:";
                        cin >> author;
                        cout << "Enter the year of publication: ";
                        cin >> year;
                        cout << "Enter the price of book: ";
                        cin >> price;
                        if (!isGreather(price) && isNumber(to_string(price)))
                        {
                            cout << "Invalid data. Please enter a positive integer.";
                            break;
                        }
                        cout << "Enter the number of books in stock";
                        cin >> quantityStock;
                        if (!isGreather(quantityStock) && isNumber(to_string(quantityStock)))
                        {
                            cout << "Invalid data. Please enter a positive integer.";
                            break;
                        }
                        cout << "Enter the seller: ";
                        cin >> seller;
                        Book newBook("A1234", title, author, year, price, quantityStock, seller);
                        dataBook.addBook(newBook);
                    }

                    break;
                    case 3:
                        // Search for a book by its key
                        break;
                    case 4:
                        // Exit the program
                        break;
                    default:
                        cout << "Invalid option.";
                    }
                }
                else
                {
                    cout << "Invalid option.";
                }
            }
            else
            {
                cout << "Authentication failed. Please check your username and password." << endl;
            }
        }
        else
        {
            cout << "Invalid option :(. Please try again." << endl;
        }
    }
    else
    {
        cout << "Invalid option. Please try again." << endl;
    }

    return 0;
};
