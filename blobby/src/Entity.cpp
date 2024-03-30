#include "Entity.h"
#include "utils.h"

#include <iostream>

Entity::Entity() noexcept : m_uXCoord(0), m_uYCoord(0), m_uRadius(1), m_uID(0) {}

Entity::Entity(uint16_t uXCoord, uint16_t uYCoord, uint16_t uRadius, uint16_t uID) noexcept : m_uXCoord(uXCoord), m_uYCoord(uYCoord), m_uRadius(uRadius), m_uID(uID) {};

bool Entity::IsColliding(const Entity& sOtherEntity)
{
    if(this == &sOtherEntity)
    {
        return false;
    }

    if(sOtherEntity.GetRadius() < m_uRadius)
    {
        return false;
    }
    auto [uOtherX, uOtherY] = sOtherEntity.GetCoordinates();
    
    
    return IsWithinRange(m_uXCoord, uOtherX, m_uRadius);
}


bool Entity::HandleCollision(Entity& sOtherEntity)
{
    if(this->IsColliding(sOtherEntity))
    {
        std::cout << " Player " << this->m_uID << " Colliding with Player " <<  sOtherEntity.GetID() << '\n';
        this->Consume();
        return true;
    }
    return false;
}

TCoordinates Entity::GetCoordinates() const noexcept
{
    return {m_uXCoord, m_uYCoord};
}