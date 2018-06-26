/*
  3x3x3 LED Cube
  Connection Setup: 
  Columns
  [(x,y)-Pin]
  (1,1)-13
  (1,2)-12
  (1,3)-11
  (2,1)-9
  (2,2)-8
  (2,3)-7
  (3,1)-5
  (3-2)-4
  Layers
  [layer-Pin]
  a-A0
*/
//initializing and declaring led rows
  int column[8]={13,12,11,9,8,7,5,4};
//initializing and declaring led layers
  int layer = A0;

  int time = 250;
 
void setup()
{
  //setting rows to ouput
  for(int i = 0; i<8; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  //setting layers to output
  pinMode(layer, OUTPUT);
  
  //seeding random for random pattern
  randomSeed(analogRead(10));
}
//xxxxxxxxxxxxxxxxxxxxFUNCTION LOOPxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void loop()
{
  turnEverythingOff();//turn all off
  flickerOn();
  turnEverythingOn();//turn all on
  delay(time);
  turnOnAndOffAllByLayerUpAndDownNotTimed();
  layerstompUpAndDown();
  turnOnAndOffAllByColumnSideways();
  delay(time);
  aroundEdgeDown();
  turnEverythingOff();
  randomflicker();
  randomRain();
  diagonalRectangle();
  goThroughAllLedsOneAtATime();
  spiralInAndOut();
  flickerOff();
  turnEverythingOff();
  delay(2000);
}


//xxxxxxxxxxxxxxxxxxxxFUNCTIONSxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

///////////////////////////////////////////////////////////turn all off
void turnEverythingOff()
 {
   for(int i = 0; i<8; i++)
   {
     digitalWrite(column[i], 1);
   }
   
   digitalWrite(layer, 0);
 }
 
////////////////////////////////////////////////////////////turn all on
void turnEverythingOn()
{
  for(int i = 0; i<8; i++)
  {
    digitalWrite(column[i], 0);
  }
  //turning on layers
  digitalWrite(layer, 1);
}
///////////////////////////////////////////////////////turn columns off
void turnColumnsOff()
{
  for(int i = 0; i<8; i++)
  {
    digitalWrite(column[i], 1);
  }
}
/////////////////////////////////////////////////////////////flicker on
void flickerOn()
{
  int i = 150;
  while(i != 0)
  {
    turnEverythingOn();
    delay(i);
    turnEverythingOff();
    delay(i);
    i-= 5;
  }
}
//////////////turn everything on and off by layer up and down NOT TIMED
void turnOnAndOffAllByLayerUpAndDownNotTimed()
{
  int x = 75;
  for(int i = 5; i != 0; i--)
  {
    turnEverythingOn();
    
    digitalWrite(layer, 0);
    delay(x);
    
    digitalWrite(layer, 1);
    delay(x);
    
    digitalWrite(layer, 0);
    delay(x);
    
    digitalWrite(layer, 1);
    delay(x);
  }
}
//////////////////////////turn everything on and off by column sideways
void turnOnAndOffAllByColumnSideways()
{
  int x = 75;
  turnEverythingOff();
  //turn on layer
  digitalWrite(layer, 1);
  
  for(int y = 0; y<3; y++)
  {
    //turn on 0-3
    for(int i = 0; i<4; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn on 4-7
    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn off 0-3
    for(int i = 0; i<4; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 4-7
    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn on 4-7
    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn on 0-3
    for(int i = 0; i<4; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn off 4-7
    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 0-3
    for(int i = 0; i<4; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
  }
}
/////////////////////////////////////////up and down single layer stomp
void layerstompUpAndDown()
{
  int x = 75;
  
  digitalWrite(layer, 0);
  
  for(int y = 0; y<5; y++)
  {
    for(int count = 0; count<1; count++)
    { 
      digitalWrite(layer, 1);
      delay(x);
      digitalWrite(layer, 0);
      
      digitalWrite(layer, 1);
      delay(x);
      digitalWrite(layer, 0);
    }

    digitalWrite(layer, 1);
    delay(x);
    
    digitalWrite(layer, 0);
    delay(x);
  }
}
////////////////////////////////////////////////////////////flicker off
void flickerOff()
{
  turnEverythingOn();
  for(int i = 0; i!= 150; i+=5)
  {
    turnEverythingOff();
    delay(i+50);
    turnEverythingOn();
    delay(i);
  }
}
///////////////////////////////////////////around edge of the cube down
void aroundEdgeDown()
{
  for(int x = 200; x != 0; x -=50)
  {
    turnEverythingOff();
    
    digitalWrite(layer, 1);
    digitalWrite(column[5], 0);
    digitalWrite(column[6], 0);
      
    digitalWrite(column[0], 0);
    delay(x);
    digitalWrite(column[0], 1);
    digitalWrite(column[4], 0);
    delay(x);
    digitalWrite(column[4], 1);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[7], 1);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[3], 1);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[2], 1);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[1], 1);
  }
}
/////////////////////////////////////////////////////////random flicker
void randomflicker()
{
  turnEverythingOff();
  int x = 10;
  for(int i = 0; i !=750; i+=2)
  {
    int randomColumn = random(0,7);
  
    digitalWrite(layer, 1);
    digitalWrite(column[randomColumn], 0);
    delay(x);
    digitalWrite(layer, 0);
    digitalWrite(column[randomColumn], 1);
    delay(x); 
  }
}
////////////////////////////////////////////////////////////random rain
void randomRain()
{
  turnEverythingOff();
  int x = 100;
  for(int i = 0; i!=60; i+=2)
  {
    int randomColumn = random(0,7);
    digitalWrite(column[randomColumn], 0);
    digitalWrite(layer, 1);
    delay(x+50);
    digitalWrite(layer, 0);
    delay(x);
    digitalWrite(layer, 1);
    delay(x);
    digitalWrite(layer, 0);
    delay(x+50);
    digitalWrite(column[randomColumn], 1);
  }
}
/////////////////////////////////////////////////////diagonal rectangle
void diagonalRectangle()
{
  int x = 350;
  turnEverythingOff();
  for(int count = 0; count<5; count++)
  {
    //top left
    for(int i = 0; i<8; i++)
    {
      digitalWrite(column[i], 0);
    }
    
    digitalWrite(layer, 1);
    delay(x);
    
    turnEverythingOff();

    digitalWrite(layer, 1);
    delay(x);
    
    turnEverythingOff();
    
    digitalWrite(layer, 1);
    delay(x);
    
    turnEverythingOff();
    //bottom left
    for(int i = 0; i<8; i++)
    {
      digitalWrite(column[i], 0);
    }
    
    digitalWrite(layer, 1);
    delay(x);
    
    turnEverythingOff();
    
    digitalWrite(layer, 1);
    delay(x);
    
    turnEverythingOff();
    
    //top middle
    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 0);
    }
    
    delay(x);
    turnEverythingOff();
  }
  //top left
  for(int i = 0; i<8; i++)
  {
    digitalWrite(column[i], 0);
  }

  delay(x);
  turnEverythingOff();
}

//////////////////////////////////////////////////////spiral in and out
void spiralInAndOut()
{
  turnEverythingOn();
  int x = 60;
  for(int i = 0; i<6; i++)
  {
    //spiral in clockwise
    digitalWrite(column[0], 1);
    delay(x);
    digitalWrite(column[1], 1);
    delay(x);
    digitalWrite(column[2], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[7], 1);
    delay(x);
    digitalWrite(column[4], 1);
    delay(x);
    digitalWrite(column[5], 1);
    delay(x);
    digitalWrite(column[6], 1);
    delay(x);
    ///////////////////////////////////////spiral out counter clockwise
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[4], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);
    ///////////////////////////////////////spiral in counter clock wise
    digitalWrite(column[0], 1);
    delay(x);
    digitalWrite(column[4], 1);
    delay(x);
    digitalWrite(column[7], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[2], 1);
    delay(x);
    digitalWrite(column[1], 1);
    delay(x);
    digitalWrite(column[5], 1);
    delay(x);
    digitalWrite(column[6], 1);
    delay(x);
    //////////////////////////////////////////////spiral out clock wise
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[4], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);
  }
}
//////////////////////////////////////go through all leds one at a time
void goThroughAllLedsOneAtATime()
{
  int x = 15;
  turnEverythingOff();
  for(int y = 0; y<5; y++)
  {
    //0-3
    digitalWrite(layer, 1);
    for(int i = 0; i<4; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
      digitalWrite(column[i], 1);
      delay(x);
    }
    digitalWrite(layer, 0);
    //4-7
    digitalWrite(layer, 1);
    for(int i = 4; i<8; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
      digitalWrite(column[i], 1);
      delay(x);
    }
    digitalWrite(layer, 0);
  }
}
