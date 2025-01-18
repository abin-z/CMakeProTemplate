#include <common/cppslefuse.h>
#include <iostream>

/// Person类
Person::Person(std::string name, int age) : name_(name), age_(age)
{
  std::cout << "Person::Person(std::string name, int age) called." << std::endl;
}

Person::~Person()
{
  std::cout << "Person::~Person() called." << std::endl;
}

void Person::say()
{
  std::cout << name_ << ": hello! I`am " << std::to_string(age_) << " years old." << std::endl;
}

void Person::say(const std::string str)
{
  std::cout << name_ << ": " << str << std::endl;
}

// MyClass类, 使用了PImpl（Pointer to Implementation） 模式隐藏实现细节
/// @brief 具体的实现类, 在头文件中不可见.
struct MyClass::Impl
{
  void doSomethingInternal()
  {
    std::cout << "Hello from MyClass::Impl!" << std::endl;
  }
};

MyClass::MyClass() : impl_(new Impl{}) // 构造时分配实现对象
{
  std::cout << "MyClass::MyClass() called." << std::endl;
}

MyClass::~MyClass()
{
  delete impl_; // 析构时释放内存
  std::cout << "MyClass::~MyClass() called." << std::endl;
}

void MyClass::doSomething()
{
  impl_->doSomethingInternal(); // 调用实现方法
}
