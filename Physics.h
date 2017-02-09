#ifndef _Physics_h_
#define _Physics_h_

#include <Arduboy2.h>
#include "ELBBitmaps.h"

class Physics
{
public:
  Physics(Arduboy2 &arduboy);  
  int Raycast(Point pos, int direction, int color);//0 = Down, 1 = Left, 2 = Right, 3 = Up
  bool Pixelcollide(Point pos, int bitmapheight, int bitmapwidth, int direction, int color, int distance); //Distance = How far away to return true
  
private:
  Arduboy2 *ardu;
  
};



#endif //_Physics_h_
