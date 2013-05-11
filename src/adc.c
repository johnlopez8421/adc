#include <avr/io.h>
#include "adc.h"
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

void ad_setprescale(uint8_t prescale)
{
	uint8_t reg;
	reg = ADCSRA;
	reg &= ~AD_PRESCLMASK;
	reg |= prescale;
	ADCSRA = reg;
}

void ad_refsel(uint8_t reference)
{
	uint8_t reg;
	reg = ADMUX;
	reg &= ~AD_REFMASK;
	reg |= reference;
	ADMUX = reg;
}

void ad_chansel(uint8_t channel)
{
	uint8_t reg;
	reg = ADMUX;
	reg &= ~AD_CHMASK;
	reg |= channel;
	ADMUX = reg;
}

void ad_enable(void)
{
	uint8_t reg;
	reg = ADCSRA;
	reg |= AD_EN;
	ADCSRA = reg;
}

void ad_start(void)
{
	uint8_t reg; 
	reg = ADCSRA;
	reg |= AD_STRT;
	ADCSRA = reg;
}

uint8_t ad_isrunning(void)
{
	return (ADCSRA & AD_STRT);
}

uint16_t ad_rd(uint8_t channel)
{
	uint16_t resultl, resulth = 0;
	ad_chansel(channel);
	ad_start();
	while(ad_isrunning()){};
	resultl = ADCL;
	resulth = ADCH;
	resulth <<= 8;
	return (resultl | resulth);
}