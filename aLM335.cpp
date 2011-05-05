#include <WProgram.h>
#include "aLM335.h"

/* aLM335 Copyright 2011 Kes Calhoun
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice,
	this list of conditions and the following disclaimer.
    
    Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
    
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

aLM335::aLM335() {
  _pin = 0;
  _refVoltage = 5;
  refFactorMetric = _refVoltage * 100 / 1024;
  refFactorImperial = _refVoltage * 180 / 1024;
}

aLM335::aLM335(int input) {
  _pin = input;
  _refVoltage = 5;
  refFactorMetric = _refVoltage * 100 / 1024;
  refFactorImperial = _refVoltage * 180 / 1024;
}

aLM335::aLM335(int input, float voltage) {
  _pin = input;
  _refVoltage = voltage;
  refFactorMetric = _refVoltage * 100 / 1024;
  refFactorImperial = _refVoltage * 180 / 1024;
}

aLM335::aLM335(int input, float voltage, bool externalReference) {
  _pin = input;
  if (externalReference) {
    analogReference(EXTERNAL);
  }
  else {
    analogReference(DEFAULT);
  }
  _refVoltage = voltage;
  refFactorMetric = _refVoltage * 100 / 1024;
  refFactorImperial = _refVoltage * 180 / 1024;
}


int aLM335::getRaw() {

  return (analogRead(_pin));

}

float aLM335::getKelvin() {

  float temperature = getRaw();
  temperature *= refFactorMetric;

  return (temperature);

}

float aLM335::getCelsius() {

  float temperature = getRaw();
  temperature *= refFactorMetric;
  temperature -= 273;

  return (temperature);

}

float aLM335::getFahrenheit() {

  float temperature = getRaw();
  temperature *= refFactorImperial;
  temperature -= 459.67;

  return (temperature);

}
