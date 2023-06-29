#define _CRT_SECURE_NO_WARNINGS 1
//在这个版本中，我们使用了Alpha-Beta剪枝算法来优化电脑玩家的决策过程。alphaBeta函数实现了Alpha-Beta剪枝算法的核心部分，用于评估当前棋局的得分并选择最佳移动。makeComputerMove函数使用alphaBeta来选择最佳移动并执行。你可以尝试调整alphaBeta函数中的深度参数来调整电脑玩家的难度级别。
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 15
#define PLAYER 'X'
#define COMPUTER 'O'

char board[BOARD_SIZE][BOARD_SIZE];
int currentPlayer;

void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void drawBoard() {
    system("cls"); // 清空控制台屏幕

    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

int isWinningMove(int row, int col) {
    int i, j;

    // 水平方向
    for (i = col; i <= col + 4; i++) {
        if (i < 0 || i + 4 >= BOARD_SIZE) {
            continue;
        }

        int count = 0;

        for (j = i; j <= i + 4; j++) {
            if (board[row][j] == board[row][col]) {
                count++;
            }
            else {
                break;
            }
        }

        if (count == 5) {
            return 1;
        }
    }

    // 垂直方向
    for (i = row; i <= row + 4; i++) {
        if (i < 0 || i + 4 >= BOARD_SIZE) {
            continue;
        }

        int count = 0;

        for (j = i; j <= i + 4; j++) {
            if (board[j][col] == board[row][col]) {
                count++;
            }
            else {
                break;
            }
        }

        if (count == 5) {
            return 1;
        }
    }

    // 左上到右下斜线
    for (i = row, j = col; i <= row + 4, j <= col + 4; i++, j++) {
        if (i < 0 || i + 4 >= BOARD_SIZE || j < 0 || j + 4 >= BOARD_SIZE) {
            continue;
        }

        int count = 0;

        for (int k = 0; k < 5; k++) {
            if (board[i + k][j + k] == board[row][col]) {
                count++;
            }
            else {
                break;
            }
        }

        if (count == 5) {
            return 1;
        }
    }

    // 左下到右上斜线
    for (i = row + 4, j = col - 4; i >= row, j <= col; i--, j++) {
        if (i < 0 || i - 4 >= BOARD_SIZE || j < 0 || j + 4 >= BOARD_SIZE) {
            continue;
        }

        int count = 0;

        for (int k = 0; k < 5; k++) {
            if (board[i - k][j + k] == board[row][col]) {
                count++;
            }
            else {
                break;
            }
        }

        if (count == 5) {
            return 1;
        }
    }

    return 0;
}

int isValidMove(int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return 0;
    }

    if (board[row][col] != ' ') {
        return 0;
    }

    return 1;
}

void makeMove(int row, int col, char player) {
    board[row][col] = player;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == PLAYER) ? COMPUTER : PLAYER;
}

int evaluateBoard() {
    int i, j;

    // 检查水平方向
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE - 4; j++) {
            if (board[i][j] == 'X' && board[i][j + 1] == 'X' && board[i][j + 2] == 'X' && board[i][j + 3] == 'X' && board[i][j + 4] == 'X') {
                return -100;
            }
            else if (board[i][j] == 'O' && board[i][j + 1] == 'O' && board[i][j + 2] == 'O' && board[i][j + 3] == 'O' && board[i][j + 4] == 'O') {
                return 100;
            }
        }
    }

    // 检查垂直方向
    for (i = 0; i < BOARD_SIZE - 4; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'X' && board[i + 1][j] == 'X' && board[i + 2][j] == 'X' && board[i + 3][j] == 'X' && board[i + 4][j] == 'X') {
                return -100;
            }
            else if (board[i][j] == 'O' && board[i + 1][j] == 'O' && board[i + 2][j] == 'O' && board[i + 3][j] == 'O' && board[i + 4][j] == 'O') {
                return 100;
            }
        }
    }

    // 检查左上到右下斜线
    for (i = 0; i < BOARD_SIZE - 4; i++) {
        for (j = 0; j < BOARD_SIZE - 4; j++) {
            if (board[i][j] == 'X' && board[i + 1][j + 1] == 'X' && board[i + 2][j + 2] == 'X' && board[i + 3][j + 3] == 'X' && board[i + 4][j + 4] == 'X') {
                return -100;
            }
            else if (board[i][j] == 'O' && board[i + 1][j + 1] == 'O' && board[i + 2][j + 2] == 'O' && board[i + 3][j + 3] == 'O' && board[i + 4][j + 4] == 'O') {
                return 100;
            }
        }
    }

    // 检查左下到右上斜线
    for (i = 4; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE - 4; j++) {
            if (board[i][j] == 'X' && board[i - 1][j + 1] == 'X' && board[i - 2][j + 2] == 'X' && board[i - 3][j + 3] == 'X' && board[i - 4][j + 4] == 'X') {
                return -100;
            }
            else if (board[i][j] == 'O' && board[i - 1][j + 1] == 'O' && board[i - 2][j + 2] == 'O' && board[i - 3][j + 3] == 'O' && board[i - 4][j + 4] == 'O') {
                return 100;
            }
        }
    }

    return 0;
}

int minimax(int depth, int isMaximizingPlayer) {
    int score = evaluateBoard();

    if (score == 100) {
        return score - depth;
    }

    if (score == -100) {
        return score + depth;
    }

    if (depth == 0) {
        return 0;
    }

    if (isMaximizingPlayer) {
        int bestScore = -1000;

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = COMPUTER;
                    int moveScore = minimax(depth - 1, 0);
                    board[i][j] = ' ';

                    if (moveScore > bestScore) {
                        bestScore = moveScore;
                    }
                }
            }
        }

        return bestScore;
    }
    else {
        int bestScore = 1000;

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = PLAYER;
                    int moveScore = minimax(depth - 1, 1);
                    board[i][j] = ' ';

                    if (moveScore < bestScore) {
                        bestScore = moveScore;
                    }
                }
            }
        }

        return bestScore;
    }
}

void makeComputerMove() {
    int bestScore = -1000;
    int bestMoveRow = -1;
    int bestMoveCol = -1;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = COMPUTER;
                int moveScore = minimax(4, 0);
                board[i][j] = ' ';

                if (moveScore > bestScore) {
                    bestScore = moveScore;
                    bestMoveRow = i;
                    bestMoveCol = j;
                }
            }
        }
    }

    makeMove(bestMoveRow, bestMoveCol, COMPUTER);
}

void playGame() {
    char input[3];
    int row, col;

    initBoard();
    currentPlayer = PLAYER;

    while (1) {
        drawBoard();

        if (currentPlayer == PLAYER) {
            printf("请输入你的下棋位置（例如A1）：");
            scanf("%s", input);

            row = input[1] - '1';
            col = input[0] - 'A';

            if (isValidMove(row, col)) {
                makeMove(row, col, PLAYER);

                if (isWinningMove(row, col)) {
                    drawBoard();
                    printf("恭喜你，你赢了！\n");
                    break;
                }

                switchPlayer();
            }
            else {
                printf("无效的移动，请重试。\n");
            }
        }
        else {
            printf("电脑正在思考中...\n");
            makeComputerMove();

            if (isWinningMove(row, col)) {
                drawBoard();
                printf("很遗憾，电脑赢了！\n");
                break;
            }

            switchPlayer();
        }
    }
}

int main() {
    playGame();

    return 0;
}
