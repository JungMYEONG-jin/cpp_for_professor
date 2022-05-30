# EC2 생성

아마존 들어가서 생성하면 됨


# 기본 세팅 하기

## Nginx
https://wingsnote.com/55?category=514236 여기 참고

웹서버는 Nginx Apache 골라서 설치하면됨

## Apache2 (웹서버 설치)

``` console
sudo apt-get install -y apache2 
```

기본 페이지 바꾸는법

- 경로 이동 : cd /etc/apache2/sites-available
- vim 000-default.conf 입력
- 약 12번째 줄의 DocumentRoot /var/www/html 부분을 희망하는 경로로 수정
- Esc, :,wq로 저장 후 종료
- 경로 이동 : cd /etc/apache2/
- vim apache2.conf입력
- 약 164번 줄의 directory /var/www/html 부분을 희망하는 경로로 수정
- Esc, :,wq로 저장 후 종료
- service apache2 restart

apache2는 websocket 사용시 프록시 패스, 포트 포워딩이 필요함.

/etc/apache2/ports.conf
/etc/apache2/sites-available/deafult-ssl.conf
수정해야함

ports.conf

ssl 모듈내 listen port 수정하면 해당 포트를 https 연결에 사용하겠다는 뜻임

ex) 8443 설정시 앞으로 8443이 https 포트로 되는거

default-ssl.conf에서도 Listen 포트 변경해줘야함(기존 443이기 때문 프록시 패스를 사용하면 해당 포트도 추가해주고)

websocket은 ws, wss로 사용되 ws http wss https임

근데 apache2에서는 이걸 그냥 ws, wss로 인식해버림

``` console
$ a2enmod rewrite        # 보통 default로 enable 되어있는 경우가 많다.
$ a2enmod proxy_wstunnel

# default-ssl.conf docker file expose를 443으로 하고 wss 8200으로 https는 기존 443으로 그대로 두면됨

RewriteEngine on
RewriteCond %{HTTPS:UPGRADE} =websocket [NC]
RewriteRule .* wss:/spass.hancy.kr:8200/$1 [P,L]
 
ProxyPass / https://spass.hancy/kr:8200
ProxyPassReverse / https://spass.hancy.kr:8200
or
ProxyPass / https://127.0.0.1:8200
ProxyPassReverse / https://127.0.0.1:8200

```

## docker

docker run -p 

docker run -it -p 8200:8200 spass
이렇게 컨테이너를 새로 만들면, 호스트 운영체제의 8200 포트와 컨테이너의 8200 포트가 매핑됩니다. 호스트 운영체제의 8200 포트로 전달된 정보들이 도커를 통해 컨테이너의 8200 포트로 포워딩된다는 의미입니다.

도커를 실행할 때 -p 옵션은 꼭 같은 번호로 하지 않아도 됩니다.

docker run -it -p 8088:80 spass
위 명령처럼 컨테이너를 실행하면 호스트 운영체제의 8088번 포트가 컨테이너의 80번 포트로 연결됩니다.

Dockerfile의 EXPOSE
도커 이미지를 만들 수 있는 Dockerfile에 EXPOSE 명령을 사용할 수 있습니다. 예를 들어

FROM openjdk:8
COPY Test.class /root
WORKDIR /root
EXPOSE 443
ENTRYPOINT ["java", "-agentlib:jdwp=transport=dt_socket,server=y,suspend=y,address=443", "Test"]
이런 Dockerfile이 있을 때 EXPOSE 명령을 이용해, '이 도커 이미지는 443 포트를 외부에 공개할 예정이다'라고 명시할 수 있습니다.


사실 도커에서 웹서버가 자체적으로 가능해서 apache2를 같이 적용할 필요없음. apache2 stop시키고 해도됨.


## yum설치

우분투 22.04 jammy는 yum4로 설치해야한다...

unable to locate package error 발생시 해당 문구 넣어주기

``` console
sudo vi sources.list

deb http://archive.ubuntu.com/ubuntu bionic main restricted universe multiverse
deb http://archive.ubuntu.com/ubuntu bionic-security main restricted universe multiverse
deb http://archive.ubuntu.com/ubuntu bionic-updates main restricted universe multiverse

```

그리고 설치

``` console

sudo apt-get update
sudo apt-get install yum4

```

근데 아직 문제가 많음

20.04나 18.04등 안정된 버전으로 다시 세팅하는게 좋을듯



## Tomcat (WAS 설치)

Tomcat을 설치하기 전 자바를 먼저 설치해야함.

우선 설치 가능한 버전을 확인하자

```console
sudo apt list | grep jdk

```

버전 확인후 원하는 버전 설치

```console
sudo apt-get install openjdk-11-jdk

java -version
javac -version
```
설치후 잘 설치되었나 확인

그리고 환경설정 해주자

``` console
vi ~/.bashrc
export JAVA_HOME=$(dirname $(dirname $(readlink -f $(which java))))
export PATH=$PATH:$JAVA_HOME/bin

```
편집기로 열어준후 맨아래에 export 문구 넣어줌

저장후 

``` console
source ~/.bashrc
echo $JAVA_HOME
```

echo 했을때 경로 나오면 성공

이제 톰캣을 설치해보자

## Nodejs 설치

docker에 node를 띄우지 않고 직접 서버에 띄우려면 node를 설치해야한다.

``` console

sudo apt-get update

sudo apt-get install nodejs

sudo apt-get install npm

# 버전별로 설치하려면 nvm 설치하는게 더좋음
# https://github.com/nvm-sh/nvm 해당 깃헙 들어가서 메인에 curl ~~~ 부분 복사해서 실행

curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.1/install.sh | bash

# 수정사항 적용 위해 source 실행
source ./bashrc

cd spass directory

# index.js를 실행해주면된다.
node index.js

```

하지만 이렇게 하면 터미널이 종료되면 node서버가 종료되는 현상이 생긴다. 그 이유는 백그라운드애서 돌아가지 않기 때문이다.
이를 해결하려면 백그라운드에서 돌게 하거나 도커로 실행하면됨. 만약 서버에서 백그라운드 돌릴거라면 forever 모듈이 필요함.

``` console

sudo npm install forever -g

# 이렇게 구동시 백그라운드에서 실행됨.
sudo forever start index.js

# 현재 백그라운드에서 구동중인 프로세스 보여줌
sudo forever list

# 중단 하려면 pid 알아야됨.

sudo forever stop {pid}


```
pid에 프로세스 아이디 값을 넣어주면 해결




