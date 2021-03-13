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
#include "include.h"
#include "map.h"

using namespace std;

//Function that is called by the constructor
void Map::init(){

    srand(time(0));
    char objects[] ={' ',' ',' ',' ',' ',' ',
                    'X','#','@','$'};
    
    int noOfObjects = 10;

    dimX = 15;
    dimY = 10;

    //create dynamic 2D array using vector
    map.resize(dimY); //create rows
    for (int i=0;i<dimY;i++){
        map[i].resize(dimX);//resize each row
    }

    //put random chars into the vector array
    for(int i=0;i<dimY; ++i){
        for(int j=0; j<dimX; ++j){
            int objNo = rand() % noOfObjects;
            map[i][j] = objects[objNo];
        }
    }
}
void Map::resize(int new_dimX, int new_dimY, char ch){

    dimX = new_dimX;
    dimY = new_dimY;
}

//display the map
void Map::display(){

    system("clear");

    for(int i=0; i<dimY; ++i){
    cout<<" ";
        for(int j=0;j<2*dimX; ++j){
            cout<<BOLDRED<<"+-"<<WHITE;
        }
        cout<<BOLDRED<<"+"<<WHITE<<endl;
        cout<<setw(2)<<(dimY-i);

        for(int j=0; j<dimX;++j){
        
                if(map[i][j] == '$'){
                    cout<<BOLDRED<<"| "<<BOLDYELLOW<<map[i][j]<<WHITE<<" ";
                }

                else if(map[i][j] == '@'){
                    cout<<BOLDRED<<"| "<<BOLDMAGENTA<<map[i][j]<<WHITE<<" ";
                }

                else if(map[i][j]== 'X'){
                    cout<<BOLDRED<<"| "<<BOLDGREEN<<map[i][j]<<WHITE<<" ";
                }

                else if(map[i][j] == '#'){
                    cout<<BOLDRED<<"| "<<RED<<map[i][j]<<WHITE<<" ";
                }

                else if(map[i][j] == '<'||map[i][j] == '^'||map[i][j] == '>'||map[i][j] == 'V'){
                    cout<<BOLDRED<<"| "<<BOLDBLUE<<map[i][j]<<WHITE<<" ";
                }

                else
                    cout<<BOLDRED<<"| "<<WHITE<<map[i][j]<<" ";
         
        }
        
        cout<<BOLDRED<<"|"<<WHITE<<endl;
    }

    cout<<" ";
    for(int j=0;j<2*dimX;++j){
        cout<<BOLDRED<<"+-"<<WHITE;
    }
    cout<<BOLDRED<<"+"<<WHITE<<endl;

    cout<<" ";
    for(int j=0; j<dimX; ++j){
        int digit = (j+1);
        cout<<" ";
        if(digit==0)
            cout<<" ";
        else
            cout<<setw(3)<<digit;
    }
    cout<<endl;

    cout<<endl<<endl;

}

//empty the map
void Map::emptyMap(){
    for(int i=0;i<dimY; ++i){
        for(int j=0; j<dimX; ++j){
            map[i][j] = ' ';
        }
    }
}


//set the object at coordinate x,y
void Map::setObject(int x, int y, char ch){

    //This piece set object in the next cell
    if(x>15)
        x =1;
    if(y>10)
        y=1;
    if(x<1)
        x=15;
    if(y<1)
        y=10;

    map[(dimY-y)][x-1] = ch;
}

//get the object in coordinate x,y
char Map::getObject(int x, int y){

    if(x>15)
        x =1;
    if(y>10)
        y=1;
    if(x<1)
        x=15;
    if(y<1)
        y=10;

    char obj =map[dimY-y][x-1];
        return obj;
}

//get obect but use index notation
char Map::getObjectArray(int x, int y){

    return map[x][y];
}

//check whether the cell is empty
bool Map::isEmpty(int x, int y){

    if (map[dimY-y][x-1] ==' ')
        return true;
    
    else
        return false;
}
//check for gold
bool Map::isGold(int x, int y){

    if (map[dimY-y][x-1] =='$')
        return true;
    
    else
        return false;
}
//check for hill
bool Map::isHill(int x, int y){

    //This piece check for hill in the next cell
    if(x>15)
        x =1;
    if(y>10)
        y=1;
    if(x<1)
        x=15;
    if(y<1)
        y=10;

    if (map[dimY-y][x-1] =='@')
        return true;
    
    else
        return false;
}

//check for trap
bool Map::isTrap(int x, int y){

    if (map[dimY-y][x-1] =='#')
        return true;
    
    else
        return false;
}

//check for booster
bool Map::isBooster(int x, int y){

    if (map[dimY-y][x-1] =='X')
        return true;
    
    else
        return false;
}

//check to see if the rover is inside the map
//doesn't make any sense, I wan to change it
bool Map::isInsideMap(int x, int y){

    if((x>=1 && x<=dimX) && (y>=1 && y<=dimY))
        return true;

    else
        return false;
}
int Map::getDimX(){

    return dimX;
}
int Map::getDimY(){

    return dimY;
}