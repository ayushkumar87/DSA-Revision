#include <iostream>
#include <vector>
#include <string>
using namespace std;

string SHOW_STATUS(int i) {
    switch (i) {
        case 0:  return "";
        case 1:  return "not out";
        case 2:  return "bold out";
        case 3:  return "caught out";
        case 4:  return "run out";
        default: return "unknown";
    }
}

class Team {
    string team_name;
    vector<string> p_name;
    vector<int> p_run;
    vector<int> p_status;
    vector<int> p_ball;
    int p_num;
    int Extra_run;

public:
    Team() {
        team_name = "INDIA";
        Extra_run = 0;
        p_num = 0;
    }

    int Init() {
        cout << "Enter Team Name: ";
        cin >> team_name;
        cout << "No of players of the team: ";
        cin >> p_num;

        p_name.resize(p_num);
        p_run.resize(p_num, 0);
        p_status.resize(p_num, 0);
        p_ball.resize(p_num, 0);

        cout << "Enter Names of the Players:\n";
        for (int i = 0; i < p_num; i++) {
            cout << "Player " << i + 1 << ": ";
            cin >> p_name[i];
        }
        return p_num;
    }

    string get_name(int i) { return p_name[i]; }
    int get_run(int i) { return p_run[i]; }
    int get_status(int i) { return p_status[i]; }
    int get_extra() { return Extra_run; }
    int get_ball(int i) { return p_ball[i]; }
    string get_t_name() { return team_name; }

    int get_Total() {
        int total = Extra_run;
        for (int run : p_run)
            total += run;
        return total;
    }

    void Add_Run(int player_num, int run) {
        p_run[player_num] += run;
    }

    void Set_Status(int player, int status) {
        p_status[player] = status;
    }

    void Set_Out(int out_player, int type, int new_player) {
        p_status[out_player] = type;
        p_status[new_player] = 1;
    }

    void Set_Ball(int player) {
        p_ball[player]++;
    }

    void Set_Extra(int run) {
        Extra_run += run;
    }
};

class myscore {
    int player1, player2;
    int Ball_count, Over;
    int Max_Over, Out, Max_out;
    Team team1;
    int extra;

public:
    myscore() {
        player1 = player2 = 0;
        Over = Out = Ball_count = 0;
        Max_out = team1.Init();

        cout << "\nEnter number of Overs in one Innings: ";
        cin >> Max_Over;

        while (true) {
            cout << "\nChoose Opening Batsmen (1-" << Max_out << "):\n";
            cout << "Batsman 1: "; cin >> player1;
            cout << "Batsman 2: "; cin >> player2;

            if (player1 <= 0 || player1 > Max_out || player2 <= 0 || player2 > Max_out || player1 == player2) {
                cout << "Invalid entry, try again.\n";
            } else {
                player1--; player2--; // to convert to 0-based indexing
                team1.Set_Status(player1, 1);
                team1.Set_Status(player2, 1);
                break;
            }
        }
    }

    void show();
    void ch();
    void dot_ball();
    void add_run();
    void wicket();
    void extra1();
    void over_complete();
};

void myscore::show() {
    cout << "\n//////////////////////////////////////////////////\n";
    cout << "               " << team1.get_t_name() << " Score\n";
    cout << "//////////////////////////////////////////////////\n";

    for (int i = 0; i < Max_out; i++) {
        cout << team1.get_name(i) << " - " << SHOW_STATUS(team1.get_status(i)) << " " << team1.get_run(i);
        if (team1.get_status(i)) cout << " (" << team1.get_ball(i) << ")";
        cout << endl;
    }

    cout << "\nExtra: " << team1.get_extra() << endl;
    cout << "--------------------------------------------------\n";
    cout << "Over " << Over << "." << Ball_count << "  |  Wickets: " << Out << "  |  Total: " << team1.get_Total() << "\n";

    if (Over < Max_Over && Out < Max_out) {
        ch();
    }
}

void myscore::ch() {
    int option;
    cout << "\nChoose option:\n";
    cout << "[1] Dot Ball  [2] Add Run  [3] Extra  [4] Wicket  [10] Exit\n";
    cout << "Option: ";
    cin >> option;

    switch (option) {
        case 1: dot_ball(); break;
        case 2: add_run(); break;
        case 3: extra1(); break;
        case 4: wicket(); break;
        case 10: return;
        default: cout << "Invalid input.\n"; ch(); break;
    }
}

void myscore::dot_ball() {
    Ball_count++;
    team1.Set_Ball(player1);
    if (Ball_count == 6) over_complete();
    else show();
}

void myscore::extra1() {
    cout << "Extra runs: ";
    cin >> extra;
    team1.Set_Extra(extra);
    show();
}

void myscore::add_run() {
    int runs;
    cout << "Runs scored: ";
    cin >> runs;

    Ball_count++;
    team1.Set_Ball(player1);
    team1.Add_Run(player1, runs);

    if (runs % 2 == 1) swap(player1, player2);

    if (Ball_count == 6) over_complete();
    else show();
}

void myscore::over_complete() {
    Over++;
    Ball_count = 0;
    swap(player1, player2);
    if (Over == Max_Over) {
        cout << "\n\n*************\nInnings Complete\n*************\n";
        show();
    } else {
        show();
    }
}

void myscore::wicket() {
    int o_type, new_player;
    cout << "Out type? (Bold-1, Caught-2, Run Out-3): ";
    cin >> o_type;

    Out++;
    Ball_count++;
    team1.Set_Ball(player1);
    team1.Set_Status(player1, o_type + 1);

    if (Out >= Max_out) {
        cout << "\n\n*************\nInnings Complete\n*************\n";
        show();
        return;
    }

    cout << "New Batsman Number (1-" << Max_out << "): ";
    cin >> new_player;
    new_player--;

    team1.Set_Out(player1, o_type + 1, new_player);
    player1 = new_player;

    if (Ball_count == 6) over_complete();
    else show();
}

int main() {
    myscore MS;
    MS.show();
    return 0;
}
