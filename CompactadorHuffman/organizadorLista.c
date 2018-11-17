
#include <stdlib.h>

#include "lista.h"
#include "arvore.h"
// Arquivo com o objetivo de receber a lista de árvores inicial, organizá-la e retornar a árvore de huffman montada

ListaArvores* organizador(ListaArvores* lista) {



}

// caso a tenha mais ocorrências que b, o número retornado será positivo (indica que a > b), caso seja menor, retorna negativo (indica que a < b), caso seja 0, pouco importa a ordem, já que são iguais.

int compara(Arvore* a, Arvore* b) {
    return arvore_getOcorrencias(a) - arvore_getOcorrencias(b);
}

ListaArvores* organizaListaOrdemCrescente(ListaArvores* lista){
 //   return qsort(lista,lista_getTamanho(lista),sizeof(Arvore), )
}