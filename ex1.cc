#include "tao/json.hpp"
#include <utility>

template <typename T>
struct MyTraits : public tao::json::traits<T> {};

using MyValue = tao::json::basic_value<MyTraits>;

template <typename U, typename V>
struct MyTraits<std::pair<U, V>>
  : public tao::json::binding::object<
      TAO_JSON_BIND_REQUIRED("first", &std::pair<U, V>::first),
      TAO_JSON_BIND_REQUIRED("second", &std::pair<U, V>::second)> {};

std::string const str1 = R"({
  "first": true,
  "second": 42
})";

int main(void) {
  MyValue const value = tao::json::basic_from_string<MyTraits>(str1);
  auto pair = value.as<std::pair<bool, int>>();
}

