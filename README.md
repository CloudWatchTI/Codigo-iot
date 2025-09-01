# Projeto CloudWatch – Sistema de Monitoramento Inteligente de Temperatura com ESP32

---

## Introdução
Este repositório contém a implementação prática do sistema embarcado desenvolvido no projeto CloudWatch, cujo objetivo é monitorar de forma automatizada a temperatura de equipamentos de refrigeração (freezers e geladeiras) no ambiente do Restaurante-Escola Estação Bistrô, vinculado à Universidade Católica de Santos.

A arquitetura do sistema baseia-se na coleta de dados por sensores digitais, transmissão via protocolo MQTT e posterior visualização em tempo real na plataforma Shiftr.io. O sistema também prevê a notificação automática de alertas em caso de desvios térmicos, e pode ser expandido com técnicas de aprendizado de máquina para previsão de falhas.

---

## Objetivos do Código
A aplicação embarcada tem como finalidade:

* Estabelecer comunicação com uma rede Wi-Fi.

* Ler periodicamente os dados de * temperatura (e futuramente, umidade).

* Transmitir os dados por protocolo MQTT à nuvem (Shiftr.io).

* Garantir reconexão automática em caso de falhas de rede.

* Organizar o código em módulos reutilizáveis e bem documentados.

---

## Componentes Utilizados
Microcontrolador: NodeMCU ESP32

Sensor de Temperatura: DS18B20

Sensor de Umidade: (suporte futuro)

Plataforma de Mensageria: Shiftr.io

Protocolo de Comunicação: MQTT (via PubSubClient)

Conexão de rede: Wi-Fi 2.4GHz

---

## Bibliotecas Necessárias
Antes de compilar e carregar o código no ESP32, é necessário instalar as seguintes bibliotecas na IDE Arduino:

WiFi.h – para conexão à rede sem fio.

PubSubClient.h – para comunicação via MQTT.

OneWire.h – para leitura do sensor DS18B20.

DallasTemperature.h – para conversão e tratamento da temperatura.

---

## Funcionamento Geral
Inicialização
O código configura a conexão Wi-Fi e estabelece comunicação com o broker MQTT na nuvem.

Leitura de Sensores
Periodicamente, o sensor DS18B20 coleta a temperatura do ambiente.

Transmissão de Dados
Os dados coletados são enviados via MQTT para o painel de controle na plataforma Shiftr.io.

Reconexão automática
Caso o ESP32 perca conexão com a rede ou com o broker, o sistema tenta se reconectar automaticamente, evitando perda de dados.

Recepção de Mensagens (opcional)
O ESP32 pode também receber mensagens do servidor (como comandos de configuração), graças à função de callback implementada.

---


## Expansões Futuras
Como parte da proposta de inovação, este sistema pode ser estendido com:

📈 Previsão Inteligente de Temperatura: Utilização de modelos de aprendizado de máquina embarcados (como redes LSTM) para prever anomalias antes que ocorram.

☁️ Armazenamento em nuvem: Envio dos dados históricos para um banco de dados remoto para análise posterior.

⚠️ Alertas proativos: Notificações de alerta quando o modelo prever que a temperatura excederá limites em breve.

📲 Aplicativo Mobile: Interface para acesso rápido e remoto aos dados e alertas.

---

## Bibliotecas (Instale pela IDE Arduino)
```cpp
#include <WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>
```

##  Demonstração de Funcionamento
###  Painel do Shiftr.io
No painel do [shiftr.io](https://www.shiftr.io), após conectar o ESP32 com sucesso, será possível visualizar:

Gráfico em tempo real da temperatura

Tópicos ativos

Dispositivos conectados (clientes)

 Serial Monitor (IDE Arduino)
```
Wi-Fi conectado!
IP: 192.168.0.102
Tentando conectar ao broker MQTT...
Conectado!
Temperatura atual: 5.75 °C
Mensagem enviada para tópico: estacao_bistro/temperatura

```

---

## Como Usar o Sistema
> Seguindo estas instruções, será possível realizar a leitura dos sensores e envio dos dados para a nuvem via MQTT.

#### 🔧 Passo 1: Instalar a IDE Arduino
Baixe e instale a IDE Arduino a partir do site oficial:
```bash
https://www.arduino.cc/en/software
```
#### 📦 Passo 2: Instalar as Bibliotecas Necessárias
Abra a IDE Arduino e vá em Sketch > Incluir Biblioteca > Gerenciar Bibliotecas...
Instale as seguintes bibliotecas:

* WiFi (já incluída para ESP32)

* PubSubClient

* OneWire

* DallasTemperature

#### 🧩 Passo 3: Instalar a Placa ESP32 na IDE Arduino

1. Vá em Arquivo > Preferências
2. No campo URLs Adicionais para Gerenciadores de Placas, adicione:
```bash
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```
3. Vá em Ferramentas > Placa > Gerenciador de Placas...
4. Procure por esp32 e clique em Instalar (pelo Espressif Systems)

#### 🧠 Passo 4: Configurar o Código
Abra o arquivo PCE_2.ino, que é o código principal. Verifique e configure:

* Nome da sua rede Wi-Fi (ssid)

* Senha da rede (password)

* Dados do broker MQTT da Shiftr.io:

  * Host (ex: broker.shiftr.io)

  * Porta (1883)

  * Usuário e senha

#### 🔌 Passo 5: Fazer Upload para o ESP32

1. Conecte o ESP32 via cabo USB ao seu computador.
2. Selecione a porta correta em Ferramentas > Porta
3. Clique em Upload (botão com seta para a direita).
4. Aguarde a compilação e o envio para a placa.

#### 🖥️ Passo 6: Monitorar pela IDE ou pela Shiftr.io

* Abra o Serial Monitor na IDE Arduino (9600 baud) para acompanhar as mensagens.
* Acesse o painel da Shiftr.io (https://www.shiftr.io) e veja os dados sendo recebidos em tempo real no seu broker MQTT.

#### ✅ Pronto!

A partir desse momento:

* O ESP32 estará coletando a temperatura periodicamente.
* Os dados serão enviados automaticamente para o painel MQTT.
* Caso haja perda de conexão com o Wi-Fi ou o broker, o código executará uma reconexão automática.
* Futuramente as notificações ou comandos poderão ser enviados do broker para o ESP32.

---

## Autores
Projeto desenvolvido por discentes da Universidade Católica de Santos – Curso de Ciência da Computação:

Amanda Naroaka

Gustavo Marcos Xavier dos Santos Silva

Leonardo de Almeida Pereira

Lucas Vinicius Dimarzio Carneiro

Marcelo Berger Gil

Vinicius Lustosa Silva

---
