#include "Physics.h"

int Physics::Raycast(Point pos, int direction, int color){
  int result;
  if (direction == 0) {
    for (int i = 0; i < SCREENHEIGHT - pos.y; i++) {
      
      if (ardu->getPixel(pos.x,pos.y + i) == color) {
        result = pos.y + i;
        return result - pos.y;
      } else {
        return 0;
      }
      
    }
    
  } else if (direction == 2)  {
    for (int i = 0; i < SCREENWIDTH - pos.x; i++) {
      
      if (ardu->getPixel(pos.x + i,pos.y) == color) {
        result = pos.x + i;
        return result - pos.x;
      } else {
        return 0;
      }
      
    }    
  } else if (direction == 1)  {
    for (int i = 0; i < SCREENWIDTH - pos.x; i++) {
      
      if (ardu->getPixel(pos.x - i,pos.y) == color) {
        result = pos.x - i;
        return result - pos.x;
      } else {
        return 0;
      }
      
    }    
  } else if (direction == 3)  {
    for (int i = 0; i < SCREENHEIGHT - pos.y; i++) {
      
      if (ardu->getPixel(pos.x,pos.y - i) == color) {
        result = pos.y - i;
        return result - pos.y;
      } else {
        return 0;
      }
      
    }    
  }
}

bool Physics::Pixelcollide(Point pos, int bitmapheight, int bitmapwidth, int direction, int color, int distance){
  if (direction == 0) {//DOWN
    pos.y += bitmapheight;
    for (int i = 0; i < bitmapwidth; i++) {
      pos.x += i;
      if (Raycast(pos,1,color) == distance) {
        return true;      
      }
    }
  } else if (direction == 1) {//LEFT
      for (int i = 0; i < bitmapheight; i++) {
        pos.y += i;
        if (Raycast(pos,1,color) == distance) {
          return true;      
        }
      } 
  } else if (direction == 2) {//RIGHT
      pos.x += bitmapwidth;
      for (int i = 0; i < bitmapheight; i++) {        
        pos.y += i;
        if (Raycast(pos,1,color) == distance) {
          return true;      
        }
      }  
  } else if (direction == 3) {//UP
      for (int i = 0; i < bitmapwidth; i++) {
        pos.x += i;
        if (Raycast(pos,1,color) == distance) {
          return true;      
        }
      }   
  }
}

