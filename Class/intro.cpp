// 1. 객체(Object)
// 2. 클래스(Class)
//			상태(state)			행동(Behaviour)
// C++		멤버변수			멤버함수
// C#		필드(Field)			메써드(Method)
// Java		필드(Field)			메써드(Method)	
// 
// 
// 3. 캡슐화(Capsulisation)
//		사용 편리 - 알 필요가 없음
//		보안	  -	내부 정보를 숨기는
//		정보 은닉 (Information Hiding)
// 
// 4. 상속(Inheritance) , 파생(Derivation)
//		정보를 그룹화해서 재활용 - 계층구조(Hierachy)
// 5. 다형성(Polymorphism)
//		상속과 포인터
//	---------------------------------------------------

// 생성자(Constructor) / 소멸자(Destructor)

// Static Member는 인스턴스에 속하지 않는다( Dog.Member = x) Class에 속한다.

// 추상클래스(Abstraction Class)
// 공통적인 정의
		// 인터페이스(Interface)
		// 약속 - 작업X	
		// 선언 - 정의X

// 오버라이딩(override)
	// 재정의. 동일한 이름의 함수가 있으면 무시하고 내껄 
	// 기반, 파생

// 오버로딩(overload)
	// 중복 적재. 이름이 같고 매개변수가 다른 함수


//상수 멤버 함수(const member function)
// return - type function - name(parameters) const;

// 생성자 (Constructor)
// 클래스가 인스턴스화 될때 /*자동적으로 호출*/ 되는 특별한 멤버 함수
//	
//	클래스와 동일한 이름의 함수
//	반환 타입이 없음
//	매개 변수는 가능
// 
// 생성자를 작성 안할시 암시적 생성자 자동생성
// 
// myClass() {} // 암시적 생성자와 동일
// myClass() = default; 암시적 생성자와 동일
// myClass(int a, int b)
// {
//	 x = a;
//	 y = b;
// }

// 소멸자 (destructor)
// 인스턴스가 소멸될 때 /*자동적으로 호출*/ 되는 특별한 멤버함수
// 
//	클래스와 동일한 이름 앞에 ~(tilde) 붙인 함수
//	매개변수 없음
//	반환 타입이 없음


// 구조체는 모든 멤버가 public인 클래스와 같다.
// Point3D pt2{ 1,1,1 };	// 모든 멤버가 public이기에 유니폼 초기화 가능




