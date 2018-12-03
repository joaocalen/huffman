#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "escreveArquivoCompactado.h"
#include "arvore.h"
#include "bin.h"

void montaArquivo(char* nome, unsigned char** tabela, Arvore* huffman) {
    FILE* compactado;
    FILE* original;
    original = fopen(nome, "r");
    char* novoNome = retiraExtensao(nome);
    compactado = fopen(strcat(novoNome, ".comp"), "w");
    fprintf(compactado, "%d", (arvore_folhas(huffman) * 8 + arvore_qntdNos(huffman))); // quantidade de bits escritos pelo cabeçalho
    fputc('.', compactado); // separa a informação de parada do cabeçalho com a da leitura de caracteres
    fprintf(compactado, "%d", arvore_getOcorrencias(huffman)); // quantidade de caracteres que serão lidos pelo descompacta
    fputc('.', compactado); // separa informações de parada do cabeçalho
    unsigned char* escrita = (unsigned char*) malloc(9 * sizeof (unsigned char));
    memset(escrita, 0, 9);
    printf("\n\n\n");
    int i = 0;
    escreveCabecalho(compactado, huffman, escrita, &i);
    while (i != 8) {
        escrita[i] = '0';
        i++;
    }
    fputc(("%u", bin_to_dec(escrita)), compactado);
    free(escrita);
    escreveArquivo(original, compactado, tabela);
    fclose(original);
    fclose(compactado);
}

char* retiraExtensao(char* nome) {
    int i = strlen(nome);
    while (nome[i] != '.') {
        i--;
    }
    nome[i] = '\0';
    return nome;
}

void escreveCabecalho(FILE* arquivo, Arvore* huffman, unsigned char* escrita, int* i) {
    if (!arvore_vazia(huffman)) {
        if (arvore_isFolha(huffman)) {
            if (*i == 8) {
                fputc(("%u", bin_to_dec(escrita)), arquivo);
                printf("%s ", escrita);
                *i = 0;
                memset(escrita, 0, 9);
            }
            escrita[*i] = '1';

            *i = *i + 1;
            char* letra = dec_to_bin(arvore_getConteudo(huffman));

            int j = 0;
            while (j != 8) {
                if (*i == 8) {
                    fputc(("%u", bin_to_dec(escrita)), arquivo);
                    *i = 0;
                    memset(escrita, 0, 9);
                }
                escrita[*i] = letra[j];
                *i = *i + 1;
                j++;
            }
            free(letra);
        } else {
            if (*i == 8) {
                fputc(("%u", bin_to_dec(escrita)), arquivo);
                *i = 0;
                memset(escrita, 0, 9);
            }
            escrita[*i] = '0';
            *i = *i + 1;
            escreveCabecalho(arquivo, arvore_getNoE(huffman), escrita, i);
            escreveCabecalho(arquivo, arvore_getNoD(huffman), escrita, i);
        }
    }
}

void escreveArquivo(FILE* original, FILE* compactado, unsigned char** tabela) {
    unsigned char escrita[8] = {'2', '2', '2', '2', '2', '2', '2', '2'}; //valores iniciais, todos serão modificados.
    int aux = fgetc(original);
    int i = 0;
    int j = 0;
    while (aux > 0) {
        //printf("%s", c);
        while (tabela[aux][j] != '\0') {
            if (i == 8) {
                fputc(("%u", bin_to_dec(escrita)), compactado);
                i = 0;
            }
            escrita[i] = tabela[aux][j];
            i++;
            j++;
        }
        j = 0;
        aux = fgetc(original);
    }
    while (i < 8) {
        escrita[i] = '0';
        i++;
    }
    fputc(("%u", bin_to_dec(escrita)), compactado);
}