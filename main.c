#include <stdio.h>
#include <stdlib.h>

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

int main(){

    char * line = NULL;	// Armazena os dados lidos do arquivo
    size_t len = 0;		// Tamanho do buffer
    ssize_t read;		// Armazena a quantidade de bytes lidos do arquivo

	//int visited[100];
	//int unvisited[100];
	//table_item table[100];
	FILE * fp; // File Pointer para o arquivo dos nodos

    fp = fopen("Insts/inst2.dat", "r");
    if (fp == NULL){
		printf("Erro ao abrir o arquivo de Nodos\n");
        exit(EXIT_FAILURE);
	}

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
    }

	//vertex_item vertex[] // vai depender da entrada lida do usuario 
	// Ler arquivo e colocar em ED 

	printf("Começando o negocio \n");

	return 0;
}

