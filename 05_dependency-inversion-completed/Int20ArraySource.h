struct Int20ArraySource
{
private:
    int m_val;

public:
    Int20ArraySource();

    bool hasNext();
    int getNext();
};