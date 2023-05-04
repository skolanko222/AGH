#include <type_traits>
 
 
struct s_default {
  s_default() = default;
};

struct s_no_default {
  s_no_default() = delete;
};
 
int main() {
    static_assert(std::is_default_constructible<s_default>::value,
                  "Data Structure requires default-constructible elements");

    constexpr int x = 7;
    static_assert(x == 7,
                  "Test");


    static_assert(std::is_default_constructible<s_no_default>::value,
                  "Data Structure requires default-constructible elements");
}