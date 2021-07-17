# Introduction 
This Project Implements driver for SSD1306 OLED Display module. it is Improved Version of driver which is implementedfor STM32 which is then ported to ESP32. Link for original driver : https://controllerstech.com/oled-display-using-i2c-stm32/ <br>
I changed the I2C write function to make it work with the esp32. <br>
In Improvements, the original driver code was not giving higher frames per seconds which i resolved by modifiy few functions.

# Configuration 
In order to use this driver in your application you can specifiy parameters like I2C SDA-SCL Pins, Addres, Display resolution in `ssd1306.h` header file. 
```c
#define I2C_MASTER_SDA_IO 21
#define I2C_MASTER_SCL_IO 22
#define I2C_MASTER_FREQ_HZ 100000

#define SSD1306_I2C_ADDR         0x78

/* SSD1306 settings */
/* SSD1306 width in pixels */
#ifndef SSD1306_WIDTH
#define SSD1306_WIDTH            128
#endif
/* SSD1306 LCD height in pixels */
#ifndef SSD1306_HEIGHT
#define SSD1306_HEIGHT           64
#endif

```
