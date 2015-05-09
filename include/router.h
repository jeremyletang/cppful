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
#include <vector>
#include <method.h>

#include "route.h"

namespace cf {

struct router {
private:

    struct route_wrapper {
        std::function<cf::response(cf::context&)> handler;
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

    std::unordered_map<std::string, std::unordered_map<cf::method, route_wrapper>> routes;

public:
    router() = default;
    router(router&& oth);
    router(const router& oth);
    router(std::initializer_list<cf::route> routes);

    ~router() = default;

    router& operator=(router&& oth);
    router& operator=(const router& oth);

};

}

#endif