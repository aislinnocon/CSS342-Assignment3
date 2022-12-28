#include <iostream>
#include <string>
#include "child.h"
using namespace std;

int main()
{
    Child one("zmu", "zzacman", 34);
    Child two("timothy", "grandor", 567);
    Child three("lady", "crestfallen", 9);
    Child four("lady", "crestfallen", 9);
    Child five("ace", "zebrea", 77);

    if (one > five)
    {
        cout << "true" << endl;
    }
    else 
    {
        cout << "you're a failure" << endl;
    }
    cout << three << endl;
    cout << five << endl;
    three += five; 
    cout << three << endl;
    cout << five << endl;
}