#include "cppful/middleware_wrapper.h"

namespace cf {

middleware_wrapper::middleware_wrapper(middleware_wrapper&& oth)
: route(std::move(oth.route))
, middleware(std::move(oth.middleware))
, kind(oth.kind) {}

middleware_wrapper::middleware_wrapper(const middleware_wrapper& oth)
: route(oth.route)
, middleware(oth.middleware)
, kind(oth.kind) {}

middleware_wrapper& middleware_wrapper::operator=(middleware_wrapper&& oth) {
    if (this != &oth) {
        this->route = std::move(oth.route);
        this->middleware = std::move(oth.middleware);
        this->kind = oth.kind;
    }
    return *this;
}

middleware_wrapper& middleware_wrapper::operator=(const middleware_wrapper& oth) {
    if (this != &oth) {
        this->route = oth.route;
        this->middleware = oth.middleware;
        this->kind = oth.kind;
    }
    return *this;
}

bool middleware_wrapper::is_route() {
    return this->kind == middleware_kind::route;
}

bool middleware_wrapper::is_middleware() {
    return this->kind == middleware_kind::middleware;
}

cf::route&& middleware_wrapper::unwrap_route() {
    return std::move(this->route);
}

cf::middleware&& middleware_wrapper::unwrap_middleware() {
    return std::move(this->middleware);
}

}