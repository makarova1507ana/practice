// praktika.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>

#include <fstream>/*ifstream ofstream*/
#include <string.h>
#include <sstream>
using namespace std;
int main()
{ 
   /*чтение из файла*/
    fstream f;
    string path="myfile.txt";
    f.open(path);
    if (!f.is_open())
    {
        cout << "oops!";
    }
    else
    {
        cout << "yhu!";
     
        string ch;
         
     
        while (!f.eof())
        {
            ch = "";
            getline(f, ch);
            cout << ch<<endl;
        }

    }
    f.close();
}

