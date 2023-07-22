/*
#define MAXCANDIDATES 2

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    finished = false;
    int A[4];
    backtrack(A, 0, 4);
}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::backtrack(int a[], int k, int n)
{
    int c[MAXCANDIDATES];
    int ncandidates;
    int i;
    if (is_a_solution(a, k, n))
    {
        process_solution(a, k, n);
    }
    else
    {
        k++;
        construct_candidates(a, k, n, c, &ncandidates);
        for(i=0; i<ncandidates; i++)
        {
            a[k] = c[i];
            make_move(a, k, n);
            backtrack(a, k, n);
            unmake_move(a, k, n);
            if (finished) return;
        }
    }
}

void Dialog::construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
    c[0] = true;
    c[1] = false;
    *ncandidates = 2;
}

void Dialog::make_move(int a[], int k, int n)
{
   // fill_square(board->move[k].x, board->move[k].y, a[k], board);
}

void Dialog::unmake_move(int a[], int k, int n)
{
  //  free_square(board->move[k].x, board->move[k].y, board);
}

bool Dialog::is_a_solution(int a[], int k, int n)
{
    return k == n;
}

void Dialog::process_solution(int a[], int k, int n)
{
    int i;
    printf("{");
    for(i=1; i<=k; i++)
    {
        if (a[i] == true)
        {
            printf(" %d", i);
        }
    }
    printf("}\n");
}
*/
