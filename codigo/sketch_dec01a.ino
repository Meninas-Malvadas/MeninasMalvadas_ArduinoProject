//definição botoes
int button_jogador1 = 9;
int button_jogador2 = 10;
int button_jogador3 = 11;
int button_jogador4 = 12;
int buzzer = 13;

//definição leds
int led1 = 1;
int led2 = 2;
int led3 = 3;
int led4 = 4;

//definição leds que contam pontos
int ledGanhou_dupla1_1 = 5;
int ledGanhou_dupla1_2 = 6;

int ledGanhou_dupla2_1 = 7;
int ledGanhou_dupla2_2 = 8;

//definição do estado inicial dos 4 leds
int led1State = LOW;
int led2State = LOW;
int led3State = LOW;
int led4State = LOW;

//definição do estado inicial dos leds que contam os pontos
int ledGanhou_dupla1_1State = LOW;
int ledGanhou_dupla1_2State = LOW;

int ledGanhou_dupla2_1State = LOW;
int ledGanhou_dupla2_2State = LOW;

//diz qual led é que está aceso no momento (de 1 a 4 - como nenhum está aceso no inicio, começamos com 0)
int ledAceso = 0;

//variavel que verifica se o jogo ainda esta rolando
bool jogando = true;

//variavel que verifica se alguem ganhou o jogo
bool ganhou = false;

//variavel para contar o tempo
unsigned long previousTime = 0;

unsigned long currentTime = 0;

//intervalo de troca dos LEDS
const long interval = 200;

bool ledganhou1_2 = false;
bool ledganhou2_2 = false;
bool check[] = {false,false,false,false};

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  pinMode(ledGanhou_dupla1_1, OUTPUT);
  pinMode(ledGanhou_dupla1_2, OUTPUT);
  pinMode(ledGanhou_dupla2_1, OUTPUT);
  pinMode(ledGanhou_dupla2_2, OUTPUT);
  
  pinMode(button_jogador1, INPUT_PULLUP);
  pinMode(button_jogador2, INPUT_PULLUP);
  pinMode(button_jogador3, INPUT_PULLUP);
  pinMode(button_jogador4, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  digitalWrite(led1, led1State);
  digitalWrite(led2, led2State);
  digitalWrite(led3, led3State);
  digitalWrite(led4, led4State);
  
  digitalWrite(ledGanhou_dupla1_1, ledGanhou_dupla1_1State);
  digitalWrite(ledGanhou_dupla1_2, ledGanhou_dupla1_2State);
  digitalWrite(ledGanhou_dupla2_1, ledGanhou_dupla2_1State);
  digitalWrite(ledGanhou_dupla2_2, ledGanhou_dupla2_2State);

}

void loop() {

    if (jogando){
        ganhou = false;
        currentTime = millis();
    
        if(currentTime - previousTime >= interval){
             ganhou = true;
             previousTime = currentTime;

             if (ledGanhou_dupla1_1State == HIGH){
                 ledganhou1_2 = true;
             }
    
             //primeiro vai acender
             if (ledAceso == 1){
                 led1State = HIGH;
                 //tone(13,300);
             }else{
                 led1State = LOW;
                 //noTone(13);
             }
    
             //segundo vai acender
             if (ledAceso == 2){
                 led2State = HIGH;
             }else{
                 led2State = LOW;
           
             }
    
             //terceiro vai acender
             if (ledAceso == 3){
                 led3State = HIGH;
             }else{
                 led3State = LOW;
             }
    
             //quarto vai acender
             if (ledAceso == 4){
                 led4State = HIGH;
             }else{
                 led4State = LOW;
             }
             //incrementa
             ledAceso++;
    
             //volta para o inicio se for maior que 4
             if(ledAceso >= 5){
                 ledAceso = 1;
                 for (int i=0;i<4;i++)
                     check[i] = false;   
     
                 if (ledGanhou_dupla2_1State == HIGH){
                      ledganhou2_2 = true;
                 }
             }
        }
    } else{
        tone(13,300);
    }

    //leds 1,2,3,4 piscando
    digitalWrite(led1, led1State);
    digitalWrite(led2, led2State);
    digitalWrite(led3, led3State);
    digitalWrite(led4, led4State);
    
    //2 leds da primeira dupla
    digitalWrite(ledGanhou_dupla1_1, ledGanhou_dupla1_1State);
    digitalWrite(ledGanhou_dupla1_2, ledGanhou_dupla1_2State);
    
    //2 leds da segunda dupla 
    digitalWrite(ledGanhou_dupla2_1, ledGanhou_dupla2_1State);
    digitalWrite(ledGanhou_dupla2_2, ledGanhou_dupla2_2State);
    
    //checa se o jogador 1 apertou o botao
    if (digitalRead(button_jogador1) == 0 and check[0] == false){
        tone(13,300);
        check[0] = true;
        //checa se o led1 esta aceso
        if (led1State == HIGH && ledGanhou_dupla1_1State == LOW){
            ledGanhou_dupla1_1State = HIGH;
        }
        else if (led1State == HIGH && ledGanhou_dupla1_1State == HIGH && ledGanhou_dupla1_2State == LOW && ledganhou1_2 == true){
            ledGanhou_dupla1_2State = HIGH;
            jogando = false;
        }        
    } else{
        noTone(13);
    }

    //checa se o jogador 2 apertou o botao
    if (digitalRead(button_jogador2) == 0){
        //checa se o led2 esta aceso
        if (led2State == HIGH && ledGanhou_dupla1_1State == LOW){
            ledGanhou_dupla1_1State = HIGH;
        }
        else if (led2State == HIGH && ledGanhou_dupla1_1State == HIGH && ledGanhou_dupla1_2State == LOW && ledganhou1_2 == true){
            ledGanhou_dupla1_2State = HIGH;
            jogando = false;
        }
    }    

    //checa se o jogador 3 apertou o botao
    if (digitalRead(button_jogador3) == 0){
        //checa se o led3 esta aceso
        if (led3State == HIGH && ledGanhou_dupla2_1State == LOW){
            ledGanhou_dupla2_1State = HIGH;
        }
        else if (led3State == HIGH && ledGanhou_dupla2_1State == HIGH && ledGanhou_dupla2_2State == LOW && ledganhou2_2 == true){
            ledGanhou_dupla2_2State = HIGH;
            jogando = false;
        }
    }        

    //checa se o jogador 4 apertou o botao
    if (digitalRead(button_jogador4) == 0){
        //checa se o led4 esta aceso
        if (led4State == HIGH && ledGanhou_dupla2_1State == LOW){
            ledGanhou_dupla2_1State = HIGH;
        }
        else if (led4State == HIGH && ledGanhou_dupla2_1State == HIGH && ledGanhou_dupla2_2State == LOW && ledganhou2_2 == true){
            ledGanhou_dupla2_2State = HIGH;
            jogando = false;
        }
    }            


    
  
}
  //comentário aleatório de teste do app pra Android
  void restartGame()
  {
    ledAceso = 0;
    ledganhou1_2 = false;
    ledganhou2_2 = false;
    ledGanhou_dupla1_1State = LOW;
    ledGanhou_dupla1_2State = LOW;
    ledGanhou_dupla2_1State = LOW;
    ledGanhou_dupla2_2State = LOW;
    previousTime = currentTime = 0;
    jogando = true;
    ganhou = false;
  }
