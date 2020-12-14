//  <lab10>디렉토리 안에서 command창 생성
//  (prompt)> mysql -u root -p
//  Enter password: (your password)
//  mysql> source schedule.sql;

show databases;
CREATE DATABASE  IF NOT EXISTS `myinfo`;
use myinfo;
DROP TABLE IF EXISTS `schedule`;
create table schedule (
id int not null auto_increment primary key,
value varchar(100) not null,
date varchar(15) not null,
time varchar(10) not null,
place varchar(50) not null,
contact varchar(50) not null
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
describe schedule;
INSERT INTO `schedule` (`id`,`value`,`date`, `time`, `place`, `contact`) VALUES (1,'코스모 구로디지털단지', '2018/02/24', '오전10시', '서울 구로동 191-7', '010-9123-5678');
INSERT INTO `schedule` (`id`,`value`,`date`, `time`, `place`, `contact`) VALUES (2,'건강보험공단 원주', '2018/02/28', '오후3시', '원주 건강로 32', '010-2777-8342');
INSERT INTO `schedule` (`id`,`value`,`date`, `time`, `place`, `contact`) VALUES (3,'넥스트코어 송파', '2018/03/11', '오전12시', '서울 문정동 642-3', '070-5015-2313');
INSERT INTO `schedule` (`id`,`value`,`date`, `time`, `place`, `contact`) VALUES (4,'예스앤드 역삼동', '2018/03/20', '오전9시', '서울 역삼동 677', '010-7351-2984');
INSERT INTO `schedule` (`id`,`value`,`date`, `time`, `place`, `contact`) VALUES (5,'농어촌진흥재단 구로', '2018/04/15', '오후1시', '서울 우면동 760', '010-9231-7663');
INSERT INTO `schedule` (`id`,`value`,`date`, `time`, `place`, `contact`) VALUES (6,'기술정보진흥원 대전', '2018/05/4', '오후2시', '대전 도룡동 386-2', '042-388-0100');
INSERT INTO `schedule` (`id`,`value`,`date`, `time`, `place`, `contact`) VALUES (7,'위즈코어 가산디지털단지', '2018/05/6', '오전8시', '서울 염리동 172-11', '02-3273-2608');
INSERT INTO `schedule` (`id`,`value`,`date`, `time`, `place`, `contact`) VALUES (8,'LH공사 오리', '2018/05/9', '오전4시', '성남 구미동 175', '010-2374-1821');
INSERT INTO `schedule` (`id`,`value`,`date`, `time`, `place`, `contact`) VALUES (9,'정보화진흥원 무교', '2018/05/12', '오후6시', '대구 신서동 1143', '053-230-1114');
INSERT INTO `schedule` (`id`,`value`,`date`, `time`, `place`, `contact`) VALUES (10,'비컴솔루션 강남 도곡로', '2018/05/16', '오후8시', '서울 도곡1동 946-6', '02-3461-4909');
INSERT INTO `schedule` (`id`,`value`,`date`, `time`, `place`, `contact`) VALUES (11,'국립중앙도서관 서초', '2018/05/20', '오후5시', '서울 반포동 산60-1', '02-535-4142');
INSERT INTO `schedule` (`id`,`value`,`date`, `time`, `place`, `contact`) VALUES (12,'(주)서브 서초 가든파이브웍스', '2018/05/24', '오후7시', '서울 문정동 632', '010-1277-8720');
INSERT INTO `schedule` (`id`,`value`,`date`, `time`, `place`, `contact`) VALUES (13,'큐브위즈 서교동', '2018/05/29', '오후4시', '서울 서교동 80-1', '010-7163-9070');
INSERT INTO `schedule` (`id`,`value`,`date`, `time`, `place`, `contact`) VALUES (14,'과학기술위원회 서초', '2018/06/5', '오후3시', '경기 중앙동 1 정부과천청사', '010-1335-8834');
select * from schedule;
