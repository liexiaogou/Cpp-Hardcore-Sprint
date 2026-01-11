# Tesla Learning Path - C++ Sprint

这是我在休学期间冲击特斯拉工程职位的 9 个月自学记录。

## 🚀 已完成里程碑 (Week 1-2)
- **环境搭建**: 基于 WSL2 + CMake 的 Linux 工业级开发环境。
- **内存管理**: 深入理解指针、引用及堆内存分配（new/delete）。
- **现代 C++**: 引入 `std::unique_ptr` 智能指针，实现零内存泄漏。
- **系统架构**: 
  - 设计了 `TeslaCar` 基类及其派生类 `CyberTruck`。
  - 实现了基于**多态**的自动驾驶感知与决策逻辑（紧急制动系统）。
  - 使用 `std::vector` 实现多车辆并发管理。

## 🛠️ 如何编译
mkdir build && cd build
cmake ..
make
