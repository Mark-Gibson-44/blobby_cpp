#include "Field.h"
#include "Player.h"

Field::Field(uint32_t uHeight, uint32_t uWidth, uint8_t uNumPlayers) noexcept: m_uHeight(uHeight), m_uWidth(uWidth)
{
    for(uint8_t uPlayer = 0; uPlayer < uNumPlayers; uPlayer++)
    {
        m_arrGameEntities.emplace_back(std::make_unique<Player>(1, 1, 1, uPlayer));
    }
    std::vector<Entity*> sQuadTreeInput;
    for(const auto& pPlayer : m_arrGameEntities)
    {
        sQuadTreeInput.emplace_back(pPlayer.get());
    }
    this->m_sField = buildQuadTree(sQuadTreeInput);
}

void Field::Run()
{
    
    while(true)
    {
        for(auto& entity : m_arrGameEntities)
        {
            entity->Act();
        }
    }
}