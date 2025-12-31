#pragma once
#include <biology/Animal.h>

namespace biology
{
/// @brief  哺乳动物类
class Mammal : public Animal
{
 public:
  void move() const override;
};
}  // namespace biology