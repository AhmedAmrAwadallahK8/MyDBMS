#include <iostream>
#include <vector>
#include <string>

#include "DataBaseObjects\entry.h"
#include "DataBaseObjects\record.h"
#include "BPlusTree\node.h"
#include "BPlusTree\node_block.h"

// Template Issue: Reflections?

/* Entry is now a linked list of void pointers, retrive type information of data from the records attribute table */
/*TODO
    Revamp Entry for void pointers
    Revemp record for new entry implementation
    Strings currently unsupported?
 */





int main(){
    
    //Entry::test();
    //Record::test();
    //Node::test();
    Node_Block::test();






    std::cout << "Program Execution Complete";
}