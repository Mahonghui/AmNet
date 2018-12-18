//
// Created by amisher on 18-12-17.
//

#ifndef AMNET_ROUTE_H
#define AMNET_ROUTE_H

#include <functional>
#include <memory>
#include <vector>
#include "matcher.h"
#include "httpresponse.h"

class Route:public std::enable_shared_from_this<Route>{
public:
    using  Handler = std::function<void(const HttpRequest&, std::unordered_map<std::string, std::string>&, HttpResponse*)>;
    using RoutePtr = std::shared_ptr<Route>;

    Route()= default;
    ~Route() = default;

    bool AddRegex(std::string& pattern, Matcher::RegexType type, std::string key = "");

    RoutePtr SetMethodPattern(std::string& pattern);
    RoutePtr SetURLPattern(std::string& pattern);
    RoutePtr SetPreifxPattern(std::string& pattern);
    RoutePtr SetHeaderPattern(std::string& key, std::string& value);
    RoutePtr SetQueryPattern(std::string& key, std::string& value);

    RoutePtr SetHandler(Handler& handler);
    Handler GetHandler () const { return handler_;}

    bool Match(const HttpRequest& request, std::unordered_map<std::string, std::string>* dict);

private:
    Handler handler_;
    std::vector<Matcher> matchers_;
};

#endif //AMNET_ROUTE_H
