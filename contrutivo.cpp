#include <iostream>
#include <vector>
#include <utility>
#include<bits/stdc++.h> 
using namespace std;

#define ROW 4
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
    
    vector<vector<int>> pos=  {{0,40,20,100},{40,0,50,10},{20,50,0,10},{100,10,10,0}};
    vector<int> solucao;
    int sol = 0;
    int menor = 1000;
    int eita;
    int i,j;
    // for(i=0; i< ROW;i++){

    //     for(j=0; j<COL; j++){

    //         if(pos[i][j] < menor && pos[i][j] != 0){
    //             menor = pos[i][j];  
    //         }    
    //     }
    //     solucao.push_back(menor);
    // }

    for(i=0; i < 1;i++){

        for(j=0; j<COL; j++){

            if(pos[i][j] < menor && pos[i][j] != 0){
                menor = pos[i][j];
                
            }    
        }
        eita = j;
        solucao.push_back(menor);
    }


    for(j=0; j<COL; j++){

        if(pos[eita-1][j] < menor && pos[i][j] != 0){
            menor = pos[i][j];  
        }    
    }
    solucao.push_back(menor);
    

    return solucao;
}

int main()
{
    vector<int> sol = construtivo();
    printSolucao(sol,ROW);

}