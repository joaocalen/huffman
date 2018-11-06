/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#define n 255

int contagemArquivo(char* arquivo) {

    FILE *entrada;
    entrada = fopen(arquivo, "r");

    int caracteres[n];

    inicializaVetor(caracteres);

    int c = fgetc(entrada);

    // -1 é o inteiro referente a EOF
    while (c != -1) {
        caracteres[c]++;
        c = fgetc(entrada);
    }
    
    // a partir disso, criar lista e ir adicionando folhas de todos os caracteres cuja ocorrência > 0
    // depois, organizar a lista de forma crescente em ocorrências.
    
    
    
}

void inicializaVetor(int* v[]) {
    int i = 0;

    while (i < n) {
        v[i] = 0;
    }

}