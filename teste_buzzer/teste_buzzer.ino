byte buzzer_pino = 11;

void tocar (bool musica) {
    if (musica) {
        for (int hz = 2000; hz >= 700; hz -= 100) {
            tone(buzzer_pino, hz);
            delay(100);
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
