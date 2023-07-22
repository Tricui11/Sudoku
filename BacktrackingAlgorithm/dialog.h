#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<boardtype.cpp>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    bool finished;
    void backtrack(int a[], int k, BoardType *board);
    void process_solution(int a[], int k, BoardType *board);
    void next_square(int* x, int* y, BoardType *board);
    void possible_values(int x, int y, BoardType *board, bool *possible);
    void make_move(int a[], int k, BoardType *board);
    void unmake_move(int a[], int k, BoardType *board);
    bool is_a_solution(int a[], int k, BoardType *board);
    void construct_candidates(int a[], int k, BoardType *board, int c[], int *ncandidates);
    void print_board(BoardType *board);
};
#endif // DIALOG_H
