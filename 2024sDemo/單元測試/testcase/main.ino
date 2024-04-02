String s="-----------------------\n\
0:hello world\n\
1:led\n\
2:atomizer\n\
3:openmotor\n\
4:closemoter\n\
5:lcd\n\
6:btn\n\
7:pir\n\
8:wls\n\
9:dht\n\
-----------------------";
void setup() {
  testcase_setup();
  Serial.println(s);
}

void loop(){
  testcase_loop();

}