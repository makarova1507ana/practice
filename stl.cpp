#include <iostream>
#include <functional>
#include <vector>

/*односвязный список
push_front() -добавляет в начало списка гораздо быстрее чем в двусвязом
iterator для forward_list имеет презгрузку ++, но --


forward_list<int> fl={1,3,4,2};
auto it=fl.begin();
insert_after(it,999)- вставка элемента после определенного
произойдет вствка после 1
то есть будет {1,999,3,4,2}

forward_list<int> fl = { 1,3,4,2 };
auto it = fl.cbefore_begin();
insert_after(it,999)- вставка элемента после определенного
произойдет вствка после ничего
то есть будет {999,1,3,4,2}
*/
#include<forward_list>

/*статический массив
* array<int,4> arr={4,0,2,-4};
* array<int,4> arr2={3,0,2,-4};
* bool return=(arr==arr2);
*/
#include<array>

/*гибрид листа и вектора
*/
#include<deque>

/*бинарное дерево
* set<int> mySet;
* mySet.insert(7);
* mySet.insert(1);
* mySet.insert(5);
* mySet.insert(100);
* элементы добавляются по принципу бинарного дерева 
в левую часть меньше предков 
* в правую часть больше предков
* mySet.find(7);
* в set Не получится одинаковые элементы
* 
* multiset<int> myMultiSet;
* в multiset  получится одинаковые элементы
*/
#include<set>


/*Полиформная обертка*/
/*Делегат - класс, который позволяет хранить ссылку на метод с опредленной сигнатурой */
using namespace std;
void f(int a,float b)
{
    cout << "f" << endl;
}

bool checkNumber(int number)
{
    if (number>0)
    {
        cout << "checkNumber   " << number<< endl;
        return true;
    }
    else
    {
        return false;
    }
}
bool checkNumber2(int number)
{
    if (number%2== 0)
    {
        cout << "checkNumber2  " <<  number<< endl;
        return true;
    }
    else
    {
        return false;
    }
}
bool delNumber3(int number)
{
    if (number % 3 == 0)
    {
        cout << "delNumber3  " << number << endl;
        return true;
    }
    else
    {
        return false;
    }
}
void rangeVector(vector<int>& vc,function<bool(int)>func)
{
    for (auto it = vc.begin(); it != vc.end(); it++)
    {
        func(*it);
    }
}

void rangeVector(vector<int>& vc, vector<function<bool(int)>>funcvec)
{
    /*
    for (auto it = vc.begin(); it != vc.end(); it++)
    {
        for (int j = 0;  j<funcvec.size(); j++)
        {
            funcvec[j](*it);
        }
    }*/
    for (auto el: vc)
    {
        for (auto &fel : funcvec)
        {
            fel(el);
        }
    }
}
int main()
{
    setlocale(LC_ALL, "ru");
    function<void(int,float)>function1;//объект, хранящий ссылку на функцию
    function1 = f;
    function1(5,3.1);
   
    vector<int> v = { 1,4,2,7,5,-4,6,0,3 };
    function<bool(int)> function2;
    function2 = checkNumber;
    rangeVector(v, function2);


    cout << "\nVector of function\n" << endl;

    vector<function<bool(int)>> functionVector;
    functionVector.push_back(checkNumber);
    functionVector.push_back(checkNumber2);
    functionVector.push_back(delNumber3);
    rangeVector(v, functionVector);

    cout << "\nЛямба функция\n" << endl;
    bool b = true;
    function<bool(int)> function3;
   /* function3 = [b](int a) {
        std::cout << "лямбда функция  " << a << endl;
        return b;
    };*//*лямба функция*/
    rangeVector(v, [b](int a) {
        std::cout << "лямбда функция  " << a << endl;
        return b;
        });
    

}
