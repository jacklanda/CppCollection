#include <iostream>
#include <map>

int main() {
    std::map<int, int> m;
    m.insert({{0, 1055}, {1, 965}, {2, 995}});
    for (auto p : m) {
        std::cout << p.first << ':' << p.second << ' ';
    }
    std::cout << '\n';

    sort(m.begin(), m.end(),
         [](auto x, auto y) { return x.second < y.second; });

    for (auto p : m) {
        std::cout << p.first << ':' << p.second << ' ';
    }
    std::cout << '\n';
}
