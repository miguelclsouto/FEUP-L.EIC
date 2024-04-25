#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename U, typename V>
class Pair
{
    private:

        U first_;
        V second_;

    public:
    
        Pair(U first, V second) : first_(first), second_(second){};

        U get_first() const
        {
            return this->first_;
        }
        V get_second() const
        {
            return this->second_;
        }

        void show() const
        {
            cout << '{' << this->first_ << ',' << this->second_ << '}';
        }
};

template<typename G, typename H>
void show(const vector<Pair<G, H>>& v)
{
    cout << '{';

    for(Pair<G, H> p : v)
    {
        p.show();
    }

    cout << '}';
    
}

template<typename A, typename B>
void sort_by_first(vector<Pair<A, B>>& v) // TENHO QUE PASSAR O VETOR POR REFERENCIA
{
    // lambda function
    sort(v.begin(), v.end(), [](const Pair<A, B>& a, const Pair<A, B>& b) { return a.get_first() < b.get_first(); });
}

template<typename C, typename D>
void sort_by_second(vector<Pair<C, D>>& v) // TENHO QUE PASSAR O VETOR POR REFERENCIA
{
    // lambda function
    sort(v.begin(), v.end(), [](const Pair<C, D>& c, const Pair<C, D>& d) { return c.get_second() < d.get_second(); });
}


int main()
{
{ vector<Pair<string, int>> persons = { {"Maria",17},{"Ana",21},{"Pedro",19} };
  sort_by_first(persons);
  show(persons); cout << '\n'; }
{ vector<Pair<string, int>> persons = { {"Ana",19},{"Rui",16} };
  sort_by_second(persons);
  show(persons); cout << '\n'; }
{ vector<Pair<string, int>> teams = { {"Porto",91},{"Benfica",74},{"Sporting",85} };
  sort_by_first(teams);
  show(teams); cout << '\n'; }
  { vector<Pair<string, int>> teams = { {"Porto",91},{"Benfica",74},{"Sporting",85} };
  sort_by_second(teams);
  show(teams); cout << '\n'; }
  { vector<Pair<string, int>> calories = { {"orange",37},{"egg",146},{"apple",56},{"yogurt",51} };
  sort_by_second(calories);
  show(calories); cout << '\n';}
    return 0;
}