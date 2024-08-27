
/*

Infix to Pre/Postfix

expr; // Given fully parenthesized infix expression  
Stack S;  

while (not done with expr) { //For each token in the infix expression  
	t = nextToken(expr);  
	
	if (t == ‘)’) { //If a right ) then have subexpression  
		rhs = S.pop();  
		op = S.pop();  
		lhs = S.pop();  
		S.push( rhs + lhs + op ); //Convert subexpression into Post/Pre fix  
	} else if (t != ‘(‘) { //Push everything but left (  
		S.push(t);  
	}  

	return S.pop(); //Final Pre/Post fix expression on TOS  
}


*/




/*  POSTFIX INTO ASSEMBLY & COUNTING TMP'N'

char counter = '0'
String t;
String assembly;

t = "TMP" + counter;  ---> TMP0
assembly += eval(t);    ---> eval / loadInstruction
stack.push(t)
counter ++

return assembly;

*/

