
#ifndef __adc_h
#define __adc_h

 /* Copyright (c) 2012, John Lopez
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */
  
/*** A/D converter libary for ATMega328P and compatible microcontrollers ***/

/* ADMUX */
#define AD_REFAREF	( (0<<REFS1) | (0<<REFS0) )
#define AD_REFAVCC	( (0<<REFS1) | (1<<REFS0) )
#define AD_REF1V1	( (1<<REFS1) | (1<<REFS0) )
#define AD_REFMASK	( (1<<REFS1) | (1<<REFS0) )

#define AD_LEFTADJ	(1<<ADLAR)
#define AD_CH0		0x0
#define AD_CH1		0x1
#define AD_CH2		0x2
#define AD_CH3		0x3
#define AD_CH4		0x4	/* shared with TWI */
#define AD_CH5		0x5	/* shared with TWI */
#define AD_CH6		0x6
#define AD_CH7		0x7
#define AD_CHTEMP	0x8
#define AD_CH1V1	0xE
#define AD_CHGND	0xF
#define AD_CHMASK	0xF

/* ADCSRA */
#define AD_EN			(1<<ADEN)
#define AD_STRT			(1<<ADSC)
#define AD_INT			(1<<ADIF)
#define AD_PRESCL2		0x0
#define AD_PRESCL4		0x2
#define AD_PRESCL8		0x3
#define AD_PRESCL16		0x4
#define AD_PRESCL32		0x5
#define AD_PRESCL64		0x6
#define AD_PRESCL128	0x7
#define AD_PRESCLMASK	0x7

uint16_t ad_rd(uint8_t channel);
uint16_t ad_temprd(void);	/* temp sensor read */

void ad_refsel(uint8_t reference);
void ad_chansel(uint8_t channel);
void ad_setprescale(uint8_t prescale);
void ad_enable(void);
void ad_disable(void);
void ad_start(void);
uint8_t ad_isrunning(void);
void ad_stop(void);
void ad_tempsel(void);	/* temp sensor - must select 1V1 reference */

#endif /* __adc_h */