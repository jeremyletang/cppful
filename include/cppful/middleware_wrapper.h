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

#ifndef CPPFUL_MIDDLEWARE_WRAPPER
#define CPPFUL_MIDDLEWARE_WRAPPER

#include "route.h"
#include "middleware.h"

namespace cf {

struct middleware_wrapper {
private:
    enum class middleware_kind { route, middleware };
    cf::route route;
    cf::middleware middleware;
    middleware_kind kind;

public:
    middleware_wrapper() = delete;
    middleware_wrapper(middleware_wrapper&& oth);
    middleware_wrapper(const middleware_wrapper& oth);
    // build a route
    template<typename H>
    middleware_wrapper(cf::method m,
                       std::string path, H handler,
                       std::vector<std::string> middlewares = {})
    : route(std::move(m), std::move(path), handler, middlewares)
    , middleware({})
    , kind(middleware_kind::route) {
        static_assert(std::is_convertible<H, std::function<cf::response(cf::context&)>>::value,
                      "error, route handler must be convertible to std::function");
    }
    // build a middleware
    template<typename H>
    middleware_wrapper(std::string name, H&& handler)
    : route(cf::method::unknown, "", nullptr, {})
    , middleware(std::move(name), std::move(handler))
    , kind(middleware_kind::middleware) {
        static_assert(std::is_convertible<H, std::function<void(cf::context&)>>::value,
                      "error, middleware handler must be convertible to std::function");
    }

    ~middleware_wrapper() = default;

    middleware_wrapper& operator=(middleware_wrapper&& oth);
    middleware_wrapper& operator=(const middleware_wrapper& oth);

    bool is_route() const;
    bool is_middleware() const ;
    cf::route&& unwrap_route();
    cf::middleware&& unwrap_middleware();

};

}

#endif