AmNet 是一个基于 Reactor 事件驱动模型的网络库。
它使用 IO 复用技术提供高效的网络连接管理。

架构借鉴 muduo 网络库

**Feature**

- 使用epoll的LT模式实现非阻塞式的IO复用

- 基于Reactor模式，线程池负责处理IO请求

- 小根堆实现定时管理器，双缓冲机制保证异步日志

- 解析HTTP请求，支持HTTP长连接

- HTTP服务器支持URL路由分发以及静态资源访问.

  
