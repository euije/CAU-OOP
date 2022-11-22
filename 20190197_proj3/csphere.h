#ifndef C_SHPERE_H
#define C_SHPERE_H

#include <glut.h>
#define C_SPHERE_RADIUS 0.5

/**
 * @brief CSphere의 반지름은 0.5이다.
 * 
 */
class CSphere
{
public:
    float center_x, center_y, center_z;
    float color_r, color_g, color_b;
    float dir_x, dir_y, dir_z;
    float speed;

public:
    GLdouble m_mRotate[16];
    CSphere()
    {
        center_x = center_y = center_z = 0.0;
    }

    void init();
    void setCenter(float x, float y, float z);
    void setColor(float r, float g, float b);
    void draw(float _sdepth);
};

#endif