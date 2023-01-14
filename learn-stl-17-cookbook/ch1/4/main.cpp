#include <tuple>
#include <iostream>

// 让我们自定义一个模板类然后使用模板类型推导;
template <typename T1, typename T2, typename T3>
class my_wrapper
{
    T1 t1;
    T2 t2;
    T3 t3;

public:
    explicit my_wrapper(T1 t1_, T2 t2_, T3 t3_)
        : t1{t1_}, t2{t2_}, t3{t3_}
    {
    }
};

// example 3
template <typename T>
struct sum
{
    T value;

    template <typename... Ts>
    sum(Ts &&...values) : value{(values + ...)} {}

};


template <typename ... Ts>
sum(Ts&& ... ts) -> sum<std::common_type_t<Ts...>>;


int main()
{
    /* ------ //example 1 最简单的模板类型推导, 在我们使用pair或者tuple时，可以不需要传入类型，编译器会自动推导 ------ */
    std::pair p1(1, 2);
    std::tuple t1(1, 2, 3);

    /* -------------------- //example 2 我们自定义一个模板类，然后使用模板类型推导 ------------------- */
    my_wrapper w1(1, 2, 3); // 这里我们使用了模板类型推导，编译器会自动推导出T1,T2,T3的类型为int;



    /* ---------------------- //example 3 commmon_type_t会自动找到共同的类型 ---------------------- */;
    sum s{1u, 2.0, 3, 4.0f};
    sum string_sum{std::string{"abc"}, "def"};
    std::cout << s.value << '\n'
              << string_sum.value << '\n';
}