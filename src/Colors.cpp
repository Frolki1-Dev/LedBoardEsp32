#include "Colors.h"
#include <cmath>
#include <cstdlib>

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

/*RGB HSVtoRGB(float H, float S,float V){
    if(H>360 || H<0 || S>100 || S<0 || V>100 || V<0){
        return RGB{0,0,0, false};
    }
    float s = S/100;
    float v = V/100;
    float C = s*v;
    float X = C*(1-abs(fmod(H/60.0, 2)-1));
    float m = v-C;
    float r,g,b;
    if(H >= 0 && H < 60){
        r = C,g = X,b = 0;
    }
    else if(H >= 60 && H < 120){
        r = X,g = C,b = 0;
    }
    else if(H >= 120 && H < 180){
        r = 0,g = C,b = X;
    }
    else if(H >= 180 && H < 240){
        r = 0,g = X,b = C;
    }
    else if(H >= 240 && H < 300){
        r = X,g = 0,b = C;
    }
    else{
        r = C,g = 0,b = X;
    }
    int R = (r+m)*255;
    int G = (g+m)*255;
    int B = (b+m)*255;

    return RGB{R, G, B, false};
}
*/

/*RGB HSVtoRGB(float h, float s,float v)
{
    RGB rgb = RGB{};
    unsigned char region, P, Q, T;
    unsigned int H, S, V, remainder;

    H = h;
    S = s;
    V = v;

    if (S == 0)
    {
        return RGB{0,0,0, false};
    }

    region = H / 43;
    remainder = (H - (region * 43)) * 6; 

    P = (V * (255 - S)) >> 8;
    Q = (V * (255 - ((S * remainder) >> 8))) >> 8;
    T = (V * (255 - ((S * (255 - remainder)) >> 8))) >> 8;

    switch (region)
    {
        case 0:
            rgb.red = V; rgb.green = T; rgb.blue = P;
            break;
        case 1:
            rgb.red = Q; rgb.green = V; rgb.blue = P;
            break;
        case 2:
            rgb.red = P; rgb.green = V; rgb.blue = T;
            break;
        case 3:
            rgb.red = P; rgb.green = Q; rgb.blue = V;
            break;
        case 4:
            rgb.red = T; rgb.green = P; rgb.blue = V;
            break;
        default:
            rgb.red = V; rgb.green = P; rgb.blue = Q;
            break;
    }

    return rgb;
}*/

float Hue2RGB(float m1, float m2, float hue)
{
    hue = hue < 0 ? hue+1 : hue > 1 ? hue-1 : hue;

    if (hue * 6 < 1)
        return m1 + (m2 - m1) * hue * 6;
    else if (hue * 2 < 1)
        return m2;
    else if (hue * 3 < 2)
        return m1 + (m2 - m1) * (2.0 / 3.0 - hue) * 6;
    else
        return m1;
}

RGB HSL2RGB(float h, float s,float v)
{
    h = h / 360;

    float m2 = v <= 0.5 ? v * (s + 1) : v + s - v * s;
    float m1 = v * 2 - m2;

    RGB rgb = RGB{};
    rgb.red = Hue2RGB(m1, m2, h + 1.0 / 3.0);
    rgb.green = Hue2RGB(m1, m2, h);
    rgb.blue = Hue2RGB(m1, m2, h - 1.0 / 3.0);

    return rgb;
}

RGB calculateRainbowColor(int max, int current)
{
    float hue = 360 / max * current;
    return HSL2RGB(hue, 100, 50);
}