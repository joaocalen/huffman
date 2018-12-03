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

    // função principal do arquivo. Dada a tabela de sequencias, a tabela huffman e o nome do arquivo, monta o arquivo compactado de saída
    void montaArquivo(char* nome, unsigned char** tabela, Arvore* huffman);

    // dado o nome completo do arquivo, retorna o nome sem a extensão. Exemplo: Dado "nome.txt", retorna apenas "nome"
    char* retiraExtensao(char* nome);

    /* escreve o cabecalho do arquivo compactado. Nele está as principais informações para a descompactação. No cabeçalho,
    é impresso primeiramente o número de bits usados para descreve a árvore, seguido de um ponto, seguido do número de caracteres do arquivo original, seguido de outro ponto e por fim
    seguido da árvore de huffman impressa. A árvore é impressa da seguinte forma: Para cada nó não-folha, é impresso o bit 0, e para cada nó folha, é impresso o bit 1 seguido de 8 bits
    que indetificam unicamente o caracter referente ao nó folha. Esses 8 bits definem o caracter na tabela ascii*/
    void escreveCabecalho(FILE* arquivo, Arvore* huffman, unsigned char* escrita, int* i);

    // para cada caracter do arquivo principal, junta-se a sequencia binária referente a este na tabela montada a partir da árvore de huffman. Para cada 8 bits, um caracter é escrito no arquivo final
    void escreveArquivo(FILE* original, FILE* compactado, unsigned char** tabela);



#ifdef __cplusplus
}
#endif

#endif /* ESCREVEARQUIVOCOMPACTADO_H */

