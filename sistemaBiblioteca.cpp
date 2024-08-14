#include <iostream>
#include <string>
#include <cctype> // Use std::isdigit
using namespace std;

// Include of class
#include "Datas.h"
#include "Book.h"
#include "UserMenu.h"

bool isNumber(const string &str)
{
    for (char c : str)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

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

    cout << "Welcome to the library!" << endl;
    cout << "1. User" << endl
         << "2. Administrator" << endl
         << "Select an option: ";
    cin >> option;

    if (isNumber(option))
    {
        if (option == "1")
        {
            cout << "User Menu" << endl;
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
