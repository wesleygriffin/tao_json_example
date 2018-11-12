#include "tao/json.hpp"

template <typename T>
struct MyTraits : public tao::json::traits<T> {};

using MyValue = tao::json::basic_value<MyTraits>;

struct MyPair {
  bool first;
  int second;
};

template <>
struct MyTraits<MyPair> : public tao::json::binding::object<
                            TAO_JSON_BIND_REQUIRED("first", &MyPair::first),
                            TAO_JSON_BIND_REQUIRED("second", &MyPair::second)> {
};

std::string const str1 = R"({
  "first": true,
  "second": 42
})";

int main(void) {
  MyValue const value = tao::json::basic_from_string<MyTraits>(str1);
  auto pair = value.as<MyPair>();
}
