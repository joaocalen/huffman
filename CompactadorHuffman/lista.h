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



    /*Inicializa o sentinela de uma lista
     * inputs: nenhum
     * output: Sentinela inicializado
     * pre-condicao: nenhuma
     * pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL
     */
    ListaArvores* lista_inicializa();

    /*Insere um aluno na primeira posi��o da lista de alunos
     * inputs: aluno a ser inserido na lista (do tipo TipoItem) e a lista
     * output: nenhum
     * pre-condicao: aluno e lista n�o s�o nulos
     * pos-condicao: lista cont�m o aluno inserido na primeira posi��o
     */
    void lista_insere(Arvore* arvore, ListaArvores* lista);

    /*Retira um aluno de matr�cula mat da lista de alunos
     * inputs: a lista e a matr�cula do aluno a ser retirado da lista
     * output: o aluno (do tipo TipoItem) retirado da lista ou NULL, se o aluno n�o se encontrar na lista
     * pre-condicao: lista n�o � nula
     * pos-condicao: lista n�o cont�m o aluno de matr�cula mat
     */
    Arvore* lista_retira(ListaArvores* lista, char conteudo);


    /*Imprime os dados de todos os alunos da lista
     * inputs: a lista de alunos
     * output: nenhum
     * pre-condicao: lista n�o � nula
     * pos-condicao: dados dos alunos impressos na saida padrao
     */
    void lista_imprime(ListaArvores* lista);

    /*Libera toda a mem�ria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
     * inputs: a lista encadeada de alunos
     * output: Lista vazia (NULL)
     * pre-condicao: lista n�o � nula
     * pos-condicao: mem�ria alocada � liberada
     */
    ListaArvores* lista_libera(ListaArvores* lista);


#ifdef __cplusplus
}
#endif

#endif /* LISTA_H */

