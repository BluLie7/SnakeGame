#include <iostream>
#include <ctype.h>
using namespace std;
int main() {

    int gridlen;

    cin>>gridlen;
    char grid[gridlen][gridlen+1];
    int snakepos;
    int snakepos2;
    cin>>snakepos>>snakepos2;
    int applepos;
    int applepos2;
    cin>>applepos>>applepos2;
    for (int i = 0; i < gridlen; i++) {
        for (int j = 0; j < gridlen; j++) {
            grid[i][j]= 'O';
        }
    }
    grid[snakepos][snakepos2]='S';
    grid[applepos][applepos2]='A';

    while(applepos!=snakepos||applepos2!=snakepos2)
    {
        for (int i = 0; i<=gridlen ; ++i) {
            for (int j = 0;j<=gridlen  ; ++j) {
                cout<<grid[i][j]<<" ";
            }cout<<endl;
        }
        char WTG;
        cin>>WTG;
        if(tolower(WTG)=='a')
        {
            grid[snakepos][snakepos2]='O';
            grid[snakepos][snakepos2-1]='S';
            snakepos2=snakepos2-1;
            if(snakepos2<0)
            {
                cout<<"Invalid Move Repeat";
                cout<<endl;
                grid[snakepos][snakepos2+1]='S';
                snakepos2=snakepos2+1;
            }
        }
        if(tolower(WTG)=='d')
        {
            grid[snakepos][snakepos2]='O';
            grid[snakepos][snakepos2+1]='S';
            snakepos2=snakepos2+1;
            if(snakepos2>gridlen-1)
            {
                cout<<"Invalid Move Repeat";
                cout<<endl;
                grid[snakepos][snakepos2-1]='S';
                snakepos2=snakepos2-1;
            }
        }
        if(tolower(WTG)=='w')
        {
            grid[snakepos][snakepos2]='O';
            grid[snakepos-1][snakepos2]='S';
            snakepos=snakepos-1;
            if(snakepos<0)
            {
                cout<<"Invalid Move Repeat";
                cout<<endl;
                grid[snakepos+1][snakepos2]='S';
                snakepos=snakepos+1;
            }
        }
        if(tolower(WTG)=='s')
        {
            grid[snakepos][snakepos2]='O';
            grid[snakepos+1][snakepos2]='S';
            snakepos=snakepos+1;
            if(snakepos>gridlen-1)
            {
                cout<<"Invalid Move Repeat";
                cout<<endl;
                grid[snakepos-1][snakepos2]='S';
                snakepos=snakepos-1;
            }
        }
        if(snakepos2+1==gridlen)
        {
            grid[snakepos][snakepos2+1]='\0';
        }
        if(snakepos+1==gridlen)
        {
            grid[snakepos+1][snakepos2]='\0';
        }
    }
    for (int i = 0; i <=gridlen; ++i) {
        for (int j = 0; j <=gridlen ; ++j) {
            cout<<grid[i][j]<<" ";
        }cout<<endl;
    }
    cout<<"YOU HAVE EATEN THE APPLE YEY";
    return 0;
}
