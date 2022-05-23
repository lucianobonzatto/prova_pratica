//
// Created by lucia on 21/05/2022.
//

#ifndef PROVA_EXE6_H
#define PROVA_EXE6_H

#include <iostream>

#define INICIALIZACAO 0
#define CONECTA 1
#define CONECTADO 2
#define DESCONECTA 3
#define ENVIA_MENSAGEM 4
#define RECEBE_MENSAGEM 5
#define FIM 6

void maquinaEstados();
void inicializaConxao(){ }
void conecta(){ }
void desconecta(){ }
void enviaMensagem(){ }
void recebeMensagem(){ }

bool mensagemPendente(int* msg){return false;}
bool fimExecucao(){return false;}

#endif //PROVA_EXE6_H
