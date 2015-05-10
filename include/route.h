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

#ifndef CPPFUL_ROUTE
#define CPPFUL_ROUTE

#include <string>
#include <vector>
#include <functional>

#include "method.h"
#include "response.h"
#include "context.h"

namespace cf {

struct route {
    cf::method method;
    std::string path;
    std::function<cf::response(cf::context&)> handler;
    std::vector<std::string> middlewares;

    route() = delete;
    route(route&& oth);
    route(const route& oth);

    template<typename H>
    route(cf::method m, std::string path, H handler, std::vector<std::string> middlewares = {}) {
        static_assert(std::is_convertible<H, std::function<cf::response(cf::context&)>>::value,
                      "error, route handler must be convertible to std::function");
        this->method = std::move(m);
        this->path = std::move(path);
        this->handler = handler;
        this->middlewares = middlewares;
    }

    ~route() = default;

    route& operator=(route&& oth);
    route& operator=(const route& oth);

};

}

#endif
