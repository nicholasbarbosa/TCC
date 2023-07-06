# TCC
Vídeo funcionamento do sistema:
https://github.com/nicholasbarbosa/TCC/assets/54655396/4edb9e73-59c4-49a6-a068-9d4901753508


## Descrição
Utilização do ESP32-CAM em conjunto com técnicas de processamento de imagens para a detecção e reconhecimento de rostos, com o propósito de automatizar a lista de chamadas em um ambiente escolar ou empresarial. A automatização da lista de chamada pode ser uma solução eficiente para evitar a perda de tempo e minimizar possíveis erros em processos manuais, além de evitar possíveis fraudes.


## Instalação
### Arduino IDE
- 1º: Instalar a IDE do Arduino
A instalação pode ser feita pelo site oficial do Arduino: https://www.arduino.cc/en/software

- 2º: Anexar a URL
  - Abra a IDE do Arduino
  - Clique em 'Arquivos'
  - Clique em 'Preferências'
  - Em 'URLs Adicionais para Gerenciadores de Placas', cole : https://dl.espressif.com/dl/package_esp32_index.json
  - ![image](https://user-images.githubusercontent.com/54655396/207967703-0e3e56b8-8aad-46eb-8c2a-a7c9f942dd59.png)

- 3º: Gerenciador de Placas:
  - Vá em 'Ferramentas'
  - Depois em 'Placas'
  - E finalmente em 'Gerenciador de Placas'
  - Na cixa de buscas, procure por 'ESP32'. Escolha a versã mais recente e instale
  - ![image](https://github.com/nicholasbarbosa/TCC/assets/54655396/626464d0-19e0-4e59-bc50-b3429708be9a)

- 4º: Finalizando:
  - Va em 'Tools' > 'Board' > 'Boards Manager'
  - ![image](https://github.com/nicholasbarbosa/TCC/assets/54655396/d87d75f9-6e3a-44ec-9497-6034c9114630)
  - Instale o ESP32
  - ![image](https://github.com/nicholasbarbosa/TCC/assets/54655396/e16cc7b2-aacd-4704-b5ca-b6258bc3d2b4)
  - Selecione o Board "M5Stack-Timer-Cam"

### Intalando TimerCam-arduino-master
- Instale o arquivo .zip
- Vá em 'Sketch' > 'Include Library' > 'Add .ZIP Library' e inclua o ZIP que baixou
   

