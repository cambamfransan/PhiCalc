//Programmer: Alireza Shafaei
//Phi Calculation
//Tested with gcc version 4.2.1
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "ComputePhi.hpp"


phi::bignum ans,divi,buff,buff2,phiNum;
//ans div buff buff2 phi are 5 big numbers!

//this function cleans whole stored data of a BigNumber
void phi::clean(phi::bignum *a, int decPlace){
	for(int i=0;i<decPlace+2;i++){
		a->num[i]=0;
		//for every index
	}
	a->len=0;
	//length of number must be zero
}

int phi::computeDigit(int decPlace){
	ans.num[0]=2;
	ans.len=1;
	//first number of SQRT is entered manually
	divi.num[0]=1;
	divi.len=3;
	//Clock initialization to find overall time
	std::reverse(divi.num,divi.num+divi.len);
	calc(decPlace);
	//SQRT(5) calculation
	phifinalize();
	//Phi calculation
	//Clock stops
	return phiNum.num[0];
	//shows the result which is Phi
}

void phi::calc(int decPlace){
	for(int found=0;found<decPlace;found++){
	//For each decimal place to find
		buff.len=0;
		buff2.len=0;
		//Cleans first and second buffer
		multiply(&ans,&buff,20, decPlace);
		//Multiplies ans to 2 and saves it in buff
		int best=0;
		while(best<9){
		//Findes best number to multply to(instead of writing Divide function :D)
			buff.num[0]=best+1;
			buff.len=buff.len;
			multiply(&buff,&buff2,best+1, decPlace);
			if(isbigger(&divi,&buff2))
				best++;
			else
				break;
		}
	buff.num[0]=best;
	multiply(&buff,&buff,best, decPlace);
	diff(&divi,&buff,&divi);
	std::reverse(divi.num,divi.num+divi.len);
	divi.len+=2;
	std::reverse(divi.num,divi.num+divi.len);
	std::reverse(ans.num,ans.num+ans.len);
	ans.num[ans.len]=best;
	ans.len++;
	std::reverse(ans.num,ans.num+ans.len);
	//SQRT Algorithm
	}
}

void phi::multiply(phi::bignum *in,phi::bignum *out,int coef, int decPlace){
	//out=in*coef
	int i=0;
	if(coef==0){
		clean(out, decPlace);
		out->len=1;
		return;
	}
	int temp=0;
	int len=in->len;
	while(i<len){
		out->num[i]=(in->num[i]*coef)+temp;
		temp=out->num[i]/10;
		out->num[i++]%=10;
	}
	if(i==len && temp!=0){
		out->num[i]=(in->num[i]*coef)+temp;
		temp=out->num[i]/10;
		out->num[i++]%=10;
	}
	out->len=i;
}

bool phi::isbigger(phi::bignum *a,phi::bignum *b){
//checks whether  a > b or not
	if(a->len!=b->len)
		return (a->len>b->len);
	for(int i=0;i<a->len;i++)
		if(a->num[a->len-i-1]!=b->num[b->len-i-1])
			return a->num[a->len-i-1]>b->num[b->len-i-1];
	return false;
}

void phi::balance(phi::bignum *num,int i){
//It's used to make difference easier!
	if(num->num[i+1]==0){
		balance(num,i+1);
	}
	num->num[i+1]--;
	num->num[i]+=10;
	if(i==num->len-2 && num->num[num->len-1]==0)
		num->len--;
}

void phi::diff(phi::bignum *a,phi::bignum *b,phi::bignum *ans){
//ans=|a-b|
	bignum *a1,*a2;
	if(isbigger(a,b)){
		a1=a;
		a2=b;
	}else{
		a1=b;
		a2=a;
	}
	if(ans!=a1){
		for(int i=0;i<a->len;i++)
			ans->num[i]=a1->num[i];
		ans->len=a1->len;
	}
	for(int i=0;i<a2->len;i++){
		if(ans->num[i]<a2->num[i])
			balance(ans,i);
		ans->num[i]-=a2->num[i];
	}
	int i=0;
	while(ans->num[ans->len-i-1]==0)
		i++;
	ans->len-=i;
}

void phi::phifinalize(){
//makes Phi
	int temp=0;
	ans.num[ans.len-1]+=1;
	phiNum.len=ans.len;
	for(int i=0;i<ans.len;i++){
		temp*=10;
		temp+=ans.num[ans.len-i-1];
		phiNum.num[phiNum.len-i-1]=temp/2;
		temp%=2;
	}
}
