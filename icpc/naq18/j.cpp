#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Move {
    int board[5][5];
    int score;
};

static vector<Move> get_moves(int board[5][5]) {
    int dx[6] = {-2, -2, 0, 0, 2, 2};
    int dy[6] = {-2, 0, -2, 2, 2, 0};
    vector<Move> moves;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            if (board[i][j] == 0) {
                for (int x = 0; x < 6; x++) {
                    int newx = i + dx[x];
                    int newy = j + dy[x];
                    if (newx >= 0 && newx < 5 && newy >= 0 && newy <= newx && board[newx][newy] != 0) {
                        int bx = i + dx[x] / 2;
                        int by = j + dy[x] / 2;
                        if (board[bx][by] != 0) {
                            Move move;
                            move.score = board[newx][newy] * board[bx][by];
                            for (int i = 0; i < 5; i++) {
                                for (int j = 0; j <= i; j++) {
                                    move.board[i][j] = board[i][j];
                                }
                            }

                            move.board[newx][newy] = 0;
                            move.board[bx][by] = 0;
                            move.board[i][j] = board[newx][newy];
                            moves.push_back(move);
                        }
                    }
                }
            }
        }
    }
    return moves;
}

static ll p2(int board[5][5]);

static ll p1(int board[5][5]) {
    vector<Move> moves = get_moves(board);
    if (moves.size() == 0) {
        return 0;
    }
    ll max = -100000000000L;
    for (Move move: moves) {
        ll p2_score = p2(move.board);
        ll score = (ll) move.score + p2_score;
        if (score > max) {
            max = score;
        }
    }
    return max;
}

static ll p2(int board[5][5]) {
    vector<Move> moves = get_moves(board);
    if (moves.size() == 0) {
        return 0;
    }
    ll min = 10000000000L;
    for (Move move: moves) {
        ll p1_score = p1(move.board);
        ll score = p1_score - (ll) move.score;
        if (score < min)
            min = score;
    }
    return min;
}

static void print_board(int board[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int board[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> board[i][j];
        }
    }

    vector<Move> moves = get_moves(board);
    /*for (Move move: moves) {
        cout << move.score << "\n";
        print_board(move.board);
    }*/

    cout << p1(board) << "\n";
}
