#include "../include/display.hpp"


display::display(int x, int y)
{
    Length = x;
    Heigh = y;

    mat.resize(x, std::vector<int>(y, 0));
}

void display::print()
{
    system("clear");
    for(int y = Heigh - 1; y >= 0; --y)
    {
        for(int x = 0; x < Length; ++x)
        {
            std::cout << gradient[std::min(mat[x][y], (int)gradient.size() - 1)];
        }
        std::cout << '\n';
    }
}

void display::clear()
{
    for(int i = 0; i < mat.size(); ++i)
    {
        for(int j = 0; j < mat[i].size(); ++j)
        {
            mat[i][j] = 0;
        }
    }
}

void display::add(int x, int y)
{
    if(x < 0 || x >= Length || y < 0 || y >= Heigh)
    {
        return;
    }
    mat[x][y] += 1;
}

