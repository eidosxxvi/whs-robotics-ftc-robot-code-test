#pragma config(Sensor, S1,     ,               sensorLightActive)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


void earthquake()
{
  //What would display?
  double richterScale = 2.0;

  if(richterScale < 100.0)
  {
    nxtDisplayString(3,"%s", "tah'ts a rlealy rtosgn erqutakahe!");
  }
  if(richterScale < 5.0)
  {
    nxtDisplayString(3,"%s", "Whoa, that building fell down!");
  }
  if(richterScale < 2.0)
  {
    nxtDisplayString(3,"%s", "There was an earthquake, right?");
  }
  if(richterScale < 1.0)
  {
    nxtDisplayString(3,"%s", "wiggle wiggle");
  }

  /* Answer: "tah'ts a rlealy rtosgn erqutakahe!"
  ... and then "Whoa, that building fell down!"
  This is because all of these are if statements, so the compiler looks through ALL of them.
  If you want to display only "Whoa, that building fell down!", use else if statements
  after the first if statement. */
}


void mystery()
{
  //What would be displayed, if light sensor read 60?
  int lightSensor = SensorValue[S1];

  while(true)
  {
    if(lightSensor = 0)
    {
      nxtDisplayString(3,"%s", "I can't see anything!!!";
    }
    else
    {
      nxtDisplayString(3,"%s", "I see the light");
    }

    wait1Msec(50);
    lightSensor = SensorValue[S1];
  }

  /*Answer: Nothing (heh); there's going to be a compiler error because the condition in the if statement
  is written incorrectly. When only one "=" is used, the compiler reads the statement as an assignment.
  So "lightSensor = 0" reads as "put the value 0 into the variable lightSensor", not "see if the variable
  lightSensor is equal to 0".

  Also, the method nxtDisplayString is unclosed (missing a right parenthesis. */
}


void fun()
{
  //What would the string result be equal to?
    string object = "wind";
    string status = "high";
    string result = "";

    if(object == "world")
    {
      if(status == "round");
      {
        result = "it turns me on"
      }
    }
    else if(object == "wind")
    {
      if(status == "high");
      {
        result = "it blows my mind"
      }
    }
    else if(object == "sky")
    {
      if(status == "blue");
      {
        result = "it makes me cry"
      }
    }
    else
    {
      result = "aaaaahhhhhhhhhhhh"
    }

    /* Answer: The string result will still be equal to "", because the if statements are ended with ;.
    Ending if statements with ; causes the if statement to have an empty body and not go on with whatever's
    supposed to be inside it.

    Also, the assignment statements inside of the if statements (result = "it makes me cry", etc)
    are supposed to end with ;. */
}


void cool()
{
  //Would this run correctly?
  while(true){motor[motorA]=50;motor[motorB]=50;motor[motorC]=75;string str="hellotherepeoples";int x=9/3*2+13/9-1;wait1Msec(50);}

  /* Answer: Although the code looks ugly, yes, it would run correctly. The spaces and nice indentations
  (called "whitespace") are to allow the programmer to easily read code. Whitespace doesn't impact the compiler,
  meaning this:

  motor[motorA]=50;motor[motorB]=50;

  is the same as:

  motor[motorA]                                                  =                           50;    motor[motorB]
  =                                                      50;

  and:

  motor[motorA] = 50;
  motor[motorB] = 50;

  But of course, the third option is the most preferable (easiest to read, and space efficient at the same time). */
}