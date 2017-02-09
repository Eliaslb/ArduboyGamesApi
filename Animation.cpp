#include "Animation.h"

void Animation::Play(int speed, Animation_t *anim){
  if (ardu->everyXFrames(speed) && anim->frame != anim->length + 1 && anim->playing == true) {
    anim->frame += 1;    
  }

  if (ardu->everyXFrames(speed && anim->frame == anim->length + 1 && anim->playing == true)) {
    anim->frame = 0;  
  }
  
  if (anim->playing == true) {
    ardu->drawBitmap(anim->x,anim->y,anim->Frames[anim->frame]->bitmap,anim->Frames[anim->frame]->bitmapwidth,anim->Frames[anim->frame]->bitmapheight,anim->Frames[anim->frame]->color);    
  }

}

void Animation::SetPos(int x, int y, Animation_t *anim) {
  x = anim->x;    
  y = anim->y;
}

void Animation::SetFrames(Animation_t *anim){
  
}

