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
        case cf::type::tinyint: return "TNYINT";
        case cf::type::smallint: return "SMALLINT";
        case cf::type::mediumint: return "MEDIUMINT";
        case cf::type::int_: return "INT";
        case cf::type::bigint: return "BIGINT";
        case cf::type::decimal: return "DECIMAL";
        case cf::type::float_: return "FLOAT";
        case cf::type::double_: return "DOUBLE";
        case cf::type::real: return "REAL";
        case cf::type::bit: return "BIT";
        case cf::type::boolean: return "BOOLEAN";
        case cf::type::serial: return "SERIAL";
        case cf::type::date: return "DATE";
        case cf::type::datetime: return "DATETIME";
        case cf::type::timestamp: return "TIMESTAMP";
        case cf::type::time: return "TIME";
        case cf::type::year: return "YEAR";
        case cf::type::char_: return "CHAR";
        case cf::type::varchar: return "VARCHAR";
        case cf::type::tinytext: return "TINYTEXT";
        case cf::type::text: return "TEXT";
        case cf::type::mediumtext: return "MEDIUMTEXT";
        case cf::type::longtext: return "LONGTEXT";
        case cf::type::binary: return "BINARY";
        case cf::type::varbinary: return "VARBINARY";
        case cf::type::tinyblob: return "TINYBLOB";
        case cf::type::mediumblob: return "MEDIUMBLOB";
        case cf::type::blob: return "BLOB";
        case cf::type::longblob: return "LONGBLOB";
        case cf::type::enum_: return "ENUM";
        case cf::type::set: return "SET";
        default: return "UNKNWON";
    }
    return "";
}

std::ostream &operator<<(std::ostream &os, cf::type m) {
    os << cf::to_string(m);
    return os;
}

}