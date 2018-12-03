/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   organizadorLista.h
 * Author: joaogcalen
 *
 * Created on 17 de Novembro de 2018, 22:32
 */

#ifndef ORGANIZADORLISTA_H
#define ORGANIZADORLISTA_H

#include "lista.h"
#include "arvore.h"

#ifdef __cplusplus
extern "C" {
#endif

    // Dada uma lista de nós folhas (árvores), organiza tal lista para retornar uma árvore de huffman completa
    Arvore* organizador(ListaArvores* lista);

    // Dada uma lista de árvores, retorna a própria lista reorganizada em ordem crescente de ocorrência
    ListaArvores* organizaListaOrdemCrescente(ListaArvores* lista);

    // retira a árvore com o menor número de ocorrências da lista
    Arvore* retiraMenor(ListaArvores* lista);
    
    // monta a árvore de huffman a partir de vários nós folhas apresentados na lista de árvores.
    Arvore* montaArvoreHuffman(ListaArvores* lista);


#ifdef __cplusplus
}
#endif

#endif /* ORGANIZADORLISTA_H */

