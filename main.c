/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: hp
 */
/*  lib layer */
#include "STD_TYPES.h"
#include  "BIT_MATH.h"
#define   F_CPU 8000000UL
#include  <util/delay.h>



/*  mcal layer */

#include   "DIO_INT.h"

/* hal */
#include "KP_INT.h"
#include "LCD_INT.h"

s32 sum(s16 num1 , s16 num2);
s32 sub(s16 num1 , s16 num2);
s32 multip(s16 num1 , s16 num2);
f64 div(s16 num1 , s16 num2);
double calculate_root(double number);
s32 modules (s16 num1 , s16 num2);
int main(){
	u8 pinvalue;
	DIO_voidInit();
	LCD_INIT();
u8 sign ;
s16 num_1=0 ;
s16 num_2=0 ;
u8 sign_1;
u8 sign_2;
s16 ans ;
u8 flage =0 ;
f64 ans_float;
f32 decimal ;
u8 flage2 =0;
u8 clear =0 ;
u8 minus =0;
u8 minus2=0;
u8 f1 =0;
u8 contin_ans =0 ;
u8 minus_2 =0 ;


while(1){

/*  NUMBER 1*/

while(1){

//	 if( pinvalue=='a'){
//			num_1= ans ;
//	        LCD_WRITE_COMMAND(lcd_Clear);
//			LCD_WRITE_STRING("ANS");
//			 do{
//				KPD_u8KpdGetKeyState(&pinvalue);
//	         }while(pinvalue == Kpd_keynotpressed);
//			 sign_2 = pinvalue;
//			 LCD_WRITE_Char(pinvalue);
//			break ;
//	}
 do{
	 if(contin_ans==1){
		 break;
	 }
	KPD_u8KpdGetKeyState(&pinvalue);

	}while(pinvalue == Kpd_keynotpressed);
	 sign_1 = pinvalue -'0';
     sign_2 = pinvalue;
       flage =0;
		 if(sign_1 >=0 && sign_1<=9 ){
			 if(contin_ans==1){
				continue ;}
			LCD_WRITE_Char(pinvalue);
			num_1 = (num_1*10) + (pinvalue -'0');
			f1=1 ;
  }

	else if( (pinvalue=='-' || pinvalue=='_') && f1 ==0){
			LCD_WRITE_Char('-');
				 minus2=1 ;

			}
	else if( pinvalue== '='){

		LCD_WRITE_Char('=');
		if(minus2==1){
		Lcd_voidDisplayNumber(-num_1);}
		else
		{
			Lcd_voidDisplayNumber(num_1);
		}
		break ;}
	else if( pinvalue=='s'){
		if(minus2==1){
		 num_1*=-1 ;
		}
		sign_2 = pinvalue;
		LCD_WRITE_Char('^');
		break ;
	}
	else if( pinvalue=='a'){
		    num_1= ans ;
		    LCD_WRITE_COMMAND(lcd_Clear);
		    LCD_WRITE_STRING("ANS");
		    contin_ans=0;
		     do{
	      	KPD_u8KpdGetKeyState(&pinvalue);
	       }while(pinvalue == Kpd_keynotpressed);
	       sign_2 = pinvalue;
	       LCD_WRITE_Char(pinvalue);
		 						break ;

		 	}
	else if(pinvalue == 'c'){
		clear=1;
		  LCD_WRITE_COMMAND(lcd_Clear);
		break ;
		}

	else{
		if(minus2==1){
			num_1*=-1 ;
				}
		sign_2 = pinvalue;
		LCD_WRITE_Char(pinvalue);
		break ;
	}
}



if(clear ==1){
	num_1=0 ;
	num_2=0 ;
	flage2 =0;
	clear =0 ;
	minus =0;
	minus2=0;
	f1 =0;
	continue;
}

/*  NUMBER 2 */

while(1){

 do{
		KPD_u8KpdGetKeyState(&pinvalue);
	}while(pinvalue == Kpd_keynotpressed);
	 sign_1 = pinvalue -'0';
	 flage =0;
	if(sign_1 >=0 && sign_1<=9  ){
			LCD_WRITE_Char(pinvalue);
			num_2 = (num_2*10) + (pinvalue -'0');

  }
	else if( (pinvalue=='-' || pinvalue=='_')){
		LCD_WRITE_Char('-');
		minus=1;
	}
	else  if( pinvalue=='=') {
		if(minus==1){
		  num_2*=-1 ;
				}
		LCD_WRITE_Char('=');
		break ;}
	else if(pinvalue == 'c'){
	clear=1;
	  LCD_WRITE_COMMAND(lcd_Clear);
	break ;
	}
	else{

		break ;
	}
}

if(clear ==1){
	num_1=0 ;
	num_2=0 ;

	flage2 =0;
	clear =0 ;
	minus =0;
	minus2=0;
	f1 =0;
	continue;
}

if(minus==1 &&  minus2==1){
	minus_2=1;
}

/*  OPERATION */
switch(sign_2){

 case '+':
	 if(flage ==0 ){
	 ans= sum(num_1 ,num_2);
	 Lcd_voidDisplayNumber(ans);
	 flage =1 ;
	 num_1=0;
	 num_2=0 ;
  }
  do{
	  KPD_u8KpdGetKeyState(&pinvalue);
	  sign = pinvalue;
	 }while(pinvalue == Kpd_keynotpressed);
		  break ;

 case '_':
	 if(flage ==0 ){
		 if(minus==1){
			 num_2 *=-1;
		 }
	 ans= sub(num_1 ,num_2);
	 Lcd_voidDisplayNumber(ans);
	flage =1 ;
	 num_1=0;
	 num_2=0 ;
		  }

  do{
	   KPD_u8KpdGetKeyState(&pinvalue);
	 	sign = pinvalue;
}while(pinvalue == Kpd_keynotpressed);
	 		 break ;

 case 'x':
	  if(flage ==0 ){
	  ans= multip(num_1 ,num_2);
	  Lcd_voidDisplayNumber(ans);
	 flage =1 ;
	  num_1=0;
 	 num_2=0 ;
  }

  do{
 KPD_u8KpdGetKeyState(&pinvalue);
 sign = pinvalue;
 		}while(pinvalue == Kpd_keynotpressed);
  break ;

 case '/':
  if(flage ==0 ){
  ans_float= div(num_1 ,num_2);
  ans=(s32) div(num_1 ,num_2);
  f64 deci = ans_float-ans;
 if(num_2 ==0 ){
 LCD_WRITE_COMMAND(lcd_Clear);
 LCD_WRITE_STRING("Error:Division");

 LCD_GO_TO(line2,0);
  LCD_WRITE_STRING("by 0 is undefined");
	 			}
 else if(deci ==0  ){
    Lcd_voidDisplayNumber(ans);
    flage =1 ;
    num_1=0;
     num_2=0 ;
     deci=0;
     ans_float=0;}
 else{
if((minus==1 || minus2==1)&& minus_2==0){
 Lcd_voidDisplayNumber(ans);
   if(ans==0){
    LCD_WRITE_STRING("-0");
    LCD_WRITE_Char('.');
    Lcd_voidDisplayNumber((ans_float-ans)*-100.0);}
     else{
    	   LCD_WRITE_Char('.');
    	 Lcd_voidDisplayNumber((ans_float-ans)*-100.0);
     }
     flage =1 ;
     num_1=0;
     num_2=0 ;
     deci=0;
     ans_float=0;}
else if( minus ==1 && minus2==1  && minus_2==1){
	 Lcd_voidDisplayNumber(-ans);
	   if(ans==0){
	    LCD_WRITE_STRING("-0");
	    LCD_WRITE_Char('.');
	    Lcd_voidDisplayNumber((ans_float-ans)*100.0);}
	     else{
	    	   LCD_WRITE_Char('.');
	    	 Lcd_voidDisplayNumber((ans_float-ans)*100.0);
	     }
	     flage =1 ;
	     num_1=0;
	     num_2=0 ;
	     deci=0;
	     ans_float=0;
	     minus_2=0;
}
else{
	Lcd_voidDisplayNumber(ans);
 LCD_WRITE_Char('.');
 Lcd_voidDisplayNumber((ans_float-ans)*100.0);
 flage =1 ;
 num_1=0;
 num_2=0 ;
 deci=0;
 ans_float=0;}

 	}

   }

  do{
    KPD_u8KpdGetKeyState(&pinvalue);
    sign = pinvalue;
  	}while(pinvalue == Kpd_keynotpressed);
 break ;

 case 's':

  if(flage ==0 ){
  ans_float=calculate_root((f64)num_2);
  ans=(s32) calculate_root((f64)num_2 );
  f64 deci = ans_float-ans;
 if(num_2<0 ){
 LCD_WRITE_COMMAND(lcd_Clear);
 LCD_WRITE_STRING("Error:negative ");

 LCD_GO_TO(line2,0);
  LCD_WRITE_STRING("square is undefined");
	 			}
 else if(deci ==0  ){
    Lcd_voidDisplayNumber(ans);
    flage =1 ;
    num_1=0;}
 else{

 	Lcd_voidDisplayNumber(ans);
     LCD_WRITE_Char('.');
     Lcd_voidDisplayNumber((ans_float-ans)*100.0);
     flage =1 ;
     num_1=0;
 	}

   }

  do{
    KPD_u8KpdGetKeyState(&pinvalue);
    sign = pinvalue;
  	}while(pinvalue == Kpd_keynotpressed);
 break ;


 case '%':
	  if(flage ==0 ){
	 ans= modules(num_1 ,num_2);
	 Lcd_voidDisplayNumber(ans);
	 flage =1 ;
	 num_1=0;
	 num_2=0 ;
  }
  do{
	  KPD_u8KpdGetKeyState(&pinvalue);
	  sign = pinvalue;
	 }while(pinvalue == Kpd_keynotpressed);
		  break ;

}





if(sign == 'c'){
  LCD_WRITE_COMMAND(lcd_Clear);
  ans=0 ;
  num_1=0 ;
  num_2=0 ;
  flage =0 ;
 flage2 =0;
	clear =0 ;
	minus =0;
	minus2=0;
	f1 =0;
  }

 else{
 switch (sign){
	  case 'd':
	    flage2 =0;
	    clear =0 ;
	    minus =0;
	    minus2=0;
	    f1 =0;
	    LCD_WRITE_COMMAND(lcd_Clear);
	       num_2=0 ;
	        LCD_WRITE_STRING("ANS -");
	        while(1){
	       do{
	  		KPD_u8KpdGetKeyState(&pinvalue);
	  	   }while(pinvalue == Kpd_keynotpressed);
	  	   sign_1 = pinvalue -'0';
	  	   if(sign_1 >=0 && sign_1<=9  ){
	  			LCD_WRITE_Char(pinvalue);
		  		num_2 = (num_2*10) + (pinvalue -'0');

		    }
		  	else  if( pinvalue == '=') {
		  		LCD_WRITE_Char('=');
		  		 ans=ans - num_2;

		  		break ;}
		  } Lcd_voidDisplayNumber(ans);
		  do{
		 	 KPD_u8KpdGetKeyState(&pinvalue);
		 	 sign = pinvalue;
		 		 			}while(pinvalue == Kpd_keynotpressed);
	 break ;

		 case 'i':
			  flage2 =0;
			   		clear =0 ;
			   		minus =0;
			   		minus2=0;
			   		f1 =0;
			  LCD_WRITE_COMMAND(lcd_Clear);
			  num_2=0 ;
			  LCD_WRITE_STRING("ANS +");
			  while(1){
			   do{
			  		KPD_u8KpdGetKeyState(&pinvalue);
			  	}while(pinvalue == Kpd_keynotpressed);
				  sign_1 = pinvalue -'0';
				  if(sign_1 >=0 && sign_1<=9  ){
				  LCD_WRITE_Char(pinvalue);
				  num_2 = (num_2*10) + (pinvalue -'0');

				    }
				  else  if( pinvalue=='=') {
				    LCD_WRITE_Char('=');
				     ans= ans+num_2;

				  		break ;}
				  }
				  Lcd_voidDisplayNumber(ans);
				  do{
				 	    KPD_u8KpdGetKeyState(&pinvalue);
				 	    sign = pinvalue;
				 		 }while(pinvalue == Kpd_keynotpressed);
			 break ;

		 case 'a':
			 contin_ans=1;
			 LCD_WRITE_COMMAND(lcd_Clear);
			  num_2=0 ;
			  num_1=0 ;
			  flage =0 ;
			  flage2 =0;
			 clear =0 ;
			minus =0;
			minus2=0;
			f1 =0;
			 num_1=ans ;
			 sign =pinvalue;
		break ;



		 }

	 }


     if(sign == 'c'){

   		 LCD_WRITE_COMMAND(lcd_Clear);
   		 ans=0 ;
   		 num_1=0 ;
   		 num_2=0 ;
   		 flage =0 ;
         flage2 =0;
   		clear =0 ;
   		minus =0;
   		minus2=0;
   		f1 =0;
   	 }

}

 }


s32 sum(s16 num1 , s16 num2){

	s32 sumation = num1 + num2 ;
	return sumation ;
}

s32 sub(s16 num1 , s16 num2){

	s32 subtraction = num1 - num2 ;
	return subtraction ;
}

s32 multip(s16 num1 , s16 num2){

	s32 multiplay = num1 * num2 ;
	return multiplay ;
}

f64 div(s16 num1 , s16 num2){

	f64 division = (f64)num1 / num2 ;

	return division ;
}

double calculate_root(double number) {
 float x ;
 int i ;
 x =number ;
 for (i = 0; i < 10; ++i) {
	x=(x+(number/x))/2;
}

return x;
}
s32 modules (s16 num1 , s16 num2){
	s32 module ;
	s32 div ;
	if(num2>num1){
		module = num1;
	}
	else{
		div=(s32)(num1/num2);
       module = num1 - div*num2;
	}

	return module ;
}
