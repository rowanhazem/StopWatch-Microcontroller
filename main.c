#include "POPRTF.h"
#include "lcd.h"
#include "delay.h"
#include <string.h>
#include "periodic.h"

double i;
int countt=0;
int countred=0;
int flag;
int numdigit=0;
int main()
{
 PortB_Init();
 PortE_Init();
 PortF_Init();
 portA_init();
 LCD_Init ();
 systick_init();
 init_PeriodicTimer0();
 //GPIO_PORTE_DATA_R &=~( r1| r2 | r3 | r4 );
//int check;
 unsigned char arr[4];
 unsigned char arr2[4];
 unsigned char dot[]={'.'};
 unsigned char arar[4];
char temp[16];
int w; 
double num=1.00;
double x=1;

  while(1)
  {
    if(!(GPIO_PORTF_DATA_R & sw1) )
    { 
        TIMER0_CTL_R |= 0x1;
        sprintf(arar,"%f",num);
        LCD_Clear();
        LCD_String(arar);
      
        while((GPIO_PORTF_DATA_R & sw2))
        {
              while ((TIMER0_RIS_R & 0x1) == 0);
              TIMER0_ICR_R = 0x1;
              countt++;
              if (countt == 65536)
              {
                    //i=strtod(arr,NULL);
                    num=num+1;
                   sprintf(arr,"%f",num);
                   LCD_Clear();
                   LCD_String_xy(0,0,arr);
                   countt=0;
              }
        }
         x = countt*0.0000152587890625;
         sprintf(arr,"%f",num);
            LCD_Clear();
            int res=(int)num;
            while(res!=0)
            {
              numdigit++;
              res=res/10;
            }
         LCD_String_xy(0,0,arr);
          LCD_String_xy(0,(numdigit+1),dot);
         sprintf(arr2,"%f",x);
         LCD_String_xy(0,(numdigit+2),arr2); 
          NVIC_ST_CTRL_R &=(~(1<<0));
                      NVIC_ST_RELOAD_R = 0XFFFFFF;
                      NVIC_ST_CTRL_R =5;
                      int countred=0;
                     GPIO_PORTF_DIR_R |=( C2 | C3| C4);
                  
                      GPIO_PORTF_DATA_R &=~( C2 | C3| C4) ;
                     
                      while(countred<3)
                      {
                       GPIO_PORTF_DATA_R |=(C2);
                         while(((NVIC_ST_CTRL_R & 0x10000)==0));
                          GPIO_PORTF_DATA_R &=~(C2);
                          while(((NVIC_ST_CTRL_R & 0x10000)==0));
                       countred++;
                      }
                        GPIO_PORTF_PUR_R |= (C2 | C3| C4);
                      GPIO_PORTF_DIR_R &=~( C2 | C3| C4); 
                      
  }
  return 0;
}
}
/* else
        LCD_String_xy(0,0,arr);
        LCD_Clear();
        while(GPIO_PORTF_DATA_R & sw2){
          
        while(((NVIC_ST_CTRL_R & 0x10000)==0)){
          if(!(GPIO_PORTF_DATA_R & sw2))
          {
            flag=1;
                break;
          }
        }
        if(flag==1)
        {
          countt=0;
          LCD_Clear();
          break;
        }
         
            LCD_String_xy(0,0,arr);
              i =strtod(arr,NULL);
              i=i-(0.01);
             sprintf(temp,"%f",i);
               for(int t=0;t<=countt;t++)
               {
                   arr[t]=temp[t];
                   if(arr[t-2]=='.'&&t>2)
                   {
                 
                     break;
                   }
               } 
                if(i<=0.0)
                 {
                     LCD_Clear();
                    LCD_String("endofcountdown");
                    delay_ms();
                    NVIC_ST_CTRL_R &=(~(1<<0));
                      NVIC_ST_RELOAD_R = 0XFFFFFF;
                      NVIC_ST_CTRL_R =5;
                      int countred=0;
                     GPIO_PORTF_DIR_R |=( C2 | C3| C4);
                  
                      GPIO_PORTF_DATA_R &=~( C2 | C3| C4) ;
                     
                      while(countred<3)
                      {
                       GPIO_PORTF_DATA_R |=(C2);
                         while(((NVIC_ST_CTRL_R & 0x10000)==0));
                          GPIO_PORTF_DATA_R &=~(C2);
                          while(((NVIC_ST_CTRL_R & 0x10000)==0));
                       countred++;
                      }
                        GPIO_PORTF_PUR_R |= (C2 | C3| C4);
                      GPIO_PORTF_DIR_R &=~( C2 | C3| C4); 
                      
                    
                     LCD_Clear();
                    countt=0;
                   break;
                 }
               if(!(GPIO_PORTF_DATA_R & sw2))
               {
                 countt=0;
                   LCD_Clear();
                  break;
               }
      }
        
    }}*/
