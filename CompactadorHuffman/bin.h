/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bin.h
 * Author: joaogcalen
 *
 * Created on 1 de Dezembro de 2018, 11:47
 */

#ifndef BIN_H
#define BIN_H

#ifdef __cplusplus
extern "C" {
#endif

    // Dado um número em binário, retorna o caracter referente ao número decimal após a conversão
    unsigned char bin_to_dec(unsigned char* binario);

    // dado um número decimal, retorna uma cadeia de caracter que é justamente o número em binário
    char* dec_to_bin(unsigned char decimal);
#ifdef __cplusplus
}
#endif

#endif /* BIN_H */

