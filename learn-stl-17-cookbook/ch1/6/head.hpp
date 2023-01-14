#pragma once
#include <iostream>
class process_monitor {
public:
//使用inline定义类静态变量，可以在.hpp文件中定义，而不会产生符号重定义问题。
inline static const std::string standard_string{"some static globally available string"};
//如果没有inline 则会报错error: static data member of type 'const std::string' (aka 'const basic_string<char, char_traits<char>, allocator<char>>') must be initialized out of line

};



//使用inline定义全局变量（实例），可以在.hpp文件中定义，而不会产生符号重定义问题。
//如果没有inline，则会报错：duplicate symbol _global_process_monitor in
inline process_monitor global_process_monitor;
// process_monitor global_process_monitor;


//inline关键字告诉编译器：只需要接受第一个找到的符号，然后使用它即可。因此不会出现符号重定义的问题。