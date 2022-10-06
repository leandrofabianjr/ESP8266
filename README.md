# ESP8266

## Ambiente

Utilizado [PlatformIO](https://platformio.org/) com [VSCode](https://code.visualstudio.com/).

Configurando:

1. Fazer uma cópia do arquivo `example.sensitive_data.ini` renomeando-a para `sensitive_data.ini` e preencher os dados necessários.

## OLED

Fonte: https://www.electronicshub.org/nodemcu-esp8266-oled-display/

### Conexões

|  OLED Display  | ESP8266 NodeMCU |
|:--------------:|:---------------:|
|       GND      |       GND       |
|       VCC      |       3.3V      |
| D0 (SCK / CLK) |   GPIO 14 (D5)  |
|   D1 (MOSI)    |   GPIO 13 (D7)  |
|       RES      |   GPIO 4 (D2)   |
|       DC       |   GPIO 5 (D1)   |
|       CS       |   GPIO 15 (D8)  |
