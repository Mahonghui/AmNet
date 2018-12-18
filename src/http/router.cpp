//
// Created by amisher on 18-12-18.
//

#include "router.h"

Route::RoutePtr Router::NewRoute() {
    auto r = std::make_shared<Route>();
    route_ptrs_.push_back(r);
    return r;
}

Route::Handler Router::Match(const HttpRequest & request, std::unordered_map<std::string, std::string> *dict) {
    for(auto& route_ptr: route_ptrs_){
        if(route_ptr->Match(request,dict)) {
            return route_ptr->GetHandler();
        }
    }
    return nullptr;
}