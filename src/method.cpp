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

#include "method.h"

namespace cf {

std::string to_string(cf::method m) {
    switch (m) {
        case cf::method::get: return "GET";
        case cf::method::post: return "POST";
        case cf::method::put: return "PUT";
        case cf::method::delete_: return "DELETE";
        case cf::method::head: return "HEAD";
        case cf::method::options: return "OPTIONS";
        case cf::method::trace: return "TRACE";
        case cf::method::connect: return "CONNECT";
        case cf::method::merge: return "MERGE";
        case cf::method::patch: return "PATCH";
        default: return "unknown";
    }
    return "";
}

cf::method from_string(const std::string& m) {
    switch (hash_(m.c_str())) {
        case cf::hash_("GET"): return cf::method::get;
        case cf::hash_("POST"): return cf::method::post;
        case cf::hash_("PUT"): return cf::method::put;
        case cf::hash_("DELETE"): return cf::method::delete_;
        case cf::hash_("HEAD"): return cf::method::head;
        case cf::hash_("OPTIONS"): return cf::method::options;
        case cf::hash_("TRACE"): return cf::method::trace;
        case cf::hash_("CONNECT"): return cf::method::connect;
        case cf::hash_("MERGE"): return cf::method::merge;
        case cf::hash_("PATCH"): return cf::method::patch;
        default: return cf::method::unknown;
    }
    return cf::method::unknown;
}

std::ostream &operator<<(std::ostream &os, cf::method m) {
    os << cf::to_string(m);
    return os;
}

}
