
#include <math.h>

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
