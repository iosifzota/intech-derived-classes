#ifndef __LIBRARY2_H__
#define __LIBRARY2_H__

namespace Library2
{
    class ConsoleReader
    {
    private:
        int m_val;

    public:
        ConsoleReader();

        bool readInt();
        int getInt() const;
    };
}

#endif // __LIBRARY2_H__