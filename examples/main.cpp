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

#include <cppful.h>
#include <csignal>

bool should_exit = false;

void sigint_handler(int sig) {
    if (sig == SIGINT) { should_exit = true; }
}

void hello_middleware(cf::context& ctx) {
    std::cout << "on middleware !" << std::endl;
}

void stop_middleware(cf::context& ctx) {
    std::cout << "this middleware will stop routing !" << std::endl;
    throw cf::stop{ { cf::status::not_implemented, cf::to_string(cf::status::not_implemented) } };
}

cf::response ok(cf::context& ctx) { return "hello"; }
cf::response no_content(cf::context& ctx) { return {}; }
cf::response no_content_post(cf::context& ctx) { return {}; }
cf::response bad_request(cf::context& ctx) {
    return { cf::status::bad_request, cf::to_string(cf::status::bad_request) };
}

int main() {
    std::signal(SIGINT, sigint_handler);
    auto app = cf::server {
        { { cf::method::get, "/ok", ok },
          { cf::method::get, "/no_content", no_content },
          { cf::method::get, "/no_content", no_content },
          { cf::method::post, "/no_content", no_content_post },
          { cf::method::get, "/bad_request", bad_request },
          { cf::method::get, "/closure", [&](auto ctx){ return "closure"; } },
          { cf::method::get, "////sani////ti///i///z///e", ok },
          { cf::method::get, "/route/:with/a/lot/:of/:var", ok },
          { cf::method::get, "/route/:with/*/wildcard/*/and/**/double/*", ok },
          { cf::method::get, "/route/:with/:var/and/some/*/wildcards/*", ok },
          { "hello_middleware", hello_middleware },
          { "stop_middleware", stop_middleware } }
    };
    app.forever();

    auto ctx = cf::context{"/ok", cf::method::get};
    app.get_router().dispatch(ctx);
}
