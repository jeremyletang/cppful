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

#ifndef CPPFUL_ORM_SQL_FIELD
#define CPPFUL_ORM_SQL_FIELD

#include <string>
#include <functional>

#include "type.h"
#include "null.h"
#include "../priv/any.h"

namespace cf {

namespace orm {

struct field {
private:
    cf::any val;
    std::string name;
    const std::string type_name;
    cf::type ty;

    bool is_unsigned;
    bool nullable;
    bool auto_increment;
    bool id;

public:
    field() = delete;

    field(field&& oth);
    field(const field& oth);

    field(bool& val, std::string name = "");
    field(cf::orm::null<bool>& val, std::string name = "");

    field(char& val, std::string name = "");
    field(cf::orm::null<char>& val, std::string name = "");
    field(unsigned char& val, std::string name = "");
    field(cf::orm::null<unsigned char>& val, std::string name = "");

    field(int& val, std::string name = "");
    field(cf::orm::null<int>& val, std::string name = "");
    field(unsigned int& val, std::string name = "");
    field(cf::orm::null<unsigned int>& val, std::string name = "");

    ~field() = default;

    field& operator=(field&& oth);
    field& operator=(const field& oth);

    cf::type type() const;

    template<typename T>
    T& get()
    { return this->val.unwrap_ref<std::reference_wrapper<T>>().get(); }

};

}

}

#endif
