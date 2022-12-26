#include "ballmotion.h"
#include <math.h>

// Constructor

BallMotion::BallMotion()
{
    ballPosition = { 0.0F, 0.0F };
    futurePosition = { 0.0F, 0.0F };
    ballRadius = 2.2F;
    angle = 0.0F;
    speed = 4.0F;
}

// Methods

void BallMotion::SetPosition(const Vector2& position)
{
    ballPosition.x = position.x;
    ballPosition.y = position.y;

    futurePosition.x = position.x;
    futurePosition.y = position.y;
}

Vector2 BallMotion::GetPosition() const
{
    return ballPosition;
}

void BallMotion::SetFuturePosition(const Vector2& position)
{
    futurePosition.x = position.x;
    futurePosition.y = position.y;
}

Vector2 BallMotion::GetFuturePosition() const
{
    return futurePosition;
}

float BallMotion::GetAngle()
{
    return angle;
}

float BallMotion::GetSpeedX()
{
    return speed_x;
}

float BallMotion::GetSpeedY()
{
    return speed_y;
}

void BallMotion::Draw()
{
    Calculate();

    Move();

    DrawCircleV(ballPosition, ballRadius, MAROON);
}

void BallMotion::Calculate()
{
    angle = atan2(futurePosition.y - ballPosition.y, futurePosition.x - ballPosition.x) * 180 / PI;
    speed_x = cos(angle * PI / 180) * speed;
    speed_y = sin(angle * PI / 180) * speed;
}

void BallMotion::Move()
{
    if (Distance() > 1.0F)
    {
        ballPosition.x += speed_x;
        ballPosition.y += speed_y;
    }
    else
    {
        futurePosition.x = ballPosition.x;
        futurePosition.y = ballPosition.y;
    }
}

float BallMotion::Distance()
{
    float diffY = futurePosition.y - ballPosition.y;
    float diffX = futurePosition.x - ballPosition.x;
    
    return sqrt((diffY * diffY) + (diffX * diffX));
}

// Deconstructor

BallMotion::~BallMotion()
{

}
