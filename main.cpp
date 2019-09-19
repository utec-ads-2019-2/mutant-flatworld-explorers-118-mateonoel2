#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    bool map[y][x];
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            map[i][j] = false;
        }
    }
    int robotX, robotY;
    char orientation;
    string instructions;

    while(cin>>robotX>>robotY>>orientation) {
        cin>>instructions;
        bool count = false;
        for(int i = 0; i<instructions.size(); i++){
            if(instructions[i]=='F'){
                if (orientation == 'N') {
                    ++robotY;
                }
                else if (orientation == 'E') {
                    ++robotX;
                }
                else if (orientation == 'S') {
                    --robotY;
                }
                else if (orientation == 'W') {
                    --robotX;
                }
            }
            if(instructions[i]=='R'){
                if (orientation == 'N') {
                    orientation = 'E';
                }
                else if (orientation == 'E') {
                    orientation = 'S';
                }
                else if (orientation == 'S') {
                    orientation = 'W';
                }
                else if (orientation == 'W') {
                    orientation = 'N';
                }
            }
            if(instructions[i]=='L'){
                if (orientation == 'N') {
                    orientation = 'W';
                }
                else if (orientation == 'E') {
                    orientation = 'N';
                }
                else if (orientation == 'S') {
                    orientation = 'E';
                }
                else if (orientation == 'W') {
                    orientation = 'S';
                }
            }
            if(robotY>y or robotX>x or robotX<0 or robotY<0){
                if (orientation == 'N') --robotY;
                else if (orientation == 'E') --robotX;
                else if (orientation == 'S') ++robotY;
                else if (orientation == 'W') ++robotX;

                if (map[robotY][robotX]) continue;
                count = true;
                map[robotY][robotX] = true;
                break;
            }
        }

        cout << robotX << " " << robotY << " " << orientation <<(count ? " LOST" : "")<< '\n';

    }
            return 0;
}
