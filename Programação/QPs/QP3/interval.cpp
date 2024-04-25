#include <iostream>
#include "interval.h"

using namespace std;

bool later(const time_of_day& a, const time_of_day& b);
bool inside_interval(const time_of_day& a, const interval& v);
bool later_or_now(const time_of_day& a, const time_of_day& b);

interval intersection(interval a, interval b)
{

    // posso verificar se ele comeca / acaba dentro do outro intervalo, para verificar se houve intersecao

    interval c {{0, 0}, {0, 0}}; // inicializei o intervalo 

    time_of_day tmp[2];

    int i = 0;

    if (later_or_now(a.start, b.start) && later_or_now(a.end, b.end) && later_or_now(b.start, a.start) && later_or_now(b.end, a.end))
    {
        return a;
    }

    if (later(a.start, a.end) || later(b.start, b.end))
    {
        return c;
    }



    if (later(b.end, a.start) && later(a.end, b.start)) // caso o A comece depois do B acabar
    {
        // HOUVE INTERSECAO
        // agora posso verificar onde houve a intersecao

        if (inside_interval(a.start, b))
        {   

            tmp[i] = a.start;

            i++;
            // VERIFICAR SE O TEMPO ESTA NO INTERVALO

        }

        if (inside_interval(a.end, b))
        {   

            tmp[i] = a.end;

            i++;
            // VERIFICAR SE O TEMPO ESTA NO INTERVALO

        }

        if (inside_interval(b.start, a))
        {   

            tmp[i] = b.start;

            i++;
            // VERIFICAR SE O TEMPO ESTA NO INTERVALO

        }

        if (inside_interval(b.end, a))
        {   

            tmp[i] = b.end;

            i++;
            // VERIFICAR SE O TEMPO ESTA NO INTERVALO

        }

        

        if (i == 0)
        {
            tmp[0] = a.start;
            tmp[1] =  a.end;

            // c = {a.start, a.end};
        }

        else if (i == 1)
        {
            if (later_or_now(a.start, b.start) && later_or_now(b.start, a.start))
            {
                tmp[1] = a.start;
            }
            else
            {
                tmp[1] = a.end;
            }

        }


        c = {tmp[0], tmp[1]};

        if (later(c.start, c.end))
        {
            c = {c.end, c.start};
            
            // TROQUEI A ORDEM DOS START E DO END
        }


    }

    return c;

}

bool later(const time_of_day& a, const time_of_day& b)
{
    if (a.h > b.h)
    {
        return true;
        // entao ja sabemos que a acontece mais tarde do que b
    }
    else if (a.h == b.h)
    {
        if (a.m > b.m)
        {
            return true;
        }

    }

    return false;
}

bool later_or_now(const time_of_day& a, const time_of_day& b) // na verdade, aqui podia so ter chamado o funcao later e depois ter implementado a parte do now, verificando se os tempos sao iguals
{
    if (a.h > b.h)
    {
        return true;
        
    }
    else if (a.h == b.h)
    {
        if (a.m >= b.m)
        {
            return true;
        }

        
    }
    
    return false;
}

bool inside_interval(const time_of_day& a, const interval& v)
{  

    // posso verificar se ele comeca / acaba dentro do outro intervalo, para verificar se houve intersecao

    if (later(v.end, v.start)) // v.end esta depois do v.start
    {
        // Entao so preciso de verificar a se o valor esta entre estes 2
        if (later(v.end, a) && later(a, v.start))
        {
            return true;
        }

        // return false;
    }
    else // v.start esta depois do v.end
    {
        // AGORA VERIFICO SE ESTA DEPOIS DO START OU ANTES DO END 
        // OU VERIFICO SE NAO ESTA ENTRE O END E O START
        // SE NAO ESTA DEPOIS DO END E ANTES DO START
        
        if (later(a, v.start) || later(v.end, a))
        {
            return true;
        }
        
    }

    return false;

}


int main()
{
    cout << intersection( { { 12, 30 }, { 14, 30 } },
                        { { 17, 30 }, { 18, 30 } } ) << '\n';
    cout << intersection( { { 12, 30 }, { 14, 30 } },
                      { { 14, 30 }, { 18, 30 } } ) << '\n';
    cout << intersection( { { 12, 30 }, { 14, 31 } },
                      { { 14, 30 }, { 18, 30 } } ) << '\n';
    cout << intersection( { { 14, 30 }, { 15, 59 } },
                      { { 11, 30 }, { 14, 31 } } ) << '\n';
    cout << intersection( { {  4, 30 }, {  7, 59 } },
                      { {  4,  0 }, {  7, 29 } } ) << '\n';
    cout << intersection( { { 23,  0 }, { 23, 58 } },
                      { { 22, 45 }, { 23, 59 } } ) << '\n';
    cout << intersection( { { 17,  0 }, { 19,  0 } },
                      { { 15,  0 }, { 17,  0 } } ) << '\n';
    
    return 0;
}