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

## Tomcat (WAS 설치)

Tomcat을 설치하기 전 자바를 먼저 설치해야함.

우선 설치 가능한 버전을 확인하자

```console
sudo apt list | grep jdk

```

버전 확인후 원하는 버전 설치




