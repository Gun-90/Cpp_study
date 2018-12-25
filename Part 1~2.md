## Chapter01 C언어 기반의 C++

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



### 01-2. 함수 오버로딩 *

- 함수호출시 전달되는 인자(Parameter)를 통해 함수를 구분

- 반환형으로는 함수를 구분하는 기준이 될수 없다.

- 필요성

  - 만약, 정수값들을 더해서 평균을 내는 메소드를 만들어서 사용한다고 하면.  이걸 사용하다 보니 같은 기능을 하는 것으로서 실수를 다루는 메소드를 만들고 싶다면.  예를 들어, 정수를 위한 메소드 이름이 averge() 이었다면, 실수를 다루는 것은 조금이라도 이름이 달라야 하기 때문에 average_float()과 같은 식으로 작성해야 함

    하지만, 이런식으로 메소드들이 수없이 만들어지면 개발자는 모든 함수를 기억하기가 힘들어 짐.  이 경우 둘다 평균을 구하는 것이기 때문에 averge()라는 이름으로 사용하면 좋음.  C#에서는 이런 경우 average()라는 이름을 같이 사용할 수 있도록 함.

    즉, 정수를 인수로 받는 average()메소드와 실수를 인수로 받는 average() 메소드를 같이 정의할 수 있게 하는 것입니다



### 01-3. 매개변수의 디폴트 값 *

- 매개변수에 디폴트값을 지정하여 인수(argument)를 넣지 않으면 디폴트 값이 넣어짐
- 매개변수의 디폴트 값은 함수의 원형 선언에서만 위치시켜야 함
  - `int Adder(int num1 =1, int num2=2);`
- 매개변수 일부만 디폴트값 지정 가능 
- 오른쪽 매개변수 부터 지정해야함 ( 함수에 전달되는 인자가 왼쪽에서부터 오른쪽으로 채워지기 때문)
- 바텐더 늘 먹던걸로
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



### 01-4. inline 함수 *

- 매크로 함수 (매크로 함수 좀더 알아볼것 - 전처리기, 함수 몸체)
  - 장점 :실행속도가 빠르다
  - 단점 : 정의하기가 어렵다. 복잡한 함수 정의하기에는 한계가 있다.

-  inline 함수를 통해 매크로함수의 장점을 유지하되, 단점을 제거 가능.

- 반면 매크로 함수와 다른점은 매크로 함수는 자료형에 의존적이지 않은 함수라는 점.

  (inline함수는 자료형에 의존적)

- 템플릿을 이용하면 자료형에 의존적이지 않은 함수 완성 가능.

```c++
inline int SQUARE(int x){
	return x*x;
}

int main(void){
	std::cout << SQUARE(5) <<std::endl;
	std::cout <<SQUARE(12)<<std::endl;
	
	return 0;
	
}
```



### 01-5. 이름공간(namespace)에 대한 소개

- 같은 이름의 함수를 다른 이름공간에 배정하게되면 같은 이름으로 사용할수 있게된다.
- 중첩 사용가능
- 동일한 이름공간에 정의 된 함수를 호출할 때에는 이름공간 명시 할필요 없음
- `using`을 사용해 범위지정 없이 그냥 호출 가능.
- 별칭을 지정할수 있다.
- `::` 는 범위 지정 연산자.
  - 전역변수와 지역변수의 이름이 같을경우 범위지정 연산자를 통해 전역변수를 불러올수 있음

```c++
// 기본 사용법
namespace BestComImpl{
	void SimpleFunc(void){
		std::cout<<"BestCom define function"<<std::endl;
		
	}	
}

namespace ProgComImpl{
	void SimpleFunc(void){
		std::cout<<"ProgCom define function"<<std::endl;
	}
}
int main(void){
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	
}
```

```c++
// 이름공간 기반의 함수 선언과 정의 구분

#include <iostream>

namespace BestComImpl{
	void SimpleFunc(void);
}

namespace ProgComImpl{
	void SimpleFunc(void);
}

int main(void){
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	
	return 0;
}

void BestComImpl::SimpleFunc(void){
	std::cout<<"BestCom define function"<<std::endl;
	
}

void ProgComImpl::SimpleFunc(void){
	std::cout<<"ProgCom define function"<<std::endl;
}
```

```c++
//동일한 이름공간에 정의 된 함수를 호출할 때에는 이름공간 명시 할필요 없음

#include <iostream>

namespace BestComImpl{
	void SimpleFunc(void);
}

namespace BestComImpl{
	void PrettyFunc(void);
}

namespace ProgComImpl{
	void SimpleFunc(void);
}

int main(void){
	BestComImpl::SimpleFunc();
	return 0;
}

void BestComImpl::SimpleFunc(void){
	std::cout<<"BestCom define function"<<std::endl;
	PrettyFunc();
	ProgComImpl::SimpleFunc();
	
}

void BestComImpl::PrettyFunc(void){
	std::cout<<"So Pretty!!"<<std::endl;
	
}

void ProgComImpl::SimpleFunc(void){
	std::cout<<"ProgCom define function"<<std::endl;
}
```

```c++
// using을 사용해 범위지정 없이 그냥 호출 가능.
// 개별지정
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(void){
	int num=20;
	cout<<"Hello World!"<<endl;
	cout<<"Hello "<<"World!"<<endl;
	cout<<num<<' '<<'A';
	cout<<' '<<3.14<<endl;

	return 0;
}
```

```c++
// using을 사용해 범위지정 없이 그냥 호출 가능.
// 이름공간 std에 선언된 모든것에 대해 이름공간 생략

#include <iostream>

using namespace std;

int main(void){
	int num=20;
	cout<<"Hello World!"<<endl;
	cout<<"Hello "<<"World!"<<endl;
	cout<<num<<' '<<'A';
	cout<<' '<<3.14<<endl;

	return 0;
}
```

```c++
// 네임스페이스의 별칭지정

#include <iostream>
using namespace std;

namespace AAA{
	namespace BBB{
		namespace CCC{
			int num1;
			int num2;
			
		}
	}
}

int main(void){
	AAA::BBB::CCC::num1= 20;
	AAA::BBB::CCC::num2= 30;
	
	namespace ABC = AAA::BBB::CCC;
	cout<<ABC::num1<<endl;
	cout<<ABC::num2<<endl;
	
	return 0;
}
```

```c++
// 전역변수와 지역변수의 이름이 같을경우 범위지정 연산자를 통해 전역변수를 불러올수 있음

#include <iostream>
int val=100;

int main(void){
	int val=20;
	val+=3;
	::val+=7;
	
	std::cout<<val<<std::endl;
	std::cout<<::val<<std::endl;
	
	
	return 0;3
}
```



### 02-3 참조자(Reference)의 이해***

- `int &num2 = num1;` 의 형태
- 할당된 하나의 메모리 공간에 둘의 이름을 붙일때 사용
- 참조자의 수에 제한 없음
- 참조자를 대상으로도 참조자 선언 가능
- 변수에 대해서만 선언 가능
- `int &ref;` 참조자만 선언 불가능( 선언과 동시에 변수를 참조해야함)
- `int &ref = NULL`로  초기화 불가능
- 배열 요소도 참조 가능



### 02-4. 참조와 함수

- Call-by-value를 통해 두 변수의 저장된 값을 바꾸면 원한는 값을 얻을수 없음.



### 02-5. malloc & free를 대신하는 new & delete

- 동적할당시 `new`와 `delete`키워드를 사용해서 메모리 할당과 해제
- 배열 소멸시 `delete []arr1;`형태
- `new`와 `malloc`함수의 동작방식에는 차이가 있다.





### 02-6. C++에서 C언어의 표준함수 호출하기

- C를 더하고 .h를 빼면 됨 `#include <stdio.h>`  → `#include <cstdio>`



### 03-1. C++에서의 구조체

- C++에서의 구조체 변수를 선언 하는 방법`Car basicCar;` (typedef 선언 없이도 가능)
- 구조체 안에 함수 삽입 허용 → 함수를 인라인으로 처리하라는 의미가 됨(밖으로 빼내면 의미가 사라짐)
- 함수 선언부는 구조체에서 선언하고 정의는 구조체 외부로 뺄 수있다. → 코드 분석이 용이 해짐.



### 03-2. 클래스와 객체 *

- 구조체와 클래스의 특성은 같음(한가지 제외)
- 클래스는 접근과 관련해서 별도의 선언을 하지 않으면, 클래스 내에 선언된 변수 및 함수에 대한 접근은 허용하지 않음
- 접근제한자
  - `public` : 어디에서나 접근가능
  - `protected ` :클래스내에서만 접근가능
  - `private` : 상속관계에 놓여있을 때, 유도 클래스에서의 접근허용
- 파일분할
  - 인라인 함수는 헤더파일에 함께 넣어야 함



### 04-1. Information Hiding(정보 은닉) **

- ~~캡슐화된 코드를 제공할때 함부로 건드려서는 안되는 코드들을 보호하기 위해, 프로그램의 안정적 구현을 위해서는 정보은닉이 필요하다.~~
- 정보은닉이란 지정된 함수를 통해서만 데이터를 변경할수 있도록 하는것
  - 이렇게 함으로써 프로그래머의 실수 방지
  - 건드리지 말아야할 데이터를 컴파일러에게 미리 알려주고 건드리게 되면 경고를 띄워 주라는 의미
- `const` 함수를 통해 안전성을 높일수 있음

  - 이 함수내에서는 멤버 변수에 저장된 값을 변경하지 않겠다는 뜻.

  - `int GetX() const;` 형태

  - const가 아닌 **<u>함수</u>**의 호출이 제한




### 04-2. 캡슐화(Encapsulation) **

- 캡슐화란 클래스를 정의하는데 있어서 관련있는 데이터 및 함수를 하나로 묶는것
- 캡슐화에는 정보은닉이 기본적으로 포함 됨.*
  - c++에서는 클래스를 정의하면 디폴트로 private 접근제한자가 선언되므로



### 04-3. 생성자와(Constructor)와 소멸자(Destructor)**

- 생성자
  - `SimpleClass sc(100)` : 전역 및지역변수 형태
  - `SimpleClass * ptr2 = new SimpleClass(100)` : 동적 할당의 형태
  - `SimpleClass sc1();` 처럼 설정 불가능 : 컴파일러가 함수의 원형선언문으로 식별함
  - 클래스 생성시 멤버변수 초기화의 기능
  - 클래스의 이름관 함수의 이름이 동일
  - 반환형이 선언되어 있지않으며, 실제로 반환하지 않는다
  - 객체 생성시 딱 한번만 호출
  - 오버로딩 가능
  - 디폴트 값 설정가능
  - 이니셜라이저를 이용한 멤버 초기화
    ```Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2):upLeft(x1, y1), lowRight(x2, y2){}```
  - const 멤버변수도 이니셜라이저를 이용하면 초기화가 가능하다.
  - 클래스는 디폴트 생성자가 기본적으로 정의되어있음 하나라도 선언되어 있으면 디폴트 생성자는 삽입되지 않음
  - private생성자  ****
- 소멸자
  - `~AAA(){ }` 형태
  - 반환형 없음
  - 오버로딩, 디폴트 값 설정 불가능
  - 소멸자는 스택형식으로 호출됨(먼저 사용된게 나중에 삭제됨)

```c++
#include <iostream>
#include <cstring>
using namespace std;

class Person{
	private:
		char *name;
		int age;
		
	public:
		Person(char * myname, int myage){
			int len =strlen(myname)+1;
			name= new char[len];
			strcpy(name, myname);
			age=myage;
		}
		void ShowPersonInfo() const{
			cout<<"name: "<<name<<endl;
			cout<<"age: "<<age<<endl;
		}
		~Person(){
			cout<<name<<" called destrucor!"<<endl;
			delete []name;
			
		}
};

int main(void){
	Person man1("Lee dong woo", 29);
	Person man2("Jang dong gun", 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
    //장동건 먼저 삭제
    //이동우 삭제
	
	return 0;
	
}
```



### 04-4. 클래스와 배열 그리고 this 포인터 **

- `this`포인터는 그 주소 값과 자료형이 정해져 있지 않은 포인터

- 객체배열은 객체로 이루어진 배열
  - `SoSimple arr[10];` 형태
- 객체 포인터 배열은 객체의 주소 값 저장이 가능한 포인터 변수로 이루어진 배열
  - `SoSimple * ptrArr = new SoSimple[10];` 형태
- `this`포인터를 이용하면 parameter와 멤버변수 이름이 같아도 구분할수 있음





### 05-1 '복사 생성자'와의 첫 만남 **

- `int num=20;`과 `int num(20);`은 같다.
- 자신과 같은 객체를 인자로 받는 생성자를 복사생성자라고 함
- SoSimple 클래스 에서는`SoSimple(const SoSimple &copy):num1(copy.num1){}` 의 형태
- 호출시점이  다른 일반 생성자와 차이가 있다
- const를 선언을 해주면 좀더 예쁘게(어떤 의미인지 모르겠음) → 인수로 전달되는 객체를 바꾸지 않겠다(보호하겠다는 표현)
- 복사 생성자를 정의하지않으면 `디폴트 복사 생성자` 자동으로 삽입
- `explict`으로 막을수 있음 → 이 경우 `AAA obj(3);`형태로만 객체 생성(`AAA obj2 =obj;` 불가능)

### 05-2. '깊은 복사'와 '얕은 복사' **

-  `디폴트 복사 생성자`로 하는 복사는 `얕은 복사`라고 칭함
-  얕은 복사는 별개의 멤버변수를 복사하는 것이아니라 주소만 복사한다.(223p 그림)
-  깊은 복사를 위해선 복사생성자를 설정해야함



### 05-3. 복사 생성자의 호출시점 **

- 객체를 새로 생성, 단 생성과 동시에 동일한 자료형의 객체로 초기화 해야한다.
  - 기존에 생성된 객체를 이용해서 새로운객체를 초기화 하는 경우
  - Call-by-value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
  - 객체를 반환하되, 참조형으로 반환하지 않는 경우
- 임시객체의 소멸 시점
  - 임시객체는 다음 행으로 넘어가면 바로 소멸되어 버림
  - 참조자에 참조되는 임시객체는 바로 소멸되지 않는다.

### 

### 06-1. const와 관련해서 아직 못다한 이야기 



### 06-2. 클래스와 함수에 대한 friend 선언 **

- A 클래스가 B 클래스를 대상으로 friend선언을 하면, B 클래스는 A 클래스의 private 멤버에 직접 접근이 가능.
- A 클래스도 B  클래스의 Private 멤버에 직접 접근이 가능 하려면, B 클래스가 A 클래스를 대상으로 friend 선언을 해줘야한다.

### 06-3. C++에서 static **

- `static변수`는 전역변수와 마찬가지로  초기화하지 않으면 0으로 초기화 됨.
- `static 멤버함수` 내에서는 static 멤버변수와 static 멤버 함수만 호출이 가능하다.
- `mutable`
  - `const` 함수 내에서의 값의 변경을 예외적으로 허용한다.
- `const static` 변수
  - `const static int RUSSIA = 17057540;`처럼 선언과 동시에 초기화 가능
- 객체의 멤버로 존재하지 않는다.
  - 따라서 `private`선언시 객체 내부에서 접근 할 수 없다.

- 전역변수에 선언된 `static`
  - 선언된 파일 내에서만 참조를 허용하겠다는 의미
- 함수 내에 선언된 `static`의 의미
  - 한번만 초기화 되고, 지역변수와 달리 함수를 빠져나가도 소멸되지 않는다.
- 필요성 :
  - 전역 변수를 객체들이 공유하는 변수로 선언한면 어디서든 접근이 가능하므로 안전하지 않다
  - 하지만 클래스의 `static`멤버 로 선언시 이러한 문제의 소지를 없앨 수 있다.

