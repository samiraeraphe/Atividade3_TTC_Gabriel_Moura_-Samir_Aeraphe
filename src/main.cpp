#include <SPI.h>
#include <LoRa.h>

// Definições de pinos baseadas no manual 7Semi RA-02 [cite: 137, 182]
#define SS 5
#define RST 4
#define DIO0 26

// Configurações do Contador e Temporização
int contador = 0;
unsigned long ultimoEnvio = 0;
const long intervalo = 2000; // Intervalo de 2 segundos (2000ms)

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;

    Serial.println("--- Iniciando Node LoRa RA-02 ---");

    // Configuração dos pinos SPI para o ESP32 conforme manual [cite: 201, 206]
    LoRa.setPins(SS, RST, DIO0);

    // Inicializa o rádio em 433 MHz [cite: 234]
    if (!LoRa.begin(433E6)) // caso seja o de 915 Mhz basta usar 915E6
    {
        Serial.println("Erro: Falha no hardware LoRa!");
        while (1)
            ;
    }

    Serial.println("Sistema Pronto. Aguardando/Enviando dados...");
}

void loop()
{
    unsigned long tempoAtual = millis();

    // --- TRANSMISSÃO AUTOMÁTICA (TX) ---
    if (tempoAtual - ultimoEnvio >= intervalo)
    {
        ultimoEnvio = tempoAtual;

        String mensagem = "Envio modulo 1 - ID: " + String(contador);

        Serial.print(">> Transmitindo: ");
        Serial.println(mensagem);

        LoRa.beginPacket();   // [cite: 242]
        LoRa.print(mensagem); // [cite: 250]
        LoRa.endPacket();     // [cite: 251]

        contador++; // Incrementa para a próxima mensagem ser distinta
    }

    // --- RECEPÇÃO (RX) ---
    int packetSize = LoRa.parsePacket(); // [cite: 294]
    if (packetSize)
    {
        String recebido = "";
        while (LoRa.available())
        {
            recebido += (char)LoRa.read(); // [cite: 299]
        }

        Serial.print("<< Recebido: ");
        Serial.print(recebido);
        Serial.print(" | RSSI: ");
        Serial.println(LoRa.packetRssi()); // Força do sinal recebido
    }
}