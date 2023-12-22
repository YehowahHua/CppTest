#include "unique_ptr_test.h"

/***
 * 智能指针 unique_ptr操作 Integer 对象 
 ***/  
void unique_ptr_test() {
   std::cout << "Creating a unique_ptr that points to an Integer\n";

   // 创建 unique_ptr对象，指向 Integer， 7是构造函数参数
   auto ptr{std::make_unique<Integer>(7)};

   // 使用 unique_ptr 调用对象成员函数
   std::cout << fmt::format("Integer value: {}\n\nMain ends\n",
      ptr->getValue()); // 自动析构
}
