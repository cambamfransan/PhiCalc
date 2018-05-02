#ifndef COMPUTE_PHI_H
#define COMPUTE_PHI_H

namespace phi
{
#define MAX 1000200 
	//a bignum structure is used to carry big number's data!

struct bignum{
	int num[MAX];
	int len;
	bignum(){
		for(int i=0;i<MAX;i++)
			num[i]=0;
		len=0;
		//this function clears the number during initialization of it
	}
};
	
	int computeDigit(int decPlace);	
	void calc(int decPlace);
	//this function calculates square root of 5
	void multiply(bignum *in,bignum *out,int coef, int decPlace);
	//this function multiplies Big number 'in' to coef and saves it in big number 'out'
	bool isbigger(bignum *a,bignum *b);
	//this function checks whether a > b or not
	void diff(bignum *a,bignum *b,bignum *ans);
	//this function returns | a - b | in ans which is a big number
	void phifinalize();
	//this function adds 1 to square root of five then divides it to 2 to calculate Phi
	void clean(bignum *a, int decPlace);
	void balance(bignum *num,int i);
}
#endif
