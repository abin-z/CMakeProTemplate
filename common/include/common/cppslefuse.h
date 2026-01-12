#pragma once
#include <common/dll_export.h>

#include <string>

/*
 * 如果动态库只是在 C++ 项目中使用，而不需要与其他语言或 C 编译器兼容，那么不需要使用 extern "C"。
 * 你可以充分利用 C++ 的特性，例如函数重载、模板、类、标准库等，以提高代码的灵活性和可维护性。
 * 只要动态库和客户端(调用端)使用相同的 C++ 编译器及其版本，就可以避免 ABI 不一致的问题。
 */

/// @brief 普通的c++类
class DLL_PUBLIC_API Person
{
 public:
  Person() = default;
  explicit Person(std::string name, int age = 18);  // 默认参数
  Person(const Person &) = default;
  Person &operator=(const Person &) = default;
  Person(Person &&) noexcept = default;
  Person &operator=(Person &&) noexcept = default;
  ~Person();

  void say();
  void say(const std::string &str);  // 函数重载

 private:
  std::string name_;
  int age_ = 0;
};

/// @brief 一个普通的C++类, 使用 PImpl（Pointer to Implementation） 模式隐藏实现细节，同时确保动态库接口的 ABI 稳定性
class DLL_PUBLIC_API MyClass
{
 public:
  MyClass();   // 构造函数
  ~MyClass();  // 析构函数

  MyClass(const MyClass &) = delete;             // 禁用拷贝构造函数
  MyClass &operator=(const MyClass &) = delete;  // 禁用拷贝赋值运算符

  MyClass(MyClass &&other) noexcept;             // 移动构造
  MyClass &operator=(MyClass &&other) noexcept;  // 移动赋值

  void doSomething();  // 对外提供的接口

 private:
  struct Impl;  // 前向声明实现结构体
  Impl *impl_;  // 使用指针指向实现部分, 可使用std::unique_ptr<Impl>
};