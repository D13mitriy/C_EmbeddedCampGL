/*
 * blink_once.h
 *
 *  Created on: Apr 16, 2023
 *      Author: ubuntu
 */

#ifndef INC_BLINK_ONCE_H_
#define INC_BLINK_ONCE_H_

typedef enum
{
	green  = 12,
	orange = 13,
	red    = 14,
	blue   = 15

} color;

void blink_pin(color pin, uint32_t delay_time)
{
	switch(pin) {
			case(green):
		                 //HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
			             //HAL_Delay(delay_time);
			             //HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
			             HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
			             HAL_Delay(delay_time);
			break;

			case(orange):
						 //HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
					     //HAL_Delay(delay_time);
					     //HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
			             HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
			             HAL_Delay(delay_time);
			break;

			case(red):
						 //HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
						 //HAL_Delay(delay_time);
					     //HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		                 HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
		                 HAL_Delay(delay_time);
			break;

			case(blue):
		                 //HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
			             //HAL_Delay(delay_time);
					     //HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
				   	     HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
					     HAL_Delay(delay_time);
			break;
	}



}

void blink_X(uint16_t start_pin, uint16_t pin_number)
{
	  color pin = start_pin;
	  uint16_t end_pin = start_pin + pin_number;
	  for(uint16_t idx = pin; idx < end_pin; ++idx)
	  {

		  uint32_t time_d = 200;
		  blink_pin( idx, time_d);

	  }
}


#endif /* INC_BLINK_ONCE_H_ */
