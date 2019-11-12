int button = 10;
int buttonReset = 11;

int led1 = 2;
int led2 = 3;
int led3 = 6;
int ledGanhou = 7;

int led1State = LOW;
int led2State = LOW;
int led3State = LOW;
int ledGanhouState = LOW;

int ledAceso = 0;
bool jogando = true;

bool ganhou = false;

//variavel para contar o tempo
unsigned long previousTime = 0;

unsigned long currentTime = 0;

//intervalo de troca dos LEDS
const long interval = 200;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(ledGanhou, OUTPUT);
  
  pinMode(button, INPUT_PULLUP);
  pinMode(buttonReset, INPUT_PULLUP);

  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(led1, led1State);
  digitalWrite(led2, led2State);
  digitalWrite(ledGanhou, ledGanhouState);
  digitalWrite(led3, led3State);
}

void loop() {

  if (jogando)
  {
    ganhou = false;
    currentTime = millis();
  
    if(currentTime - previousTime >= interval)
    {
      ganhou = true;
       previousTime = currentTime;
       
       if (ledAceso == 1)
       {
          led1State = HIGH;
       }
       else
       {
          led1State = LOW;
       }
       if (ledAceso == 2)
       {
          led2State = HIGH;
       }
       else
       {
          led2State = LOW;
       }
       if (ledAceso == 3)
       {
          led3State = HIGH;
       }
       else
       {
          led3State = LOW;
       }
       ledAceso++;

       if(ledAceso >= 4)
       {
        ledAceso = 1;
       }
    }
  }

  digitalWrite(led1, led1State);
  digitalWrite(led2, led2State);
  digitalWrite(led3, led3State);
  digitalWrite(ledGanhou, ledGanhouState);

  if (digitalRead(button) == 0)
  {
      if(led3State == HIGH)
      {
        ledGanhouState = HIGH;
        digitalWrite(LED_BUILTIN, HIGH);
        jogando = false;
      }
  }

  if (digitalRead(buttonReset) == 0)
  {
     restartGame();
  }
 
  
}
  //comentário aleatório de teste do app pra Android
  void restartGame()
  {
    ledAceso = 0;
    ledGanhouState = LOW;
    digitalWrite(LED_BUILTIN, LOW);
    previousTime = currentTime = 0;
    jogando = true;
    ganhou = false;
  }
