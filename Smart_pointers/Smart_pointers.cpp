#include <iostream>
#include "Smart.h"
#include <memory>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    int* raw_ptr1 = new int(101);
    int* raw_ptr2 = new int(10);

   /* 
   Shared<int> test1(raw_ptr1);
    Shared<int> test2(test1);
    cout << test1.use_count();
    */
    

    

    /*
    Unique<int> test1(raw_ptr1);
    unique_ptr<int> test2(raw_ptr2);
    //////////////
    cout << "Получение сырого указателя\n";
    cout << test1.get() << endl;
    cout << test2.get() << endl;
    cout << endl;
    */

    //Swap
    /*Unique<int> test1(raw_ptr1);
    Unique<int> test2(raw_ptr2);
    cout << *test1.get() << endl;
    cout << *test2.get() << endl;
    test1.swap(test2);
    cout << *test1.get() << endl;
    cout << *test2.get() << endl;*/

    
    

    /////////////////
   /* 
   cout << "Reset()\n";
    test1.reset();
    test2.reset();
    cout << "raw pointers\n";
    cout << raw_ptr1 << endl;
    cout << raw_ptr2 << endl;
    cout << endl;
    */

    ////////////////
    /*
    cout << "Release()\n";
    test1.release();
    test2.release();
    cout << "raw pointers\n";
    cout << *raw_ptr1 << endl;
    cout << *raw_ptr2 << endl;
    */

    /*
    cout << *test1 << endl;
    cout << *test2 << endl;
    */



    return 0;
}
