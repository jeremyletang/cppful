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

#include "cppful/orm/field.h"

#include <functional>

namespace cf {

namespace orm {

field::field(field&& oth)
: val(std::move(oth.val))
, ty(oth.ty) {}

field::field(const field& oth)
: val(oth.val)
, ty(oth.ty) {}

field& field::operator=(field&& oth) {
    if (this not_eq &oth) {
        this->val = std::move(oth.val);
        this->ty = oth.ty;
    }
    return *this;
}

field& field::operator=(const field& oth) {
    if (this not_eq &oth) {
        this->val = oth.val;
        this->ty = oth.ty;
    }
    return *this;
}

// bool

field::field(bool& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::boolean)
, is_unsigned(false) {}

field::field(cf::orm::null<bool>& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::boolean)
, is_unsigned(false) {}

// char

field::field(char& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::tinyint)
, is_unsigned(false) {}

field::field(cf::orm::null<char>& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::tinyint)
, is_unsigned(false) {}

field::field(unsigned char& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::tinyint)
, is_unsigned(true) {}

field::field(cf::orm::null<unsigned char>& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::tinyint)
, is_unsigned(true) {}

// short

field::field(short& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::smallint)
, is_unsigned(false) {}

field::field(cf::orm::null<short>& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::smallint)
, is_unsigned(false) {}

field::field(unsigned short& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::smallint)
, is_unsigned(true) {}

field::field(cf::orm::null<unsigned short>& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::smallint)
, is_unsigned(true) {}

// int

field::field(int& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::int_)
, is_unsigned(false) {}

field::field(cf::orm::null<int>& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::int_)
, is_unsigned(false) {}

field::field(unsigned int& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::int_)
, is_unsigned(true) {}

field::field(cf::orm::null<unsigned int>& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::int_)
, is_unsigned(true) {}

// long

field::field(long& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::bigint)
, is_unsigned(false) {}

field::field(cf::orm::null<long>& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::bigint)
, is_unsigned(false) {}

field::field(unsigned long& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::bigint)
, is_unsigned(true) {}

field::field(cf::orm::null<unsigned long>& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::bigint)
, is_unsigned(true) {}

// float

field::field(float& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::float_)
, is_unsigned(false) {}

field::field(cf::orm::null<float>& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::float_)
, is_unsigned(false) {}

// double

field::field(double& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::double_)
, is_unsigned(false) {}

field::field(cf::orm::null<double>& val)
: val(any(std::ref(val)))
, ty(cf::orm::type::double_)
, is_unsigned(false) {}

cf::orm::type field::type() const
{ return this->ty; }

}

}