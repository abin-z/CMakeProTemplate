#pragma once
#include <biology/Mammal.h>

namespace biology
{
/// @brief 猫类
class Cat : public Mammal
{
 public:
  Cat() = default;
  ~Cat() override = default;
  void makeSound() const override;
  [[nodiscard]] const char *getType() const override;
};
}  // namespace biology