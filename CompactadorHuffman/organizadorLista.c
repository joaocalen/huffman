
#include <stdlib.h>

#include "organizadorLista.h"
// Arquivo com o objetivo de receber a lista de árvores inicial, organizá-la e retornar a árvore de huffman montada

ListaArvores* organizador(ListaArvores* lista) {
    lista = organizaListaOrdemCrescente(lista);
    lista_imprime(lista);
    
    Arvore* huffman = montaArvoreHuffman(lista);
    arvore_imprime(huffman);
    
    arvore_libera(huffman);
    
}

// caso a tenha mais ocorrências que b, o número retornado será positivo (indica que a > b), caso seja menor, retorna negativo (indica que a < b), caso seja 0, pouco importa a ordem, já que são iguais.

int compara(Arvore* a, Arvore* b) {
    return arvore_getOcorrencias(a) - arvore_getOcorrencias(b);
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
        lista_insere(arvore_cria((char) 0, arvore_getOcorrencias(arv1) + arvore_getOcorrencias(arv2), arv1, arv2),lista);
    }
    arv1 = lista_retiraPrimeiro(lista);
    lista_libera(lista);
    return arv1;
}