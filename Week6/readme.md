# Week6
04.09  
시스템 호출
  
void * = oid형은 그 형태가 int형이든 char 형이든 구조체든 문자열을 가리키고 있는 포인터이든 상관없이 단순히 주소값만이요. 그러니 void포인터는 자료형이 무엇이든 간에 주소값만 바라봅니다.  

### 파일 위치 포인터 이동 lseek() 
lseek() 시스템 호출  
임의의 위치로 파일 위치 포인터를 이동시킬 수 있다.

파일 위치 이동  
lseek(fd, 0L, SEEK_SET); 파일 시작으로 이동(rewind)
lseek(fd, 100L, SEEK_SET); 파일 시작에서 100바이트 위치로
lseek(fd, 0L, SEEK_END); 파일 끝으로 이동(append)

레코드 단위로 이동
lseek(fd, n * sizeof(record), SEEK_SET); n+1번째 레코드 시작위치로
lseek(fd, sizeof(record), SEEK_CUR); 다음 레코드 시작위치로
lseek(fd, -sizeof(record)m SEEK_CUR); 전 레코드 시작위치로

파일 끝 이후로 이동
lseek(fd, sizeof(record), SEEK_END); 파일 끝에서 한 레코드 다음 위치로
  
레코드 저장 예
![image](https://github.com/Kimra0467/SystemP/assets/87680279/e333118e-a0c8-47fd-b246-a06622b3a79d)

* * *
### 시험 예상 문제
student.h  
define START_ID 숫자 바꿔보기  
헤더파일 암기하기  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/4143f4cd-bd3f-4fe8-b9da-0291db804308)  
  
dbcreate.c  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/22c99609-a34f-4bfb-a32e-9af37a473fb8)  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/a5785d74-f1a5-4476-a974-164d593404fd)  

  
dbquery.c  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/a86131f0-c8fc-4a23-b849-c1012a0edb96)  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/7262fb9e-8296-4f1d-a2e4-470753cbe858)  

dbupdate.c  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/cf8100eb-baf5-4cbf-a642-f7ac463b6bf1)  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/a6971215-6aae-453a-99b8-301951a928df)  

### 발표
#### argc/argv  
명령행 인자 : 프로그램 실행할 때 명령 프롬포트나 터미널을 통해 프로그램에 전달되는 인자값  
이 인자들은 프로그램이 실행될 때 프로그램 이름 뒤에 공백으로 구부한여 입력

argument(전달인자)  
- 함수나 메서드를 호출할 때 실제로 전달되는 값

parameter(매개변수)  
-함수나 메서드 정의에 사용되는 변수  
- 이 변수들은 함수가 실행될 때 필요한 입력 값의 '형식'을 정의

e.g.  
int add(int a, int b) -> a와 b는 parameter  
add(3, 5) -> 3, 5는 argument  
  
argc (Argument Count)  
프로그램에 전달된 인자의 개수를 나타냄  
프로그램 이름 자체도 하나의 인자로 취급/ 항상 1 이상  

argv (Argument Vector)  
문자열 포인터의 배열로 실제로 전달된 인자들의 값을 담음  
argv[0]은 프로그램의 실행 경로를 나타냄, argv[1]부터 시작하는 나머지 요소들은 사용자가 입력한 인자들을 순서대로 담음  
코드  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/bbeecf06-6600-429d-b8b0-47918c915b5b)  
  
결과  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/ade4bc12-0ac2-4f1f-bd34-5f671370dd12)

#### size_t/ssize_t

size_t
- int로 표현하기에 사이즈가 너무 커지면 오버플로가 나타나기때문에 int 대신 size_t를 사용하여 오류를 막기 위해 사용
- 컴파일러에 따라 unsigned int(32 bit), unsigned long long(64bit)의 크기로 정의  
- 양의 정수 값만 표현 가능  
- 메모리 내의 객체 크기를 나타내는데 주로 사용  
- sizeof 연산자, malloc, strlen 함수의 파라미터 혹은 리턴 타입으로 사용  

ssize_t  
- 양의 정수, 음의 정수 모두 표현 가능
- 시스템 호출(system call)과 같은 I/O 작업에서 주로 사용
- read(), write() 함수의 리턴 타입으로 사용

*stddef.h에 정의되어있다.  
[size_t/ssize_t 참고사이트](https://pubs.opengroup.org/onlinepubs/9699919799/)  
ㅇㄹㅇㄹ
