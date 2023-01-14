#include <iostream>
#include <string>
#include <vector>

template <typename T>
class addable
{
public:
    T val;

public:
    addable(T v) : val{v} {}

    template <typename U>
    T add(U x) const
    {
        if constexpr (std::is_same<T, std::vector<U>>::value)
        {
            std::cout<<"vector"<<std::endl;
            
            auto copy(val);
            for (auto &n : copy)
            {
                n += x;
            }
            return copy;
        }
        else
        {
            std::cout<<"not vector"<<std::endl;
            return val + x;
        }
    }

};





int main()
{
    addable<int>{1}.add(2);               // is 3
    addable<float>{1.f}.add(2);           // is 3.0
    addable<std::string>{"aa"}.add("bb"); // is "aabb"

    std::vector<int> v{1, 2, 3};
    addable<std::vector<int>>{v}.add(10); // is std::vector<int> {11, 12, 13}

    std::vector<std::string> sv{"a", "b", "c"};
    addable<std::vector<std::string>> sss{sv};
    sss.add(std::string{"z"}); // is {"az", "bz", "cz"};

}