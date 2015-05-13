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
    if (this != &oth) {
        this->val = std::move(oth.val);
        this->ty = oth.ty;
    }
    return *this;
}

field& field::operator=(const field& oth) {
    if (this != &oth) {
        this->val = oth.val;
        this->ty = oth.ty;
    }
    return *this;
}

field::field(bool& val, std::string name)
: val(any(std::ref(val)))
, name(name)
, ty(cf::type::boolean) {}

field::field(cf::orm::null<bool>& val, std::string name)
: val(any(std::ref(val)))
, name(name)
, ty(cf::type::boolean) {}

field::field(int& val, std::string name)
: val(any(std::ref(val)))
, name(name)
, ty(cf::type::integer) {}

field::field(cf::orm::null<int>& val, std::string name)
: val(any(std::ref(val)))
, name(name)
, ty(cf::type::integer) {}

cf::type field::type() const {
    return this->ty;
}

}

}