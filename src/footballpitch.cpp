#include "footballpitch.h"

// Constructor

FootballPitch::FootballPitch()
{
    ratio = 10.0F;
    zero_x = ratio * 7.5F;
    zero_y = ratio * 6.0F; 
    width = ratio * 105;
    height = ratio * 68;

    // Stadium & pitch

    stadium = { 25, 25, width + ratio * 10.0F, height + ratio * 7.0F };
    pitch_limits = { zero_x, zero_y, width, height };

    // Left objects

    goal_left = { zero_x - ratio * 2.44F, zero_y + ratio * 30.34F, ratio * 2.44F, ratio * 7.32F };
    goal_area_left = { zero_x, zero_y + ratio * 25.34F, ratio * 5.5F, ratio * 17.32F };
    penalty_area_left = { zero_x, zero_y + ratio * 13.84F, ratio * 16.5F, ratio * 40.32F };
    penalty_spot_left = { zero_x + ratio * 11.0F, zero_y + ratio * 34.0F };
    corner_arc_up_left = { zero_x, zero_y };
    corner_arc_down_left = { zero_x, zero_y + height };

    // Right objects

    goal_right = { zero_x + width, zero_y + ratio * 30.34F, ratio * 2.44F, ratio * 7.32F };
    goal_area_right = { zero_x + width - ratio * 5.5F, zero_y + ratio * 25.34F, ratio * 5.5F, ratio * 17.32F };
    penalty_area_right = { zero_x + width - ratio * 16.5F, zero_y + ratio * 13.84F, ratio * 16.5F, ratio * 40.32F };
    penalty_spot_right = { zero_x + width - ratio * 11.0F, zero_y + ratio * 34.0F };
    corner_arc_up_right = { zero_x + width, zero_y };
    corner_arc_down_right = { zero_x + width, zero_y + height };

    // Center objects

    halfway_line_startPos = { zero_x + width / 2 - 0.5F, zero_y};
    halfway_line_endPos = { zero_x + width / 2 - 0.5F, zero_y + height };
    centre_spot = { zero_x + width / 2 -0.5F, zero_y + ratio * 34.0F };
}

// Methods

void FootballPitch::Draw()
{
    // Stadium & pitch

    DrawRectangleRec(stadium, PITCH);
    DrawRectangleLinesEx(pitch_limits, 1, RAYWHITE);

    // Left objects

    DrawRectangleLinesEx(goal_left, 1, RAYWHITE);
    DrawRectangleLinesEx(goal_area_left, 1, RAYWHITE);
    DrawRectangleLinesEx(penalty_area_left, 1, RAYWHITE);
    DrawCircleV(penalty_spot_left, 2.0F, RAYWHITE);
    DrawRingLines(penalty_spot_left, ratio * 9.15F, ratio * 9.15F, 36.95F, 143.05F, 0, RAYWHITE);
    DrawRingLines(corner_arc_up_left, ratio * 1.0F, ratio * 1.0F, 0.0F, 90.0F, 0, RAYWHITE);
    DrawRingLines(corner_arc_down_left, ratio * 1.0F, ratio * 1.0F, 90.0F, 180.0F, 0, RAYWHITE);

    // Right objects

    DrawRectangleLinesEx(goal_right, 1, RAYWHITE);
    DrawRectangleLinesEx(goal_area_right, 1, RAYWHITE);
    DrawRectangleLinesEx(penalty_area_right, 1, RAYWHITE);
    DrawCircleV(penalty_spot_right, 2.0F, RAYWHITE);
    DrawRingLines(penalty_spot_right, ratio * 9.15F, ratio * 9.15F, 216.95F, 323.05F, 0, RAYWHITE);    
    DrawRingLines(corner_arc_up_right, ratio * 1.0F, ratio * 1.0F, 270.0F, 360.0F, 0, RAYWHITE);
    DrawRingLines(corner_arc_down_right, ratio * 1.0F, ratio * 1.0F, 180.0F, 270.0F, 0, RAYWHITE);

    // Center objects

    DrawLineEx(halfway_line_startPos, halfway_line_endPos, 1.0F, RAYWHITE);
    DrawCircleV(centre_spot, 2.0F, RAYWHITE);
    DrawCircleLines(zero_x + width / 2 -0.5F, zero_y + ratio * 34.0F, ratio * 9.15F, RAYWHITE);
}

Vector2 FootballPitch::GetCentreSpot()
{
    return centre_spot;
}

Rectangle FootballPitch::GetPitchLimits()
{
    return pitch_limits;
}

// Deconstructor

FootballPitch::~FootballPitch()
{

}
