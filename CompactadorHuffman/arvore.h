/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arvore.h
 * Author: joaogcalen
 *
 * Created on 6 de Novembro de 2018, 01:31
 */

#ifndef ARVORE_H
#define ARVORE_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct arvore Arvore;

    //Cria uma �rvore vazia
    Arvore* arvore_criavazia(void);

    //cria uma �rvore com a informa��o do n� raiz c, e
    //com sub�rvore esquerda e e sub�rvore direita d
    Arvore* arvore_cria(unsigned char c, int o, Arvore* e, Arvore* d);

    //libera o espa�o de mem�ria ocupado pela �rvore a
    Arvore* arvore_libera(Arvore* a);

    //retorna true se a �rvore estiver vazia e false 
    //caso contr�rio
    int arvore_vazia(Arvore* a);

    //indica a ocorr�ncia (1) ou n�o (0) do caracter c
    int arvore_pertence(Arvore* a, unsigned char c);

    //imprime as informa��es dos n�s da �rvore
    void arvore_imprime(Arvore* a);

    //retorna o pai de um dado no
    Arvore* arvore_pai(Arvore* a, unsigned char c);

    //retorna a quantidade de folhas de uma arvore binaria
    int arvore_folhas(Arvore* a);

    //retorna o numero de ocorrencias de um dado caracter na arvore 
    int arvore_ocorrencias(Arvore* a, unsigned char c);

    //retorna o campo informacao de um dado no
    unsigned char arvore_getConteudo(Arvore* a);

    //retorna a altura da arvore
    int arvore_altura(Arvore* a);

    // retorna o número de ocorrências do caracter daquele nó
    int arvore_getOcorrencias(Arvore* a);

    // retorna 1 se a árvore for nó folha, 0 se não.
    int arvore_isFolha(Arvore* a);

    // retorna o nó filho à esquerda da árvore
    Arvore* arvore_getNoE(Arvore* a);

    // retorna o nó filho à direita da árvore
    Arvore* arvore_getNoD(Arvore* a);

    // retorna o número de nós da árvore
    int arvore_qntdNos(Arvore* a);

    // Dada uma árvore a e uma árvore b, retorna a com b de nó filho à esquerda
    Arvore* arvore_setNoE(Arvore* a, Arvore* b);

    // Dada uma árvore a e uma árvore b, retorna a com b de nó filho à direita
    Arvore* arvore_setNoD(Arvore* a, Arvore* b);

    // Dada uma árvore a um inteiro x, retorna a como tendo x ocorrências
    Arvore* arvore_setOcorrencias(Arvore* a, int ocorrencias);

    // Dada uma árvore a um caracter c, retorna a como tendo c de conteúdo
    Arvore* arvore_setConteudo(Arvore* a, unsigned char conteudo);

#ifdef __cplusplus
}
#endif

#endif /* ARVORE_H */

