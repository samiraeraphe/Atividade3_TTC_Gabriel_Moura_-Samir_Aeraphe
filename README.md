# Atividade3_TTC_Gabriel_Moura_Samir_Aeraphe
#  Comunicação LoRa (TT&C)

## Descrição
Este projeto implementa um sistema de comunicação sem fio utilizando dois microcontroladores ESP32 e módulos LoRa RA-02, com o objetivo de aplicar conceitos básicos de TT&C (Telemetria, Rastreamento e Comando).

O sistema foi desenvolvido em modo **half-duplex**, permitindo que ambos os dispositivos possam transmitir e receber dados de forma alternada. As mensagens são enviadas periodicamente em formato de texto, com identificação incremental, possibilitando o acompanhamento da comunicação via Serial Monitor.

---

## Configuração do Sistema

### Hardware
- 2x ESP32  
- 2x Módulo LoRa RA-02  
- Comunicação via SPI  

### Conexões (ESP32 ↔ LoRa)
- SS → GPIO 5  
- RST → GPIO 4  
- DIO0 → GPIO 26  
- SPI padrão do ESP32 (MISO, MOSI, SCK)

---

## Parâmetros de Comunicação
- Frequência: **433 MHz**
- Biblioteca utilizada: `LoRa.h`
- Modo de operação: **Half-Duplex**
- Envio de mensagens: periódico (intervalo fixo)
- Identificação: contador incremental

---

## Funcionamento

- Os dispositivos alternam entre transmissão e recepção  
- As mensagens seguem o padrão:
- O receptor exibe:
- Mensagem recebida  
- Intensidade do sinal (RSSI)  

---

## Observações

Durante os testes e com o aviso na atividade, foi identificado que um dos módulos LoRa apresentava instabilidade, reiniciando a cada envio.  
Devido a essa limitação de hardware, não foi possível validar completamente o funcionamento em modo half-duplex.

Como solução, o módulo instável foi utilizado predominantemente como receptor, permitindo ainda a demonstração da comunicação básica entre os dispositivos.

---

##  Tecnologias Utilizadas
- ESP32  
- LoRa RA-02  
- PlatformIO  
- Biblioteca LoRa.h  

---

##  Autores
- Gabriel Moura  
- Samir Aeraphe  
