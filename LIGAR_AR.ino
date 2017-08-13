/*
   IRremote: IRsendRawDemo - demonstrates sending IR codes with sendRaw
   An IR LED must be connected to Arduino PWM pin 3.
   Version 0.1 July, 2009
   Copyright 2009 Ken Shirriff
   http://arcfn.com

   IRsendRawDemo - added by AnalysIR (via www.AnalysIR.com), 24 August 2015

   This example shows how to send a RAW signal using the IRremote library.
   The example signal is actually a 32 bit NEC signal.
   Remote Control button: LGTV Power On/Off.
   Hex Value: 0x20DF10EF, 32 bits

   It is more efficient to use the sendNEC function to send NEC signals.
   Use of sendRaw here, serves only as an example of using the function.

*/


#include <IRremote.h>

IRsend irsend;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  Serial.println("Enviando");
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
  unsigned int irSignal[] = { 4464, 4428, 576, 1616, 576, 520, 576, 1616, 572, 1616, 576, 544, 552, 520, 576, 1612, 576, 520, 576, 544, 524, 1644, 572, 548, 548, 524, 572, 1616, 576, 1616, 572, 524, 572, 1616, 576, 544, 548, 1616, 552, 1640, 576, 1616, 572, 1616, 552, 568, 524, 1640, 576, 1616, 576, 1616, 576, 520, 548, 572, 548, 544, 552, 520, 572, 1616, 576, 524, 572, 524, 572, 1616, 572, 1616, 576, 1616, 576, 544, 548, 524, 548, 548, 572, 548, 548, 520, 576, 520, 572, 548, 548, 524, 572, 1616, 576, 1612, 576, 1616, 576, 1616, 576, 1612, 576, 5264, 4492, 4428, 576, 1616, 572, 524, 572, 1616, 576, 1616, 576, 520, 576, 520, 572, 1616, 576, 520, 576, 520, 576, 1612, 580, 520, 572, 544, 548, 1616, 576, 1616, 576, 520, 576, 1612, 576, 524, 572, 1616, 576, 1612, 576, 1616, 576, 1616, 576, 544, 548, 1616, 576, 1616, 576, 1612, 576, 520, 576, 544, 552, 544, 552, 520, 572, 1616, 576, 520, 576, 544, 552, 1612, 576, 1616, 576, 1616, 576, 520, 572, 548, 548, 520, 576, 544, 552, 544, 552, 544, 552, 544, 548, 544, 552, 1616, 576, 1612, 576, 1616, 576, 1616, 572, 1616, 576 };
  unsigned int irSignal2[] =  {4468, 4424, 580, 1612, 580, 516, 580, 1612, 576, 1612, 580, 516, 580, 516, 604, 1588, 576, 520, 576, 516, 604, 1588, 576, 520, 576, 520, 576, 1612, 580, 1612, 576, 520, 576, 1612, 580, 1612, 576, 520, 576, 1612, 580, 1612, 580, 1608, 580, 1612, 608, 1584, 604, 1584, 580, 520, 576, 1612, 580, 516, 580, 516, 576, 516, 580, 516, 580, 516, 580, 516, 576, 1612, 580, 516, 608, 1584, 580, 1608, 608, 1584, 580, 1612, 580, 516, 604, 488, 608, 488, 580, 1612, 604, 492, 580, 516, 576, 516, 580, 516, 604, 1588, 576, 1612, 608, 5232, 4496, 4424, 608, 1584, 604, 492, 604, 1584, 580, 1612, 580, 516, 604, 492, 580, 1608, 608, 488, 580, 516, 604, 1584, 584, 516, 604, 516, 552, 1612, 580, 1608, 580, 516, 580, 1612, 604, 1584, 608, 488, 608, 1584, 580, 1608, 584, 1608, 608, 1584, 608, 1580, 584, 1608, 604, 492, 608, 1580, 584, 512, 584, 512, 580, 516, 580, 516, 604, 492, 608, 488, 604, 1584, 608, 488, 580, 1608, 584, 1608, 608, 1584, 580, 1608, 608, 488, 608, 488, 608, 488, 580, 1608, 584, 512, 584, 512, 608, 488, 584, 512, 608, 1580, 612, 1580, 608};
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
  delay(5000); //In this example, the signal will be repeated every 5 seconds, approximately.
  Serial.println("Enviando 2");
  irsend.sendRaw(irSignal2, sizeof(irSignal2) / sizeof(irSignal2[0]), khz);
  delay(5000);

}
