#include<iostream>
using namespace std;

namespace {
    int i= 200;
}
namespace {
    int i= 200;     //redefination error
    int j= 200;
}

int main() {
    cout<<i<<endl;
    return 0;
}