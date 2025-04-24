#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cidades.h"

int main() {
    int Soma = 0;
    int NumTeste = 0;

    FILE *Resposta = fopen("Resultado.txt", "w");
    if (!Resposta) {
        perror("Erro ao criar Resultado.txt");
        return 1;
    }

    Estrada *T1 = getEstrada("Teste01.txt");
    if (!T1) {
        fprintf(stderr, "Erro ao carregar os dados de Teste01.txt\n");
        fclose(Resposta);
        return 1;
    }

    double D1 = calcularMenorVizinhanca("Teste02.txt");
    char *C1 = cidadeMenorVizinhanca("Teste02.txt");

    printf("===== RESULTADO DOS TESTES =====\n");
    fprintf(Resposta, "===== RESULTADO DOS TESTES =====\n");

    // Teste 1 - Comprimento da estrada
    NumTeste++;
    if (T1->T == 10) {
        Soma++;
        printf("✔️ Comprimento da estrada correto\n");
        fprintf(Resposta, "✔️ Comprimento da estrada correto\n");
    } else {
        printf("❌ Comprimento da estrada incorreto\n");
        fprintf(Resposta, "❌ Comprimento da estrada incorreto\n");
    }

    // Teste 2 - Número de cidades
    NumTeste++;
    if (T1->N == 2) {
        Soma++;
        printf("✔️ Número de cidades correto\n");
        fprintf(Resposta, "✔️ Número de cidades correto\n");
    } else {
        printf("❌ Número de cidades incorreto\n");
        fprintf(Resposta, "❌ Número de cidades incorreto\n");
    }

    // Teste 3 - Menor vizinhança
    NumTeste++;
    if (D1 == 3.5) {
        Soma++;
        printf("✔️ Menor vizinhança correta\n");
        fprintf(Resposta, "✔️ Menor vizinhança correta\n");
    } else {
        printf("❌ Menor vizinhança incorreta (%.2f)\n", D1);
        fprintf(Resposta, "❌ Menor vizinhança incorreta (%.2f)\n", D1);
    }

    // Teste 4 - Cidade com menor vizinhança
    NumTeste++;
    if (strcmp(C1, "Birnin Zana") == 0) {
        Soma++;
        printf("✔️ Cidade com menor vizinhança correta\n");
        fprintf(Resposta, "✔️ Cidade com menor vizinhança correta\n");
    } else {
        printf("❌ Cidade com menor vizinhança incorreta (%s)\n", C1);
        fprintf(Resposta, "❌ Cidade com menor vizinhança incorreta (%s)\n", C1);
    }

    float nota = 2.0f * (float)Soma / (float)NumTeste;

    printf("\n🔎 Você acertou %d de %d itens. Nota final: %.2f / 2.00\n", Soma, NumTeste, nota);
    fprintf(Resposta, "\n🔎 Você acertou %d de %d itens. Nota final: %.2f / 2.00\n", Soma, NumTeste, nota);

    // Libera memória
    free(C1);
    free(T1->C);
    free(T1);
    fclose(Resposta);

    return 0;
}
