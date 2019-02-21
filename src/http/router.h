//
// Created by amisher on 18-12-18.
//

#ifndef AMNET_ROUTER_H
#define AMNET_ROUTER_H

#include "route.h"

// router 下分多个 route
class Router{
public:
    Router()= default;
    ~Router() = default;
    // 返回新的子路由
    Route::RoutePtr NewRoute();
    // 遍历所有路由是否匹配
    Route::Handler Match(const HttpRequest&, std::unordered_map<std::string, std::string>* dict);
private:
    // 所有子路由
    std::vector<Route::RoutePtr> route_ptrs_;
};
#endif //AMNET_ROUTER_H
