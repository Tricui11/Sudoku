import {BoardType} from '/js/boardtype.js'
import {SudokuSolver} from '/js/sudokusolver.js'

const sudokuGrid = document.querySelector('.sudoku-grid');

function createSudokuGrid() {
    for (let i = 0; i < 81; i++) {
        const input = document.createElement('input');
        input.type = 'text';
        input.className = 'cell';
        input.maxLength = 1;
        input.addEventListener('input', (event) => {
            if (!/^[1-9]$/.test(event.target.value)) {
              event.target.value = '';
            }
          });
        sudokuGrid.appendChild(input);
      }
}

function readBoardFromUI() {
    let board = new BoardType();
    const inputs = document.querySelectorAll('.sudoku-grid input');    

    let idx = 0;
    inputs.forEach(input => {
        const value = input.value;
        const row = Math.floor(idx / BoardType.Dimension);
        const col = idx % BoardType.Dimension;
        if (value !== '') {
            board.m[row][col] = parseInt(value);
            board.move[idx + 1].isInitial = true;
            board.freecount--;
        }
        else {
            board.m[row][col] = 0;
        }
        idx++;
    });

    return board;
}

function writeBoardToUI(board) {
    const inputs = document.querySelectorAll('.sudoku-grid input');
    
    let idx = 0;
    inputs.forEach(input => {
        const row = Math.floor(idx / BoardType.Dimension);
        const col = idx % BoardType.Dimension;
        input.value = board.m[row][col] !== 0 ? board.m[row][col] : '';
        if (board.move[idx + 1].isInitial) {
            input.classList.add('initial-cell');
        } else {
            input.classList.remove('initial-cell');
        }
        idx++;
    });
}

createSudokuGrid();

document.getElementById('solveBtn').addEventListener('click', () => {

    const board = readBoardFromUI();

    let A = Array(BoardType.NCELLS);
    let solver = new SudokuSolver();
    
    solver.backtrack(A, BoardType.NCELLS - board.freecount, board);

    if (solver.finished) {
        writeBoardToUI(board);
    } else {
        alert("No solution found!");
    }
});

document.getElementById('clearBtn').addEventListener('click', () => {
    const inputs = document.querySelectorAll('.sudoku-grid input');    
    inputs.forEach(input => { input.value = ''; input.classList.remove('initial-cell'); });
});
