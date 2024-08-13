#include <iostream>
#include <string>
#include <cctype> // Para std::isdigit

using namespace std;

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

int main()
{
    string option, username, password;

    cout << "Welcome to the library!" << endl;
    cout << "1. User" << endl
         << "2. Administrador" << endl
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
}
