# 객체지향의 전개

## 상속의 이해

- 상속에 들어가기에 앞서

  - 상속 : 기존에 정의해 놓은 클래스의 재활용을 목적으로 만들어진 문법적 요소(좋은 특성을 물려받는 것 이라고도 설명할수 있다) => 작가는 아니라고 말함
  - 연관된 클래스들을 동일하게 접근하기 위함 (중요!!!)
  - ~~핸들러(컨트롤) 클래스 : 기능의 처리 담당~~
  - 모든 소프트웨어에서 중요시 하는것
    - 요구사항의 변경에 대응하는 프로그램의 유연성
    - 기능의 추가에 따른 프로그램의 확장성


- 상속의 문법적인 이해


  - `class UnivStudent : protected Person{};` 의 형태

  - 하위 클래스 생성시 상위클래스 생성자를 호출하지 않으면 상위클래스의 void생성자 호출

  - 하위 클래스에서 상위클래스의 생성자는 100% 호출 - 

  - 객체소멸시 하위클래스 소멸자 실행후, 상위 클래스 소멸자 실행



  - 상속받은 객체의 초기화시 상위클래스를 호출하여 초기화  하는 것이 좋다

    - ```c++
      UnivStudent(char * myname, int myage, char * myname)
      	:Person(myage, myname)
      {
          strcpy(major, mymajor);
      }
      ```



- Protected 선언과 세가지 형태의 상속 ************************** 다시보기

  - protected의 의미 protected보다 접근의 범위가 넓은 멤버는 proteced로 변경시켜서 상속하겠다는 의미
- 상속을 위한 조건

  - IS A
  - HAS A





## 상속과 다형성

- 다형성 : 같은 실행 문이 객체의 타입에 따라 다른형태를 띄게함
  - int 에서 +는 두 수의 합으로 표현
  - String에서 + 는 두 배열을 하나의 배열로 합쳐서 배열을 만드는 것
- 객체 포인터의 참조관계
  - 상위 클래스는 하위 클래스의 객체를 포인터로 가리킬수 있다.
    - IS A 관계 처럼 CCC는 AAA이다 또는 CCC는 AAA일종이다 라고 설명할수 있기때문
    - 하위 클래스는 상위클래스를 가리킬수 없나? 궁금
  - 함수 오버라이딩
- 가상함수
  - 객체 포인터
    - 상위 클래스 포인터로 상속받는 개체 참조 가능 
    - 상속받는 클래스의 멤버는 참조 불가 => 포인터형에 해당하는 클래스에 정의된 멤버에만 접근이 가능
  - 컴파일러는 포인터의 자료형을 기준으로 판단, 실제 가리키는 객체의 자료형을 기준으로 판단 (X)
  - 멤버 함수를 오버라이딩시 포인터 변수의 자료형에 따라서 함수 종류가 달라진다 -> 발표에 넣자
  - 가상함수 `virtual` 선언 시 포인터의 자료형을 기반으로 호출대상을 결정하지 않고 포인터 변수가 실제로 가리키는 객체를 참조하여 호출의 대상을 결정
  - 순수 가상함수
    -  추상클래스에서 사용
    - 객체 생성을 목적으로 정의되지 않는 클래스에서 사용
    - `virtual int GetPay() const = 0;` 의 형태처럼 몸체가 없고 = 0의 대입을 표시
    - 다형성
      - 문장은 같은데 결과는 다르다
- 가상 소멸자와 참조자의 참조 가능성
  - 가상소멸자
    - `virtual`로 선언된 소멸자
    - 하위 객체부터 실행됨-- test 필요
  - 참조자
    - 포인터 처럼 참조자의 자료형에 따라서 함수 종류가 달라진다





## 가상의 원리와 다중상속
- 멤버함수와 가상함수의 동작원리
- 다중상속에 대한 이해



# 객체지향의 완성
## 연산자 오버로딩1
- 연산자 오버로딩의 이해와 유형
  - 기존의 존재하던 연산자의 기본 기능 이외에 다른 기능을 추가함
  - 객체도 완벽히 기본 자료형처럼 취급하기 위해
  - `operator+`의 형태 (+부분은 다른연산자로 대체가능)
  - const 선언을 통해 안정화하면 좋음
    - 피연산자으 ㅣ값을 변경하는 것이 아닉 ㅗ새로운 연산의 결과를 만들어 내는것이기 때문에
  - 연산자 오버로딩 방법
    - 밑의 둘의 차이가 뭘까
    - 멤버함수에 의한 연산자 오버로딩
      - `pos1.operator+(pos2);`의 형태
    - 전역함수에 의한 연산자 오버로딩
      - `operator+(pos1, pos2);` 의 형태
  - 그밖에 외워야할것 410p
- 단항 연산자의 오버로딩 412p 좀더 확인 필요
  - `return *this`를 통해 자기 자신을 반환
  - 전위 증가와 후위 증가
    - `++pos` → `pos.operator++();`
    - `pos++` → `pos.operator++(int);`
    - 422p
- 교환법칙 문제의 해결
- cout, cin 그리고 endl의 정체





## 연산자 오버로딩2

- 반드시 해야 하는 대입 연산자의 오버로딩
  - 디폴트 대입 연산자 (발표 X)
    - 복사 생성자에서 보인 문제와 동일
  - 하위클래스의 대입 연산자에는 아무런명시를 하지 않으면 상위클래스의 대입 연산자가 호출되지 않는다.
- 배열의 인덱스 연산자 오버로딩
  - 배열은 `arr[-1];` 과 같이 경계검사를 하지 않는다는 단점을 지니고있다.
  - `arrObject.operator[](2)`
  - 함수뒤 `const`도 오버로딩의 조건
  - `exit(1)`은 프로그램을 종료시킴
- 그 이외의 연산자 오버로딩
  - 건너 뜀 

## String 클래스의 디자인

- C++의 표준과 표준 string 클래스
  - `#define <string>` 추가해야 사용할 수있음
- 문자열 처리 클래스의 정의

## 템플릿 1

- 함수 또는 클래스를 여려 자료형으로 만들기 위한 틀

- 템플릿에 대한 이해와 함수 템플릿

  - 함수템플릿 - 함수를 만드는데 사용되는 템플릿

  - 템플릿 함수 - 템플릿을 기반으로 만들어진 함수 ( 컴파일러가 만들어낸)

  - ```c++
    template <typename T> // typename 대신에 class 도 사용가능, T대신 다른 글자도사용가능
    T Add( num1, T num2){
        return num1+num2;
    }
    ```

  - ```c++
    Add<int>(15,20); //처럼 호출 <int>는 생략가능 (컴파일러가 자료형 참조)
    ```

  - ```c++
    template <class T1, class T2> // 둘이상의 템플릿 선언하기
    void ShowData(double num){
    	cout<<(T1)num<<", "<<(T2)num<<endl;
    }
    ```

- 함수 템플릿의 특수화(Specialization)
  - 함수템플릿을 통해 함수를 생성할때 특정한 데이터타입을 지정하여 그 데이터 타입만 별도로 함수를 지정

  - ```c++
    template <>
    const char* Max(const char* a, const char* b){
        cout<<"const char* Max<const char*>(const char* a, const char* b)"<<endl;
        return strcmp(a, b) > 0? a: b;
    }
    ```

- 클래스 템플릿

  - 클래스 템플릿 기반의 객체생성에는 반드시 자료형 정보를 명시해야함

  - ```c++
    template <typename T> //클래스 템플릿으 ㅣ형태
    class Point{
      private:
        T xpos, ypos;
      public:
        Point(T x=0, T y=0) :xpos(x), ypos(y){}
        void ShowPosition() const{
            cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
        }
    };
    ```

  - ```c++
    template <typename T> // 외부에서 정의시
    T SimpleTemplate<T>::SimpleFunc(const T& ref){ ... }
    ```

  - 

## 템플릿 2 

- 13에서 공부한 내용의 확장

  - 클래스 템플릿 기반의 객체 생성시 템플릿 클래스를 저장 시에는

    - `BoundCheckArray<point<int>> oarr(50);`

  - point<int>형 포인터라면

    - `BounCheckArray<point<int>*> oparr(50);`

  - typedef 선언을 통해

    - ```c++
      typedef Point<int>* POINT_PTR;
      BoundCheckArray<POINT_PTR> oparr(50);
      ```

    - 

- 클래스 템플릿의 특수화

  - 함수 템플릿과 같음

  - 부분 특수화

    - ```c++
      template<typename T1, typename T2>
      class MySimple { ... }
      
      template <typename T1> //부분 특수화
      class MySimple<T1, int> { ... }
      ```

- 템플릿 인자

  - 템플릿 매개변수에는 변수의 선언이 올수 있다.

  - ```c++
    template <typename T, int len>
    class SimpleArray{
    private:
    	T arr[len];
    public
    T& operator[] (int idx){
    		return arr[idx];
    	}
    }
    
    //객체 생성시
    SimpleArray<int, 5> i5arr;
    SimpleArray<int, 7> i7arr; // 두 객체는 서로 다른 자료형의 클래스로 구분됨
    
    ```

  - 디폴트 값 지정도 가능 (발표하자)

    - ```c++
      template <typename T=int, int len=7> // 디폴트값 지정~!
      class SimpleArray{
      private:
      	T arr[len];
      public
      T& operator[] (int idx){
      		return arr[idx];
      	}
      }
      
      //객체 생성시
      SimpleArray<int, 5> i5arr;
      SimpleArray<int, 7> i7arr; // 두 객체는 서로 다른 자료형의 클래스로 구분됨
      ```

- 템플릿과 static

  - 템플릿 기반의   static  멤버 초기화

    - ```c++
      //템플릿 클래스가 있다고 가정
      template <typename T>
      T SimpleStaticMem<T> ::mem=0;
      ```

    - 특수화

      - ```c++
        template<>
        long SimpleStaticMem<long>::mem=5;
        ```


  ## 예외처리

- 예외상황과 예외처리의 이해

  - 예외란 문법적인 오류가 아닌, 프로그램의 논리에 맞지 않는 상황을 의미

- c++의 예외처리 메커니즘

  - try - 예외 발견
  - catch - 예외를 잡는다
  - throw - 예외를 던진다.
    - 예외가 발생했음을 알리는 문장의 구성에 사용됨
  - try 묶는 기준 - 일 단위로 구성

- Stack unwinding(stack 풀기)

  - 함수내에 throw 문만 있고 try ~catch가 없을경우 함수를 호출한 영역으로 throw 전달(return 값의 반환과 유사)

  - 예외상황이 발생한 위치와 예외상황을 처리해야 하는 위치가 다른경우

    - 함수내에 throw와 함수 밖에서 try ~catch 

  - 예외가 처리되지 않아서 함수를 호출한 영역으로 예외 데이터가 전달되는 방식을 스택 풀기라한다

  - 자료형이 일치하지 않아도 예외 데이터는 전달된다.

  - 하나의 try와 다수의 catch 블록이 가능 - throw값을  어떤 catch문이 캐치할지 어떻게 구분하는지 알아야할듯

  - 전달되는 예외의 명시

    - ```c++
      int ThrowFunc(int num) throw (int, char){}
      ```

    - catch문에서 int와 char이외의 데이터가 전달될 경우 unexpected함수의 호출이되며 이함수내에서 terminate함수의 호출로 인해서 프로그램은 종료

    - 

- 예외상황을 표현하는 예외 클래스의 설계

  - 예외 발생을 알리는데 사용되는 객체를 예외 객체
  - 예외 객체 생성을 위해 정의된 클래스를 예외 클래스
  - catch문이 둘이상일 경우 첫번째 catch문 부터 이 예외의 타당한 catch 블록인지 검사 613p 다시보기

- 예외처리와 관련된 또 다르 ㄴ특성들

  - new 연산자에 의해서 발생하는 예외

    - bad_alloc

  - 모든 예외를 처리하는 catch 블록

    - ```c++
      try{
          
      }catch{ ... } // ...은 모든 예외를 다 받아주겠다는 선언
      ```

  - catch블록에 전달된 예외는 다시 던져질 수 있다. 이로인해 하나의 예외가 둘 이상의 catch 블록에 의해서 처리되게 할수있음 616p


## c++의 형 변환 연사자

- c++에서 형 변환 연산
  - dynamic_cast
    - 상속관계에서의 안전한 형변환
    - 상속관계에 있는 하위 클래스의 포인터 및 참조형 데이터를 상위 클래스의 포인터 및 참조형 데이터로 형변환하겠다
    - `dynamic_cast<T>(expr)`의 형태
  - static_cast
    - a 타입에서 B타입으로
    - 하위 클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로뿐만 아니라 기초클래스의 포인터 및 참조형 데이터도 유도 클래스의 포인터 및 참조형 데이터로 아무런 조건 없이 형 변환시켜 줄게, 하지만 그에 대한 책임은 네가 져야해
    - `static_cast<T>(expr)`의 형태
    - ex) `Truck * ptruck1 = static_cast<Truck*>(pcar1);`
    - dynamic_cast보다 빠름
  - const_cast
    - const의 성향을 삭제하라
    - const 선언으로 인한 형(type)의 불일치가 발생해서 인자의 전달이 불가능한 경우에 유용하게 사용
    - volatile의 성향을 제거하는데도 사용가능 - volatile 처음들어봄
  - reinterpret_cast
    - 상관없는 자료형으로의 형 변환
    - `reinterpret_cast<T>(expr)`
    - 포인터를 대상으로 하는, 그리고 포인터와 관련이 있는(?) 모든 유형의 형 변환을 허용 -- 예제 확인642P
  - Polymorphic 클래스
    - 하나이상의 가상함수를 지니는 클래스
  - dynamic_cast와 static_cast 차이 확인하기 645P



