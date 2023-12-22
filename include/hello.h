#pragma once
#include <iostream>
#include <string>
using namespace std;

class Hello{
public:
    Hello(){}
    ~Hello(){}

    void setName(std::string name);
    std::string getName(void);
private:
    string name;
};
