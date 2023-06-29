//#define _CRT_SECURE_NO_WARNINGS 1
//基于极小化极大算法（Minimax Algorithm）
//#include <stdio.h>
//#include <stdlib.h>
//#include <conio.h>
//#include <windows.h>
//
//#define BOARD_SIZE 15
//#define PLAYER 0
//#define COMPUTER 1
//
//char board[BOARD_SIZE][BOARD_SIZE];
//int currentPlayer;
//COORD cursorPosition;
//
//void gotoxy(int x, int y) {
//    COORD coord;
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//
//void drawBoard() {
//    system("cls");
//    int i, j;
//
//    printf("=== 五子棋 ===\n\n");
//
//    for (i = 0; i < BOARD_SIZE; i++) {
//        printf(" %2d ", i + 1);
//
//        for (j = 0; j < BOARD_SIZE; j++) {
//            if (board[i][j] == 'X') {
//                printf("X ");
//            }
//            else if (board[i][j] == 'O') {
//                printf("O ");
//            }
//            else {
//                printf(". ");
//            }
//        }
//
//        printf("\n");
//    }
//
//    printf("\n    ");
//    for (i = 0; i < BOARD_SIZE; i++) {
//        printf("%c ", 'A' + i);
//    }
//
//    printf("\n\n");
//    printf("当前玩家: %c\n", (currentPlayer == PLAYER) ? 'X' : 'O');
//}
//
//void initBoard() {
//    int i, j;
//
//    for (i = 0; i < BOARD_SIZE; i++) {
//        for (j = 0; j < BOARD_SIZE; j++) {
//            board[i][j] = ' ';
//        }
//    }
//}
//
//int isWinningMove(int row, int col) {
//    int i, j;
//    char player = board[row][col];
//
//     水平方向
//    for (j = col - 4; j <= col; j++) {
//        if (j < 0 || j + 4 >= BOARD_SIZE) {
//            continue;
//        }
//
//        int count = 0;
//
//        for (i = j; i < j + 5; i++) {
//            if (board[row][i] == player) {
//                count++;
//            }
//        }
//
//        if (count == 5) {
//            return 1;
//        }
//    }
//
//     垂直方向
//    for (i = row - 4; i <= row; i++) {
//        if (i < 0 || i + 4 >= BOARD_SIZE) {
//            continue;
//        }
//
//        int count = 0;
//
//        for (j = i; j < i + 5; j++) {
//            if (board[j][col] == player) {
//                count++;
//            }
//        }
//
//        if (count == 5) {
//            return 1;
//        }
//    }
//
//     左上到右下斜线
//    for (i = row - 4, j = col - 4; i <= row, j <= col; i++, j++) {
//        if (i < 0 || i + 4 >= BOARD_SIZE || j < 0 || j + 4 >= BOARD_SIZE) {
//            continue;
//        }
//
//        int count = 0;
//
//        for (int k = 0; k < 5; k++) {
//            if (board[i + k][j + k] == player) {
//                count++;
//            }
//        }
//
//        if (count == 5) {
//            return 1;
//        }
//    }
//
//     左下到右上斜线
//    for (i = row + 4, j = col - 4; i >= row, j <= col; i--, j++) {
//        if (i < 0 || i - 4 >= BOARD_SIZE || j < 0 || j + 4 >= BOARD_SIZE) {
//            continue;
//        }
//
//        int count = 0;
//
//        for (int k = 0; k < 5; k++) {
//            if (board[i - k][j + k] == player) {
//                count++;
//            }
//        }
//
//        if (count == 5) {
//            return 1;
//        }
//    }
//
//    return 0;
//}
//
//int isValidMove(int row, int col) {
//    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
//        return 0;
//    }
//
//    if (board[row][col] != ' ') {
//        return 0;
//    }
//
//    return 1;
//}
//
//void makeMove(int row, int col, int player) {
//    board[row][col] = (player == PLAYER) ? 'X' : 'O';
//}
//
//void switchPlayer() {
//    currentPlayer = (currentPlayer == PLAYER) ? COMPUTER : PLAYER;
//}
//
//int evaluateBoard() {
//    int i, j;
//
//     检查水平方向
//    for (i = 0; i < BOARD_SIZE; i++) {
//        for (j = 0; j < BOARD_SIZE - 4; j++) {
//            if (board[i][j] == 'X' && board[i][j + 1] == 'X' && board[i][j + 2] == 'X' && board[i][j + 3] == 'X' && board[i][j + 4] == 'X') {
//                return -100;
//            }
//            else if (board[i][j] == 'O' && board[i][j + 1] == 'O' && board[i][j + 2] == 'O' && board[i][j + 3] == 'O' && board[i][j + 4] == 'O') {
//                return 100;
//            }
//        }
//    }
//
//     检查垂直方向
//    for (j = 0; j < BOARD_SIZE; j++) {
//        for (i = 0; i < BOARD_SIZE - 4; i++) {
//            if (board[i][j] == 'X' && board[i + 1][j] == 'X' && board[i + 2][j] == 'X' && board[i + 3][j] == 'X' && board[i + 4][j] == 'X') {
//                return -100;
//            }
//            else if (board[i][j] == 'O' && board[i + 1][j] == 'O' && board[i + 2][j] == 'O' && board[i + 3][j] == 'O' && board[i + 4][j] == 'O') {
//                return 100;
//            }
//        }
//    }
//
//     检查左上到右下斜线
//    for (i = 0; i < BOARD_SIZE - 4; i++) {
//        for (j = 0; j < BOARD_SIZE - 4; j++) {
//            if (board[i][j] == 'X' && board[i + 1][j + 1] == 'X' && board[i + 2][j + 2] == 'X' && board[i + 3][j + 3] == 'X' && board[i + 4][j + 4] == 'X') {
//                return -100;
//            }
//            else if (board[i][j] == 'O' && board[i + 1][j + 1] == 'O' && board[i + 2][j + 2] == 'O' && board[i + 3][j + 3] == 'O' && board[i + 4][j + 4] == 'O') {
//                return 100;
//            }
//        }
//    }
//
//     检查左下到右上斜线
//    for (i = 4; i < BOARD_SIZE; i++) {
//        for (j = 0; j < BOARD_SIZE - 4; j++) {
//            if (board[i][j] == 'X' && board[i - 1][j + 1] == 'X' && board[i - 2][j + 2] == 'X' && board[i - 3][j + 3] == 'X' && board[i - 4][j + 4] == 'X') {
//                return -100;
//            }
//            else if (board[i][j] == 'O' && board[i - 1][j + 1] == 'O' && board[i - 2][j + 2] == 'O' && board[i - 3][j + 3] == 'O' && board[i - 4][j + 4] == 'O') {
//                return 100;
//            }
//        }
//    }
//
//    return 0;
//}
//
//int minimax(int depth, int isMaximizing) {
//    int score = evaluateBoard();
//    if (score == 100 || score == -100) {
//        return score;
//    }
//    if (depth == 0) {
//        return 0;
//    }
//
//    int bestScore;
//    if (isMaximizing) {
//        bestScore = -1000;
//        for (int i = 0; i < BOARD_SIZE; i++) {
//            for (int j = 0; j < BOARD_SIZE; j++) {
//                if (board[i][j] == ' ') {
//                    board[i][j] = 'O';
//                    int currentScore = minimax(depth - 1, !isMaximizing);
//                    board[i][j] = ' ';
//                    if (currentScore > bestScore) {
//                        bestScore = currentScore;
//                    }
//                }
//            }
//        }
//        return bestScore;
//    }
//    else {
//        bestScore = 1000;
//        for (int i = 0; i < BOARD_SIZE; i++) {
//            for (int j = 0; j < BOARD_SIZE; j++) {
//                if (board[i][j] == ' ') {
//                    board[i][j] = 'X';
//                    int currentScore = minimax(depth - 1, !isMaximizing);
//                    board[i][j] = ' ';
//                    if (currentScore < bestScore) {
//                        bestScore = currentScore;
//                    }
//                }
//            }
//        }
//        return bestScore;
//    }
//}
//
//void makeComputerMove() {
//    int bestScore = -1000;
//    int bestMoveRow = -1;
//    int bestMoveCol = -1;
//
//    for (int i = 0; i < BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE; j++) {
//            if (board[i][j] == ' ') {
//                board[i][j] = 'O';
//                int moveScore = minimax(4, 0);
//                board[i][j] = ' ';
//
//                if (moveScore > bestScore) {
//                    bestScore = moveScore;
//                    bestMoveRow = i;
//                    bestMoveCol = j;
//                }
//            }
//        }
//    }
//
//    makeMove(bestMoveRow, bestMoveCol, COMPUTER);
//}
//
//void playGame() {
//    char input[3];
//    int row, col;
//
//    initBoard();
//    currentPlayer = PLAYER;
//    cursorPosition.X = 0;
//    cursorPosition.Y = 2;
//
//    while (1) {
//        drawBoard();
//        gotoxy(cursorPosition.X, cursorPosition.Y);
//
//        if (currentPlayer == PLAYER) {
//            printf("输入您的下一步 (例如 A1): ");
//            scanf("%s", input);
//
//            col = input[0] - 'A';
//            row = input[1] - '1';
//
//            if (isValidMove(row, col)) {
//                makeMove(row, col, PLAYER);
//
//                if (isWinningMove(row, col)) {
//                    drawBoard();
//                    printf("玩家 X 获胜！\n");
//                    break;
//                }
//
//                switchPlayer();
//            }
//            else {
//                printf("无效的移动，请重试。\n");
//            }
//        }
//        else {
//            makeComputerMove();
//
//            if (isWinningMove(row, col)) {
//                drawBoard();
//                printf("玩家 O 获胜！\n");
//                break;
//            }
//
//            switchPlayer();
//        }
//    }
//}
//
//int main() {
//    playGame();
//    return 0;
//}
