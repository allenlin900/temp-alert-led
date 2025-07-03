
//******************************************************************************
//  MSP430G2xx3 Demo - Software Toggle P1.0
//
//  Description; Toggle P1.0 by xor'ing P1.0 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430G2xx3
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  E. Chen
//  Texas Instruments, Inc
//  May 2018
//  Built with CCS Version 8.0 and IAR Embedded Workbench Version: 7.11
//******************************************************************************

#include <msp430g2553.h>



void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;        
  BCSCTL1 = CALBC1_1MHZ;           
  DCOCTL = CALDCO_1MHZ;
  P1DIR |= BIT0;                    
  P1OUT &= ~BIT0;                   

  ADC10CTL1 = INCH_10;             // 選擇溫度感測器 
  ADC10CTL0 = SREF_1 + ADC10SHT_3 + REFON + ADC10ON;
  __delay_cycles(1000);            //讓ADC參考電壓穩定 

  ADC10CTL0 |= ENC + ADC10SC;      // 開始做轉換 
  while (ADC10CTL1 & ADC10BUSY);
  int begin_TEMP = ADC10MEM;

  while (1)
  {
    ADC10CTL0 |= ENC + ADC10SC;
    while (ADC10CTL1 & ADC10BUSY);
    int current_TEMP = ADC10MEM;

    if (current_TEMP > begin_TEMP)
    {
      P1OUT ^= LED;
      __delay_cycles(500000);      // 0.5秒 
    }
    else
    {
      P1OUT &= ~LED;
    }
    __delay_cycles(500000);        //0.5秒 ask一次 
  }
}
