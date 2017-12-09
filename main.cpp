#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100 // tamanho maximo de nodos 'n' do grafo

//==============================================================================
// ALGORITMO DE DIJKSTRA
//==============================================================================

// prototipos de funcoes utilizadas
void printaTabela(int dist[], int num_vert);
void printaConjFechado(bool set[], int u, int num_vert);
int proxVertice(int dist[], bool S[], int num_vert);

// funcao com algoritmo de dijkstra que imprime na tela os resultados  
void dijkstra(int grafo[][MAX], int x, int y, int num_vert, int modo_det)
{
    int dist[num_vert]; // array de distancias (dist[x] = menor distancia do nodo inicial ate x)
    bool S[num_vert];   // conjunto fechado S que indica os vertices com distancia ja calculada
    int i = 0;
  
    // inicializa todas as distancias como INT_MAX ("infinito") e conjunto fechado "S"
    for (i = 0; i < num_vert; i++){
        dist[i] = INT_MAX;
        S[i] = false;
    }

    // distancia do vertice inicial para ele mesmo
    dist[x] = 0;
  
    // acha a menor distancia para todos os vertices
    for (int count = 0; count < num_vert - 1; count++)
    {
        // determina o vertice com menor distancia que ainda nao pertence
        // ao conjunto fechado
        int u = proxVertice(dist,S,num_vert); // u = proximo nodo a ser procesado
  		
        // adiciona u ao conjunto fechado
        S[u] = true;

        // se estiver no modo detalhado, imprime o conjunto fechado
        if(modo_det) {
            printaConjFechado(S,u,num_vert);
        }

        // atualiza a tabela de distancias se descobrir um caminho menor a partir do vertice 'u'
        for (int v = 0; v < num_vert; v++) {
            // para cada 'v', atualiza dist[v] apenas se:
            // vertice 'v' nao esta no conjunto fechado &&
            // vertice 'v' e adjacente ao 'u' escolhido &&
            // distancia do caminho novo e menor do que a distancia anterior
            if ((!S[v]) && (grafo[u][v] && dist[u] != INT_MAX) && (dist[u]+grafo[u][v] < dist[v])) {
                dist[v] = dist[u] + grafo[u][v];
            }
        }

        // se estiver no modo detalhado, imprime a tabela de distancias atualizada
        if(modo_det) {
            printaTabela(dist,num_vert);
        }
    }

    // printa o resultado
    printf("\n****************** RESULTADO *******************\n");
    printf("Menor distancia entre os nodos %d e %d: %d\n\n",x,y,dist[y]);
}

// funcao que imprime o array de distancias
void printaTabela(int dist[], int num_vert)
{
    printf("\nTabela de distancias:\n");

    for (int i = 0; i < num_vert; i++) {
        // se o valor for infinito
        if (dist[i] == INT_MAX) {
            printf("%d: INFINITO\n", i);
        }
        // se o valor for finito
        else {
            printf("%d: %d\n", i, dist[i]);
        }
    }
}

// funcao que imprime o conjunto fechado "S"
// usada no modo detalhado
void printaConjFechado(bool S[], int u, int num_vert)
{
    int i = 0;
    int primeiro = 1;
    printf("\n************** Visitando nodo %d ***************\n",u);
    printf("Conjunto fechado S = {");

    for(i = 0; i < num_vert; i++) {
        if(S[i] == true) {
            if (primeiro) {
                printf("%d", i);
                primeiro = 0;
            }
            else {
                printf(", %d",i);
            }
        }
    }

    printf("}");
}

// funcao auxiliar para achar o vertice com menor distancia que ainda nao
// pertence ao conjunto fechado "S" e retornar seu indice no array de distancias
int proxVertice(int dist[], bool S[], int num_vert)
{
    int min = INT_MAX, indice;

    // percorre array de distancias e determina o vertice
    for (int v = 0; v < num_vert; v++) {
        if (S[v] == false && dist[v] <= min){
            min = dist[v];
            indice = v;
        }
    }

    return indice; // retorna o indice do vertice encontrado
}

//==============================================================================
// FIM DO ALGORITMO
//==============================================================================


int main()
{
    int num_nodos, num_arestas; // quantidade de nodos e arestas do grafo (1a linha do arquivo)
    int nodo_inicial, nodo_destino; // "x" e "y" de acordo com a especificacao do trabalho
    int nodo1, nodo2, peso_aresta; // variavies auxiliares para leitura do arquivo
    int matriz_adj[MAX][MAX] = {0}; // matriz de adjacencia do grafo
    int modo_det; // flag que indica se o modo e detalhado ("execucao passo a passo") 
	FILE *fp; // file pointer para o arquivo de entrada

    // zera a matriz de adjacencia
    for(int i = 0; i < MAX;i++)
        for(int j = 0; j < MAX; j++)
            matriz_adj[i][j] = 0;

    // abre o arquivo de entrada
    fp = fopen("inst2/inst22n.dat","r");

    if (fp == NULL){
        printf("Erro ao abrir o arquivo de entrada!\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp,"%d %d",&num_nodos,&num_arestas); // le o numero de nodos e arestas
    printf("Quantidade de nodos: %d\nQuantidade de arestas: %d\n",num_nodos,num_arestas);

    // le os nodos e aresta de cada linha
    // e preenche a matriz de adjacencia
    while(fscanf(fp,"%d %d %d",&nodo1,&nodo2,&peso_aresta) > 0)  
    {  
      matriz_adj[nodo1][nodo2] = peso_aresta;
      matriz_adj[nodo2][nodo1] = peso_aresta;
    }

    // pede "x" e "y" para o usuario
    printf("\nQual o nodo inicial?\n>>> ");
    scanf("%d",&nodo_inicial);
    printf("\nQual o nodo final?\n>>> ");
    scanf("%d",&nodo_destino);

    // pede o modo de execucao para o usuario
    printf("\nModo simples(0) ou modo detalhado(1) ?\n>>> ");
    scanf("%d",&modo_det);

    // executa o algoritmo de dijkstra no modo selecionado
    dijkstra(matriz_adj,nodo_inicial,nodo_destino,num_nodos,modo_det);

    return 0;
}
