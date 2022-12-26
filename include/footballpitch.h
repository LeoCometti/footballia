#ifndef FOOTBALLPITCH_H
#define FOOTBALLPITCH_H

#include "raylib.h"

class FootballPitch
{
    public:
        FootballPitch(void);
        ~FootballPitch(void);
        void Draw();
        Vector2 GetCentreSpot();
        Rectangle GetPitchLimits();
    private:   
        Color PITCH = Color { 0, 174, 0, 255 };
        float ratio;
        float zero_x;
        float zero_y; 
        float width;
        float height;
        // Stadium & pitch
        Rectangle stadium;
        Rectangle pitch_limits;
        // Left objects
        Rectangle goal_left;
        Rectangle goal_area_left;
        Rectangle penalty_area_left;
        Vector2 penalty_spot_left;
        Vector2 corner_arc_up_left;
        Vector2 corner_arc_down_left;
        // Right objects
        Rectangle goal_right;
        Rectangle goal_area_right;
        Rectangle penalty_area_right;
        Vector2 penalty_spot_right;
        Vector2 corner_arc_up_right;
        Vector2 corner_arc_down_right;
        // Center objects
        Vector2 halfway_line_startPos;
        Vector2 halfway_line_endPos;
        Vector2 centre_spot;
};

#endif