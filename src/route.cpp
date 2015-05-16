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

#include "cppful/route.h"

namespace cf {

route::route(route&& oth)
: method(std::move(oth.method))
, path(std::move(oth.path))
, handler(std::move(oth.handler))
, middlewares(std::move(oth.middlewares)) {}

route::route(const route& oth)
: method(oth.method)
, path(oth.path)
, handler(oth.handler)
, middlewares(oth.middlewares) {}

route& route::operator=(const route& oth) {
    if (this not_eq &oth) {
        this->method = oth.method;
        this->path = oth.path;
        this->handler = oth.handler;
        this->middlewares = oth.middlewares;
    }
    return *this;
}

route& route::operator=(route&& oth) {
    if (this not_eq &oth) {
        this->method = std::move(oth.method);
        this->path = std::move(oth.path);
        this->handler = std::move(oth.handler);
        this->middlewares = std::move(this->middlewares);
    }
    return *this;
}

}
