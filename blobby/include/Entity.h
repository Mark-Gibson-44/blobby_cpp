#pragma once
// uint_t
#include <cstdint>
// std::pair
#include <utility>

using TCoordinates = std::pair<uint16_t, uint16_t>;

class Entity
{

public:
    // Function each Inherited Entity object must implement to move
    virtual void Act() = 0;

public:

    Entity() noexcept;
    Entity(uint16_t uXCoord, uint16_t uYCoord, uint16_t uRadius) noexcept; 

    // Is another object colliding with the current object
    bool IsColliding(const Entity& sOtherEntity) noexcept;

    TCoordinates GetCoordinates() const noexcept;
    inline uint8_t GetRadius() const { return m_uRadius; }
protected:

    uint16_t m_uXCoord;
    uint16_t m_uYCoord;
    uint16_t m_uRadius;
};