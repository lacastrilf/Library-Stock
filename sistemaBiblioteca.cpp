#include <iostream>
#include <string>
#include <cctype> // Use std::isdigit
using namespace std;

// Include of class
#include "Datas.h"

class Book
{
private:
    string key;
    string tittle;
    string author;
    int year;
    double price;
    int quantityStock;
    string seller;

public:
    Book(string keys, string tittle, string author, int year, double price, int quantityStock, string seller)
    {
        this->key = keys;
        this->tittle = tittle;
        this->author = author;
        this->year = year;
        this->price = price;
        this->quantityStock = quantityStock;
        this->seller = seller;
    }

    string getKey() { return key; }
    string getTittle() { return tittle; }
    string getAuthor() { return author; }
    int getYear() { return year; }
    double getPrice() { return price; }
    int getQuantityStock() { return quantityStock; }
    string getSeller() { return seller; }

    void setPrice(double price) { this->price = price; }
    void setQuantityStock(int quantityStock) { this->quantityStock = quantityStock; }

    void printData()
    {
        cout << "Key: " << key << endl;
        cout << "Title: " << tittle << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity Stock: " << quantityStock << endl;
        cout << "Seller: " << seller << endl;
    };
};

bool isNumber(const string &str)
{
    for (char c : str)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

class UserMenu {
public:
    void showMenu() {
        string userOption;
        do {
            cout << "--User Menu--" << endl;
            cout << "1. Sell a book" << endl;
            cout << "2. Buy books" << endl;
            cout << "3. Watch list of books" << endl;
            cout << "4. Filter books by title letter" << endl;
            cout << "5. Search book by a Key" << endl;
            cout << "6. Exit" << endl;
            cout << "Select an option please: ";
            cin >> userOption;

            if (isNumber(userOption)){
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
    void sellBook(){
        string title, author;  int year;  double price; 
        cout << "Enter book details please: " << endl;
        
        cout << "Title: ";
        cin.ignore(); 
        getline(cin, title);

        cout << "Author: ";
        getline(cin, author);

        cout << "Year: ";
        cin >> year;

        do {
            cout << "Price: $";
            cin >> price;

            if (price <= 0)
            {
                cout << "Error: Price must be greater than 0. Please try again. :)" << endl;
            }
        } while (price <= 0);
            cout << "Book titled '" << title << "' by " << author << " added for sale at $" << price << "." << endl;

        
    }

    void buyBook(){
        string title, option;  int year;  double price;
        

        cout << "Where do you want to buy the book?" << endl;
        cout << "1. From the library" << endl;
        cout << "2. From UserX" << endl; // Enter the name from the sellBook class??? to do
        cout << "Select an option: ";
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


//--------------------------------------------------------------------------------------------
int main()
{
    string option, username, password;

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
            Datas data("./txtFiles/administrator.txt");
            cout << "Enter your username" << endl;
            cin >> username;
            cout << "Enter your password" << endl;
            cin >> password;

            if (data.getAdministrator(username, password))
            {
                cout << "Administrator authenticated successfully!" << endl;
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
