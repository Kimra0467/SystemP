# Week11
0514  
  
Linux Command Line and Shell Scripting Bible, 2nd Edition.pdf 실습  
220p  
test0 : argv 이용 $0 $1 $2 $3 후 텍스트 입력받기  
test1 : echo 사용해보기  
test2 : user id, UID 확인
test3 : 변수 적용  
test4 : $value 이용 php 방식
test5 :  
run  
vi $1  
chmod +x $1  
./$1   
이용하여 test5 바로 작성 및 실행  
  
*backtick(option + ~)  

? : one, * : all  

test6 : expr $var2 / var1 계산  
오류로 var3=$(expr $var2 / $var1) 으로 수정  
test7, test8 : $ 계산  
test13 : exit status test  
answer is 40  
test14 : test13 차이 echo $? : 40  
test14b : test14 value값 변경  
test21 : date 확인 후 echo  
test22 : 명령어 못찾으면 we are outside of the if statement 출력  
test23 : testuser 확인 /etc/passwd 호출  
test24 : testuser 가 badtest 면 the user name badtest does not exist on this system 출력  
Test25 : -gt와 -eq 확인  
test27 : user 와 testuser 확인 일치하면 welcome $USER 출력  
test28 : user 와 testuser 확인 불일치 하면 this is not $testuser 출력  
