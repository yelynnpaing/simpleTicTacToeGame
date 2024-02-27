#include <iostream>

using namespace std;


///int space[] = { {(0,0), (0,1), (0,2)}, {(1,0), (1,1), (1,2)}, {(2,0), (2,1), (2,2)}};
 char space[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
};

string userOne , userTwo ;
char token = 'x';
int row , column;
bool tie = false;

void funOne()
{

    cout << "\n\n" << "  " << space[0][0] << "    " << space[0][1] << "    " << space[0][2] << endl;
    cout << "____|____" << "|____" << endl;
    cout << "    |    |    " << endl;
    cout << "  " << space[1][0] << " |" << "  " << space[1][1] << " |" << "  " << space[1][2] << endl;
    cout << "____|____" << "|____" << endl;
    cout << "    |" << "    |" << endl;
    cout << "  " << space[2][0] << "    " << space[2][1] << "    " << space[2][2] << endl;

};

void funTwo()
{
    int digit;

    if(token == 'x')
    {
        cout << "\nUser : " << userOne << ", Please enter a digit : ";
        cin >> digit;
    }
    if(token == '0')
    {
        cout << "\nUser : " << userTwo << ", Please enter a digit : " ;
        cin >> digit;
    }

    if(digit == 1)
    {
        row = 0;
        column = 0;
    }
    if(digit == 2)
    {
        row = 0;
        column = 1;
    }
    if(digit == 3)
    {
        row = 0;
        column = 2;
    }
    if(digit == 4)
    {
        row = 1;
        column = 0;
    }
    if(digit == 5)
    {
        row = 1;
        column = 1;
    }
    if(digit == 6)
    {
        row = 1;
        column = 2;
    }
    if(digit == 7)
    {
        row = 2;
        column = 0;
    }
    if(digit == 8)
    {
        row = 2;
        column = 1;
    }
    if(digit == 9)
    {
        row = 2;
        column = 2;
    }
    else if(digit < 1 || digit > 9){
        cout << "Invalid !!! Input number should be one in 1 to 9.";
    }

    if(token == 'x' && space[row][column] != 'x' && space[row][column] != '0')
    {
        space [row][column] = 'x';
        token = '0';
    }
    else if(token == '0' && space[row][column] != 'x' && space[row][column] != '0')
    {
        space[row][column] = '0';
        token = 'x';
    }
    else{
        cout << "There is no empty space...";
        funTwo();
    }
    funOne();
};

bool funThree()
{
    for(int i=0; i<3; i++)
    {
        if(space[i][0] == space[0][1] && space[i][0] == space[0][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
        {
            return true;
            cout << space[i][0] << endl;
        }
    }

    if(space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0])
    {
        return true;
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            space[i][j] != 'x' && space[i][j] != '0';
            return false;
        }
    }

    tie = true;

    return false;
}

int main()
{
    cout << "Enter First User Name : " ;
    getline(cin , userOne);

    cout << "\nEnter Second User Name : ";
    getline(cin, userTwo);

    cout << "\n" << userOne << " is player one, so do first" << endl;
    cout << "\n" << userTwo << " is plyer two, so do second";

    while(!funThree()){
        funOne();
        funTwo();
        funThree();
    }

    if(token == 'x' && tie == false)
        cout << "\nPlayer : " << userOne << " Wins the match.";
    else if(token == '0' && tie == false)
        cout << "\nPlayer : " << userTwo << " Wins the match.";
    else
        cout << "\nDraw the match.";

    return 0;
}


