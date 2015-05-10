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

#ifndef CPPFUL_SERVER
#define CPPFUL_SERVER

#include <string>
#include <vector>

#include "route.h"
#include "router.h"

namespace cf {

struct server {
private:
    cf::router router;
    std::string ip;
    unsigned int port;
    std::string mime;

public:
    server() = default;
    server(server&& oth);
    server(const server& oth);
    server(cf::router r,
           std::string h = "0.0.0.0",
           unsigned ip = 8080,
           std::string mime = "application/json");
    server(server& oth);

    ~server() = default;

    server& operator=(server&& oth);
    server& operator=(const server& oth);

    bool run();
};

}

#endif
