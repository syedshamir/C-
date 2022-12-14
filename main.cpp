// TODO: Include your header file of the class describing a series of four colors
#include "color.hh"
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <stdlib.h>
#include <cctype>
#include <algorithm>



/* Mastermind
 *
 * Desc:
 *   This program implements a Mastermind game. First a secret series of
 * four colors is either given or drawn. The series can have several
 * identical colors, but none of the four positions can be empty.
 * The user tries to guess which colors the secret series has and in which
 * order they occur there. For this purpose, the user gives their own
 * series of four colors, and the program tells how many colors in the
 * guess was totally correct (correct color in correct position) and how
 * many of them were correct in color (but incorrect in position). After
 * that the user guesses again and so on.
 *   At first, the user is asked, if the game board will be filled with
 * randomly drawn colors, or with user-given ones. (The latter way is not
 * very sensible, but it is useful in testing purposes.) In the first
 * option, a seed value for the random number generator will be asked next.
 * In the latter option, the user is asked to input four colors (the first
 * letters of the colors, i.e. a string consisting of four characters).
 *   On each round, the user is asked for a new guess. The player wins if
 * all colors in the guess are totally correct. The player loses if they
 * have used the maximum number (10) of guesses without the right one.
 *   The program checks if the user-given colors are among accepted ones.
 * When the game ends, the program tells if the player won or lost.
 *
 * Program author ( Fill with your own info )
 * Name: SYED SHAMIR RAZA
 * Student number:150597942
 * UserID: VBSHRA
 * E-Mail: shamir.raza@tuni.fi
 *
 * * Program author ( Fill with your own info )
 * Name: USAMA ALI
 * Student number: 151265163
 * UserID: VDUSAL
 * E-Mail: usama.ali@tuni.fi
 *
 * Notes about the program and it's implementation:
 *
 * */

using namespace std;

// Maximum number of guesses
// (Not used in the template code)
//const unsigned int GUESS_MAX = 10; // Not in use, yet


// Length of the suffix part when printing a row.
// The suffix consists of three vertical lines ('|') and two digits, where one
// tells the amount of totally correct colors and the other tells the amount
// of correct colors in incorrect positions.
const unsigned int SUFFIX_LENGTH_IN_PRINT = 5;

// Text printed at the beginning of the program
const string INFO_TEXT = "Colors in use: \
B = Blue, R = Red, Y = Yellow, G = Green, O = Orange, V = Violet";
// TODO: Do you need more constants?

// Reads the input way, either random or listing way,
// and fills the color series in the user-desired way.
// Repeats the question until the user enters either R or L.
void get_input(color &sec_col_ser)
{
    int t=0;
    while(!t)

    {
        //if user selected R or r, then play game
        // call game function
        cout << "Enter an input way (R = random, L = list): ";
        string input_str = "";
        cin >> input_str;
        if(input_str == "R" or input_str == "r")
    {
        //if user selected R or r, then play game
        // call game function
        t=1;
        cout << "Enter a seed value: ";
        int seed = 0;
        cin >> seed;
        sec_col_ser.make_Rancolorseries(seed);

    }
            //if user selected L or l , then play game
            // call game function
            else if(input_str == "L" or input_str == "l")
    {
            bool accepted = false;
            t=1;

            while(not accepted)
        {
              sec_col_ser.make_usercolorseries();
        //if user prints q or Q while making secret color series, it will exit
              if(sec_col_ser.save_usercolorlist()=="q" || sec_col_ser.save_usercolorlist()=="Q")
          {
                exit(0);
          }

           if(sec_col_ser.check_givenlength()==false)
              {
                cout<<"Wrong size"<<endl;
              }
            else
            {
              if(sec_col_ser.check_givencolors())
             {
                 accepted=true;

             }
              else
                {
                  cout<<"Unknown color"<<endl;
                }

            }
        }
    }

    else
    {
        cout << "Bad input" << endl; 
    }
        }

}
        // Prints a line consisting of the given character c.
        // The length of the line is given in the parameter line_length.
void print_line_with_char(char c, unsigned int line_length)
        {
            for(unsigned int i = 0; i < line_length; ++i)
            {
                cout << c;
            }
            cout << endl;
        }

    //play game function

int playgame(color sec_col_ser, color game_sec_col)

{

   int game=0;
   std::string out[10][4];          //array to save the guesses
   std::string sec_str="";
   std::string guess_str="";

    while(game!=10)
    {

        for (int i=0; i<10;i++)
    {
           sec_str=sec_col_ser.save_usercolorlist();
           std::transform(sec_str.begin(), sec_str.end(),sec_str.begin(), ::toupper); //capitalize the string (secret_series)
           game_sec_col.make_gamecolorseries();
           guess_str=game_sec_col.save_usercolorlist();
           std::transform(guess_str.begin(), guess_str.end(),guess_str.begin(), ::toupper);   //capitalize the string (game_guess_series)

           game+=1;

           if(guess_str=="q" || guess_str=="Q")
           {
           exit(0);
           }
        else
{
           if(game_sec_col.check_givenlength()==false)

              {
                cout<<"Wrong size"<<endl;
              }
            else
           {

              if(game_sec_col.check_givencolors())
             {

            int gamecoun=0;
            int oi=guess_str.length();
            for (int t=0; t<oi; t++)
                {
                    out[i][t]=toupper(guess_str[t]);
                    if (toupper(sec_str[t])==toupper(guess_str[t]))

                    {
                        gamecoun+=1;
                    }

                }

            // use print_line_fn_here it will print "========" on top of grid

            print_line_with_char('=', 2 * (SIZE + SUFFIX_LENGTH_IN_PRINT) + 1);

            for (int r=0; r<=i; r++)

            // below lines print grid and guessed colors
            {
                int c=0;
                string current;
                for (int k=0; k<4;k++)
                {

                    if (k==0)
                    {

                        cout<<"| ";
                    }

                    current += out[r][k];
                    cout<<out[r][k]<<" ";

                    c+=1;

                    if (c==int(guess_str.length()))
                    {
                        cout<<"| ";
                    }

                }

                int count=0;
                string temp_guess;
                string temp_sec;

                // TODO:Fill color series based on the given string and check if
                // the user gave the correct amount of allowed colors
                for (int m=0; m<4;m++)

                {

                    if (sec_str[m] == current[m])

                {

                    count+=1;              //counter for the first number (telling totally correct guesses)
                    temp_guess += 'x';     //make a temp_guess string, it will put x at the same index, if guess is totally correct
                    temp_sec += 'x';       //make a temp_sec string, it will put x at the same index, if guess is totally correct
                } else {
                        temp_guess += 'o';  //make a temp_guess string, it will put o at the same index, if guess is not totally correct
                        temp_sec += 'o';    //make a temp_sec string, it will put o at the same index, if guess is not totally correct


                    }
            }
             //counter for the amount of correct colors in incorrect positions.
            int sec_count=0;
            for (int w=0; w<4; w++)
            {
               if(temp_guess[w]=='o')

               {
                for (int u=0; u<4; u++)
                {
                    if(temp_sec[u]=='o' && current[w]==sec_str[u])

                    {
                    sec_count+=1;
                    temp_sec[u]='x';
                    temp_guess[w]='x';
                    break;
                    }
                 }

                }
             }

              cout<<count<<" | "<<sec_count<<" |"<<endl;
            }
            // use print_line_fn_here it will print "========" on top of grid

            print_line_with_char('=', 2 * (SIZE + SUFFIX_LENGTH_IN_PRINT) + 1);

            //if the game is won, game counter and will be 4 and it will print YOU WON, it will exit

            if (gamecoun==4)
                    {
                        cout<<"You won: Congratulations!"<<endl;
                        exit(0);
                    }
                }


              else
                {
                  cout<<"Unknown color"<<endl;
                 }
          }

            // TODO: Update the boolean variable called accepted
        }

        }

        // if user takes all 10 guesses wrong
        if (game==10)
        {
        cout<<"You lost: Maximum number of guesses done"<<endl;
        }
}
    return 0;


}


// Prints all color series.
// (Not called in the template code.)
void print_all(/* a vector including color series */)
{
    print_line_with_char('=', 2 * (SIZE + SUFFIX_LENGTH_IN_PRINT) + 1);
    //for(/* go through the vector */)
    {
        // TODO: print each vector element (color series)
    }
    print_line_with_char('=', 2 * (SIZE + SUFFIX_LENGTH_IN_PRINT) + 1);
}


// Implements the actual game loop, where user-given guesses are read
// and compared to the secret row.
// On each round, all rows given so far are printed.
int main()
{


    cout << INFO_TEXT << endl;
    print_line_with_char('*', INFO_TEXT.size());

    // TODO: Declare an object for a color series (the secret one)
    color sec_col_ser=color();
    get_input(sec_col_ser);

    // TODO: Play the game, i.e. repeatedly read a user given number series
    // and compare it with the secret one
    // TODO: Declare a second object for a color series (the game guess secret)
    color game_sec_col=color();
    playgame(sec_col_ser, game_sec_col);

    return 0;
}

