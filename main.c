#include <16f887.h>
#fuses nowdt,hs,noput,noprotect,nodebug,nobrownout,nolvp,nocpd,nowrt
#use delay(clock=20000000)
   
#bit toi=0x06.4
#bit lui=0x06.5
#bit tr=0x06.3
#bit ph=0x6.2
#bit nn=0x6.0
#bit nc=0x6.1
INT8 trai,phai;
int1 i;
void setbamxung()
{
   setup_timer_2 (t2_div_by_4, 124, 1) ;
   setup_ccp1 (ccp_pwm);
   setup_ccp2 (ccp_pwm);
   set_pwm2_duty (0);
   set_pwm1_duty (0);
}

void setdc(INT8 trai,phai)
{
   output_low (pin_c0);
   output_low (pin_c3);
   set_pwm2_duty (trai);
   set_pwm1_duty (phai);
}

/////////////////////////////////////////////////////////////
void setdcng(INT8 trai,phai)
{
   output_high (pin_c0);
   output_high (pin_c3);
   set_pwm2_duty (trai);
   set_pwm1_duty (phai);
}


void chaynhanh()
{
while(i==0)
{
      while(nc==0)
      {
      i=1;
      }
       setdc(0,0);
       ///////////////toi/////////////////////////
       WHILE (toi == 0)
       {
          setdc (100, 100) ;
       }

       ///////////////////////lui///////////////////
       WHILE (lui == 0)
       {
          setdcng (100, 100) ;
       }

       ///////////////trai///////////////////
       WHILE (tr == 0)
       {
          output_high (pin_c0) ;
          set_pwm2_duty (50);
          set_pwm1_duty (50);
       }

       /////////////////////phai/////////////////////////
       WHILE (ph == 0)
       {
          output_high (pin_c3) ;
          set_pwm2_duty (50);
          set_pwm1_duty (50);
       }
    }
}
void chaycham()
{
while(i==1)
{        
      while(nn==0)
      {
      i=0;
      }
       setdc(0,0);
       ///////////////toi/////////////////////////
       WHILE (toi == 0)
       {
          setdc (30, 30) ;
       }

       ///////////////////////lui///////////////////
       WHILE (lui == 0)
       {
          setdcng (30, 30) ;
       }

       ///////////////trai///////////////////
       WHILE (tr == 0)
       {
          output_high (pin_c0) ;
          set_pwm2_duty (50);
          set_pwm1_duty (50);
       }

       /////////////////////phai/////////////////////////
       WHILE (ph == 0)
       {
          output_high (pin_c3) ;
          set_pwm2_duty (50);
          set_pwm1_duty (50);
       }
    }
}   

//////////////////////////////
 VOID main ()
 {
    setbamxung ();
   while(true)
   {
    i=1;
    delay_ms(200);
     chaycham();
     delay_ms(200);
     chaynhanh();
    delay_ms(200);
 }
 }

