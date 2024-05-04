#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unsigned roman_to_arab(const string& roman)
{
    std::unordered_map<char, unsigned int> rom_to_arab = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
    };

    // vector<pair<char, unsigned>> roman_to_int = {
    // {'I', 1},
    // {'V', 5},
    // {'X', 10},
    // {'L', 50},
    // {'C', 100},
    // {'D', 500},
    // {'M', 1000}
    // };

    std::unordered_set<std::string> exceptions{ "IV", "IX", "XL", "XL", "XC", "CD", "CM" };
    
    unsigned int len = roman.length();

    unsigned int num = 0;

    for(unsigned int i = 0; i < len - 1; i++)
    {

        // std::string key = roman.substr(i, 2);

        // roman[i] + roman[i + 1] são chars

        std::string s = std::string() + roman[i] + roman[i + 1]; // isto ja converte tudo para string


        if(exceptions.find(s) != exceptions.end())  // (exceptions.find(key) != exceptions.end()) // se for != do iterador exceptions.end()
        // se isto for verdade, entao encontrou uma exceção
        {

            num -= rom_to_arab[roman[i]];

        }
        else
        {
            num += rom_to_arab[roman[i]];
        }
    }

    num += rom_to_arab[roman[len - 1]];

    return num;

}


int main()
{
    { string r = "XV"; cout << roman_to_arab(r) << '\n'; }
    { string r = "LXXXIV"; cout << roman_to_arab(r) << '\n'; }
    { string r = "CMLXIV"; cout << roman_to_arab(r) << '\n'; }
    { string r = "MMMCMXCIX"; cout << roman_to_arab(r) << '\n'; }
    { string r = "MMMDCCCLXXXVIII"; cout << roman_to_arab(r) << '\n'; }

    return 0;
}