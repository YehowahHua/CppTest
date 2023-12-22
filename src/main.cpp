#include <iostream>
#include "hello.h"

using namespace std;

int main(){
    string hello = "hua";
    Hello ye{};
    
    ye.setName(hello);
    cout <<"hello world name=" << ye.getName() << endl;
    cout << hello<<".\n";
}
