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
    Arvore* arvore_cria(char c, int o, Arvore* e, Arvore* d);

    //libera o espa�o de mem�ria ocupado pela �rvore a
    Arvore* arvore_libera(Arvore* a);

    //retorna true se a �rvore estiver vazia e false 
    //caso contr�rio
    int arvore_vazia(Arvore* a);

    //indica a ocorr�ncia (1) ou n�o (0) do caracter c
    int arvore_pertence(Arvore* a, char c);

    //imprime as informa��es dos n�s da �rvore
    void arvore_imprime(Arvore* a);

    //retorna o pai de um dado no
    Arvore* arvore_pai(Arvore* a, char c);

    //retorna a quantidade de folhas de uma arvore binaria
    int arvore_folhas(Arvore* a);

    //retorna o numero de ocorrencias de um dado caracter na arvore 
    int arvore_ocorrencias(Arvore* a, char c);

    //retorna o campo informacao de um dado no
    char arvore_getConteudo(Arvore* a);

    //retorna a altura da arvore
    int arvore_altura(Arvore* a);

    int arvore_getOcorrencias(Arvore* a);


#ifdef __cplusplus
}
#endif

#endif /* ARVORE_H */

