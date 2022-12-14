#ifndef COLOR_HH
#define COLOR_HH

#include <iostream>
#include <vector>
#include <random>
#include <string>


// Number of colors in a series
const unsigned int SIZE = 4;



class color
{
public:
    color();
    void make_Rancolorseries(int&);
    void make_usercolorseries();
    std::string make_gamecolorseries();
    bool check_givencolors();
    bool check_givenlength();
    std::string save_usercolorlist();
    bool operator ==(color& game_sec_col);




private:
    std:: string user_colorlist = "";
    std:: string user_colorlist1="";
    std::vector<std::string> colors_;

};

#endif // COLOR_HH
