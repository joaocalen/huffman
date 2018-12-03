/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lista.h
 * Author: joaogcalen
 *
 * Created on 12 de Novembro de 2018, 22:52
 */

#ifndef LISTA_H
#define LISTA_H

#include "arvore.h"


#ifdef __cplusplus
extern "C" {
#endif

    typedef struct arvore_celula Arvore_celula;

    typedef struct lista ListaArvores;



    /*Inicializa o sentinela de umaa lista
     * inputs: nenhum
     * output: Sentinela inicializado
     * pre-condicao: nenhuma
     * pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL e tam = 0
     */
    ListaArvores* lista_inicializa();

    /*Insere uma árvore na ultima posi��o da lista de árvores (para facilitar manipulação quanto a montagem da arvore de huffman)
     * inputs: árvore a ser inserido na lista e a lista
     * output: nenhum
     * pre-condicao: árvore e lista n�o s�o nulos
     * pos-condicao: lista cont�m a árvore inserido na última posição
     */
    void lista_insere(Arvore* arvore, ListaArvores* lista);

    /*Retira uma árvore de com o conteúdo dado da lista de árvores
     * inputs: a lista e a caracter da árvore a ser retirada da lista
     * output: a árvore retirada da lista ou NULL, se o árvore não se encontrar na lista
     * pre-condicao: lista n�o � nula
     * pos-condicao: lista n�o cont�m a árvore com tal conteúdo
     */
    Arvore* lista_retira(ListaArvores* lista, unsigned char conteudo);


    /*Imprime os dados de todas as árvores da lista
     * inputs: a lista de árvores
     * output: nenhuma
     * pre-condicao: lista n�o � nula
     * pos-condicao: dados das árvores impressos na saida padrao
     */
    void lista_imprime(ListaArvores* lista);

    /*Libera toda a mem�ria alocada para a lista
     * inputs: a lista encadeada de árvores
     * output: Lista vazia (NULL)
     * pre-condicao: lista n�o � nula
     * pos-condicao: mem�ria alocada � liberada
     */
    ListaArvores* lista_libera(ListaArvores* lista);
    
    // retira o elemento com menor número de ocorrências da lista
    Arvore* lista_retiraMenor(ListaArvores* lista);
    
    // define o tamanho da lista e retorna a própria lista com o tamanho definido
    ListaArvores* lista_setTamanho(ListaArvores* lista, int tam);
    
    // retorna o tamanho da lista especificada
    int lista_getTamanho(ListaArvores* lista);
    
    // retira o primeiro elemento da lista
    Arvore* lista_retiraPrimeiro(ListaArvores* lista);


#ifdef __cplusplus
}
#endif

#endif /* LISTA_H */

