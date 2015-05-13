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

#ifndef CPPFUL_ORM_SQL_VALUE
#define CPPFUL_ORM_SQL_VALUE

#include "type.h"
#include "../priv/any.h"

namespace cf {

namespace orm {

struct value {
private:
    cf::any val;
    cf::type ty;

public:
    value() = delete;
    value(value&& oth);
    value(const value& oth);
    value(bool &val, cf::type ty = cf::type::boolean);
    value(int &val, cf::type ty = cf::type::integer);
    ~value() = default;

    value& operator=(value&& oth);
    value& operator=(const value& oth);

    cf::type type() const;
    template<typename T>
    T& get();

};

}

}

#endif
