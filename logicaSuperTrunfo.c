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
    float pib_per_capita_carta1;
    float densidade_populacional_carta1
    int pontos_turisticos_carta1;

    // Carta 2.
    char letra_carta2;
    char codigo_carta2[4];
    char nome_cidade_carta2[30];
    unsigned long int quantidade_carta2;
    float area_carta2;
    float pib_carta2;
    float pib_per_capita_carta2
    float densidade_populacional_carta2;
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

    // Preparar valores para comparação.
    double val1 = 0.0, val2 = 0.0;
    const char *nome_atributo = "desconhecido";

    switch (atributo_escolhido) {
        case POPULACAO:
            nome_atributo = "população";
            val1 = (double)quantidade_carta1;
            val2 = (double)quantidade_carta2;
            break;
        case AREA:
            nome_atributo = "área (km2)";
            val1 = area_carta1;
            val2 = area_carta2;
            break;
        case PIB:
            nome_atributo = "pib (bilhões)";
            val1 = pib_carta1;
            val2 = pib_carta2;
            break;
        case DENSIDADE:
            nome_atributo = "densidade populacional (hab/km2)";
            val1 = densidade_populacional_carta1;
            val2 = densidade_populacional_carta2;
            break;
        case PIB_PER_CAPITA:
            nome_atributo = "pib per capita (moeda/unidade)";
            val1 = pib_per_capita_carta1;
            val2 = pib_per_capita_carta2;
            break;
        default:
            printf("atributo inválido.\n");
            return 1;
    }

    // Comparar: para densidade, menor vence; para os outros, maior vence.
    int resultado = 0; // 1 = carta1 vence, 2 = carta2 vence, 0 = empate
    if (atributo_escolhido == DENSIDADE) {
        if (val1 < val2) resultado = 1;
        else if (val2 < val1) resultado = 2;
        else resultado = 0;
    } else {
        if (val1 > val2) resultado = 1;
        else if (val2 > val1) resultado = 2;
        else resultado = 0;
    }

    // Exibir resultado no formato pedido.
    printf("\ncomparação de cartas (atributo: %s)\n\n", nome_atributo);

    if (atributo_escolhido == POPULACAO) {
        char buf1[64], buf2[64];
        format_ulong_with_dots(quantidade_carta1, buf1);
        format_ulong_with_dots(quantidade_carta2, buf2);
        printf("carta 1 - %s (%s): %s\n", nome_cidade_carta1, codigo_carta1, buf1);
        printf("carta 2 - %s (%s): %s\n", nome_cidade_carta2, codigo_carta2, buf2);
    } else if (atributo_escolhido == PIB) {
        printf("carta 1 - %s (%s): %.2f (bilhões)\n", nome_cidade_carta1, codigo_carta1, pib_carta1);
        printf("carta 2 - %s (%s): %.2f (bilhões)\n", nome_cidade_carta2, codigo_carta2, pib_carta2);
    } else if (atributo_escolhido == AREA) {
        printf("carta 1 - %s (%s): %.2f km2\n", nome_cidade_carta1, codigo_carta1, area_carta1);
        printf("carta 2 - %s (%s): %.2f km2\n", nome_cidade_carta2, codigo_carta2, area_carta2);
    } else if (atributo_escolhido == DENSIDADE) {
        printf("carta 1 - %s (%s): %.2f hab/km2\n", nome_cidade_carta1, codigo_carta1, densidade_populacional_carta1);
        printf("carta 2 - %s (%s): %.2f hab/km2\n", nome_cidade_carta2, codigo_carta2, densidade_populacional_carta2);
    } else if (atributo_escolhido == PIB_PER_CAPITA) {
        printf("carta 1 - %s (%s): %.2f\n", nome_cidade_carta1, codigo_carta1, pib_per_capita_carta1);
        printf("carta 2 - %s (%s): %.2f\n", nome_cidade_carta2, codigo_carta2, pib_per_capita_carta2);
    }

    // Mensagem final.
    if (resultado == 1) {
        printf("resultado: carta 1 (%s) venceu!\n", nome_cidade_carta1);
    } else if (resultado == 2) {
        printf("resultado: carta 2 (%s) venceu!\n", nome_cidade_carta2);
    } else {
        printf("resultado: empate!\n");
    }

    int resultado1, resultado2;
    char primeiroAtributo, segundoAtributo;
    int ataque1, ataque2, defesa1, defesa2, recuo1, recuo2;

    // Gerando número aleatório.
    srand(time(0));
    ataque1 = 50;//rand() % 100 + 1; // Número entre 1 e 100
    ataque2 = 20;//rand() % 100 + 1; // Número entre 1 e 100
    defesa1 = 65;//rand() % 100 + 1; // Número entre 1 e 100
    defesa2 = 45;//rand() % 100 + 1; // Número entre 1 e 100
    recuo1 = 85;//rand() % 100 + 1; // Número entre 1 e 100
    recuo2 = 10;//rand() % 100 + 1; // Número entre 1 e 100

    // Inicio do jogo.
    printf("Bem-vindo ao jogo!\n");
    printf("Escolha o primeiro atributo.\n");
    printf("A. Ataque\n");
    printf("D. Defesa\n");
    printf("R. Recuo\n");

    printf("Escolha a comparação: ");
    scanf(" %c", &PrimeiroAtributo);

    switch (PrimeiroAtributo)
    {
    case 'A':
    case 'a':
        printf("Você escolheu a opção Ataque!\n");
        resultado1 = ataque1 > ataque2 ? 1 : 0;
        break;
    case 'D':
    case 'd':
    printf("Você escolheu a opção Defesa!\n");
        resultado1 = defesa1 > defesa2 ? 1 : 0;
        break;
    case 'R':
    case 'r':
    printf("Você escolheu a opção Recuo!\n");
        resultado1 = recuo1 > recuo2 ? 1 : 0;
        break;
    default:
        printf("Opção de jogo invalida\n");
        break;

    }

    printf("Escolha o segundo atributo.\n");
    printf("A. Ataque\n");
    printf("D. Defesa\n");
    printf("R. Recuo\n");

    printf("Escolha a comparação: ");
    scanf(" %c", &SegundoAtributo);

    if (primeiroAtributo == SegundoAtributo)
    {
        printf("Você escolheu o mesmo atributo");
    } else {
        switch (SegundoAtributo)
    {
    case 'A':
    case 'a':
        printf("Você escolheu a opção Ataque!\n");
        resultado2 = ataque1 > ataque 2 ? 1 : 0;
        break;
    case 'D':
    case 'd':
    printf("Você escolheu a opção Defesa!\n");
        resultado2 = defesa1 > defesa2 ? 1 : 0;
        break;
    case 'R':
    case 'r':
    printf("Você escolheu a opção Recuo!\n");
        resultado2 = recuo1 > recuo2 ? 1 : 0;
        break;
    default:
        printf("Opção de jogo invalida\n");
        break;

}

if (resultado1 && resultado2)
{
    printf("Parabens, você venceu!\n");

} else if (resultado1 != resultado2){
    printf("Empatou!\n");
}else {
    printf("Infelizmente, você perdeu!\n");
}
    return 0;
}