/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2018103815
 *
 * Created on 30 de Agosto de 2018, 09:21
 */

//#include <cstdlib>
#include "lista.h"
#include "arvore.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//using namespace std;

struct arvore_celula {
    Arvore* arvore;
    Arvore_celula* prox;
};

struct lista {
    Arvore_celula* prim;
    Arvore_celula* ult;
    int tam; // tam max da lista
};

ListaArvores* lista_inicializa() {
    ListaArvores* lista;
    lista = (ListaArvores*) malloc(sizeof (ListaArvores));
    lista -> prim = NULL;
    lista -> ult = NULL;
    return lista;
}

void lista_insere(Arvore* arvore, ListaArvores* lista) {
    Arvore_celula* arvoreCel = (Arvore_celula*) malloc(sizeof (Arvore_celula));
    arvoreCel -> arvore = arvore;
    if (lista -> prim == NULL) {
        lista -> prim = arvoreCel;
    } else {
        lista -> ult -> prox = arvoreCel;
    }
    lista -> ult = arvoreCel;
    arvoreCel -> prox = NULL;
}

Arvore* lista_retira(ListaArvores* lista, char conteudo) {
    //Arvore_celula* arvoreCel = (Arvore_celula*) malloc(sizeof (Arvore_celula));
    //arvoreCel -> arvore -> conteudo = conteudo;
    Arvore_celula* aux;
    Arvore_celula* ant;
    Arvore* retorno = NULL;
    if (lista -> ult == NULL) {
        return NULL;
    } else if ((lista -> prim == lista -> ult) && arvore_getConteudo(lista ->prim -> arvore) == conteudo) {
        retorno = lista -> prim -> arvore;
        free(lista -> prim);
        lista -> prim = NULL;
        lista -> ult = NULL;
        (lista -> tam)--;
        printf("TAMANHO: %d",lista -> tam);
        return retorno;
    }
    aux = lista -> prim;
    while (arvore_getConteudo(aux -> arvore) != conteudo) {
        ant = aux;
        aux = aux -> prox;
    }
    if (aux != NULL) {
        ant -> prox = aux -> prox;
        retorno = aux -> arvore;
        (lista -> tam)--;
        free(aux);
    }
    return retorno;
}

ListaArvores* lista_libera(ListaArvores* lista) {
    Arvore_celula* p = lista -> prim;
    Arvore_celula* aux;
    while (p != NULL) {
        aux = p->prox;
        free(p->arvore);
        free(p);
        p = aux;
    }
    free(lista);
    return NULL;
}

void lista_imprime(ListaArvores* lista) {
    if (lista != NULL) {
        Arvore_celula* p = lista -> prim;
        while (p != NULL) {
            printf("Caracter: %c\n", arvore_getConteudo(p-> arvore));
            printf("Ocorrências: %d\n", arvore_getOcorrencias(p-> arvore));
            printf("\n\n");
            p = p -> prox;
        }
    }
}

int lista_getTamanho(ListaArvores* lista) {
    return lista -> tam;
}

ListaArvores* lista_setTamanho(ListaArvores* lista, int tam) {
    lista -> tam = tam;
    return lista;
}

Arvore* lista_retiraMenor(ListaArvores* lista) {
    Arvore* menor = lista -> prim -> arvore;
    Arvore_celula* aux = lista -> prim;
    while (menor != NULL) {
        if (arvore_getOcorrencias(menor) > arvore_getOcorrencias(aux->arvore)) {
            menor = aux -> arvore;
        }
        aux = aux -> prox;
    }
    return lista_retira(lista, arvore_getConteudo(menor));
}

//Arvore* lista_getArvore(Arvore_celula* arvorecel){
//    return arvorecel -> arvore;
//}

//int lista_pertence(ListaArvores* lista, char c) {
//    
//}