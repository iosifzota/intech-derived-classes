#ifndef __LIBRARY1_H__
#define __LIBRARY1_H__

namespace Library1
{
    // This has 10 values: 1, 3, 5, 7, ...
    class FirstNOddNumbers
    {
        int m_val;

    public:
        FirstNOddNumbers();

        bool reachedEnd() const;
        int getNumber();
    };
}
#endif // __LIBRARY1_H__