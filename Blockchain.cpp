#include "Blockchain.h"

Blockchain::Blockchain()
{
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 1;
}

void Blockchain::AddBlock(Block bNew)
{
    bNew.sPrevHash = _GetLastBlock().sHash;
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const
{
    return _vChain.back();

}

void Blockchain::setDifficulty(uint32_t difficulty){

    _nDifficulty = difficulty;
}

