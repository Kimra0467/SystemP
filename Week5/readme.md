# Week5
0402  

### make  
Makefile 생성  
<target> : <의존성 List>  
[TAB]    : <명령 List>  

Makefile
![image](https://github.com/Kimra0467/SystemP/assets/87680279/885d4438-d706-49ba-b210-73d616b20e4b)  
  
Makefile 간략히  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/d5478307-4b3f-48d5-b3b0-8ba6cc36718c)

make file은 디렉토리 하나 당 하나 디렉토리가 관리  

### 시스템 호출
시스템 호출은 커널에 서비스 요청을 위한 프로그래밍 인터페이스  
응용 프로그램은 시스템 호출을 통해서 커널에 서비스를 요청한다.  

파일 열기 : open()  
파일을 사용하기 위해서 먼저 open() 시스템 호출을 이용하여 파일을 열어야한다.  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/2c9669a1-0f51-49b8-94a9-a6c2766219e8)  
파일 디스크립터는 열린 파일을 나타내는 번호이다.  

oflag  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/c629cae8-58a7-4c18-a748-0ea18a1b655e)  

fopen.c
![image](https://github.com/Kimra0467/SystemP/assets/87680279/962f8182-a8bb-4732-bb7e-2ce749e87756)

파일 닫기 close()  

데이터 읽기 read()  
ssize의 s는 signd  
  
fsize.c  
file descript?  
파일 디스크립터 0 = 표준입력(키보드)  
               1 = 표준출력(모니터)  
               2 = 표준에러(에러파일)  


번외)변수 타입, typedef 사용법
발표주제 (void *) 가 무엇인지, 
