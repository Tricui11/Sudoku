#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


    QRegularExpression intRegEx("[1-9]\\d{0,3}");
    QValidator *intValidator = new QRegularExpressionValidator(intRegEx, this);
//    ui->lineEdit_Min->setValidator(intValidator);
//    ui->lineEdit_Max->setValidator(intValidator);
//    ui->lineEdit_XFreq->setValidator(intValidator);

    QRegularExpression cellRegEx("[1-9X-X]\\d{0,3}w{0,1}");
    cellValidator = new QRegularExpressionValidator(cellRegEx, this);

}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::backtrack(int a[], int k, BoardType *board)
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
//    for (int i = 0; i < 6 + 3; i++)
//    {
//        for (int j = 0; j < 6 + 3; j++)
//        {
//            printf(" %d", board->m[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
}




void Dialog::on_pushButton_GenMap_clicked()
{
    mapGridLayoutClear();

 //   int min = stoi(ui->lineEdit_Min->text().toStdString());
   //             int random = min + (rand() % static_cast<int>(max - min + 1));
    //            mapGridLayoutAddCell(QString::number(random), i, j);
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
    QLayoutItem* cell;
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
    QFont font("Arial", 14);
    font.setBold(true);
    QFontMetrics fm(font);
    le->setFont(font);
    le->setAlignment(Qt::AlignCenter);
    le->setObjectName("Foo");
    int l = 1, r = 0, t = 1, b = 0;
    if (i % 3 == 0)
    {
        t = 3;
    }
    if (i == 8)
    {
        b = 3;
    }
    if (j % 3 == 0)
    {
        l = 3;
    }
    if (j == 8)
    {
        r = 3;
    }
    QString css = "#Foo { border-top: %1px solid black; border-bottom: %2px solid black;  border-right: %3px solid black; border-left: %4px solid black; }";
    css = css.arg(t).arg(b).arg(r).arg(l);
    le->setStyleSheet(css);
    ui->mapGridLayout->addWidget(le, i, j);
}

void Dialog::on_pushButton_Solve_clicked()
{
    finished = false;
    int A[NCELLS];
    int freeCells = 81;
    BoardType *board = new BoardType();
    for(int i=0; i<DIMENSION; i++)
    {
        for(int j=0; j<DIMENSION; j++)
        {
            std::string currentCellText = ((QLineEdit*)ui->mapGridLayout->itemAtPosition(i,j)->widget())->text().toStdString();
            if(currentCellText != "")
            {
                int value = stoi(currentCellText);
                board->m[i][j] = value;
                freeCells--;
            }
        }
    }
    board->freecount = freeCells;
    backtrack(A, NCELLS - freeCells, board);
    for(int i=0; i<DIMENSION; i++)
    {
        for(int j=0; j<DIMENSION; j++)
        {
            QLineEdit *currentCell = ((QLineEdit*)ui->mapGridLayout->itemAtPosition(i,j)->widget());
            currentCell->setText(QString::number(board->m[i][j]));
        }
    }
}
