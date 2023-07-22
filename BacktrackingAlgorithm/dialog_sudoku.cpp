/*
#define MAXCANDIDATES 9

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    finished = false;
    int A[NCELLS];
    BoardType *board = new BoardType();
    board->freecount = 81 - 17;
    board->m[7][0] = 1;
    board->m[8][0] = 2;
    board->m[4][1] = 3;
    board->m[5][1] = 5;
    board->m[3][2] = 6;
    board->m[7][2] = 7;
    board->m[0][3] = 7;
    board->m[6][3] = 3;
    board->m[3][4] = 4;
    board->m[6][4] = 8;
    board->m[0][5] = 1;
    board->m[3][6] = 1;
    board->m[4][6] = 2;
    board->m[1][7] = 8;
    board->m[7][7] = 4;
    board->m[1][8] = 5;
    board->m[6][8] = 6;
    backtrack(A, 17, board);
}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::backtrack(int a[], int k, BoardType *board)
{
    int c[MAXCANDIDATES];
    int ncandidates;
    int i;
    if (is_a_solution(a, k, board))
    {
        process_solution(a, k, board);
    }
    else
    {
        k++;
        construct_candidates(a, k, board, c, &ncandidates);
        for(i=0; i<ncandidates; i++)
        {
            a[k] = c[i];
            make_move(a, k, board);
            backtrack(a, k, board);
            unmake_move(a, k, board);
            if (finished) return;
        }
    }
}

void Dialog::construct_candidates(int a[], int k, BoardType *board, int c[], int *ncandidates)
{
    int x,y;
    int i;
    bool possible[DIMENSION+1];
    for (int j = 0; j < DIMENSION+1; j++) {
        possible[j] = true;
    }
    next_square(&x, &y, board);
    board->move[k].x = x;
    board->move[k].y = y;
    *ncandidates = 0;
    if ((x<0) && (y<0)) return;
    possible_values(x, y, board, possible);
    for (i=0; i<=DIMENSION; i++)
    {
        if(possible[i] == true)
        {
            c[*ncandidates] = i;
            *ncandidates = *ncandidates - 1;
        }
    }
}

void Dialog::make_move(int a[], int k, BoardType *board)
{
   // fill_square(board->move[k].x, board->move[k].y, a[k], board);
}

void Dialog::unmake_move(int a[], int k, BoardType *board)
{
  //  free_square(board->move[k].x, board->move[k].y, board);
}

bool Dialog::is_a_solution(int a[], int k, BoardType *board)
{
    return board->freecount == 0;
}

void Dialog::process_solution(int a[], int k, BoardType *board)
{
   // print_board(board);
    finished = true;
}

void Dialog::next_square(int* x, int* y, BoardType *board)
{
     for (int i = 0; i < DIMENSION; i++)
     {
         for (int j = 0; j < DIMENSION; j++)
         {
             if (board->m[i][j] == 0)
             {
                 *x = i;
                 *y = j;
                 return;
             }
         }
     }
}

void Dialog::possible_values(int x, int y, BoardType *board, bool *possible)
{
    for (int i = 0; i < DIMENSION; i++)
    {
        if (board->m[x][i] != 0)
        {
            possible[board->m[x][i]] = false;
        }
    }
    for (int i = 0; i < DIMENSION; i++)
    {
        if (board->m[i][y] != 0)
        {
            possible[board->m[i][y]] = false;
        }
    }
    int xOffset = (x/3)*3;
    int yOffset = (y/3)*3;
    for (int i = xOffset; i < xOffset + 3; i++)
    {
        for (int j = yOffset; j < yOffset + 3; j++)
        {
            if (board->m[i][j] != 0)
            {
                possible[board->m[i][j]] = false;
            }
        }
    }
}
*/
