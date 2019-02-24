AmNet 是一个基于 Reactor 事件驱动模型的网络库。
它使用 IO 复用技术提供高效的网络连接管理。



**Feature**

- 使用epoll的LT模式实现非阻塞式的IO复用

- 基于Reactor模式，线程池负责处理IO请求

- 简单应用 std::thread 库和 std::chrono 库

- 使用智能指针和 RAII 机制管理生命周期

- HTTP服务器支持URL路由分发以及静态资源访问.

  
