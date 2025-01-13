#pragma once

namespace biology
{
  /// @brief 动物类
  class Animal
  {
    public:
    virtual ~Animal() = default;

    // 基础方法（纯虚函数）
    virtual void makeSound() const = 0;       // 发出声音
    virtual void move() const = 0;            // 移动方式

    // 通用属性
    virtual const char* getType() const = 0;  // 获取动物类型
  };
}