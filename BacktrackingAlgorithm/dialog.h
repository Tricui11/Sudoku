#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<boardtype.cpp>
#include <QRegularExpressionValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_GenMap_clicked();

    void on_pushButton_Solve_clicked();

private:
    Ui::Dialog *ui;
    QValidator *cellValidator;
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
    void mapGridLayoutClear();
    void mapGridLayoutAddCell(QString text, int i, int j);
    void generateXCellsForGridLayout(int N, int M);
};
#endif // DIALOG_H
