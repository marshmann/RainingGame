#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

float pi= 3.1415925359;
void gridLines(void);
void idle(void);
void keyboard(char key);
void fallingMan(float x, float y);
void catcher(float x1);
unsigned int randNum(void);


int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
  glutInitWindowPosition(0,0);
  glutInitWindowSize(450,550);
  glutCreateWindow("It's Raining Men!");

  glutDisplayFunc(gridLines);
  glutIdleFunc(idle);
  glutKeyboardFunc(keyboard);

  glutMainLoop();
}

float x = 0.0, y = -0.705, x1 = -1.0, y1 = 0.0;
int count = 0; int num = 0; float amount = 0.0009;
int score = 0; int miss = 0;
void idle(void) {
  y -= amount;
  if(count == 0){
    printf("%s\n", "Your current score will display here.");
    printf("%s\n", "If you miss three, it's game over!");
    y = 1;
    num = randNum();
    count++;
    amount += 0.0002;
  }
  if(y <= -1.4){
    if(num == 1 && (-1.0 <= x1 && x1 <= -0.85)){
      score++;
      printf("%s", "Current Score: ");
      printf("%d\n", score); 

    }
    else if(num == 2 && (x1 > -0.55 && x1 <= -0.4f)){
      score++;
      printf("%s", "Current Score: ");
      printf("%d\n", score);
    }
    else if(num == 3 && (0.34 > x1 && x1 > -0.1)){
      score++;
      printf("%s", "Current Score: ");
      printf("%d\n", score);
    }
    else if(num == 4 && (0.4 <= x1 && x1 < 0.7)){
      score++;
      printf("%s", "Current Score: ");
      printf("%d\n", score);
    }
    else{ 
      miss++;
      if(miss == 1){
        printf("%s\n", "You've let a man die this day.");
      }
      if(miss ==2){
        printf("%s\n", "You've let two men die this day.  You should feel bad.");
      }
      if(miss == 3){
        printf("%s\n", "That's enough death for today; terminating program.");
        printf("%s", "Your final score was: ");
        printf("%d\n", score);
        exit(0);
       }
    }
    y = 1;
    num = randNum();
    count++;
    amount += 0.0002;
  }
  switch(num){
  case 1: 
    x = 0.05;
    fallingMan(x,y);
    break;
  case 2:
    x = 0.55;
    fallingMan(x,y);
    break;
  case 3: 
    x = 1.05;
    fallingMan(x,y);
    break;
  case 4:
    x = 1.55;
    fallingMan(x,y);
    break;
  default:
    break;
  }
  catcher(0.9 + x1);
  glutPostRedisplay();

}
void keyboard(char key) {
  switch(key){
  case 033:
    exit(0);
    break;
  case 'a': case 'w':
    x1 -= 0.15;
    break;
  case 's': case 'd':
    x1 += 0.15;
    break;
  default:
    break;
  }
  glutPostRedisplay();
}
void fallingMan(float x, float y) {
  glClearColor(1.0,1.0,1.0,1.0);  
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0,0.0,0.0);

  glBegin(GL_POLYGON);
  for(int i = 0; i<=3000; i++){
    float theta = 2*pi*i/3000;
    glVertex2d(0.05*cos(theta) - 0.9 + x,0.04*sin(theta) + 0.75 + y);
  }
  glEnd();
 
  glLineWidth(5);
  glBegin(GL_LINES);
  glVertex2f(-0.9 + x,0.75 + y);
  glVertex2f(-0.78 + x,0.67 + y);
  
  glEnd();
  glLineWidth(2.5);
  glBegin(GL_LINES);

  glVertex2f(-0.84 + x, 0.71 + y);
  glVertex2f(-0.82 + x, 0.775 + y);

  glVertex2f(-0.84 + x, 0.71 + y);
  glVertex2f(-0.88 + x, 0.69 + y);

  glVertex2f(-0.88 + x, 0.69 + y);
  glVertex2f(-0.88 + x, 0.66 + y);

  glEnd();

  glLineWidth(4);
  glBegin(GL_LINES);

  glVertex2f(-0.78 + x,0.67 + y);
  glVertex2f(-0.74 + x, 0.7 + y);

  glVertex2f(-0.74 + x, 0.7 + y);
  glVertex2f(-0.68 + x, 0.67 + y);

  glVertex2f(-0.78 + x,0.67 + y);
  glVertex2f(-0.76 + x, 0.72 + y);

  glVertex2f(-0.76 + x, 0.72 + y);
  glVertex2f(-0.7 + x, 0.73 + y);
  glEnd();
 
  //Falling Lines on the Man
  glLineWidth(1); 
  glColor3f(0.5,0.5,0.5);
  glBegin(GL_LINES);

  glVertex2f(-0.91 + x,0.9 + y);
  glVertex2f(-0.91 + x,0.825 + y);
  glVertex2f(-0.81 + x,0.9 + y);
  glVertex2f(-0.81 + x,0.825 + y);
  glVertex2f(-0.71 + x,0.9 + y);
  glVertex2f(-0.71 + x,0.825 + y);
  glEnd();
}

void catcher(float x1) {
  glColor3f(0.5,0.0,0.0);
  glBegin(GL_POLYGON);
  for(int i = 0; i<=3000; i++){
    float theta = 2*pi*i/3000;
    glVertex2d(0.05*cos(theta) - 0.75 + x1,0.04*sin(theta) -0.75 + y1);
  }
  glEnd();

  glBegin(GL_POLYGON);
  glVertex2d(0.05*cos(2*pi*3.0/4.0) - 0.75 + x1, 0.04*sin(2*pi*3.0/4.0)-0.735 + y1);
  glVertex2f(-0.7 + x1,-0.9 + y1);
  glVertex2f(-0.8 + x1,-0.9 + y1);
  glEnd();

  glLineWidth(2);
  glBegin(GL_LINES);
  glVertex2f(-0.765 + x1,-0.9 + y1);
  glVertex2f(-0.765 + x1,-0.95 + y1);

  glVertex2f(-0.735 + x1,-0.9 + y1);
  glVertex2f(-0.735 + x1,-0.95 + y1);
 
  glVertex2f(-0.74 + x1,-0.8 + y1);
  glVertex2f(-0.64 + x1,-0.72 + y1);

  glVertex2f(-0.76 + x1,-0.8 + y1);
  glVertex2f(-0.86 + x1,-0.72 + y1);
  glEnd();

}
unsigned int randNum(void) {
  double s = (double)rand()/RAND_MAX;
  return (4)*s+1;
}
void gridLines(void) {

  //Grid Lines
  /*
  glLineWidth(1);
  glBegin(GL_LINES);
  glVertex2f(-0.5,1);
  glVertex2f(-0.5,-1);

  glVertex2f(0.0,1);
  glVertex2f(0.0,-1);

  glVertex2f(0.5,1);
  glVertex2f(0.5,-1);

  glVertex2f(1,-0.705);
  glVertex2f(-1,-0.705);
  glEnd();
 */
  glFlush();
}
