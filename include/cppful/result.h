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

#ifndef CPPFUL_RESULT
#define CPPFUL_RESULT

#include <type_traits>

namespace cf {

template<typename Ok, typename Err>
struct result {
private:
    bool status;
    Ok ok;
    Err err;

    static_assert(std::is_default_constructible<Ok>::value,
                  "You cannot create a cf::result struct with a non default constructible OK type");
    static_assert(std::is_default_constructible<Err>::value,
                  "You cannot create a cf::result struct with a non default constructible Err type");

public:
    result() = delete;
    ~result() = default;

    explicit result(Err&& err)
    : status(false)
    , err(std::move(err)) {}

    explicit result(const Err& err)
    : status(false)
    , err(err) {}

    explicit result(Ok&& ok)
    : status(true)
    , ok(std::move(ok)) {}

    explicit result(const Ok& ok)
    : status(true)
    , ok(ok) {}

    result(result&& oth)
    : status(std::move(oth.status))
    , ok(std::move(oth.ok))
    , err(std::move(oth.err)){}

    result(const result& oth)
    : status(oth.status)
    , ok(oth.ok)
    , err(oth.err) {}

    result& operator=(result&& oth) {
        if (this not_eq &oth) {
            this->status = std::move(oth.status);
            this->ok = std::move(oth.ok);
            this->err = std::move(oth.err);
        }
        return *this;
    }
    result& operator=(const result& oth) {
         if (this not_eq &oth) {
            this->status = oth.status;
            this->ok = oth.ok;
            this->err = oth.err;
        }
        return *this;
    }

    bool is_err() const { return not this->status; }

    bool is_ok() const { return this->status; }

    Err&& unwrap_ok() const { return std::move(this->ok); }
    Err&& unwrap_err() const { return std::move(this->err); };
};

}

#endif
