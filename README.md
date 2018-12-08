AmNet is a multi-thread http server based on Reactor pattern.
It utils network libs and IO multiplex tech in C++ to provide high performance.

**Feature**

- 使用epoll的LT模式实现非阻塞式的IO复用

- 基于Reactor模式，线程池负责处理IO请求

- 小根堆实现定时管理器，双缓冲机制保证异步日志

- 使用HTTP有限状态机解析HTTP请求，支持HTTP长连接

- HTTP服务器支持URL路由分发以及静态资源访问.

  
