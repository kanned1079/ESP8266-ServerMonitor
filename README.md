# ESP8266-ServerMonitor
A small linux server monitor on ESP8266

本项目使用一块ESP8266开发板和SSD1306-OLED显示屏  

可以横向显示，也可以竖向显示  
横向显示的Shell脚本请用 `send-horizontal.sh`  
竖向显示的Shell脚本请用 `send-vertical.sh`  

macOS ch340驱动 CH34xVCPDriver.pkg  
第三方库 ssd1306syp.zip 需要下载安装  

OLED  
SCL -> D1  
SDA -> D2  

继电器  
SIN -> D3  

![image_20220711132757](https://user-images.githubusercontent.com/58361983/178203704-753173c9-e4dd-4cc7-85fe-2e479d67a361.jpg)
![image_20220711192709](https://user-images.githubusercontent.com/58361983/178254977-14d40c7f-8f0c-4a72-949d-c3d4737c61ce.jpg)
