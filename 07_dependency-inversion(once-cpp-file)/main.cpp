#include <iostream>

using namespace std;

struct ArraySource
{
    virtual bool hasNext() = 0;
    virtual int getNext() = 0;
};

// This has 10 values: 1, 3, 5, 7, ...
// This is a class implemented to be able
// to test the Accumulator. So it's a dummy
// implementation but enables us to test
// the code seperatly from any library dependency.
class ArraySourceMock2 : public ArraySource
{
    int m_val;

public:
    ArraySourceMock2() : m_val{1}
    {
        // empty
    }

    bool hasNext() override
    {
        return m_val < 20;
    }

    int getNext() override
    {
        int tmp = m_val;
        m_val += 2;
        return tmp;
    }
};

// This has 20 values: 0, 1, 2, 3, 4
// This is a class implemented to be able
// to test the Accumulator. So it's a dummy
// implementation but enables us to test
// the code seperatly from any library dependency.
class ArraySourceMock1 : public ArraySource
{
private:
    int m_val;

public:
    ArraySourceMock1() : m_val{1}
    {
        // empty
    }

    bool hasNext() override
    {
        return m_val <= 20;
    }

    int getNext() override
    {
        return m_val++;
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

// Imagine ConsoleReader is from a library
class ConsoleReader
{
private:
    int m_val;
    
public:
    bool readInt()
    {
        return !!(cin >> m_val);
    }
    
    int getInt() const
    {
        return m_val;
    }
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
    ConsoleReader m_reader;
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

int main()
{
    ArraySource *arrSrc1 = new ArraySourceMock1();
    Accumulator comp{arrSrc1};
    cout << "Mock execution returned: " << comp.execute() << endl;

    ArraySource *arrSrc2 = new ArraySourceMock2();
    comp.setArraySource(arrSrc2);
    cout << "Mock execution returned: " << comp.execute() << endl;
    
    ArraySource *arrSrc3 = new ArraySourceImpl1();
    comp.setArraySource(arrSrc3);
    cout << "Real input execution returned: " << comp.execute() << endl;

    return 0;
}