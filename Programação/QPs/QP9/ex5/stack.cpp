#include "Stack.h"

using namespace std;

#define TEMPLATE template<typename T>

TEMPLATE
Stack<T>::Stack()
{
    elements.clear();
}

TEMPLATE
size_t Stack<T>::size() const
{
    return elements.size();
}

TEMPLATE
bool Stack<T>::peek(T& elem) const
{

    if(elements.empty())
    {
        return false;
    }

    elem = elements[elements.size() - 1];

    return true;

}

TEMPLATE
bool Stack<T>::pop(T& elem)
{

    // if(elements.empty())
    // {
    //     return false;
    // }

    // elem = elements[elements.size() - 1];

    // elements.pop_back();

    // return true;

    bool y = this->peek(elem);

    if(!y)
    {
        return false;
    }

    elements.pop_back();

    return y; // return true

}

TEMPLATE
void Stack<T>::push(const T& elem)
{
    elements.push_back(elem);
}


int main()
{
 { Stack<int> s;
  const Stack<int>& r = s;
  int v = -1;
  cout << r.size()  << ' ' << boolalpha
       << r.peek(v) << ' ' << v << ' '
       << s.pop(v)  << ' ' << v << ' '
       << s.size() << '\n'; }
       { Stack<int> s;
  int v = -1;
  s.push(123);
  cout << s.size()  << ' ' << boolalpha
       << s.peek(v) << ' ' << v << ' '
       << s.pop(v)  << ' ' << v << ' '
       << s.size() << '\n'; }
       { Stack<string> s; string v;
  s.push("a"); s.push("b"); s.push("c");
  cout << s.size();
  while(s.pop(v)) cout << ' ' << v;
  cout << ' ' << s.size() << '\n'; }
  { Stack<int> s; int v = -1;
  s.push(111); s.push(222); s.push(333);
  cout << s.size();
  while(s.peek(v)) {
    cout << ' ' << v;
    s.pop(v);
    cout << ' ' << v;
    if (v % 2 != 0) s.push(v + 1);
    cout << ' ' << s.size(); }
  cout << '\n'; }
    return 0;
}

#undef TEMPLATE