#include <iostream>
#include <algorithm>

using namespace std;


/*
    * rook moves horizontally and vertically a == e || b == f
    * bishop moves diagonally |c - e| == |d - f|
    *
    *
    * (row, col)
    * (a, b): Position of the white rook.
    * (c, d): Position of the white bishop.
    * (e, f): Position of the black queen.
    *
    * check if the rook at (a, b) is in the same row or column as (e, f). If not, move the rook to align with (e, f) horizontally or vertically
    * case 1 direct capture
    *
    *
    *
 */
class Solution {
public:
    static int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int moves = 1;

        // Check if the rook is blocking the queen's path to bishop
        if ((a==b && c == d && e == f) && ((a<c) && (a<e)) && ((b<d) && (b<f))) {
            moves = 1;

        } else if  (abs(c - e) == abs(d - f) && // check if bishop is diagonally to the queen
            abs(a - e) == abs(b - f)  && // check if rook is diagonally to the queen
            abs(c - a) == abs(d - b)// check if rook is diagonally to the queen
            && (abs(f-b) < abs(f-d))) // check if the difference between queen-rook is smaller than queen-bishop
        {

            moves = 2;
        }
        // Check if the bishop is blocking vertically the queen's path
        else if ((b==d && d==f) && (abs(e-a) > abs(e-c))) { // check bishop is not between rook and queen
            if  ((a < c ? (e > a && e < c) : (e > c && e < a))) {
                moves = 1;
            } else {
                moves = 2;
            }
        }
        // Check if the bishop is blocking horizontally the queen's path
        else if ((e==c && c==a) && (abs(f-b) > abs(f-d))) { // check bishop is not between rook and queen
            if ((b < d ? (f > b && f < d) : (f > b && f < d))) {
                moves = 1;
            } else {
                moves = 2;
            }
        }

        // direct capture by rook
        else if (a == e || b == f) {
            moves = 1;
        }
        // direct capture by bishop
        else if (abs(c - e) == abs(d - f)) {
            moves = 1;
        }
        else {
            moves = 2; // always return 2 moves if none of the above direct captures are satisfied
            }

        return moves;
    }
};

int main(){
    Solution sol;
    // case 1
    // int moves = Solution::minMovesToCaptureTheQueen(1,1,8,8,2,3);
    // case 2
    // int moves = Solution::minMovesToCaptureTheQueen(5,3,3,4,5,2);
    // case 7
    int moves = Solution::minMovesToCaptureTheQueen(3,1,2,1,1,1); // 2
    // case 9
    //int moves = Solution::minMovesToCaptureTheQueen(4,4,8,4,7,4); // 1

    cout << moves;
    return 0;
}