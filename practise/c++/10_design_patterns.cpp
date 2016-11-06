#include<iostream>
using namespace std;

// 23 classical methos(design patterns)
// dofactory.com// for design patterns
// ivar jacobson:: patterns
// grady booch
// GRASP:: principles
//kent beck
//martin fowler

#if 0
// template method
class Bank
{
public:
    void Dojob()
    {
        cout << "open db" << endl;
        DoDelayedJod();
        cout << "close db" << endl;
    }
protected:
    // interface:: class includes only pure functions
    // abstract class:: pure function with other methods
    virtual void DoDelayedJod() = 0;
};

class SbAccount : public Bank
{
public:
protected:
    void DoDelayedJod()
    {
        cout << "Perform Sb account job" << endl;

    }
};

class CurrentAccount : public Bank
{
public:
protected:
    void DoDelayedJod()
    {
        cout << "Perform Current account job" << endl;
    }
};

int main()
{
    SbAccount obj;
    obj.Dojob();
    cout << "---------------------------------------------------------------------" << endl;
    CurrentAccount obj1;
    obj1.Dojob();
    cout << "---------------------------------------------------------------------" << endl;
    
    return 0;
}
#endif

#if 1

#endif