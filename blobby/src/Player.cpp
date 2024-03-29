#include "Player.h"

#include <cstdlib>
#include <iostream>

Player::Player(uint16_t uXCoord, uint16_t uYCoord, uint16_t uSize, uint16_t uID) noexcept : Entity(uXCoord, uYCoord, uSize, uID), m_uMovementSpeed(1), m_eCurrentDirection(DIRECTION::NORTH) {}

void Player::Act() 
{
    this->_Move();
    this->_ChangeDirection();
    std::cout << "Node " << m_uID << '\n';
    std::cout << "Current Position X: " << m_uXCoord << " Y: " << m_uYCoord << '\n';
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