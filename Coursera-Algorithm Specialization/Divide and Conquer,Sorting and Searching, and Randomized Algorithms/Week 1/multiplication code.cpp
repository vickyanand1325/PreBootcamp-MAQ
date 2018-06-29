#include<bits/stdc++.h>
using namespace std;

string ddiff(string num1,string num2){
    if (num1 == num2)
        return "0";
    
	int len1 = num1.length();
    int len2 = num2.length();
    
	int diff = len1 - len2;
    int carry = 0;
    
	string res = "";
	
    for(int i = len2 - 1;i >= 0; i--){
            int d = (num1[i+diff]-'0') - (num2[i]-'0') - carry;
            
            if(d<0){
                d += 10;
                carry = 1;
			}
			else{
				carry = 0;
			}
			
            char ch = d +'0';
            res = ch + res;
    }

    for(int j = len1-len2-1;j >= 0; j--){

        if(carry == 1 && num1[j] == '0'){
            char ch = '9';
            res = ch + res;
            continue;
        }
        
        int d = (num1[j]-'0') - carry;
        
		if(j > 0 || d > 0){
            char ch1 = d +'0';
            res = ch1 + res;
        }
        carry = 0;
    }

    int count = 0;
    for(int i = 0;i < res.length();i++){
        if(res[i]-'0' > 0)
            break;
        else
            count++;
    }
    
    res = res.substr(count);

    return res;
}


string addd(string num1, string num2){
	
	int diff = num1.length()-num2.length();
	
	if(diff<0)
		swap(num1, num2);
	
	diff = abs(diff);
	int carry = 0;
	
	string res = "";
	
	int len1 = num1.length();
	int len2 = num2.length();
	
	for(int i = len2 - 1;i >= 0; i--){
            
			int d = (num1[i+diff]-'0') + (num2[i]-'0') + carry;
            
            if(d>9){
            	d = d%10;
                carry = 1;
			}
			else{
				carry = 0;
			}
            
            char ch = d +'0';
            res = ch + res;
    }
    
    for(int j = len1-len2-1;j >= 0; j--){

        int d = (num1[j]-'0') + carry;
        
		if(d>9){
        	d = d%10;
            carry = 1;
		}
		else{
			carry = 0;
		}
        
        char ch1 = d +'0';
        res = ch1 + res;
    }
    
    if(carry > 0){
        char ch1 = carry +'0';
        res = ch1 + res;
    }

    int count = 0;
    for(int i = 0;i < res.length();i++){
        if(res[i]-'0' > 0)
            break;
        else
            count++;
    }
    
    res = res.substr(count);

    return res;
}

string prod(string num1, string num2){
//	cout<<num1<<endl;
//	cout<<num1.length();
	
	int n = num1.length();
	int len1 = num1.length();
	int len2 = num2.length();
	
	string a,b,c,d;
	
	a = b = c = d = "";
	
	if (len1 == 1){
	    
		int first = num1[0]-'0';
	    int second = num2[0]-'0';
	    
		int result = first*second;
	
		
	    char last1 = ((result%10))+'0';
	    result = result / 10;
	    
		char last2 = ((result%10))+'0';
	    
		string res = "";
	    
		res = last1 + res;
		
	    res = last2 + res;
	    
	    string res2;
	    res2 = res;
	    
		if (res[0] == '0'){
	        res = "";
	        res = res + last1;
	        return res;
	    }
		else
			return res2;
	}

	
	int mid = (len1-1)/2;
	
	for(int i = 0;i <= mid;i++)
	    a = a + num1[i];
	
	for(int i= mid+1 ; i<len1;i++)
	    b = b + num1[i];
	
	for(int i= 0;i <= mid ;i++)
	    c = c + num2[i];
	
	for(int i= mid+1; i <len1;i++)
	    d = d + num2[i];
	
	
	int diff = a.length()-c.length();
	
	if(diff>0){
		for(int i=0;i<diff;i++){
			c = '0' + c;
		}
	}
	else if(diff<0){
		diff *=-1;
		for(int i=0;i<diff;i++)
			a = '0' + a;
	}
	
	string product1 = prod(a,c);
	
	 diff = b.length()-d.length();
	
	if(diff>0){
		for(int i=0;i<diff;i++){
			d = '0' + d;
		}
	}
	else if(diff<0){
		diff *=-1;
		for(int i=0;i<diff;i++)
			b = '0' + b;
	}
	
	string product2 = prod(b,d);

	string ab = addd(a,b);
	string cd = addd(c,d);
	
	diff = ab.length()-cd.length();
	
	if(diff>0){
		for(int i=0;i<diff;i++){
			cd = '0' + cd;
		}
	}
	else if(diff<0){
		diff *=-1;
		for(int i=0;i<diff;i++)
			ab = '0' + ab;
	}

	string product3 = prod(ab,cd);

	string ddiff1 = ddiff(product3,product2);

	string ddiff2 = ddiff(ddiff1,product1);

	if(n%2 !=1){

	    for(int i = 1;i <= n; i++){
		    product1 = product1 + '0';
		}

	}
	else{
		for(int i = 1;i <= n-1; i++){
		    product1 = product1 + '0';
		}
	}
	
	for(int i = 1;i <= (n/2); i++)
	    ddiff2 = ddiff2 + '0';	


	string result1 = addd(product1,ddiff2);
	string finalresult = addd(product2,result1);

	return finalresult;

	return "";
}

int main(){
	
	freopen("input.txt", "r", stdin); // redirects standard input
	freopen("output.txt", "w", stdout); // redirects standard output
	
	string num1;
	string num2;
	
	cin>>num1;
	cin>>num2;
	
	int size1 = num1.length();
	int size2 = num2.length();
	
	int diff = abs(size1-size2);
	
	if(size1>size2){

		for(int i=0;i<diff;i++)
			num2 = '0' + num2;			
	}
	else if(size1<size2){
		
		for(int i=0;i<diff;i++)
			num1 = '0' + num1;
	}
	
	if(num1.length()==1){
		num1 = '0' + num1;
		num2 = '0' + num2;
	}
	
	string res = prod(num1, num2);
	
	cout<<res<<endl;
	return 0;
}
