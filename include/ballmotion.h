#ifndef BALLMOTION_H
#define BALLMOTION_H

#include "raylib.h"

class BallMotion
{
    public:
        BallMotion(void);
        ~BallMotion(void);
        void SetPosition(const Vector2& position);
        Vector2 GetPosition() const;
        void SetFuturePosition(const Vector2& position);
        Vector2 GetFuturePosition() const;
        float GetAngle();
        float GetSpeedX();
        float GetSpeedY();
        float Distance();
        void Draw();
    private:
        void Calculate();
        void Move();
        Vector2 ballPosition;
        Vector2 futurePosition;
        float angle;
        float speed;
        float ballRadius;
        float speed_x;
        float speed_y;
};

#endif