# Projeto CloudWatch – Sistema de Monitoramento Inteligente de Temperatura com ESP32

---

## 1. Introdução
Este repositório contém a implementação prática do sistema embarcado desenvolvido no projeto CloudWatch, cujo objetivo é monitorar de forma automatizada a temperatura de equipamentos de refrigeração (freezers e geladeiras) no ambiente do Restaurante-Escola Estação Bistrô, vinculado à Universidade Católica de Santos.

A arquitetura do sistema baseia-se na coleta de dados por sensores digitais, transmissão via protocolo MQTT e posterior visualização em tempo real na plataforma Shiftr.io. O sistema também prevê a notificação automática de alertas em caso de desvios térmicos, e pode ser expandido com técnicas de aprendizado de máquina para previsão de falhas.

---

## 2. Objetivos do Código
A aplicação embarcada tem como finalidade:

Estabelecer comunicação com uma rede Wi-Fi.

Ler periodicamente os dados de temperatura (e futuramente, umidade).

Transmitir os dados por protocolo MQTT à nuvem (Shiftr.io).

Garantir reconexão automática em caso de falhas de rede.

Organizar o código em módulos reutilizáveis e bem documentados.

---

## 3. Estrutura Modular do Código
A aplicação foi dividida em múltiplos arquivos .ino, cada um com uma função específica no projeto. Essa abordagem modular facilita a manutenção, compreensão e expansibilidade do sistema.

📁 Descrição dos Arquivos
Arquivo	Descrição Acadêmica
PCE_2.ino	Arquivo principal. Contém a função setup() e o loop(), que inicializam o sistema, realizam leituras dos sensores e coordenam o envio dos dados para a nuvem.
C_Setup_WiFi.ino	Função responsável por configurar e conectar o ESP32 a uma rede Wi-Fi. É chamada no setup(). Inclui tentativas de reconexão e verificação de sucesso.
D_Reconnect.ino	Verifica periodicamente a conexão com o broker MQTT. Caso a conexão seja perdida, executa a rotina de reconexão automática.
envio_de_mensagens.ino	Realiza o envio dos dados lidos (temperatura) ao servidor via protocolo MQTT. Utiliza a biblioteca PubSubClient.
B_Recebe_as_mensagens.ino	Define a função callback, responsável por receber e processar mensagens MQTT enviadas do broker para o ESP32 (ex: comandos remotos, configurações).
Sensor_umidade.ino	Código complementar voltado à futura integração com sensores de umidade. Ainda em desenvolvimento, serve como base para expansão do sistema.

---

## 4. Componentes Utilizados
Microcontrolador: NodeMCU ESP32

Sensor de Temperatura: DS18B20

Sensor de Umidade: (suporte futuro)

Plataforma de Mensageria: Shiftr.io

Protocolo de Comunicação: MQTT (via PubSubClient)

Conexão de rede: Wi-Fi 2.4GHz

---

## 5. Bibliotecas Necessárias
Antes de compilar e carregar o código no ESP32, é necessário instalar as seguintes bibliotecas na IDE Arduino:

WiFi.h – para conexão à rede sem fio.

PubSubClient.h – para comunicação via MQTT.

OneWire.h – para leitura do sensor DS18B20.

DallasTemperature.h – para conversão e tratamento da temperatura.

---

## 6. Funcionamento Geral
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

## 7. Visualização em Nuvem
A integração com a plataforma Shiftr.io permite:

Visualização dos dados em tempo real.

Testes com múltiplos dispositivos simultâneos.

Diagnóstico remoto de falhas de leitura ou conectividade.

---

## 8. Expansões Futuras
Como parte da proposta de inovação, este sistema pode ser estendido com:

📈 Previsão Inteligente de Temperatura: Utilização de modelos de aprendizado de máquina embarcados (como redes LSTM) para prever anomalias antes que ocorram.

☁️ Armazenamento em nuvem: Envio dos dados históricos para um banco de dados remoto para análise posterior.

⚠️ Alertas proativos: Notificações de alerta quando o modelo prever que a temperatura excederá limites em breve.

📲 Aplicativo Mobile: Interface para acesso rápido e remoto aos dados e alertas.

---

## 9. Considerações Finais
A organização modular do código, o uso de padrões consolidados em IoT (como MQTT) e a possibilidade de expansão com inteligência artificial tornam este sistema adequado para aplicações em ambientes críticos, como cozinhas industriais, hospitais ou laboratórios.

A escolha do ESP32 como plataforma base se deu por sua eficiência energética, capacidade de processamento e versatilidade de conexão, sendo apropriado mesmo para soluções embarcadas com recursos limitados.

---
## 10. Pré-requesitos
Pré-requisitos
### 10.1 Hardware
NodeMCU ESP32

Sensor de temperatura DS18B20

(Opcional) Sensor de umidade

Resistores e cabos de conexão

Fonte de alimentação USB

10.2 Bibliotecas (Instale pela IDE Arduino)
cpp
Copiar
Editar
#include <WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

---

## 11. Autores
Projeto desenvolvido por discentes da Universidade Católica de Santos – Curso de Ciência da Computação:

Amanda Naroaka

Gustavo Marcos Xavier dos Santos Silva

Leonardo de Almeida Pereira

Lucas Vinicius Dimarzio Carneiro

Marcelo Berger Gil

Vinicius Lustosa Silva

---
