#include <iostream>

#include <cmath>
using namespace std;

int HexatoDec(char c);

unsigned long hstr_to_integer(const char hstr[])
{
    // enum hexa_to_dec1 {A = 10, B, C, D, E, F};
    // enum hexa_to_dec2 {a = 10, b, c, d, e, f};

    unsigned long num = 0; // acumular

    int i = 0; // e mais facil ter um int para ter uma nocao das iteracoes

    while (hstr[i] != '\0') // '\0'
    {
        // int temp = HexatoDec(hstr[i]);

        num = num * 16 + HexatoDec(hstr[i]);

        i++;
        
    }

    return num;
}

int HexatoDec(char c)
{
    switch(c)
    {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6':
        case '7': case '8': case '9': // entre 0 e 9
            // return (int) c;
            // return std::stoi(c);

            return c - '0'; // isto ja faz a conversao para int

        case 'A': case 'a':
            return 10;
        case 'B': case 'b':
            return 11;
        case 'C': case 'c':
            return 12;
        case 'D': case 'd':
            return 13;
        case 'E': case 'e':
            return 14;
        case 'F': case 'f':
            return 15;
            
    }

    return 0;
}

int main()
{
    cout << hstr_to_integer("0");
    cout << hstr_to_integer("A");
    cout << hstr_to_integer("19");
    cout << hstr_to_integer("fF");
    cout << hstr_to_integer("CafeBabe2022");

    return 0;

}