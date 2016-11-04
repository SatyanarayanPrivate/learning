#include <iostream>
using namespace std;

class CA {
public:
    int i;
    const int iConst; 
    static int iStatic;
    
    CA(): i(100), iConst(200)
    {
        //iConst = 23;    // compiler error: accessing read only member
    }    
    void Display () const {
        //iConst = 29;  // compiler error: accessing read only member
        iStatic = 302;
        cout << "iConst = " << iConst << endl; 
        cout << "iStatic = " << iStatic << endl; 
    }
};

//if not initiazed compiler error:: undefined reference to `CA::iStatic' be generated
int CA::iStatic = 300;
//int CA::iStatic = 304; // compiler error:: redefinition

int main() {
    //int CA::iStatic = 300;  //compiler error: as static variables must initiazed at global scope
    int var;
    int *ptr = NULL;
    CA obj;
    
    /*Const member*/
    //obj.iConst = 10;      // compiler error: modifying read only member
    var = obj.iConst;
    //ptr = &obj.iConst;
    //*ptr = 101;             // compiler error: invalid conversion from ‘const int*’ to ‘int*’
    ptr = (int *)&obj.iConst; // forcefully modifying
    *ptr = 102;
    
    obj.iStatic = 301; // static varible can be accessed outside class
    obj.Display();
    
}
