/* Simple geometry viewer:  Left mouse: rotate;  Right mouse:   translate;  ESC to quit. */
#define GL_SILENCE_DEPRECATION
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <glut.h>
// you may try "#include <GL/glut.h>" if "#include <GLUT/glut.h>" wouldn't work
//#include <GL/glut.h>

#include <cmath>
#include "csphere.h"
#include "cwall.h"

#define WALL_WIDTH 1.0

#define COLOR_WHITE 1.0, 1.0, 1.0
#define COLOR_RED 0.8, 0.2, 0.2
#define COLOR_GREEN 0.15, 0.4, 0.15
#define COLOR_GRAY 0.15, 0.15, 0.15
#define COLOR_YELLOW 1.0, 0.83, 0.0

// GLdouble rotMatrix[4][16];
const int NO_SPHERE = 2;
const int NUM_OBSTACLES = 15;
const int WALL_ID = 1000;

int rotate_x = 0, rotate_y = 80;
int choice = 1;

GLfloat BoxVerts[][3] = {
    {-1.0, -1.0, -1.0},
    {-1.0, -1.0, 1.0},
    {-1.0, 1.0, -1.0},
    {-1.0, 1.0, 1.0},
    {1.0, -1.0, -1.0},
    {1.0, -1.0, 1.0},
    {1.0, 1.0, -1.0},
    {1.0, 1.0, 1.0}};

GLfloat bNorms[][3] = {
    {-1.0, 0.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {0.0, -1.0, 0.0},
    {0.0, 0.0, -1.0},
    {0.0, 0.0, 1.0}};

int cubeIndices[][4] = {
    {0, 1, 3, 2},
    {4, 6, 7, 5},
    {2, 3, 7, 6},
    {0, 4, 5, 1},
    {0, 2, 6, 4},
    {1, 5, 7, 3}};

/* Viewer state */
float sdepth = 20;
float zNear = 1.0, zFar = 100.0;
float aspect = 5.0 / 2.0;
float xcam = 1000, ycam = 1000;
long xsize, ysize;
int downX, downY;
bool leftButton = false, middleButton = false, rightButton = false;
int i, j;
GLfloat light0Position[] = {0, 1, 0, 1.0};
int displayMenu, mainMenu;

void MyIdleFunc(void) { glutPostRedisplay(); } /* things to do while idle */
void RunIdleFunc(void) { glutIdleFunc(MyIdleFunc); }
void PauseIdleFunc(void) { glutIdleFunc(NULL); }
void renderScene();

// ----------------------------------------------------------------
/**
 * 게임 오브젝트 및 Status 관련 변수
 */

int space_flag = 0;
int game_start_flag = 0;

CSphere g_sphere[2];
CSphere obstacles[NUM_OBSTACLES];
CWall g_wall(BoxVerts, 10.0, 0.2, 20.0);
CWall g_wallL(BoxVerts, WALL_WIDTH, 1.0, 20.0);
CWall g_wallR(BoxVerts, WALL_WIDTH, 1.0, 20.0);
CWall g_wallT(BoxVerts, 12.0, 1.0, WALL_WIDTH);

typedef struct Vector2
{
    float x;
    float z;
    Vector2(float _x = 0.0, float _z = 0.0)
    {
        x = _x;
        z = _z;
    }
    friend Vector2 operator*(const float &_const, const Vector2 &operand)
    {
        return Vector2(_const * operand.x, _const * operand.z);
    }
    friend Vector2 operator-(const Vector2 &op1, const Vector2 &op2)
    {
        return Vector2(op1.x - op2.x, op2.x - op2.z);
    }
    float size()
    {
        return sqrt(pow(x, 2) + pow(z, 2));
    }
    float innerProduct(Vector2 operand)
    {
        return x * operand.x + z * operand.z;
    }
    Vector2 reversed()
    {
        return Vector2(-x, -z);
    }
    Vector2 symmetrical(Vector2 line)
    {
        Vector2 _line = (1.0 / line.size()) * this->size() * this->innerProduct(line) / (this->size() * line.size()) * line;

        return (2.0 * _line) - (*this);
    }
} Vector2;
bool isCollision2DSphereAndWall(CSphere sphere, CWall wall, char axis1 = 'x', char axis2 = 'z')
{
    Vector2 distance = Vector2(wall.center_x - sphere.center_x, wall.center_z - sphere.center_z);
    Vector2 normalOfWall = Vector2(wall.center_x, wall.center_z);
    float d = distance.size();
    float h = normalOfWall.size();
    return abs(d * distance.innerProduct(normalOfWall) / d * h) <= C_SPHERE_RADIUS + WALL_WIDTH / 2;
}
// ----------------------------------------------------------------

void ReshapeCallback(int width, int height)
{
    xsize = width;
    ysize = height;
    aspect = (float)xsize / (float)ysize;
    glViewport(0, 0, xsize, ysize);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(64.0, aspect, zNear, zFar);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutPostRedisplay();
}

void DisplayCallback(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    for (i = 0; i < NO_SPHERE; i++)
        g_sphere[i].draw(sdepth);

    for (i = 0; i < NUM_OBSTACLES; i++)
        obstacles[i].draw(sdepth);

    g_wall.draw(sdepth, cubeIndices, bNorms);
    g_wallL.draw(sdepth, cubeIndices, bNorms);
    g_wallR.draw(sdepth, cubeIndices, bNorms);
    g_wallT.draw(sdepth, cubeIndices, bNorms);

    glutSwapBuffers();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void KeyboardCallback(unsigned char ch, int x, int y)
{
    if('1' <= ch && ch <= '2')
        choice = ch - '0';
    else if('a' <= ch && ch <= 'o')
        choice = 10 + ch - 'a';

    switch (ch)
    {
    case 32:
        if (space_flag)
        {
            space_flag = 0;
        }
        else
        {
            space_flag = 1;
            if (!game_start_flag)
            {
                g_sphere[1].dir_z = -5.0;
                g_sphere[1].dir_x = g_sphere[1].center_x < 0 ? -4.0 : 4.0;
                game_start_flag = 1;
            }
        }
        break; // SPACE_KEY

    case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void MouseCallback(int button, int state, int x, int y)
{
    downX = x;
    downY = y;
    leftButton = ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN));
    middleButton = ((button == GLUT_MIDDLE_BUTTON) && (state == GLUT_DOWN));
    rightButton = ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN));
    glutPostRedisplay();
}

void rotate(int id)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glRotated(((double)rotate_y), 1.0, 0.0, 0.0);
    glRotated(((double)rotate_x), 0.0, 1.0, 0.0);

    if (id < NO_SPHERE)
    {
        glGetDoublev(GL_MODELVIEW_MATRIX, g_sphere[id].m_mRotate);
    }
    else if (10 <= id && id < 10 + NUM_OBSTACLES)
    {
        glGetDoublev(GL_MODELVIEW_MATRIX, obstacles[id - 10].m_mRotate);
    }
    else if (id == WALL_ID)
    {
        glGetDoublev(GL_MODELVIEW_MATRIX, g_wall.m_mRotate);
    }
    else if (id == 1001)
    {
        glGetDoublev(GL_MODELVIEW_MATRIX, g_wallL.m_mRotate);
    }
    else if (id == 1002)
    {
        glGetDoublev(GL_MODELVIEW_MATRIX, g_wallR.m_mRotate);
    }
    else if (id == 1003)
    {
        glGetDoublev(GL_MODELVIEW_MATRIX, g_wallT.m_mRotate);
    }
    glPopMatrix();
}

void MotionCallback(int x, int y)
{
    int tdx = x - downX, tdy = 0, tdz = y - downY;
    if (rightButton)
    {
        rotate_x += x - downX;
        rotate_y += y - downY;
        for (i = 0; i < NO_SPHERE; i++)
            rotate(i);

        for (i = 0; i < NUM_OBSTACLES; i++)
            rotate(i + 10);

        rotate(WALL_ID);
        rotate(1001);
        rotate(1002);
        rotate(1003);
    }
    else if (leftButton)
    {
        if (choice < NO_SPHERE)
            g_sphere[choice].setCenter(g_sphere[choice].center_x + tdx / 100.0, g_sphere[choice].center_y + tdy / 100.0, g_sphere[choice].center_z + tdz / 100.0);
        else if (10 <= choice && choice < 25)
            obstacles[choice - 10].setCenter(obstacles[choice - 10].center_x + tdx / 100.0, obstacles[choice - 10].center_y + tdy / 100.0, obstacles[choice - 10].center_z + tdz / 100.0);
    }
    downX = x;
    downY = y;
    glutPostRedisplay();
}

void PassiveMotionCallback(int x, int y)
{
    g_sphere[0].setCenter(
        x / 34.0 - 15.0,
        0,
        10.5);
    if (!game_start_flag)
    {
        g_sphere[1].setCenter(
            x / 34.0 - 15.0,
            0,
            9.5);
    }
}

void initRotate()
{
    g_sphere[0].init();
    g_sphere[1].init();

    for (int i = 0; i < NUM_OBSTACLES; i++)
        obstacles[i].init();

    g_wall.init();
    g_wallL.init();
    g_wallR.init();
    g_wallT.init();

    // Setting Objects to Camera perspective
    for (int i = 0; i < NO_SPHERE; i++)
        rotate(i);

    for (int i = 0; i < NUM_OBSTACLES; i++)
        rotate(i + 10);

    rotate(WALL_ID);
    rotate(1001);
    rotate(1002);
    rotate(1003);
}

void InitGL()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("OpenGL Applications");
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glPolygonOffset(1.0, 1.0);
    glDisable(GL_CULL_FACE);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
    glEnable(GL_LIGHT0);
    initRotate();

    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);

    glutIdleFunc(renderScene);
    glutReshapeFunc(ReshapeCallback);
    glutDisplayFunc(DisplayCallback);
    glutKeyboardFunc(KeyboardCallback);
    glutMouseFunc(MouseCallback);
    glutMotionFunc(MotionCallback);
    glutPassiveMotionFunc(PassiveMotionCallback);
}

int currentTime, previousTime = -1;
void renderScene()
{
    int timeDelta;
    currentTime = glutGet(GLUT_ELAPSED_TIME);
    if (previousTime == -1)
        timeDelta = 0;
    else
        timeDelta = currentTime - previousTime;

    float x = g_sphere[1].center_x;
    float y = g_sphere[1].center_y;
    float z = g_sphere[1].center_z;

    if (game_start_flag)
    {
        g_sphere[1].center_x = x + timeDelta * 0.002 * g_sphere[1].dir_x;
        g_sphere[1].center_z = z + timeDelta * 0.002 * g_sphere[1].dir_z;
    }

    if (z > 11.5 || z < -11.5 || x > 6.5 || x < -6.5)
    {
        game_start_flag = 0;
        space_flag = 0;
    }

    if (game_start_flag)
    {
        // if (isCollision2DSphereAndWall(g_sphere[1], g_wallT, 'x', 'z'))
        if (g_sphere[1].center_z <= g_wallT.center_z + (WALL_WIDTH / 2 + C_SPHERE_RADIUS))
        {
            g_sphere[1].dir_z = -g_sphere[1].dir_z;
        }
        // if (isCollision2DSphereAndWall(g_sphere[1], g_wallL, 'x', 'z'))
        else if (g_sphere[1].center_x <= g_wallL.center_x + (WALL_WIDTH / 2 + C_SPHERE_RADIUS))
        {
            g_sphere[1].dir_x = -g_sphere[1].dir_x;
        }
        // if (isCollision2DSphereAndWall(g_sphere[1], g_wallR, 'x', 'z'))
        else if (g_sphere[1].center_x >= g_wallR.center_x - (WALL_WIDTH / 2 + C_SPHERE_RADIUS))
        {
            g_sphere[1].dir_x = -g_sphere[1].dir_x;
        }
        else if (pow(g_sphere[1].center_x - g_sphere[0].center_x, 2) + pow(g_sphere[1].center_z - g_sphere[0].center_z, 2) <= 1.0)
        {
            g_sphere[1].dir_z = -g_sphere[1].dir_z;
        }
        for (int i = 0; i < NUM_OBSTACLES; i++)
        {
            if (pow(g_sphere[1].center_x - obstacles[i].center_x, 2) + pow(g_sphere[1].center_z - obstacles[i].center_z, 2) <= 1.0)
            {
                obstacles[i].setCenter(10.0, 0.0, 10.0);
                if (abs(g_sphere[1].center_z - obstacles[i].center_z) <= 1.0)
                    g_sphere[1].dir_x = -g_sphere[1].dir_x;
                else
                    g_sphere[1].dir_z = -g_sphere[1].dir_z;
            }
        }
    }
    glutPostRedisplay();
    previousTime = currentTime;
}

void InitObjects()
{
    // White, Cusion Sphere
    g_sphere[0].setColor(COLOR_WHITE);
    g_sphere[0].setCenter(0.0, 0.0, 0.0);

    // Red, Main Sphere
    g_sphere[1].setColor(COLOR_RED);
    g_sphere[1].setCenter(0.0, 0.0, 0.0);

    for (int i = 0; i < 8; i++)
    {
        obstacles[i].setColor(COLOR_YELLOW);
        obstacles[i].setCenter(-4.0 + (float)i, 0.0, -6.0 + (float)i);
    }
    for (int i = 8; i < NUM_OBSTACLES; i++)
    {
        if (i == 12)
            continue;
        obstacles[i].setColor(COLOR_YELLOW);
        obstacles[i].setCenter(4.0 - (float)(i - 8), 0.0, -6.0 + (float)(i - 8));
    }
    obstacles[12].setColor(COLOR_YELLOW);
    obstacles[12].setCenter(-3.0, 0.0, 1.0);

    // specify initial colors and center positions of a wall
    g_wall.setColor(COLOR_GREEN);
    g_wall.setCenter(0.0, -0.6, 0.0);

    g_wallL.setColor(COLOR_GRAY);
    g_wallL.setCenter(-5.5, 0.0, 0.0);

    g_wallR.setColor(COLOR_GRAY);
    g_wallR.setCenter(5.5, 0.0, 0.0);

    g_wallT.setColor(COLOR_GRAY);
    g_wallT.setCenter(0, 0.0, -10.5);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    InitObjects();
    InitGL();
    glutMainLoop();
    return 0;
}