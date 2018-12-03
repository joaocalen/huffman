#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Arquivo que manipula binário, decimais e afins para inserção no arquivo e também para codificação necessária para o descompactador

// retorna caracter referente à sequencia binária na tabela ASCII

unsigned char bin_to_dec(unsigned char* binario) {
    int dec = 0;
    for (int i = 0; i < 8; i++) {
        if (binario[i] == '1') {
            dec += pow(2, 7 - i);
        }
    }
    return (unsigned char) dec;
}

char* dec_to_bin(int decimal) {
    char* binario = (char*) malloc(9 * sizeof (char));
    memset(binario,0,9);
    //printf("%d",decimal);
    int i = 7;
    while (i >= 0) {
        if (decimal >= pow(2, i)) {
            binario[7-i] = '1';
            decimal -= pow(2, i);
        } else {
            binario[7-i] = '0';
        }
        i--;
    }
    return binario;
}
