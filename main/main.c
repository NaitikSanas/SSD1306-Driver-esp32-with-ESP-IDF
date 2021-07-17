#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "ssd1306.h"
#include "fonts.h"

int i = 0;
void task ();
void app_main(){
    SSD1306_Init();
    printf("SSD1306 Initialized..\n");
    
    char str[16];
    SSD1306_GotoXY(0,16);
    sprintf(str,"hello world");
    SSD1306_Puts(str, &Font_7x10, 1);
    printf("printed text\n");
    SSD1306_UpdateScreen();
    vTaskDelay(1);
    SSD1306_GotoXY(10,10);
    
    xTaskCreate(&task, "oled_display", 2046, NULL, 5, NULL);
}

void task (){
    char str [16];
    while (1)
    {
        SSD1306_GotoXY(10,10);
        SSD1306_Clear();
        vTaskDelay(10);
        sprintf(str,"%d",i);
        SSD1306_Puts(str,&Font_11x18,1);
        i = i + 1;
        SSD1306_UpdateScreen();
    }  
}