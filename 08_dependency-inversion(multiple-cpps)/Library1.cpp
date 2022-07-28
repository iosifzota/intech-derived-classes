#include "Library1.hpp"

namespace Library1
{
    FirstNOddNumbers::FirstNOddNumbers() : m_val{1}
    {
        // empty
    }

    bool FirstNOddNumbers::reachedEnd() const
    {
        return m_val > 20;
    }

    int FirstNOddNumbers::getNumber()
    {
        int tmp = m_val;
        
        if (!reachedEnd())
        {
            m_val += 2;
        }
        return tmp;
    }
}