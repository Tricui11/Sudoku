#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QRegularExpressionValidator>
#include <sudokuSolver.cpp>

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
    void on_pushButton_Solve_clicked();

    void on_pushButton_New_clicked();

private:
    Ui::Dialog *ui;
    QValidator *cellValidator;
    SudokuSolver *solver = nullptr;

    void drawMapGrid();
    void mapGridLayoutClear();
    void mapGridLayoutAddCell(QString text, int i, int j);
    void generateXCellsForGridLayout(int N, int M);
    BoardType* readBoard();
    void writeBoard(BoardType *board);
};
#endif // DIALOG_H
