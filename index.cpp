#include<iostream>
 using namespace std;
 char board[3][3]={
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
 }
 char currentPlayer='X';
 void displayboard()
 {
    cout<<"/n";
    for(int i=0;i<3;i++)
    {
        cout<" "<<board[i][0]<<"|"<<board[i][1]<<"|"<<board[i][2]<<endl;
        if(i<2)
        cout<<"---|---|---"<<endl;
    }
    cout<<"/n";
 }
 bool checkwin(0)
{
  for(i=0;i<3;i++)
  {
   if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
   return true;
   if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
   return false;
  }
  if(board[0][0]==board[1][1]&&board[1][1]==board[2][2])
  return true;
  if(board[0][2]==board[1][1]&&board[1][1]==board[2][0])
  return true;
else
return false;
}
bool checkdraw()
{
   for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
          if(board[i][j]!='X'&&board[i][j]!='o')
          return false;
      }
    }
    return true;
}
void makemove(int choice)
{
   int row=(choice-1)/3;
   int col=(choice-1)%3;
   
   if(board[row][col]!='X'&& board[row][col]!='o')
   {
      board[row][col]=currentPlayer;
      currentPlayer=(currentPlayer=='X')?'o':'X';
   }
   else{
      cout<<"cell already occupied!Try Again\n";
   }
}
int main()
{
   int choice;
   while(true)
   {
      displayboard();
      cout<<"player"<<currentPlayer<<"enter your choice 1-9";
      cin>>choice;
      if(choice<1||choice>9)
      {
         cout<<"invalid choice!try again";
         continue;
      }
      makemove(choice);
      if(checkwin())
      {
         displayboard();
         cout<<"player"<<(currentPlayer=='X'?'o':'x)<<"wins!\n";
            break;
      }
      if(checkdraw())
      {
      
      displayboard();
      cout<<"it's a draw!\n";
      break;}
   }
      return 0;
}
