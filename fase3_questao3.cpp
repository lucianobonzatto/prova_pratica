/*considere que essas funções estão implementadas em outros arquivos incluídos no projeto*/
int Get_Eeprom_Temporary_Buffer_Space_Available();
bool Check_Message_Integrity(unsigned char * message_pointer, int message_size);
int Get_Eeprom_First_Available_Address();
bool Write_To_Eeprom_Temporary_Buffer(unsigned char * buffer_to_write, int buffer_size);
bool Write_Eeprom_Temporary_Buffer_To_Flash(unsigned char memory_region);
void Reset_Eeprom_Temporary_Buffer();
/*fim das declarações externas*/
//--- variáveis globais
int last_command_index = 0;
int last_command_type = 0;
//------- A partir daqui você deve melhorar
#define STATUS_MSG    1
#define CMD_MSG       2
#define RST_CMD       3
#define FW_UPD        4
#define FW_DWLD_MSG   5
#define CFG_MSG       6

int store(unsigned char * msg,int size)
{
    if(!Check_Message_Integrity(msg,size)) {
        //mensagem corrompida
        return -1;
    }
    if(!(Get_Eeprom_Temporary_Buffer_Space_Available()>size-3)) {
        //eeprom pequena
        return -1;
    }
    if(!(msg[0]==FW_DWLD_MSG || msg[0]==CFG_MSG)) {
        //mensagem invalida
        return -1;
    }
    if(!(msg[0]==last_command_type||msg[2]==0)){
        //mensagem invalida
        Reset_Eeprom_Temporary_Buffer();
        return -1;
    }

    last_command_type=msg[0];
    if(last_command_index==msg[1]+1)
    {
        last_command_index=msg[2];
        Write_To_Eeprom_Temporary_Buffer(&msg[3],size-3);
        return 0;
    }
    else if(msg[1]==msg[2])
    {
        last_command_index=msg[2];
        Write_To_Eeprom_Temporary_Buffer(&msg[3],size-3);
        Write_Eeprom_Temporary_Buffer_To_Flash(msg[0]);
        return 0;
    }
    else
    {
        last_command_index=msg[2];
        return -1;
    }
}