#include "Player.h"

#include <cstdlib>
#include <iostream>

Player::Player(uint16_t uXCoord, uint16_t uYCoord, uint16_t uSize, uint16_t uID) noexcept : Entity(uXCoord, uYCoord, uSize, uID), m_uMovementSpeed(1), m_eCurrentDirection(DIRECTION::NORTH) {}

void Player::Act(uint16_t uMaxWidth, uint16_t uMaxHeight) 
{
    this->_Move(uMaxWidth, uMaxHeight);
    this->_ChangeDirection();
    std::cout << "Node " << m_uID << '\n';
    std::cout << "Current Position X: " << m_uXCoord << " Y: " << m_uYCoord << '\n';
    std::cout << "Size " << m_uRadius << '\n';
}

void Player::Consume()
{
    if(decltype(m_uRadius)(m_uRadius + 1) > m_uRadius)
    {
        m_uRadius++;
    }
}

void Player::_Move(uint16_t uMaxWidth, uint16_t uMaxHeight)
{
    switch(m_eCurrentDirection)
    {
        case DIRECTION::NORTH:
            m_uYCoord = (m_uYCoord + m_uMovementSpeed) % uMaxHeight;
            break;
        case DIRECTION::SOUTH:
            m_uYCoord = (m_uYCoord - m_uMovementSpeed) % uMaxHeight;
            break;
        case DIRECTION::EAST:
            m_uXCoord = (m_uXCoord + m_uMovementSpeed) % uMaxWidth;
            break;
        case DIRECTION::WEST:
            m_uXCoord = (m_uXCoord - m_uMovementSpeed) % uMaxWidth;
            break;
    }
}

void Player::_ChangeDirection()
{
    m_eCurrentDirection = (DIRECTION)(std::rand() % (decltype(std::rand()))DIRECTION::MAX_DIRECTIONS);
}