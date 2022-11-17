void button_setup()
{
  pinMode(button, INPUT);
  attachInterrupt(button, ISR_button, HIGH);
}

void ISR_button()
{
  status_button++
}
