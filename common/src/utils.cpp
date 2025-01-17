#include <common/utils.h>
#include <cmath>

DLL_PUBLIC_API double mysqrt(double val)
{
  return std::sqrt(val);
}

DLL_PUBLIC_API double mypow(double base, double exponent)
{
  return std::pow(base, exponent);
}