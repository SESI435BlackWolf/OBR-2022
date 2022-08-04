# OBR-2022

## Descrição
Este é o projeto usado pela equipe de robótica do SESI-435 para o campeonato OBR, Olimpíada Brasileira de Robótica. Todo o código é feito em c++ para uma placa arduino Atmega2560. Para o robô também utilizamos:
 * 2x Lego servo motor NXT
 * 1x Driver Motor Ponte H L298n
 * 1x Acelerômetro e giroscópio GY-521 (MPU-6050).
 * 4x Sensores reflexivos Tcrt5000

## Bibliotecas e requerimentos:
MPU6050_tockn por [tockn](https://github.com/tockn)

### Instruções
A instalação da biblioteca MPU6050_tockn pode ser feita tanto pelo github quanto pelo gerenciador de bibliotecas do Arduino IDE.

## Giroscópio
Como o giroscopio usado no robô queimou, decidimos manter os códigos do giroscópio nos arquivos, porém, comentados com `/* @Gisoscopio */`. Isso ocorre, pois, futuramente, compraremos outro, mas por hora, os trechos de código seriam inuteis e atrabalhariam o a performace do robô. Para voltar a utilia-los basta apagar os comentarios - apagando `/* Giroscopio` e `*/`, exemplo:

```C++
void setup() {
    pinMode(buzzer_pino, OUTPUT);

    Serial.begin(9600);

    /* @Giroscopio    <--- Apagar
    Wire.begin();
    mpu6050.begin();
    // Calibragem do giroscopio
    tocar(1);
    mpu6050.calcGyroOffsets(true); // delay de 3 s antes da calibragem e 3 s depois
    tocar(0);
    */    <--- Apagar 

    calibrar();
}
```

Ficaria:

```C++
void setup() {
    pinMode(buzzer_pino, OUTPUT);

    Serial.begin(9600);

    Wire.begin();
    mpu6050.begin();
    // Calibragem do giroscopio
    tocar(1);
    mpu6050.calcGyroOffsets(true); // delay de 3 s antes da calibragem e 3 s depois
    tocar(0);

    calibrar();
}
```