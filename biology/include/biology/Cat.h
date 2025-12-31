#pragma once
#include <biology/Mammal.h>

namespace biology
{
/// @brief 猫类
class Cat : public Mammal
{
 public:
  Cat() = default;
  ~Cat() = default;
  void makeSound() const override;
  const char *getType() const override;
};
}  // namespace biology