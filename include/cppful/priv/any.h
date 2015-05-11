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

#ifndef CPPFUL_ANY
#define CPPFUL_ANY

#include <memory>
#include <typeinfo>
#include <iostream>
#include <memory>

namespace cf {

struct any {
private:
    struct base_any {
        virtual const std::type_info& type() const = 0;
        virtual base_any* copy() const = 0;
        virtual ~base_any() {}
    };

    template<typename T>
    struct any_impl: base_any {
        T value;
        const std::type_info& ty;

        any_impl() = delete;

        any_impl(const T& value)
        : value(value)
        , ty(typeid(T)) {}

        any_impl(T&& value)
        : value(std::move(value))
        , ty(typeid(T)) {}

        ~any_impl() = default;

        base_any* copy() const {
            auto c = new any_impl<T>(value);
            return c;
        }

        const std::type_info& type() const
        { return this->ty; }

        T& get_ref()
        { return this->value; }

        T get_copy()
        { return this->value; }
    };

    base_any* value = nullptr;

public:
    any() = delete;
    any(any&& oth);
    any(const any& oth);

    template<typename T>
    explicit any(T& value)
    : value(new any_impl<T>(value)) {}

    template<typename T>
    explicit any(T&& value)
    : value(new any_impl<T>(std::move(value))) {}

    ~any();

    any& operator=(const any& oth);
    any& operator=(any&& oth);

    template<typename T>
    bool is() const
    { return this->value->type() == typeid(T); }

    const std::type_info& type() const;

    void clear();

    template<typename T>
    T& ref_unwrap() {
        if (not this->value or not this->is<T>()) { throw std::bad_cast{}; }
        auto ptr = reinterpret_cast<any_impl<T>*>(this->value);
        if (not ptr) { throw std::bad_cast(); }
        return ptr->get_ref();
    }

    template<typename T>
    T copy_unwrap() {
        if (not this->value or not this->is<T>()) { throw std::bad_cast{}; }
        auto ptr = reinterpret_cast<any_impl<T>*>(this->value);
        if (not ptr) { throw std::bad_cast(); }
        return ptr->get_copy();
    }

    friend bool operator==(const any& a, std::nullptr_t nullp);
    friend bool operator==(std::nullptr_t nullp, const any& a);

};

bool operator==(const any& a, std::nullptr_t nullp);
bool operator==(std::nullptr_t nullp, const any& a);

}

#endif
