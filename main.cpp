#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

//=====================================================================================================================
// AQUI COMEÇA O ALGORITMO DE DJIKSTRA
//======================================================================================================================
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[],int V)
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min){
			min = dist[v];
 			min_index = v;
  		}
   return min_index;
}


void printClosedSet(bool set[], int u, int V)
{
	int i = 0;
	printf("************** Visitando Nodo %d ***************\n",u);
	printf("****** Conjunto Fechado ******\n");
	for(i=0 ;i<V ;i++){	// Imprime closed set
		if(set[i] == true){
			printf("%d,",i);		
		}
	}
	printf("\n");

}

 
// A utility function to print the constructed distance array
void printPartialSolution(int dist[], int V)
{
   printf("Conjunto fechado:\n");
   for (int i = 0; i < V; i++)
      printf("%d: %d\n", i, dist[i]);
}
  
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[][MAX], int src, int dst, int V, int flag)   //V vai ser o numero de vertices
{
     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
  	 int i =0;
     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
  
     // Initialize all distances as INFINITE and stpSet[] as false
     for (i = 0; i < V; i++){
        dist[i] = INT_MAX;		// Distancia de todo mundo olocada em infinito 
		sptSet[i] = false;		// Não conhecemos a distancia de ninguem
	}
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet,V); // U = proximo nodo a ser procesado
  		
       // Mark the picked vertex as processed
       sptSet[u] = true;
		if(flag){
			printClosedSet(sptSet,u,V);
		}

  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]){
            dist[v] = dist[u] + graph[u][v];
		}
		if(flag){	// Este é o modod detalhado -> imprimir tabela passo a passo
		     printPartialSolution(dist, V);
		}			
     }
  
     // print the constructed distance array
		
		printf("Distancia de %d -> %d: %d\n",src,dst,dist[dst]);

}
  

//=====================================================================================================================
// AQUI TERMINA O ALGORITMO
//======================================================================================================================

int main(){

	int nodo;
	int nodo_destino;
	int aresta;
	int nodo1, nodo2, peso_aresta;
  	int matriz_adj[MAX][MAX] = {0};
  	int nodo_inicial;
	int flag ;
	//int visited[100];
	//int unvisited[100];
	//table_item table[100];
	FILE * fp; // File Pointer para o arquivo dos nodos

    for(int i = 0; i < MAX;i++)
      for(int j = 0; j < MAX; j++)          //zera a matriz
        matriz_adj[i][j] = 0;

    fp = fopen("inst2/inst22n.dat", "r");
    if (fp == NULL){
		printf("Erro ao abrir o arquivo de Nodos\n");
        exit(EXIT_FAILURE);
	}
	fscanf(fp,"%d %d",&nodo,&aresta) ;       //aqui le o numero de nodos e arestas
	printf("Nodos: %d\tArestas: %d\n",nodo,aresta);

	while(fscanf(fp,"%d %d %d",&nodo1,&nodo2,&peso_aresta) > 0)  //aqui le nodo1, nodo2 e o peso da aresta. ate o fim do arquivo
	{  
	  matriz_adj[nodo1][nodo2] = peso_aresta;
      matriz_adj[nodo2][nodo1] = peso_aresta;     //preenche a matriz de adjacencia
      //printf("\n %d %d %d",nodo1,nodo2,peso_aresta);
                                               
	}  

	printf("\nQual o nodo inicial?\t");
    scanf("%d",&nodo_inicial);
	printf("\nQual o nodo final?\t");
    scanf("%d",&nodo_destino);

	printf("\nModo simples (0) ou Modo Detalhado (1) ?\t");
    scanf("%d",&flag);

    dijkstra(matriz_adj, nodo_inicial,nodo_destino, nodo,flag);

	return 0;
}

