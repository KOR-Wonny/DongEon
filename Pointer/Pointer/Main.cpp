#include <iostream>
#include <string>

using namespace std;

class Object
{
private:
	string Key;
public:
	void Initialize()
	{
		Key = "Player";
	}

	void Output()
	{
		cout << Key << endl;
	}
public:
	Object() {};
	~Object() {};
};

int main(void)
{
	int Num = 10;
	int* pNumber = &Num;

	cout << *pNumber << endl;

	// 배열의 크기는 2의 n승으로 설정한다.
	// ex) 배열의 크기를 100개로 하고싶으면 2의 7승인 128.
	// 배열 100을 만드는 방법
	// 100이 한번에 들어갈 수 있는 128을 생성 -> 28이 남음 -> 28이 한번에 들어갈 32 생성 -> 4남음 -> 4생성. 
	
	int iArray[128] = { 0 };

	for (int i = 0; i < 128; ++i)	// 전위연산 후위연산?
	{
		iArray[i] = i + 1;
	}

	int* iter = iArray;	// 배열은 바로 주소보내기 가능
	
	for (int i = 0; i < 128; ++i)	// 전희연산 후희연산?
	{
		cout << *(iter+i) << endl;
	}

	Object* pObj = new Object;

	pObj->Initialize();
	pObj->Output();

	return 0;
}

#pragma region 비트값
// 비트값
/*
0000 0001 = 1
0000 0010 = 2
0000 0011 = 3
0000 0100 = 4
0000 0101 = 5
0001 0110 = 6
0010 0111 = 7
0100 1000 = 8
0000 1001 = 9
0000 1010 = 10
0000 1001 = 11
0000 1100 = 12
0000 1101 = 13
0000 1110 = 14
0000 1111 = 15
0001 0000 = 16
0001 0001 = 17
0001 0010 = 18
*/

// 더하기
/*
   0000 1010 = 10
 + 0000 1000 =  8
ㅡㅡㅡㅡㅡㅡㅡㅡㅡ
   0001 0010 = 18

   0000 1010 = 10
 - 0000 1000 =  8
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
   0000 0010 = 2


10 - 8 == 10 + (-8)
   0000 1000
 + 1111 1111
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
   1111 0111 + 1
   1111 1000 = -8

 맨 앞의 값이 0이면(0111 1111)양수, 1이면(1000 0000) 음수 값.
 */

 // [빼기 2]
 /*
	0000 0100 = 4
  - 0000 0010 = 2
 ㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	???? ???? = 2

 4 - 2 == 4 + (-2)

	0000 0010 = 2
  + 1111 1111 <= 1의 보수
 ㅡㅡㅡㅡㅡㅡㅡㅡ
	1111 1101 =
  + 0000 0001 <= 1의 보수
 ㅡㅡㅡㅡㅡㅡㅡㅡ
	1111 1110  = (-2)

	0000 0100 = 4
  + 1111 1110 = (-2)
 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	0000 0010
 */

 // [빼기 3]
/*
	   0000 0001 = 1
	 - 0000 0011 = 3
	ㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	   0000 0000 = 0

	 1 - 3 == 1 + (-3)

	   0000 0011	(3)
	 + 1111 1111	(1의 보수)
	ㅡㅡㅡㅡㅡㅡㅡ
	   1111 1100
	 + 0000 0001	(1의 보수)
	ㅡㅡㅡㅡㅡㅡㅡ
	   1111 1101 = (-3)	(1의 보수가 두번 == 2의 보수)

	   0000 0001 = 1
	 + 1111 1101 = (-3)
	ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	   1111 1110 = (-2)
 */
#pragma endregion

#pragma region 객체지향프로그래밍(OOP)의 5가지 특성
/*
1. 추상화(Abstraction)
 - 공통의 속성이나 기능을 묶어 이름을 붙이는 것.
 - 다른 객체들과는 구분되는 핵심적인 특징들에만 집중하여 복잡도를 관리할 수 있도록 함
 = 간략화, 개략화

2. 캡슐화(Encapsulation)
 - 외부에는 불필요하거나 내부적으로만 사용되는 부분을 감추기위해 특정 속성이나 메소드를 
 - 데이터(변수)와 데이터를 다루는 방법(함수)들을 하나로 묶은 것.
 - 실제의 구현 부분을 외부로 드러나지 않도록 하는 것.
 - 데이터 외부에서 직접 접근하지 않고 공용 메소드(함수)를 통해서만 접근.

3. 정보은닉(information hiding)
 - 객체에 대한 구체적인 정보를 노출시키지 않는 것.
 - 권한이 없는 외부 객체의 접근이 불가능함.
 - 캡슐 내의 요소들에 대한 세부 구현사항들을 외부로부터 숨긴다.

4. 상속성(inheritance)
 - 상위 클래스(부모 클래스)의 모든 개념을 하위 클래스(자식 클래스)가 물려받는 것.

5. 다형성(polymorphism)

*/
#pragma endregion
