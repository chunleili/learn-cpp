#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(std::vector<int> v)
{
    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << '\n';
}


int main()
{
    /* ------------------------------ example 1 移除2 ----------------------------- */
    vector<int> v{1, 2, 3, 2, 5, 2, 6, 2, 4, 8};
    const auto new_end(remove(begin(v), end(v), 2));
    print(v);



    /* ------------------------- example 2 移除奇数 ------------------------------- */
    const auto odd([](int i){return i % 2 != 0;});
    v.erase(remove_if(begin(v), end(v), odd), end(v));
    v.shrink_to_fit() ;
    print(v);




    return 0;
}