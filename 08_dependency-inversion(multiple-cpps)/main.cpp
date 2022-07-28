#include <iostream>

using namespace std;

#include "Library1.hpp"
#include "Library2.hpp"

// Our interface for the input source.
struct ArraySource
{
    virtual bool hasNext()  = 0;
    virtual int getNext() = 0;
};


// Inside our code we wrap the input source from the library
// into a class that is implements our interface.
// This is called the "Adapter pattern".
// This is similar to what an adapter does: on our laptops
// we use only the HDMI interface. If the monitor we want to
// connect uses a cable that is VGA then we need an "adapter"
// that makes the link between VGA and HDMI. This is similar
// what we have here: the library did use our interface for
// an input source so we made an adapter from our interface
// to the input source from the library.
class ArraySourceImpl1 : public ArraySource
{
private:
    Library1::FirstNOddNumbers m_oddNumbers;
public:
    
    bool hasNext() override
    {
        return !m_oddNumbers.reachedEnd();
    }

    int getNext() override
    {
        return m_oddNumbers.getNumber();
    }
};

class ArraySourceImpl2 : public ArraySource
{
private:
    Library2::ConsoleReader m_reader;
public:
    
    bool hasNext() override
    {
        return m_reader.readInt();
    }

    int getNext() override
    {
        return m_reader.getInt();
    }
};

class Accumulator
{
private:
    ArraySource *m_arrSrc;

public:
    Accumulator(ArraySource *arrSrc) : m_arrSrc{arrSrc}
    {
        // empty
    }

    void setArraySource(ArraySource *arrSrc)
    {
        m_arrSrc = arrSrc;
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
    ArraySource *arrSrc1 = new ArraySourceImpl1;
    Accumulator comp{arrSrc1};
    cout << "Execution returned: " << comp.execute() << endl;

    ArraySource *arrSrc2 = new ArraySourceImpl2;
    comp.setArraySource(arrSrc2);
    cout << "Execution returned: " << comp.execute() << endl;

    return 0;
}
