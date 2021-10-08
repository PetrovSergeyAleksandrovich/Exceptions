#include <iostream>
#include <map>

int main() {

    std::map<int, int> list_a;
    std::map<int, std::map<int, int>> list_b;

    list_b.insert(std::pair<int, std::pair<int, int>>(1, (2, 3)));

    return 0;
}
