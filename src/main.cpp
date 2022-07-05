#include <iostream>
#include <vector>
#include <string>

#include "DataBaseObjects\entry.h"
#include "DataBaseObjects\record.h"
#include "BPlusTree\node.h"
#include "BPlusTree\node_block.h"
#include "BPlusTree\b_plus_tree.h"
#include "DataBaseObjects\database.h"
#include "Tests\test_b_plus_tree.h"
#include "Tests\test_table.h"
#include "Tests\test_database.h"

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
    //Node<int>::test();
    //Node_Block<int>::test();
    //Test_B_Plus_Tree::test();
    //Test_Table::test();
    Test_Database::test();








    std::cout << "Program Execution Complete6";
}