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

#ifndef CPPFUL_ORM_MYSQL_FACTORY
#define CPPFUL_ORM_MYSQL_FACTORY

#include <functional>

#ifdef __APPLE__
#include "mysql.h"
#elif __linux__
#include "mysql/mysql.h"
#endif

#include "db_factory.h"
#include "db_connection.h"
#include "mysql_connection.h"

namespace cf {

namespace orm {

struct mysql_factory : public cf::orm::db_factory {
private:
    std::string host;
    std::string username;
    std::string password;
    std::string database;
    unsigned int port;

public:
    mysql_factory() = delete;
    mysql_factory(const std::string& host,
                  const std::string& username,
                  const std::string& password,
                  const std::string& database,
                  unsigned int port = 0);
    mysql_factory(mysql_factory&& oth);
    ~mysql_factory();
    mysql_factory& operator=(mysql_factory&& oth);

    std::unique_ptr<cf::orm::db_connection> make_connection();

};

}

}

#endif