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
#include "string.h"
#include "../priv/any.h"

namespace cf {

namespace orm {

struct field {
private:
    cf::any val;
    std::string name;
    cf::orm::type ty;

    bool is_unsigned;
    bool nullable;
    bool auto_increment;
    bool id;

public:
    field() = delete;

    field(field&& oth);
    field(const field& oth);

    field(bool& val, std::string name);
    field(cf::orm::null<bool>& val, std::string name);

    field(char& val, std::string name);
    field(cf::orm::null<char>& val, std::string name);
    field(unsigned char& val, std::string name);
    field(cf::orm::null<unsigned char>& val, std::string name);

    field(short& val, std::string name);
    field(cf::orm::null<short>& val, std::string name);
    field(unsigned short& val, std::string name);
    field(cf::orm::null<unsigned short>& val, std::string name);

    field(int& val, std::string name);
    field(cf::orm::null<int>& val, std::string name);
    field(unsigned int& val, std::string name);
    field(cf::orm::null<unsigned int>& val, std::string name);

    field(long& val, std::string name);
    field(cf::orm::null<long>& val, std::string name);
    field(unsigned long& val, std::string name);
    field(cf::orm::null<unsigned long>& val, std::string name);

    field(float& val, std::string name);
    field(cf::orm::null<float>& val, std::string name);

    field(double& val, std::string name);
    field(cf::orm::null<double>& val, std::string name);

    template<cf::orm::string_kind T>
    field(cf::orm::string<T>& val, std::string name)
    : val(any(std::ref(val)))
    , name(name)
    , ty(cf::orm::string_kind_to_orm_type(val.kind()))
    , is_unsigned(false) {}

    ~field() = default;

    field& operator=(field&& oth);
    field& operator=(const field& oth);

    cf::orm::type type() const;

    template<typename T>
    T& get()
    { return this->val.unwrap_ref<std::reference_wrapper<T>>().get(); }

};

}

}

#endif
