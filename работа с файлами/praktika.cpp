// praktika.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>

#include <fstream>/*ifstream ofstream*/
#include <string.h>
using namespace std;
int main()
{ 
   /*создание файла и запись в него*/
    ofstream f;
    string path="myfile.txt";
    f.open(path, ofstream::app);
    if (!f.is_open())
    {
        cout << "oops!";
    }
    else
    {
        cout << "yhu!";
        for (int i = 0; i < 5; i++)
        {
            f << "1111" << endl;
        }

    }
    f.close();
}

