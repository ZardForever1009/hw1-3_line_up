// hw1-2: analyze different time of line up status for a game
// environment: Clion 2021.3.2
// C++ type: C++ 11
// gcc type: gcc version 8.1.0
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// class for a player
class Player {
public:
    Player(int player_num, int arrive_hour, int coin) {
        this->player_num = player_num;
        this->arrive_hour = arrive_hour;
        this->coin = coin;
    }

// player personal info
    int player_num;
    int arrive_hour;
    int coin;
};

// get integer function for coin counts & arrive hours (foolproof)
int get_integer_input(const string& info) {
    cout << info;
    string input;
    getline(cin, input);
    for (int i = 0; i < input.size(); i++) { // NOLINT(modernize-loop-convert)
        if (isdigit(input[i]));
        else {
            cout << "Error >> invalid input\n";
            return -1;
        }
    }
    return stoi(input);
}

// get player info & store it with vector
vector<int> get_player_info(const string& title, const string& info) {
    vector<int> result;
    cout << title << endl;
    for (int i = 1; i <= 5; i++) {
        int input = -1;
        while (input == -1) {
            input = get_integer_input(info + to_string(i) + " :");
        }
        result.push_back(input);
    }
    return result;
}

// assign each player info to its class
void assign_info_to_player(vector<int> arrived_hour, vector<int> coin, vector<Player>& player_list) {
    for (int i = 0; i < 5; i++) {
        player_list[i].arrive_hour = arrived_hour[i];
        player_list[i].coin = coin[i];
    }
}

// push function

// pop function

// start analyze & show result


int main() {

    // create player
    Player p1(1, 0, 0);
    Player p2(2, 0, 0);
    Player p3(3, 0, 0);
    Player p4(4, 0, 0);
    Player p5(5, 0, 0);

    // build player vector
    vector<Player> player_list;
    player_list.push_back(p1);
    player_list.push_back(p2);
    player_list.push_back(p3);
    player_list.push_back(p4);
    player_list.push_back(p5);

    // get player info & assign them to player info
    vector<int> player_arrive_hour = get_player_info("=====Player Arrived Hour=====", "Player ");
    vector<int> player_own_coin = get_player_info("=====Player Owned Coin=====", "Player ");
    assign_info_to_player(player_arrive_hour, player_own_coin, player_list);

    //start analyze result
    Player line_queue[5] = {Player(0,0,0),Player(0,0,0),Player(0,0,0),Player(0,0,0),Player(0,0,0)};

    system("pause");
    return 0;
}
