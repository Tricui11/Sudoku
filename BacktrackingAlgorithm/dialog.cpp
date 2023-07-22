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
    board->m[0][1] = 7;
    board->m[0][2] = 2;
    board->m[0][4] = 3;
    board->m[0][7] = 8;
    board->m[0][8] = 9;

    board->m[1][0] = 5;
    board->m[1][3] = 8;

    board->m[2][0] = 8;
    board->m[2][4] = 4;

    board->m[3][3] = 9;
    board->m[3][5] = 2;
    board->m[3][6] = 8;
    board->m[3][7] = 7;

    board->m[4][2] = 3;
    board->m[4][5] = 5;
    board->m[4][7] = 2;

    board->m[6][0] = 3;
    board->m[6][4] = 1;
    board->m[6][6] = 5;

    board->m[7][2] = 7;

    board->m[8][6] = 6;
    board->m[8][7] = 9;
    board->m[8][8] = 1;

    int freeCells = 81-23;
    board->freecount = freeCells;
    print_board(board);
    backtrack(A, NCELLS - freeCells, board);
}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::backtrack(int a[], int k, BoardType *board)
{
    int c[MAXCANDIDATES];
    for (int j = 0; j < MAXCANDIDATES; j++)
    {
        c[j] = 0;
    }
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
            if (finished) return;
            unmake_move(a, k, board);
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
    for (i=1; i<=DIMENSION; i++)
    {
        if(possible[i] == true)
        {
            c[*ncandidates] = i;
            *ncandidates = *ncandidates + 1;
        }
    }


}

void Dialog::make_move(int a[], int k, BoardType *board)
{
    int x = board->move[k].x;
    int y = board->move[k].y;
    int sd = a[k];


   board->m[board->move[k].x][board->move[k].y] = a[k];
   board->freecount--;
  // print_board(board);
}

void Dialog::unmake_move(int a[], int k, BoardType *board)
{
    int x = board->move[k].x;
    int y = board->move[k].y;
    int sd = a[k];


    board->m[board->move[k].x][board->move[k].y] = 0;
    board->freecount++;
 //   print_board(board);
}

bool Dialog::is_a_solution(int a[], int k, BoardType *board)
{
    return board->freecount == 0;
}

void Dialog::process_solution(int a[], int k, BoardType *board)
{
    print_board(board);
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
        int sd = board->m[x][i];
        if (board->m[x][i] != 0)
        {
            possible[board->m[x][i]] = false;
        }
    }
    for (int i = 0; i < DIMENSION; i++)
    {
        int sd = board->m[i][y];
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

void Dialog::print_board(BoardType *board)
{
    for (int i = 0; i < 6 + 3; i++)
    {
        for (int j = 0; j < 6 + 3; j++)
        {
            printf(" %d", board->m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
