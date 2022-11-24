#ifndef LEVEL_H
#define LEVEL_H

void setup(field& poligonFirst, object& snake, object& fruit, int& score);
void drow(field& poligonFirst, object& snake, object& fruit, const int score, const int nTail, int*& tailX, int*& tailY);
void input(bool& flag);
void logic(field& poligonFirst, object& snake, object& fruit, int& score, bool& flag, int& nTail, int*& tailX, int*& tailY, int& size, int& setting_wall);
#endif