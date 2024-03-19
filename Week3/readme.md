# Week3  0319
mkdir, cd 명령어 사용
sudo apt install tree / tree 설치
* * *
cs1.txt 만들기
* * *
### rm 설명
* : all  
? : one

rm -f = 강제로 삭제  
rm -r = 삭제 여부 확인
rm -ri = 디렉토리 안에 있는 내용을 하나하나 확인 
rm -rf = 경고없이 모든 파일 삭제  
* * *
### cat 명령어 
cat > 파일 = 바로 작성 가능  
more = 하나 이상의 파일 이름을 받을 수 잇으며 페이지 단위로 출력  
head = 파일의 앞부분(10줄)을 출력  
tail = 파일의 뒷부분(10줄)줄 출력  
wc(word count) = 파일에 저장된 줄, 단어 문자의 개수를 세서 출력  
* * *
### cp 파일 디렉터리 복사  
cp cs1.txt/tmp = 파일 1의 복사본을 디렉터리 내에 만듦

* * *
### mv 
파일 이름 변경, 파일을 디렉터리 내로 이동    
실습 내용  
cs1.txt 를 cssw.txt 로 변경  
mv cs1.txt cssw.txt  
cs2.txt를 choi/cs101 로 이동  
mv cs2.txt ../../choi/cs101  

* * *
### 파일 타입(file attribute)  

-rw-r--r-- 파일 타입  
일반 파일(-), 디렉터리(d), 링크(l), 파이프(p), 소켓(s), 디바이스(b 혹은 c)  
사용 권환 = 소유자, 그룹, 기타 사용자의 파일에 대한 읽기/쓰기/실행 권환  
소유자 및 그룹 = 파일의 소유자 및 소유자가 속한 그룹  
나, 그룹, 그룹 외(athores)  
ex) -rw(사용자), r--(group), r--(athores)  
r = read, w = write, x= execulciv(실행)  
크기 = 파일을 구성하는 블록 수  
수정 시간 = 파일을 최후로 생성 혹은 수정한 시간(touch)  
* * *
### chmod(change mode)  
ex)사용권환 rw- rw- r--  
2진수 110 110 100  
8진수 6 6 4  
chmod 664 cs1.txt = cs1.txt rw- rw- r--  

u = user, g = group, o = other, a = all  
연산자 +, -, =  
권한 : r, w, x  
예시 chmod g+w cs1.txt  
그룹에 w 권환 부여  
* * *
### 출력 재지정  
cat > list1.txt  
Hi !  
This is the first list  
^D  
명령어 >> 파일  
cat >> list1.txt  
Bye !THis is the end of the first list  
^D <- EOF  

cat list1.txt  
HI !  
This is the first list.  
Bye !  
This is the end of the first list.  

명령어의 표준입력을 키보드 대신에 파일에서 받는다.  
명령어 < 파일  
wc < list.txt  
4 17 71 list1.txt  
* * * 
### 전면 처리 vs 후면처리  
전면 처리  
명령어를 입력하면 명령어가 전면에서 실행되며 명령어 실행이 끝날 때까지 쉘이 기다려준다  
후면처리  
명령어들은 후면에서 처리하고 전면에서는 다른 작업을 할 수 있으면 동시에 여러작업을 수행할 수 있다.  
$ 명령어 &  

* * *
#### 동기, 비동기, 블록킹, 논블록킹
동기 : 함수 A가 함수 B를 호출한 뒤, 함수 B의 리턴값을 계속 확인하면서 신경쓰는것  
비동기 : 함수 A가 함수 B를 호출할 떄 콜백 함수를 함께 전달해서 함수B의 작업이 완료되면 함께 보낸 콜백 함수를 실행  
함수 A는 함수 B를 호출한 후로 함수 B의 작업 완료 여부에는 신경쓰지 않는다.  
  
블로킹 : A함수가 B함수를 호출하면 제어권을 A가 호출한 B함수에 넘겨준다.  
논블로킹 : A함수가 B함수를 호출해도 제어권을 그댈 ㅗ자신이 가지고 있는다.  

* * *
### sleep
$ (sleep 100; echo done) &  
[1] 8320
$ find . -name test.c -print &
[2] 8325  
$ jobs  
[1] + Running (sleep 100l echo done)  
[2] - Running find . -name test.c -print  


$ fg %작업번호  
$ fg %1  
(sleep 100; echo done)  

* * *
### 프로세스 (process)  
실행중인 프로그램을 **프로세스**  
각 프로세스는 유일한 프로세스 번호 **PID**를 갖는다  
ps 를 사용하여 나의 프로세스들을 확인 가능  
