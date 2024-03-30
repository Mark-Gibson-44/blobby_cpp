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
    virtual void Act(uint16_t uMaxWidth, uint16_t uMaxHeight) = 0;
    virtual void Consume() = 0;
    //virtual void LogEntity() = 0;

public:

    Entity() noexcept;
    Entity(uint16_t uXCoord, uint16_t uYCoord, uint16_t uRadius, uint16_t m_uID) noexcept; 
    Entity(const Entity&) = delete;
    Entity& operator=(const Entity&) = delete;
    ~Entity() = default;
    // Is another object colliding with the current object
    bool IsColliding(const Entity& sOtherEntity);
    bool HandleCollision(Entity& sOtherEntity);  
    TCoordinates GetCoordinates() const noexcept;
    uint16_t GetRadius() const { return m_uRadius; }
    uint16_t GetID() const { return m_uID; }


protected:

    uint16_t m_uXCoord;
    uint16_t m_uYCoord;
    uint16_t m_uRadius;
    uint16_t m_uID;
};