//#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_all.hpp>

#include "testFixture.h"

#include "Entity.h"
#include "Player.h"

TEST_CASE( "Entity collision detection", "[single-file]" )
{
    bool isCollisionExpected = GENERATE(true, false);

    uint16_t uP1Size = 0;
    constexpr uint16_t uP2Size = 1;
    constexpr uint16_t uP1XCoord = 1;
    constexpr uint16_t uP2XCoord = 3;
    constexpr uint16_t uP1YCoord = 1;
    constexpr uint16_t uP2YCoord = 1;

    if(isCollisionExpected)
    {
        uP1Size = 5;
    }
    else
    {
        uP1Size = 1;
    }
    Player sTestEntity1(uP1XCoord, uP1YCoord, uP1Size, 0);
    Player sTestEntity2(uP2XCoord, uP2YCoord, uP2Size, 0);

    REQUIRE(sTestEntity2.IsColliding(sTestEntity2) == false);
    REQUIRE(sTestEntity1.IsColliding(sTestEntity1) == false);

    //REQUIRE(sTestEntity2.IsColliding(sTestEntity1) == isCollisionExpected);
}

TEST_CASE( "Player size does not overflow", "[Player]" )
{
 
    static constexpr uint16_t uXPos = 0;
    static constexpr uint16_t uYPos = 0;
    static constexpr uint16_t uID = 0;

    static constexpr uint16_t uTestValue = 0xFFFF;
    Player sTestPlayer(uXPos, uYPos, uTestValue, uID);

    sTestPlayer.Consume();

    REQUIRE(sTestPlayer.GetRadius() >= uTestValue);
}
