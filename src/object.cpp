#include "../include/object.hpp"
#include <cmath>
#include <random>

std::mt19937 random_value(239);

float force_function(float dist)
{
    if(dist < EPS)
    {
        return 0;
    }

    if (dist < 60)
    {
        return -dist;
    }
    else {
        return 2 * dist * dist;
    }
    return 1 * dist * dist;
}

object::object()
{
    x = 0;
    y = 0;
    v_x = 0;
    v_y = 0;
    a_x = 0;
    a_y = 0;
}
void object::set_random_locate()
{
    x = random_value() % (1 + ROOM_MAX_X - ROOM_MIN_X) + ROOM_MIN_X;
    y = random_value() % (1 + ROOM_MAX_Y - ROOM_MIN_Y) + ROOM_MIN_Y;
}

void object::next_tick()
{
    a_x -= v_x * ALPHA;
    a_y -= v_y * ALPHA;

    x += TICK * v_x + TICK * TICK  * a_x;
    y += TICK * v_y + TICK * TICK  * a_y;

    v_x += a_x * TICK;
    v_y += a_y * TICK;
    
    a_x = 0;
    a_y = 0;

    if(x < ROOM_MIN_X)
    {
        x = 2 * ROOM_MIN_X - x;
        v_x = abs(v_x);
    }
    if(x > ROOM_MAX_X)
    {
        x = 2 * ROOM_MAX_X - x;
        v_x = -abs(v_x);
    }
    if(y < ROOM_MIN_Y)
    {
        y = 2 * ROOM_MIN_Y - y;
        v_y = abs(v_y);
    }
    if(y > ROOM_MAX_Y)
    {
        y = 2 * ROOM_MAX_Y - y;
        v_y = -abs(v_y);
    }
}

void object::interact_with(object &obj)
{
    float dist = sqrt(pow(x - obj.x, 2) + pow(y - obj.y, 2));
    float f = force_function(dist);

    if(dist > EPS)
    {
        f /= dist;
    }

    a_x += f * (obj.x - x);
    a_y += f * (obj.y - y);
}