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

    ListaArvores* organizador(ListaArvores* lista);

    int compara(Arvore* a, Arvore* b);

    ListaArvores* organizaListaOrdemCrescente(ListaArvores* lista);

    Arvore* retiraMenor(ListaArvores* lista);


#ifdef __cplusplus
}
#endif

#endif /* ORGANIZADORLISTA_H */

