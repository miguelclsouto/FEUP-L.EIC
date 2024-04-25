#include <iostream>

#include "interval.h"


bool later_time(const time_of_day& a, const time_of_day& b);

bool later_time(const time_of_day& a, const time_of_day& b) // apenas later, nao later ou igual
{
    if (a.h > b.h)
    {
        return true;
    }
    else if (a.h < b.h)
    {
        return false;
    }
    else // a.h == b.h
    {
        if(a.m > b.m)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool same_time(const time_of_day& a, const time_of_day& b)
{
    return (!later_time(a, b) && !later_time(b, a)); // a.h == b.h && a.m == b.m
}

bool time_in_interval(const time_of_day& a, const interval& b)
{
    // e mais facil verificar se nao esta contido

    if (a.h > b.end.h || a.h < b.start.h)
    {
        return false;
    }

    else if ((a.h == b.start.h && a.m < b.start.m) || (a.h == b.end.h && a.m >= b.end.m)) // se for igual consideramos que nao esta
    {
        return false;
    }

    else
    {
        return true;
    }


}

interval interval_union(const interval& a, interval& b) // o return type e void pq ja estou a modificar o interval& u
{   
    // como nao e a intersecao e mais facil
    // e so ver qual o intervalo que comeca antes e o que acaba depois
    interval u;
    if(later_time(b.start, a.start))
    {
        u.start = a.start;
    }
    else
    {
        u.start = b.start;
    }

    if(later_time(a.end, b.end))
    {
        u.end = a.end;
    }
    else
    {
        u.end = b.end;
    }

    return u;
    
    
}



void interval_union_better(const interval& a, interval& u) // o return type e void pq ja estou a modificar o interval& u
{   

    // e so ver qual o intervalo que comeca antes e o que acaba depois
    
    if(later_time(u.start, a.start))
    {
        u.start = a.start;
    }

    if(later_time(a.end, u.end))
    {
        u.end = a.end;
    }

}

int calc_minutes(time_of_day start, const time_of_day& end)
{
    int minutes = 0;

    while(!same_time(start, end))
    {
        while(start.h != end.h)
        {
            minutes += 60; // somar 60 minutos e somar uma hora para o start
            start.h += 1;
            start.h = start.h % 24;
        }
        // quando tiverem igual vou fzr

        minutes += end.m - start.m;

        return minutes;

    }

    return minutes;

}

int search_intervals(time_of_day t, const interval a[], int n, interval& u)
{
    // int minutes = 0; // queremos fzr return dos minutes

    u = {t, t};

    for(int i = 0; i < n; i++)
    {
        if(time_in_interval(t, a[i]))
        {
            interval_union_better(a[i], u);
        }
        // else just continue
    }

    // agora tenho que calcular os minutos

    

    return calc_minutes(u.start, u.end);

}

int main()
{
    { const int n = 1;
  const time_of_day t = { 13, 00 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; }

  { const int n = 2;
  const time_of_day t = { 14, 30 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                  { { 14, 30 }, { 15, 30 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; }

  { const int n = 2;
  const time_of_day t = { 12, 30 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                  { { 14, 30 }, { 15, 30 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; }

  { const int n = 2;
  const time_of_day t = { 15, 30 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                  { { 14, 30 }, { 15, 30 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; } 

  { const int n = 5;
  const time_of_day t = { 15, 15 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                  { { 14, 30 }, { 15, 30 } }, 
                  { { 15, 10 }, { 16, 10 } }, 
                  { {  9, 30 }, { 15, 15 } }, 
                  { {  9, 45 }, { 15, 16 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; } 

    return 0;
}