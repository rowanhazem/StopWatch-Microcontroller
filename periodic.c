#include "periodic.h"
void init_PeriodicTimer0(){
  SYSCTL_RCGCTIMER_R |= 0x01;
        TIMER0_CTL_R = 0x0;
        TIMER0_CFG_R |= 0x4;
        TIMER0_TAMR_R |= 0x12;
        TIMER0_TAILR_R = 244;
}