#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

template <typename... Ts>
auto sum(Ts... ts);

template <typename... Ts>
auto sum(Ts... ts)
{
    std::cout << "size of paramter pack: " << sizeof...(ts) << std::endl;
    return (ts + ...);
}

template <typename... Ts>
auto product(Ts... ts)
{
    return (ts * ... * 1);
}

template <typename R, typename... Ts>
auto matches(const R &range, Ts... ts)
{
    return (std::count(std::begin(range), std::end(range), ts) + ...);
}

template <typename T, typename... Ts>
bool insert_all(T &set, Ts... ts)
{
    return (set.insert(ts).second && ...);
}

template <typename T, typename... Ts>
bool within(T min, T max, Ts... ts)
{
    return ((min <= ts && ts <= max) && ...);
}


template <typename T, typename ... Ts>
void insert_all(std::vector<T> &vec, Ts ... ts){
	(vec.push_back(ts), ...);
}



int main()
{
    int the_sum{sum(1, 2, 3, 4, 5)}; // value: 15
    std::cout << the_sum << std::endl;
    /* ------------------------------------ a ----------------------------------- */

    std::string a{"Hello "};
    std::string b{"World"};
    std::string c{"!"};
    std::cout << sum(a, b, c) << '\n'; // output: Hello World
    
    /* ------------------------------------ a ----------------------------------- */

    product(2, 3, 4);
    std::cout << product(2, 3, 4) << std::endl;

    /* ------------------------------------ a ----------------------------------- */

    std::vector<int> v{1, 2, 3, 4, 5};

    cout << matches(v, 2, 5) << endl;                  // return 2
    cout << matches(v, 100, 200) << endl;              // return 0;
    cout << matches("abcdefg", 'x', 'y', 'z') << endl; // return 0
    cout << matches("abcdefg", 'a', 'b', 'f') << endl; // return 3
    /* ------------------------------------ a ----------------------------------- */

    std::set<int> my_set{1, 2, 3};

    auto res1 = insert_all(my_set, 4, 5, 6); // Returns true
    auto res2 = insert_all(my_set, 7, 8, 2); // Returns false, because the 2 collides

    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;

    /* ------------------------------------ a ----------------------------------- */
    auto res21 = within(10, 20, 1, 15, 30);       // --> false
    auto res22 = within(10, 20, 11, 12, 13);      // --> true
    auto res23 = within(5.0, 5.5, 5.1, 5.2, 5.3); // --> true

    std::cout << res21 << std::endl;
    std::cout << res22 << std::endl;
    std::cout << res23 << std::endl;

    std::string aaa {"aaa"};
std::string bcd {"bcd"};
std::string def {"def"};
std::string zzz {"zzz"};

within(aaa, zzz, bcd, def); // --> true
within(aaa, def, bcd, zzz); // --> false




/* ------------------------------------ a ----------------------------------- */
	std::vector<int> vv{1, 2, 3};
	insert_all(vv, 4, 5, 6);
    std::cout<<"vv:";
    for(auto x:vv){
        std::cout<<x<<'\t';
    }
    return 0;
}