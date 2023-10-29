#include <iostream>
#include <fstream>
#include <GL/freeglut.h>

using std::cout;
using std::fstream;
using std::ios;

//----------------------------------------------------------------------
//DINO 1
/*
const int screenWidth = 640;
const int screenHeight = 480;

void myInit(void)
{
    glClearColor(0.9, 0.9, 0.9, 0.0);//the color is a very light gray
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);// Sets the matrix mode for projection transformations, enabling you to configure how the 3D scene is projected onto a 2D screen or viewport.
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}

void drawPolyLineFile(const char* fileName)
{
	fstream inStream;
    inStream.open(fileName, ios ::in); // open the file
    if(inStream.fail())
	    return;
    glClear(GL_COLOR_BUFFER_BIT); // clear the screen
    GLint numpolys, numLines, x ,y;
    inStream >> numpolys; // read the number of polylines
   for(int j = 0; j < numpolys; j++) // read each polyline
    {
    inStream >> numLines;
    glBegin(GL_LINE_STRIP); // draw the next polyline
    for (int i = 0; i < numLines; i++)
    {
    inStream >> x >> y; // read the next x, y pair
    glVertex2i(x, y);
    }
    glEnd();
    }
    glFlush();
    inStream.close(); 

}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_MODELVIEW);//Sets the matrix mode for modeling transformations, allowing you to control the view and position of objects in 3D space.
    glLoadIdentity();
    drawPolyLineFile("dino.dat");

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Dinosaur Banao");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;

} 
*/







//--------------------------------------------------------------------------
//DINO 2 & 3
//Tiling the display with copies of the dinosaur.
//Multiple Dino
/*
const int screenWidth = 640; // width of screen window in pixels
const int screenHeight = 480; // height of screen window in pixels

//--------------- setWindow ---------------------
void setWindow(float left, float right, float bottom, float top)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left, right, bottom, top);
}
//---------------- setViewport ------------------
void setViewport(float left, float right, float bottom, float top)
{
    glViewport(left, bottom, right - left, top - bottom);
}

void myInit(void)
{
    glClearColor(0.9, 0.9, 0.9, 0.0); // background color is light gray
    glMatrixMode(GL_PROJECTION); // set "camera shape"
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}
void drawPolyLineFile(const char* fileName)
{
    std::ifstream inStream;
    inStream.open(fileName, std::ios::in);// open the file
    if (inStream.fail())
        return;
    GLint numpolys, numLines, x, y;
    inStream >> numpolys; //read the number of polylines 
    for (int j = 0; j < numpolys; j++) // read each polyline
    {
        inStream >> numLines;
        glBegin(GL_LINE_STRIP); // draw the next polyline
        for (int i = 0; i < numLines; i++)
        {
            inStream >> x >> y; // read the next x,y pair
            glVertex2i(x, y);
        }
        glEnd();
    }
    inStream.close();
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    
    setWindow(0, 640.0, 0, 480.0);
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 2; j++) {
             //glViewport(i * 64, j * 44, 64, 44);
            if ((i + j) % 2 == 0) {

                setWindow(0, 640.0, 0, 480.0);
            }

            else {
                setWindow(0, 640.0, 480.0, 0);

            }
            glViewport(j * 64, i * 44, 64, 44);
            drawPolyLineFile("dino.dat");//purpose is to draw a set of polylines based on the data stored in the "dino.dat" file.
        }
    }
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Dinosaur Grid");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}
*/





//-----------------------------------------------------------------------------
//DINO 04
//Zooming in and Zooming out on a figure
/*
const int screenWidth = 640;
const int screenHeight = 480;
GLfloat zoomFactor = 1.0; // Initial zoom factor

void myInit(void)
{
    glClearColor(0.9, 0.9, 0.9, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}

void drawPolyLineFile(const char* fileName)
{
    fstream inStream;
    inStream.open(fileName, ios::in);
    if (inStream.fail())
        return;
    glClear(GL_COLOR_BUFFER_BIT);
    GLint numpolys, numLines, x, y;
    inStream >> numpolys;
    for (int j = 0; j < numpolys; j++)
    {
        inStream >> numLines;
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < numLines; i++)
        {
            inStream >> x >> y;
            glVertex2i(x, y);
        }
        glEnd();
    }
    glFlush();
    inStream.close();
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(zoomFactor, zoomFactor, 1.0); // Apply the zoom factor

    drawPolyLineFile("dino.dat");

    glFlush();
}

void myKeyboard(unsigned char key, int x, int y)
{
    if (key == '+')
    {
        zoomFactor *= 1.1; // Zoom in by increasing the zoom factor
    }
    else if (key == '-')
    {
        zoomFactor /= 1.1; // Zoom out by decreasing the zoom factor
    }
    glutPostRedisplay(); // Redraw the scene with the updated zoom factor
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Dinosaur Banao");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(myKeyboard); // Register the keyboard function
    myInit();
    glutMainLoop();
    return 0;

} 
*/




//------------------------------------------------------------------
//DINO 5
//Make a Viewport Dynamic.( Output is attached) i.e Roaming a.k.a Panning (To move the view in a specific direction ).
/*
const int screenWidth = 640;
const int screenHeight = 480;
int ViewportXmin = 0;
int ViewportXmax = screenWidth;
int ViewportYmin = 0;
int ViewportYmax = screenHeight;
int ReferenceX = 0;
int ReferenceY = 0;

//---------------- setViewport ------------------
void setViewport()
{
    glViewport(ViewportXmin, ViewportYmin, ViewportXmax - ViewportXmin, ViewportYmax - ViewportYmin);
}

void myMouse(int button, int state, int x, int y)
{
    // Remember the location of the mouse when the button was pressed
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        ReferenceX = x;
        ReferenceY = y;
    }
}

void myMotion(int x, int y)
{
    // Translate the Viewport according to the distance from the reference
    int dx = x - ReferenceX;
    int dy = y - ReferenceY; // because the y axis is down

    ViewportXmin += dx;
    ViewportXmax += dx;
    ViewportYmin -= dy;
    ViewportYmax -= dy;
    setViewport();

    ReferenceX = x;
    ReferenceY = y;

    glutPostRedisplay();
}

void mykeys(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'u':
            // Adjust the viewport by increasing the Y values
            ViewportYmin += 2;
            ViewportYmax += 2;
            setViewport();
            glutPostRedisplay();
            break;
    }
}

void myInit(void)
{
    glClearColor(0.9, 0.9, 0.9, 0.0); // the color is a very light gray
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}

void drawPolyLineFile(const char *fileName)
{
    std::fstream inStream;
    inStream.open(fileName, std::ios::in);
    if (inStream.fail())
        return;
    glClear(GL_COLOR_BUFFER_BIT);
    GLint numpolys, numLines, x, y;
    inStream >> numpolys;
    for (int j = 0; j < numpolys; j++)
    {
        inStream >> numLines;
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < numLines; i++)
        {
            inStream >> x >> y;
            glVertex2i(x, y);
        }
        glEnd();
    }
    glFlush();
    inStream.close();
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawPolyLineFile("dino.dat");
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Dinosaur Banao");
    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);
    glutKeyboardFunc(mykeys);
    myInit();
    glutMainLoop();
    return 0;
}
*/


