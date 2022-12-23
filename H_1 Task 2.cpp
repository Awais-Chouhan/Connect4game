/*
File Name   : Task 	2
Author Name : M.Awais
Dated       : 2020 - 10 - 15
*/

#include <iostream>
using namespace std;

class Connect4game
{
	private:
	int **ptr;
	int turn;

	public:
	Connect4game()
	{
	 turn=0;
	 ptr=NULL;
    }
    Connect4game(int t)
    {
     turn=t;
	 ptr=new int *[7];
     for(int j=0;j<7;j++)
	 	{
	 		ptr[j]=new int [7];
	 	}

	 	for(int i=0;i<7;i++)
	 	{
	 		for(int j=0;j<7;j++)
	 		{
	 			ptr[i][j]=0;
			 }
		 }
	 }

	 ~Connect4game()
	 {
	     for(int i =0; i < 7; i++)
         {
             if(ptr != NULL)
             delete[] ptr[i];
         }
         delete ptr;
	 }
	void showBoard()
	{
		cout<<"   1"<<" \t "<<"  2"<<" \t "<<"3"<<" \t "<<"4"<<" \t "<<"5"<<" \t "<<"6"<<" \t "<<"7"<<endl;
		cout<<"---------------------------------------------------------"<<endl;
		for(int i =0;i<7;i++)
		{
			cout<<"|";
			for(int j=0;j<7;j++)
			{
				if(ptr[i][j]!=0)
				{
				cout<<ptr[i][j]<<"\t|";
			    }
			    else
			    {
			    	cout<<""<<"\t|";
				}
		     }
		     cout<<endl;
		}
		cout<<"---------------------------------------------------------"<<endl;
	}
	void switchTurn(int player)
	{
		int a;
		if(player==1)
	{
		cout<<"Player 1 turn :";
		cin>>a;
		for(int i=6;i>=0;i--)
		{
		 if(ptr[i][a-1]==0)
		  {
		 	ptr[i][a-1]=1;
		 	break;
		  }
	    }
	}
	    else
	 {
	    cout<<"Player 2 turn :";
	    cin>>a;
	    for(int i=6;i>=0;i--)
		 {
		  if(ptr[i][a-1]==0)
		  {
		 	ptr[i][a-1]=2;
		 	break;
		  }
		 }

    }
}
	bool isWon()
	{
		int a=0,b=0;
		for(int i=0 ; i<7 ; i++)
		{
		 for(int j=0 ; j<7 ; j++)
		  {
		 	if(ptr[i][j]==1)
		 	{
		 		if(	j < 4 &&

                        ptr[i][j] == 1 &&
                        ptr[i][j + 1] == 1 &&
                        ptr[i][j + 2] == 1 &&
                        ptr[i][j + 3] == 1
                    )
                 {
                 	a=1;
					}
					if(	j < 3 &&

                        ptr[i][j] == 1 &&
                        ptr[i][j - 1] == 1 &&
                        ptr[i][j - 2] == 1 &&
                        ptr[i][j - 3] == 1
                    )
                 {
                 	a=1;
					}   if(	i > 2 &&

                        ptr[i][j] == 1 &&
                        ptr[i-1][j] == 1 &&
                        ptr[i-2][j] == 1 &&
                        ptr[i-3][j] == 1
                    )
                 {
                 	a=1;
					}   if(	i < 4 &&

                        ptr[i][j] == 1 &&
                        ptr[i+1][j] == 1 &&
                        ptr[i+2][j] == 1 &&
                        ptr[i+3][j] == 1
                    )
                 {
                 	a=1;
					}   if( i>2 &&	j < 4 &&

                        ptr[i][j] == 1 &&
                        ptr[i-1][j + 1] == 1 &&
                        ptr[i-2][j + 2] == 1 &&
                        ptr[i-3][j + 3] == 1
                    )
                 {
                 	a=1;
					}   if(	i < 4 && j<3 &&

                        ptr[i][j] == 1 &&
                        ptr[i+1][j - 1] == 1 &&
                        ptr[i+2][j - 2] == 1 &&
                        ptr[i+3][j - 3] == 1
                    )
                 {
                 	a=1;
					}   if(	i < 2 && j<3 &&

                        ptr[i][j] == 1 &&
                        ptr[i-1][j - 1] == 1 &&
                        ptr[i-2][j - 2] == 1 &&
                        ptr[i-3][j - 3] == 1
                    )
                 {
                 	a=1;
					}   if(	i<4 && j < 4 &&

                        ptr[i][j] == 1 &&
                        ptr[i+1][j + 1] == 1 &&
                        ptr[i+1][j + 2] == 1 &&
                        ptr[i+3][j + 3] == 1
                    )
                 {
                 	a=1;
					}
				else if(ptr[i][j]==2)
				{
					if(	j < 4 &&

                        ptr[i][j] == 2 &&
                        ptr[i][j + 1] == 2 &&
                        ptr[i][j + 2] == 2 &&
                        ptr[i][j + 3] == 2
                    )
                 {
                 	b=1;
					}
					if(	j < 3 &&

                        ptr[i][j] == 2 &&
                        ptr[i][j - 1] == 2 &&
                        ptr[i][j - 2] == 2 &&
                        ptr[i][j - 3] == 2
                    )
                 {
                 	b=1;
					}   if(	i > 2 &&

                        ptr[i][j] == 2 &&
                        ptr[i-1][j] == 2 &&
                        ptr[i-2][j] == 2 &&
                        ptr[i-3][j] == 2
                    )
                 {
                 	b=1;
					}   if(	i < 4 &&

                        ptr[i][j] == 2 &&
                        ptr[i+1][j] == 2 &&
                        ptr[i+2][j] == 2 &&
                        ptr[i+3][j] == 2
                    )
                 {
                 	b=1;
					}   if( i>2 &&	j < 4 &&

                        ptr[i][j] == 2 &&
                        ptr[i-1][j + 1] == 2 &&
                        ptr[i-2][j + 2] == 2 &&
                        ptr[i-3][j + 3] == 2
                    )
                 {
                 	b=1;
					}   if(	i < 4 && j<3 &&

                        ptr[i][j] == 2 &&
                        ptr[i+1][j - 1] == 2 &&
                        ptr[i+2][j - 2] == 2 &&
                        ptr[i+3][j - 3] == 2
                    )
                 {
                 	b=1;
					}   if(	i < 2 && j<3 &&

                        ptr[i][j] == 2 &&
                        ptr[i-1][j - 1] == 2 &&
                        ptr[i-2][j - 2] == 2 &&
                        ptr[i-3][j - 3] == 2
                    )
                 {
                 	b=1;
					}   if(	i<4 && j < 4 &&

                        ptr[i][j] == 2 &&
                        ptr[i+1][j + 1] == 2 &&
                        ptr[i+1][j + 2] == 2 &&
                        ptr[i+3][j + 3] == 2
                    )
                 {
                 	b=1;
					}

				}
			 }
		  }
		}
		   if (a == 1 && b == 1)
        {
            cout << "\nGAME DRAW" << endl;
            return true;
        }

        else if (a == 1 && b == 0)
        {
            cout << "\nCongratulations!!\nPlayer 1 won the game " << endl;
            return true;
        }

        else if (a == 0 && b == 1)
        {
            cout << "\nCongratulations!!\nPlayer 2 won the game " << endl;
            return true;
        }

        else
        {
            return false;
        }

	}
	bool isBoardFull()
	{int a=0;
		for(int i=0;i<7;i++)
		{
		  if(ptr[0][i]!=0)
		  {
		  	a++;
		  }
	    }
	    if(a==7)
		{
			return true;
		}
		return false;

	}
	void start( )
	{
		Connect4game o1(2);
		o1.showBoard();
		while(o1.isBoardFull()==false || o1.isWon()==false)
		{
			o1.switchTurn(1);
			o1.showBoard();
			if(o1.isWon())
			{
				return;
			}
			if(o1.isBoardFull())
			{
				return;
			}
			o1.switchTurn(2);
			o1.showBoard();
			if(o1.isWon())
			{
				return;
			}
			if(o1.isBoardFull())
			{
				return;
			}
		}
	}

};
int main()
{
	cout<<"WELCOME IN CONNECT 4 GAME "<<endl<<endl;

	Connect4game o2;
	o2.start();

}

