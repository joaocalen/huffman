
#include <stdio.h>
#include <string.h>
#include "escreveArquivoCompactado.h"


void montaArquivo(char* nome, unsigned char* tabela[]){
    FILE* compactado;
    char* novoNome = retiraExtensao(nome);
    compactado = fopen(strcat(novoNome,".comp"),"w");
    escreveCabecalho(compactado,tabela);
    
}

char* retiraExtensao(char* nome){
    int i = strlen(nome);
    while (nome[i] != '.'){
        i--;
    }
    nome[i] = '\0';
    return nome;
}

void escreveCabecalho(FILE* arquivo, unsigned char* tabela[]){
    
}