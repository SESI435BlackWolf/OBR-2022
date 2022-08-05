#define DELAY 2000


class Motor {
    private:
        byte pinoMarrom;
        byte pinoBranco;
        byte pinoControle;

    public:
        Motor(byte pM, byte pB, byte pC) {
            this->pinoMarrom   = pM;
            this->pinoBranco   = pB;
            this->pinoControle = pC;

            pinMode(this->pinoMarrom, OUTPUT);
            pinMode(this->pinoBranco, OUTPUT);
            pinMode(this->pinoControle, OUTPUT);
        }

    void ligar(bool pinoM, bool pinoB, byte velocidade) {
            Serial.println("Pino Marrom:  (" + String(pinoMarrom) + ")\t\t\t" + String(pinoMarrom? HIGH : LOW));
            Serial.println("Pino Branco:  (" + String(pinoBranco) + ")\t\t\t" + String(pinoBranco? HIGH : LOW));
            Serial.println("Pino Laranja: (" + String(pinoControle) + ")\t\t\t" + String(pinoControle));

            digitalWrite(pinoMarrom, pinoM);
            digitalWrite(pinoBranco, pinoB);
            analogWrite(pinoControle, velocidade);
        }
};


Motor motorDireita (52, 53, 12);    // Marrom (IN_1 ) : Branco (IN_2) : Laranja (EN_A)
Motor motorEsquerda(50, 51, 13);    // Marrom (IN_3 ) : Branco (IN_4) : Laranja (EN_B)

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println("----------------------- Testando Motor Direito -----------------------");
    Serial.println("Motor direita -> Frente:");
    motorDireita.ligar(LOW, HIGH, 255);
    delay(DELAY);

    Serial.println("Motor direita -> Re:");
    motorDireita.ligar(LOW, HIGH, 255);
    delay(DELAY);

    Serial.println("---------------------- Testando Motor Esquerdo -----------------------");
    Serial.println("Motor direita -> Frente:");
    motorDireita.ligar(LOW, HIGH, 255);
    delay(DELAY);

    Serial.println("Motor direita -> Re:");
    motorDireita.ligar(LOW, HIGH, 255);
    delay(DELAY);


    Serial.println("--------------------------- Testando Robo ----------------------------");
    Serial.println("Robo -> Frente:");
    motorDireita.ligar(LOW, HIGH, 255);
    motorEsquerda.ligar(LOW, HIGH, 255);
    delay(DELAY);

    Serial.println("Robo direita -> Re:");
    motorDireita.ligar(HIGH, LOW, 255);
    motorEsquerda.ligar(HIGH, LOW, 255);
    delay(DELAY);

    Serial.println("Motor direita -> Horario:");
    motorDireita.ligar(HIGH, LOW, 255);
    motorEsquerda.ligar(LOW, HIGH, 255);
    delay(DELAY);

    Serial.println("Motor direita -> Antihorario:");
    motorDireita.ligar(LOW, HIGH, 255);
    motorEsquerda.ligar(HIGH, LOW, 255);
    delay(DELAY);
}
