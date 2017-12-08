#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
                          // Number of vertices in the graph
#define V 9               //aqui ta como define, temos que trocar pro que vai ser lido do arquivo de entrada

typedef struct item {
	int vertex;
	int shortest_distance;
	int previous_vertex;
}table_item;

typedef struct item2 {
	int vertexA;
	int vertexB;
	int weight;
}vertex_item;

//=====================================================================================================================
// AQUI COMEÇA O ALGORITMO DE DJIKSTRA
//======================================================================================================================
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  
// A utility function to print the constructed distance array
void printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d tt %d\n", i, dist[i]);
}
  
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
  
     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
  
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
  
     // print the constructed distance array
     printSolution(dist, V);
}
  

//=====================================================================================================================
// AQUI TERMINA O ALGORITMO
//======================================================================================================================

int main(){

  //  char * line = NULL;	// Armazena os dados lidos do arquivo
  //  size_t len = 0;		// Tamanho do buffer
 //   ssize_t read;		// Armazena a quantidade de bytes lidos do arquivo
	//int i=0;
	int nodo;
	int aresta;
  int nodo1, nodo2, peso_aresta;
	//int visited[100];
	//int unvisited[100];
	//table_item table[100];
	FILE * fp; // File Pointer para o arquivo dos nodos

    fp = fopen("Insts/inst2.dat", "r");
    if (fp == NULL){
		printf("Erro ao abrir o arquivo de Nodos\n");
        exit(EXIT_FAILURE);
	}
	fscanf(fp,"%d %d",&nodo,&aresta) ;       //aqui le o numero de nodos e arestas
	printf("Nodos:%d Arestas: %d \n",nodo,aresta);

	while(fscanf(fp,"%d %d %d",&nodo1,&nodo2,&peso_aresta) == 1)  //aqui le nodo1, nodo2 e o peso da aresta. ate o fim do arquivo
	{  
		  // printf("\n%s\t%c", item,status);       //dentro desse while, tem que pegar e colocar na matriz de adjascencia o peso
                                                // das arestas. o que seria esse status que estaria sendo printado?
	}  

/*
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
		// Strtok 
		i = i +1;
    }
*/
	//vertex_item vertex[] // vai depender da entrada lida do usuario 
	// Ler arquivo e colocar em ED 

	printf("Começando o negocio 2\n");

	return 0;
}

