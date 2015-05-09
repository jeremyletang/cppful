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

#include "server.h"

namespace cf {

server::server(server&& oth)
: ip(std::move(oth.ip))
, port(std::move(oth.port))
, router(std::move(oth.router)) {}

server::server(const server& oth)
: ip(oth.ip)
, port(oth.port)
, router(oth.router) {}

server::server(std::string ip, unsigned int port, cf::router router)
: ip(std::move(ip))
, port(std::move(port))
, router(std::move(router)) {
    std::cout << "here" << std::endl;
}

server& server::operator=(const server& oth) {
    if (this != &oth) {
        this->ip = oth.ip;
        this->port = oth.port;
        this->router = oth.router;
    }
    return *this;
}

server& server::operator=(server&& oth) {
    if (this != &oth) {
        this->ip = std::move(oth.ip);
        this->port = std::move(oth.port);
        this->router = std::move(oth.router);
    }
    return *this;
}


bool server::run() {
    return true;
}

}