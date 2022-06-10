byte buzzer_pin = 11;

void tocar (bool musica) {
    if (musica) {
        for (byte x = 0; x < 6; x ++) {
            tone(buzzer_pino, 500);
            delay(250);
            tone(buzzer_pin, 5000);
            delay(250);
        }
    }
    else {
        for (byte x = 0; x < 3; x ++) {
            tone(buzzer_pin, 700);
            delay(300);
            tone(buzzer_pin, 5000);
            delay(300);
        }
    digitalWrite(buzzer_pin, LOW);
    }
}

void setup() {
    // put your setup code here, to run once:
    pinMode(buzzer_pin, OUTPUT);
    
}

void loop() {
    // put your main code here, to run repeatedly:
    tocar(0);
    delay(1500);
    tocar(1);
    delay(1500);
}
