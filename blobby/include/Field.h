#pragma once

#include <memory>
#include <vector>

#include "Quadtree.h"



class Field
{

public:
    Field(uint32_t uHeight, uint32_t uWidth, uint8_t uNumPlayers) noexcept;


    void Run();


private:
    std::vector<std::unique_ptr<Entity>> m_arrGameEntities;

    QuadTree m_sField;
    const uint32_t m_uHeight;
    const uint32_t m_uWidth;

};