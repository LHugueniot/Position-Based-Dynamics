#ifndef TRACKBALLCAM_H
#define TRACKBALLCAM_H


class trackBallCam
{
public:
    trackBallCam();
    ~trackBallCam();

    void rotate();
    void zoom();
    void translate();
    void update();
};

#endif // TRACKBALLCAM_H
