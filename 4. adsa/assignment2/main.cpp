#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

std::vector<std::string> ProcessInput(std::string temp) {
    std::istringstream iss(temp);
    std::vector<std::string> input((std::istream_iterator<std::string>(iss)),
                                 std::istream_iterator<std::string>());
    return input;
}

#ifndef BTT_H
#define BTT_H

class BTT
{
    struct Node {
        int number;
        Node *smaller;
        Node *bigger;
        int height;
    };

    public:
        BTT(){
            root = NULL;
        }
        ~BTT(){}
        Node *root;
        
        void Add(int n) {
            root = Insert(root, n);
        }

        void Remove(int n) {
            root = Delete(root, n);
        }

        void printIN(){
            if (root == NULL)
                std::cout << "EMPTY";
            else
                PrintInNode(root);
            std::cout << std::endl;
        }

        void printPRE(){
            if (root == NULL)
                std::cout << "EMPTY";
            else
                PrintPreNode(root);
            std::cout << std::endl;
        }

        void printPOST(){
            if (root == NULL)
                std::cout << "EMPTY";
            else
                PrintPostNode(root);
            std::cout << std::endl;
        }

    protected:

        void PrintInNode(Node* node){
            if(node == NULL)
                return;
            PrintInNode(node->smaller);
            std::cout << node->number << " ";
            PrintInNode(node->bigger);
        }

        void PrintPreNode(Node* node){
            if(node == NULL)
                return;
            std::cout << node->number << " ";
            PrintPreNode(node->smaller);
            PrintPreNode(node->bigger);
        }

        void PrintPostNode(Node* node){
            if(node == NULL)
                return;
            PrintPostNode(node->smaller);
            PrintPostNode(node->bigger);
            std::cout << node->number << " ";
        }

        void printRoot(){
            if(root == NULL){
                std::cout << " ROOT: NULL " << std::endl;;
            } else {
                std::cout << " ROOT PRE: ";
                printPRE();
            }
        }

        void print(Node* node){
            if(node == NULL)
                return;
            std::cout << "Node Head: "<< node->number;
            if (node->smaller != NULL)
                std::cout << " Smaller: "<< node->smaller->number;
            if (node->bigger != NULL)
                std::cout << " Bigger: " << node->bigger->number;
            std::cout << std::endl;
            
            printRoot();
        }

        Node* NodeNull (int n){
            Node * temp = new Node;
            temp -> number = n;
            temp -> smaller = NULL;
            temp -> bigger = NULL;
            temp -> height = 1;
            return temp;
        }

        int h (Node* node){
            if(node == NULL)
                return 0;

            std::cout << " Height: " << node->height << std::endl;
            return node->height;
        }
        
        int maxHeight(Node* node){
            int tempS = h(node->smaller);
            int tempB = h(node->bigger);
            int ht = std::max(tempS, tempB) + 1;
            //std::cout << " Height: " << ht << std::endl;
            return ht;
        }

        int findBalance (Node* node){ 
            int tempS = h(node->smaller);
            int tempB = h(node->bigger);
            int bal = tempS - tempB;
            std::cout << " Bal: " << bal << std::endl;
            return bal;
        }

        Node* SmallerN (Node* node){
            if(node == NULL)
                return NULL;
            else if(node->smaller == NULL)
                return node;
            else
                return SmallerN(node->smaller);
        }

        Node* BiggerN (Node* node){
            if(node == NULL)
                return NULL;
            else if(node->bigger == NULL)
                return node;
            else
                return BiggerN(node->bigger);
        }

        Node *leftRotation(Node *node) {
            std::cout << "Before Right Node: "; 
            print(node);

            Node *old = node;
            Node *temp = node->bigger;

            old->bigger = temp->smaller;
            temp->smaller = old;

            old->height = maxHeight(old);
            temp->height = maxHeight(temp);

            std::cout << "After - Temp: "; 
            print(temp);        
            return temp;
        }

        Node *rightRotation(Node *node) {
            std::cout << "Before Left Node: "; 
            print(node);

            Node *old = node;
            Node *temp = node->smaller;

            old->smaller = temp->bigger;
            temp->bigger = old;
            
            old->height = maxHeight(old);
            temp->height = maxHeight(temp);

            std::cout << "After - Temp: ";   
            print(temp);       
            return temp;
        }

        Node* recoverBalance(Node* node){
            std::cout << "H: " << h(node->smaller) << " - " << h(node->bigger) << std::endl;
            if (findBalance(node) == -2){
                std::cout << "Recover FIND -2: ";
                std::cout << h(node->bigger->bigger) << " < " << h(node->bigger->smaller) << std::endl;
                if (h(node->bigger->smaller) > h(node->bigger->bigger)){
                    node = rightRotation(node->bigger);
                }
                else{
                    node = leftRotation(node);
                    std::cout << "LEFT " << std::endl;
                }
            } else if (findBalance(node) == 2){
                std::cout << "Recover FIND 2: "; 
                std::cout <<  h(node->smaller->bigger) << " > " << h(node->smaller->smaller) << std::endl;
                if (h(node->smaller->bigger) > h(node->smaller->smaller)){
                node = leftRotation(node->smaller);
                }
                else {
                    node = rightRotation(node);
                    std::cout << "RIGHT " << std::endl;
                }
                    
            }
            std::cout << "RESULT: ";   
            print(node);
            return node;
        }

        Node* Insert(Node* node, int n) {
            if (node == NULL){
                return NodeNull(n);
            } 

            if (n < node->number){
                node->smaller = Insert(node->smaller, n);
            
            } else if (n > node->number){
                node->bigger = Insert(node->bigger, n);
                
            } else {
                return node;
            }

            node->height = maxHeight(node);
            node = recoverBalance(node);
            return node;
        }


        Node* Delete(Node* node, int n) {
            if(node == NULL)
                return NULL;
            
            if (n < node->number){
                node->smaller = Delete(node->smaller, n);  
            } else if (n > node->number){
                node->bigger = Delete(node->bigger, n);
            } else {
                if (node->smaller == NULL && node->bigger == NULL){
                    return node = NULL;
                }

                if (node->smaller != NULL && node->bigger != NULL){
                    Node* temp = BiggerN(node->smaller);
                    node->number = temp->number;
                    node->smaller = Delete(node->smaller, node->number);
                } else {
                    if(node->smaller == NULL)
                        node = node->bigger;
                    else if(node->bigger == NULL)
                        node = node->smaller;
                } 
            }

            if(node == NULL)
                return node;

            node->height = maxHeight(node);
            node = recoverBalance(node);
            
            return node;
        }
        
};

#endif //BTT_H


int main()
{
    std::string temp;
    std::vector<std::string> input;
    BTT avl;

    //while(true){
        //std::cout << ">> ";
        std::getline(std::cin, temp);
        input = ProcessInput(temp);   
        for (int i = 0; (unsigned)i < input.size(); i++){
            if (input[i][0] == 'A'){
                std::string Svalue = input[i];
                Svalue.erase (Svalue.begin(),Svalue.begin()+1); 
                std::stringstream Tmp(Svalue); 
                int value = 0; 
                Tmp >> value; 
                //std::cout << "***** ADD " << value << std::endl;
                avl.Add(value);
            } else if (input[i][0] == 'D'){
                std::string Svalue = input[i];
                Svalue.erase (Svalue.begin(),Svalue.begin()+1); 
                std::stringstream Tmp(Svalue); 
                int value = 0; 
                Tmp >> value; 
                //std::cout << "REMOVE " << value << std::endl;
                avl.Remove(value);
            } else if (input[i] == "IN"){
                //std::cout << "IN: ";
                avl.printIN();
            } else if (input[i] == "PRE"){ 
                //std::cout << "PRE: ";
                avl.printPRE();
            } else if (input[i] == "POST"){ 
                //std::cout << "POST: ";
                avl.printPOST();
            } else if (input[i] == "Z") {
                exit(0);
            }
        //}
    }
    
    return 0;
}