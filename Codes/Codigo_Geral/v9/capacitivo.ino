void ISR_capacitivo1()
{
  bool status_1 = digitalRead(Capacitivo_1);
  bool status_2 = digitalRead(Capacitivo_2);
  if(status_1 == HIGH && status_2 == HIGH) {
    Tanque_nivel = 2;
    Tanque_display = 75;
    }
  else if (status_1 == HIGH && status_2 == LOW) {
    Tanque_nivel = 1;
    Tanque_display = 45;
    }
  else if (status_1 == LOW && status_2 == LOW) {
    Tanque_nivel = 0;
    Tanque_display = 15;
    }
}
void ISR_capacitivo2()
{
  bool status_1 = digitalRead(Capacitivo_1);
  bool status_2 = digitalRead(Capacitivo_2);
  if(status_1 == HIGH && status_2 == HIGH) {
    Tanque_nivel = 2;
    Tanque_display = 75;
    }
  else if (status_1 == HIGH && status_2 == LOW) {
    Tanque_nivel = 1;
    Tanque_display = 45;
    }
  else if (status_1 == LOW && status_2 == LOW) {
    Tanque_nivel = 0;
    Tanque_display = 15;
    }
}
