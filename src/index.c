#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    FILE *arquivo = fopen("dados.txt", "w");
    if (!arquivo) {
        printf("Erro ao criar o arquivo de dados.\n");
        return 1;
    }
    
    //repetições
    int quant;
    printf("Digite a quantidade de repetições: ");
    scanf("%d", &quant);

    int *arrayDados = (int *)malloc(quant*2 * sizeof(int));
    if (arrayDados == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    for (int i=0;i<quant*2;i++) {
        arrayDados[i] = 0;
    }
    srand(time(NULL));
    int num1;
    int num2;
    int soma;
    for (int i = 0;i<quant;i++){
        num1 = rand() % (quant+1);
        num2 = rand() % (quant+1);
        soma = num1+num2;
        arrayDados[soma]++;
    }
    printf("x  y\n");
    fprintf(arquivo, "x y\n");
    for (int i=0;i<quant*2;i++) {
        printf("%d  %d\n", i, arrayDados[i]);
        fprintf(arquivo, "%d %d\n", i, arrayDados[i]);
    }
    printf("\nArquivo escrito com sucesso!\n");
    fclose(arquivo);
    free(arrayDados);
    return 0;
}
