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

#include "status.h"

namespace cf {

std::string to_string(cf::status s) {
    switch (s) {
    case cf::status::ok: return "ok";
    case cf::status::created: return "created";
    case cf::status::accepted: return "accepted";
    case cf::status::no_content: return "no content";
    case cf::status::multiple_choices: return "multiple choices";
    case cf::status::moved_permanently: return "moved permanently";
    case cf::status::moved_temporarily: return "moved temporarily";
    case cf::status::not_modified: return "not modified";
    case cf::status::bad_request: return "bad request";
    case cf::status::unauthorized: return "unauthorized";
    case cf::status::forbidden: return "forbidden";
    case cf::status::not_found: return "not found";
    case cf::status::not_supported: return "not supported";
    case cf::status::not_acceptable: return "not acceptable";
    case cf::status::internal_server_error: return "internal server error";
    case cf::status::not_implemented: return "not implemented";
    case cf::status::bad_gateway: return "bad gateway";
    case cf::status::service_unavailable: return "service unavailable";
    default: return "unknown";
    }
    return "";
}

std::ostream &operator << (std::ostream &os, cf::status s) {
    os << cf::to_string(s);
    return os;
}

}
