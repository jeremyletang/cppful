#include "cppful/middleware_wrapper.h"

namespace cf {

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