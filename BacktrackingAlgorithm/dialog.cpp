#include "dialog.h"
#include "ui_dialog.h"
#include <QLineEdit>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QRegularExpression cellRegEx("[1-9]\\d{0,0}w{0,1}");
    cellValidator = new QRegularExpressionValidator(cellRegEx, this);

    drawMapGrid();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::drawMapGrid()
{
    for(int i=0; i<DIMENSION; i++)
    {
        for(int j=0; j<DIMENSION; j++)
        {
            mapGridLayoutAddCell("", i, j);
        }
    }
}

void Dialog::mapGridLayoutClear()
{
    QLayoutItem *cell;
    while ((cell = ui->mapGridLayout->takeAt(0)) != NULL)
    {
        delete cell->widget();
        delete cell;
    }
}

void Dialog::mapGridLayoutAddCell(QString text, int i, int j)
{
    QLineEdit *le = new QLineEdit(text);
    le->setFixedWidth(56);
    le->setFixedHeight(56);
    le->setValidator(cellValidator);
    QFont font("Arial", 20);
    font.setBold(true);
    le->setFont(font);
    le->setAlignment(Qt::AlignCenter);
    le->setObjectName("Foo");
    int l = 1, r = 0, t = 1, b = 0;
    if (i % 3 == 0) t = 3;
    if (i == 8) b = 3;
    if (j % 3 == 0) l = 3;
    if (j == 8) r = 3;
    QString css = "#Foo { border-top: %1px solid black; border-bottom: %2px solid black;  border-right: %3px solid black; border-left: %4px solid black; }";
    css = css.arg(t).arg(b).arg(r).arg(l);
    le->setStyleSheet(css);
    ui->mapGridLayout->addWidget(le, i, j);
}

BoardType* Dialog::readBoard()
{
    BoardType *board = new BoardType();
    board->freecount = NCELLS;
    for(int i=0; i<DIMENSION; i++)
    {
        for(int j=0; j<DIMENSION; j++)
        {
            std::string currentCellText = ((QLineEdit*)ui->mapGridLayout->itemAtPosition(i,j)->widget())->text().toStdString();
            if(currentCellText != "")
            {
                int value = stoi(currentCellText);
                board->m[i][j] = value;
                board->move[i * DIMENSION + j + 1].isInitial = true;
                board->freecount--;
            }
        }
    }
    return board;
}

void Dialog::writeBoard(BoardType *board)
{
    for(int i=0; i<DIMENSION; i++)
    {
        for(int j=0; j<DIMENSION; j++)
        {
            QLineEdit *currentCell = ((QLineEdit*)ui->mapGridLayout->itemAtPosition(i,j)->widget());
            currentCell->setText(QString::number(board->m[i][j]));
            if(!board->move[i * DIMENSION + j + 1].isInitial)
            {
                QFont font = currentCell->font();
                font.setBold(false);
                font.setPointSize(15);
                currentCell->setFont(font);
            }
        }
    }
}

void Dialog::on_pushButton_Solve_clicked()
{
    int A[NCELLS];
    BoardType* board = readBoard();

    if (solver == nullptr)
    {
        solver = new SudokuSolver();
    }
    solver->finished = false;
    solver->backtrack(A, NCELLS - board->freecount, board);

    writeBoard(board);
}

void Dialog::on_pushButton_New_clicked()
{
    mapGridLayoutClear();
    drawMapGrid();
}
