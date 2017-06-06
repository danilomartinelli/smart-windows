//Configurações dos Pinos.
int pino_digital = 0;
int pino_analogico = A5;
int pino_motor_1 = 6;
int pino_motor_2 = 7;
int pino_botao_fechado = 8;
int pino_botao_aberto = 9;
 
//Variáveis do código.
int val_analogico = 0;
int estado_botao_fechado = 0;
int estado_botao_aberto = 0;
boolean bool_chuva = false;
 
void setup()
{
  pinMode(pino_analogico, INPUT);
  pinMode(pino_motor_1, OUTPUT);
  pinMode(pino_motor_2, OUTPUT);
  pinMode(pino_botao_fechado, INPUT);
  pinMode(pino_botao_aberto, INPUT);
}
 
void loop()
{
  // Lê e armazena valores.
  val_analogico = analogRead(pino_analogico);
  estado_botao_fechado = digitalRead(pino_botao_fechado);
  estado_botao_aberto = digitalRead(pino_botao_aberto);
  // Verifica se está chovendo ou não.
  if (val_analogico > 400)
  {
    // Sol
    bool_chuva = false;
   
  }
  else
  {
    // Chuva
    bool_chuva = true;
  }
 
  // Aciona motor.
  if (bool_chuva && estado_botao_fechado == LOW)
  {
    digitalWrite(pino_motor_1, LOW);
    digitalWrite(pino_motor_2, HIGH);
  }
  if (bool_chuva && estado_botao_fechado == HIGH)
  {
    digitalWrite(pino_motor_1, LOW);
    digitalWrite(pino_motor_2, LOW);
  }
  if (!bool_chuva && estado_botao_aberto == LOW)
  {
     digitalWrite(pino_motor_1, HIGH);
     digitalWrite(pino_motor_2, LOW);
  }
  if (!bool_chuva && estado_botao_aberto == HIGH)
  {
    digitalWrite(pino_motor_1, LOW);
    digitalWrite(pino_motor_2, LOW);
  }
 
}
