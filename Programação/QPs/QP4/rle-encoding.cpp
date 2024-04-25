#include <iostream>
#include <math.h>

using namespace std;

void int_to_str(int& n,const char str[], int& pos)
{
    char c = str[pos];

    n = 1;

    pos++;

    // ou podia guardar a pos inicial numa variavel
    // temporaria e depois calculava o numero usando pos_f - pos_i;

    while(str[pos] == c)
    {
        pos++;
        n++;
    }

}

void rle_encode(const char str[], char rle[])
{
    int i = 0;
    int j = 0;
    while(str[i] != '\0')
    {
        int n;

        

        char c = str[i];

        int_to_str(n, str, i);

        int num = n;

        int size = 0;

        while(num != 0)
        {
            size++;
            num /= 10;
        }

        while(size != 0)
        {
            
            num = n / (int) pow(10, size - 1);
            n = n % (int) pow(10, size - 1);
            rle[j] = num + '0';
            j++;
            size--;
        }

        rle[j] = c;

        j++;

    }

    rle[j] = '\0';
}

// void int_to_str(int& n, const char str[], int& pos)
// {

// }

int main()
{
{ char rle[1] = { -1 }; 
  rle_encode("", rle);
  cout << rle << endl; }
  { char rle[2 + 1] = { -1, -1, -1 }; 
  rle_encode("a", rle);
  cout << rle << endl; }
  { char rle[10 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; 
  rle_encode("abcde", rle);
  cout << rle << endl; }
  { char rle[9 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; 
  rle_encode("aaaaabbbbbbbbbbbcccd", rle);
  cout << rle << endl; }
  { char rle[3 + 1] = { -1, -1, -1, -1 }; 
  rle_encode("xxxxxxxxxxxxxxxxxxxx", rle);
  cout << rle << endl; }
    return 0;
}