#ifndef DATAS_H
#define DATAS_H

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

class Datas
{
private:
    std::string filename;

public:
    Datas(std::string file) : filename(file) {}

    // Method to check if the provided username and password match any existing user in the CSV file
    bool getAdministrator(std::string username, std::string password)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cerr << "Error opening file!" << endl;
            return 1;
        }
        else
        {
            string vector[2]{};
            string line;
            while (getline(file, line))
            {
                stringstream ss(line);
                string token;
                int index = 0;
                while (getline(ss, token, ',') && index < 2)
                {
                    vector[index] = token;
                    index++;
                }

                if (vector[0] == username && vector[1] == password)
                {
                    return true;
                }
            }

            return false;
        }
    };

    void addBook(Book book)
    {
    }
};

#endif // DATAS_H