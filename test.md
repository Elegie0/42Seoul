# 소인수분해 함수
## testcase
### 에러 케이스
- 인수가 없는 경우

		$ factorization
		Error : No arguments.
		$

- 인수가 2개 이상인 경우

		$ factorization 123 456
		Error : Too mant arguments.
		$

- 입력값이 자료형의 최댓값을 초과하는 경우

		$ factorization 4294967296
		Error : Too large number. (Max = 4294967295)
		$ factorization 4294967303
		Error : Too large number. (Max = 4294967295)
		$

	- 괄호 안에 인자로 받을 수 있는 최댓값을 표현 함.

	괄호 안의 최댓값은 코드상에 고정된 값이 아니고, 자료형에 따라 계산된 값이다. 주어진 자료형은 unsigned int형이지만, 확장성과 시스템의 차이를 고려하여 unsigned int를 typedef를 통해 다른 자료형으로 표현했고, 함수 내부에서는 새로운 자료형으로 계산한다.  
	다른 자료형으로 오버플로우 예외처리를 하는 경우, 자료형의 크기가 다르면 오버플로우를 일으키는 값이 다를 수 있으므로, sizeof(자료형)을 통해 주어진 자료형의 최댓값을 구하게 했다. 나중에 자료형을 바꿔도 간단히 typedef만 바꾸면 문제없이 작동한다.
	
	- 컴파일러가 예민하지 않다면 unsigned 형이라도 0보다 큰지 작은지 판단할 수 있지만, -wall -wextra -werror에서는 그런 조건문을 에러처리하는 문제가 발생했다. 부득이하게 자료형에 부호가 있는지 없는지에 따라 전처리기를 바꾸어서 함수가 작동하도록 했다.

- 인수가 2보다 작은 경우

		$ factorization 0
		Error : Wrong number. Argument must be larger than 2.
		$ factorization 1
		Error : Wrong number. Argument must be larger than 2.
		$

- 인수가 숫자가 아닌 경우(인수에 문자열이 섞여 있는 경우 등)

		$ factorization 1234qwer
		Error : No available arguments.
		$

### 정상작동 케이스
- 인수가 최솟값(2)인 경우

		$ factorization 2
		2
		$

- 인수가 최댓값(4294967295)인 경우

		$ factorization 4294967295
		3 5 17 257 65537
		$
