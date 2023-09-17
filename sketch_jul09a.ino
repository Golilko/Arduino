int anodPins[] = {A1, A2, A3, A4};
int segmentsPins[] = {5, 6, 7, 8, 9, 10, 11, 12};

void setup() {
for (int i = 0; i < 4; i++) {
pinMode(anodPins[i], OUTPUT);
}
for (int i = 0; i < 8; i++) {
pinMode(segmentsPins[i], OUTPUT);
}
}

int seg1[] = {0, 1, 1, 0, 0, 0, 0, 0}; //Буква хуй
int seg2[] = {1, 1, 0, 1, 1, 0, 1, 0};
int seg3[] = {1, 1, 1, 1, 0, 0, 1, 0};
int seg4[] = {0, 1, 1, 0, 0, 1, 1, 0};
int seg5[] = {1, 0, 1, 1, 0, 1, 1, 0};
int seg6[] = {1, 0, 1, 1, 1, 1, 1, 0};
int seg7[] = {1, 1, 1, 0, 0, 0, 0, 0};
int seg8[] = {1, 1, 1, 1, 1, 1, 1, 0};
int seg9[] = {1, 1, 1, 1, 0, 1, 1, 0};
int seg0[] = {1, 1, 1, 1, 1, 1, 0, 0};
int* seg[] = {seg1, seg2, seg3, seg4, seg5, seg6, seg7, seg8, seg9, seg0};

void loop() {
// отображаем букву хуй на всех разрядах
/* for (int i = 0; i < 4; i++) {
for (int k = 0; k < 8; k++) {
digitalWrite(segmentsPins[k], ((seg0[k] == 1) ? HIGH : LOW));
} */
for (int i = 0; i < 4; i++) {
for (int j = 0; j < 10; j++) {
for (int k = 0; k < 8; k++) {
digitalWrite(segmentsPins[k], ((seg[j][k] == 1) ? HIGH : LOW));
}

delay(500); // Дали паузу глазу воспринять
digitalWrite(anodPins[i], LOW); // Сняли напряжение с анода, чтобы переключение катодов не вызывали мерцание
}
}
} 
