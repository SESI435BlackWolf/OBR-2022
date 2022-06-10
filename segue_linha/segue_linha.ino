#define NTESTES 125
#define PRETO 0
#define BRANCO 1

byte buzzer_pino = 2;

void tocar (bool musica) {
    if (musica) {
        for (int hz = 1400; hz >= 700; hz -= 100) {
            tone(buzzer_pino, hz, 200);
            delay(250);
            noTone(buzzer_pino);
        }
        delay(100);
    }
    else {
        for (byte x = 0; x < 3; x ++) {
            tone(buzzer_pino, 500, 300);
            delay(400);
            tone(buzzer_pino, 3000, 300);
            delay(400);
        }
    }
    noTone(buzzer_pino);
}

class Sensor {
  public:
    byte pinoEntrada;
    unsigned short threshold;

    Sensor(byte pino) {
      this->pinoEntrada = pino;
      this->threshold = 0;
    }

    bool ler() {
      return (analogRead(this->pinoEntrada) > this->threshold);
    }
};

class Motor {
  private:
    byte pinoPreto;
    byte pinoBranco;
    byte pinoControle;

  public:
    Motor(byte pP, byte pB, byte pC) {
      this->pinoPreto = pP;
      this->pinoBranco = pB;
      this->pinoControle = pC;

      pinMode(this->pinoPreto, OUTPUT);
      pinMode(this->pinoBranco, OUTPUT);
      pinMode(this->pinoControle, OUTPUT);
    }

    void ligar(bool pinoP, bool pinoB, byte velocidade) {
      digitalWrite(pinoPreto, pinoP);
      digitalWrite(pinoBranco, pinoB);
      analogWrite(pinoControle, velocidade);
    }
};

Motor motorDireita(22, 23, 13);
Motor motorEsquerda(24, 25, 12);

Sensor sensorExDireita(0);
Sensor sensorDireita(1);
Sensor sensorEsquerda(2);
Sensor sensorExEsquerda(3);

void calibrar() {
  tocar(1);
  Serial.println("========================================");
  Serial.println("Coloque todos os sensores na cor BRANCA");
  delay(5000);

  // Calibragem Branco
  unsigned long media_brancoD  = 0;
  unsigned long media_brancoDD = 0;
  unsigned long media_brancoE  = 0;
  unsigned long media_brancoEE = 0;

  for (short teste = 1; teste <= NTESTES; teste++) {
    media_brancoD  += analogRead( sensorDireita.pinoEntrada    );
    media_brancoDD += analogRead( sensorExDireita.pinoEntrada  );
    media_brancoE  += analogRead( sensorEsquerda.pinoEntrada   );
    media_brancoEE += analogRead( sensorExEsquerda.pinoEntrada );
  }
  
  tocar(0);
  delay(1000);
  tocar(1);
  Serial.println("========================================");
  Serial.println("Coloque todos os sensores na cor PRETA");
  delay(5000);
  

  // Calibragem Preto
  unsigned long media_pretoD  = 0;
  unsigned long media_pretoDD = 0;
  unsigned long media_pretoE  = 0;
  unsigned long media_pretoEE = 0;

  for (short teste = 1; teste <= NTESTES; teste++) {
    media_pretoD  += analogRead( sensorDireita.pinoEntrada    );
    media_pretoDD += analogRead( sensorExDireita.pinoEntrada  );
    media_pretoE  += analogRead( sensorEsquerda.pinoEntrada   );
    media_pretoEE += analogRead( sensorExEsquerda.pinoEntrada );
  }
  tocar(0);

  sensorDireita.threshold    = round( (media_brancoD  + media_pretoD  ) / (NTESTES * 2));
  sensorExDireita.threshold  = round( (media_brancoDD + media_pretoDD ) / (NTESTES * 2));
  sensorEsquerda.threshold   = round( (media_brancoE  + media_pretoE  ) / (NTESTES * 2));
  sensorExEsquerda.threshold = round( (media_brancoEE + media_pretoEE ) / (NTESTES * 2));

  Serial.println("========================================");
  Serial.println("Sensor Direita     | " + String(sensorDireita.threshold));
  Serial.println("Sensor Ex Direita  | " + String(sensorExDireita.threshold));
  Serial.println("Sensor Esquerda    | " + String(sensorEsquerda.threshold));
  Serial.println("Sensor Ex Esquerda | " + String(sensorExEsquerda.threshold));
}

void setup() {
  Serial.begin(9600);

  pinMode(53, OUTPUT);
  pinMode(buzzer_pino,OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(53, HIGH);
  digitalWrite(5, LOW);

  calibrar();
}

void loop() {
  // Segue Linha
  bool leituraD = sensorDireita.ler();
  bool leituraE = sensorEsquerda.ler();
  bool leituraXD = sensorExDireita.ler();
  bool leituraXE = sensorExEsquerda.ler();

/*
  Serial.print   ("ExD: " + String( leituraXD ));
  Serial.print   ("  D: "   + String( leituraD  ));
  Serial.print   ("  E: "   + String( leituraE  ));
  Serial.println ("  ExE: " + String( leituraXE ));
  
  if (leituraXD == PRETO or leituraXE == PRETO) {
    //curva >90°
    if (leituraXD == PRETO and leituraXE == BRANCO) {
      motorDireita.ligar(LOW, HIGH, 115);
      motorEsquerda.ligar(LOW, HIGH, 115);
      delay(500);

      motorDireita.ligar(HIGH, LOW, 115);
      motorEsquerda.ligar(LOW, HIGH, 115);
      delay(1500);
    }
    else if (leituraXD == BRANCO and leituraXE == PRETO) {
      motorDireita.ligar(LOW, HIGH, 115);
      motorEsquerda.ligar(LOW, HIGH, 115);
      delay(500);

      motorDireita.ligar(LOW, HIGH, 115);
      motorEsquerda.ligar(HIGH, LOW, 115);
      delay(1500);
    }
  }
  */
  // else {
    if (leituraD == PRETO and leituraE == PRETO) {
      motorDireita.ligar(LOW, HIGH, 90);
      motorEsquerda.ligar(LOW, HIGH, 90);
    }
    else if (leituraD == BRANCO and leituraE == PRETO) {
      motorDireita.ligar(HIGH, LOW, 86);
      motorEsquerda.ligar(LOW, HIGH, 86);
    }
    else if (leituraD == PRETO and leituraE == BRANCO) {
      motorDireita.ligar(LOW, HIGH, 86);
      motorEsquerda.ligar(HIGH, LOW, 86);
    }
    else if (leituraD == BRANCO and leituraE == BRANCO) {
      motorDireita.ligar(LOW, HIGH, 90);
      motorEsquerda.ligar(LOW, HIGH, 90);
    }
  // }
}
