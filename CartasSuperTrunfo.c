#include <stdio.h>

int main() {
    // Área para definição das variáveis da Carta 1
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    float superPoder1;

    // Área para definição das variáveis da Carta 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;

    // Variáveis para armazenar os resultados das comparações
    int resultadoPopulacao;
    int resultadoArea;
    int resultadoPib;
    int resultadoPontosTuristicos;
    int resultadoDensidadePopulacional;
    int resultadoPibPerCapita;
    int resultadoSuperPoder;

    // Entrada de dados da Carta 1
    printf("Cadastro da Carta 1\n");

    printf("Digite o estado da Carta 1 (A a H): ");
    scanf(" %c", &estado1);

    printf("Digite o codigo da Carta 1 (ex: A01): ");
    scanf("%3s", codigo1);

    printf("Digite o nome da cidade da Carta 1: ");
    scanf(" %49[^\n]", nomeCidade1);

    printf("Digite a populacao da Carta 1: ");
    scanf("%lu", &populacao1);

    printf("Digite a area da Carta 1 em km2: ");
    scanf("%f", &area1);

    printf("Digite o PIB da Carta 1 em bilhoes de reais: ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos da Carta 1: ");
    scanf("%d", &pontosTuristicos1);

    // Entrada de dados da Carta 2
    printf("\nCadastro da Carta 2\n");

    printf("Digite o estado da Carta 2 (A a H): ");
    scanf(" %c", &estado2);

    printf("Digite o codigo da Carta 2 (ex: B02): ");
    scanf("%3s", codigo2);

    printf("Digite o nome da cidade da Carta 2: ");
    scanf(" %49[^\n]", nomeCidade2);

    printf("Digite a populacao da Carta 2: ");
    scanf("%lu", &populacao2);

    printf("Digite a area da Carta 2 em km2: ");
    scanf("%f", &area2);

    printf("Digite o PIB da Carta 2 em bilhoes de reais: ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos da Carta 2: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo da densidade populacional e do PIB per capita da Carta 1
    densidadePopulacional1 = (float) populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0f) / populacao1;

    // Cálculo da densidade populacional e do PIB per capita da Carta 2
    densidadePopulacional2 = (float) populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0f) / populacao2;

    // Cálculo do Super Poder da Carta 1
    // O inverso da densidade é usado porque menor densidade significa maior poder.
    superPoder1 = 
        (float) populacao1 +
        area1 +
        pib1 +
        pontosTuristicos1 +
        pibPerCapita1 +
        (1.0f / densidadePopulacional1);

    // Cálculo do Super Poder da Carta 2
    superPoder2 = 
        (float) populacao2 +
        area2 +
        pib2 +
        pontosTuristicos2 +
        pibPerCapita2 +
        (1.0f / densidadePopulacional2);

    // Comparação das cartas
    // Para quase todos os atributos, vence o maior valor.
    resultadoPopulacao = populacao1 > populacao2;
    resultadoArea = area1 > area2;
    resultadoPib = pib1 > pib2;
    resultadoPontosTuristicos = pontosTuristicos1 > pontosTuristicos2;

    // Para densidade populacional, vence o menor valor.
    resultadoDensidadePopulacional = densidadePopulacional1 < densidadePopulacional2;

    // Para PIB per capita e Super Poder, vence o maior valor.
    resultadoPibPerCapita = pibPerCapita1 > pibPerCapita2;
    resultadoSuperPoder = superPoder1 > superPoder2;

    // Exibição dos dados cadastrados da Carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    // Exibição dos dados cadastrados da Carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // Exibição dos resultados das comparações
    // Quando o resultado é 1, a Carta 1 venceu.
    // Quando o resultado é 0, a Carta 2 venceu.
    printf("\nComparacao de Cartas:\n");

    printf("Populacao: Carta %d venceu (%d)\n", 2 - resultadoPopulacao, resultadoPopulacao);
    printf("Area: Carta %d venceu (%d)\n", 2 - resultadoArea, resultadoArea);
    printf("PIB: Carta %d venceu (%d)\n", 2 - resultadoPib, resultadoPib);
    printf("Pontos Turisticos: Carta %d venceu (%d)\n", 2 - resultadoPontosTuristicos, resultadoPontosTuristicos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", 2 - resultadoDensidadePopulacional, resultadoDensidadePopulacional);
    printf("PIB per Capita: Carta %d venceu (%d)\n", 2 - resultadoPibPerCapita, resultadoPibPerCapita);
    printf("Super Poder: Carta %d venceu (%d)\n", 2 - resultadoSuperPoder, resultadoSuperPoder);

    return 0;
}