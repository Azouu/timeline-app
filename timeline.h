#ifndef TIMELINE_H
#define TIMELINE_H

class Timeline
{ 
    private :
    int nbFrames;
    int frameIndex;

    public :
    Timeline(int nbFrames);
    int getNbFrames();
    int getFrameIndex();
    void setFrameIndex(int newIndex);
    void incrFrameIndex();
    void decrFrameIndex();
};

#endif 