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

#include "cppful/orm/type.h"

namespace cf {

std::string to_string(cf::type m) {
    switch (m) {
        case cf::type::character: return "character";
        case cf::type::varchar: return "varchar";
        case cf::type::binary: return "binary";
        case cf::type::boolean: return "boolean";
        case cf::type::varbinary: return "varbinary";
        case cf::type::smallint: return "smallint";
        case cf::type::integer: return "integer";
        case cf::type::decimal: return "decimal";
        case cf::type::float_: return "float";
        case cf::type::real: return "real";
        case cf::type::double_precision: return "double_precision";
        case cf::type::date: return "date";
        case cf::type::time: return "timestamp";
        case cf::type::array: return "interval";
        case cf::type::multiset: return "multiset";
        case cf::type::xml: return "xml";
        default: return "unknown";
    }
    return "";
}

std::ostream &operator<<(std::ostream &os, cf::type m) {
    os << cf::to_string(m);
    return os;
}

}