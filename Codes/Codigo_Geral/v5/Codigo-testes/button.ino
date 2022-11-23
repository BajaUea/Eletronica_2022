void button_setup(){
  pinMode(button, INPUT);
  attachInterrupt (button, ISR_button, CHANGE);
}

void ISR_button()
{
  status_button = digitalRead(button);
}
