#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdlib>

#include <vector>

#include "Entity.h"

static TCoordinates MidPoint(TCoordinates pPoint1, TCoordinates pPoint2)
{
    // TODO. Add Tests for this function, might be wrong
    return { (std::abs(pPoint1.first - pPoint2.first) >> 2), (std::abs(pPoint1.second - pPoint2.second))};
}

struct Box
{
    TCoordinates tTopCorner {INT16_MAX, INT16_MAX};
    TCoordinates tBottomCorner{0, 0};

    Box & Extend(TCoordinates tPoint)
    {
        this->tBottomCorner.first = std::min(this->tBottomCorner.first, tPoint.first);
        this->tBottomCorner.second = std::min(this->tBottomCorner.second, tPoint.second);
        this->tTopCorner.first = std::min(this->tTopCorner.first, tPoint.first);
        this->tTopCorner.second = std::min(this->tTopCorner.second, tPoint.second);
        
        return *this;
    }

};

template <typename Iterator>
Box CreateBoundingBox(Iterator begin,Iterator end)
{
    Box result;
    while(begin != end)
    {
        result = result.Extend(*begin);
        begin++;
    }

    return result;
}

struct TreeNode
{
    std::array<std::array<uint16_t, 2>, 2> arrChildNodes = {{0, 0, 0, 0}};
};

struct QuadTree
{

    Box sBoundingBox;
    uint16_t uRootID = 0;
    std::vector<TreeNode> sNodes;
    //std::vector<Entity>??
};

template <typename Iterator>
uint16_t build_impl(QuadTree& sTree, Box bbox, Iterator begin, Iterator end, uint8_t uDepthLimit)
{
    if(begin == end)
    {
        return 0;
    }

    uint16_t result = sTree.sNodes.size();
    if(uDepthLimit == 0)
    {
        return result;
    }
    sTree.sNodes.emplace_back();

    if(begin + 1 == end)
    {
        return result;
    }

    TCoordinates sCenter = MidPoint(bbox.tBottomCorner, bbox.tTopCorner);
    // Split y part
    Iterator yPartition = std::partition(begin, end, [sCenter](TCoordinates p) { return p.second < sCenter.second;} );
    // Split X part
    Iterator xPartitionLower = std::partition(begin, yPartition, [sCenter](TCoordinates p) { return p.first < sCenter.first;} );
    Iterator xPartitionUpper = std::partition(yPartition, end, [sCenter](TCoordinates p) { return p.first < sCenter.first;});

    sTree.sNodes[result].arrChildNodes[0][0] = build_impl(sTree, {bbox.tBottomCorner, sCenter}, begin, xPartitionLower, uDepthLimit-1);
    sTree.sNodes[result].arrChildNodes[0][1] = build_impl(sTree, { {sCenter.first, bbox.tBottomCorner.second}, {bbox.tTopCorner.first, sCenter.second }}, xPartitionLower, yPartition, uDepthLimit-1);
    sTree.sNodes[result].arrChildNodes[1][0] = build_impl(sTree, { {bbox.tBottomCorner.first, sCenter.second}, {sCenter.first, bbox.tBottomCorner.second}}, yPartition, xPartitionUpper, uDepthLimit-1);
    sTree.sNodes[result].arrChildNodes[1][1] = build_impl(sTree, {sCenter, bbox.tTopCorner}, xPartitionUpper, end, uDepthLimit-1);


    return result;
}

template <typename Iterator>
QuadTree build(Iterator begin, Iterator end)
{
    QuadTree ret;
    ret.uRootID = build_impl(ret, CreateBoundingBox(begin, end), begin, end, 64);
    return ret;
}
