#include <iostream>
#include <string>
#include <glut.h>

#include "include/util.h"
#include "include/game.h"

Game::Game() : WINDOW_WIDTH(640), WINDOW_HEIGHT(480), FPS(60),
               camera(0.0f, 3.0f, -5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f),
               player(0.0f, 0.75f, 9.8f, 0.0f, 0.0f, 0.0f), arrow(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f),
               target(0.0f, 1.4f, 10.0f, 0.0f, 180.0f, 0.0f),
               quiver(2.0f, 0.3f, 7.0f, 0.0f, 0.0f, 0.0f),
               dummy(2.0f, 0.9f, 1.3f, 0.0f, 0.0f, 0.0f),
               table(-4.0f, -0.1f, 1.3f, 0.0f, 90.0f, 0.0f),
               bow(-3.5f, 0.5f, 1.3f, 0.0f, 90.0f, 0.0f),
               arrowSecondary(-3.5f, 0.5f, 1.3f, 0.0f, 90.0f, 45.0f),
               boundariesColors{0.9f, 0.9f, 0.9f, 0.4f, 0.4f, 0.4f},
               keyHandler(*this) {}

void Game::update()
{
    if (gameOver)
        return;

    time -= 1.0 / FPS;

    if (time <= 0)
    {
        gameOver = true;
        return;
    }

    if (arrowAnimation)
        arrowSecondary.angle.z += 1.0f;

    if (bowAnimation)
        bow.angle.y += 1.0f;

    if (quiverAnimation)
    {
        quiver.scale += quiverScaleDx;
        if (quiver.scale >= 1.2f || quiver.scale <= 0.8f)
        {
            quiverScaleDx = -quiverScaleDx;
        }
    }

    if (dummyAnimation)
    {
        dummy.position.x += dummyPositionDx;
        if (dummy.position.x >= 2.5f || dummy.position.x <= 1.5f)
        {
            dummyPositionDx = -dummyPositionDx;
        }
    }

    if (tableAnimation)
    {
        table.color[0] += tableColorDx;
        if (table.color[0] >= 0.9f || table.color[0] <= 0.4f)
        {
            tableColorDx = -tableColorDx;
        }
    }

    target.color[0] += targetColorDx;
    target.color[1] += targetColorDx;
    target.color[2] += targetColorDx;
    if (target.color[0] >= 3.0f || target.color[0] <= 0.5f)
    {
        targetColorDx = -targetColorDx;
    }

    if (arrowShot)
    {
        util::moveForward(arrow.position, arrow.angle, 0.1f);
        if (arrow.position.z >= 10.3)
        {
            if (arrow.position.y >= 1.1 && arrow.position.y <= 1.7 && arrow.position.x <= 0.3 && arrow.position.x >= -0.3)
            {
                arrowShot = false;
                score += 50;
            }
            else if (arrow.position.y >= 0.7 && arrow.position.y <= 2.1 && arrow.position.x >= -0.7 && arrow.position.x <= 0.7)
            {
                arrowShot = false;
                score += 30;
            }
            else if (arrow.position.y >= 0.4 && arrow.position.y <= 3 && arrow.position.x >= -1.2 && arrow.position.x <= 1.2)
            {
                arrowShot = false;
                score += 10;
            }
        }
    }

    boundariesColors[0][0] += boundariesColorsDx;
    boundariesColors[0][1] += boundariesColorsDx;
    boundariesColors[0][2] += boundariesColorsDx;

    boundariesColors[1][0] += boundariesColorsDx;
    boundariesColors[1][1] += boundariesColorsDx;
    boundariesColors[1][2] += boundariesColorsDx;

    if (boundariesColors[0][0] >= 0.9f || boundariesColors[0][0] <= 0.6f)
    {
        boundariesColorsDx = -boundariesColorsDx;
    }
}

void drawBoundaries(const float boundariesColors[2][3])
{
    double wallThickness = 0.05;

    glPushMatrix();
    glTranslated(-50.0, -2.1, -50.0);
    glScaled(100.0, 40.0, 100.0);

    glPushMatrix();
    util::drawWall(wallThickness, boundariesColors);
    glPopMatrix();

    glPushMatrix();
    glRotated(90, 0, 0, 1.0);
    util::drawWall(wallThickness, boundariesColors);
    glPopMatrix();

    glPushMatrix();
    glRotated(-90, 1.0, 0.0, 0.0);
    util::drawWall(wallThickness, boundariesColors);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0, 0.0, 1);
    glRotated(-90, 1.0, 0, 0);
    util::drawWall(wallThickness, boundariesColors);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.0, 0.0, 0.0);
    glRotated(90, 0, 0, 1.0);
    util::drawWall(wallThickness, boundariesColors);
    glPopMatrix();

    glPopMatrix();
}

void Game::render() const
{
    if (gameOver)
    {
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();

        if (score >= 100)
        {
            glColor3f(0.0f, 1.0f, 0.0f);
            util::drawText(WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2, 0.0f, "You Win!");
        }
        else
        {
            glColor3f(1.0f, 0.0f, 0.0f);
            util::drawText(WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2, 0.0f, "Game Over");
        }

        glColor3f(1.0f, 0.0f, 1.0f);
        util::drawText(10.0f, WINDOW_HEIGHT - 20.0f, 0.0f, "Score: " + std::to_string(score));
        util::drawText(10.0f, WINDOW_HEIGHT - 40.0f, 0.0f, "Time: " + std::to_string((int)time));

        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        return;
    }

    player.render();
    if (arrowShot)
        arrow.render();
    target.render();

    quiver.render();
    dummy.render();
    table.render();
    bow.render();
    arrowSecondary.render();

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glColor3f(1.0f, 0.0f, 1.0f);
    util::drawText(10.0f, WINDOW_HEIGHT - 20.0f, 0.0f, "Score: " + std::to_string(score));
    util::drawText(10.0f, WINDOW_HEIGHT - 40.0f, 0.0f, "Time: " + std::to_string((int)time));

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    drawBoundaries(boundariesColors);
}

void Game::shoot()
{
    arrowShot = true;
    arrow.position.x = player.position.x;
    arrow.position.y = player.position.y;
    arrow.position.z = player.position.z;
    arrow.angle.x = player.rightArmRotation.x + 30.0f;
    arrow.angle.y = player.angle.y;
    arrow.angle.z = player.angle.z;
}

void Game::setFrontView()
{
    camera.eye.x = 0.0f;
    camera.eye.y = 0.5f;
    camera.eye.z = -5.0f;
    camera.center.x = 0.0f;
    camera.center.y = 0.5f;
    camera.center.z = 0.0f;
    camera.up.x = 0.0f;
    camera.up.y = 1.0f;
    camera.up.z = 0.0f;
}

void Game::setSideView()
{
    camera.eye.x = -15.0f;
    camera.eye.y = 0.5f;
    camera.eye.z = 5.0f;
    camera.center.x = 0.0f;
    camera.center.y = 0.5f;
    camera.center.z = 5.0f;
    camera.up.x = 0.0f;
    camera.up.y = 1.0f;
    camera.up.z = 0.0f;
}

void Game::setTopView()
{
    camera.eye.x = 0.0f;
    camera.eye.y = 15.0f;
    camera.eye.z = 5.0f;
    camera.center.x = 0.0f;
    camera.center.y = 5.0f;
    camera.center.z = 5.0f;
    camera.up.x = 0.0f;
    camera.up.y = 0.0f;
    camera.up.z = 1.0f;
}