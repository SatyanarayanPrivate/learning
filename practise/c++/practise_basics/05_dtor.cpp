#include<iostream>
using namespace std;

class CA {
    static int count;
    int x;
public:
    int val;
    CA()
    {
        count++;
        x = count;
        val  = 0x00;
        cout << "CA default ctor" << endl;
    }
    CA (int val): val (val) {
        count++;
        x = count;
        cout << "CA one param ctor" << endl;
    }
    CA(const CA &ref) {
        x = 111;
        cout << "CA Ctor Copy" << endl;
    }

    ~CA() {
        cout << "Dtor x= " << x << " val= "<< val << endl;
    }
};

int CA::count = 0x00;

void fun() {
    CA obj1;
    cout << "orange11" << endl;
}

CA fun1(void)
{
    CA obj;
    cout << "orange" << endl;
    return obj;
}

int main1() {
    CA obj1;
    fun();
    cout << "Apple" << endl;
    return 0;
}

int main2() {
    CA obj1 = fun1();   // copy ctor not defined this statement gives compiler error
    CA obj2(obj1);      // call to copy ctor
    cout << "Apple" << endl;
    return 0;
}

#if 1
// order of global ctor/ dtor is order of declairation.
static CA obj2(12);
CA obj1(11);

void fun2()
{
    static CA obj3(13);
    CA obj4;
    cout << "orange" << endl;
}

int main()
{
    fun2();
    CA *obj5 = new CA();

    delete obj5;
    cout << "Apple" << endl;
    return 0;
}
// 1st fun static obj's dtor gets called then global obj's
#endif

#if 0
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
#endif