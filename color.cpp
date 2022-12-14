#include "color.hh"
#include <iostream>
#include <vector>
#include <random>
#include <string>

color::color()
{

}


void color::make_Rancolorseries(int &seed)
{
    std::vector<char> color_set {'b', 'r','y', 'g','o','v'};
    enum c {b, r,y, g,o,v};
    static std::uniform_int_distribution<int> distribution(b, v);
    static std::default_random_engine gen(seed);
    for (uint i=0; i<SIZE; i++)
    {
    int a =distribution(gen);
    user_colorlist.push_back(color_set.at(a));
     }
}


//function which takes user secret color series if user press L or l as input way
;
void color::make_usercolorseries()
{
    std::cout << "Enter four colors (four letters without spaces): ";
    //std::string user_colorlist = "";
    std::cin >> user_colorlist;
}

//function just returns the user secret color list
std::string color::save_usercolorlist()
{
    return user_colorlist;
}

//function takes game guesses color series

std::string color::make_gamecolorseries()
{
     std::cout << "ROW> ";
     std::cin >> user_colorlist;
     return user_colorlist;
}

//function checks if the typed color series if with in allowed colors
bool color::check_givencolors()
{
    int s=0;
    std::string allowed_colors="brygov";
    for (char c: user_colorlist)
    {
        for (char j:allowed_colors)
        {
            if (c==j)
            {
                s++;
            }
        }
    }

    if ( s==4)
   {
       return true;
   }

   else
   {
       return false;
     }

}

//function checks if the typed color series if with in allowed given length
bool color::check_givenlength()
{

   return(user_colorlist.length()==SIZE);
}


