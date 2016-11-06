#include<iostream>
using namespace std;

class CA
{
public:
    CA() {
        fun();
    }
    ~CA() {
        fun();
    }
    virtual void fun() {
        cout<<"fun ca"<<endl;
    }
};
class CB:public CA {
public:
    void fun() {
    cout<<"fun cb"<<endl;
    }
};
int main() {
    CB obj;
    obj.fun();
    return 0;
}