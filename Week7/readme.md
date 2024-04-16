# Week7
0416  
  
리눅스 파일 시스템 구조  
### 파일 시스템 구조  
#### 부트 블록(Boot block)  
- 파일 시스템 시작붕에 위치하고 보통 첫 번째 섹터를 차지
- 부트 스트랩 코드가 저장되는 블록

#### 슈퍼 블록(Super block)  
- 전체 파일 시스템에 대한 정보를 저장
  - 총 블록 수, 사용 가능한 i-노드 개수, 사용 가능한 블록 비트 맵, 블록의 크기, 사용 중인 블록 수, 사용 가능한 블록 수 등

#### i-리스트(i-list)  
- 각 파일을 나타내는 모든 i-노드들의 리스트
- 한 블록은 약
- 40개 정도의 i-노드를 포함

#### 데이터 블록(data block)  
- 파일의 내용(데이터)을 저장하기 위한 블록들

#### i - node
- 한 파일은 하나의 i - 노드를 갖는다.
- 파일에 대한 모든 정보를 가지고 있음
  - 파일 타입 : 일반 파일, 디렉터리, 블록 장치, 문자 장치 등
  - 파일 크기
  - 사용 권환
  - 파일 소유자 및 그룹
  - 접근 및 갱신 시간
  - 데이터 블록에 대한 포인터 등


#### 파일 열기 및 파일 입출력 구현  
파일 열기 open()  
- 시스템은 커널 내에 파일을 사용할 준비를 한다  
  
파일 입출력 구현을 위한 커널 내 자료구조  
- 파일 디스크립터 배열(fd array)  
- 열린 파일 테이블(open file table)  
- 동적 i - 노드 테이블(active i - node table)  

파일을 위한 커널 자료구조  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/da9d8f11-1710-4b49-8986-b823795abd2e)  

#### 파일 상태(file status)  
파일 상태  
- 파일에 대한 모든 정보
- 블록 수, 파일 타입, 사용 권한, 링크 수, 파일 소유자의 사용자 id
- 그룹 id, 파일 크기, 최종 수정 시간 등

예  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/aa49225d-aa89-4648-81ce-1c54f9a1bf9b)  

### 상태 정보(stat)  
- 파일 하나당 하나의 i- 노드가 있으며 i - 노드 내에 파일에 대한 모든 상태 정보가 저장되어있다.

stat 구조체  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/3fe5003b-9c17-43c8-900c-0bda029146d2)  

파일 타입 검사 함수  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/6f0ef3bb-0823-4985-91f6-d71947680b91)  
  
chmod(), fchmod()  
파일의 사용 권환(access permission)을 변경  
  
chown()  
파일의 user ID와 group id를 변경  

utime()  
파일의 최종 접근 시간과 최종 변경 시간을 조정  

### Hard/Sympolic Link  

i - node ? 유닉스 개통의 파일 시스템에서 사용하는 자료구조  
- 파일 생성 시 i- node number가 부여됨 리눅스 커널과ㅡ 파일 시스템은 inode Number로 파일 관리  
- ls -il : i-node number 값을 확인  
  
hard link  
원본 파일과 동일한 inode(포인터)를 생성 (동일한 파일을 하나 새로 만듦)  
- 원본 파일 삭제, 이동해도 hard Link한 파일은 존재  
- 원본 파일과 동일한 i-node를 가짐  
- 파일 수정 시 원본 파일과 hard Link 파일은 같은 데이터를 가짐  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/515e991b-733a-494f-99b3-02f520f33ba5)  

cp =/= hard link  
cp = i-node가 원본 파일과 다름  

symbolic Link  
원본 파일을 참조하는 i-node를 참조하는 파일을 생성
- 파일과 디렉토리를 가르키는 텍스트 포인터 참조 가능
- 원본 파일과 다른 inode number 와 권한을 가짐
- 원본 파일 삭제 시 오류 발생
- 파일 속성에 "L"로 표현
  ![image](https://github.com/Kimra0467/SystemP/assets/87680279/58e623ec-23aa-4da4-a333-de1a4c88fb5b)  

[절대경로 상대경로](https://mommoo.tistory.com/82)  

### System Call/ Library
system call  
응용 프로그램 실행 시 커널의 함수를 이용하기 위해 user mod -> kernel mod로 전환 kernel에 접근할 수 있도록 하는 인터페이스  

동작 과정  
- 사용자 프로세스가 시스템 콜 요청  
- 유저모드에서 커널 모들 변환 후 커널 공간으로 진입 -> 프로그램 실행 일시 중단, 운영체제에 의해 제어  
- 커널 공간에서 호출된 시스템 콜 처리  
- 처리 후, 해당 결과를 커널 공간에서 사용자 공간으로 반환 후 응용 프로그램을 이어서 실행

strace 명령어
![image](https://github.com/Kimra0467/SystemP/assets/87680279/0848615a-b4ff-46c6-b0d5-a3d647f4a175)  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/94b72eb6-f6ff-4705-a30b-f15f6048132c)  


Library  
프로그래밍 시 재사용 가능한 코드들을 정리한 파일  

표준 라이브러리(standard Library)  
<stdio.h>, <stlib.h>, <string.h>  

외부 라이브러리(External Library)  
GTX, SQLite 

- #include 지시문으로 헤더 파일을 소스코드에 포함
- 컴파일러에게 해당 헤더 파일이 저장된 위치를 전달
- 헤더 파일에서 사용되는 라이브러리 함수를 호출하여 컴파일
- 처리 후 링킹  


