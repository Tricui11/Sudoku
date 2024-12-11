import {BoardType} from '/js/boardtype.js'

export class SudokuSolver {
    constructor() {
      this.finished = false;
      this.possibleBuf = Array(BoardType.Dimension + 1).fill(false);
    }
  
    backtrack(a, k, board) {
      const c = Array(BoardType.Dimension).fill(0);
      let ncandidates;

      if (board.freecount === 0) {
        
        this.finished = true;
      } else {
        
        k++;
        ncandidates = this.constructCandidates(k, board, c);

         for (let i = 0; i < ncandidates; i++) {
            a[k] = c[i];
            this.makeMove(a, k, board);
            this.backtrack(a, k, board);
            if (this.finished) return;
            this.unmakeMove(k, board);
          }
        };
      }
  
    constructCandidates(k, board, c) {
      const possible = Array(BoardType.Dimension + 1).fill(true);
      let { x, y } = this.nextSquare(board);
      board.move[k].x = x;
      board.move[k].y = y;
  
      let ncandidates = 0;
      if (x === -1) return 0;
  
      this.possibleValues(x, y, board, possible);
      for (let i = 1; i <= BoardType.Dimension; i++) {
        if (possible[i]) {
          c[ncandidates] = i;
          ncandidates++;
        }
      }

      return ncandidates;
    }
  
    makeMove(a, k, board) {
      board.m[board.move[k].x][board.move[k].y] = a[k];
      board.freecount--;
    }
  
    unmakeMove(k, board) {
      board.m[board.move[k].x][board.move[k].y] = 0;
      board.freecount++;
    }
  
    nextSquare(board) {
      let x = -1, y = -1; 
      for (let i = 0; i < BoardType.Dimension; i++) {
        for (let j = 0; j < BoardType.Dimension; j++) {
          board.move[i * BoardType.Dimension + j + 1].nCandidates = 0;
          if (board.m[i][j] === 0) {
            const possible = Array(BoardType.Dimension + 1).fill(true);
            const nCandidates = this.possibleValues(i, j, board, possible);
            if (nCandidates === 1) {
              x = i;
              y = j;
              return { x, y }; 
            } else {
              board.move[i * BoardType.Dimension + j + 1].nCandidates = nCandidates;
            }
          }
        }
      }
  
      for (let j = 2; j < BoardType.Dimension + 1; j++) {
        for (let i = 1; i < BoardType.NCELLS + 1; i++) {
          if (board.move[i].nCandidates === j) {
            x = Math.floor((i - 1) / BoardType.Dimension);
            y = i - 1 - x * BoardType.Dimension;
            return { x, y };
          }
        }
      }
  
      return { x: -1, y: -1 };
    }
  
    possibleValues(x, y, board, possible) {  
      for (let i = 0; i < BoardType.Dimension; i++) {
        if (board.m[x][i] !== 0) {
          possible[board.m[x][i]] = false;
        }
      }
  
      for (let i = 0; i < BoardType.Dimension; i++) {
        if (board.m[i][y] !== 0) {
          possible[board.m[i][y]] = false;
        }
      }
  
      const xOffset = Math.floor(x / 3) * 3;
      const yOffset = Math.floor(y / 3) * 3;
      for (let i = xOffset; i < xOffset + 3; i++) {
        for (let j = yOffset; j < yOffset + 3; j++) {
          if (board.m[i][j] !== 0) {
            possible[board.m[i][j]] = false;
          }
        }
      }
  
      let nCandidates = 0;
      for (let i = 1; i < BoardType.Dimension + 1; i++) {
        if (possible[i]) {
          nCandidates++;
        }
      }
  
      return nCandidates;
    }
  }
  