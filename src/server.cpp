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
: router(std::move(oth.router))
, ip(std::move(oth.ip))
, port(std::move(oth.port))
, mime(std::move(oth.mime)) {}

server::server(const server& oth)
: router(oth.router)
, ip(oth.ip)
, port(oth.port)
, mime(oth.mime) {}

server::server(cf::router router, std::string ip, unsigned int port, std::string mime)
: router(std::move(router))
, ip(std::move(ip))
, port(std::move(port))
, mime(std::move(mime)) {}

server& server::operator=(const server& oth) {
    if (this != &oth) {
        this->router = oth.router;
        this->ip = oth.ip;
        this->port = oth.port;
        this->mime = oth.mime;
    }
    return *this;
}

server& server::operator=(server&& oth) {
    if (this != &oth) {
        this->router = std::move(oth.router);
        this->ip = std::move(oth.ip);
        this->port = std::move(oth.port);
        this->mime = std::move(oth.mime);
    }
    return *this;
}

bool server::run() {
    this->validate_routes();
    return true;
}

void server::validate_routes() {
    auto dup_list = this->router.validate();
    if (not dup_list.empty()) {
        for (auto e : dup_list) {
            std::cout << "warning: multiple handler defined for path " << e.first
            << " with method " << cf::to_string(e.second) << std::endl;
        }
    }
}

}
