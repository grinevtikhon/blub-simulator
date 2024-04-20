

const int ROOM_MAX_X = 200;
const int ROOM_MAX_Y = 100;
const int ROOM_MIN_X = 0;
const int ROOM_MIN_Y = 0;

const float EPS = 1;

const float TICK = 1e-1;
const float ALPHA = 1e-2;

float force_function(float dist);

class object
{
    float v_x;
    float v_y;
    
    float a_x;
    float a_y;

    public:

    float x;
    float y;

    object();
    void next_tick();
    void interact_with(object &obj);
    void set_random_locate();
};