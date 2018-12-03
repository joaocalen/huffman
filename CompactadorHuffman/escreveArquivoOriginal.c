
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void montaArquivo(char* nome, unsigned char** tabela) {
    FILE* compactado = fopen(nome, "r");
    FILE* original = fopen(strcat(retiraExtensao(nome), ".txt"), "w");
    char* binario = (char*) malloc(9 * sizeof (char));
    memset(binario, 0, 9);
    int c, numBits = 0;
    fscanf(compactado, "%d", &numBits);
    fgetc(compactado); //andando uma posição no arquivo (pular o ponto)
    int numCaracteres = 0;
    fscanf(compactado, "%d", &numCaracteres);
    fgetc(compactado); //andando uma posição no arquivo, para chegar na árvore compactada impressa
    int aux = 0;
    andaPonteiro(compactado, numBits);
    char* conteudoArquivo = converteConteudo(compactado);
    while (c > 0) {
        binario = strcat(binario, c);
        aux = caracterReferente(binario, tabela);
        if (aux > 0) {
            fputc(aux, compactado);
            memset(binario, 0, 9);
        }
    }
}


// função identica à função de escreveArquivoCompactado.c. A preferência em repetir a função ao invés de usar a do outro arquivo,
// é justamente a de não precisar dar um include em todo o arquivo em questão

char* retiraExtensao(char* nome) {
    int i = strlen(nome);
    while (nome[i] != '.') {
        i--;
    }
    nome[i] = '\0';
    return nome;
}

// Retorna o caracter referente à sequencia de binários

int caracterReferente(char* binario, unsigned char** tabela) {
    for (int i = 0; i < 256; i++) {
        if (!strcmp(binario, tabela[i])) {
            return i;
        }
    }
    return -1;
}

char* andaPonteiro(FILE* compactado, int numBits) {
    int aux = 0;
    while (aux < (int) (numBits / 8)) {
        fgetc(compactado);
        aux++;
    }
}

char* converteConteudo(FILE* compactado) {

}