#ifndef _Animation_h_
#define _Animation_h_

#include <Arduboy2.h>
#include "ELBBitmaps.h"

typedef struct Frame_s {
  const uint8_t *bitmap;
  int bitmapwidth;
  int bitmapheight;  
  int color;
} Frame_t;

typedef struct Animation_s {
  int x;
  int y;
  int speed; // Everyxframes (speed); Speed for switching frames
  int frame = 0; // Which frame is currently playing
  int length; //Amount of frames
  Frame_t *Frames[1]; 
  bool playing; 
} Animation_t;

class Animation
{
public:
  Animation(Arduboy2 &arduboy);
  void Play(int speed, Animation_t *anim);
  void SetPos(int x, int y, Animation_t *anim);
  void SetFrames(Animation_t *anim);
private:
  Arduboy2 *ardu;
  
};



#endif //_Animation_h_
