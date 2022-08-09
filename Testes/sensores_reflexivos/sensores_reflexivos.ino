class Sensor {
    public:
        byte pinoEntrada;

        Sensor(byte pino) {
            this->pinoEntrada = pino;
        }

        byte ler() {
            return (analogRead(pinoEntrada));
        }
};


Sensor sensorExEsquerda(A0);    // Amarelo
Sensor sensorEsquerda  (A1);    // Azul
Sensor sensorDireita   (A2);    // Roxo
Sensor sensorExDireita (A3);    // Verde

void setup() {
    Serial.begin(9600);

}

void loop() {
    Serial.print("ExD: "    ); Serial.print(sensorExDireita.ler());
    Serial.print("\t| D: "  ); Serial.print(sensorDireita.ler());
    Serial.print("\t| E: "  ); Serial.print(sensorEsquerda.ler());
    Serial.print("\t| ExE: "); Serial.print(sensorExEsquerda.ler());
    Serial.println();
}
