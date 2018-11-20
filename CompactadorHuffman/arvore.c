/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
int max(int a, int b);

struct arvore {
    Arvore* noD;
    Arvore* noE;
    char conteudo;
    int ocorrencias;
};

Arvore* arvore_criavazia() {
    return NULL;
}

Arvore* arvore_cria(char c, int o, Arvore* e, Arvore* d) {
    Arvore* nova = (Arvore*) malloc(sizeof (Arvore));
    nova -> noE = e;
    nova -> noD = d;
    nova -> conteudo = c;
    nova -> ocorrencias = o;
    return nova;
}

int arvore_vazia(Arvore* a) {
    return (a == arvore_criavazia());
}

Arvore* arvore_libera(Arvore* a) {
    if (!arvore_vazia(a)) {
        arvore_libera(a->noE);
        arvore_libera(a->noD);
        free(a);
    }
    return NULL;
}

int arvore_pertence(Arvore* a, char c) {
    if (arvore_vazia(a)) {
        return 0;
    } else {
        return ((arvore_getConteudo(a) == c) || arvore_pertence(a->noE, c) || arvore_pertence(a->noD, c));
    }
}

void arvore_imprime(Arvore* a) {
    printf("<%c%d", arvore_getConteudo(a),arvore_getOcorrencias(a));
    if (!arvore_vazia(a)) {
        arvore_imprime(a->noE);
        arvore_imprime(a->noD);
    }
    printf(">");
}

int folhas(Arvore* a) {
    if (arvore_vazia(a)) {
        return 0;
    } else if (arvore_vazia(a->noE) && (arvore_vazia(a->noD))) {
        return 1;
    } else {
        return folhas(a->noE) + folhas(a->noD);
    }
}

int ocorrencias(Arvore* a, char c) {
    if (arvore_vazia(a)) {
        return 0;
    } else if (arvore_getConteudo(a) == c) {
        ocorrencias(a->noE, c) +ocorrencias(a->noD, c);
        return 1;
    } else {
        return ocorrencias(a->noE, c) + ocorrencias(a->noD, c);
    }
}

int altura(Arvore* a) {
    if (arvore_vazia(a)) {
        return -1;
    } else {
        return 1 + max(altura(a->noE), altura(a->noD));
    }
}

Arvore* arvore_pai(Arvore* a, char c) {
    if (arvore_getConteudo(a->noD) == c || arvore_getConteudo(a->noE) == c) {
        return a;
    } else if (arvore_vazia(a)) {
        return NULL;
    } else {
        arvore_pai(a->noE, c);
        arvore_pai(a->noD, c);
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// (char) 0 equivale a NULL na tabela ASCII
char arvore_getConteudo(Arvore* a) {
    if (!arvore_vazia(a))
        return a -> conteudo;
    return (char) 0;
}

int arvore_getOcorrencias(Arvore* a) {
    if (!arvore_vazia(a))
        return a -> ocorrencias;
    return 0;
}