#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"

// Função para comparar cidades por posição 
int compararCidades(const void *a, const void *b) {
    Cidade *c1 = (Cidade *)a;
    Cidade *c2 = (Cidade *)b;
    return c1->Posicao - c2->Posicao;
}

//função para iniciar a estrutura Estrada e ler os dados do arquivo
Estrada *getEstrada(const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    Estrada *e = malloc(sizeof(Estrada));
    if (!e) {
        perror("Erro ao alocar memória para Estrada");
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d", &e->T);
    fscanf(file, "%d", &e->N);

    //verifica se os valores estão dentro dos limites permitidos
    if (e->T < 3 || e->T > 1000000 || e->N < 2 || e->N > 10000) {
        fprintf(stderr, "Erro: T e N devem estar entre os limites permitidos\n");
        free(e);
        fclose(file);
        return NULL;
    }

    //aloca memória para o vetor de cidades
    e->C = malloc(e->N * sizeof(Cidade));
    if (!e->C) {
        perror("Erro ao alocar memória para Cidades");
        free(e);
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < e->N; i++) {
        fscanf(file, "%d", &e->C[i].Posicao);
        fscanf(file, " %[^\n]", e->C[i].Nome);

        //verificar se existe cidade com nome vazio
        if (e->C[i].Posicao <= 0 || e->C[i].Posicao >= e->T) {
            fprintf(stderr, "Erro: Posição inválida para cidade\n");
            free(e->C);
            free(e);
            fclose(file);
            return NULL;
        }

        // Verificar se já existe cidade na mesma posição
        for (int j = 0; j < i; j++) {
            if (e->C[i].Posicao == e->C[j].Posicao) {
                fprintf(stderr, "Erro: Cidades não podem ter mesma posição\n");
                free(e->C);
                free(e);
                fclose(file);
                return NULL;
            }
        }
    }

    fclose(file);
    return e;
}

//função para calcular a menor vizinhança
double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada *e = getEstrada(nomeArquivo);
    if (!e) return -1;

    qsort(e->C, e->N, sizeof(Cidade), compararCidades); //ordena as cidades por posição

    double menorVizinhanca = e->T;

    for (int i = 0; i < e->N; i++) {
        double ini = (i == 0) ? 0 : (e->C[i].Posicao + e->C[i - 1].Posicao) / 2.0;
        double fim = (i == e->N - 1) ? e->T : (e->C[i].Posicao + e->C[i + 1].Posicao) / 2.0;

        double vizinhanca = fim - ini;
        if (vizinhanca < menorVizinhanca)
            menorVizinhanca = vizinhanca;
    }

    free(e->C);
    free(e);
    return menorVizinhanca;
}

//função para retornar o nome da cidade com menor vizinhança
char *cidadeMenorVizinhanca(const char *nomeArquivo) {
    Estrada *e = getEstrada(nomeArquivo);
    if (!e) return NULL;

    qsort(e->C, e->N, sizeof(Cidade), compararCidades);

    double menorVizinhanca = e->T;
    int indiceMenor = 0;

    for (int i = 0; i < e->N; i++) {
        double ini = (i == 0) ? 0 : (e->C[i].Posicao + e->C[i - 1].Posicao) / 2.0;
        double fim = (i == e->N - 1) ? e->T : (e->C[i].Posicao + e->C[i + 1].Posicao) / 2.0;

        double vizinhanca = fim - ini;
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
            indiceMenor = i;
        }
    }

    //aloca memória para o nome da cidade
    char *nome = malloc(strlen(e->C[indiceMenor].Nome) + 1);
    strcpy(nome, e->C[indiceMenor].Nome);

    free(e->C);
    free(e);
    return nome;
}
