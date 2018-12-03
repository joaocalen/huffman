/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   escreveArquivoOriginal.h
 * Author: joaogcalen
 *
 * Created on 2 de Dezembro de 2018, 18:16
 */

#ifndef ESCREVEARQUIVOORIGINAL_H
#define ESCREVEARQUIVOORIGINAL_H

#ifdef __cplusplus
extern "C" {
#endif
    // função principal do arquivo. Dada a tabela de sequencias e o nome do arquivo, monta o arquivo original, ou seja, o arquivo antes da compactação
    void montaArquivoOriginal(char* nome, unsigned char** tabela);
    
    // dado o nome completo do arquivo, retorna o nome sem a extensão. Exemplo: Dado "nome.txt", retorna apenas "nome"
    char* retiraExtensaoComp(char* nome);

    /* dado uma sequencia binária (uma cadeia de caracteres cujos caracteres são uns e zeros), verifica se há um caracter na tabela referente a tal sequencia. Se sim,
     * retorna o inteiro referente ao caracter. Se não, retorna -1 
     *  */
    int caracterReferente(char* binario, unsigned char** tabela);

    // anda com o ponteiro pelo arquivo até chegar ao início da parte compactada. Ou seja, logo após o cabeçalho
    void andaPonteiro(FILE* compactado, int numBits);

    // Converte todo o conteúdo do arquivo compactado em uma cadeia de caracter, representando um caracter por 8 caracteres de 0s e 1s.
    char* converteConteudo(FILE* compactado, char* conteudo);

#ifdef __cplusplus
}
#endif

#endif /* ESCREVEARQUIVOORIGINAL_H */

