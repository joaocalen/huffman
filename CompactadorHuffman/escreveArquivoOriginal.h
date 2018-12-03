/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   escreveArquivoOriginal.h
 * Author: joaogcalen
 *
 * Created on 2 de Dezembro de 2018, 18:16
 */

#ifndef ESCREVEARQUIVOORIGINAL_H
#define ESCREVEARQUIVOORIGINAL_H

#ifdef __cplusplus
extern "C" {
#endif

    void montaArquivoOriginal(char* nome, unsigned char** tabela);

    char* retiraExtensaoComp(char* nome);

    int caracterReferente(char* binario, unsigned char** tabela);

    void andaPonteiro(FILE* compactado, int numBits);

    char* converteConteudo(FILE* compactado, char* conteudo);

#ifdef __cplusplus
}
#endif

#endif /* ESCREVEARQUIVOORIGINAL_H */

