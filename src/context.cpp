#include "cppful/context.h"

namespace cf {

context::context(context&& oth)
: path(std::move(oth.path))
, method(std::move(oth.method)) {}

context::context(const context& oth)
: path(oth.path)
, method(oth.method) {}

context::context(const std::string& path, cf::method method)
: path(path)
, method(method) {}

context& context::operator=(context&& oth) {
    if (this != &oth) {
        this->path = std::move(oth.path);
        this->method = std::move(oth.method);
    }
    return *this;
}

context& context::operator=(const context& oth) {
    if (this != &oth) {
        this->path = oth.path;
        this->method = oth.method;
    }
    return *this;
}

}