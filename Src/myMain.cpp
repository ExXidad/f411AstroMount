//
// Created by Ivan Kalesnikau on 28.12.2022.
//
#include "../Inc/myMain.hpp"

[[noreturn]] int myMain()
{
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);

    Timer altTimer(&htim1, TIM_CHANNEL_1);
    altTimer.startPWM();
    altTimer.writePWMDuty(1);

    GPIO_PinState a = GPIO_PIN_SET;
    GPIO_PinState b = GPIO_PIN_RESET;

    HAL_GPIO_WritePin(altA_GPIO_Port,altA_Pin,a);
    HAL_GPIO_WritePin(altB_GPIO_Port,altB_Pin,b);

    Timer azTimer(&htim1, TIM_CHANNEL_2);
    azTimer.startPWM();
    azTimer.writePWMDuty(1);

    HAL_GPIO_WritePin(azA_GPIO_Port,azA_Pin,a);
    HAL_GPIO_WritePin(azB_GPIO_Port,azB_Pin,b);

    while (1)
    {
        HAL_Delay(1000);
        HAL_GPIO_TogglePin(altA_GPIO_Port,altA_Pin);
        HAL_GPIO_TogglePin(altB_GPIO_Port,altB_Pin);
        HAL_GPIO_TogglePin(azA_GPIO_Port,azA_Pin);
        HAL_GPIO_TogglePin(azB_GPIO_Port,azB_Pin);
    }
}
