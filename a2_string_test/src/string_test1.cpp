#include "string_test1.h"



void string_test1(){
    std::string s1{"happy"}; // 初始化string
    std::string s2{" birthday"}; 
    std::string s3; 
    std::string_view v{"hello"}; // 使用 string_view 初始化字符串

    std::cout << "s1: \"" << s1 << "\"; s2: \"" << s2 << "\"; s3: \"" << s3 << "\"; v: \"" << v << "\"\n\n";

    // 比较字符串
    std::cout << "The results of comparing s2 and s1:\n"
        << fmt::format("s2 == s1: {}\n", s2 == s1) //false
        << fmt::format("s2 != s1: {}\n", s2 != s1) //true
        << fmt::format("s2 > s1: {}\n", s2 > s1) //false
        << fmt::format("s2 < s1: {}\n", s2 < s1) //true
        << fmt::format("s2 >= s1: {}\n", s2 >= s1) //false
        << fmt::format("s2 <= s1: {}\n\n", s2 <= s1); //true

    std::cout << "Testing s3.empty():\n";
    //测试 空 empty
    if (s3.empty()) {
        std::cout << "s3 is empty; assigning s1 to s3;\n";
        s3 = s1; // assign s1 to s3
        std::cout << fmt::format("s3 is \"{}\"\n\n", s3);
    }

    // 连接字符串
    s1 += s2; 
    std::cout << fmt::format("s1 += s2 yields s1 = {}\n\n", s1);//happy birthday

    s1 += " to you";
    std::cout << fmt::format("s1 += \" to you\" yields s1 = {}\n\n", s1);//happy birthday to you

    // 使用 C++14 string-object literal 连接字符串，累加
    using namespace std::string_literals;
    s1 += ", have a great day!"s; // 需要添加s
    std::cout << fmt::format("s1 += \", have a great day!\"s yields\ns1 = {}\n\n", s1);//happy birthday to you, have a great day!

    // 测试子串 substr
    std::cout << fmt::format("{} {}\n{}\n\n",
        "The substring of s1 starting at location 0 for",
        "14 characters, s1.substr(0, 14), is:", s1.substr(0, 14));//happy birthday

    // 测试最后
    std::cout << fmt::format("{} {}\n{}\n\n",
        "The substring of s1 starting at",
        "location 15, s1.substr(15), is:", s1.substr(15));//to you, have a great day!

    //  copy 构造
    std::string s4{s1};
    std::cout << fmt::format("s4 = {}\n\n", s4);

    // 赋值
    std::cout << "assigning s4 to s4\n";
    s4 = s4;
    std::cout << fmt::format("s4 = {}\n\n", s4);

    // string_view 构造string类型
    std::cout << "initializing s5 with string_view v\n";
    std::string s5{v};
    std::cout << fmt::format("s5 is {}\n\n", s5);//hello

    // 某位赋值
    s1[0] = 'H';
    s1[6] = 'B';
    std::cout << fmt::format("{}:\n{}\n\n",
        "after s1[0] = 'H' and s1[6] = 'B', s1 is", s1);//Happy Birthday to you, have a great day!

    // 索引 "at"   
    try {
        std::cout << "Attempt to assign 'd' to s1.at(100) yields:\n";
        s1.at(100) = 'd'; // ERROR: subscript out of range            
    }
    catch (const std::out_of_range& ex) {
        std::cout << fmt::format("An exception occurred: {}\n", ex.what());//basic_string::at: __n (which is 100) >= this->size() (which is 40)
    }
}