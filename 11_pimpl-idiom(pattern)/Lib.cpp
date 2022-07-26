#include "Lib.h"
#include <iostream>

using namespace std;

void foo(char)
{
    cout << "foo(char)" << endl;
}

static void foo(float)
{
    cout << "foo(float)" << endl;
}