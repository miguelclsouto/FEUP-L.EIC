#include <iostream>
#include <sstream>

#include <string>
#include <vector>
#include <list>

template <typename Itr> 
std::string to_string(Itr start, Itr end)
{
    std::ostringstream out;

    out << "[ ";
    
    while(start != end)
    {

        out << *start;

        out << ' ';

        start++;

    }

    out << ']';

    return out.str();
}

template <typename Itr, typename T> 
int replace(Itr start, Itr end, const T& a, const T& b)
{
    int acc = 0;

    while(start != end)
    {
        if (*start == a)
        {
            *start = b;
            acc++;
        }

        start++;
    }

    return acc;

}

int main()
{
{ std::vector<int> v;
  std::cout << ::replace(v.begin(), v.end(), 0, 1) << ' '
       << to_string(v.cbegin(), v.cend()) << '\n'; }
       { std::vector<int> v { 1, 2, 3, 3, 4 };
  std::cout << ::replace(v.begin(), v.end(), 3, 0) << ' '
       << to_string(v.cbegin(), v.cend()) << '\n'; }
       { std::vector<int> v { 5, 1, 2, 3, 4, 5 };
  std::cout << ::replace(v.begin() + 1, v.end() - 1, 5, 0) << ' '
       << to_string(v.cbegin(), v.cend()) << '\n'; }
       { std::list<std::string> l { "C++", "Java", "C++", "Python", "Rust", "C" } ;
  std::cout << ::replace(l.begin(), l.end(), std::string("C++"), std::string("Rust")) << ' '
       << ::replace(l.begin(), l.end(), std::string("C"), std::string("Rust")) << ' '
       << to_string(l.cbegin(), l.cend()) << '\n'; }
       { std::string s = "Hello world";
  std::cout << ::replace(s.begin(), s.end(), 'l', 'L') << ' '
       << to_string(s.cbegin(), s.cend()) << ' ' 
       << ::replace(s.rbegin(), s.rend(), 'o', 'O') << ' '
       << to_string(s.crbegin(), s.crend()) <<  ' '
       << to_string(s.cbegin(), s.cend()) << '\n'; }

    return 0;
}