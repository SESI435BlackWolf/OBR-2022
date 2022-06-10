byte buzzer_pino = 11;

void tocar (bool musica) {
    if (musica) {
        for (byte x = 0; x < 6; x ++) {
            tone(buzzer_pino, 500, 250);
            delay(350);
            tone(buzzer_pino, 4500, 250);
            delay(350);
        }
    }
    else {
        for (byte x = 0; x < 3; x ++) {
            tone(buzzer_pino, 500, 300);
<<<<<<< HEAD
            delay(400);
            tone(buzzer_pino, 4500, 300);
            delay(400);
            tone(buzzer_pino, 4500, 300);
>>>>>>> 9d6730e5b330fc1db534e1aeff3d9eff5225784e
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
