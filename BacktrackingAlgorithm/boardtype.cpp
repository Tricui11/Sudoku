#include<point.cpp>

#define DIMENSION 9
#define NCELLS DIMENSION*DIMENSION

typedef struct
{
    int m[DIMENSION][DIMENSION];
    int freecount;
    Point move[NCELLS+1];
} BoardType;
