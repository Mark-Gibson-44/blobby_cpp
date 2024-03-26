#include "Player.h"

#include <cstdlib>
#include <iostream>

Player::Player(uint16_t uXCoord, uint16_t uYCoord, uint16_t uSize) noexcept : Entity(uXCoord, uYCoord, uSize), m_uMovementSpeed(1), m_eCurrentDirection(DIRECTION::NORTH) {}

void Player::Act() 
{
    this->_Move();
    this->_ChangeDirection();

}

void Player::_Move()
{
    switch(m_eCurrentDirection)
    {
        case DIRECTION::NORTH:
            m_uYCoord += m_uMovementSpeed;
            break;
        case DIRECTION::SOUTH:
            m_uYCoord -= m_uMovementSpeed;
            break;
        case DIRECTION::EAST:
            m_uXCoord += m_uMovementSpeed;
            break;
        case DIRECTION::WEST:
            m_uYCoord -= m_uMovementSpeed;
            break;
    }
}

void Player::_ChangeDirection()
{
    m_eCurrentDirection = (DIRECTION)(std::rand() % (decltype(std::rand()))DIRECTION::MAX_DIRECTIONS);
}