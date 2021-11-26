#include "Colors.h"

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