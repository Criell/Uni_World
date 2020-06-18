// convert Jack VM Code into a document tree
#include "csdocument.h"
#include "tokeniser.h"

// to make out programs a bit neater
using namespace std ;

static string token ;         // the last token read
static cs_node token_node ;   // a document node for the last token read
static void nextToken()       // call next_token and update token_node
{
    token = next_token() ;
    token_node = cs_new_node_text(token,token_value()) ;
}

// the function vmparser() will be called by the main program
// the document tree constructed must be returned as the function result
cs_node vmparser()
{
    // initialise the tokeniser then read the first token
    init_tokeniser() ;
    nextToken() ;

    // construct the root node of our document tree
    // initially we create a "tokens" node, this will need to be changed to "class"
    cs_node root = cs_new_node("class") ;

/*****************   REPLACE THE FOLLOWING CODE  ******************/

    // we stop when we see the token "?"
    // this may be end of input or an error
    // we cannot tell so treat both as end of input
    while ( token != "?" )
    {
        if (token == "stack")
        {
            cs_node astack = cs_new_node("a-stack");
            cs_append_child(root, astack) ;
            cs_append_child(astack, token_node) ;

            nextToken();
            if (token == "segment")
            {
                cs_append_child(astack, token_node) ;


                nextToken();
                if (token == "number")
                {
                    cs_append_child(astack, token_node) ;
                    nextToken();
                } else
                {
                    exit(0);
                }
            } else
            {
                exit(0);
            }
        } else if (token == "func")
        {
            cs_node afunc = cs_new_node("a-func");
            cs_append_child(root, afunc) ;
            cs_append_child(afunc, token_node) ;

            nextToken();
            if (token == "label")
            {
                cs_append_child(afunc, token_node) ;
            } else
            {
                exit(0);
            }

            nextToken();
            if (token == "number")
            {
                cs_append_child(afunc, token_node) ;
            } else
            {
                exit(0);
            }
        } else if (token == "jump")
        {
            cs_node ajump = cs_new_node("a-jump");
            cs_append_child(root, ajump) ;
            cs_append_child(ajump, token_node) ;

            nextToken();
            if (token == "label")
            {
                cs_append_child(ajump, token_node) ;
            } else
            {
                exit(0);
            }
        } else if (token == "op")
        {
            cs_node anop = cs_new_node("an-op");
            cs_append_child(root, anop) ;
            cs_append_child(anop, token_node) ;

            nextToken();
        }
        // add the next token's node as a child of the root node
        cs_append_child(root,token_node) ;
    }

/*****************        DOWN TO HERE         ******************/

    return root ;
}



        // add the next token's node as a child of the root node
        //cs_node astack = cs_new_node("a-stack") ;
        //cs_append_child(root, astack);
        
        //nextToken() ;
        //if (token== "segment")
        //    cs_append_child(astack, token_node);
        //else
        //    exit(0);
        //nextToken() ;
        //cs_append_child(astack, token_node);


        //cs_append_child(root,token_node) ;

        // read the next token
        //nextToken() ; 
