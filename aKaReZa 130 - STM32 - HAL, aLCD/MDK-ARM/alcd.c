#include "alcd.h"

bool __alcd_initStatus = false;
uint8_t __alcd_x_position = 0;
uint8_t __alcd_y_position = 0; 


void alcd_customChar(uint8_t _alcd_CGRAMadd, const uint8_t *_alcd_CGRAMdata)
{
    uint8_t _forCounter = 0;
    uint8_t _CG_Add = __alcd_CGRAM_Start + (_alcd_CGRAMadd << 3);
    for(_forCounter=0; _forCounter < 8; _forCounter++)
    {
        alcd_write(_CG_Add++, __alcd_writeCmd);
        alcd_write(*_alcd_CGRAMdata++, __alcd_writeData);
    };
    alcd_gotoxy(__alcd_x_position, __alcd_y_position);
};


#ifdef __alcd_BL_GPIO_Port
    void alcd_backLight(bool _alcd_BL)
    {
			HAL_GPIO_WritePin(__alcd_BL_GPIO_Port, __alcd_BL_Pin, _alcd_BL);
    };
#endif

void alcd_display(bool _alcd_Display, bool _alcd_Cursor, bool _alcd_Blink)
{
    uint8_t _cursorState = __alcd_Display_OFF;
    bitChange(_cursorState, 0, _alcd_Blink);
    bitChange(_cursorState, 1, _alcd_Cursor); 
    bitChange(_cursorState, 2, _alcd_Display); 
    alcd_write(_cursorState, __alcd_writeCmd);
};


void alcd_clear(void)
{
    alcd_write(__alcd_Display_Clear, __alcd_writeCmd);
    __alcd_x_position = 0;
    __alcd_y_position = 0;
    __alcd_delay(__alcd_delay_modeSet);
};


void alcd_gotoxy(uint8_t _alcd_x, uint8_t _alcd_y)
{
    uint8_t _address = 0x00;

    if(_alcd_x >= __alcd_max_x || _alcd_y >= __alcd_max_y)
    {
        __alcd_x_position = 0;
        __alcd_y_position = 0;
    }
    else
    {
        __alcd_x_position = _alcd_x;
        __alcd_y_position = _alcd_y;
    };

    _address = (__alcd_y_position == 0) ? __alcd_Line1_Start : __alcd_Line2_Start;
    _address = _address + __alcd_x_position;

    alcd_write(_address, __alcd_writeCmd);
};


void alcd_puts(char* _str)
{
    while (*_str != '\0')
    {
        alcd_putc(*_str++);
    };  
};


void alcd_putc(char _char)
{
    alcd_write(_char, __alcd_writeData);
    __alcd_x_position++;
    if(__alcd_x_position >=  __alcd_max_x)
    {
        __alcd_x_position = 0;
        __alcd_y_position++;
        alcd_gotoxy(__alcd_x_position, __alcd_y_position);
    };
};


void alcd_write(uint8_t _data, bool _alcd_cmdData)
{
	HAL_GPIO_WritePin(__alcd_RS_GPIO_Port, __alcd_RS_Pin, _alcd_cmdData);

	HAL_GPIO_WritePin(__alcd_DB4_GPIO_Port, __alcd_DB4_Pin, bitCheck(_data, 4));
	HAL_GPIO_WritePin(__alcd_DB5_GPIO_Port, __alcd_DB5_Pin, bitCheck(_data, 5));
	HAL_GPIO_WritePin(__alcd_DB6_GPIO_Port, __alcd_DB6_Pin, bitCheck(_data, 6));
	HAL_GPIO_WritePin(__alcd_DB7_GPIO_Port, __alcd_DB7_Pin, bitCheck(_data, 7));

	HAL_GPIO_WritePin(__alcd_EN_GPIO_Port, __alcd_EN_Pin, GPIO_PIN_SET);
	if(__alcd_initStatus == false)
	{
			__alcd_delay(__alcd_delay_modeSet);
	}
	else
	{
			__alcd_delay(__alcd_delay_CMD);
	}
	HAL_GPIO_WritePin(__alcd_EN_GPIO_Port, __alcd_EN_Pin, GPIO_PIN_RESET);
	


	HAL_GPIO_WritePin(__alcd_DB4_GPIO_Port, __alcd_DB4_Pin, bitCheck(_data, 0));
	HAL_GPIO_WritePin(__alcd_DB5_GPIO_Port, __alcd_DB5_Pin, bitCheck(_data, 1));
	HAL_GPIO_WritePin(__alcd_DB6_GPIO_Port, __alcd_DB6_Pin, bitCheck(_data, 2));
	HAL_GPIO_WritePin(__alcd_DB7_GPIO_Port, __alcd_DB7_Pin, bitCheck(_data, 3));

	HAL_GPIO_WritePin(__alcd_EN_GPIO_Port, __alcd_EN_Pin, GPIO_PIN_SET);
	if(__alcd_initStatus == false)
	{
			__alcd_delay(__alcd_delay_modeSet);
	}
	else
	{
			__alcd_delay(__alcd_delay_CMD);
	}
	HAL_GPIO_WritePin(__alcd_EN_GPIO_Port, __alcd_EN_Pin, GPIO_PIN_RESET);
	
  
};

void alcd_init(void)
{
    __alcd_initStatus = false;
    __alcd_delay(__alcd_delay_powerON);

		#ifdef __alcd_BL_GPIO_Port
			HAL_GPIO_WritePin(__alcd_BL_GPIO_Port, __alcd_BL_Pin, GPIO_PIN_SET);
    #endif

    alcd_write(__alcd_Mode_4bit_Step1, __alcd_writeCmd);
    __alcd_delay(__alcd_delay_modeSet);
    alcd_write(__alcd_Mode_4bit_Step2, __alcd_writeCmd);
    __alcd_delay(__alcd_delay_modeSet);  
    alcd_write(__alcd_Mode_4bit_2line_5x8, __alcd_writeCmd);
    __alcd_delay(__alcd_delay_modeSet);      
    alcd_write(__alcd_Display_ON, __alcd_writeCmd); 
    __alcd_delay(__alcd_delay_modeSet);    
    alcd_write(__alcd_Cursor_OFF, __alcd_writeCmd); 
    __alcd_delay(__alcd_delay_modeSet);    
    alcd_write(__alcd_Entry_Inc, __alcd_writeCmd);
    __alcd_delay(__alcd_delay_modeSet);    
    alcd_write(__alcd_Display_Clear, __alcd_writeCmd);
    __alcd_delay(__alcd_delay_modeSet);    
    __alcd_initStatus = true;
};