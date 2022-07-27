#include <iostream>
#include "Accumulator.h"
#include "Int20ArraySource.h"

using namespace std;

struct ArraySourceImpl : ArraySource
{   
private:
    bool hasNext() override
    {
        return m_src.hasNext();
    }
    int getNext() override
    {
        return m_src.getNext();
    }

    Int20ArraySource m_src;
};

struct ArraySourceImpl2 : ArraySource
{
    bool hasNext() override
    {
        return (cin >> m_val).good();
    }
    int getNext() override
    {
        return m_val;
    }

private:
    int m_val;
};

int main()
{
    ArraySource * arraySource = new ArraySourceImpl;

    Accumulator comp{arraySource};
    cout << "Execution result: " << comp.execute();

    comp.setArraySource(new ArraySourceImpl2);
    cout << "Execution result: " << comp.execute();

    return 0;
}
