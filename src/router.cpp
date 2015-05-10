// The MIT License (MIT)
//
// Copyright (c) 2015 Jeremy Letang
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "cppful/router.h"

namespace cf {

const std::string router::var_regex = "([-_a-zA-Z0-9]*)";
const std::string router::wildcard_regex = "[-_a-z0-9A-Z]*";
const std::string router::two_wildcard_regex = "[/-_a-z0-9A-Z]*";

router::router(router&& oth)
: routes(std::move(oth.routes))
, init_routes(std::move(oth.init_routes)) {}

router::router(const router& oth)
: routes(oth.routes)
, init_routes(oth.init_routes) {}

router::router(std::initializer_list<cf::route> routes)
: init_routes(routes) {}

router& router::operator=(router&& oth) {
    if (this != &oth) {
        this->routes = oth.routes;
        this->init_routes = oth.init_routes;
    }
    return *this;
}

router& router::operator=(const router& oth) {
    if (this != &oth) {
        this->routes = std::move(oth.routes);
        this->init_routes = std::move(oth.init_routes);
    }
    return *this;
}

std::string router::sanitize_path(std::string path) {
    auto re = std::regex("//+");
    auto sanitized = std::regex_replace(path, re, "/");
    if (not sanitized.empty() && sanitized.back() not_eq '/') {
        sanitized.push_back('/');
    }
    return sanitized;
}

std::vector<std::string> router::make_var_captures(std::string path) {
    std::vector<std::string> cap;

    auto iter_begin = std::sregex_iterator(path.begin(), path.end(), this->find_var_regex);
    auto iter_end = std::sregex_iterator();
    for (auto match = iter_begin; match != iter_end; ++match) {
        cap.push_back((*match).str().erase(0, 1));
    }
    return cap;
}

std::pair<std::regex, std::vector<std::string>> router::make_route_regex(std::string path) {
    auto cap = this->make_var_captures(path);
    path = std::regex_replace(path, this->find_two_wildcard_regex, "__TWO_WILDCARD_PLACEHOLDER__");
    path = std::regex_replace(path, this->find_wildcard_regex, this->wildcard_regex);
    path = std::regex_replace(path, this->find_placeholder_regex, this->two_wildcard_regex);
    path = std::regex_replace(path, this->find_var_regex, this->var_regex);
    return std::make_pair(std::regex(path), cap);
}

std::vector<std::pair<std::string, cf::method>> router::validate() {
    auto dup_list = std::vector<std::pair<std::string, cf::method>>{};

    for (auto&& e : this->init_routes) {
        auto sanitized_path = this->sanitize_path(e.path);
        auto path_regex = this->make_route_regex(sanitized_path);
        auto rw = router::route_wrapper{ std::move(e.handler),
                                         std::move(e.middlewares),
                                         std::move(path_regex.first),
                                         std::move(path_regex.second) };
        if (not this->insert(e.path, e.method, std::move(rw))) {
            dup_list.push_back(std::make_pair(e.path, e.method));
        }
    }
    return dup_list;
}

bool router::insert(std::string path, cf::method method, route_wrapper&& rw) {
    auto search_path = this->routes.find(path);
    if(search_path not_eq this->routes.end()) {
        auto search_method = search_path->second.find(method);
        if (search_method not_eq search_path->second.end()) {
            // method for path already exist
            return false;
        } else {
            // add the route_wrapper for the method to the routes
            search_path->second.emplace(std::move(method), std::move(rw));
        }
    } else {
        // create the cf::method and route_wrapper map
        auto route_wrapper_map = std::map<cf::method, route_wrapper>{};
        // insert current data
        route_wrapper_map.emplace(std::move(method), std::move(rw));
        // insert the map inside the routes map
        this->routes.emplace(std::move(path), std::move(route_wrapper_map));
    }
    return true;
}


// router_wrapper impl

router::route_wrapper::route_wrapper(route_wrapper&& oth)
: handler(std::move(oth.handler))
, middlewares(std::move(oth.middlewares))
, match_path(std::move(oth.match_path))
, var_names(std::move(oth.var_names)) {}

router::route_wrapper::route_wrapper(const route_wrapper& oth)
: handler(oth.handler)
, middlewares(oth.middlewares)
, match_path(oth.match_path)
, var_names(oth.var_names) {}

router::route_wrapper::route_wrapper(std::function<cf::response(cf::context&)>&& handler,
                                     std::vector<std::string>&& middlewares,
                                     std::regex&& match_path,
                                     std::vector<std::string>&& var_names)
: handler(std::move(handler))
, middlewares(std::move(middlewares))
, match_path(std::move(match_path))
, var_names(std::move(var_names)) {}

router::route_wrapper& router::route_wrapper::operator=(route_wrapper&& oth) {
    if (this != &oth) {
        this->handler = oth.handler;
        this->middlewares = oth.middlewares;
        this->match_path = oth.match_path;
        this->var_names = oth.var_names;
    }
    return *this;
}

router::route_wrapper& router::route_wrapper::operator=(const route_wrapper& oth) {
    if (this != &oth) {
        this->handler = std::move(oth.handler);
        this->middlewares = std::move(oth.middlewares);
        this->match_path = std::move(match_path);
        this->var_names = std::move(oth.var_names);
    }
    return *this;
}

}
