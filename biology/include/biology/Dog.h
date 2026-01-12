#pragma once
#include <biology/Mammal.h>

namespace biology
{
/// @brief 狗类
class Dog : public Mammal
{
 public:
  Dog() = default;
  ~Dog() override = default;
  void makeSound() const override;
  [[nodiscard]] const char *getType() const override;
};
}  // namespace biology