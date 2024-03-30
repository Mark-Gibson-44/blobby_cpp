#include "Entity.h"


// TODO Try to move to non-cardinal movement
enum class DIRECTION : uint8_t
{
    NORTH = 0,
    SOUTH = 1,
    EAST = 2,
    WEST = 3,
    MAX_DIRECTIONS = 4,

};

class Player final : public Entity
{
public:
    Player(uint16_t uXCoord, uint16_t uYCoord, uint16_t uSize, uint16_t uID) noexcept;
    void Act(uint16_t uMaxWidth, uint16_t uMaxHeight) override;
    void Consume() override;
private:

    void _ChangeDirection();
    void _Move(uint16_t uMaxWidth, uint16_t uMaxHeight);

    // IF AI is being used put it here
    uint16_t m_uMovementSpeed;
    DIRECTION m_eCurrentDirection;
};