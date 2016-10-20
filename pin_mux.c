/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_common.h"
#include "fsl_port.h"

/*******************************************************************************
 * Code
 ******************************************************************************/

/* Function Name : BOARD_InitPins */
void BOARD_InitPins(void)
{
    /* Initialize LPSCI0 pins below */
    /* Ungate the port clock */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Affects PORTA_PCR1 register */
    PORT_SetPinMux(PORTA, 1u, kPORT_MuxAlt2);
    /* Affects PORTA_PCR2 register */
    PORT_SetPinMux(PORTA, 2u, kPORT_MuxAlt2);

	  /* Ungate the port clock */
    CLOCK_EnableClock(kCLOCK_PortE);

    PORT_SetPinMux(PORTE, 24U, kPORT_MuxAlt5);
    PORT_SetPinMux(PORTE, 25U, kPORT_MuxAlt5);
	
	  SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK; //This enables the clock to PORTC
    PORTC->PCR[3] = PORT_PCR_MUX(1u); //This sets the Mux control of PTC3 to 001, or GPIO
    PORTC->PCR[12] = PORT_PCR_MUX(1u); //This sets the Mux control of PTC12 to 001, or GPIO
		PORTC ->PCR[0] = 0x01;
		PORTC ->PCR[1] |= 0x01;
		PTC->PDDR &= ~(1u<<3);
		PTC->PDDR &= ~(1u<<12);
	
}

void BOARD_I2C_ConfigurePins(void)
{
    port_pin_config_t pinConfig = {0};
    pinConfig.pullSelect = kPORT_PullUp;
    pinConfig.slewRate = kPORT_FastSlewRate;
    pinConfig.passiveFilterEnable = kPORT_PassiveFilterDisable;
    pinConfig.driveStrength = kPORT_LowDriveStrength;
    pinConfig.mux = kPORT_MuxAlt5;
    CLOCK_EnableClock(kCLOCK_PortE);

    PORT_SetPinConfig(PORTE, 25U, &pinConfig);
    PORT_SetPinConfig(PORTE, 24U, &pinConfig);
}
