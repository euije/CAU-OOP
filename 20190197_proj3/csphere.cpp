#define GL_SILENCE_DEPRECATION
#include "csphere.h"

void CSphere::init()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glGetDoublev(GL_MODELVIEW_MATRIX, m_mRotate);
    glPopMatrix();
}

void CSphere::setCenter(float x, float y, float z)
{
    center_x = x;
    center_y = y;
    center_z = z;
}

void CSphere::setColor(float r, float g, float b)
{
    color_r = r;
    color_g = g;
    color_b = b;
}

void CSphere::draw(float _sdepth)
{
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -(_sdepth));
    glMultMatrixd(m_mRotate);
    glTranslated(center_x, center_y, center_z);
    glColor3f(color_r, color_g, color_b);
    glutSolidSphere(C_SPHERE_RADIUS, 20, 16);
}