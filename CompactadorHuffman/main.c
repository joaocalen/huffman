/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: joaogcalen
 *
 * Created on 6 de Novembro de 2018, 01:06
 */

#include <stdio.h>
#include <stdlib.h>

#include "leitorArquivo.h"
#include "organizadorLista.h"

/*
 * 
 */
int main(int argc, char** argv) {
    organizador(contagemArquivo(argv[argc - 1]));
    return (EXIT_SUCCESS);
}

