#include <iostream>
#include <map>
#include <string>


int main()
{
    std::map<std::string, size_t> m { {"b", 1}, {"c", 2}, {"d", 3} };

    //准备一个提示器，指向map的末尾
    auto insert_it (std::end(m));

    //插入元素
    for (const auto &s : {"z", "y", "x", "w"}) {
        insert_it = m.insert(insert_it, {s, 1});
    }    

    //在最右侧位置插入最左侧元素
    m.insert(std::end(m), {"a", 1});
    for (const auto & [key, value] : m) {
        std::cout << "\"" << key << "\": " << value << "\n";
    }
    std::cout << '\n';
}