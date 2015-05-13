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

#ifndef CPPFUL_ANYMAP
#define CPPFUL_ANYMAP

#include <unordered_map>
#include <typeinfo>
#include <typeindex>

#include "priv/any.h"

namespace cf {

struct nullopt : public std::exception {};

struct any_map {
private:
    std::unordered_map<std::type_index, cf::any> map;

public:
    any_map() = default;
    any_map(any_map&& oth);
    any_map(const any_map& oth);
    any_map(std::initializer_list<any> init);

    any_map& operator=(any_map&& oth);
    any_map& operator=(const any_map& oth);

    ~any_map() = default;

    bool empty() noexcept;
    void clear() noexcept;

    template<typename T>
    bool exist() noexcept {
        auto& e = this->map.find(std::type_index(typeid(T)));
        return e not_eq this->map.end();
    }

    template<typename T>
    void insert(T&& value) {
        auto e = this->map.find(std::type_index(typeid(T)));
        if (e not_eq this->map.end()) {
            this->map.erase(e);
        }
        auto any_value = any(std::move(value));
        this->map.emplace(std::type_index(typeid(T)), std::move(any_value));
    }

    template<typename T>
    void insert(const T& value) {
        auto e = this->map.find(std::type_index(typeid(T)));
        if (e not_eq this->map.end()) {
            this->map.erase(e);
        }
        auto any_value = any(value);
        this->map.emplace(std::type_index(typeid(T)), std::move(any_value));
    }

    template<typename T>
    T& get() {
        auto e = this->map.find(std::type_index(typeid(T)));
        if (e == this->map.end()) {
            throw cf::nullopt{};
        }
        return (*e).second.ref_unwrap<T>();
    }

};

}

#endif