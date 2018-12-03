
#include <stdlib.h>

#include "organizadorLista.h"
// Arquivo com o objetivo de receber a lista de árvores inicial, organizá-la e retornar a árvore de huffman montada

Arvore* organizador(ListaArvores* lista) {
    lista = organizaListaOrdemCrescente(lista);
    Arvore* huffman = montaArvoreHuffman(lista);
    return huffman;
}


ListaArvores* organizaListaOrdemCrescente(ListaArvores* lista) {
    // retira o elemento com menor número de ocorrências da lista e adiciona em outra lista. No fim do procedimento, free na lista inicial.
    // enquanto houver elementos na primeira lista:
    ListaArvores* novaLista = lista_inicializa();
    while (lista_getTamanho(lista) > 0) {
        lista_insere(retiraMenor(lista), novaLista);
    }
    lista_libera(lista);
    return novaLista;
}

Arvore* retiraMenor(ListaArvores* lista) {
    return lista_retiraMenor(lista);
}

// transforma lista de nós em uma árvore de huffman

Arvore* montaArvoreHuffman(ListaArvores* lista) {
    Arvore* arv1 = arvore_criavazia();
    Arvore* arv2 = arvore_criavazia();
    while (lista_getTamanho(lista) > 1) {
        arv1 = lista_retiraPrimeiro(lista);
        arv2 = lista_retiraPrimeiro(lista);
        lista_insere(arvore_cria((unsigned char) 0, arvore_getOcorrencias(arv1) + arvore_getOcorrencias(arv2), arv1, arv2),lista);
        lista = organizaListaOrdemCrescente(lista);
    }
    arv1 = lista_retiraPrimeiro(lista);
    lista_libera(lista);
    return arv1;
}