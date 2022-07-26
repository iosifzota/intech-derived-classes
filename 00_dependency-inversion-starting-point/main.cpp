#include <iostream>

using namespace std;

class ArraySource
{
    int m_val;

public:
    ArraySource() : m_val{ 0 }
    {
        // empty
    }

    bool hasNext()
    {
        return m_val <= 20;
    }
    int getNext()
    {
        return m_val++;
    }
};

class Accumulator
{
private:
    ArraySource * m_arrSrc;

public:
    Accumulator(ArraySource * arrSrc) : m_arrSrc{arrSrc}
    {
        // empty
    }
    
    int execute()
    {
        int sum = 0;
        while (m_arrSrc->hasNext())
        {
            sum += m_arrSrc->getNext();
        }
        return sum;
    }
};

int main()
{
    ArraySource arraySource;
    Accumulator comp{&arraySource};
    cout << "Execution result: " << comp.execute();

    return 0;
}
