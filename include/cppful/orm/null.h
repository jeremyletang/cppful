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

#ifndef CPPFUL_ORM_NULL
#define CPPFUL_ORM_NULL

namespace cf {

namespace orm {

template <typename T>
struct null {
private:
    T val;
    bool is_null;

public:
    null()
    : val(T())
    , is_null(true) {}

    null(null&& oth)
    : val(std::move(oth.val))
    , is_null(std::move(oth.is_null)) {}

    null(const null& oth)
    : val(oth.val)
    , is_null(oth.is_null) {}

    null(const T& val)
    : val(val)
    , is_null(false) {}

    ~null() = default;

    null<T>& operator=(null<T>&& oth) {
        if (this != &oth) {
            this->val = std::move(oth.val);
            this->is_null = oth.is_null;
        }
        return *this;
    }

    null<T>& operator=(const null<T>& oth) {
        if (this != &oth) {
            this->val = oth.val;
            this->is_null = oth.is_null;
        }
        return *this;
    }

    null<T>& operator=(const T& val) {
        this->val = val;
        this->is_null = false;
        return *this;
    }

    T& operator*() { return this->val; }

};

template<typename T>
inline bool operator==(const null<T>& lhs, const T& rhs)
{ return *lhs == rhs; }

template<typename T>
inline bool operator!=(const null<T>& lhs, const T& rhs)
{ return not (lhs == rhs); }

template<typename T>
inline bool operator==(const T& rhs, const null<T>& lhs)
{ return *lhs == rhs; }

template<typename T>
inline bool operator!=(const T& rhs, const null<T>& lhs)
{ return not (lhs == rhs); }

template<typename T>
inline bool operator==(const null<T>& lhs, std::nullptr_t nullp)
{ return lhs.is_null(); }

template<typename T>
inline bool operator!=(const null<T>& lhs, std::nullptr_t nullp)
{ return not (lhs == nullp); }

template<typename T>
inline bool operator==(std::nullptr_t nullp, const null<T>& lhs)
{ return lhs.is_null(); }

template<typename T>
inline bool operator!=(std::nullptr_t nullp, const null<T>& lhs)
{ return not (lhs == nullp); }

}

}

#endif
