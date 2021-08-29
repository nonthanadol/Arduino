double channel[4];
void setup() {
//    pinMode(3, INPUT);
//    pinMode(5, INPUT);
//    pinMode(6, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    Serial.begin(9600);
}

void loop() {
//    channel[0] = pulseIn(3, HIGH);
//    channel[1] = pulseIn(5, HIGH);
//    channel[2] = pulseIn(6, HIGH);
    channel[3] = pulseIn(4, HIGH);
    channel[4] = pulseIn(5, HIGH);
    Serial.print(channel[3]);
    Serial.print(" - ");
    Serial.println(channel[4]);
}
