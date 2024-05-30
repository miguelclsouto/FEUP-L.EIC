#include <iostream>
#include <vector>

using namespace std;

template<typename T>
// a = min, b = max
T clamp(const T& v, const T& a, const T& b)
{
    return v < a ? a : v > b ? b : v;
}

void show_vector(const vector<vector<int>>& v) 
{
  cout << "{";

    for (const auto& line : v) 
    {
        cout << "{ ";

        for (const auto& elem : line)
            cout << elem << ' ';

        cout << "}";
    }

  cout << "}";
}

int position_max(const vector<vector<int>> &v, const unsigned min_line, const unsigned max_line, const unsigned min_col, const unsigned max_col)
{

    int max = v[min_line][min_col];

    for(unsigned i = min_line; i < max_line + 1; i++)
    {
        for(unsigned j = min_col; j < max_col + 1; j++)
        {
            if (v[i][j] > max)
            {
                max = v[i][j];
            }
        }
    }

    return max;

}

bool max_filter(vector<vector<int>> &v, int n)
{
    
    int n_lines = static_cast<int>(v.size());

    // tinha que verificar isto antes
    if (n < 0)
    {
        return false;
    }

    int n_cols = static_cast<int>(v[0].size());

    if(n % 2 == 0 || n_lines < n || n_cols < n)
    {
        return false;
    }

    // temos que criar um novo vetor

    // uma forma de inicializar o vetor
    // vector<vector<int>> t(n_lines, vector<int>(n_cols, 0));

    // OR

    vector<vector<int>> t;

    for(int i = 0; i < n_lines; i++)
    {
        // assim posso aceder diretamente na coluna
        // vector<int> temp(n_cols);

        // assim faco push_back

        vector<int> temp;

        for(int j = 0; j < n_cols; j++)
        {

            unsigned min_line = ::clamp(i - (int)(n / 2), 0, n_lines - 1);
            unsigned max_line = ::clamp(i + (int)(n / 2), 0, n_lines - 1);
            unsigned min_col = ::clamp(j - (int)(n / 2), 0, n_cols - 1);
            unsigned max_col = ::clamp(j + (int)(n / 2), 0, n_cols - 1);

            // cout << min_line << ' ';

            // cout << max_line << ' ';

            // cout << min_col << ' ';

            // cout << max_col << '\n';

            temp.push_back(position_max(v, min_line, max_line, min_col, max_col));
        }

        t.push_back(temp);

    }

    v = t;

    return true;

}

int main()
{

    { vector<vector<int>> v = { {1,2,3}, {4,5,6}, {7,8,9} };
  bool b = max_filter(v, 3); cout << boolalpha << b;
  show_vector(v); cout << endl; }

  { vector<vector<int>> v =
  { { 8,5,4,2,1 },
    { 1,2,4,5,9 },
    { 3,6,3,7,3 },
    { 5,7,8,1,4 },
    { 9,1,2,6,5 } };
  bool b = max_filter(v, 3); cout << boolalpha << b;
  show_vector(v); cout << endl; }

  { vector<vector<int>> v = { { 8,5,4,2,1 }, { 9,1,2,6,5 } };
  bool b = max_filter(v, 3); cout << boolalpha << b;
  show_vector(v); cout << endl; }

  { vector<vector<int>> v =
    { { -8,-5,4,2,1,-1,7 },
      { -1,-2,4,5,9,0,4 },
      { -3,6,-3,-7,3,-10,-7 },
      { 5,7,8,1,4,-2,-31 },
      { -9,1,-2,6,5,-5,-16 } };
  bool b = max_filter(v, 3); cout << boolalpha << b;
  show_vector(v); cout << endl; }

  { vector<vector<int>> v =
    { { -8,-5,4,2,1,-1,7 },
      { -1,-2,4,5,9,0,4 },
      { -3,6,-3,-7,3,-10,-7 },
      { 5,7,8,1,4,-2,-31 },
      { -9,1,-2,6,5,-5,-16 } };
  bool b = max_filter(v, 5); cout << boolalpha << b;
  show_vector(v); cout << endl; }

    return 0;
}