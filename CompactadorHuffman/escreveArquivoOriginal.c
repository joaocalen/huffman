
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bin.h"
#include "codificador.h"
#include "escreveArquivoOriginal.h"

void montaArquivoOriginal(char* nome, unsigned char** tabela) {
    FILE* compactado = fopen(nome, "r");
    char* novoNome = retiraExtensaoComp(nome);
    FILE* original = fopen(novoNome, "w");
    char binario[8] = {'0'};
    memset(binario, 0, 9);
    int numBits = 0;
    fscanf(compactado, "%d", &numBits);
    fgetc(compactado); //andando uma posição no arquivo (pular o ponto)
    int numCaracteres = 0;
    fscanf(compactado, "%d", &numCaracteres);
    fgetc(compactado); //andando uma posição no arquivo, para chegar na árvore compactada impressa
    int aux = 0, caracterInt = 0;
    unsigned char caracter = 0;
    andaPonteiro(compactado, numBits);
    char* conteudoArquivo = (char*) malloc(numCaracteres * 8 * sizeof (char));
    memset(conteudoArquivo, 0, numCaracteres * 8);
    conteudoArquivo = converteConteudo(compactado, conteudoArquivo);
    int i = 0, j = 0;
    printf("%d\n\n", numCaracteres);
    while (aux < numCaracteres) {
        printf("%d %d %d \n", i, j, aux);
        binario[j] = conteudoArquivo[i];
        caracterInt = caracterReferente(binario, tabela);
        j++;
        if (caracterInt > 0) {
            fputc((unsigned char) caracterInt, original);
            memset(binario, 0, 9);
            j = 0;
            aux++;
        }
        i++;
    }
    fclose(compactado);
    fclose(original);
    free(conteudoArquivo);
    tabela_libera(tabela);
}


// função identica à função de escreveArquivoCompactado.c. A preferência em repetir a função ao invés de usar a do outro arquivo,
// é justamente a de não precisar dar um include em todo o arquivo em questão

char* retiraExtensaoComp(char* nome) {
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

void andaPonteiro(FILE* compactado, int numBits) {
    int aux = 0;
    while (aux < (int) (numBits / 8)) {
        fgetc(compactado);
        aux++;
    }
    if (numBits % 8 != 0) {
        fgetc(compactado);
    }
}

char* converteConteudo(FILE* compactado, char* conteudo) {
    unsigned char c = fgetc(compactado);
    while (!feof(compactado)) {
        //conteudo = realloc(conteudo, strlen(conteudo) + 8 * sizeof (char));
        char* bin = dec_to_bin(c);
        conteudo = strcat(conteudo, bin);
        free(bin);
        c = fgetc(compactado);
    }
    return conteudo;
}