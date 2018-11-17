/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   leitorArquivo.h
 * Author: joaogcalen
 *
 * Created on 6 de Novembro de 2018, 01:29
 */

#ifndef LEITORARQUIVO_H
#define LEITORARQUIVO_H

#include "arvore.h"
#include "lista.h"

#ifdef __cplusplus
extern "C" {
#endif

    void inicializaVetor(int* c);
    ListaArvores* contagemArquivo(char* arquivo);
    ListaArvores* adicionarArvoresArquivo(int* c);

#ifdef __cplusplus
}
#endif

#endif /* LEITORARQUIVO_H */

