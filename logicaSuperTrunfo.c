#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas

#include <stdio.h>
#include <time.h>   // Necessário para srand(time(0))
#include <stdlib.h> // Necessário para rand() e srand()
#include <string.h> // Necessário para strlen() e outras funções de string

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas

// Define os atributos como constantes para evitar erros de digitação no switch
// e tornar o código mais legível.
enum Atributos {
    POPULACAO = 1,
    AREA,
    PIB,
    DENSIDADE,
    PIB_PER_CAPITA
};

// Função para formatar números grandes com pontos.
// Esta função não existia no código original e foi implementada.
void format_ulong_with_dots(unsigned long int n, char *buf) {
    char temp[64];
    sprintf(temp, "%lu", n);
    int len = strlen(temp);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && (len - i) % 3 == 0) {
            buf[j++] = '.';
        }
        buf[j++] = temp[i];
    }
    buf[j] = '\0';
}


int main() {
    // Definição das variáveis para armazenar as propriedades das cidades.
    // Variáveis da Carta 1:
    char letra_carta1;
    char codigo_carta1[4];
    char nome_cidade_carta1[30];
    unsigned long int quantidade_carta1;
    float area_carta1;
    float pib_carta1;
    float pib_per_capita_carta1;
    float densidade_populacional_carta1;
    int pontos_turisticos_carta1;
    float super_poder1; 

    // Variáveis da Carta 2:
    char letra_carta2;
    char codigo_carta2[4];
    char nome_cidade_carta2[30];
    unsigned long int quantidade_carta2;
    float area_carta2;
    float pib_carta2;
    float pib_per_capita_carta2;
    float densidade_populacional_carta2;
    int pontos_turisticos_carta2;
    float super_poder2; 

    // Variáveis do Jogo:
    int atributo_escolhido;


    // ENTRADA DE DADOS - CARTA 1:
    printf("--- CARTA 1 ---\n");
    printf("Digite a letra da carta 1:\n");
    scanf(" %c", &letra_carta1);

    printf("Digite o codigo da carta 1:\n");
    scanf(" %3s", codigo_carta1);

    printf("Digite o nome da cidade 1:\n");
    // Limpa o buffer de entrada para ler a string corretamente:
    while(getchar() != '\n'); 
    scanf("%29[^\n]", nome_cidade_carta1);

    printf("Digite a populacao da cidade 1:\n");
    scanf("%lu", &quantidade_carta1);

    printf("Digite a area da cidade 1:\n");
    scanf("%f", &area_carta1);

    printf("Digite o PIB (em bilhoes) da cidade 1:\n");
    scanf("%f", &pib_carta1);

    printf("Digite o numero de pontos turisticos da cidade 1:\n");
    scanf("%d", &pontos_turisticos_carta1);

    // Cálculos Carta 1:
    if (area_carta1 > 0.0f) {
        densidade_populacional_carta1 = (float)quantidade_carta1 / area_carta1;
    } else {
        printf("Atencao: Area da Carta 1 e zero! Densidade definida como 0.00.\n");
        densidade_populacional_carta1 = 0.0f;
    }

    if (quantidade_carta1 > 0UL) {
        pib_per_capita_carta1 = (pib_carta1 * 1000000000.0f) / (float)quantidade_carta1;
    } else {
        printf("Atencao: Populacao da Carta 1 e zero! PIB per capita definido como 0.00.\n");
        pib_per_capita_carta1 = 0.0f;
    }

    float inverso_densidade1 = 0.0f;
    if (densidade_populacional_carta1 > 0.0f) {
        inverso_densidade1 = 1.0f / densidade_populacional_carta1;
    }

    super_poder1 = (float)quantidade_carta1 + area_carta1 + pib_carta1 +
                     pib_per_capita_carta1 + inverso_densidade1 +
                     (float)pontos_turisticos_carta1;

    // ENTRADA DE DADOS - CARTA 2:
    printf("\n--- CARTA 2 ---\n");
    printf("Digite a letra da carta 2:\n");
    scanf(" %c", &letra_carta2);

    printf("Digite o codigo da carta 2:\n");
    scanf(" %3s", codigo_carta2);

    printf("Digite o nome da cidade 2:\n");
    // Limpa o buffer de entrada para ler a string corretamente.
    while(getchar() != '\n');
    scanf(" %29[^\n]", nome_cidade_carta2);

    printf("Digite a populacao da cidade 2:\n");
    scanf("%lu", &quantidade_carta2);

    printf("Digite a area da cidade 2:\n");
    scanf("%f", &area_carta2);

    printf("Digite o PIB (em bilhoes) da cidade 2:\n");
    scanf("%f", &pib_carta2);

    printf("Digite o numero de pontos turisticos da cidade 2:\n");
    scanf("%d", &pontos_turisticos_carta2);

    // Cálculos Carta 2:
    if (area_carta2 > 0.0f) {
        densidade_populacional_carta2 = (float)quantidade_carta2 / area_carta2;
    } else {
        printf("Atencao: Area da Carta 2 e zero! Densidade definida como 0.00.\n");
        densidade_populacional_carta2 = 0.0f;
    }

    if (quantidade_carta2 > 0UL) {
        pib_per_capita_carta2 = (pib_carta2 * 1000000000.0f) / (float)quantidade_carta2;
    } else {
        printf("Atencao: Populacao da Carta 2 e zero! PIB per capita definido como 0.00.\n");
        pib_per_capita_carta2 = 0.0f;
    }
    
    // Adicionado cálculo para a carta 2 para consistência:
    float inverso_densidade2 = 0.0f;
    if (densidade_populacional_carta2 > 0.0f) {
        inverso_densidade2 = 1.0f / densidade_populacional_carta2;
    }
    
    super_poder2 = (float)quantidade_carta2 + area_carta2 + pib_carta2 +
                     pib_per_capita_carta2 + inverso_densidade2 +
                     (float)pontos_turisticos_carta2;


    // LÓGICA DE COMPARAÇÃO DAS CARTAS:
    printf("\n--- ESCOLHA UM ATRIBUTO PARA COMPARAR ---\n");
    printf("%d. Populacao\n", POPULACAO);
    printf("%d. Area\n", AREA);
    printf("%d. PIB\n", PIB);
    printf("%d. Densidade Populacional (menor vence)\n", DENSIDADE);
    printf("%d. PIB Per Capita\n", PIB_PER_CAPITA);
    printf("Digite o numero do atributo: ");
    scanf("%d", &atributo_escolhido);

    // Preparar valores para comparação:
    double val1 = 0.0, val2 = 0.0;
    const char *nome_atributo = "desconhecido";

    switch (atributo_escolhido) {
        case POPULACAO:
            nome_atributo = "populacao";
            val1 = (double)quantidade_carta1;
            val2 = (double)quantidade_carta2;
            break;
        case AREA:
            nome_atributo = "area (km2)";
            val1 = area_carta1;
            val2 = area_carta2;
            break;
        case PIB:
            nome_atributo = "pib (bilhoes)";
            val1 = pib_carta1;
            val2 = pib_carta2;
            break;
        case DENSIDADE:
            nome_atributo = "densidade populacional (hab/km2)";
            val1 = densidade_populacional_carta1;
            val2 = densidade_populacional_carta2;
            break;
        case PIB_PER_CAPITA:
            nome_atributo = "pib per capita";
            val1 = pib_per_capita_carta1;
            val2 = pib_per_capita_carta2;
            break;
        default:
            printf("Atributo invalido.\n");
            return 1; // Encerra o programa se a opção for inválida.
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

    //Exibir resultado no formato pedido:
    printf("\n--- COMPARACAO DE CARTAS (Atributo: %s) ---\n\n", nome_atributo);

    // Buffer para formatar os números grandes:
    char buf1[64], buf2[64];

    if (atributo_escolhido == POPULACAO) {
        format_ulong_with_dots(quantidade_carta1, buf1);
        format_ulong_with_dots(quantidade_carta2, buf2);
        printf("Carta 1 - %s (%s): %s habitantes\n", nome_cidade_carta1, codigo_carta1, buf1);
        printf("Carta 2 - %s (%s): %s habitantes\n", nome_cidade_carta2, codigo_carta2, buf2);
    } else if (atributo_escolhido == PIB) {
        printf("Carta 1 - %s (%s): %.2f (bilhoes)\n", nome_cidade_carta1, codigo_carta1, pib_carta1);
        printf("Carta 2 - %s (%s): %.2f (bilhoes)\n", nome_cidade_carta2, codigo_carta2, pib_carta2);
    } else if (atributo_escolhido == AREA) {
        printf("Carta 1 - %s (%s): %.2f km2\n", nome_cidade_carta1, codigo_carta1, area_carta1);
        printf("Carta 2 - %s (%s): %.2f km2\n", nome_cidade_carta2, codigo_carta2, area_carta2);
    } else if (atributo_escolhido == DENSIDADE) {
        printf("Carta 1 - %s (%s): %.2f hab/km2\n", nome_cidade_carta1, codigo_carta1, densidade_populacional_carta1);
        printf("Carta 2 - %s (%s): %.2f hab/km2\n", nome_cidade_carta2, codigo_carta2, densidade_populacional_carta2);
    } else if (atributo_escolhido == PIB_PER_CAPITA) {
        printf("Carta 1 - %s (%s): %.2f\n", nome_cidade_carta1, codigo_carta1, pib_per_capita_carta1);
        printf("Carta 2 - %s (%s): %.2f\n", nome_cidade_carta2, codigo_carta2, pib_per_capita_carta2);
    }

    //Mensagem final:
    if (resultado == 1) {
        printf("\nResultado: CARTA 1 (%s) VENCEU!\n", nome_cidade_carta1);
    } else if (resultado == 2) {
        printf("\nResultado: CARTA 2 (%s) VENCEU!\n", nome_cidade_carta2);
    } else {
        printf("\nResultado: EMPATE!\n");
    }

    
    //SEGUNDA PARTE DO CÓDIGO (JOGO BÔNUS):
    
    int resultado_rodada1, resultado_rodada2;
    char primeiroAtributo, segundoAtributo;
    int ataque1, ataque2, defesa1, defesa2, recuo1, recuo2;

    // Gerando número aleatório:
    srand(time(0));
    ataque1 = 50; //rand() % 100 + 1;
    ataque2 = 20; //rand() % 100 + 1;
    defesa1 = 65; //rand() % 100 + 1;
    defesa2 = 45; //rand() % 100 + 1;
    recuo1 = 85;  //rand() % 100 + 1;
    recuo2 = 10;  //rand() % 100 + 1;

    printf("\n\n--- JOGO BONUS ---\n");
    printf("Escolha o primeiro atributo.\n");
    printf("A. Ataque\n");
    printf("D. Defesa\n");
    printf("R. Recuo\n");

    printf("Escolha a comparação: ");
    scanf(" %c", &primeiroAtributo);

    switch (primeiroAtributo) {
        case 'A':
        case 'a':
            printf("Você escolheu a opção Ataque!\n");
            resultado_rodada1 = ataque1 > ataque2 ? 1 : 0;
            break;
        case 'D':
        case 'd':
            printf("Você escolheu a opção Defesa!\n");
            resultado_rodada1 = defesa1 > defesa2 ? 1 : 0;
            break;
        case 'R':
        case 'r':
            printf("Você escolheu a opção Recuo!\n");
            resultado_rodada1 = recuo1 > recuo2 ? 1 : 0;
            break;
        default:
            printf("Opcao de jogo invalida\n");
            return 1; 
    }

    printf("\nEscolha o segundo atributo.\n");
    printf("A. Ataque\n");
    printf("D. Defesa\n");
    printf("R. Recuo\n");

    printf("Escolha a comparação: ");
    scanf(" %c", &segundoAtributo);

    if (primeiroAtributo == segundoAtributo) {
        printf("Você não pode escolher o mesmo atributo duas vezes.\n");
    } else {
        switch (segundoAtributo) {
            case 'A':
            case 'a':
                printf("Você escolheu a opção Ataque!\n");
                resultado_rodada2 = ataque1 > ataque2 ? 1 : 0;
                break;
            case 'D':
            case 'd':
                printf("Você escolheu a opção Defesa!\n");
                resultado_rodada2 = defesa1 > defesa2 ? 1 : 0;
                break;
            case 'R':
            case 'r':
                printf("Você escolheu a opção Recuo!\n");
                resultado_rodada2 = recuo1 > recuo2 ? 1 : 0;
                break;
            default:
                printf("Opção de jogo invalida\n");
                return 1; // Encerra
        }

        // Lógica de vitória: Vence se ganhar nas duas rodadas escolhidas.
        if (resultado_rodada1 && resultado_rodada2) {
            printf("\nParabêns, você venceu!\n");
        } else if (resultado_rodada1 != resultado_rodada2) {
            // Ganhou uma e perdeu outra:
            printf("\nEmpatou!\n");
        } else {
            // Perdeu as duas:
            printf("\nInfelizmente, você perdeu!\n");
        }
    }

    return 0;
}