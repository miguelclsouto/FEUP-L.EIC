#include <iostream>

#include <vector>
#include <iostream>

#include "smatrix.h"

using namespace std;

void sum(const smatrix& a, const smatrix& b, smatrix& r)
{

    // AS DUAS MATRIZES ESTAO SORTED
    // vou usar um while em que uso dois indexes para cada uma das sparse matrixes

    // POSSO USAR UM LOOP PARA DESCOBRIR QUAL TERIA QUE SER O TAMANHO DA MATRIX FINAL
    // se as cenas nao tivessem sorted, poderia fzr sort
    // poderia calcular o valor minimo de cada vez, tendo em conta o valor minimo anterior,
    // porque o prox valor tera que ser o valor minimo depois desse
    // e depois procurava em ambas a matrixes por esse valor

    // como ambas estao sorted, posso so ir vendo qual tem o menor valor e entao adiciono se for diferente de 0
    // se tiverem o mesmo valor adiciono o conteudo das duas e verifico se da 0, se sim, entao nao quero adicionar a matriz resultante,
    // se nao quero adicionar a matriz resultante.
    // Isto e semelhante ao MERGE SORT ALGORITHM.

    
    unsigned int i = 0, j = 0;

    unsigned int a_size = a.size(), b_size = b.size();

    

    while(i < a_size && j < b_size)
    {
        // tenho que verificar o do i e o do j e ver qual e maior / menor ou se sao iguais
        // tenho que descobrir qual e que devo ver primeiro
        // bool i_primeiro = false; // se i_primeiro = true, entao vejo o i primeiro,
        // se nao vejo o j primeiro

        // primeiro vemos a row e depois a col

        if (b[j].row > a[i].row || (b[j].row == a[i].row && b[j].col > a[i].col)) // o j esta depois do a 
        {

            // aqui e so acrescentar o a[i] ao r

            r.push_back(a[i]);
            
            i++;

        }
        else if(b[j].row == a[i].row && b[j].col == a[i].col)
        {
            // aqui sao iguais por isso temos que acrescentar os 2
            // aqui ja tenho que somar os valores
            // r[k].row = a[i].row; // b[j].row == a[i].row
            // r[k].col = a[i].col; // b[j].col == a[i].col
            // r[k].value = a[i].value + b[j].value;
            
            // SE A SOMA DE AMBOS FOR 0 NAO VAIS QUERER ADICIONAR ISSO A SPARSE MATRIX

            int temp = a[i].value + b[j].value;

            if(temp != 0)
            {
                r.push_back({a[i].row, a[i].col, temp}); // array de structs smatrix
            }

            i++;
            j++;
        }
        else
        {
            // b e antes
            // aqui e so acrescentar o b[j] ao r
            r.push_back(b[j]);
            j++;
        }

        // k++;

        // a cada iteracao vou aumentar o index da matrix final  

    }

    while(i < a_size)
    {
        // acrescentar os que faltam do a ao r
        r.push_back(a[i]);
        i++;
        // k++;
    }
    while(j < b_size)
    {
        // acrescentar todos que faltam do b ao r
        r.push_back(b[j]);
        j++;
        // k++;
    }

    // ISTO E TIPO O MERGE SORT ALGORITHM

}

int main()
{
{ smatrix r;
  sum({ },
      { {0, 3, 1}, {0, 50, 1} },
      r);
  print(r); }
  { smatrix r;
  sum({ {0, 0, 1}, {1, 0, 1} },
      { {0, 3, 1}, {0, 50, 1} },
      r);
  print(r); }
  { smatrix r;
  sum({ {0, 0, 1}, {0, 1, 2}, {5, 10, 20}, {99, 12, 32} },
      { {0, 0, 1}, {0, 1, -2}, {10, 5, 20}, {99, 10, 30}, {99, 11, 31} },
      r);
  print(r); }
  { smatrix r;
  sum({ {0, 0, -1}, {0, 1, 2}, {5, 10, 20}, {10, 5, -20} },
      { {0, 0, 1}, {0, 1, -2}, {10, 5, 20} },
      r);
  print(r); }
  { smatrix r;
  sum({ {0, 0, -1}, {0, 1, 2},  {5, 10, 20 }, {10, 5, -20} },
      { {0, 0, 1}, {0, 1, -2},  {5, 10, -20}, {10, 5, 20} },
      r);
  print(r); }
    return 0;
}