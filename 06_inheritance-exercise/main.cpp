#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>


using namespace std;

struct Shape
{
    void draw()
    {
        this->drawImpl();
    }

private:
    virtual void drawImpl() = 0;
};

struct Circle : Shape
{

private:
    void drawImpl() override
    {
        cout << "Circle::draw()" << endl;
    }
};

struct Rectangle : Shape
{

private:
    void drawImpl() override
    {
        cout << "Rectangle::draw()" << endl;
    }
};

struct Triangle : Shape
{

private:
    void drawImpl() override
    {
        cout << "Triangle::draw()" << endl;
    }
};

void testUniquePtr()
{
    cout << "# testUniquePtr()" << endl;
    unique_ptr<Shape> arr[] = {
        unique_ptr<Shape>{new Triangle}
        ,unique_ptr<Shape>{new Rectangle}
        ,unique_ptr<Shape>{new Circle}
        ,unique_ptr<Shape>{new Triangle}
        };

    for (auto& elem : arr)
    {
        elem->draw();
    }

    cout << "====" << endl;
    
    for_each(begin(arr), end(arr), [](auto& elem) { elem->draw(); } );
}

void testNormalPtr()
{
    cout << "# testNormalPtr()" << endl;
    Shape* arr[] = {
        new Triangle
        ,new Rectangle
        ,new Circle
        ,new Triangle
        };

    for (auto& elem : arr)
    {
        elem->draw();
    }

    cout << "====" << endl;
    
    for_each(begin(arr), end(arr), [](auto& elem) { elem->draw(); } );
}

int main()
{
    testNormalPtr();
    cout << "====" << endl;
    cout << "----" << endl;
    cout << "====" << endl;
    testUniquePtr();

    return 0;
}