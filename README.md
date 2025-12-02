# 现代CMake模块化项目管理指南

出发点: 基于CMake的C/C++项目, 如何优雅地、模块化地组织大量源文件?

#### 一. CMake项目推荐的目录组织方式

- 项目名/include/项目名/模块名.h
- 项目名/src/模块名.cpp

  ```sh
  [user@ubuntu CMakeProTemplate]$ tree 项目名/
  项目名/
  ├── CMakeLists.txt
  ├── include
  │   └── 项目名
  │       └── 模块名.h
  └── src
      └── 模块名.cpp
  ```

- CMakeLists.txt中写:

  ```cmake
  target_include_directories(项目名 PUBLIC include)
  ```

- 在头文件中(`项目名/include/项目名/模块名.h`)写:

  ```cpp
  #pragma once
  
  namespace 项目名
  {
  void 函数名();
  }
  ```

- 在实现文件中(`项目名/src/模块名.cpp`)写:

  ```cpp
  #include <项目名/模块名.h>
  
  namespace 项目名
  {
  void 函数名()
  {
      // 函数实现
  }
  }
  ```
  
- 使用该模块的源文件`main.cpp`:

  ```cpp
  #include <项目名/模块名.h>
  
  int main(int argc, char **argv)
  {
  	项目名::函数名();
  }
  ```

  

#### 二. 划分子项目

- 大型的项目，往往会划分为几个子项目, 子项目有的是库的形式.

- 一个主要的可执行文件, 类似"前台接待员"的功能, 真正的功能是在其他几个lib库项目中实现的.

- 下图的案例中,  在根目录下, 主项目为`mainproject`, 有两个子项目`biology`和`network`库. 它们分别在各自的目录下都有专属的CMakeLists.txt文件. 在根目录下用主CMakeLists.txt 进行组织.

  ```sh
  .
  ├── biology
  │   ├── CMakeLists.txt
  │   ├── include
  │   │   └── biology
  │   │       ├── Animal.h
  │   │       ├── Cat.h
  │   │       ├── Dog.h
  │   │       └── Mammal.h
  │   └── src
  │       ├── Cat.cpp
  │       ├── Dog.cpp
  │       └── Mammal.cpp
  ├── CMakeLists.txt
  ├── mainproject
  │   ├── CMakeLists.txt
  │   ├── include
  │   │   └── mainproject
  │   │       └── utils.hpp
  │   └── src
  │       └── main.cpp
  ├── network
  │   ├── CMakeLists.txt
  │   ├── include
  │   │   └── network
  │   │       └── socket.h
  │   └── src
  │       └── socket.cpp
  └── README.md
  
  12 directories, 16 files
  ```

#### 三. 根目录的CMakeLists.txt配置

- 在根目录中的CMakeLists.txt中, 设置了默认的构建模式, 设置了C++版本等各种选项, 然后通过project命令初始化根项目.
- 设置静态库/动态库/可执行文件的输出目录.
- 通过`add_subdirectory`把各个子项目添加进来(顺序无关紧要的), 这会调用各个子项目中的CMakeLists.txt.

  ```cmake
  # 设置 CMake 的最低版本要求
  cmake_minimum_required(VERSION 3.20)
  
  # 如果没有指定构建类型，默认设置为 Release
  if (NOT CMAKE_BUILD_TYPE)
      set(CMAKE_BUILD_TYPE Release)
  endif()
  
  # 设置 C++ 标准为 C++17，并强制要求支持 C++17
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON) # 强制要求支持指定的 C++ 标准
  set(CMAKE_CXX_EXTENSIONS OFF)       # 禁用编译器特定扩展，确保代码更具可移植性
  
  # 定义项目名称及支持的语言
  project(SmallDemo LANGUAGES C CXX)
  
  # 设置所有库生成位置无关代码 (Position Independent Code) 对应GCC/Clang的-fPIC
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
  
  # 设置输出目录
  # 静态库输出目录
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/build_output/lib)
  # 动态库输出目录
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/build_output/bin)
  # 可执行文件输出目录
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/build_output/bin)
  
  # 添加子目录
  # 每个子目录对应一个模块
  add_subdirectory(mainproject)
  add_subdirectory(network)
  add_subdirectory(biology)
  ```

### 三. 子项目的CMakeLists.txt配置

- 子项目的CMakeLists.txt就干净许多，只是创建了network这个静态库对象，并通过`GLOB_RECRUSE`分别批量添加了所有位于`include`的头文件和`src`的实现文件。

  ```cmake
  # 设置目标名称为 network
  set(tgt_name network)
  
  # 递归查找头文件，存储在变量 headers 中
  # CONFIGURE_DEPENDS 用于确保当文件系统中匹配的文件发生变化时，会触发重新配置
  file(GLOB_RECURSE headers CONFIGURE_DEPENDS include/*.h include/*.hpp)
  
  # 递归查找源文件，存储在变量 sources 中
  file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.c src/*.cpp src/*.cc src/*.cxx)
  
  # 创建一个名为 ${tgt_name} 的目标库（默认是静态库）
  add_library(${tgt_name})
  
  # 将头文件添加到目标的 PUBLIC 源文件列表中
  # PUBLIC 意味着头文件将对目标的用户可见
  target_sources(${tgt_name} PUBLIC ${headers})
  
  # 将源文件添加到目标的 PRIVATE 源文件列表中
  # PRIVATE 意味着这些文件仅对目标本身可见
  target_sources(${tgt_name} PRIVATE ${sources})
  
  # 指定 include 目录，让目标及其用户能够访问 include 下的头文件
  # PUBLIC 意味着 include 目录会被传播给目标的依赖者
  target_include_directories(${tgt_name} PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
  )
  ```

- 根项目的CMakeLists.txt负责处理全局有效的设定。而子项目的CMakeLists.txt则仅考虑该子项目自身的设定，比如他的头文件目录，要链接的库等等。

  ```cmake
  # 设置目标名称为 mainproject
  set(tgt_name mainproject)
  
  # 递归查找头文件，存储在变量 headers 中
  # CONFIGURE_DEPENDS 用于确保当文件系统中匹配的文件发生变化时，会触发重新配置
  file(GLOB_RECURSE headers CONFIGURE_DEPENDS include/*.h include/*.hpp)
  
  # 递归查找源文件，存储在变量 sources 中
  file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.c src/*.cpp src/*.cc src/*.cxx)
  
  # 创建一个名为 ${tgt_name} 的目标库（默认是静态库）
  add_library(${tgt_name})
  
  # 将头文件添加到目标的 PUBLIC 源文件列表中
  # PUBLIC 意味着头文件将对目标的用户可见
  target_sources(${tgt_name} PUBLIC ${headers})
  
  # 将源文件添加到目标的 PRIVATE 源文件列表中
  # PRIVATE 意味着这些文件仅对目标本身可见
  target_sources(${tgt_name} PRIVATE ${sources})
  
  # 指定 include 目录，让目标及其用户能够访问 include 下的头文件
  # PUBLIC 意味着 include 目录会被传播给目标的依赖者
  target_include_directories(${tgt_name} PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
  )
  
  # 链接biology和network库, 面向目标target
  target_link_libraries(${tgt_name} PRIVATE biology network)
  ```



