# Chapter01 C언어 기반의 C++

### 01-1.  << 연산자를 이용해 연속해서 출력대상 표현과 endl을 통한 개행

- num1과 ' '(공백)과 num2를 

  printf("%d %d",num1,num2)로 표현하지 않아도됨( 포맷지정 불필요 )

- cin도 마찬가지

```c++
int num1 = 3,num2 =4;
char str[100];
// c
printf("%d %d",num1,num2);
// c++
std::cout << num1 << ' ' <<num2 << std::endl;

// c 
scanf("%s",str); // 배열명은 주소이기때문에 &안써줘도됨
// c++
std::cin>>str;

```



### 01-2. 함수 오버로딩

- 함수호출시 전달되는 인자(Parameter)를 통해 함수를 구분
- 반환형으로는 함수를 구분하는 기준이 될수 없다.



### 01-3. 매개변수의 디폴트 값

- 매개변수에 디폴트값을 지정하여 인수(argument)를 넣지 않으면 디폴트 값이 넣어짐
- 매개변수의 디폴트 값은 함수의 원형 선언에서만 위치시켜야 함
- 매개변수 일부만 디폴트값 지정 가능 
- 오른쪽 매개변수 부터 지정해야함 ( 함수에 전달되는 인자가 왼쪽에서부터 오른쪽으로 채워지기 때문)
```c++
// int Adder(int num1 =1, int num2); (x) => 오른쪽 매개변수 부터 디폴트 지정
int Adder(int num1 =1, int num2=2);

int main(void){
	std::cout << Adder() << std::endl;
	std::cout << Adder(5) << std::endl;
	std::cout << Adder(3,5) << std::endl;
	
	return 0;
}

int Adder(int num1, int num2){
	return num1 + num2;
}
```



### 01-4. inline 함수

- 매크로 함수 
  - 장점 :실행속도가 빠르다
  - 단점 : 정의하기가 어렵다. 복잡한 함수 정의하기에는 한계가 있다.
- 