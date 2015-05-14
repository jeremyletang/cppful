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

std::string to_string(cf::orm::type m) {
    switch (m) {
        case cf::orm::type::tinyint: return "TNYINT";
        case cf::orm::type::smallint: return "SMALLINT";
        case cf::orm::type::mediumint: return "MEDIUMINT";
        case cf::orm::type::int_: return "INT";
        case cf::orm::type::bigint: return "BIGINT";
        case cf::orm::type::decimal: return "DECIMAL";
        case cf::orm::type::float_: return "FLOAT";
        case cf::orm::type::double_: return "DOUBLE";
        case cf::orm::type::real: return "REAL";
        case cf::orm::type::bit: return "BIT";
        case cf::orm::type::boolean: return "BOOLEAN";
        case cf::orm::type::serial: return "SERIAL";
        case cf::orm::type::date: return "DATE";
        case cf::orm::type::datetime: return "DATETIME";
        case cf::orm::type::timestamp: return "TIMESTAMP";
        case cf::orm::type::time: return "TIME";
        case cf::orm::type::year: return "YEAR";
        case cf::orm::type::char_: return "CHAR";
        case cf::orm::type::varchar: return "VARCHAR";
        case cf::orm::type::tinytext: return "TINYTEXT";
        case cf::orm::type::text: return "TEXT";
        case cf::orm::type::mediumtext: return "MEDIUMTEXT";
        case cf::orm::type::longtext: return "LONGTEXT";
        case cf::orm::type::binary: return "BINARY";
        case cf::orm::type::varbinary: return "VARBINARY";
        case cf::orm::type::tinyblob: return "TINYBLOB";
        case cf::orm::type::mediumblob: return "MEDIUMBLOB";
        case cf::orm::type::blob: return "BLOB";
        case cf::orm::type::longblob: return "LONGBLOB";
        case cf::orm::type::enum_: return "ENUM";
        case cf::orm::type::set: return "SET";
        case cf::orm::type::error: return "ERROR";
        default: return "UNKNWON";
    }
    return "";
}

std::ostream &operator<<(std::ostream &os, cf::orm::type m) {
    os << cf::to_string(m);
    return os;
}

}