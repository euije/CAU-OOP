#define GL_SILENCE_DEPRECATION
#include "cwall.h"

void CWall::init()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glGetDoublev(GL_MODELVIEW_MATRIX, m_mRotate);
    glPopMatrix();
}

void CWall::setSize(float w, float h, float d)
{
    width = w;
    height = h;
    depth = d;
}

void CWall::setCenter(float x, float y, float z)
{
    center_x = x;
    center_y = y;
    center_z = z;
}

void CWall::setColor(float r, float g, float b)
{
    color_r = r;
    color_g = g;
    color_b = b;
}

void CWall::draw(float _sdepth, int _cubeIndices[][4], GLfloat _bNorms[][3])
{
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -(_sdepth));
    glMultMatrixd(m_mRotate);
    glTranslatef(center_x, center_y, center_z);

    glColor3f(color_r, color_g, color_b);

    int i;
    int v1, v2, v3, v4;

    for (i = 0; i < 6; i++)
    {
        v1 = _cubeIndices[i][0];
        v2 = _cubeIndices[i][1];
        v3 = _cubeIndices[i][2];
        v4 = _cubeIndices[i][3];

        glBegin(GL_QUADS);
        glNormal3f(_bNorms[i][0], _bNorms[i][1], _bNorms[i][2]);
        glVertex3f(this->Verts[v1][0], this->Verts[v1][1], this->Verts[v1][2]);
        glNormal3f(_bNorms[i][0], _bNorms[i][1], _bNorms[i][2]);
        glVertex3f(this->Verts[v2][0], this->Verts[v2][1], this->Verts[v2][2]);
        glNormal3f(_bNorms[i][0], _bNorms[i][1], _bNorms[i][2]);
        glVertex3f(this->Verts[v3][0], this->Verts[v3][1], this->Verts[v3][2]);
        glNormal3f(_bNorms[i][0], _bNorms[i][1], _bNorms[i][2]);
        glVertex3f(this->Verts[v4][0], this->Verts[v4][1], this->Verts[v4][2]);
        glEnd();
    }
}