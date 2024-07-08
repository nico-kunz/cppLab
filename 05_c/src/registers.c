#include "registers.h"

#include <stdio.h>
#define BIT22_23 (0b11 << 22)
#define BIT16_21 (0b111111 << 16)
#define BIT24_29 (0b111111 << 24 )
#ifdef FAST_ADC
#define TQ60 (15 << 24)
#endif
#ifndef FAST_ADC
#define TQ60 (30 << 24)
#endif
#define BIT13_15 (0b111 << 13)
#define VREFSEL110 (0b110 << 13)

void setupADC(Register_t *reg) {
    // enable ADC6 and 7 (bits 22 and 23)
    *reg = *reg | BIT22_23;

    // disable ADC0 - 5 (bits 16 - 21)
    *reg = *reg & (~BIT16_21);

    // set Tq to 60 (val 30) (bits 24 - 29)
    // create mask to unset bits that we want to set to 59, (TQ60 | ~TQ60) should also work
    // clear bits that we want to set
    *reg = *reg & ~BIT24_29;

    // set cleared bits to 59
    *reg = *reg | TQ60;

    // set VREFSEL to Internal V_REFH and AV_SS (0b110)
    *reg = *reg & ~BIT13_15;
    *reg = *reg | VREFSEL110;
}

void setupADC_Struct(Register_t *reg) {
    struct ADCCON3_Register {
        uint32_t: 13;
        uint32_t VREFSEL: 3;
        uint32_t ADC: 8;
        uint32_t TQ: 6;
        uint32_t: 2;
    };

    struct ADCCON3_Register *ADC_reg = (struct ADCCON3_Register *) reg;
    ADC_reg->ADC = 0b11000000;
    ADC_reg->TQ = 30;
    ADC_reg->VREFSEL = 0b110;
}

void setupADC_CompileOption(Register_t *reg) {
    setupADC(reg);
}
