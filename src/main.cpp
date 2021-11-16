#include <Arduino.h>

#include <../lib/led/QwiicLedStick.h>

static LED *_leds;
static int delayLed = 500;

struct RGB {
  int red, green, blue;
  bool isOff;
};

struct Board {
  RGB led0, led1, led2, led3, led4, led5, led6, led7, led8, led9;
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();

  Serial.println("Initializing");
  _leds = new LED();
  _leds->begin();
  Serial.println("Starting");
}

RGB getRgbByIndex(Board board, int index) {
  switch(index) {
    case 0:
    return board.led0;
    case 1:
    return board.led1;
    case 2:
    return board.led2;
    case 3:
    return board.led3;
    case 4:
    return board.led4;
    case 5:
    return board.led5;
    case 6:
    return board.led6;
    case 7:
    return board.led7;
    case 8:
    return board.led8;
    case 9:
    return board.led9;
  }
}

RGB red() {
  return RGB{255,0,0,false};
}

RGB blue() {
  return RGB{0,0,255,false};
}

RGB green() {
  return RGB{0,255,0,false};
}

RGB rgbOff() {
  return RGB{0,0,0,true};
}

/**
 * @brief Make the knight rider animation
 * 
 * @return Board*
 */
void knightRiderAnimation(Board * animation) {
  animation[0] = {
    rgbOff(),
    red(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    red(),
  };
  animation[1] = {
    rgbOff(),
    rgbOff(),
    green(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    green(),
    rgbOff(),
  };
  animation[2] = {
    rgbOff(),
    rgbOff(),
    rgbOff(),
    blue(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    blue(),
    rgbOff(),
    rgbOff(),
  };
  animation[3] = {
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    red(),
    rgbOff(),
    red(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
  };
  animation[4] = {
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    green(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
  };
  animation[5] = {
    rgbOff(),
    blue(),
    blue(),
    blue(),
    blue(),
    blue(),
    blue(),
    blue(),
    blue(),
    blue(),
  };
  animation[6] = {
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    red(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
  };
  animation[7] = {
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    green(),
    rgbOff(),
    green(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
  };
  animation[8] = {
    rgbOff(),
    rgbOff(),
    rgbOff(),
    blue(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    blue(),
    rgbOff(),
    rgbOff(),
  };
  animation[9] = {
    rgbOff(),
    rgbOff(),
    red(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    red(),
    rgbOff(),
  };
  animation[10] = {
    rgbOff(),
    green(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    green(),
  };
  animation[11] = {
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
    rgbOff(),
  };
}

void loop() {
  // put your main code here, to run repeatedly:
  //_leds->setLEDBrightness(5);

  Board animation[11];
  int size;

  knightRiderAnimation(animation);

  for(int board_index = 0; board_index <= 11; board_index++) {
    Serial.printf("Bord %i\n", board_index);
    Board currentBoard = animation[board_index];
    // Loop thought LED
    for(int led_index = 0; led_index <= 9; led_index++) {
      Serial.printf("Index %i\n", led_index);
      RGB currentRgb = getRgbByIndex(currentBoard, led_index);
      if(currentRgb.isOff) {
        _leds->setLEDBrightness(led_index, 0);
      } else {
        _leds->setLEDBrightness(led_index, 5);
        _leds->setLEDColor(led_index, currentRgb.red, currentRgb.green, currentRgb.blue);
      }
    }
    delay(delayLed);
  }
}