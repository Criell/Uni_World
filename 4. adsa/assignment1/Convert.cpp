void printV (std::string tempString, std::vector<int> v){
	std::cout << tempString  << ": ";
	for (int i = 0; (unsigned)i < v.size(); i++)
		std::cout << v[i];	
	std::cout << std::endl; 
}

void printBV (std::string tempString, std::vector<int> v){
	std::cout << tempString  << " (Back): ";
	for (int i = v.size()-1; i > -1 ; i--)
		std::cout << v[i];	
	std::cout << std::endl; 
}

void printS (std::string tempString, std::string s){
	std::cout << tempString << ": "<< s << std::endl; 
}

long long VectoLong(std::vector<int> tempVector){
	std::string tempString;
	for (int i = 0; (unsigned)i < tempVector.size() ; i++)
		tempString = tempString + std::to_string(tempVector[i]);
	long long tempLong = 0;
	std::stringstream ss;
    ss << tempString;
    ss >> tempLong;
    return tempLong;
}

std::vector<int> Subtr(std::vector<int> half_P1, std::vector<int> SumP02){
	std::vector<int> a, b;
	//printV("HALF PI: ",half_P1);
	//printV("Sum P0 + P2: ",SumP02);
	Reverse (half_P1,SumP02, a, b);
	//printV("A: ", b);
	//printV("B: ", a);	

	long long la = VectoLong (a);
	long long lb = VectoLong (b);
	//std::cout << la << " - " << lb << std::endl;

	std::string tempString = std::to_string(la - lb);

	//std::cout << tempString << std::endl;

	std::vector<int> tempVec;
	for (int i = tempString.size()-1; i > -1; i--){
		tempVec.push_back(tempString[i]-'0');
	}

	//printV("Rest: ", tempVec);

	return tempVec;
}

std::vector<int> StringtoVec0(std::string tempString){
	int temp = 0;
	std::vector<int> tempVec;
    std::stringstream ss;
    ss << tempString;
    ss >> temp;
    tempVec.push_back(temp);
    return tempVec;
}

std::vector<int> StringtoVec(std::string tempString){
	std::vector<int> tempVec;
	for (int i = 0; (unsigned)i < tempString.size(); i++)
		tempVec.push_back(tempString[i]-'0');
	return tempVec;
}

std::string VectoString (std::vector<int> tempVector){
	std::string tempString;
	
	return tempString;
}

long long VectoLong(std::vector<int> tempVector){
	std::string tempString;
	for (int i = 0; (unsigned)i < tempVector.size() ; i++)
		tempString = tempString + std::to_string(tempVector[i]);
	long long tempLong = 0;
	std::stringstream ss;
    ss << tempString;
    ss >> tempLong;
    return tempLong;
}

long StringtoLong(std::string tempString){
	long tempLong = 0;
    std::stringstream ss;
    ss << tempString;
    ss >> tempLong;
    return tempLong;
}

void main (){
	int choice;
    while (1)
    {
        std::cout<<"\n---------------------"<<std::endl;
        std::cout<<"AVL Tree Implementation"<<std::endl;
        std::cout<<"\n---------------------"<<std::endl;
        std::cout<<"1.Insert Element into the tree"<<std::endl;
        std::cout<<"2.Display Balanced AVL Tree"<<std::endl;
        std::cout<<"3.InOrder traversal"<<std::endl;
        std::cout<<"4.PreOrder traversal"<<std::endl;
        std::cout<<"5.PostOrder traversal"<<std::endl;
        std::cout<<"6.Exit"<<std::endl;
        std::cout<<"Enter your Choice: ";
        std::cin>>choice;

        switch(choice)
        {
        case 1:
            std::cout<<"Enter value to be inserted: ";
            break;
        case 2:
            //if (avl.root == NULL){
                //std::cout<<"Tree is Empty"<<std::endl;
                //continue;
            //}
            std::cout<<"Balanced AVL Tree:"<<std::endl;
            break;
        case 3:
            std::cout<<"Inorder Traversal:"<<std::endl;
            std::cout<<std::endl;
            break;
        case 4:
            std::cout<<"Preorder Traversal:"<<std::endl;
            std::cout<<std::endl;
            break;
        case 5:
            std::cout<<"Postorder Traversal:"<<std::endl;   
            std::cout<<std::endl;
            break;
        case 6:
            exit(1);    
            break;
        default:
            std::cout<<"Wrong Choice"<<std::endl;
        }
     
    }
}