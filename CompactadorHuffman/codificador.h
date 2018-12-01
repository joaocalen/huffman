/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   codificador.h
 * Author: joaogcalen
 *
 * Created on 30 de Novembro de 2018, 23:13
 */

#ifndef CODIFICADOR_H
#define CODIFICADOR_H

#include "arvore.h"

#ifdef __cplusplus
extern "C" {
#endif

char* percorreArvore(Arvore* huffman, char* sequencia, int tam);

char* criaSequencias(Arvore* huffman);


#ifdef __cplusplus
}
#endif

#endif /* CODIFICADOR_H */

