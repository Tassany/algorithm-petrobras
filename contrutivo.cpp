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
    // Bases: [[-0.0, 6], [-2, 5], [-3.25, 0.0], [-4, 3], [-6, 1]]
    vector<vector<int>> costs = {
        {0,1,10,10,10,2},
        {1,0,1,10,10,10},
        {10,1,0,1,10,10},
        {10,10,1,0,1,10},
        {10,10,10,1,0,1},
        {2,10,10,10,1,0},
    };
    
    // Solucao inicial aleatória,
    // Mesmo mudando os valores do nó, a solucao será a mesma
    vector<int> vertices = { 3, 2, 4,6,5};
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