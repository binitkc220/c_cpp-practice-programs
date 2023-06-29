#include <graphics.h>
#include <math.h>

#define PI 3.14159265

void drawCube(float angle);

int main() {
  int gm, gd=DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
	initgraph(&gd,&gm,data);

  while (1) {
    cleardevice();
    drawCube(30.0);
    delay(100);
  }

  getch();
  closegraph();
  return 0;
}

void drawCube(float angle) {
  float vertices[8][3] = {
    {-1, -1, -1},
    {-1, -1, 1},
    {-1, 1, -1},
    {-1, 1, 1},
    {1, -1, -1},
    {1, -1, 1},
    {1, 1, -1},
    {1, 1, 1}
  };

  int edges[12][2] = {
    {0, 1},
    {0, 2},
    {0, 4},
    {1, 3},
    {1, 5},
    {2, 3},
    {2, 6},
    {3, 7},
    {4, 5},
    {4, 6},
    {5, 7},
    {6, 7}
  };

  float rotationMatrix[3][3] = {
    {cos(angle * PI / 180), -sin(angle * PI / 180), 0},
    {sin(angle * PI / 180), cos(angle * PI / 180), 0},
    {0, 0, 1}
  };

  float translatedVertices[8][3];
  int i, j;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 3; j++) {
      translatedVertices[i][j] = vertices[i][j];
    }
    float x = vertices[i][0];
    float y = vertices[i][1];
    float z = vertices[i][2];
    translatedVertices[i][0] = rotationMatrix[0][0] * x + rotationMatrix[0][1] * y + rotationMatrix[0][2] * z;
    translatedVertices[i][1] = rotationMatrix[1][0] * x + rotationMatrix[1][1] * y + rotationMatrix[1][2] * z;
    translatedVertices[i][2] = rotationMatrix[2][0] * x + rotationMatrix[2][1] * y + rotationMatrix[2][2] * z;
  }

  int sx[8], sy[8];
  for (i = 0; i < 8; i++) {
    float x = translatedVertices[i][0];
    float y = translatedVertices[i][1];
    float z = translatedVertices[i][2];
    sx[i] = 200 + 50 * x / (1 - z);
    sy[i] = 200 + 50 * y / (1 - z);
  }

  for (i = 0; i < 12; i++) {
    int v1 = edges[i][0];
    int v2 = edges[i][1];
    line(sx[v1], sy[v1], sx[v2], sy[v2]);
  }
}
