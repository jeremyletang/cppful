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

#include "cppful/orm/value.h"

#include <functional>

namespace cf {

namespace orm {

value::value(value&& oth)
: val(std::move(oth.val))
, ty(oth.ty) {}

value::value(const value& oth)
: val(oth.val)
, ty(oth.ty) {}

value& value::operator=(value&& oth) {
    if (this != &oth) {
        this->val = std::move(oth.val);
        this->ty = oth.ty;
    }
    return *this;
}

value& value::operator=(const value& oth) {
    if (this != &oth) {
        this->val = oth.val;
        this->ty = oth.ty;
    }
    return *this;
}

value::value(bool &val, cf::type ty)
: val(any(std::ref(val)))
, ty(ty) {}

value::value(int &val, cf::type ty)
: val(any(std::ref(val)))
, ty(ty) {}

cf::type value::type() const {
    return this->ty;
}

template<>
int& value::get() {
    return this->val.unwrap_ref<std::reference_wrapper<int>>().get();
}

template<>
bool& value::get() {
    return this->val.unwrap_ref<std::reference_wrapper<bool>>().get();
}

}

}