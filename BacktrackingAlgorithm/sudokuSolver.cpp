#include <algorithm>
#include <boardtype.cpp>

class SudokuSolver
{
public:
    bool finished;
    bool possibleBuf[DIMENSION+1];

    void backtrack(int a[], int k, BoardType *board)
    {
        int c[DIMENSION];
        for (int j = 0; j < DIMENSION; j++)
        {
            c[j] = 0;
        }
        int ncandidates;
        if (board->freecount == 0)
        {
            finished = true;
        }
        else
        {
            k++;
            construct_candidates(k, board, c, &ncandidates);
            for(int i=0; i<ncandidates; i++)
            {
                a[k] = c[i];
                make_move(a, k, board);
                backtrack(a, k, board);
                if (finished) return;
                unmake_move(k, board);
            }
        }
    }

    void construct_candidates(int k, BoardType *board, int c[], int *ncandidates)
    {
        int x,y;
        bool possible[DIMENSION+1];
        for (int j = 0; j < DIMENSION+1; j++)
        {
            possible[j] = true;
        }
        next_square(&x, &y, board);
        board->move[k].x = x;
        board->move[k].y = y;
        *ncandidates = 0;
        if (x == -1) return;
        possible_values(x, y, board, possible);
        for (int i=1; i<=DIMENSION; i++)
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
        board->m[board->move[k].x][board->move[k].y] = a[k];
        board->freecount--;
    }

    void unmake_move(int k, BoardType *board)
    {
        board->m[board->move[k].x][board->move[k].y] = 0;
        board->freecount++;
    }

    void next_square(int* x, int* y, BoardType *board)
    {
        for(int i = 0; i < DIMENSION; i++)
        {
            for(int j = 0; j < DIMENSION; j++)
            {
                board->move[i * DIMENSION + j + 1].nCandidates = 0;
                if (board->m[i][j] == 0)
                {
                    for (int k = 0; k < DIMENSION+1; k++)
                    {
                        possibleBuf[k] = true;
                    }
                    int nCandidates = possible_values(i, j, board, possibleBuf);
                    if (nCandidates == 1)
                    {
                        *x = i;
                        *y = j;
                        return;
                    }
                    else
                    {
                        board->move[i * DIMENSION + j + 1].nCandidates = nCandidates;
                    }
                }
            }
        }

        for(int j = 2; j < DIMENSION+1; j++)
        {
            for(int i = 1; i < NCELLS+1; i++)
            {
                if(board->move[i].nCandidates == j)
                {
                    *x = (i-1)/DIMENSION;
                    *y = i-1 - *x*DIMENSION;
                    return;
                }
            }
        }

        *x = -1;
    }

    int possible_values(int x, int y, BoardType *board, bool *possible)
    {
        int i;
        for (i = 0; i < DIMENSION; i++)
        {
            if (board->m[x][i] != 0)
            {
                possible[board->m[x][i]] = false;
            }
        }
        for (i = 0; i < DIMENSION; i++)
        {
            if (board->m[i][y] != 0)
            {
                possible[board->m[i][y]] = false;
            }
        }
        int xOffset = (x/3)*3;
        int yOffset = (y/3)*3;
        for (i = xOffset; i < xOffset + 3; i++)
        {
            for (int j = yOffset; j < yOffset + 3; j++)
            {
                if (board->m[i][j] != 0)
                {
                    possible[board->m[i][j]] = false;
                }
            }
        }
        int nCandidates = 0;
        for (i = 1; i < DIMENSION+1; i++)
        {
            if (possible[i])
            {
                nCandidates++;
            }
        }
        return nCandidates;
    }
};
