#ifndef KP_CONFIG_H
#define KP_CONFIG_H

#define KPD_ROWS_PORT  PORTA
#define KPD_CLS_PORT  PORTB
/*
select DATA port :
PORTA
PORTB
PORTC
PORTD
 
*/

#define KPD_CL1_PIN   PIN_0
#define KPD_CL2_PIN   PIN_1
#define KPD_CL3_PIN   PIN_2
#define KPD_CL4_PIN   PIN_3
#define KPD_CL5_PIN   PIN_4
#define KPD_CL6_PIN   PIN_5

/*SELECT
 *PIN_0
 * OR
 * PIN1
 * OR
 * PIN_2
 * OR
 * PIN_3
 * OR
 * PIN_4
 * OR
 * PIN_5
 * OR
 * PIN_6
 * OR
 * PIN_7
 *
 */


#define KPD_RL1_PIN   PIN_0
#define KPD_RL2_PIN   PIN_1 
#define KPD_RL3_PIN   PIN_2
#define KPD_RL4_PIN   PIN_3

/*SELECT
 *PIN_0
 * OR
 * PIN1
 * OR
 * PIN_2
 * OR
 * PIN_3
 * OR
 * PIN_4
 * OR
 * PIN_5
 * OR
 * PIN_6
 * OR
 * PIN_7
 *
 */

#define  KPD_Keys   { {'c','7','8','9','x','/'}, \
	                  {'-','4','5','6','_','a'},  \
                      {'%','1','2','3','+','d'},  \
					  {'s','0','.','=','+','i'}}



#endif 
