#include "Blockchain.h"
#include <ctime>

int main()
{

    Blockchain masterChain = Blockchain();
   
    masterChain.AddBlock(Block(1, "Block 1 Data"));
    cout << "Genetis Block is Created"<< endl << endl;

    clock_t start, finish;

    for(uint32_t  i = 2; i < 20; i++){

        start = clock();
        cout << "Start Mining Block... " << i << endl;
        cout << "Difficulty: "<< i*8 << "bits"<< endl;
        masterChain.setDifficulty(i);
        masterChain.AddBlock(Block(i, "Block Data"));
        cout << "Previous Block Hash: "<< masterChain._GetLastBlock().sPrevHash << endl;
        cout << "Current Block Hash: "<< masterChain._GetLastBlock().sHash << endl;
        cout << "Success with nonce："<< masterChain._GetLastBlock().getNonce() << endl;
        finish = clock();
        cout << "Time Spent: "<< (double) (finish - start) / CLOCKS_PER_SEC<< "s"<< endl << endl;

    }

    return 0;
}

