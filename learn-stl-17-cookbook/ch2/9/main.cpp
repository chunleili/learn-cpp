#include <iostream>
#include <set>
#include <string>
#include <iterator>

using namespace std;

int main()
{
    set<string> s;

    istream_iterator<string> it{cin};
    istream_iterator<string> end;

    copy(it, end, inserter(s, begin(s)));

    for (const auto word : s)
    {
        cout << word << ", ";
    }
    cout << '\n';
}

//run with :
// echo "a a a b c foo bar foobar foo bar bar" | ./ch2-9  