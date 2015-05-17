#include <cppful.h>
#include <string>

struct person : public cf::orm::object<person, cf::orm::mysql_factory> {
    int id;
    cf::orm::tinytext name;
    unsigned int age;

    person(int id, const cf::orm::tinytext& name, unsigned int age)
    : id(id)
    , name(name)
    , age(age) {
        this->fields = {
            { "id", { this->id } },
            { "name", { this->name } },
            { "age", { this->age} }
        };
    }

    person()
    : person(0, "", 0) {}

    person(const cf::orm::tinytext& name, unsigned int age)
    : person(0, name, age) {}
};

struct sql_middleware {
    cf::orm::mysql_factory f;

    void operator()(cf::context& ctx) {
        ctx.custom_data.insert(f.make_connection());
    }
};

cf::response make_person(cf::context& ctx) {
    auto conn = ctx.custom_data.get<cf::orm::mysql_connection>();
    auto p = person {
        "Paul Atreides",
        42
    };
    conn.create(p);
}

int main() {
    auto app = server {
        { { cf::method::get, "/person", make_person, {"mysql_middleware"} },
          { "mysql_middleware", sql_middleware{} }}
    }.forever();
}