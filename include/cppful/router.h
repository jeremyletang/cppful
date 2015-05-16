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

#ifndef CPPFUL_ROUTER
#define CPPFUL_ROUTER

#include <unordered_map>
#include <map>
#include <functional>
#include <vector>
#include <regex>

#include "route.h"
#include "middleware.h"
#include "middleware_wrapper.h"
#include "method.h"

namespace cf {

struct router {
private:
    static const std::regex find_var_regex;
    static const std::regex find_wildcard_regex;
    static const std::regex find_two_wildcard_regex;
    static const std::regex find_placeholder_regex;
    static const std::regex sanitize_regex;
    static const std::string var_regex;
    static const std::string wildcard_regex;
    static const std::string two_wildcard_regex;

    struct route_wrapper {
        // the function to call for for given route and method
        std::function<cf::response(cf::context&)> handler;
        // the middleware names to call on dispatch
        std::vector<std::string> middlewares;

        route_wrapper() = delete;
        route_wrapper(route_wrapper&& oth);
        route_wrapper(const route_wrapper& oth);
        route_wrapper(std::function<cf::response(cf::context&)>&& handler,
                      std::vector<std::string>&& middlewares);

        ~route_wrapper() = default;

        route_wrapper& operator=(route_wrapper&& oth);
        route_wrapper& operator=(const route_wrapper& oth);
    };

    struct route_data {
        // the regex to match the path to dispatch
        std::regex match_path;
        // the names of the var we will catch in the path
        std::vector<std::string> var_names;
        // association of the different http methods/routes for a given path
        std::map<cf::method, route_wrapper> methods_map;

        route_data() = delete;
        route_data(route_data&& oth);
        route_data(const route_data& oth);
        route_data(std::regex&& match_path,
                   std::vector<std::string> var_names);

        ~route_data() = default;

        route_data& operator=(route_data&& oth);
        route_data& operator=(const route_data& oth);
    };

    // match the path + the list of the routes it
    std::unordered_map<std::string, route_data> routes;
    // the vector build using the initializer list from the router constructor
    std::vector<cf::middleware_wrapper> init_wrappers;

    std::string sanitize_path(std::string);
    std::pair<std::regex, std::vector<std::string>> make_route_regex(std::string path);
    std::vector<std::string> make_var_captures(std::string path);
    bool insert(std::string path, cf::method method, route_wrapper&& rw);

public:
    router() = default;
    router(router&& oth);
    router(const router& oth);
    router(std::initializer_list<cf::middleware_wrapper> wrappers);

    ~router() = default;

    router& operator=(router&& oth);
    router& operator=(const router& oth);

    std::vector<std::pair<std::string, cf::method>> validate();
    cf::response dispatch(cf::context& ctxt);

};

}

#endif
