//
// Created by lucia on 21/05/2022.
//

#ifndef PROVA_FASE3_QUESTAO3_H
#define PROVA_FASE3_QUESTAO3_H

int store(unsigned char * msg,int size);
int Get_Eeprom_Temporary_Buffer_Space_Available(){return 0;}
bool Check_Message_Integrity(unsigned char * message_pointer, int message_size){return 0;}
int Get_Eeprom_First_Available_Address(){return 0;}
bool Write_To_Eeprom_Temporary_Buffer(unsigned char * buffer_to_write, int buffer_size){return 0;}
bool Write_Eeprom_Temporary_Buffer_To_Flash(unsigned char memory_region){return 0;}
void Reset_Eeprom_Temporary_Buffer(){}

#endif //PROVA_FASE3_QUESTAO3_H
