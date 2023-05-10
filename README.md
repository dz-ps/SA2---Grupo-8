# SA2---Grupo-8

# 1) a) O ThingSpeak é uma plataforma de Internet das Coisas (IoT) desenvolvida pela MathWorks, que permite a coleta, análise e visualização de dados de dispositivos IoT conectados. Ele fornece uma plataforma baseada na nuvem para coletar e analisar dados de sensores e outros dispositivos IoT, além de permitir que os usuários criem aplicativos baseados em IoT para monitorar e controlar seus dispositivos.

Existem várias maneiras de explorar a plataforma ThingSpeak, algumas das quais são:

1. Monitoramento de temperatura: uma aplicação comum de IoT é o monitoramento de temperatura. Os sensores de temperatura podem ser conectados a dispositivos IoT que enviam dados para a plataforma ThingSpeak, onde os dados podem ser analisados e visualizados em tempo real. Isso é útil em várias aplicações, como monitoramento de temperatura em salas de servidores, sistemas de aquecimento e refrigeração em edifícios e até mesmo monitoramento de temperatura em estufas.

2. Monitoramento de qualidade do ar: sensores de qualidade do ar podem ser conectados a dispositivos IoT que enviam dados para a plataforma ThingSpeak. Isso pode ser útil para monitorar a qualidade do ar em ambientes fechados, como edifícios, ou em ambientes externos, como áreas urbanas com alta poluição do ar.

3. Monitoramento de uso de energia: sensores de uso de energia podem ser conectados a dispositivos IoT que enviam dados para a plataforma ThingSpeak. Isso pode ser útil para monitorar o uso de energia em edifícios e identificar áreas onde a economia de energia pode ser realizada.

4. Controle de dispositivos: a plataforma ThingSpeak também pode ser usada para controlar dispositivos IoT, permitindo que os usuários liguem ou desliguem dispositivos remotamente. Isso pode ser útil em várias aplicações, como sistemas de irrigação, sistemas de iluminação e até mesmo sistemas de segurança.

5. Monitoramento de saúde: sensores de saúde podem ser conectados a dispositivos IoT que enviam dados para a plataforma ThingSpeak. Isso pode ser útil para monitorar a saúde de pacientes em tempo real e fornecer dados para médicos e outros profissionais de saúde.

Esses são apenas alguns exemplos de como a plataforma ThingSpeak pode ser explorada para coletar, analisar e visualizar dados de dispositivos IoT. A plataforma é altamente flexível e pode ser usada em uma ampla variedade de aplicações, dependendo das necessidades específicas do usuário.

# 1) b) Este é um exemplo de código que utiliza o sensor DHT22 para coletar dados de temperatura e umidade e enviar para a plataforma ThingSpeak, através da API HTTP. A integração é feita utilizando o protocolo WiFi e o módulo ESP32.

A seguir estão os passos de configuração e desenvolvimento da integração:

1. Bibliotecas:
Antes de iniciar a programação, é necessário incluir as bibliotecas necessárias para a utilização do sensor DHT22, do protocolo WiFi e da API HTTP. No código fornecido, as bibliotecas utilizadas são:

- DHTesp.h: para a leitura dos dados do sensor DHT22;
- WiFi.h: para a configuração da conexão WiFi;
- HTTPClient.h: para a integração com a API HTTP.

2. Definir as variáveis:
É necessário definir as variáveis que serão utilizadas no código, como o nome da rede WiFi e a senha, os pinos utilizados para os LEDs e para o sensor DHT22, e os valores de temperatura e umidade.

3. Configurar a conexão WiFi:
Para se conectar à rede WiFi, é necessário utilizar o método WiFi.begin() e um loop while para aguardar a conexão ser estabelecida. No código fornecido, a rede utilizada é "Wokwi-GUEST" e não há senha.

4. Configurar o sensor DHT22:
Para configurar o sensor DHT22, é necessário criar um objeto do tipo DHTesp e definir o pino utilizado para a leitura dos dados. No código fornecido, o pino utilizado é o 15.

5. Realizar a leitura dos dados do sensor:
Utilizando o método dhtSensor.getTempAndHumidity() é possível obter os valores de temperatura e umidade e armazená-los nas variáveis correspondentes.

6. Montar a URL da API:
É necessário montar a URL da API que será utilizada para enviar os dados para a plataforma ThingSpeak. No código fornecido, a URL é formada pelo endereço da API, a chave de API e os valores de temperatura e umidade.

7. Ativar os LEDs:
Para indicar as condições de temperatura e umidade, é possível utilizar LEDs. No código fornecido, se a temperatura for maior ou igual a 35°C, o LED 1 é ligado, e se a umidade for maior ou igual a 70%, o LED 2 é ligado.

8. Enviar os dados para a plataforma ThingSpeak:
Para enviar os dados para a plataforma ThingSpeak, é necessário utilizar a API HTTP. No código fornecido, é utilizado o método http.begin() para iniciar a conexão com a API, e o método http.GET() para enviar os dados. Se a conexão for bem-sucedida, o código verifica se o código de resposta HTTP está entre 200 e 299, indicando que a requisição foi bem-sucedida, e exibe o conteúdo da resposta (payload). Caso contrário, exibe uma mensagem de erro.

9. Aguardar um tempo antes de executar novamente:
Para evitar que a plataforma ThingSpeak seja sobrecarregada com dados, é recomendável adicionar uma pausa entre as leituras dos sensores. No código fornecido, é utilizado o método delay() para aguardar 1,5 segundos antes de executar novamente.
