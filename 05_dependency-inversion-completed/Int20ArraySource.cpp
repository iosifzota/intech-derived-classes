#include "Int20ArraySource.h"

Int20ArraySource::Int20ArraySource() : m_val{ 0 }
{
    // empty
}

bool Int20ArraySource::hasNext()
{
    return m_val <= 20;
}

int Int20ArraySource::getNext()
{
    return m_val++;
}
