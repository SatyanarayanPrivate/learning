#include<iostream>
using namespace std;

class CA
{
    static int count;
    int x;
public:
    CA()
    {
        count++;
        x = count;
        cout << "Default" << endl;
    }
    CA(CA &ref)
    {
        x = 999;
        cout << "Copy" << endl;
    }
    ~CA()
    {
        cout << "D-tor x=" << x << endl;
    }
};
int CA::count = 0;
CA fun()
{
    CA obj;
    return obj;
}
int main()
{
    CA obj;
    obj = fun();
    
    cout << "Apple" << endl;
    return 0;
}