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

#include "cppful/orm/string.h"

namespace cf {

namespace orm {

cf::orm::type string_kind_to_orm_type(cf::orm::string_kind k) {
    switch (k) {
        case cf::orm::string_kind::char_ : return cf::orm::type::char_;
        case cf::orm::string_kind::varchar : return cf::orm::type::varchar;
        case cf::orm::string_kind::tinytext : return cf::orm::type::tinytext;
        case cf::orm::string_kind::text : return cf::orm::type::text;
        case cf::orm::string_kind::mediumtext : return cf::orm::type::mediumtext;
        case cf::orm::string_kind::longtext : return cf::orm::type::longtext;
        case cf::orm::string_kind::binary : return cf::orm::type::binary;
        case cf::orm::string_kind::varbinary : return cf::orm::type::varbinary;
        default: return cf::orm::type::error;
    }
    return cf::orm::type::error;
}

}

std::string to_string(cf::orm::string_kind k) {
    switch (k) {
        case cf::orm::string_kind::char_ : return "char";
        case cf::orm::string_kind::varchar : return "varchar";
        case cf::orm::string_kind::tinytext : return "tinytext";
        case cf::orm::string_kind::text : return "text";
        case cf::orm::string_kind::mediumtext : return "mediumtext";
        case cf::orm::string_kind::longtext : return "longtext";
        case cf::orm::string_kind::binary : return "binary";
        case cf::orm::string_kind::varbinary : return "varbinary";
        default: return "unreachable";
    }
    return "";
}

std::ostream &operator<<(std::ostream &os, cf::orm::string_kind m) {
    os << cf::to_string(m);
    return os;
}

}