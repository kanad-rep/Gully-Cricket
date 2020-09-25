/*
 ============================================================================
 Name        : Gully Cricket App
 Author      : Kanad Das
 Description : A simple game of cricket comprising two innings, each consisting of six balls.
 ============================================================================
 */

//Declaration of libraries
#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

using namespace std;

//Declaration of functions
void greet_user();
void display_team_details(string [], string []);
void select_batsman_and_bowler(string [], string []);
void start_innings(int , string , string);
int play_innings();
void display_score(string, int);
void decide_winner(int , int );

// Declaration of global variables
string current_batsman;
string current_bowler;

int main() {

	//Declaration of the class
	class Team {
		public:
			int runs_scored;
			string team_name;
			string players[3];

	};

	Team team_A;
	team_A.team_name = "Team A";
	team_A.players[0] = "Virat Kohli";
	team_A.players[1] = "Yuvraj Singh";
	team_A.players[2] = "Hardik Pandya";

	Team team_B;
	team_B.team_name = "Team B";
	team_B.players[0] = "MS Dhoni";
	team_B.players[1] = "Ravindra Jadeja";
	team_B.players[2] = "Jasprit Bumrah";

	greet_user();
	sleep(4);
	display_team_details(team_A.players, team_B.players);

	cout << "\n============================================================================ \n" << endl;
	cout << "Starting Match..." << endl;
	cout << "============================================================================ \n" << endl;

	sleep(5);
	// First innings

	select_batsman_and_bowler(team_A.players, team_B.players);
	start_innings(1, team_A.team_name, team_B.team_name);
	sleep(5);
	team_A.runs_scored = play_innings();
	display_score(team_A.team_name, team_A.runs_scored);

	cout << "============================================================================" << endl;
	cout << "End of First Innnings!" << endl;
	cout << "============================================================================ \n" << endl;

	sleep(5);
	// Second Innings

	select_batsman_and_bowler(team_B.players, team_A.players);
	start_innings(2, team_B.team_name, team_A.team_name);
	sleep(5);
	team_B.runs_scored = play_innings();
	display_score(team_B.team_name, team_B.runs_scored);

	cout << "============================================================================" << endl;
	cout << "End of Second Innnings!" << endl;
	cout << "============================================================================ \n" << endl;

	sleep(5);
// Deciding the results

	decide_winner(team_A.runs_scored, team_B.runs_scored);
	return 0;
}

void greet_user() {
	cout << "============================================================================" << endl;
	cout << "Welcome to Gully Cricket 2020!" << endl;
	cout << "============================================================================ \n" << endl;

	sleep(2);
	cout << "Creating Teams..." << endl;
	cout << "============================================================================ \n" << endl;
}

void display_team_details(string team_1[], string team_2[]) {
		cout << "Players of Team A:" << endl;
		for(int i=0; i< 3; i++) {
			cout << "Player " << i+1 << ": " << team_1[i] << endl;
		}
		cout << endl << "Players of Team B:" << endl;
				for(int j=0; j< 3; j++) {
					cout << "Player " << j+1 << ": " << team_2[j] << endl;
				}
	}

void select_batsman_and_bowler(string team_1[], string team_2[]) {

	srand(time(NULL));

	int idx = rand()%3;
	current_batsman = team_1[idx];

	idx = rand()%3;
	current_bowler = team_2[idx];
}

void start_innings(int inn_no, string batting_team, string bowling_team) {
	cout << "Innings " << inn_no << "\n" << endl;
	cout << "============================================================================ \n" << endl;

	cout << "Batting: \t " << batting_team  <<"\t Bowling: \t " << bowling_team << endl;
	cout << "Current Batsman:\t " << current_batsman  << endl << "Current Bowler:\t " << current_bowler << endl;
}

int play_innings() {
	int total_runs = 0;
	srand(time(NULL));
	cout << "Ball \t \t" << "Runs" << endl;
	for(int i = 0; i< 6; i++) {
		int run = rand()%7;
		cout << i+1 << "\t \t" << run << endl;
		total_runs += run;
		sleep(2);
	}
	return total_runs;
}

void display_score(string team, int total_runs) {
	cout << "Total Runs scored by " << team << ": \t\t" << total_runs << endl;
}

void decide_winner(int team1_score, int team2_score) {

	if (team1_score > team2_score) {

		cout << "\n============================================================================" << endl;
		cout << "Team A wins!" << endl;
		cout << "============================================================================ \n" << endl;
	}
	else if (team2_score > team1_score) {

		cout << "\n============================================================================" << endl;
		cout << "Team B wins!!" << endl;
		cout << "============================================================================ \n" << endl;
		}
	else {

		cout << "\n============================================================================" << endl;
		cout << "Match Tied!" << endl;
		cout << "============================================================================ \n" << endl;
	}
}
