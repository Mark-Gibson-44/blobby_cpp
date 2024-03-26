#include "Entity.h"
#include "utils.h"


Entity::Entity() noexcept : m_uXCoord(0), m_uYCoord(0), m_uRadius(1) {}

Entity::Entity(uint16_t uXCoord, uint16_t uYCoord, uint16_t uRadius) noexcept : m_uXCoord(uXCoord), m_uYCoord(uYCoord), m_uRadius(uRadius) {};

bool Entity::IsColliding(const Entity& sOtherEntity) noexcept
{
    if(sOtherEntity.GetRadius() < m_uRadius)
    {
        return false;
    }
    auto [uOtherX, uOtherY] = sOtherEntity.GetCoordinates();
    

    return IsWithinRange(m_uXCoord, uOtherX, m_uRadius);
}

TCoordinates Entity::GetCoordinates() const noexcept
{
    return {m_uXCoord, m_uYCoord};
}