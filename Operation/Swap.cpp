
/*----four methods for exchange two elements ----*/

//first method   ,is the best
template <typename T>
void Swap(T &a, T &b)
{
	if(a==b){// if a equils b; 
		return;
	}
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

//second method ,
template <typename T>
void Swap(T &a, T &b)
{
	a = a + b;     //maybe leads to ArrayIndexOutOfBounds 
	b = a - b;
	a = a - b;
}

//third method ,
template <typename T>
void Swap(T &a, T &b)
{
	a = a * b;     //maybe leads to ArrayIndexOutOfBounds 
	b = a / b;
	a = a / b;
}

//fourth method 
template <typename T>
void Swap(T *a, T *b)
{
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;
}




