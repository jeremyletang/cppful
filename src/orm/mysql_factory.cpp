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

#include "cppful/orm/mysql_factory.h"

#include <iostream>

namespace cf {

namespace orm {

mysql_factory::mysql_factory(const std::string& host,
                             const std::string& username,
                             const std::string& password,
                             const std::string& database,
                             unsigned int port)
: host(host)
, username(username)
, password(password)
, database(database)
, port(port) {}

mysql_factory::mysql_factory(mysql_factory&& oth)
: host(std::move(oth.host))
, username(std::move(oth.username))
, password(std::move(oth.password))
, database(std::move(oth.database))
, port(oth.port) {}


mysql_factory::~mysql_factory() {
    // if (this->connection) {
    //     mysql_close(this->connection);
    //     mysql_library_end();
    // }
}

mysql_factory& mysql_factory::operator=(mysql_factory&& oth) {
    if (this not_eq &oth) {
        this->host = std::move(oth.host);
        this->username = std::move(oth.username);
        this->password = std::move(oth.password);
        this->database = std::move(oth.database);
        this->port = oth.port;
    }
    return *this;
}

std::unique_ptr<cf::orm::db_connection> mysql_factory::make_connection() {
    auto mc = std::make_unique<cf::orm::mysql_connection>();
    return std::move(mc);
}


// std::pair<bool, std::string> mysql_factory::connect() {
//     // init mysql
//     mysql_library_init(0, nullptr, nullptr);

//     // make MYSQL object
//     this->connection = mysql_init(nullptr);
//     if (not this->connection)  {
//         auto err =  mysql_error(this->connection);
//         return std::make_pair(false, err);
//     }

//     // try to connect
//     auto connection_result = mysql_real_connect(this->connection,
//                                                 this->host.c_str(),
//                                                 this->username.c_str(),
//                                                 this->password.c_str(),
//                                                 this->database.c_str(),
//                                                 this->port,
//                                                 nullptr,
//                                                 0);

//     if (not connection_result)  {
//         auto err = mysql_error(this->connection);
//         mysql_close(this->connection);
//         this->connection = nullptr;
//         return std::make_pair(false, std::string(err));
//     }
//     return std::make_pair(true, "");
// }

}

}

