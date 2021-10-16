#include <cxxabi.h>

#include <iostream>

struct A {};

template <typename T>
void print_type(T val) {
    /* typeid().name() 返回的是类型的简写，并不直观 */
    /* const char* name = typeid(val).name(); */
    /* __cxa_demangle可以实现复杂类型的直观输出 */
    const char* name =
        abi::__cxa_demangle(typeid(val).name(), nullptr, nullptr, nullptr);
    while (*name != '\0') {
        std::cout << *name;
        name += 1;
    }
    std::cout << '\n';
}

int main(int argc, char* argv[]) {
    int a{1};
    float b{2.71828};
    double c{3.1415926};
    A obj{};

    print_type(a);
    print_type(b);
    print_type(c);
    print_type(obj);

    return 0;
}
