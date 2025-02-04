#include <iostream>
#include <vector>
using namespace std;

class my_robot {
public:
    char map[10][10];
    vector<pair<int, int>>record; /*record the locations already visited to avoid exceeding 10 in each position*/
    int x; /*rows*/
    int y; /*columns*/
    int count; /**/
    int total;

    my_robot(int x, int y) : count(0), total(0), x(6), y(1) {
        record.push_back(make_pair(x, y)); initiate_map();
    }
    void initiate_map() {
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < 10; j++)
                map[j][i] = '.';
        }
        map[6][1] = '*';
    }
    /*this class function uses a forloop to execute the input once it is called in main through multiple
    move functions (methods) of return type (0/1) depending on input from string in main*/
    void execute_move(string input) {
        for (char move : input) {
            bool successful_move = 0;

            if (move == 'e') {
                successful_move = right();
            }
            else if (move == 'w') {
                successful_move = left();
            }
            else if (move == 'n') {
                successful_move = up();
            }
            else if (move == 's') {
                successful_move = down();
            }
            if (successful_move) total++;

            if (map[x][y] == '.') map[x][y] = '1';
            else if (map[x][y] != 'X') {
                if (map[x][y] != '*') map[x][y]++;
                if (map[x][y] == '9') {
                    map[x][y] = 'X';
                    cout << "Bad robot!" << endl;
                    return;
                }
            }
        }
        map[x][y] = 'R';
    }
    bool right() {
        if (x < 9) {
            x++;
            return true;
        }
        else return 0;
    }
    bool left() {
        if (x > 0) {
            x--;
            return true;
        }
        else return 0;
    }
    bool up() {
        if (y < 9) {
            y++;
            return true;
        }
        else return 0;
    }
    bool down() {
        if (y > 0) {
            y--;
            return true;
        }
        else return 0;
    }

    void display_map() {
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < 10; j++)
                cout << map[j][i] << ' ';
            cout << endl;
        }
    }
    /*we need to introduce a function with return type integer for printing out total in main*/
    int print_total() {
        return total;
    }
};

int main() {
    my_robot run(6, 1); /*class object created with the given initial position*/
    string input; /*string will hold our path through the map*/
    cout << "Provide the directions to follow (input n/s/e/w to move the robot up/down/right/left)." << endl;
    cin >> input;
    run.execute_move(input); /*calling function in main-->string input-->move functions*/
    run.display_map();
    cout << endl << "We took " << run.print_total() << " steps.";
    return 0;
}