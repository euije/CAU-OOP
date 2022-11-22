#ifndef C_WALL_H
#define C_WALL_H

#include <glut.h>

class            CWall
{
public:
    float width, height, depth;
    float center_x, center_y, center_z;
    float color_r, color_g, color_b;

    GLfloat Verts[8][3];

public:
    GLdouble m_mRotate[16];
    CWall(GLfloat _BoxVerts[][3], float w = 0.0, float h = 0.0, float d = 0.0)
    {
        width = w;
        height = h;
        depth = d;
        color_r = 0.0;
        color_g = 1.0;
        color_b = 0.0;

        int i, j;
        float coef;
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (j == 0)
                    coef = w / 2.0;
                if (j == 1)
                    coef = h / 2.0;
                if (j == 2)
                    coef = d / 2.0;
                Verts[i][j] = coef * _BoxVerts[i][j];
            }
        }
    }

    void init();
    void setSize(float w, float h, float d);
    void setCenter(float x, float y, float z);
    void setColor(float r, float g, float b);
    void draw(float _sdepth, int _cubeIndices[][4], GLfloat _bNorms[][3]);
};

#endif // !C_WALL_H