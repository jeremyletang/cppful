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
    cf::orm::type ty;

    bool is_unsigned;
    bool nullable;
    bool auto_increment;
    bool id;

public:
    field() = delete;

    field(field&& oth);
    field(const field& oth);

    field(bool& val);
    field(cf::orm::null<bool>& val);

    field(char& val);
    field(cf::orm::null<char>& val);
    field(unsigned char& val);
    field(cf::orm::null<unsigned char>& val);

    field(short& val);
    field(cf::orm::null<short>& val);
    field(unsigned short& val);
    field(cf::orm::null<unsigned short>& val);

    field(int& val);
    field(cf::orm::null<int>& val);
    field(unsigned int& val);
    field(cf::orm::null<unsigned int>& val);

    field(long& val);
    field(cf::orm::null<long>& val);
    field(unsigned long& val);
    field(cf::orm::null<unsigned long>& val);

    field(float& val);
    field(cf::orm::null<float>& val);

    field(double& val);
    field(cf::orm::null<double>& val);

    template<cf::orm::string_kind T>
    field(cf::orm::string<T>& val)
    : val(any(std::ref(val)))
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
