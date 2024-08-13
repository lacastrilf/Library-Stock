#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
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
    string getTitle() { return tittle; }
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

#endif // BOOK_H