# Final Exam

## 작업 제어

### 1. process 기본

* 리눅스에서는 모든 작업을 process로 불리운다.
* 각 process는 자식 process를 생성할 수 있다.
* 모든 process는 자신의 **_PID_**(process ID)와 부모의 **_PID_**(parent process ID, **_PPID_**)를 가진다.
* 일부 process는 강제 종료 하기 까지 계속 살아남는다. 대표적으로 shell process가 있다.
* shell 에서 외부명령(실행파일)을 실행하면,
    1. 메모리에 명령 적재.
    2. 명령을 실행한 shell process의 자식 process 생성.

    example)
    ~~~bash
    $ ps -f
    UID     PID     PPID    C   STIME   TTY     TIME        CMD
    user    4642    4639    0   11:37   pts/1   00:00:00    -bash
    user    4841    4642    0   11:55   pts/1   00:00:00    ps -f
    ~~~

### 2. process의 분류
* process는 **_제어 터미널 유무_** 에 따라 나뉜다.
  * ##### foreground process
    * 제어 터미널이 **_있다_**.
    * 현재의 키보드와 모니터를 사용한다.
    * 키보드의 입력으로 죽이거나(^C) 일시중지(^Z) 시킬 수 있다.
    * 수행이 끝나야 다시 쉘 프롬프트가 뜬다.
  * ##### background process
    * 제어 터미널이 **_없다_**.
    * 터미널 제어와 무관하므로 명령 입력 즉시 쉘 프롬프트가 뜬다.
    * 쉘에서 직접 백그라운드 수행을 명령 할 수 있다. (명령 뒤에 & 추가)
    * ex) 
  ~~~bash 
  $ find / -name ifcfg-eth0 &
  ~~~

### 3. process 명령어
* ps는 현재 숭행중인 process 이름, ID 번호, 부모 ID 번호, 제어 터미널과 소유자를 포함한 속성을 보여준다.
* kill은 process ID에 근거하여 process에게 적절한 signal 전달.
* wait은 쉘이 자식 process들 중 하나가 끝날 때 까지 대기상태로 만듬.
* 현재 process 상태를 보고한다.

    ```bash
    $ ps [option]

    [options]   
    -e : "all" process
    -f : full format
    ```
* 시스템 및 process의 상태를 일정 시간 간격으로 보여준다. (끝내려면 q)

    ```bash
    $ top
    ```
  
```bash
$ kill [-s signal] pid
$ killall [-s signal] pname
```
* 지정된 process에 signal을 보낸다.
* kill은 반드시 process를 종료시키는 것만은 아니다.
* killall은 같은 이름의 많은 process를 한꺼번에 종료할 때 편리하다.
> 9 SIGKILL     process 사멸
> 19 SIGSTOP    process 정지

## 명령 스케줄

### 주기적 실행
```bash
$ cron
$ crontab
```
* cron은 일정 시간 마다 주기적으로 예약된 명령을 수행하는 서비스이다.
* crontab은 cron이 실행할 명령들에 접근하는 사용자 인터페이스이다.
* crond라는 daemon으로 작동
* cron을 설정하는 2가지 방법
    1. crontab -e 를 통한 직접 설정.
    2. crontab file을 만든 후 crontab명령을 사용하여 등록.
* 생성된 명령들은 /var/spool/cron/$USER에 file로 저장, 실행

### 일시적 실행
```bash
$ at
```
* 일시적으로 한번만 수행하는 작업 예약에 사용
* atd라는 daemon으로 작동

## Linux_Shell

### Shell의 운영
* shell은 다양한 종류(**_bash_**, csh, zsh, ...)가 있다.
* 사용 가능한 shell은 /etc/shells에 등록되어 있음
* shell 변경
    ```bash
    $ /bin/csh          일시적 변경
    $ chsh -s /bin/csh  영구적 변경
    ```
* shell login/logout을 할때 shell의 환경 설정 파일(startup file)
> /etc/profile : 시스템 전역에 영향을 미치는 설정 파일
> 
> ~/.bash_profile : login할 때 읽어들이는 설정 파일. .bashrc 호출
> 
> ~/.bashrc : sub-shell이 실행 될 때마다 실행
> 
> /etc/bashrc : 시스템 전역에 영향을 미치고 새로운 shell이 생성 될 때마다 실행
> 
> /etc/profile, /etc/bashrc : 시스템 관리자가 설정  
> ~/.bash_profile, ~/.bashrc : 각 사용자가 설정
> 
> ~/bash_logout : shell이 끝낼 때 수행.

* shell prompt 설정은 $PS1 환경변수에 저장
* 내장 명령어 / 외부 명령어 / 기타 응용 프로그램
  * 내장 명령어는 shell에 포함된 명령어를 말한다.
  * 설명 열람 방법
  * 내장이 아닌 명령어는 모두 **_실행 파일_** 형태로 저장되어 있다.
  * 설명 열람 방법
  * 일보 내장 명령은 외부명령으로 구현 된 것도 있다.
  * example)
* 명령 수행 순서
> 1. prompt에 명령 입력  
> 2. shell 내부 우선 탐색
> 3. 찾으면 실행, 못찾으면 환경변수 경로 탐색
> 4. 찾으면 실행, 못찾으면 오류 메시지 전송

### bash 내장 명령

* <span style="color:red">".", source</span>
  * shell 내에서 실행 권한이 없는 파일을 실행할 때 사용.
  * "." 혹은 source로 명령 실행시, sub-shell 없이 부모 shell이 **_직접_** 수행
  * script 파일에 권한을 부여하여 실행하는 것과, 소스로 실행하는 것은 차이가 있다.

### shell의 기능 : 메타 문자

| 기호 | 의미 |
|---|:---:|
| > | 표준 출력을 보내는 **_출력_** redirection |
| >> | 표준 출력을 덧붙이는 **_출력_** redirection |
| < | file로 부터 읽는 **_입력_** redirection |
| << string | string을 **_입력_**으로 처리 |
| \| | 앞 명령의 출력을 다음 명령의 입력으로 보내는 **_pipe_** |
| * | 모든 가능성의 문자로 **_대치_**하는 wild card |
| ? | 한 자리의 다른 문자와 **_대치_**하는 wild card |
| [ ] | 대괄호속 범위에 맞춰 **_대치_**하는 대표문자 |
| & | 명령을 background에서 실행 |
| && | 앞 명령이 성공할 경우만 다음 명령 실행하는 조건부 실행 |
| \|\| | 앞 명령이 실패할 경우만 다음 명령 실행하는 조건부 실행 |
| ; | 명령의 구분에 사용 |
| 2> | 오류 메시지를 보내는 출력 redirection |
| 2>> | 오류 메시지를 덧붙이는 출력 redirection |

* command "tee" : pipe라인 도중에 생성된 임시 출력을 파일로 저장
    ```bash
    $ who | tee who.out | sort
    user    pts/1   Mar 25 18:57 (211.221.225.39)
    root    pts/0   Mar 25 17:38 (211.221.225.39)
    $ cat who.out
    user    pts/1   Mar 25 18:57 (211.221.225.39)
    root    pts/0   Mar 25 17:38 (211.221.225.39)
    ```
* grave accent "'"로 둘러싸인 명령어는 실행된 결과가 대체되어 표준 출력으로 나온다.
    ```bash
    $ echo There are 'who | wc -l' users on the system
    There are 3 users on the system
    ```

* 명령어 그룹 : 명령어 들을 관호 안에 하나의 그룹으로 묶어, 하나의 자식 shell에 의해 실행

    ```bash
    $ (date; ls; pwd) > pwd.out
    ```

### shell의 기능 : 전,후면 처리
* jobs : background 작업의 목록을 표시한다.
* fg : background에서 도는 작업을 foreground로 불러온다.
* bg : foreground 작업을 background로 바꾼다.

* 후면처리 작업은, 쉘의 효율을 위해 출력을 별도의 파일로 지정할 수 있다.
*  후면 처리 작업 중 입력이 필요해지면, process는 즉시 일시 정지한다.
*  입력이 필요한 background process에게 미리 입력될 내용을 파일로 저장하여 입력 redirecion으로 제공 할 수 있다.

    ```bash
    $ ./run < in.dat > output &
    in.dat 의 내용이 ./run의 입력으로 들어가고, 결과값은 output으로 출력된다.
    ```

### shell의 기능 : sub-shell

* 현재 shell이 자식 shell을 생성하는 경우
  * $ bash 와 같은 직접 실행
  * 그룹의 명령어가 실행
  * script가 실행

* 자식 shell의 자료 공간
  * 모든 shell은 두 종류의 변수를 가진다.
    * 환경 변수 : shell 운영에 필요한 정보 보관. 자식 shell에게도 전달됨
    * 지역 변수 : 사용자가 임의로 정의하여 사용하는 공간. 상속 X
  * 자식 shell은 환경 변수 값 상속 O, 지역 변수 값 상속 X

### shell의 기능 : shell 변수

* shell 변수는 문자열 형이 기본.
* 변수의 종류
  * 지역 변수 : 사용자가 임의로 정의하여 사용하는 공간.
  * 환경 변수 : shell 운영에 필요한 정보 보관
  * 위치 매개변수 : $0, $1, $2, ... 명령행에서 script로 넘어온 인자들.

* 환경 변수 열람
    ```bash
    $ printenv
    $ env
    ```

* 변수 수정
  * "=" 좌우로 공백이 없어야 한다.
  ```bash
  $ 변수명=변수값
  $ 변수명="변수값"
  ```
  * 환경변수 PATH에 원하는 directory 추가
  ```bash
  $ PATH=$PATH:$HOME/bin
  ```
* 미리 정의된 환경 변수

    | 환경 변수 | 의미 |
    | --- | :---: |
    | HOME | home directory의 절대 경로 |
    | PATH | 외부 명령어를 탐색할 directory list |
    | USER | 사용자 이름 |
    | SHELL | log in shell의 절대 경로 |
    | LANG | 사용하는 언어 |
    | HOSTNAME | host 이름|
    | PS1 | main prompt. $가 default. |
    | PS2 | sub prompt. >가 default. |

* 전역 변수 전환 : export
* script란 실행 가능한 text file로서,
  > shell -실행-> script == C_LANG -호출-> main function
* 다음은 명령행으로 준 인자들을 script 내부로 전달 하는데 사용
  * $0      : 명령행에서의 0번째 단어(실행 명령어)
  * $1 ~ $9 : 명령행의 인자
  * $*      : 명령행 인자들의 목록
  * $#      : script에 넘겨진 인자의 갯수
  * $\$     : shell script의 process ID


## Bash shell programming

* alias vs shell script
  * alias : 지정된 매개변수만 운용가능 (활용성이 떨어짐)
  * shell script : 일종의 interpreter 언어로 활용되며, 프로그래밍 언어로서 기능을 한다.

### shell script

* 일련의 shell 명령어들을 연속적인 자동 실행을 위해 text file 형태로 저장한 것.
  * 명령을 하나씩 입력하여 발생하는 error 방지
  * 명령 수행을 예약 및 자동화 가능
* shell script는 기본적으로, 실행시 자식 shell이 수행
* compile 필요 없이, shell이 해석해서 수행
* script는 반복 작업을 자동 수행하는데 유용
* script 첫줄에서 사용 될 shell을 결정
  * 첫줄이 단지 \#이면 이 script를 수행한 shell과 같은 shell로 수행
  * \#!ShellName 형식이면 ShellName에 명시된 shell 사용
  * 위 규칙이 모두 안되면, bash 사용
* text file로 만든 script file은, 실행 허가권을 주고 실행 (혹은, source를 이용하여 실행)


## Communication between bash & C

* C 언어로 Linux와 상호작용 하기
    ```C
    //callbash.c
    #include <stdio.h>

    int main()
    {
        system("ls: sleep 5");
        system("/bin/bash"); // sub-shell 호출.
        system("ps -f");
    }
    ```

* Linux Shell이나 script에서 인자를 C Program 으로 넘기는 방법  
  `int main(int argc, char *argv[])`
* 



