#pragma once
#include <biology/Mammal.h>

namespace biology
{
/// @brief 狗类
class Dog : public Mammal
{
 public:
  Dog() = default;
  ~Dog() = default;
  void makeSound() const override;
  const char *getType() const override;
};
}  // namespace biology