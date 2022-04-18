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
     
        char ch;
        while (f.get(ch))/* пока считывается символ */
        {
            f >> ch;/*считываем символ  */
            cout << ch<<endl;
        }

    }
    f.close();
}

