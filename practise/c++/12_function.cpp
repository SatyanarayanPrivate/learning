#include<iostream>
using namespace std;

//1.naming convention
//2.return type
//3.calling convention
//4.name
//5.arguement
//6.exception list
//7.prolog
//8.Body
//9.epilog
/*extern "C" void __stdcall fun(int x, int y) throw(int,float)
{
//body
}*/

void fun()//?fun@@YAXXZ				
{
}
void fun(int)//?fun@@YAXH@Z
{
}
extern "C" void fun1()//_fun1
{
}
extern "C++" void fun2()//
{
}
int main1()
{
    fun2();//call	?fun2@@YAXXZ
    fun();//call	?fun@@YAXXZ
    fun(10);//call	?fun@@YAXH@Z
    fun1();//call	_fun1
    return 0;
}


void AddFun(int x, int y)
{
}//ret	0
void __cdecl AddFun1(int x, int y)
{
}//ret	0
void __stdcall AddFun2(int x, int y)
{
}//ret	8
void __fastcall AddFun3(int x, int y)
{
}//ret	0

class CA
{
public:
    void __thiscall AddFun4(int x, int y)
    {
    }
};
int main2()
{
    AddFun(10, 20);
    /*
    push	20					; 00000014H
    push	10					; 0000000aH
    call	?AddFun@@YAXHH@Z			; AddFun
    add	esp, 8
    */
    AddFun1(1, 2);
    /*
    push	2
    push	1
    call	?AddFun1@@YAXHH@Z			; AddFun1
    add	esp, 8
    */
    AddFun2(11, 22);
    /*
    push	22					; 00000016H
    push	11					; 0000000bH
    call	?AddFun2@@YGXHH@Z			; AddFun2
    */
    AddFun3(1, 2);
    /*
    mov	edx, 2
    mov	ecx, 1
    call	?AddFun3@@YIXHH@Z			; AddFun3
    */
    CA obj;
    obj.AddFun4(1, 2);

    return 0;
}

/*
void myFun(int,int,int=333);
void myFun(int, int=222, int);
void myFun(int=111, int , int);*/

void myFun(int x = 111, int y = 222, int z = 333)
{
    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    cout << "z=" << z << endl;
    cout << "_______________" << endl;
}
int main()
{
    myFun(1, 2, 3);
    myFun(11, 22);
    myFun(11);
    myFun();
    return 0;
}