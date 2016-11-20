#include<iostream>
using namespace std;

#if 0
class CA
{
public:
    CA()
    {
        cout << "Default" << endl;
    }
    ~CA()
    {
        cout << "D-tor " << endl;
        delete this;
        /*
        call dtor
        free()
        */
    }
};

int main()
{
    CA *obj5 = new CA();
    /*
    1) allot memory(malloc)
    2) call ctor
    */

    delete obj5;
    /*
    call dtor
    free()
    */
    
    return 0;
}
#endif 

#if 0
//Overloading global new & delete
void* operator new(size_t sz) {
    void* m = malloc(sz);
    if(!m)
    cout<<"out of memory"<<endl;
    return m;
}
void operator delete(void* m) {
    free(m);
}
int main() {
    int* p = new int(47);
    delete p;
    CA* pobj = new CA;
    delete pobj;
    CA* obj = new CA[3];
    delete []obj;
}
#endif

#if 0
// Overloading new & delete for a class
class CA
{
public:
    static void * operator new( unsigned int cb ) {
        return malloc(cb);
    }
    static void operator delete(void * obj) {
        free(obj);
    }
};
void main() {
    CA *obj = new CA;
    delete obj;
}
// The static keyword is optional for new & delete operators. when you overload new and delete for a class, you’re creating static member functions.
#endif

#if 0
//Overloading new & delete for arrays
class CA {
public:
    void * operator new[]( unsigned int cb ) {
        cout<<"n[]"<<endl;
        return ::new char[cb];
    }

    void operator delete[](void * obj) {
        cout<<"d[]"<<endl;
        ::delete []obj;
    }
};
void main() {
    CA *obj = new CA[10];
    delete []obj;
}
#endif

#if 1
class CA
{
public:
    CA()
    {
        cout << "CA Default Ctor= " << this << endl;
    }
    ~CA() {
        cout << "Dtor CA= " << this << endl;
    }
};

int main1() {
    // allocate memory on heap
    CA *ptr = new CA();
    cout << "ptr= " << ptr << endl;

    // release memory
    delete ptr;
    return 0;
}

int main2() {
    // alloc array of object
    CA *ptr = new CA[5];
    cout << "______________________________" << endl;
    // release
    delete[] ptr;
    return 0;
}
int main3()
{
    // incorrect way
    CA *ptr = new CA();
    if (ptr != NULL)
    {
        delete ptr;	// need to handle exceptions as new returns bad_alloc on error
    }
    return 0;
}

int main4()
{
    try
    {
        CA *ptr = new CA();
        if (ptr != NULL)
        {
            delete ptr;	// need to handle exceptions as new returns bad_alloc on error
        }
    }
    catch (bad_alloc & bad)
    {
        cout << bad.what() << endl;
    }

    // OR
    CA *ptr = new(nothrow) CA();
    if (ptr != NULL)
    {
        delete ptr;	// need to handle exceptions as new returns bad_alloc on error
    }
    return 0;
}

int main() {
    int *buffer = new int[255];
    cout << "buffer = " << buffer << endl;

    CA *ptr = new(buffer) CA();
    CA *ptr1 = new(buffer + 1) CA();
    CA *ptr2 = new(buffer + 5) CA();
    //dtor has to be called explicitly
    ptr->CA::~CA();
    ptr1->CA::~CA();
    ptr2->CA::~CA();

    delete[] buffer;
    return 0;
}
#endif