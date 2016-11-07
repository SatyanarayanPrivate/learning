#include<iostream>
#include <typeinfo>
using namespace std;

class CA
{
public:
void fun()
{
cout<<"fun"<<endl;
}
};
int main()
{
CA obj;
cout << typeid(obj).name() << endl;
return 0;
}