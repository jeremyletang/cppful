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

#include "cppful/priv/any.h"

namespace cf {

any::any(any&& oth)
: value(oth.value) {
    oth.value = nullptr;
}

any::any(const any& oth)
: value(oth.value->copy()) {}

any::~any()
{ if (this->value) { delete this->value; } }

any& any::operator=(const any& oth) {
    if (this != &oth) {
        this->clear();
        this->value = oth.value->copy();
    }
    return *this;
}

any& any::operator=(any&& oth) {
    if (this != &oth) {
        this->clear();
        this->value = oth.value;
        oth.value = nullptr;
    }
    return *this;
}


const std::type_info& any::type() const
{ return this->value->type(); }

void any::clear() {
    if (this->value) {
        delete this->value;
        this->value = nullptr;
    }
}

bool operator==(const any& a, std::nullptr_t nullp)
{ return a.value == nullptr; }

bool operator==(std::nullptr_t nullp, const any& a)
{ return a.value == nullptr; }

}
