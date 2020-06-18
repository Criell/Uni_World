// convert a document tree into VM code
#include "csdocument.h"
#include "tokeniser.h"

// to make out programs a bit neater
using namespace std ;

// the function vmtranslator() will be called by the main program
// its is passed the document tree constructed by vmparser()
// it walks the document tree and produces the equivalent VM code as output
void vmtranslator(cs_node root)
{
    // to start with just pretty print the document tree
    // this will need to be replaced by a tree walker that generates the code

    cs_pretty_print(root) ;
}
