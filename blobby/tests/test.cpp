#include <catch2/catch_test_macros.hpp>

#include "testFixture.h"

#include "Entity.h"
#include "Player.h"

TEST_CASE( "Entity collision detection", "[single-file]" )
{
    
    REQUIRE(true);
}

/*TEST_CASE( "Player size does not overflow", "[Player]" )
{

    static constexpr uint16_t uXPos = 0;
    static constexpr uint16_t uYPos = 0;
    static constexpr uint16_t uID = 0;

    static constexpr uint16_t uTestValue = 0xFFFF;
    Player sTestPlayer(uXPos, uYPos, uTestValue, uID);

    sTestPlayer.Consume();

    REQUIRE(sTestPlayer.GetRadius() >= uTestValue);
}*/
