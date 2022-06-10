byte buzzer_pino = 11;

void tocar (bool musica) {
    if (musica) {
        for (byte x = 0; x < 6; x ++) {
            tone(buzzer_pino, 500, 250);
            tone(buzzer_pino, 4500, 250);
        }
    }
    else {
        for (byte x = 0; x < 3; x ++) {
            tone(buzzer_pino, 500, 300);
            tone(buzzer_pino, 4500, 300);
        }
        noTone(buzzer_pino);
    }
}

void setup() {
    // put your setup code here, to run once:
    pinMode(buzzer_pino, OUTPUT);

}

void loop() {
    // put your main code here, to run repeatedly:
    tocar(0);
    delay(1000);
    tocar(1);
    delay(1000);
}
