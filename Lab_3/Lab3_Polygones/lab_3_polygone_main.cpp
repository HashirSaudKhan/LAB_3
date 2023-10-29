#include <iostream>
#include <fstream>
#include <string>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <cmath>

/*
const double PI = 3.14159265358979323846;//This line defines a constant PI with the value of p.

class Point2 {  // simple class representing a 2D point with x and y coordinates.
public: //members can be accessed from outside the class.
    float x, y;

    Point2(float x = 0.0, float y = 0.0) : x(x), y(y) {} //constructor 
};
// The purpose of this function is to draw
// a point on the screen at the coordinates specified by the Point2 object p.
void moveTo(const Point2& p) { //constant reference to a Point2 object named p
    glVertex2f(p.x, p.y);
}

void lineTo(const Point2& p) {
    glVertex2f(p.x, p.y);
}
//ngon is a function that draws an ngon (polygon with n sides) centered at (cx, cy) with a given radius. It also allows for rotation (rotAngle) of the ngon.
//It first checks if the number of sides n is less than 3 (a polygon must have at least 3 sides).
void ngon(int n, double cx, double cy, double radius, double rotAngle) {
    if (n < 3) {
        return;
    }

    glBegin(GL_LINE_LOOP);

    double angle = rotAngle * PI / 180;
    double angleInc = 2 * PI / n;

    Point2 startPoint(cx + radius * cos(angle), cy + radius * sin(angle));
    //The moveTo function is used to set the starting point,
	
    moveTo(startPoint);

    for (int i = 0; i < n; ++i) {
        angle += angleInc;
        Point2 vertex(cx + radius * cos(angle), cy + radius * sin(angle));
        //lineTo function is used to draw lines to the subsequent vertices.
        lineTo(vertex);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); // Set color to red

    int sides = 15;          // N Number of sides in the polygon
    double centerX = 0.0;   // X-coordinate of the center
    double centerY = 0.0;   // Y-coordinate of the center
    double radius = 0.5;    // Radius of the polygon
    double rotation = 30.0; // Rotation angle in degrees

    ngon(sides, centerX, centerY, radius, rotation);

    glFlush();
}

int main(int argc, char** argv) 
{
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ngon");
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glutDisplayFunc(display);
    glutMainLoop();
}
*/


//----------------------------------------------------------------------
//LAB 7 Arc
/*
const double PI = 3.14159265358979323846;

class Point2 {
public:
    float x, y;

    Point2(float x = 0.0, float y = 0.0) : x(x), y(y) {}
};

void moveTo(const Point2& p) {
	glVertex2f(p.x, p.y);
    
}

void lineTo(const Point2& p) {
	glVertex2f(p.x, p.y);
    
}

void drawArc(Point2 center, float radius, float startAngle, float sweep) {
    // StartAngle and sweep are in degrees
    glBegin(GL_LINE_STRIP);
    const int n = 30; // Number of intermediate segments in the arc
    float angle = startAngle * PI / 180; // Initial angle in radians
    float angleInc = sweep * PI / (180 * n); // Angle increment
    float cx = center.x, cy = center.y;
    
    Point2 startPoint(cx + radius * cos(angle), cy + radius * sin(angle));
    //The moveTo function is used to set the starting point,
    moveTo(startPoint);

    //moveTo(Point2(cx + radius * cos(angle), cy + radius * sin(angle)));

    for (int k = 1; k < n; k++, angle += angleInc) {
        Point2 vertex(cx + radius * cos(angle), cy + radius * sin(angle));
        //lineTo function is used to draw lines to the subsequent vertices.
        lineTo(vertex);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); // Set color to black

    // Define the parameters for the arc
    int sides = 30; // Number of sides in the arc
    double centerX = 0.0; //  X-coordinate of the center c
    double centerY = 0.0; // Y-coordinate of the center c
    double radius = 0.5; // R Radius of the arc
    double startAngle = 30.0; // a Starting angle in degrees
    double sweepAngle = 120.0; // b Sweep angle in degrees

    // Call the drawArc function
    drawArc(Point2(centerX, centerY), radius, startAngle, sweepAngle);

    glFlush();
}

int main(int argc, char** argv) {
    // Initialize OpenGL and create a window
    // Set up callbacks and other necessary setup

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Arc Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glutDisplayFunc(display);
    glutMainLoop();

}
*/


//--------------------------------------------------
//Rose Petal
/*
const double PI = 3.14159265358979323846;
const int numPoints = 50; // You can adjust the number of points for smoother or rougher curves
const int n = 2; // Change 'n' to control the number of petals

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Set color to black

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= numPoints; i++) {
        double theta = 2.0 * PI * i / numPoints;
        double x = cos(n * theta) * cos(theta);
        double y = cos(n * theta) * sin(theta);
        glVertex2d(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rose Curve");
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
*/





//--------------------------------------------------------- 
//lab 9 rossete 
/*const double PI = 3.14159265358979323846;

class Point2 {
public:
    float x, y;

    Point2(float x = 0.0, float y = 0.0) : x(x), y(y) {}
};

void moveTo(const Point2& p) {
    glVertex2f(p.x, p.y);
}

void lineTo(const Point2& p) {
    glVertex2f(p.x, p.y);
}

void Rosette(int N, float radius) {
    // Assuming N is the number of vertices in the rosette
    Point2 pt[N];

    // Generate the vertices of the rosette
    for (int i = 0; i < N; i++) {
        double angle = 2.0 * PI * i / N;//This line calculates the angle for the current vertex.
        double x = radius * cos(angle);//This calculates the x-coordinate of the current vertex
        double y = radius * sin(angle);//This calculates the y-coordinate of the current vertex
        pt[i] = Point2(x, y);
    }

    glBegin(GL_LINES);

    // Draw lines to connect all vertices
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            moveTo(pt[i]);
            lineTo(pt[j]);
        }
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 1.0); // Set color to purple 

    int vertices = 5;      // Number of vertices in the rosette
    double rosetteRadius = 0.5;

    // Call the Rosette function
    Rosette(vertices, rosetteRadius);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rosette Example");
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
*/

//-----------------------------------------------------------------------------
// For Circle Curves 
/*
const double PI = 3.14159265358979323846;
const int numSegments = 100; // You can adjust this for the circle's smoothness
float radius = 0.8; // Radius of the circle
float centerX = 0.0; // X-coordinate of the circle's center
float centerY = 0.0; // Y-coordinate of the circle's center

void drawCircle() {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; i++) {
        double angle = 2.0 * PI * i / numSegments;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 1.0); // Set color to pink

    // Call the function to draw the circle
    drawCircle();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Circle Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
*/
