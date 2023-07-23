#include <boardtype.cpp>

class SudokuSolver
{
public:
    bool finished;

    void backtrack(int a[], int k, BoardType *board)
    {
        int c[DIMENSION];
        for (int j = 0; j < DIMENSION; j++)
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

    void construct_candidates(int a[], int k, BoardType *board, int c[], int *ncandidates)
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

    void make_move(int a[], int k, BoardType *board)
{
    int x = board->move[k].x;
    int y = board->move[k].y;
    int sd = a[k];


   board->m[board->move[k].x][board->move[k].y] = a[k];
   board->freecount--;
}

    void unmake_move(int a[], int k, BoardType *board)
{
    int x = board->move[k].x;
    int y = board->move[k].y;
    int sd = a[k];


    board->m[board->move[k].x][board->move[k].y] = 0;
    board->freecount++;
}

    bool is_a_solution(int a[], int k, BoardType *board)
{
    return board->freecount == 0;
}

    void process_solution(int a[], int k, BoardType *board)
{
    finished = true;
}

    void next_square(int* x, int* y, BoardType *board)
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

    void possible_values(int x, int y, BoardType *board, bool *possible)
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

};
