#ifndef TESTCHAIN_BLOCKCHAIN_H
#define TESTCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {

    public:
        Blockchain();

        void AddBlock(Block bNew);
        void setDifficulty(uint32_t difficulty);
         
        Block _GetLastBlock() const;

    private:
        uint32_t _nDifficulty;
        vector<Block> _vChain;

};

#endif //TESTCHAIN_BLOCKCHAIN_H

