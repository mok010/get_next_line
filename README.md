# get_next_line

**get_next_line 용도**

파일 디스크립터(fd)를 통해 텍스트에서 개행 문자(\n)가 나올 떄까지 파일에서 라인(한 줄씩)을 읽어 반환하는 함수.




# 구현 세부 조건

|                      카테고리                        |                                             세부사항                                          |
| :---------------------------------------------------------: | :-----------------------------------------------------------------------------------: |
|   프로토타입     |       int get_next_line(int fd, char **line);                |
|  제출할 파일   |        get_next_line.c, get_next_line_utils.c, get_next_line.h              |
|  매개변수   |       1. 프로그림이 읽을 파일 디스크립터(file descriptor for readinf) <br> 2. 읽어왔던 값(The value od what has been read)          |
|  리턴 값   |                1 : 한 라인이 읽혔을 떄(A line has been read) <br> 0 : EOF에 도달했을 때(EOF has been reached) <br> -1 : 에러가 발생했을 떄(An error happened)                 |
|  외부함수   |                   read, malloc, free               |
|     설명         |              파일 디스크럽터로부터 읽어 온 하나의 라인(newline 없이)을 반환하는 함수 작성 <br> Write a function which returns a line read from a file descriptor, without the newline                |


## **_bonus가 붙은 파일과 붙지않은 파일의 차이**

-  붙은 파일은 복수의 파일을 가져와도 중간에 어디까지 읽었는지를 저장해, 여러 파일을 사용 할 수 있도록 한 모델이고, 붙지 않은 파일은 단일 파일만을 사용할 수 있도록 한 모델이다.
-------------------

## ** 파일 디스크립터(fd)**

- **0** : standard input : 표준 입력

  
- **1** : standard output : 표준 출력


- **2** : standard error : 표준 에러

  
-------------------


## **EOF(End of File)**

 파일에서 데이터를 읽을 때 파일의 끝을 나타내는 상태 또는 신호. 파일 읽기 함수가 더 이상 읽을 데이터가 없음을 알리는 방법.

  
- **표현** : C 언어에서 EOF는 일반적으로 -1로 정의되며, <stdio.h> 헤더 파일에 정의되어 있다.
  
-------------------


## **read 함수**

- open 함수를 이용해 파일의 내용을 읽는 함수

&ensp;: size_t read(int fd, void *duff, size_t bytes)

- **헤더** : unistd.h


- **fd** : 파일 디스크립터


- **buff** : 읽은 파일의 내용을 저장할 배열

&ensp;: bytes만큼 fd를 읽어 buff에 저장하는 함수

-------------------


## **size_t 에 대해**

- size_t는 표준 라이브러리에 정의된 데이터 타입


- **정의** : size_t는 stddef.h 헤더 파일에 정의. 보통 stdlib.h 또는 stdio.h를 포함하면 간접적으로 포함.

&ensp;: 함수 내부에서 초기화를 하면 프로그램이 시작할 때 초기화되며, 함수가 호출될 때는 변수를 초기화하지 않는다. 


- **용도** : size_t는 메모리 관련 작업에서 크기(길이)를 나타내기 위해 사용됨. 이는 배열의 크기, 메모리 블록의 크기, 문자열 길이 등을 나타낼 때 사용.


- **자료** : size_t는 부호 없는 정수형(unsigned integer)입니다. 이는 크기 또는 길이를 나타내기 위해 음수 값이 필요하지 않기 때문입니다. 구체적인 자료형은 시스템에 따라 다를 수 있지만, 일반적으로 unsigned int 또는 unsigned long으로 정의됩니다.


- **크기** : size_t의 크기는 플랫폼에 따라 다릅니다. 32비트 시스템에서는 32비트 크기를 가지며, 64비트 시스템에서는 64비트 크기를 가질 수 있습니다.


-------------------

## **static 변수 (정적 변수)**

- 메모리의 데이터 영역에 저장되어 프로그램이 종료될 때까지 남아있는 변수


- **선언 방식** : static char *record

&ensp;: 함수 내부에서 초기화를 하면 프로그램이 시작할 때 초기화되며, 함수가 호출될 때는 변수를 초기화하지 않는다. 


- **buff** : 읽은 파일의 내용을 저장할 배열

&ensp;: bytes만큼 fd를 읽어 buff에 저장하는 함수


-------------------

