/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   escreveArquivoCompactado.h
 * Author: joaogcalen
 *
 * Created on 1 de Dezembro de 2018, 12:11
 */

#ifndef ESCREVEARQUIVOCOMPACTADO_H
#define ESCREVEARQUIVOCOMPACTADO_H

#include "arvore.h"

#ifdef __cplusplus
extern "C" {
#endif

    void montaArquivo(char* nome, unsigned char** tabela, Arvore* huffman);
    
    char* retiraExtensao(char* nome);
    
    void escreveCabecalho(FILE* arquivo, Arvore* huffman, unsigned char* escrita, int* i);
    
    void escreveArquivo(FILE* original, FILE* compactado, unsigned char** tabela);



#ifdef __cplusplus
}
#endif

#endif /* ESCREVEARQUIVOCOMPACTADO_H */

