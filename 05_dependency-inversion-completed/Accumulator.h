#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

struct ArraySource
{
    virtual bool hasNext() = 0;
    virtual int getNext() = 0;
};

class Accumulator
{
private:
    ArraySource * m_arrSrc;
public:
    Accumulator(ArraySource * arrSrc);    
    int execute();
    void setArraySource(ArraySource * arrSrc)
    {
        m_arrSrc = arrSrc;
    }
};

#endif