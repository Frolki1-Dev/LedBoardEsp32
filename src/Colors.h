#pragma once

struct RGB {
  int red, green, blue;
  bool isOff;
};

RGB red();
RGB blue();
RGB green();
RGB rgbOff();