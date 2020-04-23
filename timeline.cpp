#include "timeline.h"

Timeline::Timeline(int nbFrames)
{
   this->nbFrames = nbFrames;
   this->frameIndex = 0;
}

int Timeline::getNbFrames() {
    return nbFrames;
}

int Timeline::getFrameIndex() {
    return frameIndex;
}

void Timeline::setFrameIndex(int newIndex) {
    if (newIndex >= nbFrames) {newIndex = nbFrames - 1;}
    if (newIndex < 0) {newIndex = 0;}
    this->frameIndex = newIndex;
}

void Timeline::incrFrameIndex() {
    if (frameIndex < nbFrames - 1)
        frameIndex++;
}

void Timeline::decrFrameIndex() {
    if (frameIndex > 0) 
        frameIndex--;
}