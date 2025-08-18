#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    // Carta 1.
    char letra_carta1;
    char codigo_carta1[4]; // 3 caracteres.
    char nome_cidade_carta1[30];
    unsigned long int quantidade_carta1;
    float area_carta1;
    float pib_carta1; // PIB em bilhões.
    int pontos_turisticos_carta1;

    // Carta 2.
    char letra_carta2;
    char codigo_carta2[4];
    char nome_cidade_carta2[30];
    unsigned long int quantidade_carta2;
    float area_carta2;
    float pib_carta2;
    int pontos_turisticos_carta2;

    // CARTA 1.
    printf("Digite a letra da carta 1:\n");
    scanf(" %c", &letra_carta1);

    printf("Digite o código da carta 1:\n");
    scanf(" %3s", codigo_carta1);

    printf("Digite o nome da cidade 1:\n");
    scanf(" %29[^\n]", nome_cidade_carta1);

    printf("Digite a população da cidade 1:\n");
    scanf("%lu", &quantidade_carta1);

    printf("Digite a área da cidade 1:\n");
    scanf("%f", &area_carta1);

    printf("Digite o PIB (em bilhões) da cidade 1:\n");
    scanf("%f", &pib_carta1);

    printf("Digite o número de pontos turísticos da cidade 1:\n");
    scanf("%d", &pontos_turisticos_carta1);

    // Cálculos Carta 1.
    if (area_carta1 != 0.0f) {
        densidade_populacional_carta1 = (float)quantidade_carta1 / area_carta1;
    } else {
        printf("Atenção: Área da Carta 1 é zero! Densidade definida como 0.00.\n");
        densidade_populacional_carta1 = 0.0f;
    }

    if (quantidade_carta1 != 0UL) {
        pib_per_capita_carta1 = (pib_carta1 * 1000000000.0f) / (float)quantidade_carta1;
    } else {
        printf("Atenção: População da Carta 1 é zero! PIB per capita definido como 0.00.\n");
        pib_per_capita_carta1 = 0.0f;
    }

    float inverso_densidade1 = 0.0f;
    if (densidade_populacional_carta1 != 0.0f) {
        inverso_densidade1 = 1.0f / densidade_populacional_carta1;
    }

    super_poder1 = (float)quantidade_carta1 + area_carta1 + pib_carta1 +
                   pib_per_capita_carta1 + inverso_densidade1 +
                   (float)pontos_turisticos_carta1;

    // CARTA 2.
    printf("\n Digite a letra da carta 2:\n");
    scanf(" %c", &letra_carta2);

    printf("Digite o código da carta 2:\n");
    scanf(" %3s", codigo_carta2);

    printf("Digite o nome da cidade 2:\n");
    scanf(" %29[^\n]", nome_cidade_carta2);

    printf("Digite a população da cidade 2:\n");
    scanf("%lu", &quantidade_carta2);

    printf("Digite a área da cidade 2:\n");
    scanf("%f", &area_carta2);

    printf("Digite o PIB (em bilhões) da cidade 2:\n");
    scanf("%f", &pib_carta2);

    printf("Digite o número de pontos turísticos da cidade 2:\n");
    scanf("%d", &pontos_turisticos_carta2);

    // Cálculos Carta 2.
    if (area_carta2 != 0.0f) {
        densidade_populacional_carta2 = (float)quantidade_carta2 / area_carta2;
    } else {
        printf("Atenção: Área da Carta 2 é zero! Densidade definida como 0.00.\n");
        densidade_populacional_carta2 = 0.0f;
    }

    if (quantidade_carta2 != 0UL) {
        pib_per_capita_carta2 = (pib_carta2 * 1000000000.0f) / (float)quantidade_carta2;
    } else {
        printf("Atenção: População da Carta 2 é zero! PIB per capita definido como 0.00.\n");
        pib_per_capita_carta2 = 0.0f;
    }

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
     if (quantidade_carta1 > quantidade_carta2) {
         printf("Cidade 1 tem maior população.\n");
    } else {
        printf("Cidade 2 tem maior população.\n");
    }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}
