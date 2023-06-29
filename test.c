//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <conio.h>
//#include <windows.h>
//
//#define BOARD_SIZE 15
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
//    printf("当前玩家: %c\n", (currentPlayer == 0) ? 'X' : 'O');
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
//    // 水平方向
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
//    // 垂直方向
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
//    // 左上到右下斜线
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
//    // 左下到右上斜线
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
//void makeMove(int row, int col) {
//    board[row][col] = (currentPlayer == 0) ? 'X' : 'O';
//}
//
//void switchPlayer() {
//    currentPlayer = (currentPlayer == 0) ? 1 : 0;
//}
//
//void playGame() {
//    char input[3];
//    int row, col;
//
//    initBoard();
//    currentPlayer = 0;
//
//    while (1) {
//        drawBoard();
//
//        printf("输入您的下一步 (例如 A1): ");
//        scanf("%s", input);
//
//        col = input[0] - 'A';
//        row = input[1] - '1';
//
//        if (isValidMove(row, col)) {
//            makeMove(row, col);
//
//            if (isWinningMove(row, col)) {
//                drawBoard();
//                printf("玩家 %c 获胜！\n", (currentPlayer == 0) ? 'X' : 'O');
//                break;
//            }
//
//            switchPlayer();
//        }
//        else {
//            printf("无效的移动，请重试。\n");
//        }
//    }
//}
//
//int main() {
//    playGame();
//    return 0;
//}
//
//
