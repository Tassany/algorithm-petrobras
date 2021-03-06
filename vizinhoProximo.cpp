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
    
    vector<vector<int>> costs = {
        {0,40,20,100},
        {40,0,50,10},
        {20,50,0,10},
        {100,10,10,0}
    };
    vector<int> vertices = { 2, 3, 4};
    vector<int> sol = {1};
    int solCost = 0;

    int instanceSize = costs[1].size() - 1 ;
    int i,j;

    int menor = 1000;
    int menorJ = 1000;
    
    while (!vertices.empty())
    {
        for(i=0;i<ROW;i++){
            for(j=0;j<ROW;j++){
                if(costs[i][j] < menor && costs[i][j] != 0){
                    sol.push_back(j);
                }
            }
            int it = j - 1;
            vertices.erase(vertices.begin() +  it);
        }
    }
    cout << solCost;
    return sol;
}

int main()
{
    vector<int> sol = construtivo();
    printSolucao(sol,ROW);

}