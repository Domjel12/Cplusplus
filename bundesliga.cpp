#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Team {
    string name;
    int points;
};

vector<Team> load(const string& filename) {
    ifstream file(filename);
    vector<Team> teams;
    string line;

        while (getline(file, line)) {
            istringstream ss(line);
            string name;
            int points;
            char delimiter;

            getline(ss, name, ',');
            ss >> points;

            Team team{name, points};
            teams.push_back(team);
        }

    return teams;
}

void print_teams(const vector<Team>& teams) {
    for (const auto& team : teams) {
        cout << setw(25) << left << team.name 
             << setw(5) << team.points << endl;
    }
}

void print_filtered_teams(const vector<Team>& teams, int start, int end, const string& description) {
    cout << description << ":" << endl;
    for (int i = start; i < end; ++i) {
        cout << setw(20) << left << teams[i].name 
             << setw(5) << teams[i].points << endl;
    }
}

int main() {
    string filename = "bundesliga_tabelle.csv";
    vector<Team> teams = load(filename);

    cout << "Alle Teams:" << endl;
    print_teams(teams);

    print_filtered_teams(teams, 0, 5, "Champions-League Teilnehmer");

    print_filtered_teams(teams, 5, 6, "Europa-League Teilnehmer");

    print_filtered_teams(teams, 6, 7, "Conference-League Teilnehmer");
    
    return 0;
}
