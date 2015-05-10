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

#include "cppful/response.h"
#include <iostream>

namespace cf {

response::response(response&& oth)
: status(std::move(oth.status))
, body(std::move(oth.body))
, headers(std::move(oth.headers)) {}

response::response(const response& oth)
: status(oth.status)
, body(oth.body)
, headers(oth.headers) {}

response::response(const char* body)
: status(cf::status::ok)
, body(body)
, headers({}) {}

response::response(const std::string& body)
: status(cf::status::ok)
, body(body)
, headers({}) {}

response::response(cf::status m, const std::string& body)
: status(m)
, body(body)
, headers({})  {}


response& response::operator=(response&& oth) {
    if (this != &oth) {
        this->status = std::move(oth.status);
        this->body = std::move(oth.body);
        this->headers = std::move(oth.headers);
    }
    return *this;
}

response& response::operator=(const response& oth) {
    if (this != &oth) {
        this->status = oth.status;
        this->body = oth.body;
        this->headers = oth.headers;
    }
    return *this;
}

}