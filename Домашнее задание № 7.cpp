#include <iostream>
#include <exception>
#include "Container.h"
using namespace std;

int main()
{	
    try 
    {
        IntArray array(10);

        for (int i = 0; i < array.getLength(); ++i)
        {
           array[i] = i + 2;
        }

        array.remove(2);
        array.insertAtBeginning(3);
        array.resize(7);
        array.insertAtEnd(5);
           

        for (int i = 0; i < array.getLength(); ++i)
        {
            cout << array[i] << ' ' << endl;
        }

    }

    catch (...)
    {
        cout << "bad range " << endl;
    }

    return 0;
}