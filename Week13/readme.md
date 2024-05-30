# Week13
0528
  
#### ppt 10장

passwd - 패스워드변경 명령어  
패스워드는 root가 권한을 가지고 있음  
root가 user에게 권한을 줌 set-user-id  
각각의 유저가 알아서 실행 시키세요~  
실제 사용은 root  

set-user-id 실행권한은 심볼릭 모드로 's'로 표시  
set-uid(실행권한 설정) 을/를 사용할땐 4개의 8진수 사용  
chmod 4755 file1  
  
set-gid비트 설정 // 강제 잠금 설정  
chmod 2755 file1  

프로세스  
프로그램 정상 종료 0의 의미 검색  
ex) return 0  
쉘 프로그램 0 출력 의미 검색  

echo $?  
쉘에서 최근 실행한 명령어의 종료 상태를 담은 변수  

ppt 11장  
fork() 부모 프로세스를 똑같이 복제하여 새로운 자식 프로세스 생성  
자기복제  
새로운 자식 프로세스 생성 -> 자식 프로세스에게는 0을 리턴하고 부모프로세스에게는 자식 프로세스 id를 리턴  

fork1.c 실습  
<img width="346" alt="image" src="https://github.com/Kimra0467/SystemP/assets/87680279/22cc04de-0700-4fb1-97d9-b48d93557f88">  

fork2.c 실습  
부모프로세스와 자식 프로세스 구분  
<img width="346" alt="image" src="https://github.com/Kimra0467/SystemP/assets/87680279/8d349561-b627-4da6-8ec8-43f1434337d6">  


fork3.c 실습  
두개의 자식 프로세스 생성  
<img width="345" alt="image" src="https://github.com/Kimra0467/SystemP/assets/87680279/8686af30-c9f0-4c2b-a379-6d82ab68ca64">  

forkWait.c 실습  
자식 프로세스 중의 하나가 끝날때까지 기다린다  
끝난 자식 프로세스의 종료 코드가 status에 저장 끝난 자식 프로세스의 번호를 리턴  
<img width="366" alt="image" src="https://github.com/Kimra0467/SystemP/assets/87680279/7a0b859c-35df-4c8e-9e09-46400ea74778">  
exit(1)의 의미를 잘 생각해보기  

waitPid.c 실습  
<img width="485" alt="image" src="https://github.com/Kimra0467/SystemP/assets/87680279/3652f90e-063e-41dd-aa76-16284cb8bac9">  

fork()후에 파일 공유  
- 자식은 부모의 fd 테이블을 복사한다
  - 부모와 자식이 같은 파일 디스크립터를 공유
  - 같은 파일 오프셋을 공유
  - 부모와 자식으로 부터 출력이 서로 섞이게 됨
- 자식에게 상속되지 않는 성질
  - fork()의 반환값
  - 프로세스 id
  - 파일 잠금
  - 설정된 알람과 시그널


프로그램 실행  
fork()후  
- 자식 프로세스는 부모 프로세스와 똑같은 코드 실행  
자식 프로세스에게 새 프로그램 실행  
- exec()시스템 호출 사용  
- 프로세스 내의 프로그램을 새 프로그램에 대치  
보통 fork()후에 exec()
- 새로 실행할 프로그램에 대한 정보를 arguments 로 전달한다.
exec()호출 성공하면
- 자식 프로세스는 새로운 프로그램을 실행하게 되고
- 부모는 계속해서 다음 코드를 실행하게 된다
- exec() 호출이 성공하면 리턴할 곳이 없어진다
- 성공한 exec() 호출은 절대 리턴하지 않는다

exec1.c 실습  
<img width="485" alt="image" src="https://github.com/Kimra0467/SystemP/assets/87680279/32eb6115-5056-4990-844f-764ae2b59b70">  

exec2.c 실습  
<img width="485" alt="image" src="https://github.com/Kimra0467/SystemP/assets/87680279/c723200b-28fe-4e4a-966a-4acde09cc75b">

exec3.c 실습  
<img width="485" alt="image" src="https://github.com/Kimra0467/SystemP/assets/87680279/480508d1-440a-4895-b0b8-9c8a4e42f428">

system()  
자식 프로세스를 생성하고 /bin/sh로 하여금 지정된 명령어를 실행시킨다.  
system()함수 구현  
- fork(),exec(),watipid() 시스템 호출을 이용  
반환값  
- 명령어의 종료코드  
- -1 with errno: fork()혹은 watipid() 실패  
- 127 :          exec()실패  

systemTest.c 실습    
<img width="485" alt="image" src="https://github.com/Kimra0467/SystemP/assets/87680279/39294572-0774-49e2-9078-13b5d2357828">  

system()함수 구현  
system.c 실습  

systemCall.c 

여기까지 기말고사 범위  

### 발표  
#### booting  
부팅 과정  
전원켜기 -> post(power on self test) -> bios 단계 -> 부팅장치검색 -> 부트로더실행 -> 실행 할 커널 선택 -> 커널 로드 및 pid 1 번 실행 -> 기타 필수 프로그램 실행
grub 실행  
bios(basic input/output system)  
boot 메뉴 : 부팅 장치의 검색 순서 등 설정  
booting 메시지의 (/var/log/boot.log)에서 booting때 메세지 확인 가능  
런 레벨 : 시스템의 상태를 나타낸다  
0 : halt(시스템 종료) run level을 0으로 변경하면 시스템 종료  
1 : 단일 사용자 모드(single user mode) 시스템 복원모드  
2 : 네트워킹 비활성화된 다중 사용자 모드(multi user mode without NFS)  
3 : 네트워크를 활성화한 다중 사용자 모드 레벨(Full multi User Mode)(거의 모든 자원 사용 가능한 텍스트 유저 모드)  
4 : Not used(사용x) 특정 시스템에서 사용자 정의 레벨로 설정 가능  
5 : 그래픽 환경을 지원하는 다중 사용자 모드 레벨, level 3과 비슷하나 x윈도우가 실행된 그래픽 유저 모드  
6 : reboot(시스템 재부팅) run level을 6으로 변경하면 시스템 재부팅  

run level 관련 명령어  
who -r : 현재 및 이전 런 레벨을 확인하는 명령어  
init run level(0~6) : 런 레벨 스크립트를 실행하는 명령어  
- etc파일에서 rc로 시작하는 디렉토리들을 보면 erc0~6처럼 런 레벨에 맞는 런 레벨 스크립트  
- 디렉토리로 이동해서 리스트를 보면 K로 시작하는 것은 이 런 레벨에서 끄는 것
- S로 시작하는 것은 이 런 레벨에서 실행하는 것

Init 프로세스  
리눅스 시스템의 부팅 및 초기화를 담당하는 핵심 프로세스  
첫번쨰 프로세스 (PID: 1)  
시스템의 런레벨 설정 및 서비스 시작  
/etc/inittab 의 파일을 이용해 설정  

systemd  
유닉스의 system V, BSD init 시스템을 대신하는 init 시스템  
system의 d는 유닉스에서의 daemon을 의미  
모든 배포판들에 대해 기본 리눅스 구성과 서비스 동작을 통일하는게 주요 목적  
대부분의 최신 리눅스 배포판에서 systemd를 기본 init시스템으로 채택 중  
unit 개념을 사용  
- 여러 서비스, 시스템 구성 요소를 단위별로 정의, 관리
- 병렬 부팅을 지원 -> 시스템 부팅 시간 단축

런레벨/타겟 설정  
시스템의 운영 상태를 숫자나 문자로 표현한 것  
설정된 런레벨(또는 타겟)따라 시스템의 서비스와 데몬을 시작  

daemon(데몬)  
유닉스 계열 운영체제에서 백그라운드에서 실행되는 프로그램  
시스템의 부팅 시 자동으로 시작되어 종료될 때까지 계속 실행됨  
사용자와 직접 상호작용하지 않고 특정 작업이나 서비스를 지속적으로 수행  
데몬 프로그램의 이름은 d로 끝나는 특징을 가짐  

로그인 프롬프트 표시  
모든 서비스가 시작  
로그인 프롬프트 표시  
사용자가 터미널(또는 GUI)환경에서 로그인 가능  

#### format  
기존의 파일 시스템을 지우고 새롭게 파일 시스템을 구축하는 것  
즉, 기존 파일 시스템에 기록된 폴더의 구조, 파일명, 파일의 위치 등이 지워지게 되는 것  

일반 포맷  
- 파일 시스템을 재구축하면서 메타 정보 뿐 아니라 데이터 모두 지워진다  
- 모든 섹터의 값들을 0으로 재 기록하는 과정을 거치게 되어 완전히 지워지게 됨  
- 시간이 오래 걸리고 효율적인 운용에는 도움이 안됨  
- 보안이 높고 복구가 불가능  

빠른 포맷  
- 파일시스템을 재구축하면서 메타정보만 지우고 데이터는 그대로 보존
- 메타정보만 지우고도 새로운 데이터를 저장하면 덮어쓰기가 되므로 빠른 포맷은 기기의 효율적 운용에 매우 도움이 되는 포맷 형태
- 보안에 취약하고 쉽게 복구 가능

low-level format
- 하드 드라이브의 실린더와 트랙을 공백으로 표시하는 물리적 포맷 프로세스
- 디스크에 섹터와 트랙을 다시 생성하고 디스크를 원래 상태로 물리적으로 정리
- 하드 드라이브의 트랙은 섹터 마커가 있는 섹터로 구분
- 하드 드라이브를 공장 설정으로 재설정하는 널리 사용
- 공장초기화, 영구삭제를 말한다.
- 데이터 복구 가능성 x

high-level format  
- 고급 포맷이라고 함
- 하드 드라이브를 빈 파일 시스템으로 설정하고 pc의 경우 부트 섹터를 설치하는 프로세스
- 종종 빠른 작업이며 빠른 포맷이라고 함

