//
// Created by lucia on 21/05/2022.
//
#include "exe2.h"

double seno(float angulo, int num = 5){
    double sen_angulo = 0, termo_atual = 1, denominador = 1, potencia = 1, numerador = angulo;

    for (int i = 0; i < num; i++) {
        termo_atual = numerador / denominador;

        //verifica se (-1)^i é igual a -1 ou 1
        if((i%2) == 1)
            termo_atual *= -1;
        sen_angulo += termo_atual;

        //calcula x^(2(i+1)+1) baseado no valor de i
        numerador = angulo * (angulo * potencia) * (angulo * potencia);
        potencia *= angulo;     //atualiza potencia para ficar igual a angulo^(i+1)

        //calcula (2(i+1)+1)! baseado no valor de i
        denominador *= (2 * (i + 1)) * (2 * (i + 1) + 1);
    }
    return sen_angulo;
}
