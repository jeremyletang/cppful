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

#include "router.h"

namespace cf {

router::router(router&& oth)
: routes(std::move(oth.routes)) {}

router::router(const router& oth)
: routes(oth.routes) {}

router::router(std::initializer_list<cf::route> routes) {
    for (auto e : routes) {
        auto t = router::route_wrapper{ std::move(e.handler), std::move(e.middlewares) };
    }
}

router& router::operator=(router&& oth) {
    if (this != &oth) {
        this->routes = oth.routes;
    }
    return *this;
}

router& router::operator=(const router& oth) {
    if (this != &oth) {
        this->routes = std::move(oth.routes);
    }
    return *this;
}

router::route_wrapper::route_wrapper(route_wrapper&& oth)
: handler(std::move(oth.handler))
, middlewares(std::move(oth.middlewares)) {}

router::route_wrapper::route_wrapper(const route_wrapper& oth)
: handler(oth.handler)
, middlewares(oth.middlewares) {}

router::route_wrapper::route_wrapper(std::function<cf::response(cf::context&)>&& handler,
                                     std::vector<std::string>&& middlewares)
: handler(std::move(handler))
, middlewares(std::move(middlewares)) {}

router::route_wrapper& router::route_wrapper::operator=(route_wrapper&& oth) {
    if (this != &oth) {
        this->handler = oth.handler;
        this->middlewares = oth.middlewares;
    }
    return *this;
}

router::route_wrapper& router::route_wrapper::operator=(const route_wrapper& oth) {
    if (this != &oth) {
        this->handler = std::move(oth.handler);
        this->middlewares = std::move(oth.middlewares);
    }
    return *this;
}

}