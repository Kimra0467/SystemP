mkdir, cd 명령어 사용
sudo apt install tree / tree 설치
* * *
cs1.txt 만들기
* * *
rm 설명
* : all  
? : one

rm -f = 강제로 삭제  
rm -r = 삭제 여부 확인
rm -ri = 디렉토리 안에 있는 내용을 하나하나 확인 
rm -rf = 경고없이 모든 파일 삭제  
* * *
cat 명령어 
cat > 파일 = 바로 작성 가능  
more = 하나 이상의 파일 이름을 받을 수 잇으며 페이지 단위로 출력  
head = 파일의 앞부분(10줄)을 출력  
tail = 파일의 뒷부분(10줄)줄 출력  
wc(word count) = 파일에 저장된 줄, 단어 문자의 개수를 세서 출력  
* * *
cp 파일 디렉터리 복사  
cp cs1.txt/tmp = 파일 1의 복사본을 디렉터리 내에 만듦

* * *
mv 
파일 이름 변경, 파일을 디렉터리 내로 이동    
실습 내용  
cs1.txt 를 cssw.txt 로 변경  
mv cs1.txt cssw.txt  
cs2.txt를 choi/cs101 로 이동  
mv cs2.txt ../../choi/cs101  


