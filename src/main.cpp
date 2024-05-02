#include "../include/display.hpp"
#include "../include/object.hpp"

int main()
{
    display win(40, 20);
    




    int n = 200;
    std::vector<object> dot(n);
    for(int i = 0; i < n; ++i)
    {
        dot[i].set_random_locate();
    }

    float time = 0;

    while(true)
    {

        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i != j)
                {
                    dot[i].interact_with(dot[j]);
                }
            }
        }

        for(int i = 0; i < n; ++i)
        {
            dot[i].next_tick();
        }
        
        time += TICK;
        
        win.clear();
        for(int i = 0; i < n; ++i)
        {
            int x = (dot[i].x - ROOM_MIN_X) / ((ROOM_MAX_X - ROOM_MIN_X) / win.Length);
            int y = (dot[i].y - ROOM_MIN_Y) / ((ROOM_MAX_Y - ROOM_MIN_Y) / win.Heigh);
            win.add(x, y); 
        }
        
        win.print();
        std::cout << time << '\n';
        // _sleep(1);
       
        // std::cout << dot[0].x << ' ' << dot[0].y << '\n';
        // std::cout << dot[1].x << ' ' << dot[1].y << '\n';

        //sleep(1);
    }

    
}