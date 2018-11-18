
#include <stdlib.h>

#include "organizadorLista.h"
// Arquivo com o objetivo de receber a lista de árvores inicial, organizá-la e retornar a árvore de huffman montada

ListaArvores* organizador(ListaArvores* lista) {
    lista = organizaListaOrdemCrescente(lista);
    lista_imprime(lista);
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
    return novaLista;
}

Arvore* retiraMenor(ListaArvores* lista) {
    return lista_retiraMenor(lista);
}

