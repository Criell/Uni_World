#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void Reverse(std::vector<int> x, std::vector<int> y, std::vector<int> &a, std::vector<int> &b){
	//Copy the vectors in reverse order
	for (int i = x.size()-1; i > -1; i--){
		a.push_back(x[i]);
	}
	for (int i = y.size()-1; i > -1; i--){
		b.push_back(y[i]);
	}
}

void SameSize(std::vector<int> &a, std::vector<int> &b){
	// Return new vector with the same size with zeros on the left 
	int n = a.size();
	if (a.size() > b.size()){ 
		for (int i = n - b.size(); i > 0; i--){
			b.push_back(0);	
		}
	} else if (b.size() > a.size()){
		n = b.size();
		for (int i = n - a.size(); i > 0; i--){
			a.push_back(0);	
		}
	}
}	

void CopySame(std::vector<int> x, std::vector<int> y, std::vector<int> &a, std::vector<int> &b){
	// Copy the vectors into new ones
	for (int i = 0; (unsigned)i < x.size(); i++){
		a.push_back(x[i]);
	}
	for (int i = 0; (unsigned)i < y.size(); i++){
		b.push_back(y[i]);
	}
	SameSize(a, b);
}

int nSize(std::vector<int> a, std::vector<int> b){
	//Return the bigger n of the 2 vectores
	int n = a.size();
	if (b.size() > a.size()){
		n = b.size();
	}
	return n;
}

std::vector<int> AddNum(std::vector<int> x, std::vector<int> y, int B){
	std::vector<int> a, b, s;
	CopySame(x,y,a,b);
	int n = nSize(a,b); 
	int c = 0, temp = 0;

	// Integer Addition
	for (int i = 0; i < n; i++){
		temp = a[i]+b[i]+c;
		
		//Carry when the addition is more than the base
		if (temp > B-1){
			c = temp/B;
			temp = temp - B;
		}
		else {
			c = 0;
		}

		//Fill the s vector
		s.push_back(temp);
	}

	//when Carry is more than 0 add value to s vector
	if (c > 0) {
		s.push_back(c);
	}

	return s; 
}

std::vector<int> FinalK(std::vector<int> mul){
	
	//Delete extra 0 on the left in the original vector
	std::vector<int> t;
	int NotZeros = mul.size()-1;
	
	while(mul[NotZeros] == 0 && NotZeros > 0){
		NotZeros--;
	}

	for (int i = NotZeros; i > -1; i--){
		t.push_back(mul[i]);
	}
	return t;
}

//School Method for Multiplicacion   
std::vector<int> School(std::vector<int> a, std::vector<int> b, int B){

	//Return 0 when one of the vector has the value 0
	//And return the one vector value when the other is 1
	if (a.size() == 1){
		if (a[0] == 0)
			return a;
		else if (a[0] == 1)
			return b;
	} else if (b.size() == 1){
		if (b[0] == 0)
			return b;
		else if (b[0] == 1)
			return a;
	}

	int c = 0;

	int mulSize = a.size() + b.size();

	std::vector<int> mul(mulSize, 0);

	//Multiplication every digit at the time
	for (int i = 0; (unsigned)i < a.size(); i++){
		for (int j = 0; (unsigned)j < b.size(); j++){
			mul[i+j] += a[i] * b[j];
		} 
	}

	for (int i = 0; (unsigned)i < mul.size()-1; i++){
		//Carry when the multiplication is more than the base
		if (mul[i] > B-1){
			c = mul[i]/B;
			mul[i] = mul[i] - (c*B);
			mul[i+1] = mul[i+1] + c;
		} else {
			c = 0;
		}
	}
	
	return mul;
}

//Karatsuba Algorithm
std::vector<int> Karatsuba(std::vector<int> a, std::vector<int> b, int B){	

	//Use school method when the size is less than 4 digits
	if (a.size() < 4 || b.size() < 4 )
		return School(a, b, B);

	//Add an extra 0 to left to make the sizes even
	int n = nSize(a,b);
	if (n%2 != 0){
		a.push_back(0);
		b.push_back(0);
	}
	n++;

	int m = n/2;

	std::vector<int> a0, a1, b0, b1, p0, p1, p2, k;
	
	for (int i = 0; i < m; i++){
	//Divide a in 2 parts.	
		a0.push_back(a[i]);
		a1.push_back(a[i+m]);
	//Divide b in 2 parts.
		b0.push_back(b[i]);
		b1.push_back(b[i+m]);
	}

//P0 = a0 * b0
	if (a0.size() < 4 || b0.size() < 4)
		p0 = School(a0, b0, B);
	else
		p0 = Karatsuba(a0, b0, B);

//P2 = a2 * b2
	if (a1.size() < 4 || b1.size() < 4)
		p2 = School(a1, b1, B);		
	else 
		p2 = Karatsuba(a1, b1, B);
	
	std::vector<int> MulA1B0, MulA0B1;
// a1 * b0
	MulA1B0 = School(a1, b0, B);
// a0 * b1
	MulA0B1 = School(a0, b1, B);
//P1 = (a1 * b0) + (a0 * b1)
	p1 = AddNum(MulA1B0, MulA0B1, B);

	for (int i = 0; i < m; i++){
	//P2 = P2*B^2m
		p2.insert(p2.begin(), 0);
		p2.insert(p2.begin(), 0);
	//P1 = P1*B^m
		p1.insert(p1.begin(), 0);
	}

	//Karatsuba = (P0 + P2) + P1
	k = AddNum(p0, p2, B);
	k = AddNum(k, p1, B);

	return k;
}

int main()
{	
	std::string I1, I2; 
	int B = 0;
	std::vector<int> x, y, a, b, s, p, fnS, fnP;
	
	// Take 1 and 2 input numbers. 
	std::cin >> I1;
	std::cin >> I2;

	// Vector 'a' with the 1 int in reverse
	//std::string s_a = std::to_string(I1);
	for (int i = I1.size()-1; i > -1 ; i--){
		x.push_back(I1[i] - '0');	
	}

	// Vector 'b' with the 2 int in reverse
	//std::string s_b = std::to_string(I2);
	for (int i = I2.size()-1; i > -1 ; i--){
		y.push_back(I2[i] - '0');	
	}

	// Take Base (only from 1 to 10)
	std::cin >> B; 
	if (B < 1 || B > 10){ return 0;}

//Addition
	s = AddNum(x,y,B);
	//Delete extra 0 on the left in the original vector
	fnS = FinalK(s);

	// Return new vector with the same size with zeros on the left 
	CopySame(x,y,a,b);
	
//Karatsuba
	p = Karatsuba(a,b,B);
	//Delete extra 0 on the left in the original vector
	fnP  = FinalK(p);

	//Print Integer Addition Result
	for (int i = 0; (unsigned)i < fnS.size(); i++){
		std::cout << fnS[i];
	}
	std::cout << " ";

	//Print Karatsuba algorithm Result
	for (int i = 0; (unsigned)i < fnP.size(); i++){
		std::cout << fnP[i];
	}
	std::cout << " ";

	//Print Integer Division
	std::cout << "0" << std::endl;

	return 0;
}