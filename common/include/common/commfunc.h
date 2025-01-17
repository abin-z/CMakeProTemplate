#pragma once

#ifdef _WIN32
// Windows 系统
#ifdef DLL_PUBLIC_EXPORTS
#define DLL_PUBLIC_API __declspec(dllexport) // 导出符号
#else
#define DLL_PUBLIC_API __declspec(dllimport) // 导入符号
#endif
#elif defined(__GNUC__) || defined(__clang__)
// GCC 或 Clang 编译器
#define DLL_PUBLIC_API __attribute__((visibility("default"))) // 使用默认可见性，适用于Linux、macOS等
#else
// 默认情况，假定没有特殊的导入导出要求
#define DLL_PUBLIC_API
#endif

#ifdef __cplusplus
extern "C"
{
#endif

  /// 可选：如果需要显式的内存对齐控制，可以使用 #pragma pack 或 __attribute__((packed))
  /// 如果不需要，可以去掉这些指令。
  struct point_t
  {
    double x;
    double y;
    double z;
  };

  struct parameter_t
  {
    int num;
    point_t point;
  };

  DLL_PUBLIC_API void say_hello();
  DLL_PUBLIC_API int add(int a, int b);

  DLL_PUBLIC_API point_t getPoint();
  DLL_PUBLIC_API void printPoint(point_t arg);

  DLL_PUBLIC_API parameter_t getParam();
  DLL_PUBLIC_API void printParam(parameter_t arg);

#ifdef __cplusplus
}
#endif