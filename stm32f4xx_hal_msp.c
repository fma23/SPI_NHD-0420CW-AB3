/**
  ******************************************************************************
  * File Name          : stm32f4xx_hal_msp.c
  * Description        : This file provides code for the MSP Initialization 
  *                      and de-Initialization codes.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "I2C.h"
#include "SPI.h"

/**
  * @brief SPI MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration  
  * @param hspi: SPI handle pointer
  * @retval None
  */
void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  

					/* Enable SPI clock */
					SPI2_CLK_ENABLE(); 
					
					__GPIOI_CLK_ENABLE();
					SPI2_RS_CLK_ENABLE();            //__GPIOA_CLK_ENABLE()
		
				 /* SPI2 SCK GPIO pin configuration  */
					GPIO_InitStruct.Pin       = SPI2_SCK_PIN;
					GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
					GPIO_InitStruct.Pull      = GPIO_PULLUP;
					GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;
					GPIO_InitStruct.Alternate = SPI2_SCK_AF;
					
					HAL_GPIO_Init(SPI2_SCK_GPIO_PORT, &GPIO_InitStruct);
						
					/* SPI2 MISO GPIO pin configuration  */
					GPIO_InitStruct.Pin = SPI2_MISO_PIN;
					GPIO_InitStruct.Alternate = SPI2_MISO_AF;
					HAL_GPIO_Init(SPI2_MISO_GPIO_PORT, &GPIO_InitStruct);
					
					/* SPI2 MOSI GPIO pin configuration  */
					GPIO_InitStruct.Pin = SPI2_MOSI_PIN;
					GPIO_InitStruct.Alternate = SPI2_MOSI_AF;
					HAL_GPIO_Init(SPI2_MOSI_GPIO_PORT, &GPIO_InitStruct);
					
					
					/* SPI2 CHIP Select GPIO pin configuration  */
					GPIO_InitStruct.Pin       = GPIO_PIN_5;
					GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
					GPIO_InitStruct.Pull      = GPIO_PULLUP;
					GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;

					HAL_GPIO_Init(SPI2_SCK_GPIO_PORT, &GPIO_InitStruct);

					/* RESET GPIO pin configuration  */
					GPIO_InitStruct.Pin       = GPIO_PIN_9;
					GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
					GPIO_InitStruct.Pull      = GPIO_PULLUP;
					GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;
					
					HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
