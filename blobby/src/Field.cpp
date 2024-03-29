#include "Field.h"
#include "Player.h"

Field::Field(uint32_t uHeight, uint32_t uWidth, uint8_t uNumPlayers) noexcept: m_uHeight(uHeight), m_uWidth(uWidth)
{
    for(uint8_t uPlayer = 0; uPlayer < uNumPlayers; uPlayer++)
    {
        uint16_t uStartX = std::rand() % m_uWidth;
        uint16_t uStartY = std::rand() % m_uHeight;
        std::cout << "Played created at" << uStartX << ", " << uStartY << '\n';
        m_arrGameEntities.emplace_back(std::make_shared<Player>(uStartX, uStartY, 1, uPlayer));
    }
    std::vector<Entity*> sQuadTreeInput;
    /*for(const auto& pPlayer : m_arrGameEntities)
    {
        sQuadTreeInput.emplace_back(pPlayer.get());
    }
    this->m_sField = buildQuadTree(sQuadTreeInput);*/
}

void Field::Run()
{
    
    while(true)
    {
        for(uint16_t uEntityNum = 0; uEntityNum < m_arrGameEntities.size(); uEntityNum++)
        {
            auto& sEntity = m_arrGameEntities[uEntityNum];
            sEntity->Act();

            auto numErased = std::erase_if(m_arrGameEntities, [=](std::shared_ptr<Entity> sOtherEntities){ return sEntity->IsColliding(*sOtherEntities.get()) && sEntity.get() != sOtherEntities.get(); });
            std::cout << "Number of collsions = "  << numErased << '\n';
            if(m_arrGameEntities.size() == 1)
            {
                std::cout << "FINISH\n";
                return;
            }
        }
    }
}