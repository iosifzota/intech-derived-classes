#include "Accumulator.h"

Accumulator::Accumulator(ArraySource * arrSrc) : m_arrSrc{arrSrc}
{
    // empty
}

int Accumulator::execute()
{
    int sum = 0;
    while (m_arrSrc->hasNext())
    {
        sum += m_arrSrc->getNext();
    }
    return sum;
}

