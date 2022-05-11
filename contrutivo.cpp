#include <iostream>
#include <vector>
#include <utility>
#include<bits/stdc++.h> 
using namespace std;

#define ROW 3
#define COL 4


void printSolucao(vector<int> &sol, int arraySize)
{
  cout << endl
       << "Solucao: [ ";

  for (size_t i = 0; i < sol.size(); i++)
  {
    cout << sol[i] << " ";
  }

  cout << "]" << endl;
}

vector<int> construtivo(){
    
    // Custos de cada Nó para outro Nó
    // Custo de ij = ji
    vector<vector<int>> costs = {
        {0,40,20,100},
        {40,0,50,10},
        {20,50,0,10},
        {100,10,10,0}
    };
    
    // Solucao inicial aleatória,
    // Mesmo mudando os valores do nó, a solucao será a mesma
    vector<int> vertices = { 2, 3, 4};
    vector<int> sol = {1};
    int solCost = 0;

    int instanceSize = costs[1].size() - 1 ;
    int i,j;

    
    while (vertices.size() != 0)
    {
        int menor = 1000;
        int currentVertice = -1;

        for(i = 0 ; i < vertices.size() ; i++){
            if(costs[sol[sol.size()-1]-1][vertices[i]-1] < menor) {
                menor = costs[sol[sol.size()-1]-1][vertices[i]-1];
                currentVertice = i;
            }
        }


        sol.push_back(vertices[currentVertice]);
        vertices.erase(vertices.begin() + currentVertice);
    }
    sol.push_back(1);
    return sol;
}

int main()
{
    vector<int> sol = construtivo();
    printSolucao(sol,ROW);

}