#include "Player.hpp"

Player::Player()
    : Character("assets/mainCharacter.png", "player")
{
    attacking = false;
    walking_frames = 8;
    att_frames = 6;
    health = 1500;
    damage = 10;

    //creating animation arrays
    walking_down_arr = new SDL_Rect[walking_frames];
    walking_up_arr = new SDL_Rect[walking_frames];
    walking_left_arr = new SDL_Rect[walking_frames];
    walking_right_arr = new SDL_Rect[walking_frames];
    attack_arr = new SDL_Rect[att_frames];

    //set player frames
    for (int i = 0; i < walking_frames; i++)
    {
        //initializing arrays to hold animation frames
        walking_down_arr[i].x = 0 + i * 64;
        walking_down_arr[i].y = 650;
        walking_down_arr[i].w = 63;
        walking_down_arr[i].h = 60;

        walking_up_arr[i].x = 0 + i * 64;
        walking_up_arr[i].y = 520;
        walking_up_arr[i].w = 63;
        walking_up_arr[i].h = 60;

        walking_left_arr[i].x = 0 + i * 64;
        walking_left_arr[i].y = 580;
        walking_left_arr[i].w = 63;
        walking_left_arr[i].h = 60;

        walking_right_arr[i].x = 0 + i * 64;
        walking_right_arr[i].y = 710;
        walking_right_arr[i].w = 63;
        walking_right_arr[i].h = 60;
    }

    for (int i = 0; i < att_frames; i++)
    {
        attack_arr[i].x = 0 + i * 64;
        attack_arr[i].y = 970;
        attack_arr[i].w = 63;
        attack_arr[i].h = 60;
    }

    //default static animation
    init_rec = {0, 140, 70, 60};

    src_rec = init_rec;
    dest_rec.w = src_rec.w;
    dest_rec.h = src_rec.h;
    dest_rec.x = x_pos;
    dest_rec.y = y_pos;

    m_direction = "static";
    speed = 4.2;
}

void Player::movement()
{
    if (isDead)
    {
        return;
    }

    //player coordinate updates in accordance to direction
    if (m_direction == "up" and u_movable)
    {
        y_pos -= speed;
        Character::update_location();
    }
    else if (m_direction == "down" and d_movable)
    {
        y_pos += speed;
        Character::update_location();
    }
    else if (m_direction == "right" and r_movable)
    {
        x_pos += speed;
        Character::update_location();
    }
    else if (m_direction == "left" and l_movable)
    {
        x_pos -= speed;
        Character::update_location();
    }
    else
    {
        Character::update_location();
    }
}

void Player::dialogue() {}
void Player::attack()
{
    if (attacking)
    {
        frame++;
        //std::cout << frame << std::endl;

        if (frame / att_frames >= att_frames)
        {
            frame = 0;
            attacking = false;
            src_rec = init_rec;
            return;
        }

        src_rec = attack_arr[frame / att_frames];

        dest_rec.x = x_pos;
        dest_rec.y = y_pos;
    }
}
void Player::get_state() {}

int &Player::get_currentscore()
{
    return current_score;
}


int Player::get_previous_score()
{
     std:: ifstream fio;
    int s;

    fio.open("scorefile.txt");
    while(fio>>s)
    {
        previous_score = s;

    }
    fio.close();
    return previous_score;
}
int Player::show_highscore(std::string filename)
{
    std:: ifstream fio;
    int s;

    fio.open(filename);
    while(fio>>s)
    {
        previous_score = s;

    }
    fio.close();
    return previous_score;
   
    
}

void Player::update_highscore(std::string filename)
{
    std::ofstream fio;
    std::cout<<"here3"<<std::endl;
    fio.open(filename,std::ios:: out);
    
        std::cout << "Writing hi score to file: " << current_score << std::endl;
        fio << current_score;

        fio.close();
   
}

Player::~Player()
{
    //deletion of walking arrays in Character
    delete attack_arr;
}
