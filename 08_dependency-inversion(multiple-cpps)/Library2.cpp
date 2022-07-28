#include "Library2.hpp"
#include <iostream>

using namespace std;

namespace Library2
{
    ConsoleReader::ConsoleReader() : m_val{1}
    {
        // empty
    }

    bool ConsoleReader::readInt()
    {
        return !!(cin >> m_val); // We use '!' to force the expression to be a boolean expression.
        // Because we negate the expression it means it's doing the oppsite of what we intended so we add another ! to cancel the inital negation. !!0 = 0, !!1 = 1.
    }

    int ConsoleReader::getInt() const
    {
        return m_val;
    }
}
