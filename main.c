#include <16f877a.h>
#FUSES XT,NOWDT,NOPROTECT,PUT,NOBROWNOUT,NOLVP     
#use delay(clock=4000000)
                          
#include <lcd.c>



#define trig pin_B1
#define echo pin_B0
#USE standard_io(b)
int16 distancia, tiempo;
void main()
{
   lcd_init();                             
printf(LCD_PUTC, "\f Iniciando.");
delay_ms(500);
printf(LCD_PUTC, "\f Iniciando..");
delay_ms(500);
printf(LCD_PUTC, "\f Iniciando...");
delay_ms(500);
                            
setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);

while(1)
{
output_high(trig);                   
delay_us(20);                       
output_low(trig);
while(!input(echo))                     
{}
set_timer1(0);                         
while(input(echo))                     
{}
tiempo=get_timer1();
distancia=(tiempo*10)/(58.0);
printf(LCD_PUTC, "\fTiempo :%Lu \nDistancia = %Lu",tiempo,distancia);
delay_ms(500);
}
}
