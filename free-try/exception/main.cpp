#include <exception>
#include <iostream>

void func()
{
    std::cout<<__FUNCTION__<<std::endl;
    throw std::invalid_argument("Invalid argument");
    throw std::bad_alloc();
    throw std::bad_cast();
    throw std::bad_typeid();
    throw std::bad_exception();
    throw std::logic_error("Logic error");
    throw std::domain_error("Domain error");
    throw std::invalid_argument("Invalid argument");
    throw std::length_error("Length error");
    throw std::out_of_range("Out of range");
    throw std::runtime_error("Runtime error");
    throw std::range_error("Range error");
    throw std::overflow_error("Overflow error");
    throw std::underflow_error("Underflow error");
    throw std::system_error(std::error_code());
    throw std::bad_function_call();
    throw std::bad_weak_ptr();
    throw std::bad_array_new_length();
    throw std::ios_base::failure("Ios base failure");
}


int main()
{
    
    try
    {
        func();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}