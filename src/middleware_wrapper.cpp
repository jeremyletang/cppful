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

#include "cppful/middleware_wrapper.h"

namespace cf {

middleware_wrapper::middleware_wrapper(middleware_wrapper&& oth)
: route(std::move(oth.route))
, middleware(std::move(oth.middleware))
, kind(oth.kind) {}

middleware_wrapper::middleware_wrapper(const middleware_wrapper& oth)
: route(oth.route)
, middleware(oth.middleware)
, kind(oth.kind) {}

middleware_wrapper& middleware_wrapper::operator=(middleware_wrapper&& oth) {
    if (this not_eq &oth) {
        this->route = std::move(oth.route);
        this->middleware = std::move(oth.middleware);
        this->kind = oth.kind;
    }
    return *this;
}

middleware_wrapper& middleware_wrapper::operator=(const middleware_wrapper& oth) {
    if (this not_eq &oth) {
        this->route = oth.route;
        this->middleware = oth.middleware;
        this->kind = oth.kind;
    }
    return *this;
}

bool middleware_wrapper::is_route() const {
    return this->kind == middleware_kind::route;
}

bool middleware_wrapper::is_middleware() const {
    return this->kind == middleware_kind::middleware;
}

cf::route&& middleware_wrapper::unwrap_route() {
    return std::move(this->route);
}

cf::middleware&& middleware_wrapper::unwrap_middleware() {
    return std::move(this->middleware);
}

}