// (lab2-1) 시간(Date객체, getMonth), 문자열처리 메소드(indexOf, substring), if-else문, 함수
console.log("\n==============================================================================\n(lab2-1) 시간(Date객체), 문자열메소드(indexOf, substring), if-else문, 함수\n==============================================================================\n");
date = new Date();
now = date.getMonth() + 1;

myBirth = "1998년 12월 24일";
myBirth2 = "1998년 1월 1일";
myBirth3 = "1998년 7월 10일";
myBirth4 = "1998년 3월 25일";
greeting(myBirth);
greeting(myBirth2);
greeting(myBirth3);
greeting(myBirth4);

function greeting(myBirth)
{
  // (lab2-1) 구현위치
  console.log("---");
  console.log(myBirth);
  tokens = myBirth.split(" ");
  suber = myBirth.substring(6,9);
  if(suber[0] == " ")
  {
      suber = suber.replace(" ", "");
  }
  console.log("내 생일은 " + suber + "입니다.");
  month = new Date();
  month = month.getMonth();
  targetmonth = tokens[1].replace("월", "");

  leftmonth = (month + 1) - targetmonth;
  if(leftmonth < 0)
  {
      console.log(-leftmonth + "개월이 남았군요. 추카추카!!!");
  }
  else if(leftmonth > 0)
  {
      console.log("올해 생일이 " + leftmonth + "개월 지났네요.");
  }
  else
  {
      console.log("이번달이 생일이군요. 추카추카!!!");
  }

}

// (lab2-2) 타이머(setInterval, setTimeout), 함수(익명함수, callback함수)
console.log("\n==============================================================================\n(lab2-2) 타이머(setInterval, setTimeout), 함수(익명함수, callback함수)\n==============================================================================\n");

var x = 0;
m = "x(=1,2,3,...,10)의 제곱값을 1초 단위로 출력합니다.";
m2 = "타이머를 정지합니다.";
m3 = "x(=1,2,3,...,10)의 세제곱값을 1초 단위로 출력합니다.";

function math(msg, msg2, callback, callback2)
{
    // (lab2-2) 구현위치
    begin = setInterval(function()
    {
        if(x >= 10)
        {
            callback2(begin);
        }
        else
        {
            callback(msg);
        }
    } , 1000);
}

function start(msg)
{
    if(x==0) {console.log(""); console.log("-----"); console.log(msg);}
    x += 1;
    console.log(x * x);
}

function clear(t)
{
    clearInterval(t);
    console.log(m2);
    //epilog
}

// x(=1,2,3,...,10)의 제곱값을 1초 단위로 출력
math(m, m2, start, clear);

// x(=1,2,3,...,10)의 세제곱값을 1초 단위로 출력
setTimeout(function()
  {
      x = 0;
      // (lab2-2) 구현위치
      //   math()를 호출하되 3번인수에 start() 내용을 수정하여
      //   3승을 계산하는 익명함수 형태로 작성, 호출할 것.
      math(m3, m2, function(msg){
          if(x==0) {console.log(""); console.log("-----"); console.log(msg);}
          x += 1;
          console.log(x * x * x);

      }, clear);

  }, 12000);
