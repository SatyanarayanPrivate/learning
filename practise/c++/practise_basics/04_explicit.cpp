#include<iostream>
using namespace std;

class CA {
    int x;
    int y;
public:
    CA() : x(10), y(20)
    {
        cout << "Default Ctor" << endl;
    }

    // to avoid reallocation of resources
    // to supress casting and allows only one parameter ctor
    explicit CA(int val) : x(val), y(val)
    {
        cout << "One parameter Ctor" << endl;
    }

    explicit CA(int val1, int val2) : x(val1), y(val2)	// explicit for multi parameter is feature of C++11
    {
        cout << "Multi parameter Ctor" << endl;
    }
    // expenssive, to copy state of one object to other
    CA(CA & obj2Copy) : x(obj2Copy.x), y(obj2Copy.y)
    {
        cout << "Copy Ctor" << endl;
    }
    void Display() {
        cout << "x=" << x << endl;
        cout << "y=" << y << endl;
        cout << "-------------------------------------------" << endl << endl;
    }
};

int main()
{
    //default Ctor
    CA obj1;
    obj1.Display();

    //one param Ctor
    //explicit Ctor
    CA obj2(300);
    //CA obj2 = 200; // casting
    obj2.Display();
    //obj2 = 300;	// casting
    //obj2.Display();

    // multi param ctor
    CA obj3(120, 212);
    //CA obj3 = {120, 458}; // C++ comma operator plays role/ won't work with explicit
    obj3.Display();

    // copy ctor
    CA obj4(obj2);
    obj4.Display();
    
    return 0;
}

#if 0
class CA
{
    int x;
    int y;
public:
    CA() :x(10), y(20)
    {
    }
    explicit operator int()  //c++11
    {
        cout << "Casting works" << endl;
        return x + y;
    }
    void Disp()
    {
        cout << "x=" << x << "\ny=" << y << endl;
    }
};

void fun(int v)
{
    cout << "Apple" << endl;
    cout << "v=" << v << endl;
    cout << "Orange" << endl;
}
void fun1(CA & obj1)
{
    cout << "Apple11" << endl;
    cout << "v=" << (int)obj1 << endl;
    cout << "Orange22" << endl;
}
int  main()
{
    CA obj1;
    //int g = obj1.operator int();
    //int g = obj1;     // compiler error: can't convert CA to int
    int g = (int)obj1;
    //int b = (char)obj1; // compiler error: can't convert CA to char casting operator is not defined
    obj1.Disp();
    cout << "g=" << g << endl;
    fun(100);
    cout << "______________________" << endl;
    fun((int)obj1);
    cout << "______________________" << endl;
    
    return 0;
}
#endif

#if 0 
class Rect;
class Polar
{
    double angle;
    double dist;
public:
    Polar(double angle, double dist) :angle(angle), dist(dist)
    {
    }
    operator Rect();
};
class Rect
{
    double xCor;
    double yCor;
public:
    Rect(double xCor, double yCor) :xCor(xCor), yCor(yCor)
    {
    }
    Rect() :xCor(0.0), yCor(0.0)
    {
    }
    friend ostream & operator<<(ostream & os, Rect &rect)
    {
        os << "x=" << rect.xCor << " and y=" << rect.yCor << endl;
        return os;
    }
};
Polar::operator Rect()
{
    Rect temp;// (10.0, 20.0);
    return temp;
}

int main()
{
    Polar p(3.14 / 2.0, 15.0);
    Rect r;
    r = p;
    cout << r << endl;
    
    return 0;
}
#endif

