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
    unsigned char conteudo;
    int ocorrencias;
};

Arvore* arvore_criavazia() {
    return NULL;
}

Arvore* arvore_cria(unsigned char c, int o, Arvore* e, Arvore* d) {
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

int arvore_pertence(Arvore* a, unsigned char c) {
    if (arvore_vazia(a)) {
        return 0;
    } else {
        return ((arvore_getConteudo(a) == c) || arvore_pertence(a->noE, c) || arvore_pertence(a->noD, c));
    }
}

void arvore_imprime(Arvore* a) {
    printf("<%c%d", arvore_getConteudo(a), arvore_getOcorrencias(a));
    if (!arvore_vazia(a)) {
        arvore_imprime(a->noE);
        arvore_imprime(a->noD);
    }
    printf(">");
}

int arvore_folhas(Arvore* a) {
    if (arvore_vazia(a)) {
        return 0;
    } else if (arvore_vazia(a->noE) && (arvore_vazia(a->noD))) {
        return 1;
    } else {
        return arvore_folhas(a->noE) + arvore_folhas(a->noD);
    }
}

int ocorrencias(Arvore* a, unsigned char c) {
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

Arvore* arvore_pai(Arvore* a, unsigned char c) {
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

unsigned char arvore_getConteudo(Arvore* a) {
    if (!arvore_vazia(a))
        return a -> conteudo;
    return (unsigned char) 0;
}

int arvore_getOcorrencias(Arvore* a) {
    if (!arvore_vazia(a))
        return a -> ocorrencias;
    return 0;
}

int arvore_isFolha(Arvore* a) {
    return a != arvore_criavazia() && a->noD == arvore_criavazia() && a->noE == arvore_criavazia();
}

Arvore* arvore_getNoE(Arvore* a) {
    return a->noE;
}

Arvore* arvore_getNoD(Arvore* a) {
    return a->noD;
}

Arvore* arvore_setNoE(Arvore* a, Arvore* b) {
    if (!arvore_vazia(a))
        a->noE = b;
    return a;
}

Arvore* arvore_setNoD(Arvore* a, Arvore* b) {
    if (!arvore_vazia(a))
        a->noD = b;
    return a;
}

Arvore* arvore_setOcorrencias(Arvore* a, int ocorrencias) {
    if (!arvore_vazia(a))
        a->ocorrencias = ocorrencias;
    return a;
}

Arvore* arvore_setConteudo(Arvore* a, unsigned char conteudo) {
    if (!arvore_vazia(a)) {
        a->conteudo = conteudo;
    }
    return a;
}

int arvore_qntdNos(Arvore* a) {
    if (a != NULL) {
        return arvore_qntdNos(a->noE) + arvore_qntdNos(a->noD) + 1;
    } else {
        return 0;
    }
}
