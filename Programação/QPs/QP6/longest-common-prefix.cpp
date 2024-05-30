#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longest_prefix(const vector<string>& v)
{
    string longpref = v[0]; // e o primeiro string
    
    for(int i = 1; i < static_cast<int>(v.size()); i++)
    {

       for(int j = 0; j < static_cast<int>(v[i].size()); j++)
       {
            if(!(j < static_cast<int>(longpref.size()) && longpref[j] == v[i][j])) // if (j >= static_cast<int>(longpref.size()) || longpref[j] != v[i][j])
            {
                // entao vou querer atualizar o longest prefix
                longpref = longpref.substr(0, j); // a length e j;
                break;
                // posso entao acabar este loop
                // para ir para o proximo valor / a proxima iteracao
            }
       }

       if (longpref.empty())
       {
            break; // nao vale a pena procurar mais
       }

    }

    return longpref;
}

int main()
{
    cout << "\"" << longest_prefix({ "apple", "apply", "ape", "april" }) << "\"\n";
    cout << "\"" << longest_prefix({ "ap", "apple", "apply", "ape", "april", "aq", "x" }) << "\"\n";
    cout << "\"" << longest_prefix({ "geezer", "geeksforgeeks", "geeks", "geek",  }) << "\"\n";
    cout << "\"" << longest_prefix({ "sedatesingratiateconcomitant", "sedatesparleypoliteness", "sedateselbowsHahn", "sedatesgloweringimbecility's", "sedatesbuttershexing", "sedatesKwangju'smulch's", "sedatesunwiserN", "sedatesprepossessedboggles", "sedatesinterrelationshipdialings", "sedatesgropesNelsen's", "sedatesMayfaircondemnations" }) << "\"\n";
    cout << "\"" << longest_prefix({ "symmetricstalwartscorn'flowers", "symmetricShetland'ssuccessfully", "symmetricreceiver'shipsteed", "symmetricGrailsflown", "symmetricpromenadingoutflank", "symmetricdrugg'ingseizure", "symmetricsanctumsove'rprinting", "symmetricCitroentransgr'essed", "symmetricdissembledwinging", "symmetric'recoupingCinderella" }) << "\"\n";
    return 0;
}
