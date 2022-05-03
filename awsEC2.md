# EC2 생성

아마존 들어가서 생성하면 됨


# 기본 세팅 하기

## Ngix
https://wingsnote.com/55?category=514236 여기 참고

웹서버는 Ngix나 Apache 골라서 설치하면됨

## Apache2 (웹서버 설치)

``` console
sudo apt-get install -y apache2 
```

## Tomcat (WAS 설치)

Tomcat을 설치하기 전 자바를 먼저 설치해야함.

우선 설치 가능한 버전을 확인하자

```console
sudo apt list | grep jdk

```

버전 확인후 원하는 버전 설치


