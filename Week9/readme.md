# week09
24.04.30  

### sysp07 ppt 참고
fchmod.c  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/0a72703c-4afc-4a43-ac9a-371279b083b5)  

디렉토리란?
- 파일을 효율적 관리하기 위한 개념

#### Istat() 시스템 호출  
- 파일 타입과 사용권한 정보는 st -> st_mode 필드에 함께 저장

#### st_mode 필드  
4비트 : 파일타입  
3비트 : 특수용도  
9비트 : 사용권한  
  - 3비트 : 파일 소유자의 사용권한 owner
  - 3비트 : 그룹의 사용권한 group
  - 3비트 : 기타 사용자의 사용권한 athoer
![image](https://github.com/Kimra0467/SystemP/assets/87680279/f4d12852-d541-4828-9aad-f56e8461b88f)
  
#### 디렉토리 만들기  
mkdir() 시스템 호출  
- path가 나타내는 새로운 디렉터리를 생성  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/539c572d-1339-46e8-a9d6-eb3d4b1f83c3)  

#### 디렉토리 삭제  
rmdir() 시스템 호출  
-path가 나타내는 디렉터리가 비어 있으면 삭제  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/98561280-334d-49b4-84e1-e279a6976a73)  

#### 디렉토리 구현  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/2d17d6ba-bb46-416d-836c-f5f36cf45b57)  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/53433f2d-6e65-4732-a527-ae71ee3e040f)  

#### 링크
- 기존 파일에 대한 또 다른 이름
- 하드 링크와 심볼릭(소프트)링크
![image](https://github.com/Kimra0467/SystemP/assets/87680279/4c1b86be-e4ca-4ac0-85bf-aec563272672)
  
link.c  
밑 줄 친 부분이 있어야함  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/a3a576a4-b432-4ee7-8cb2-49e0cc3073d8)  

unlink.c  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/39d6da97-9afa-45a3-b798-8418f05e575a)  

#### 7장 핵심 개념
- 표준 유닉스 파일 시스템
  - 부트블록, 슈퍼블록, i-list, 데이터블록 부분으로 구성
- 파일 i/o 구현을 위해서 커널 내에 파일 디스크립터 배열, 파일 테이블, 동적 i-node 테이블 등의 자료구조를 사용

## 7장 실습

### ftype.c  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/042b5930-b192-4e73-a8e5-bd566e1b3785)  

ftype.c 실습  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/a129f80f-dbb1-4aaa-b26a-6a94e2e5a912)  


### fchmod.c  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/8abd6ba3-70fb-4a28-882a-519abe82735f)  
  
변경 전 파일  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/4f5abeaf-9f29-48e3-9fb1-5212d09a261b)  
  
변경 후 파일  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/3f2761d5-c9d8-40bd-b89b-d7da3645a0d7)  



### cptime.c  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/d02d472a-66e5-42ad-9eed-751f6d642466)  
  
실행 방법  
./cptime [원본 파일명] [대상 파일명]  

실행 전  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/6672c4fb-dffc-4075-8ee3-227575aea0e6)  

실행 후  
![image](https://github.com/Kimra0467/SystemP/assets/87680279/3e4063d7-82ea-444c-9f4a-e3e23d4aa962)  

### list1.c


