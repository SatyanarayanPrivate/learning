#include<iostream>
using namespace std;

class Circle
{
public:
	virtual void DrawCircle() = 0;
	virtual void CircleArea() = 0;
};

class Rectangle
{
public:
	virtual void DrawRectangle() = 0;
	virtual void RectangleArea() = 0;
};

class Shape : public Circle, public Rectangle
{
public:
    virtual void DrawCircle()
    {
        cout << "Circle Drawn" << endl;
    }
    virtual void CircleArea()
    {
        cout << "Circle Area" << endl;
    }
    virtual void DrawRectangle()
    {
        cout << "Rectangle Drawn" << endl;
    }
    virtual void RectangleArea()
    {
        cout << "Rectangle Area" << endl;
    }
};
int main1()
{
    Circle *circle = new Shape();
    long *vp2 = (long*)circle;
    long *vt = (long*)*(vp2 + 1);
    cout << "CB::vftable = " << *vp2 << endl;
    ((void(*)())vt[1])();

    circle->DrawCircle();
    circle->CircleArea();

    Rectangle *rect = (Rectangle*)circle;
    rect->DrawRectangle();  // circle methods gets called
    rect->RectangleArea();
    
    return 0;
}

int main2()
{
    Circle *circle = new Shape();
    circle->DrawCircle();
    circle->CircleArea();

    //Rectangle *rect = (Rectangle*)(Shape*)circle;
    //Rectangle *rect = (Shape*)circle;	// bcz of LSP
    Rectangle *rect = dynamic_cast<Rectangle*>(circle);	// dynamic cast only for polymorpic type, return null if fail
    rect->DrawRectangle();  // rectangle methods gets called
    rect->RectangleArea();

    return 0;
}
int main3()
{
    char *s = "India is Great !!!!";
    int *i = reinterpret_cast<int*> (s);	// forced cast
    cout << (char *)i << endl;
    
    return 0;
}

int main4()
{
    short i = 10;
    double d = static_cast <double> (i); // itermediate casting is supressed
    
    return 0;
}

void fun(const int *ptr)
{
    //*ptr = 1000;
    int *pt = const_cast<int*>(ptr);
    *pt = 1000;
}

int main()
{
    int i = 10;
    fun(&i);
    cout << "i= " << i << endl;
    
    return 0;
}