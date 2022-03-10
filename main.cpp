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
    // default constructor
    Player() {
        this->player_num = -1;
        this->arrive_hour = -1;
        this->coin = -1;
    }

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

// create player list
vector<Player> create_player_list(){
    // create player
    vector<Player> player_list;
    for(int i=1;i<=5;i++){
        Player p(i,0,0);
        player_list.push_back(p);
    }
    return player_list;
}

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
void assign_info_to_player_list(vector<int> arrived_hour, vector<int> coin, vector<Player>& player_list) {
    for (int i = 0; i < 5; i++) {
        player_list[i].arrive_hour = arrived_hour[i];
        player_list[i].coin = coin[i];
    }
}

// push function (from rear)
void push(Player*& line_queue, Player push_player) {
    for(int i=0;i<5;i++){
        if(line_queue[i].player_num==-1){
            line_queue[i].player_num = push_player.player_num;
            line_queue[i].arrive_hour = push_player.arrive_hour;
            line_queue[i].coin = push_player.coin;
            return;
        }
        else;
    }
}

// pop function (from begin)
void pop(Player*& line_queue){
    // move all player info before an index & reset the last one
    for(int i=0;i<5;i++){
        if(i==4){
            line_queue[i].player_num=-1;
            line_queue[i].arrive_hour = -1;
            line_queue[i].coin = -1;
        }
        else{
            line_queue[i]=line_queue[i+1];
        }
    }
}

// start analyze & show result


int main() {

    // build player vector
    vector<Player> player_list = create_player_list();

    // get player info & assign them to player info
    vector<int> player_arrive_hour = get_player_info("=====Player Arrived Hour=====", "Player ");
    vector<int> player_own_coin = get_player_info("=====Player Owned Coin=====", "Player ");
    assign_info_to_player_list(player_arrive_hour, player_own_coin, player_list);

    //start analyze result
    auto* line_queue = new Player[5];


/*    for(int i=0;i<5;i++){
        cout<<"==============\n";
        cout<<line_queue[i].player_num<<": "<<line_queue[i].arrive_hour<<"/"<<line_queue[i].coin<<endl;
    }
    push(line_queue, player_list[1]);
    for(int i=0;i<5;i++){
        cout<<"==============\n";
        cout<<line_queue[i].player_num<<": "<<line_queue[i].arrive_hour<<"/"<<line_queue[i].coin<<endl;
    }
    push(line_queue, player_list[2]);
    for(int i=0;i<5;i++){
        cout<<"==============\n";
        cout<<line_queue[i].player_num<<": "<<line_queue[i].arrive_hour<<"/"<<line_queue[i].coin<<endl;
    }
    push(line_queue, player_list[3]);
    for(int i=0;i<5;i++){
        cout<<"==============\n";
        cout<<line_queue[i].player_num<<": "<<line_queue[i].arrive_hour<<"/"<<line_queue[i].coin<<endl;
    }
    push(line_queue, player_list[4]);
    for(int i=0;i<5;i++){
        cout<<"==============\n";
        cout<<line_queue[i].player_num<<": "<<line_queue[i].arrive_hour<<"/"<<line_queue[i].coin<<endl;
    }
    pop(line_queue);
    for(int i=0;i<5;i++){
        cout<<"==============\n";
        cout<<line_queue[i].player_num<<": "<<line_queue[i].arrive_hour<<"/"<<line_queue[i].coin<<endl;
    }
    push(line_queue, player_list[0]);
    for(int i=0;i<5;i++){
        cout<<"==============\n";
        cout<<line_queue[i].player_num<<": "<<line_queue[i].arrive_hour<<"/"<<line_queue[i].coin<<endl;
    }*/


    system("pause");
    return 0;
}
