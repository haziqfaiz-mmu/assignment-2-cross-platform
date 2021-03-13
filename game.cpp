/********************************************
Course : TCP1101 Programming Fundamentals
Session: Trimester 2, 2020/21
Assignment: 2
Lecture Section : TC1V
Tutorial Section: TT1V
Name of Student #1 : MUHAMMAD HAZIQ FAIZ BIN MOHD RIPIN
ID of Student #1: 1201302740
Email of Student #1:1201302740@student.mmu.edu.my
Phone of Student #1:0132061817
Name of Student #2 : KAVIILASAN A/L GANESAN
ID of Student #2: 1181103578
Email of Student #2:1181103578
Phone of Student #2:016-2632704
********************************************/
#include "game.h"
#include "include.h"

Game::Game(Map &Mars){
    p_mars = &Mars;
}

void Game::WelcomeLights(){

    cout <<RED<<"*******************************"<<endl;
	cout <<RED<<"   WELCOME TO MARS ROVER!!!"<<endl;
    cout <<RED<<"   LET'S EXPLORE MARS!!!"<<endl;
    cout <<RED<<"*******************************"<<endl;

    cout <<"                        "<<endl;
    cout <<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout <<"   MISSION:FIND GOLDS!!!"<<endl;
    cout <<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	
	//changeColour(GREEN);
    cout <<GREEN<<"                "<<endl;
    cout <<GREEN<<"============================="<<endl;
	cout <<GREEN<<"   PRESENTED BY:"<<endl;
	
	//changeColour(BLUE);
	cout <<GREEN<<"   HAZIQ"<<endl;
    cout <<GREEN<<"   KAVIILASAN"<<endl;
    cout <<GREEN<<"============================="<<endl;
}

void Game::alien(){

    cout<<BOLDRED<<"         -888888888888888-        "<<endl;
     cout<<RED<<"      8888888888888888888888      "<<endl;
     cout<<RED<<"    88888888888888888888888888    "<<endl;
     cout<<RED<<"   8888888888888888888888888888   "<<endl;
     cout<<RED<<"  888888888888888888888888888888  "<<endl;
     cout<<RED<<"    88888     p88888q     88888   "<<endl;
     cout<<RED<<"     88888    p88888q    88888    "<<endl;
     cout<<RED<<"       8888   p88888q   8888      "<<endl;
     cout<<RED<<"        888888888888888888        "<<endl;
     cout<<RED<<"          88888888888888          "<<endl;
     cout<<RED<<"            8888888888            "<<endl;
     cout<<RED<<"              8888888             "<<endl;
     cout<<RED<<"                888               "<<WHITE<<endl;
}

void Game::startsequence(){

    cout << "\n";
	
	WelcomeLights();
    cout << "\n\n\n";
    alien();

    cout<<setw(40)<<"The objective is to collect ALL the gold before you run out of moves"<<endl;
    cout<<setw(40)<<"Initially the rover has 50 number moves points"<<endl;
    cout<<setw(40)<<"You can't go over a a hill and moving through traps will cost you 10 move points"<<endl;
    cout<<setw(40)<<"Collecting the booster will gives the rover 5 move points "<<endl;

	cout << "\n\n\n";
    this_thread::sleep_for(chrono::milliseconds(5000) );

}

void Game::EndingLights(int x){

    //changeColour(YELLOW);
    cout <<YELLOW<<"                                          "<<endl;
    cout <<YELLOW<<setw(50)<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout <<YELLOW<<setw(50)<<"   HOPE YOU ENJOYED EXPLORING MARS!!!"<<endl;
    cout<<YELLOW<<setw(43)<< "         FINAL SCORE IS           "<<x<<endl;
    cout <<YELLOW<<setw(50)<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
}

void Game::gameOver(){

    cout<<BOLDRED<<"888888     888   88     88  88888         88888  8         8 88888 88888"<<endl;
    cout         <<"8         8   8  8 8   8 8  8            8     8  8       8  8     8   8"<<endl;
    cout         <<"8         8   8  8  8 8  8  8            8     8   8     8   8     8   8"<<endl;
    cout         <<"8   8888  88888  8   8   8  88888        8     8    8   8    88888 888"<<endl;
    cout         <<"8    8    8   8  8       8  8            8     8     8 8     8     8  8"<<endl;
    cout         <<"888888    8   8  8       8  88888         88888       8      88888 8   8"<<WHITE<<endl;

}

void Game::success(){

    cout<<BOLDGREEN<<"888888    8   8  88888888  88888888  88888888  88888888 88888888"<<endl;
    cout         <<"8         8   8  8         8         8         8        8  "<<endl;
    cout         <<"8         8   8  8         8         8         8        8  "<<endl;
    cout         <<"888888    8   8  8         8         88888888  88888888 88888888"<<endl;
    cout         <<"     8    8   8  8         8         8                8        8"<<endl;
    cout         <<"888888    88888  88888888  88888888  88888888  88888888 88888888"<<WHITE<<endl;

    cout<<setw(50)<<"You collected ALL the golds on Mars"<<endl;
    cout<<setw(35)<<"Mission Succesfull!!!"<<endl;

}

void Game::displayRealMap(){
    char decision;
    cout<<"Do you want to see the entire map of Mars? (Y/N)"<<endl;
    cin>>decision;
    if(decision=='Y')
        p_mars->display();
}

void Game::gameOverSequence(int x){

    clear();
    cout << "\n";
	
	EndingLights(x);
    cout << "\n\n\n";
    gameOver();
	
	cout << "\n\n\n";
    this_thread::sleep_for(chrono::milliseconds(5000) );;
}

void Game::successSequence(int x){

    clear();
    cout << "\n";
	
	EndingLights(x);
    cout << "\n\n\n";
    success();
	
	cout << "\n\n\n";
    this_thread::sleep_for(chrono::milliseconds(5000) );;
}