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

int main()
{
    vector<unique_ptr<Shape>> arr;
    arr.emplace_back(new Triangle);
    arr.emplace_back(new Rectangle);
    arr.emplace_back(new Circle);
    arr.emplace_back(new Triangle);


    for (auto& elem : arr)
    {
        elem->draw();
    }

    cout << "====" << endl;
    
    for_each(arr, arr + size, [](auto& elem) { elem->draw(); } );

    return 0;
}
