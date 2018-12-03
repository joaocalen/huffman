/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   descompactador.c
 * Author: joaogcalen
 *
 * Created on 2 de Dezembro de 2018, 02:03
 */

#include <stdio.h>
#include <stdlib.h>
#include "leitorArquivo.h"
#include "codificador.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Arvore* huffman = lerCompactado(argv[argc - 1]);
    unsigned char** tabela = criaSequencias(huffman);
    return (EXIT_SUCCESS);
}

