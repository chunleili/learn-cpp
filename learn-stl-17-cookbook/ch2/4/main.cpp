#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <list>
using namespace std;

template <typename T>
void print(T v)
{
    for (auto i : v)
    {
        cout << i << ", ";
    }
    cout << '\n';
}

// void insert_sorted(vector<string> &v, const string &word)
// {
//     const auto insert_pos (lower_bound(begin(v), end(v), word));
//     v.insert(insert_pos, word);
// }

template <typename C, typename T>
void insert_sorted(C &v, const T &item)
{
    const auto insert_pos (lower_bound(begin(v), end(v), item));
    v.insert(insert_pos, item);
}

int main()
{
    /* --------------------------- example1 对vector排序 --------------------------- */
    vector<string> v{"some", "random", "words",
                     "without", "order", "aaa",
                     "yyy"};
    print(v);
    std::cout<<std::boolalpha<<is_sorted(begin(v), end(v))<<std::endl;

    assert(false == is_sorted(begin(v), end(v)));
    sort(begin(v), end(v));
    assert(true == is_sorted(begin(v), end(v)));

    std::cout<<std::boolalpha<<is_sorted(begin(v), end(v))<<std::endl;
    print(v);

    /* ---------------------------- example2 插入时保持有序 ---------------------------- */

    insert_sorted(v, "foobar");
    insert_sorted(v, "zzz");
    print(v);


    /* ------------------------------ example3 list ----------------------------- */
    list<string> l{"some", "random", "words",
                     "without", "order", "aaa",
                     "yyy"};
    cout<<"list: ";
    insert_sorted(l, "foobar");
    print(l);
}
