/*
 * IRremote: IRsendRawDemo - demonstrates sending IR codes with sendRaw
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * IRsendRawDemo - added by AnalysIR (via www.AnalysIR.com), 24 August 2015
 *
 * This example shows how to send a RAW signal using the IRremote library.
 * The example signal is actually a 32 bit NEC signal.
 * Remote Control button: LGTV Power On/Off. 
 * Hex Value: 0x20DF10EF, 32 bits
 * 
 * It is more efficient to use the sendNEC function to send NEC signals. 
 * Use of sendRaw here, serves only as an example of using the function.
 * 
 */


#include "IRremote.h"

IRsend irsend;

const byte sd_pin_ = A7; 
const byte tx_pin_ = 18;

void setup()
{
	pinMode(sd_pin_, OUTPUT);
	digitalWrite(sd_pin_, LOW); 

	pinMode(tx_pin_, INPUT);
}

void loop() {
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
  //unsigned int irSignal[] = {9000, 4500, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 39416, 9000, 2210, 560}; //AnalysIR Batch Export (IRremote) - RAW
  
  //unsigned int irSignal[] = {50, -200, 50, -750, 50, -200, 50, -750, 50, -1000, 50, -2200, 50, -950, 50, -200, 50, -3250, 50, -2650, 50, -1150, 50, -200, 50, -2200, 50, -200, 50, -1150, 50, -1400, 50, -200, 50, -1950, 50, -200, 50}; //AnalysIR Batch Export (IRremote) - RAW
 
  unsigned int irSignal[] = {50, 65336, 50, 64786, 50, 65336, 50, 64786, 50, 64536, 50, 63336, 50, 64586, 50, 65336, 50, 62286, 50, 62886, 50, 64386, 50, 65336, 50, 63336, 50, 65336, 50, 64386, 50, 64136, 50, 65336, 50, 63586, 50, 65336, 50};
  
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.

  delay(5000); //In this example, the signal will be repeated every 5 seconds, approximately.
}
