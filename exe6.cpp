//
// Created by lucia on 23/05/2022.
//

#include "exe6.h"

void maquinaEstados(){
    int state = 0;
    int msg[3];
    bool executando = true;

    while (executando) {
        switch (state) {
            case INICIALIZACAO:
                inicializaConxao();
                state = CONECTA;
                break;
            case CONECTA:
                conecta();
                state = CONECTADO;
                break;
            case CONECTADO:
                if(fimExecucao())
                    state = DESCONECTA;
                else{
                    mensagemPendente(msg);
                    if(msg[0] == 0)
                        state = CONECTADO;
                    else if(msg[0] == 1)
                        state = RECEBE_MENSAGEM;
                    else
                        state = ENVIA_MENSAGEM;
                }
                break;
            case DESCONECTA:
                desconecta();
                state = FIM;
                break;
            case ENVIA_MENSAGEM:
                enviaMensagem();
                state = CONECTADO;
                break;
            case RECEBE_MENSAGEM:
                recebeMensagem();
                state = CONECTADO;
                break;
            case FIM:
                executando = false;
                break;
        }
    }
}