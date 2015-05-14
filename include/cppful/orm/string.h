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

#ifndef CPPFUL_ORM_STRING
#define CPPFUL_ORM_STRING

#include <type_traits>
#include <string>

namespace cf {

namespace orm {

enum class string_kind {
    char_,
    varchar,
    tinytext,
    text,
    mediumtext,
    longtext,
    binary,
    varbinary,
};

template<typename T>
struct bad_string : std::false_type {};

template<string_kind T>
struct string : public std::string {};

template<>
struct string<string_kind::char_> : public std::string {
  using std::string::string;
  string_kind kind() const { return string_kind::char_; }
};

template<>
struct string<string_kind::varchar> : public std::string {
  using std::string::string;
  string_kind kind() const { return string_kind::varchar; }
};

template<>
struct string<string_kind::tinytext> : public std::string {
  using std::string::string;
  string_kind kind() const { return string_kind::tinytext; }
};

template<>
struct string<string_kind::text> : public std::string {
  using std::string::string;
  string_kind kind() const { return string_kind::text; }
};

template<>
struct string<string_kind::mediumtext> : public std::string {
  using std::string::string;
  string_kind kind() const { return string_kind::mediumtext; }
};

template<>
struct string<string_kind::longtext> : public std::string {
  using std::string::string;
  string_kind kind() const { return string_kind::longtext; }
};

template<>
struct string<string_kind::binary> : public std::string {
  using std::string::string;
  string_kind kind() const { return string_kind::binary; }
};

template<>
struct string<string_kind::varbinary> : public std::string {
  using std::string::string;
  string_kind kind() const { return string_kind::varbinary; }
};

}

std::string to_string(cf::orm::string_kind t);
std::ostream &operator << (std::ostream &os, cf::orm::string_kind t);

}

#endif